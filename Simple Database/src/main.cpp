#include "define.h"
#include "ListDB.h"
#include "ProcessFunc.h"

int main()
{
	read_file(listDB);
	listDB.find("국립목포해양대학교").show();
}