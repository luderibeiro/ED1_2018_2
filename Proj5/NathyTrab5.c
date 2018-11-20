#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio_ext.h>

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
	No* n = (No *)malloc(sizeof(No));
	if(n != NULL){
		n = NULL;
	}
	char path[16] = "./BSTs/\0";
	strcat(path, nomeArquivo);
	fp = fopen(path, "r");
	if(fp == NULL){
		printf("arquivo %s inxistente. Novo arquivo criado.", path);
		return n;
	}
	while(fscanf(fp, "%d ", &valor) != EOF){
		vetor[i] = valor;
		i++;
	}
	fclose(fp);
	return n;
}

int menu(int opcao){
	printf("\n");
	printf("**********************************\n");
	printf("************   MENU   ************\n");
	printf("**********************************\n");
	printf("Escolha a sua opcao --------------\n");
	printf("1- Carregar arvore. --------------\n");
	printf("2- Mostrar arvore. ---------------\n");
	printf("3- Verificar arvore cheia. --------\n");
	printf("4- Procurar valor. ---------------\n");
	printf("5- Altura da arvore --------------\n");
	printf("6- Remover Valor. ----------------\n");
	printf("7- Print in Order. ---------------\n");
	printf("8- Print pre Order. --------------\n");
	printf("9- Print post Order. -------------\n");
	printf("10- Balancear arvore. ------------\n");
	printf("0- Sair.--------------------------\n");
	printf("----------------------------------\n\n");
	printf("Digite a opcao desejada: ");
	scanf("%d", &opcao);
	return opcao;
}

void criarArvore(No *pRaiz)
{
	pRaiz = NULL;
}

No* insercao(No *pRaiz, int numero) {
	No *novo, *aux, *anterior;
	novo=(No*)malloc(sizeof (No));
	novo->esquerda=NULL;
	novo->direita=NULL;
	novo->numero=numero;
	if (pRaiz == NULL)
	{
		pRaiz = novo;
		return novo;
	}
	else
	{
		aux = pRaiz;
		while(aux != NULL){
			anterior = aux;
			if (numero < (aux->numero))
			{
				aux = aux->esquerda;
			}
			else
			{
				aux = aux->direita;
			}
		}
		if (numero < (anterior->numero))
		{
			anterior->esquerda = novo;
		}
		else
		{
			anterior->direita = novo;
		}
	}
	return pRaiz;
}

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

// int contarFolhas(No *pRaiz){
//  if(pRaiz == NULL)
//  return 0;
//  if(pRaiz->esquerda == NULL && pRaiz->direita == NULL)
//  return 1;
//  return contarFolhas(pRaiz->esquerda) + contarFolhas(pRaiz->direita);
// }
int maior(int a, int b){
	if(a > b)
	return a;
	else
	return b;
}//maior



int getHeight(No *pRaiz){
	if((pRaiz == NULL) || (pRaiz->esquerda == NULL && pRaiz->direita == NULL))
	return 0;
	else
	return 1 + maior(getHeight(pRaiz->esquerda), getHeight(pRaiz->direita));
}
void isFull(No* pRaiz) {
	int h = getHeight(pRaiz) + 1, count = contarNos(pRaiz);
	int maximo = pow(2, h) - 1;
	if (maximo != count){
		printf("A arvore não é cheia!\n");
	}else {
		printf("A árvore é cheia!\n");
	}
}

No* freeArvore(No* pRaiz) {
	if(pRaiz != NULL){
		pRaiz = freeArvore(pRaiz->esquerda);
		pRaiz = freeArvore(pRaiz->direita);
		free(pRaiz);
	}
}
No* searchValue(No* pRaiz) {
	int valor;
	No *ant = NULL, *aux = pRaiz;

	printf("Digite um valor desejado: \n");
	scanf("%d\n", &valor);

	if(pRaiz == NULL){
		printf("Arvore nao carregada.\n");
	}
	else{
		while(aux != NULL){
			ant = aux;
			if (valor == aux->numero){
				printf("O valor dele eh: %d\n",aux->numero);
				if (ant == NULL){
					printf("Ele eh a raiz.\n");
				} else{
					printf("Seu pai eh: %d\n",ant->numero);
				}
				return aux;
			}
			else if(valor > aux->numero){
				aux = aux->direita;
			}
			else{
				aux = aux->esquerda;
			}
		}
	}
	return aux;
}

void showTree(No *pRaiz, int nivel){
     int i;
     if(pRaiz == NULL)
        return;
     showTree(pRaiz->direita, nivel+1);
     for(i=0; i < nivel; i++)
        printf("      ");
     printf("%6d\n\n", pRaiz->numero);
     showTree(pRaiz->esquerda, nivel+1);
}


int main () {

	No *pRaiz = NULL;
	int numero2, vetor[10];
	criarArvore(pRaiz);

	int opcao, h;
	No *aqueleCara;
	do {

		opcao = menu(opcao);
		system("clear");
		switch (opcao) {
			case 1:
			pRaiz = freeArvore(pRaiz);
			pRaiz = loadTreeFromFile(pRaiz, vetor);
			for(int i = 0; i < 10; i++){
				pRaiz = insercao(pRaiz, vetor[i]);
			}
			break;

			case 2:
			showTree(pRaiz, 0);
			printf("Pressione ENTER para continuar\n");
			getchar(); getchar();
			break;

			case 3:
			printf("%d\n", contarNos(pRaiz));
			isFull(pRaiz);
			printf("Pressione ENTER para continuar\n");
			getchar(); getchar();
			break;

			case 4:
			aqueleCara = searchValue(pRaiz);
			break;

			case 5:
			h = getHeight(pRaiz);
			h++;
			printf("A altura é %d\n", h);
			printf("Pressione ENTER para continuar\n");
			getchar(); getchar();
			break;

			case 6:
			//removeValue();
			break;

			case 7:
			printInOrder(pRaiz);
			printf("Pressione ENTER para continuar\n");
			getchar(); getchar();
			break;

			case 8:
			printPreOrder(pRaiz);
			printf("Pressione ENTER para continuar\n");
			getchar(); getchar();
			break;

			case 9:
			printPostOrder(pRaiz);
			printf("Pressione ENTER para continuar\n");
			getchar(); getchar();
			break;

			case 10:
			//balanceTree();
			break;

			case 0:
			//liberaArvore();
			break;

			default:
			printf("Escolha invalida \n");
			printf("Pressione ENTER para continuar\n");
			getchar(); getchar();
			break;
		}
	}while (opcao != 0);

	return 0;
}
