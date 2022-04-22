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
		printf("c (Para atualizar dados de um livro)\n");
		printf("d (Para deletar um livro)\n");
		printf("s (Para sair)\n");

		scanf("%c", &x);
		printf("\n");

		if (x == 'A' || x == 'a')
		{
			printf("\n");
			printf("--- Livros cadastrados ---\n");
			printf("\n");

			if (checkData(conn) == TRUE)
			{
				printf("#ID - #Nome - #Páginas - #Autor\n");
				printf("\n");

				read(conn);
			}
			else
			{
				printf("- Nenhum livro cadastrado -");
				printf("\n");
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

			printf("Quantas páginas tem o livro?\n");
			scanf("%d", &paginas);

			printf("Qual o nome do autor do livro?\n");
			scanf(" %[^\n]s", autor);
			strncat(toAutor, autor, strlen(autor));

			printf("\n");

			create(conn, toNome, paginas, toAutor);
		}

		if (x == 'C' || x == 'c')
		{
			int ID;

			printf("\n");
			printf("--- Atualizar dados ---\n");
			printf("\n");

			printf("Informe o ID do livro do livro a ser atualizado\n");
			scanf("%d", &ID);
			printf("\n");

			if (checkDataByID(conn, ID) == TRUE)
			{
				char toNome[255] = "", toAutor[255] = "";

				printf("Qual o nome do livro?\n");
				scanf(" %[^\n]s", nome);
				strncat(toNome, nome, strlen(nome));

				printf("Quantas páginas tem o livro?\n");
				scanf("%d", &paginas);

				printf("Qual o nome do autor do livro?\n");
				scanf(" %[^\n]s", autor);
				strncat(toAutor, autor, strlen(autor));

				printf("\n");

				update(conn, toNome, paginas, toAutor, ID);
			}
			else
			{
				printf("- Não existe livro com o ID informado -");
				printf("\n");
			}
		}

		if (x == 'D' || x == 'd')
		{
			int ID;

			printf("\n");
			printf("--- Deletar um livro ---\n");
			printf("\n");

			printf("Informe o ID do livro do livro a ser deletado\n");
			scanf("%d", &ID);
			printf("\n");

			if (checkDataByID(conn, ID) == TRUE)
			{
				delete(conn, ID);
			}
			else
			{
				printf("- Não existe livro com o ID informado -");
				printf("\n");
			}
		}

		printf("\n--- // ---\n");
		printf("\n");

		getchar();
	}

	printf("\n");

	system("pause");
	return 0;
}