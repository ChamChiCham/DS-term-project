#pragma once
#include <vector>

#include "define.h"


class ListDB
{
private:
	std::vector<School> data;

public:
	void push(const School& school);


};


extern ListDB listDB;