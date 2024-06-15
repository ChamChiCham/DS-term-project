#include <iostream>
#include "define.h"
#include "ListDB.h"
#include "MapDB.h"
#include "ProcessFunc.h"

int main()
{
    read_file(listDB);
    
    int value;
    while (true) {
        std::println("Select Database Type (LinkedList: 1 | priority queue: 2) ");
        std::print(">> ");
        std::cin >> value;
        if (1 == value || 2 == value) {
            break;
        }
        else {
            std::println("�߸��� ���Դϴ�. �ٽ� �Է����ּ���.\n");
        }
    }

    std::cout << std::endl;
    
    if (1 == value) {
        while (process_input(listDB));
    }
    else {
        while (process_input(mapDB));
    }
}