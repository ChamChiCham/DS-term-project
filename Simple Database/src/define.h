#pragma once
#include <string>

constexpr int MAX_SIZE{ 16 };
constexpr const char* FILE_NAME{ "data.csv" };

struct School
{
	std::string data[MAX_SIZE];

	void show() const;
};