#include "define.h"
#include "ListDB.h"
#include "ProcessFunc.h"

int main()
{
	read_file(listDB);
	listDB.find("���������ؾ���б�").show();
}