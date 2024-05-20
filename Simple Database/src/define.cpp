#include <print>

#include "define.h"

void School::show() const
{
	for (const auto& a : data) {
		std::println("{}", a);
	}
}
