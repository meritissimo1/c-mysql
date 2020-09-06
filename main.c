# include <stdio.h>
# include <mysql.h>

# include "main.h"

MYSQL mysql;

int main() {

	int option;
	mysql_init(&mysql);
	if(!mysql_real_connect(&mysql, HOST, USER, PASS, BASE, 0, NULL, 0)) {
		printf("Falha ao se conectar com a base de dados: Erro: %s\n", mysql_error(&mysql));
		return 1;
	}

	while(1) {

		option = menu();

		switch(option) {
			case SAIR:
				printf("Saindo...");
				return 0;
			case BUSCAR:
				search(&mysql);
			case INSERIR:
				break;
			case ATUALIZAR:
				break;
			case REMOVER:
				break;
			default:
				printf("Opção inválida!\n");
		}

	}

	return 0;

}

int menu() {
	int option;
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s",
		"###### MySQL ######",
		"[1] Buscar",
		"[2] Inserir",
		"[3] Atualizar",
		"[4] Remover",
		"[0] Sair",
		"Selecione uma opção: ");
	scanf("%d", &option);
	return option;
}

void search(MYSQL *mysql) {

	MYSQL_RES *result;
	MYSQL_ROW row;
	//unsigned int nf, nr;

	char nome[100], query[500];
	printf("Digite um pedaço do nome: ");
	scanf("%s", nome);
	sprintf(query, "SELECT * FROM usuarios WHERE nome LIKE '%%%s%%'", nome);
	if(mysql_query(mysql, query)) {
		printf("Falha ao se conectar com a base de dados: Erro: %s\n", mysql_error(mysql));
		return;
	} else {
		if((result = mysql_store_result(mysql)) != NULL) {
			//nf = mysql_num_fields(result);
			while ((row = mysql_fetch_row(result))) {
				printf("%s - %-30s%30s\n", row[0], row[1], row[2]);
			}
		} else {
			printf("Nenhum registro com '%s' encontrado.\n", nome);
		}
	}
}
