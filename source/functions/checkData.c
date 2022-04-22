#include "../headers/functions.h"
#include "../headers/constants.h"
#include <stdio.h>
#include <stdlib.h>

int checkData(MYSQL* conn)
{
	MYSQL_STMT* stmt;
	MYSQL_RES* prepare_meta_result;
	int returnedData;

	stmt = mysql_stmt_init(conn);

	if (!stmt)
	{
		fprintf(stderr, "mysql_stmt_init(), out of memory!\n");
		exit(1);
	}

	if (mysql_stmt_prepare(stmt, CHECK_DATA, strlen(CHECK_DATA)))
	{
		fprintf(stderr, "mysql_stmt_prepare(), SELECT failed!\n");
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

	if (mysql_stmt_fetch(stmt) != 100)
	{
		returnedData = TRUE;
	}
	else
	{
		returnedData = FALSE;
	}

	mysql_free_result(prepare_meta_result);

	if (mysql_stmt_close(stmt))
	{
		fprintf(stderr, "failed while closing the statement\n");
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	if (returnedData == TRUE)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}