#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char menu();

struct contato{
  char nome[101];
  char telefone[10];
  char endereco[101];
  int cep;
  char dataNascimento;
};


typedef struct elemento* Lista;

struct elemento{
  struct elemento *ant;
  struct elemento dados;
  struct elemento *prox;
};

typedef struct elemento Element;

Lista* criar_lista();
void liberar_lista(Lista* li);
int tamanho_lista(Lista* li);

int main(){

  char opcao;
  li = criar_lista();
  //liberar_lista(li);
  //int x = tamanho_lista(li);
  do{
    opcao = menu();
    switch(opcao){
      case '1': {
        inserirContato();
      }
      break;
      case '2':{
        //removerContato();
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
        //sair();
      }
      break;
      //default;
    }
  }while(opcao != 0);

  return 0;
}

Lista* criar_lista(){
  FILE *fp;
  Lista* li = (Lista *)malloc(sizeof(Lista));
  if(li != NULL){
    *li = NULL; // Conteudo de "li" aponta pra NULL
  }
  fp = fopen("contatos.txt", "r+");
  if(fp == NULL){
    printf("arquivo contatos.txt inxistente. Novo arquivo criado.");
    return li;
  }
  while(!feof(fp)){
    li = (LISTA *) malloc(1*sizeof(LISTA));
    fread(&li->dados, sizeof(contato), 1, fp);
    li->prox = NULL;
    if(primeiro == NULL){
      primeiro = li;
      ultimo = primeiro;
    }else{
      ultimo->prox = li;
      //ultimo->ant = ;
      ultimo = li;
    }
  }
  return li;
}
void liberar_lista(Lista* li){
  if(li != NULL){
    Element* no;
    while((*li) != NULL){
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}
int tamanho_lista(Lista* li){
  if(li == NULL){
    return 0;
  }
  int count = 0;
  Elem* no = *li;

  while (no != NULL) {
    count++;
    no = no->prox;
  }
  return count;
}

Lista inserirContato(Lista *li, struct contato c){
  Lista *novo;
  novo = (Lista *) calloc(1*sizeof(Lista));

  printf("Digite o nome completo do contato: ");
  scanf("%[^\n]s", elemento->nome);
  fflush(stdin);
  while (contato.nome == ""){
      printf("Nome vazio. Digite novamente.");
      scanf("%[^\n]s", elemento->nome);
      fflush(stdin);
  }
  printf("Digite o telefone do contato: ");
  scanf("%[^\n]s", elemento->telefone);

  printf("Digite o endereco do contato: ");
  scanf("%[^\n]s", elemento->endereco);

  printf("Digite o CEP do contato: ");
  scanf("%[^\n]s", elemento->cep);

  printf("Digite a data de nascimento do contato: ");
  scanf("%[^\n]s", elemento->dataNascimento);]

  return *li;
}



removerContato(Lista *li, ){


}

char menu(){
  char opcao;
  printf("1 - Inserir novo contato\n");
  printf("2 - Remover contato.\n");
  printf("3 - Pesquisar contato.\n");
  printf("4 - Listar contatos.\n");
  printf("0 - Sair.\n");
  scanf("%c", &opcao);
  return opcao;
}
