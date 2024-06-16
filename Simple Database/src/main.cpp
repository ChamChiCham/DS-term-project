#include <iostream>
#include "define.h"
#include "ListDB.h"
#include "BSTDB.h"
#include "ProcessFunc.h"

int main()
{
    std::println("엑셀 파일 읽기를 시작합니다...");
    read_file(listDB);
    read_file(bstDB);
    std::println("엑셀 파일 읽기 완료.");
    
    int value;
    while (true) {
        std::println("Select Database Type (LinkedList: 1 | Tree: 2) ");
        std::print(">> ");
        std::cin >> value;
        if (1 == value || 2 == value) {
            break;
        }
        else {
            std::println("잘못된 값입니다. 다시 입력해주세요.\n");
        }
    }

    std::cout << std::endl;
    
    if (1 == value) {
        while (process_input(listDB));
    }
    else {
        while (process_input(bstDB));
    }
}