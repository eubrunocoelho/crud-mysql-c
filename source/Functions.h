#pragma once

#include <windows.h>
#include <mysql.h>

#ifndef FUNCTIONS_H

MYSQL* getConnection();
void Read(MYSQL* conn);

#endif