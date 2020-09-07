#include "./db_mysql.h"

void load_mysql_db() 
{
    FILE *fp;
    fp = fopen(SQL_FILE, "r");
    ssize_t read;
    char * line = NULL;
    size_t len = 0;
        
    if (fp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    mysql_init(&mysql);
    
	if(!mysql_real_connect(&mysql, HOST, USER, PASS, NULL, 0, NULL, 0)) {
		printf("Falha ao se conectar com a base de dados: Erro: %s\n", mysql_error(&mysql));
		exit(1);
	}
    
    // Definindo default database
    if (mysql_select_db(&mysql, BASE))
    {
        while ((read = getline(&line, &len, fp)) != -1)
        {
            if (mysql_query(&mysql, line))
            {
                printf("Failed Query: %s", line);
                printf("Cause: %s\n", mysql_error(&mysql));
                exit(1);
            }   
        }
    
        fclose(fp);
    }
}

void search() {

	MYSQL_RES *result;
	MYSQL_ROW row;

	char nome[100], query[500];
	printf("Digite um pedaço do nome: ");
	scanf("%s", nome);
	sprintf(query, "SELECT * FROM usuarios WHERE nome LIKE '%%%s%%'", nome);
    
	if (mysql_query(&mysql, query)) 
    {
		printf("Falha ao se conectar com a base de dados: Erro: %s\n", mysql_error(&mysql));
		return;
	} 
	else {
		if((result = mysql_store_result(&mysql)) != NULL) {
			while ((row = mysql_fetch_row(result))) {
				printf("%s - %-30s%30s\n", row[0], row[1], row[2]);
			}
		} else {
			printf("Nenhum registro com '%s' encontrado.\n", nome);
		}
	}
}
