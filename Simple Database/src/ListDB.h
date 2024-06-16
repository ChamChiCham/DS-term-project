#pragma once
#include <string_view>

#include "define.h"


class ListDB
{
private:
	Node* head;

public:

	ListDB() : head(nullptr) {}
	~ListDB();

	void insert(const School&);
	
	void select(size_t, const std::string&) const;
	
	// DELETE
	void remove(const size_t, const std::string&);
	
	void update(const size_t, const std::string&, const size_t, const std::string&);
};


extern ListDB listDB;