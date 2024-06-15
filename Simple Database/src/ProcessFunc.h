#pragma once
#include <print>
#include <format>
#include <string>
#include <sstream>
#include <fstream>

#include "timer.h"

template <class DB>
void read_file(DB& db)
{
	std::ifstream file{ FILE_NAME };
	if (not file) {
		std::println("������ ã�� �� �����ϴ�. �����̸�: {}", FILE_NAME);
		while (true);
	}

	std::println("���� ���� �б⸦ �����մϴ�...");
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss{ line };
		std::string data;
		School new_school;
		for (int i{}; i < SCHOOL_SIZE; ++i) {
			if (!std::getline(ss, data, ',')) break;
			new_school.data[i] = data;
		}

		db.linkedList_push(new_school);
	}
	std::println("���� ���� �б� �Ϸ�.");
}

// 
// SELECT key = value 
//
template <class DB>
void _Process_SELECT(DB& db)
{
	Timer timer;
	std::string _line;
	std::getline(std::cin, _line);
	std::istringstream _iss{ _line };
	std::string _str[3];
	for (int i{}; i < 3; ++i) {
		if (!(_iss >> _str[i])) {
			throw std::format("{}: ���ڰ� �����մϴ�.", _line);
		}
	}

	if ("=" != _str[1]) {
		throw std::format("{}: �߸��� �Է��Դϴ�.", _line);
	}

	std::string& key = _str[0];
	std::string& value = _str[2];
	// ���� ����
	for (const auto& type : SCHOOL_TYPE) {
		if (type == key) {
			// TODO: ���⿡ SELECT �Լ��� �߰��մϴ�.
			try {
				std::vector<School> schools = db.linkedList_find_all(key, value);
				for (const auto& school : schools) {
					school.show();
					std::cout << std::endl;
				}
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
			std::cout << "SELECT ���� �ð�: " << timer.elapsed() << "��" << std::endl;
			return;

			// �ӽ� ���
			//std::println("key �߰�");
			//return;
			return;
		}
	}
	throw std::format("{}: key�� �߰ߵ��� �ʾҽ��ϴ�.", key);
}

//
// INSERT k1 k2 k3.. VALUES v1 v2 v3... 16�� ���� �� ���� �Է�
//
template <class DB>
void _Process_INSERT(DB& db)
	std::string _line;
	std::getline(std::cin, _line);
	std::istringstream _iss{ _line };
	std::string _kstr[SCHOOL_SIZE];
	std::string _vstr[SCHOOL_SIZE];
	std::string _str;

	unsigned char _kc{}, _vc{};
	
	// read keys
	while (true) {	
		if (not (_iss >> _str)) {
			throw std::format("{}: �߸��� �Է��Դϴ�.", _line);
		}

		if ("VALUES" == _str) {
			break;
		}

		if (SCHOOL_SIZE == _kc) {
			throw std::format("{}: key�� �ʹ� �����ϴ�.", _line);
		}

		_kstr[_kc++] = _str;
	}
	
	// read values
	while (_iss >> _str) {
		if (SCHOOL_SIZE == _vc) {
			throw std::format("{}: value�� �ʹ� �����ϴ�.", _line);
		}

		_vstr[_vc++] = _str;
	}

	if (_kc != _vc) {
		throw std::format("{}: key�� value�� ���� ���� �ʽ��ϴ�.", _line);
	}
	
	// compare key and values
	for (int i{}; i < _kc; ++i) {
		std::string& key = _kstr[i];
		std::string& value = _vstr[i];
		School school;

		bool _check = false;

		for (int j{}; j < SCHOOL_SIZE; ++j) {
			if (SCHOOL_TYPE[j] == key) {
				_check = true;
				school[j] = key;
			}
		}
		if (not _check) {
			throw std::format("{}: key�� �߰ߵ��� �ʾҽ��ϴ�.", key);
		}

		// TODO: ���⿡ INSERT �߰�.

	}

}


//
// UPDATE key = value WHERE key = value
//
template <class DB>
void _Process_UPDATE(DB& db)
{
	Timer timer;
	std::string _line;
	std::getline(std::cin, _line);
	std::istringstream _iss{ _line };
	std::string _str[7];
	for (int i{}; i < 7; ++i) {
		if (!(_iss >> _str[i])) {
			throw std::format("{}: ���ڰ� �����մϴ�.", _line);
		}
	}

	if ("=" != _str[1] || "WHERE" != _str[3] || "=" != _str[5]) {
		throw std::format("{}: �߸��� �Է��Դϴ�.", _line);
	}

	std::string& targ_key = _str[0];
	std::string& targ_value = _str[2];

	std::string& where_key = _str[4];
	std::string& where_value = _str[6];
	for (const auto& type : SCHOOL_TYPE) {
		if (type == where_key) {
			// TODO: ���⿡ ������Ʈ �Լ��� �߰��մϴ�.
			try {
				std::vector<School> schools = db.linkedList_find_all(where_key, where_value);
				for (auto& school : schools) {
					for (int i = 0; i < SCHOOL_SIZE; ++i) {
						if (SCHOOL_TYPE[i] == targ_key) {
							school.data[i] = targ_value;
						}
					}
					db.linkedList_update(where_value, school);
				}
				std::cout << "�б� ������ ������Ʈ�Ǿ����ϴ�." << std::endl;
				std::cout << "UPDATE ���� �ð�: " << timer.elapsed() << "��" << std::endl;
				return;
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
			return;

			// �ӽ� ���
			//std::println("where_key �߰�");
			//return;
			return;
		}
	}
	throw std::format("{}: ã������ key�� �߰ߵ��� �ʾҽ��ϴ�.", where_key);
}

//
// DELETE key = value
//
template <class DB>
void _Process_DELETE(DB& db)
{
	Timer timer;
	std::string _line;
	std::getline(std::cin, _line);
	std::istringstream _iss{ _line };
	std::string _str[3];
	for (int i{}; i < 3; ++i) {
		if (!(_iss >> _str[i])) {
			throw std::format("{}: ���ڰ� �����մϴ�.", _line);
		}
	}

	if ("=" != _str[1]) {
		throw std::format("{}: �߸��� �Է��Դϴ�.", _line);
	}

	std::string& key = _str[0];
	std::string& value = _str[2];

	for (const auto& type : SCHOOL_TYPE) {
		if (type == key) {
			// TODO: ���⿡ ���� �Լ��� �߰��մϴ�.
			try {
				db.linkedList_remove(value);
				std::cout << "�б��� �����Ǿ����ϴ�." << std::endl;
				std::cout << "DELETE ���� �ð�: " << timer.elapsed() << "��" << std::endl;
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
			return;
			// �ӽ� ���
			//std::println("key �߰�");
			//return;
			return;
		}
	}
	throw std::format("{}: key�� �߰ߵ��� �ʾҽ��ϴ�.", key);
}


template <class DB>
void process_input(DB& db)
{
	std::string in;

	std::print(">> ");
	std::cin >> in;

	try
	{
		if		(in == "SELECT") { _Process_SELECT(db); }
		else if (in == "INSERT") { _Process_INSERT(db); }
		else if (in == "UPDATE") { _Process_UPDATE(db); }
		else if (in == "DELETE") { _Process_DELETE(db); }
		else {
			std::println("{}: �߸��� ��ɾ��Դϴ�.", in);
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	}
	catch (const std::string& e)
	{
		std::cerr << e << std::endl;
	}
	std::cout << std::endl;
}