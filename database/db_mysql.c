#include "./db_mysql.h"

MYSQL* load_mysql_db() 
{
    MYSQL *mysql = mysql_init(NULL);
 
    if (!mysql)
    {
	    printf("Init Failed");
	    exit(EXIT_FAILURE);
    }
    if(!mysql_real_connect(mysql, HOST, USER, PASS, NULL, 0, NULL, 0)) {
	printf("Failed to connect with the data base: Error: %s\n", mysql_error(mysql));
	mysql_close(mysql);
	exit(EXIT_FAILURE);
    }
    


    // Definindo default database
    if (mysql_select_db(mysql, BASE))
    {
    	FILE *fp;
     	ssize_t read;
     	char *line = NULL;
     	size_t len = 0;
    	
	fp = fopen(SQL_FILE, "r");
        if (!fp)
            {
                printf("Failed to open file\n");
		mysql_close(mysql);
		exit(EXIT_FAILURE);
        
            }
	
     	while ((read = getline(&line, &len, fp)) != -1)
	{
	     if (mysql_query(mysql, line))
	     {
		     printf("Failed Query: %s", line);
		     printf("cause: %s\n", mysql_error(mysql));
		     fclose(fp);
		     free(line);
		     mysql_close(mysql);
		     exit(EXIT_FAILURE);
	     }
    	}
         
    free(line);
    fclose(fp);
    }
    return (mysql);
}


void search(MYSQL *mysql) {

	MYSQL_RES *result;
	MYSQL_ROW row;

	char nome[100], query[500];
	printf("Enter a name: ");
	scanf("%s", nome);
	sprintf(query, "SELECT * FROM usuarios WHERE nome LIKE '%%%s%%'", nome);
    
	if (mysql_query(mysql, query)) 
    {
		printf("Failed to connect with the data base: Error: %s\n", mysql_error(mysql));
		return;
	} 
	else {
		if((result = mysql_store_result(mysql)) != NULL) {
			while ((row = mysql_fetch_row(result))) {
				printf("%s - %-30s%30s\n", row[0], row[1], row[2]);
			}
			mysql_free_result(result);
		} else {
			printf("No registration found for: '%s'.\n", nome);
		}
	}
}
