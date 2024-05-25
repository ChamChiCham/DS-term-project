#pragma once
#include <print>
#include <string>
#include <sstream>
#include <fstream>

template <class T>
void read_file(T& DB)
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
		for (int i{}; i < MAX_SIZE; ++i) {
			if (!std::getline(ss, data, ',')) break;
			new_school.data[i] = data;
		}

		//DB.pqueue_push(new_school);
		DB.linkedList_push(new_school);
	}
	std::println("���� ���� �б� �Ϸ�.");
}
