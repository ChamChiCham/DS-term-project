#include <iostream>
#include "define.h"
#include "ListDB.h"
#include "BSTDB.h"
#include "ProcessFunc.h"

int main()
{
    std::println("���� ���� �б⸦ �����մϴ�...");
    read_file(listDB);
    read_file(bstDB);
    std::println("���� ���� �б� �Ϸ�.");
    
    int value;
    while (true) {
        std::println("Select Database Type (LinkedList: 1 | Tree: 2) ");
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
        while (process_input(bstDB));
    }
}