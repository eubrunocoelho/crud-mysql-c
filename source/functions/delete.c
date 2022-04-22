#include "../headers/functions.h"
#include "../headers/constants.h"
#include <stdio.h>
#include <stdlib.h>

void delete(MYSQL* conn, int ID)
{
	MYSQL_STMT* stmt;
	MYSQL_BIND param[1];
	MYSQL_RES* prepare_meta_result;

	stmt = mysql_stmt_init(conn);

	if (!stmt)
	{
		fprintf(stderr, "mysql_stmt_init(), out of memory!\n");
		exit(1);
	}

	if (mysql_stmt_prepare(stmt, DELETE, strlen(DELETE)))
	{
		fprintf(stderr, "mysql_stmt_prepare(), INSERT failed!\n");
		fprintf(stderr, "%s\n", mysql_stmt_error(stmt));
		exit(1);
	}

	memset(param, 0, sizeof(param));

	// ID (int)
	param[0].buffer_type = MYSQL_TYPE_LONG;
	param[0].buffer = (char*)&ID;
	param[0].is_null = 0;

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
		printf("Livro deletado com sucesso!\n");
	}

	prepare_meta_result = mysql_stmt_result_metadata(stmt);

	mysql_free_result(prepare_meta_result);

	if (mysql_stmt_close(stmt))
	{
		fprintf(stderr, "failed while closing the statement\n");
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
}