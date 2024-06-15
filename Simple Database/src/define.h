#pragma once
#include <string>
#include <initializer_list>

constexpr int SCHOOL_SIZE{ 16 };
constexpr const char* FILE_NAME{ "data.csv" };

constexpr const char* SCHOOL_TYPE[SCHOOL_SIZE]{
	"학교구분",
	"학교코드",
	"학교명칭",
	"본분교",
	"학제",
	"지역",
	"설립구분",
	"학교상태",
	"학교영어명칭",
	"주소",
	"우편번호",
	"학교개교일",
	"학교홈페이지",
	"총장명",
	"학교대표번호",
	"학교팩스번호"
};



struct School
{
	std::string data[SCHOOL_SIZE];

	void show() const;
	
	std::string& operator[](const size_t idx);
};

struct Node {
	School school;
	Node* next;

	Node(const School& school) : school(school), next(nullptr) {}
};

