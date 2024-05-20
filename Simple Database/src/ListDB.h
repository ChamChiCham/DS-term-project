#pragma once
#include <vector>
#include <string_view>

#include "define.h"


class ListDB
{
private:
	std::vector<School> schools;

public:
	void push(const School&);

	const School& find(std::string_view) const;
};


extern ListDB listDB;