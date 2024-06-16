#include "BSTDB.h"
#include "timer.h"

BSTDB bstDB;

BSTDB::~BSTDB()
{
	while (true) {
		remove(BST_KEY, root->data[BST_KEY]);
		if (root == nullptr) {
			break;
		}
	}
}

void BSTDB::insert(School& school)
{
	if (root == nullptr) {
		root = new TreeNode{ school };
		return;
	}

	TreeNode* current{ root };
	while (true) {
		if (current->data[BST_KEY] < school[BST_KEY]) {
			if (current->right == nullptr) {
				current->right = new TreeNode{ school };
				return;
			}
			current = current->right;
		}
		else {
			if (current->left == nullptr) {
				current->left = new TreeNode{ school };
				return;
			}
			current = current->left;
		}
	}
}

TreeNode* search(TreeNode* head, const size_t idx, const std::string& value)
{
	if (head == NULL) return NULL;
	if (value == head->data[idx])
		return head;
	if (value < head->data[idx]) {
		return search(head->left, idx, value);
	}
	else {
		return search(head->right, idx, value);
	}
}

void BSTDB::select(const size_t idx, const std::string& value) const
{
	timer.reset();
	auto result = search(root, idx, value);
	timer.elapsed();

	result->data.show();
	timer.show();
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current && current->left != NULL)
		current = current->left;

	return current;

}
void BSTDB::remove(const size_t idx, const std::string& value)
{
	root = remove_rec(root, idx, value);
}
TreeNode* BSTDB::remove_rec(TreeNode* root, const size_t idx, const std::string& value)
{
	if (root == nullptr) return root;

	if (value < root->data[idx]) {
		root->left = remove_rec(root->left, idx, value);
	}

	else if (value > root->data[idx]) {
		root->right = remove_rec(root->right, idx, value);
	}

	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right);

		root->data = temp->data;
		root->right = remove_rec(root->right, idx, temp->data[BST_KEY]);
	}
	return root;
}

void BSTDB::update(const size_t targ_idx, const std::string& targ_value, const size_t where_idx, const std::string& where_value)
{
	timer.reset();
	auto result = search(root, targ_idx, targ_value);
	timer.elapsed();

	result->data[where_idx] = where_value;
	timer.show();
}
