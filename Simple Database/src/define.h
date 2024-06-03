#pragma once
#include <string>
#include <initializer_list>

constexpr int SCHOOL_SIZE{ 16 };
constexpr const char* FILE_NAME{ "data.csv" };

constexpr const char* SCHOOL_TYPE[SCHOOL_SIZE]{
	"�б�����",
	"�б��ڵ�",
	"�б���",
	"���б�",
	"����",
	"����",
	"��������",
	"�б�����",
	"�б���",
	"�ּ�",
	"�����ȣ",
	"�б�������",
	"�б�Ȩ������",
	"�����",
	"�б���ǥ��ȣ",
	"�б��ѽ���ȣ"
};



struct School
{
	std::string data[SCHOOL_SIZE];

	void show() const;
};

struct Node {
	School school;
	Node* next;

	Node(const School& school) : school(school), next(nullptr) {}
};

