#include "source/Functions.h"
#include "source/Constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mysql.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "portuguese");
	system("chcp 1252> nul");

	MYSQL* conn = getConnection();
	Read(conn);

	system("pause");
	return 0;
}