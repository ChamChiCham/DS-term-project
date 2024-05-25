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
	const School& linkedList_find(std::string_view) const;
	void linkedList_show() const;
	void linkedList_remove(std::string_view key);
};


extern ListDB listDB;