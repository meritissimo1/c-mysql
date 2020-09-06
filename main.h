# include <mysql.h>

# define HOST "127.0.0.1"
# define PORT 3306
# define USER "clang"
# define PASS "senh@"
# define BASE "clang"

enum opcao {
	SAIR, BUSCAR, INSERIR, ATUALIZAR, REMOVER
};

int menu();

void search(MYSQL *mysql);
