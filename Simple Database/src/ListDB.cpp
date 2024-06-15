#include <iostream>
#include <vector>

#include "ListDB.h"
#include "timer.h"


ListDB listDB;


ListDB::~ListDB() {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}

void ListDB::insert(const School& school)
{
	Node* newNode = new Node(school);
	newNode->next = head;
	head = newNode;
}

void ListDB::select(const size_t idx, const std::string& value) const {
	std::vector<School*> result;
	Node* current = head;

	timer.reset();
	while (current != nullptr) {
		if (current->school[idx] == value) {
			result.push_back(&current->school);
		}
		current = current->next;
	}
	timer.elapsed();


	for (auto school : result) {
		school->show();
	}
	timer.show();
}

void ListDB::remove(const size_t idx, const std::string& value) {
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->school[idx] == value) {
			Node* temp = current;
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            delete temp;
		}
		else {
			prev = current;
			current = current->next;
		}
    }
}

void ListDB::update(
	const size_t		targ_idx,
	const std::string&	targ_value,
	const size_t		where_idx,
	const std::string&	where_value)
{
	Node* current = head;
	while (current != nullptr) {
		
		if (current->school[where_idx] == where_value) {
			current->school[targ_idx] = targ_value;
		}
		current = current->next;
	}
}
