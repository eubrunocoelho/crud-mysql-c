#pragma once

#include <windows.h>
#include <mysql.h>

#ifndef FUNCTIONS_H

MYSQL* getConnection();
void read(MYSQL* conn);
void create(MYSQL* conn, char nome[255], int paginas, char autor[255]);
int checkData(MYSQL* conn);

#endif