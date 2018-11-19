#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
	int numero;
	struct No *esquerda;
	struct No *direita;
}No;

No* insercao(No *pRaiz, int numero2);

No* loadTreeFromFile(No* pRaiz, int *vetor){

	FILE *fp;
	int valor, i = 0;
	__fpurge(stdin);
	char nomeArquivo[9];
	printf("Digite o nome do arquivo: ");
	fgets(nomeArquivo, 9, stdin);
	if(nomeArquivo[strlen(nomeArquivo)-1] == '\n'){
		nomeArquivo[strlen(nomeArquivo)-1] = '\0';
	}
	printf("Aloo %s\n", nomeArquivo);
	No* n = (No *)malloc(sizeof(No));
	if(n != NULL){
		n = NULL; // Conteudo de "li" aponta pra NULL
	}
	char path[16] = "./BSTs/\0";
	strcat(path, nomeArquivo);
	fp = fopen(path, "r");
	if(fp == NULL){
		printf("arquivo %s inxistente. Novo arquivo criado.", path);
		return n;
	}
	while(fscanf(fp, "%d ", &valor) != EOF){
		printf("%d\n", valor);
		vetor[i] = valor;
		i++;
		//pRaiz = insercao(pRaiz, vetor[i]);
		//pRaiz = insercao(pRaiz, valor);

		}
	fclose(fp);
	return n;
}

int menu(int opcao){
		printf("**********************************\n");
		printf("************   MENU   ************\n");
		printf("**********************************\n");
		printf("Escolha a sua opcao --------------\n");
		printf("1- Carregar pRaiz. --------------\n");
		printf("2- Mostrar pRaiz. ---------------\n");
		printf("3- Verficar pRaiz cheia. --------\n");
		printf("4- Procurar valor. ---------------\n");
		printf("5- Altura da pRaiz --------------\n");
		printf("6- Remover Valor. ----------------\n");
		printf("7- Print in Order. ---------------\n");
		printf("8- Print pre Order. --------------\n");
		printf("9- Print post Order. -------------\n");
		printf("10- Balancear pRaiz. ------------\n");
		printf("0- Sair.--------------------------\n");
		printf("----------------------------------\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opcao);
		return opcao;
}

void criarArvore(No *pRaiz)
{
	pRaiz = NULL;
}

No* insercao(No *pRaiz,int valor){
  No *novo = (No*)malloc(sizeof(No));
  No *aux = pRaiz;
  No *ant;
  novo->numero = valor;
  novo->esquerda = NULL;
  novo->direita = NULL;
  if(pRaiz == NULL){
    pRaiz = novo;
    return novo;
  }
  else{
    while(aux != NULL){
      ant = aux;
      if(valor > aux->numero){
        aux = aux->direita;
      }
      else{
        aux = aux->esquerda;
      }
    }
    if(valor > ant->numero){
      ant->direita = novo;
    }
    else{
      ant->esquerda = novo;
    }
  }
  return pRaiz;
}

// No* insercao(No *pRaiz, int numero2)
// {
// 	No *novo, *aux, *anterior;
// 	novo=(No*)malloc(sizeof (No));
// 	novo->esquerda=NULL;
// 	novo->direita=NULL;
// 	novo->numero=numero2;
// 	if (pRaiz == NULL)
// 	{
// 		pRaiz = novo;
// 		return novo;
// 	}
// 	else
// 	{
// 		aux = pRaiz;
// 		while(aux != NULL){
// 			anterior = aux;
// 			if (numero2 < (aux->numero))
// 			{
// 				aux = aux->esquerda;
// 			}
// 			else
// 			{
// 				aux = aux->direita;
// 			}
// 		}
// 		if (numero2 < (anterior->numero))
// 		{
// 			anterior->esquerda = novo;
// 		}
// 		else
// 		{
// 			anterior->direita = novo;
// 		}
// 	}
// 	return pRaiz;
// }
void printInOrder(No *pRaiz){
	if(pRaiz != NULL){
		printInOrder(pRaiz->esquerda);
		printf("%d\n\n", pRaiz->numero);
		printInOrder(pRaiz->direita);
	}
}
void printPreOrder(No *pRaiz){
	if(pRaiz != NULL){
		printf("%d\n\n", pRaiz->numero);
		printPreOrder(pRaiz->esquerda);
		printPreOrder(pRaiz->direita);
	}
}
void printPostOrder(No *pRaiz){
	if(pRaiz != NULL){
		printPostOrder(pRaiz->esquerda);
		printPostOrder(pRaiz->direita);
		printf("%d\n\n", pRaiz->numero);
	}
}
int contarNos(No *pRaiz){
	if(pRaiz == NULL)
	return 0;
	else
	return 1 + contarNos(pRaiz->esquerda) + contarNos(pRaiz->direita);
}
int contarFolhas(No *pRaiz){
	if(pRaiz == NULL)
	return 0;
	if(pRaiz->esquerda == NULL && pRaiz->direita == NULL)
	return 1;
	return contarFolhas(pRaiz->esquerda) + contarFolhas(pRaiz->direita);
}
int maior(int a, int b){
	if(a > b)
	return a;
	else
	return b;
}//maior



int altura(No *pRaiz){
	if((pRaiz == NULL) || (pRaiz->esquerda == NULL && pRaiz->direita == NULL))
	return 0;
	else
	return 1 + maior(altura(pRaiz->esquerda), altura(pRaiz->direita));
}


int main () {

	No *pRaiz = NULL;
	int numero2, vetor[10];
	criarArvore(pRaiz);
	//insercao(pRaiz,2);
	///insercao(pRaiz,4);
	//insercao(pRaiz,1);
	//printInOrder(pRaiz);
	printf("Rodou!\n");

	int opcao;
	do {

		opcao = menu(opcao);
		system("clear");
		switch (opcao) {
			case 1:
			pRaiz = loadTreeFromFile(pRaiz, vetor);
			for(int i = 0; i < 10; i++){
				pRaiz = insercao(pRaiz, vetor[i]);
			}
			break;

			case 2:
			//showTree();
			break;

			case 3:
			//isFull();
			break;

			case 4:
			//searchValue();
			break;

			case 5:
			//getHeight();
			break;

			case 6:
			//removeValue();
			break;

			case 7:
			// pRaiz = insercao(pRaiz, 100);
			// pRaiz = insercao(pRaiz, 20);
			// pRaiz = insercao(pRaiz, 120);
			printInOrder(pRaiz);
			break;

			case 8:
			printPreOrder(pRaiz);
			break;

			case 9:
			printPostOrder(pRaiz);
			break;

			case 10:
			//balanceTree();
			break;

			case 0:
			//liberaArvore();
			break;

			default:
			printf("Escolha invalida, digite novamente: ");
			scanf("%d", &opcao);
			break;
		}
	}while (opcao != 0);

	return 0;
}
