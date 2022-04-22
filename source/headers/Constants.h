#pragma once

#ifndef CONSTANTS_H

// Querys MySQL
#define CREATE "INSERT INTO livros(nome, paginas, autor) VALUES(?, ?, ?)"
#define READ "SELECT ID, nome, paginas, autor FROM livros"
#define CHECK_DATA "SELECT * FROM livros"

// Bool
#define TRUE 1
#define FALSE 0

#endif