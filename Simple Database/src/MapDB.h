#pragma once

#include "define.h"

class MapDB
{
public:

	void insert(const School&);

	void select(size_t, const std::string&) const;

	// REMOVE
	void remove(const size_t, const std::string&);

	// UPDATE
	void update(const size_t, const std::string&, const size_t, const std::string&);
};

extern MapDB mapDB;
