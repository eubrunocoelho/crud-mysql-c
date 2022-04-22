#include "../headers/functions.h"
#include "../headers/constants.h"
#include <stdio.h>
#include <stdlib.h>

void create(MYSQL* conn, char nome[255], int paginas, char autor[255])
{
	MYSQL* stmt;
	MYSQL_BIND param[3];

	stmt = mysql_stmt_init(conn);

	if (!stmt)
	{
		fprintf(stderr, "mysql_stmt_init(), out of memory!\n");
		exit(1);
	}

	if (mysql_stmt_prepare(stmt, CREATE, strlen(CREATE)))
	{
		fprintf(stderr, "mysql_stmt_prepare(), INSERT failed!\n");
		fprintf(stderr, "%s\n", mysql_stmt_error(stmt));
		exit(1);
	}

	memset(param, 0, sizeof(param));

	param[0].buffer_type = MYSQL_TYPE_STRING;
	param[0].buffer = (char*)nome;
	param[0].buffer_length = 255;
	param[0].is_null = 0;


	param[1].buffer_type = MYSQL_TYPE_LONG;
	param[1].buffer = (char*)&paginas;
	param[1].is_null = 0;

	param[2].buffer_type = MYSQL_TYPE_STRING;
	param[2].buffer = (char*)autor;
	param[2].buffer_length = 255;
	param[2].is_null = 0;

	if (mysql_stmt_bind_param(stmt, param))
	{
		fprintf(stderr, "mysql_stmt_bind_param(), failed!\n");
		fprintf(stderr, "%s\n", mysql_stmt_error(stmt));
		exit(1);
	}

	if (mysql_stmt_execute(stmt))
	{
		fprintf(stderr, "mysql_stmt_execute(), failed!\n");
		fprintf(stderr, "%s\n", mysql_stmt_error(stmt));
		exit(1);
	}
	else
	{
		printf("Livro cadastrado com sucesso!\n");
	}

	if (mysql_stmt_close(stmt))
	{
		fprintf(stderr, "failed while closing the statement\n");
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
}