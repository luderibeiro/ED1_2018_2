#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
	char nome[101];
	char telefone[11];
	char endereco[101];
	unsigned int cep;
	char dataNascimento[11];
}Contato;

typedef struct Lista{
	struct Lista* prox;
	Contato* dados;
	struct Lista* ant;
}Lista;

void *ListaContatos(Lista *li);
Contato* criar_lista(Contato* c);
void *ListaContatos(Lista *li);
void preencher(Contato* f, Lista *li);
//int alocarContato(Lista *li, Contato *c);



Contato* criar_lista(Contato* c){
  FILE *fp;
  c = (Contato *) malloc(sizeof(Contato));
  if(c != NULL){
    c = NULL; // Conteudo de "li" aponta pra NULL
  }
}

/*int alocarContato(Lista *li, Contato *c){

		Contato *novoContato;
		if((novoContato == malloc(novoContato)) ==NULL){
			return -1;
		}
		preencher(novoContato);
		c = novoContato;

		return 0;
}*/


//do primeiro em diante
/*void listar_Contatos(Lista li) {
	Contato * p = li.primeiro;
	while(p != NULL) {
		printf("\nNome: %s\nTelefone: %s\nEndereco: %s\nCep: %d\nData de Nascimento: %s\n",
							p->nome, p->telefone, p->endereco, p->cep, p->dataNascimento);
		p = (Contato *) p->prox;// forçando os dois lados da igualdade serem os mesmos tipos
	}
	printf("\n");
}*/

void *ListaContatos(Lista *li){
  Lista *aux;

  char cifrao = '$';

  if(li == NULL)
  {
    printf("\nLista nao existe!\n");
    exit(-2);
  }

  if(li->dados == NULL)
  {
    printf("\nLista vazia, registre um novo contato\n");
    exit(-3);
  }

  for(aux = li; aux != NULL; aux = aux->prox){
    printf("Nome: %s\n", aux->dados->nome);
    printf("Telefone: %s\n", aux->dados->telefone);
    printf("Endereco: %s\n", aux->dados->endereco);
    printf("CEP: %u\n", aux->dados->cep);
    printf("Data de Nascimento: %s\n", aux->dados->dataNascimento);
    printf("%c\n", cifrao);
  }
}


//"f" de fulano
void preencher(Contato* f, Lista *li) {

	system("clear");
	li = (Lista *) malloc(sizeof(Lista));
	f = (Contato *) malloc(sizeof(Contato));
	__fpurge(stdin);
	printf("Digite o nome completo do Contato: ");
	scanf("%s", f->nome);
	__fpurge(stdin);

	while (f->nome == ""){
		printf("Nome vazio. Digite novamente.");
		scanf("%s", f->nome);
		__fpurge(stdin);
	}
	printf("Digite o telefone do Contato: ");
	scanf("%s", f->telefone);
	__fpurge(stdin);

	printf("Digite o endereco do Contato: ");
	scanf("%s", f->endereco);
	__fpurge(stdin);

	printf("Digite o CEP do Contato: ");
	scanf("%u", &(f->cep));
	__fpurge(stdin);

	printf("Digite a data de nascimento do Contato: ");
	scanf("%[^\n]s", f->dataNascimento);
	__fpurge(stdin);

	li->ant = NULL;
	li->prox = NULL;

}
/*void inserir_no_final(Lista* li, Contato *f) {
	Contato* aux = (Contato*) malloc(sizeof(Contato));// forçando os dois lados da igualdade serem os mesmos tipos
	*aux = *f;
	if(li->ultimo == NULL) { //para lista vazia
		li->primeiro = aux;
		li->ultimo = aux;
	}
	else {
		li->ultimo->prox = (struct Contato*) aux;
		aux-> ant = (struct Contato*)li->ultimo;
		li->ultimo = aux;
	}
}*/

char menu(){
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
	char opcao = 0;
	Lista *registros;
	Contato *fulano;
	criar_lista(fulano);
	//preencher(fulano);

	do{
    opcao = menu();
    switch(opcao){
      case '1': {
				preencher(fulano, registros);
      }
      break;
      case '2':{
        //listaContatos(registros);
      }
      break;
      case '3':{
        //visualizarContatos();
      }
      break;
      case '4':{
        //contatosEmOrdem();
      }
      break;
      case '0':{
				system("clear");
        exit(0);
      }
      break;
      //default;
    }
  }while(opcao != 0);

	//inserir_no_final(&registros, fulano);
	//listar_Contatos(registros);
}
