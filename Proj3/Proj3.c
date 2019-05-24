#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

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
	Contato* final;
	int tamanho;
}Lista;

Contato* criar_lista(Contato* c) {

	c = (Contato *) malloc(sizeof(Contato));
	if(c != NULL) {
		c = NULL; // Conteudo de "li" aponta pra NULL
	}
}

int alocarContato(Lista *li, Contato *c) {

	if(malloc(sizeof(Contato)) == NULL) {
		printf("Impossivel alocar novo contato.\n");
		return -1;
	}
	preencher(c);

	return 0;
}

void inicializar(Lista* li) {
	li->inicio = NULL;
	li->final = NULL;
	li->tamanho = 0;
}


void listar_Contatos(Lista *li) {
	Contato *p = li->inicio;
	while(p != NULL) {
		printf("\nNome: %s\nTelefone: %s\nEndereco: %s\nCep: %d\nData de Nascimento: %s\n",
		p->nome, p->telefone, p->endereco, p->cep, p->dataNascimento);
		p = (Contato *) p->prox;// forçando os dois lados da igualdade serem os mesmos tipos
	}
	printf("\n");
}

void preencher(Contato* contato) {

	system("clear");
	__fpurge(stdin);
	printf("Digite o nome completo do Contato: ");
	scanf("%s", contato->nome);
	__fpurge(stdin);

	while (contato->nome == ""){
		printf("Nome vazio. Digite novamente.");
		scanf("%s", contato->nome);
		__fpurge(stdin);
	}
	printf("Digite o telefone do Contato: ");
	scanf("%s", contato->telefone);
	__fpurge(stdin);

	printf("Digite o endereco do Contato: ");
	scanf("%s", contato->endereco);
	__fpurge(stdin);

	printf("Digite o CEP do Contato: ");
	scanf("%d", &(contato->cep));
	__fpurge(stdin);

	printf("Digite a data de nascimento do Contato: ");
	scanf("%[^\n]s", contato->dataNascimento);
	__fpurge(stdin);

	contato->ant = NULL;
	contato->prox = NULL;

}

void inserir_no_final(Lista* agenda, Contato *contato) {
	Contato* aux = (Contato*) malloc(sizeof(Contato));// forçando os dois lados da igualdade serem os mesmos tipos
	*aux = *contato;
	if(agenda->final == NULL) { //para lista vazia
		agenda->inicio = aux;
		agenda->final = aux;
	}
	else {
		agenda->final->prox = (struct Contato*) aux;
		aux->ant = (struct Contato*)agenda->final;
		agenda->final = aux;
	}
}

char menu() {
	char opcao;
	system("clear");
	printf("==========================\n");
	printf("****Agenda de Contatos****\n");
	printf("==========================\n");
	printf("1 - Inserir novo Contato..\n");
	printf("2 - Remover Contato.......\n");
	printf("3 - Pesquisar Contato.....\n");
	printf("4 - Listar Contatos.......\n");
	printf("0 - Sair..................\n\n\n");
	printf("Digite a opcao que deseja realizar: ");
	scanf("%c", &opcao);
	__fpurge(stdin);
	return opcao;
}

int main() {
	char opcao;
	Lista *agenda;
	Contato *contato;
	inicializar(&agenda);
	criar_lista(contato);

	//preencherDoArq(registros);

	do{
		opcao = menu();
		switch(opcao){
			case '1': {
				//printf("AA\n");
				//alocarContato(agenda, contato);
				getchar();
			}
			break;
			case '2':{
				//removerContato();
				getchar();
			}
			break;
			case '3':{
				//visualizarContatos();
				getchar();
			}
			break;
			case '4':{
				//contatosEmOrdem();
				getchar();
			}
			break;
			case '0':{
				//sair();
				getchar();
			}
			break;
			default: {
					printf("Escolha uma opcao valida.\n");
					getchar();
					break;
			}
		}
	}while(opcao != '0');

	//inserir_no_final(&registros, fulano);
	listar_Contatos(agenda);

	return 0;
}
