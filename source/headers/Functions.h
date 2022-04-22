#pragma once

#include <windows.h>
#include <mysql.h>

#ifndef FUNCTIONS_H

// Connection
MYSQL* getConnection();

// CRUD
void create(MYSQL* conn, char nome[255], int paginas, char autor[255]);
void read(MYSQL* conn);
void update(MYSQL* conn, char nome[255], int paginas, char autor[255], int ID);
void delete(MYSQL* conn, int ID);

// Check data
int checkData(MYSQL* conn);
int checkDataByID(MYSQL* conn, int ID);

#endif