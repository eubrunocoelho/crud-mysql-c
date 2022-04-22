#define _CRT_SECURE_NO_WARNINGS
#include "headers/functions.h"
#include "headers/constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mysql.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "portuguese");
	system("chcp 1252> nul");

	MYSQL* conn = getConnection();
	char x = '0', nome[255], autor[255];
	int paginas;

	while (x != 'S' && x != 's')
	{
		printf("Escolha as seguintes letras:\n");
		printf("a (Para visualizar os livros cadastrado)\n");
		printf("b (Para cadastrar um novo livro)\n");
		printf("s (Para fechar)\n");
		scanf("%c", &x);
		printf("\n");

		if (x == 'A' || x == 'a')
		{
			printf("\n");
			printf("--- Livros cadastrados ---\n");
			printf("\n");

			if (checkData(conn) == 0)
			{
				printf("- Nenhum livro cadastrado -");
				printf("\n");
			}
			else
			{
				printf("#ID - #Nome - #P�ginas - #Autor\n");
				printf("\n");

				read(conn);
			}
		}

		if (x == 'B' || x == 'b')
		{
			char toNome[255] = "", toAutor[255] = "";

			printf("\n");
			printf("--- Cadastrar novo livro ---\n");
			printf("\n");

			printf("Qual o nome do livro?\n");
			scanf(" %[^\n]s", nome);
			strncat(toNome, nome, strlen(nome));

			printf("Quantas p�ginas tem o livro?\n");
			scanf("%d", &paginas);

			printf("Qual o nome do autor do livro?\n");
			scanf(" %[^\n]s", autor);
			strncat(toAutor, autor, strlen(autor));

			printf("\n");

			create(conn, toNome, paginas, toAutor);
		}

		printf("\n--- // ---\n");
		printf("\n");

		getchar();
	}

	printf("\n");

	system("pause");
	return 0;
}