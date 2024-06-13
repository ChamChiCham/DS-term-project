#include <algorithm>
#include <iostream>

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

ListDB::~ListDB() {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}

void ListDB::linkedList_push(const School& school)
{
	Node* newNode = new Node(school);
	newNode->next = head;
	head = newNode;
}

const School& ListDB::linkedList_find(std::string_view key) const
{
	Node* current = head;
	while (current != nullptr) {
		if (current->school.data[2] == key) {
			return current->school;
		}
		current = current->next;
	}
	throw std::runtime_error("학교를 찾을 수 없습니다.");
}

void ListDB::linkedList_show() const {
	Node* current = head;
	while (current != nullptr) {
		current->school.show();
		current = current->next;
	}
}

void ListDB::linkedList_remove(std::string_view key) {
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        bool match = false;
        for (int i = 0; i < 16; i++) {
            if (current->school.data[i] == key) {
                match = true;
                break;
            }
        }
        if (match) {
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

void ListDB::linkedList_update(std::string_view key, const School& newSchool) {
	Node* current = head;
	while (current != nullptr) {
		bool match = false;
		for (int i = 0; i < 16; i++) {
			if (current->school.data[i] == key) {
				match = true;
				break;
			}
		}
		if (match) {
			current->school = newSchool;
			return;
		}
		current = current->next;
	}
	throw std::runtime_error("학교를 찾을 수 없습니다.");
}
