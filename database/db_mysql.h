#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

#define SQL_FILE "database.sql"
#define HOST "127.0.0.1"
#define PORT 3306
#define USER "thiago"
#define PASS "admin"
#define BASE "clang"

MYSQL mysql;

MYSQL*	load_mysql_db(); 
void	search(MYSQL *mysql);
