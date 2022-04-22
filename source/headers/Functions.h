#pragma once

#include <windows.h>
#include <mysql.h>

#ifndef FUNCTIONS_H

MYSQL* getConnection();
void Read(MYSQL* conn);
void Create(MYSQL* conn, char nome[255], int paginas, char autor[255]);

#endif