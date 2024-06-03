#include <iostream>
#include "define.h"
#include "ListDB.h"
#include "ProcessFunc.h"

void search_linkedList() {
    std::string name;
    std::cout << "�˻��� �б� �̸��� �Է��ϼ���: ";
    std::getline(std::cin, name);
    try {
        const School& school = listDB.linkedList_find(name);
        std::cout << "\nã�� �б� ������\n";
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
    std::cout << "������ �б� �̸��� �Է��ϼ���: ";
    std::getline(std::cin, name);
    listDB.linkedList_remove(name);
    std::cout << name << " �б��� �����Ǿ����ϴ�.\n";
}


int main()
{
    read_file(listDB);
  
    while (true) {
        process_input(listDB);        
    }

    // int menu_choice;
    //do {
    //    std::cout << "\n���Ḯ��Ʈ�� �̿��� ���\n";
    //    std::cout << "1. �˻� ���\n2. ���� ���\n3. ������ ��ü ��� ���\n4. ����\n";
    //    std::cout << "����: ";
    //    std::cin >> menu_choice;
    //    std::cin.ignore(); // ���๮�� ����

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
    //        std::cout << "���α׷��� �����մϴ�.\n";
    //        break;
    //    default:
    //        std::cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n";
    //    }
    //} while (menu_choice != 4);
    //return 0;




}