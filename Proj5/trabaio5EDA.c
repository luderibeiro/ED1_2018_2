#include <stdio.h>
#include <stdlib.h>

FILE *arq;

typedef struct nod{
	int numero;
	struct nod *esquerda;
	struct nod *direita;
}No;

int menu(int opcao);
// void loadTreeFromFile();
// void showTree();
// void isFull();
// void searchValue();
// void getHeight();
// void removeValue();
// void printInOrder();
// void printPreOrder();
// void printPostOrder();
// void balanceTree();
// void liberaArvore();

void criarArvore(No ***pRaiz){

	*pRaiz = NULL;
}


int main(int argc, char const *argv[]) {

	No **pRaiz;
	criarArvore(&pRaiz);
	int opcao;
	while (opcao != 0) {

		opcao = menu(opcao);
		system("clear");
		switch (opcao) {
			case 1:
			//loadTreeFromFile();
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
			//printInOrder();
			break;

			case 8:
			//printPreOrder();
			break;

			case 9:
			//printPostOrder();
			break;

			case 10:
			//balanceTree();
			break;

			case 0:
			//liberaArvore();
			break;

			default:
			printf("Escloha invalida, digite novamente: ");
			scanf("%d", &opcao);
			break;
		}
	}


	return 0;
}

int menu(int opcao){
		printf("**********************************\n");
		printf("************   MENU   ************\n");
		printf("**********************************\n");
		printf("Escolha a sua opcao --------------\n");
		printf("1- Carregar Arvore. --------------\n");
		printf("2- Mostrar Arvore. ---------------\n");
		printf("3- Verficar Arvore cheia. --------\n");
		printf("4- Procurar valor. ---------------\n");
		printf("5- Altura da Arvore --------------\n");
		printf("6- Remover Valor. ----------------\n");
		printf("7- Print in Order. ---------------\n");
		printf("8- Print pre Order. --------------\n");
		printf("9- Print post Order. -------------\n");
		printf("10- Balancear Arvore. ------------\n");
		printf("0- Sair.--------------------------\n");
		printf("----------------------------------\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opcao);
		return opcao;
}
