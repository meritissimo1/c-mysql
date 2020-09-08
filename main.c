#include "main.h"

int main() 
{
	int option;
	
	load_mysql_db();

	while (1) {

		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s",
		"###### MySQL ######",
		"[1] Buscar",
		"[2] Inserir",
		"[3] Atualizar",
		"[4] Remover",
		"[0] Sair",
		"Selecione uma opção: ");
        scanf("%d", &option);

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
