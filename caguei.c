#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMITE 64

typedef struct{
	char codigo[7];
	char modoVoo;
	int combustivel;
}Voos[LIMITE];

Voos voo[LIMITE];

int inicio, final;

/*void inicializaFila(){
	inicio = 0;
	fim = -1;
}*/

void preencheFila(int numeroVoos){

	int modoAleatorio;
	FILE *arq;
	arq = fopen("codigoVoos.txt", "r");

	if (arq == NULL){
		printf("Arquivo nao existe.\n");
	}
	inicio = 0;
	final = 0;

	int i;
	while(!feof(arq)){
		for(i = 0;i < numeroVoos; i++){
			//__fpurge(stdin);
			fscanf(arq, "%s[^,]", voo[i]->codigo);
			modoAleatorio = rand()%2;
			if(modoAleatorio == 0){

				voo[i]->modoVoo = 'A';
				voo[i]->combustivel = rand()%13;
			} else {
				voo[i]->modoVoo = 'D';
				voo[i]->combustivel = 12;
			}
			final++;
		}

		for(i = 0;i < numeroVoos; i++){
			printf("%s\n", voo[i]->codigo);
			printf("%c\n", voo[i]->modoVoo);
			printf("%d\n", voo[i]->combustivel);
			printf("\n");
		}
	}


}



int main(int argc, char const *argv[]) {

	srand(time(NULL));
	int numeroVoos = rand() %(LIMITE-19) + 20;
	printf("Numero de voos: %d\n", numeroVoos);
	preencheFila(numeroVoos);

	printf("\nAeroporto Internacional de Brasilia.\n");
	printf("Hora inicial: 08:00\n");


	return 0;
	}
