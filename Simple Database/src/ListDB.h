#pragma once
#include <vector>
#include <string_view>

#include "define.h"


class ListDB
{
private:
	Node* head;
	std::vector<School> schools;

public:
	void push(const School&);

	const School& find(std::string_view) const;

	ListDB() : head(nullptr) {}
	~ListDB();
	void linkedList_push(const School&);
	const School& linkedList_find(std::string_view, std::string_view value) const;
	std::vector<School> linkedList_find_all(std::string_view key, std::string_view value) const;
	void linkedList_remove(std::string_view key);
	void linkedList_update(std::string_view key, const School& newSchool);
};


extern ListDB listDB;