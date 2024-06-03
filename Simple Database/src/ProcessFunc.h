#pragma once
#include <print>
#include <string>
#include <sstream>
#include <fstream>

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
// SELECT key=value 
//
template <class DB>
void _Process_SELECT(DB& db, std::string& arg)
{
	if (not arg.contains('=')) {
		std::println("{}: 잘못된 명령어입니다.", arg);
		return;
	}

	auto eq		{ arg.find("=") };
	auto key	{ arg.substr(0, eq) };
	auto value	{ arg.substr(eq + 1, arg.size()) };

	for (const auto& type : SCHOOL_TYPE) {
		if (key == type) {
			// TODO: 여기에 출력 함수를 추가합니다.


			// 임시 출력
			std::println("{}: key 발견", arg);
			return;
		}
	}
	std::println("{}: 일치하는 key가 없습니다.", arg);
}

//
// INSERT 새객체 (아직 미구현)
//
template <class DB>
void _Process_INSERT(DB& db, std::string& arg)
{

}

//
// UPDATE key=value WHERE key=value (아직 미구현)
//
template <class DB>
void _Process_UPDATE(DB& db, std::string& arg)
{

}

//
// DELETE key=value
//
template <class DB>
void _Process_DELETE(DB& db, const std::string& arg)
{
	if (not arg.contains('=')) {
		std::println("{}: 잘못된 명령어입니다.", arg);
		return;
	}

	auto eq		{ arg.find("=") };
	auto key	{ arg.substr(0, eq) };
	auto value	{ arg.substr(eq + 1, arg.size()) };

	for (const auto& type : SCHOOL_TYPE) {
		if (key == type) {
			// TODO: 여기에 삭제 함수를 추가합니다.


			// 임시 출력
			std::println("{}: key 발견", arg);
			return;
		}
	}
	std::println("{}: 일치하는 key가 없습니다.", arg);
}


template <class DB>
void process_input(DB& db)
{
	std::string in;

	std::print("명령어 >> ");
	std::getline(std::cin, in);

	auto space	{ in.find(" ") };
	auto cmd	{ in.substr(0, space) };
	auto arg	{ in.substr(space + 1, in.size()) };

	if		(cmd == "SELECT")	{ _Process_SELECT(db, arg); }
	else if (cmd == "INSERT")	{ _Process_INSERT(db, arg); }
	else if (cmd == "UPDATE")	{ _Process_UPDATE(db, arg); }
	else if (cmd == "DELETE")	{ _Process_DELETE(db, arg); }
	else						{ std::println("{}: 잘못된 명령어입니다.", cmd); }

	std::cout << std::endl;
}