#include "ListDB.h"

ListDB listDB;

void ListDB::push(const School& school)
{
	data.push_back(school);
}
