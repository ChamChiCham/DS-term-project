#include "define.h"

std::string& School::operator[](size_t idx)
{
	return data[idx];
}
