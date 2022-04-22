#pragma once

#ifndef CONSTANTS_H

// Querys MySQL
#define CREATE "INSERT INTO livros(nome, paginas, autor) values(?, ?, ?)"
#define READ "SELECT ID, nome, paginas, autor FROM livros"

#endif