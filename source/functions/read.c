#include "../headers/functions.h"
#include "../headers/constants.h"
#include <stdio.h>
#include <stdlib.h>

void read(MYSQL* conn)
{
	MYSQL_STMT* stmt;
	MYSQL_BIND result[4];
	MYSQL_RES* prepare_meta_result;
	int ID, paginas;
	char nome[255], autor[255];

	stmt = mysql_stmt_init(conn);

	if (!stmt)
	{
		fprintf(stderr, "mysql_stmt_init(), out of memory!\n");
		exit(1);
	}

	if (mysql_stmt_prepare(stmt, READ, strlen(READ)))
	{
		fprintf(stderr, "mysql_stmt_prepare(), SELECT failed!\n");
		fprintf(stderr, "%s\n", mysql_stmt_error(stmt));
		exit(1);
	}

	memset(result, 0, sizeof(result));

	// ID (int)
	result[0].buffer_type = MYSQL_TYPE_LONG;
	result[0].buffer = (char*)&ID;
	result[0].is_null = 0;

	// nome (string)
	result[1].buffer_type = MYSQL_TYPE_STRING;
	result[1].buffer = (char*)nome;
	result[1].buffer_length = 255;
	result[1].is_null = 0;

	// paginas (int)
	result[2].buffer_type = MYSQL_TYPE_LONG;
	result[2].buffer = (char*)&paginas;
	result[2].is_null = 0;

	// autor (string)
	result[3].buffer_type = MYSQL_TYPE_STRING;
	result[3].buffer = (char*)autor;
	result[3].buffer_length = 255;
	result[3].is_null = 0;

	if (mysql_stmt_bind_result(stmt, result))
	{
		fprintf(stderr, "mysql_stmt_bind_result(), failed!\n");
		fprintf(stderr, "%s\n", mysql_stmt_error(stmt));
		exit(1);
	}

	if (mysql_stmt_execute(stmt))
	{
		fprintf(stderr, "mysql_stmt_execute(), failed!\n");
		fprintf(stderr, "%s\n", mysql_stmt_error(stmt));
		exit(1);
	}

	prepare_meta_result = mysql_stmt_result_metadata(stmt);

	while (!mysql_stmt_fetch(stmt))
	{
		printf("%d --- %s --- %d --- %s\n", ID, nome, paginas, autor);
	}

	mysql_free_result(prepare_meta_result);

	if (mysql_stmt_close(stmt))
	{
		fprintf(stderr, "failed while closing the statement\n");
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
}
