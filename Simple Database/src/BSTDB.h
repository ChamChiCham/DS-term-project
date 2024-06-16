#pragma once

#include "define.h"

struct TreeNode {
	School data;
	struct TreeNode* left{ NULL }, * right{ NULL };

	TreeNode() = default;

	TreeNode(const School& _data)
		:data{ _data }
	{}
};

class BSTDB
{
private:
	TreeNode* root{nullptr};

public:
	~BSTDB();

	void insert(School&);

	void select(const size_t, const std::string&) const;

	// DELETE
	void remove(const size_t, const std::string&);

	void update(const size_t, const std::string&, const size_t, const std::string&);

private:
	TreeNode* remove_rec(TreeNode* root, const size_t idx, const std::string& value);

};

extern BSTDB bstDB;
