#include <iostream>
#include "define.h"
#include "ListDB.h"
#include "ProcessFunc.h"

int main()
{
    read_file(listDB);
  
    while (true) {
        process_input(listDB);        
    }
}