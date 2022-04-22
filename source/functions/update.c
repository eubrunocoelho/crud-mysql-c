#include "../headers/functions.h"
#include "../headers/constants.h"
#include <stdio.h>
#include <stdlib.h>

void update(MYSQL* conn, char nome[255], int paginas, char autor[255], int ID)
{
	MYSQL_STMT* stmt;
	MYSQL_BIND param[4];

	stmt = mysql_stmt_init(conn);

	if (!stmt)
	{
		fprintf(stderr, "mysql_stmt_init(), out of memory!\n");
		exit(1);
	}

	if (mysql_stmt_prepare(stmt, UPDATE, strlen(UPDATE)))
	{
		fprintf(stderr, "mysql_stmt_prepare(), INSERT failed!\n");
		fprintf(stderr, "%s\n", mysql_stmt_error(stmt));
		exit(1);
	}

	memset(param, 0, sizeof(param));

	// nome (string)
	param[0].buffer_type = MYSQL_TYPE_STRING;
	param[0].buffer = (char*)nome;
	param[0].buffer_length = 255;
	param[0].is_null = 0;

	// paginas (int)
	param[1].buffer_type = MYSQL_TYPE_LONG;
	param[1].buffer = (char*)&paginas;
	param[1].is_null = 0;

	// autor (string)
	param[2].buffer_type = MYSQL_TYPE_STRING;
	param[2].buffer = (char*)autor;
	param[2].buffer_length = 255;
	param[2].is_null = 0;

	// ID (int)
	param[3].buffer_type = MYSQL_TYPE_LONG;
	param[3].buffer = (char*)&ID;
	param[3].is_null = 0;
	
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
		printf("Livro atualizado com sucesso!\n");
	}

	if (mysql_stmt_close(stmt))
	{
		fprintf(stderr, "failed while closing the statement\n");
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
}