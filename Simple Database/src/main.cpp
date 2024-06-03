#include <iostream>
#include "define.h"
#include "ListDB.h"
#include "ProcessFunc.h"

void search_linkedList() {
    std::string name;
    std::cout << "검색할 학교 이름을 입력하세요: ";
    std::getline(std::cin, name);
    try {
        const School& school = listDB.linkedList_find(name);
        std::cout << "\n찾은 학교 데이터\n";
        std::cout << "-----------------\n";
        school.show();
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

void showAll_linkedList() {
    listDB.linkedList_show();
}

void delete_linkedList() {
    std::string name;
    std::cout << "삭제할 학교 이름을 입력하세요: ";
    std::getline(std::cin, name);
    listDB.linkedList_remove(name);
    std::cout << name << " 학교가 삭제되었습니다.\n";
}


int main()
{
    read_file(listDB);
  
    while (true) {
        process_input(listDB);        
    }

    // int menu_choice;
    //do {
    //    std::cout << "\n연결리스트를 이용한 기능\n";
    //    std::cout << "1. 검색 기능\n2. 삭제 기능\n3. 데이터 전체 출력 기능\n4. 종료\n";
    //    std::cout << "선택: ";
    //    std::cin >> menu_choice;
    //    std::cin.ignore(); // 개행문자 제거

    //    switch (menu_choice) {
    //    case 1:
    //        search_linkedList();
    //        break;
    //    case 2:
    //        delete_linkedList();
    //        break;
    //    case 3:
    //        showAll_linkedList();
    //        break;
    //    case 4:
    //        std::cout << "프로그램을 종료합니다.\n";
    //        break;
    //    default:
    //        std::cout << "잘못된 입력입니다. 다시 선택하세요.\n";
    //    }
    //} while (menu_choice != 4);
    //return 0;




}