#include <stdio.h>
#include <stdlib.h>
//#include "bTrees.h"

int menu(int opcao);

int main(int argc, char const *argv[]) {

	int opcao;
	while (opcao != 0) {
		opcao = menu(opcao);

		system("clear");
		printf("Opcao escolhida: %d\n", opcao);
		switch (opcao) {
			case 1:
			//
			break;

			case 2:
			//
			break;

			case 3:
			//
			break;

			case 4:
			//
			break;

			case 5:
			//
			break;

			case 6:
			//
			break;

			case 7:
			//
			break;

			case 8:
			//
			break;

			case 9:
			//
			break;

			case 10:
			//
			break;

			case 0:
			//
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
		printf("--------------------------\n");
		printf("-----------MENU-----------\n");
		printf("--------------------------\n");
		printf("Escolha a sua opcao ------\n");
		printf("1- Carregar Arvore. ------\n");
		printf("2- Mostrar Arvore. -------\n");
		printf("3- Verficar Arvore cheia. \n");
		printf("4- Procurar valor. -------\n");
		printf("5- Altura da Arvore ------\n");
		printf("6- Remover Valor. --------\n");
		printf("7- Print in Order. -------\n");
		printf("8- Print pre Order. ------\n");
		printf("9- Print post Order. -----\n");
		printf("10- Balancear Arvore. ----\n");
		printf("0- Sair.------------------\n");
		printf("--------------------------\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opcao);
		return opcao;
}
