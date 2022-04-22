#pragma once

#ifndef CONSTANTS_H

// Querys MySQL
#define CREATE "INSERT INTO livros(nome, paginas, autor) VALUES(?, ?, ?)"
#define READ "SELECT ID, nome, paginas, autor FROM livros"
#define UPDATE "UPDATE livros SET nome = ?, paginas = ?, autor = ? WHERE ID = ?"
#define DELETE "DELETE FROM livros WHERE ID = ?"
#define CHECK_DATA "SELECT * FROM livros"
#define CHECK_DATA_BY_ID "SELECT * FROM livros WHERE ID = ?"

// Valores booleanos
#define TRUE 1
#define FALSE 0

#endif