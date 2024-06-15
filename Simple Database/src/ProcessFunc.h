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
		std::println("파일을 찾을 수 없습니다. 파일이름: {}", FILE_NAME);
		while (true);
	}

	std::println("엑셀 파일 읽기를 시작합니다...");
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
	std::println("엑셀 파일 읽기 완료.");
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
			throw std::format("{}: 인자가 부족합니다.", _line);
		}
	}

	if ("=" != _str[1]) {
		throw std::format("{}: 잘못된 입력입니다.", _line);
	}

	std::string& key = _str[0];
	std::string& value = _str[2];
	// 여기 수정
	for (const auto& type : SCHOOL_TYPE) {
		if (type == key) {
			// TODO: 여기에 SELECT 함수를 추가합니다.
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
			std::cout << "SELECT 실행 시간: " << timer.elapsed() << "초" << std::endl;
			return;

			// 임시 출력
			//std::println("key 발견");
			//return;
			return;
		}
	}
	throw std::format("{}: key가 발견되지 않았습니다.", key);
}

//
// INSERT k1 k2 k3.. VALUES v1 v2 v3... 16개 전부 다 값을 입력
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
			throw std::format("{}: 잘못된 입력입니다.", _line);
		}

		if ("VALUES" == _str) {
			break;
		}

		if (SCHOOL_SIZE == _kc) {
			throw std::format("{}: key가 너무 많습니다.", _line);
		}

		_kstr[_kc++] = _str;
	}
	
	// read values
	while (_iss >> _str) {
		if (SCHOOL_SIZE == _vc) {
			throw std::format("{}: value가 너무 많습니다.", _line);
		}

		_vstr[_vc++] = _str;
	}

	if (_kc != _vc) {
		throw std::format("{}: key와 value의 쌍이 맞지 않습니다.", _line);
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
			throw std::format("{}: key가 발견되지 않았습니다.", key);
		}

		// TODO: 여기에 INSERT 추가.

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
			throw std::format("{}: 인자가 부족합니다.", _line);
		}
	}

	if ("=" != _str[1] || "WHERE" != _str[3] || "=" != _str[5]) {
		throw std::format("{}: 잘못된 입력입니다.", _line);
	}

	std::string& targ_key = _str[0];
	std::string& targ_value = _str[2];

	std::string& where_key = _str[4];
	std::string& where_value = _str[6];
	for (const auto& type : SCHOOL_TYPE) {
		if (type == where_key) {
			// TODO: 여기에 업데이트 함수를 추가합니다.
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
				std::cout << "학교 정보가 업데이트되었습니다." << std::endl;
				std::cout << "UPDATE 실행 시간: " << timer.elapsed() << "초" << std::endl;
				return;
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
			return;

			// 임시 출력
			//std::println("where_key 발견");
			//return;
			return;
		}
	}
	throw std::format("{}: 찾으려는 key가 발견되지 않았습니다.", where_key);
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
			throw std::format("{}: 인자가 부족합니다.", _line);
		}
	}

	if ("=" != _str[1]) {
		throw std::format("{}: 잘못된 입력입니다.", _line);
	}

	std::string& key = _str[0];
	std::string& value = _str[2];

	for (const auto& type : SCHOOL_TYPE) {
		if (type == key) {
			// TODO: 여기에 삭제 함수를 추가합니다.
			try {
				db.linkedList_remove(value);
				std::cout << "학교가 삭제되었습니다." << std::endl;
				std::cout << "DELETE 실행 시간: " << timer.elapsed() << "초" << std::endl;
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
			return;
			// 임시 출력
			//std::println("key 발견");
			//return;
			return;
		}
	}
	throw std::format("{}: key가 발견되지 않았습니다.", key);
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
			std::println("{}: 잘못된 명령어입니다.", in);
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