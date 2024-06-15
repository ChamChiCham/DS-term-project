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
	
	// REMOVE
	void remove(const size_t, const std::string&);
	
	// UPDATE
	void update(const size_t, const std::string&, const size_t, const std::string&);
};


extern ListDB listDB;