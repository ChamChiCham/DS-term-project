#include <algorithm>

#include "ListDB.h"


ListDB listDB;

void ListDB::push(const School& school)
{
	schools.push_back(school);
}

const School& ListDB::find(std::string_view key) const
{
	auto iter{ std::find_if(schools.begin(), schools.end(), [key](const School& a) {
		return a.data[2] == key;
		}) };

	return *iter;
}
