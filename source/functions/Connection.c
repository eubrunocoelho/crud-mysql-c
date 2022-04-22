#include "../headers/Functions.h";
#include <stdio.h>
#include <stdlib.h>

MYSQL* getConnection()
{
	MYSQL* conn = mysql_init(NULL);

	if (conn == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	if (mysql_real_connect(conn, "localhost", "root", "123456", "livrariaC", 0, NULL, 0) == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		return 0;
	}

	return conn;
}