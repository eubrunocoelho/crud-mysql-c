#define _CRT_SECURE_NO_WARNINGS
#include "headers/Functions.h"
#include "headers/Constants.h"
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

			printf("\n");
			printf("#ID - #Nome - #Páginas - #Autor\n");
			printf("\n");

			Read(conn);
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

			Create(conn, toNome, paginas, toAutor);
		}

		printf("\n--- // ---\n");
		printf("\n");

		getchar();
	}

	printf("\n");

	system("pause");
	return 0;
}