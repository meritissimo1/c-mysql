#include "main.h"

int main() 
{
	int	option;
	MYSQL	*mysql;

	mysql = load_mysql_db();

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
				printf("Saindo... até a próxima o/\n *vlw, hector* "); // ainda vem muito pela frente.
				mysql_close(mysql);
				return (0);
			case BUSCAR:
				search(mysql);
				break;
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
	mysql_close(mysql);
	return (0);
}
