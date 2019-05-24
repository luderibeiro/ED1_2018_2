#include <stdio.h>
#include <stdlib.h>




typedef struct {
	char nome[101];
	char telefone[11];
	char endereco[101];
	unsigned int cep;
	char dataNascimento[11];
	struct Contato* prox;
	struct Contato* ant;
}Contato;

typedef struct {
	Contato* inicio;
	Contato* fim;
}Lista;




void menu() {
	system("clear");
	printf("==========================\n");
	printf("****Agenda de Contatos****\n");
	printf("==========================\n");
	printf("1 - Inserir novo Contato..\n");
	printf("2 - Remover Contato.......\n");
	printf("3 - Pesquisar Contato.....\n");
	printf("4 - Listar Contatos.......\n");
	printf("0 - Sair..................\n\n");
	printf("Digite a opcao que deseja realizar: ");
}

int main() {
	char opcao;
	printf("%c\n", opcao);
	Lista *registros;
	Contato *fulano;


	do{
		menu();
		opcao = getchar();
		__fpurge(stdin);

		printf("%c\n", opcao);
		switch(opcao){
			case '1':
				printf("AAAAAAAAAAAA\n");
				break;
			case '2':
				//removerContato();
				printf("BBBBBBBBBBBB\n");
				break;
			case '3':
				//visualizarContatos();
				printf("CCCCCCCCCC\n");
				break;
			case '4':
				//contatosEmOrdem();
				printf("DDDDDDDDDD\n");
				break;
			case '0':
				//sair();
				printf("SAIR\n");
				break;
			default:
				printf("Valor invalido. Digite uma opcao valida.\n");
		}
	}while(opcao != '0');

	return 0;
}

// FILE *arq;
// arq = fopen("contatos.txt", r);
// if(arq == NULL){
// 	arq = fopen("contatos.txt", w);
// }
//
