#include <print>
#include <iostream>

#include "define.h"

void School::show() const
{
	std::println("==============");
	for (const auto& a : data) {
		std::println("{}", a);
	}
	std::println("==============");
}

std::string& School::operator[](const size_t idx)
{
	if (idx >= SCHOOL_SIZE) {
		std::println(std::cerr, "School::operator[]: Invaild index.");
		exit(-1);
	}
	return data[idx];
}
