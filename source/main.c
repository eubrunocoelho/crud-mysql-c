#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include "Constants.h"
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
	char x = '0';

	while (x != 'C' && x != 'c')
	{
		printf("Escolha as seguintes letras:\n");
		printf("a (Para visualizar os livros), c (Para fechar)\n");
		scanf("%c", &x);

		if (x == 'a' || x == 'A')
		{
			printf("\n");
			printf("#ID - #Nome - #Páginas - #Autor\n");
			Read(conn);
		}

		printf("\n");

		getchar();
	}

	printf("\n");

	system("pause");
	return 0;
}