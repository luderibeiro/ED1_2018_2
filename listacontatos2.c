#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contato{
    char nome[101];
    char telefone[10];
    char endereco[101];
    int cep;
    char dataNascimento;
};

typedef struct elemento* Lista;

struct elemento{
    struct elemento *prox;
    struct elemento dados;
    struct elemento *prox;
};

typedef struct elemento Element;

Lista* criar_lista();
void liberar_lista(Lista* li);
int tamanho_lista(Lista* li);

int main(){

    //int opcao;
    li = criar_lista();
    liberar_lista(li);
    

    int x = tamanho_lista(li);




    return 0;
}

Lista* criar_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL; // Conteudo de "li" aponta pra NULL
    }
    return li;
}
void liberar_lista(Lista* li){
    if(li != NULL){
        Elem* no;
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
