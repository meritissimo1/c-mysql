#include <mysql.h>

#define SQL_FILE "database.sql"
#define HOST "127.0.0.1"
#define PORT 3306
#define USER "thiago"
#define PASS "admin"
#define BASE "clang"

enum opcao {
	SAIR, BUSCAR, INSERIR, ATUALIZAR, REMOVER
};

int menu();
void search(MYSQL *mysql);
