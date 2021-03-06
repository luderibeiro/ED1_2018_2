#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LIMITE 64
#define UnidadeTempo 5

typedef struct voo{
	char codigo[7];
	char modoDeVoo;
	int combustivel;
	struct voo *prox;
}Voos;

typedef struct{
	Voos *primeiro;
	Voos *ultimo;
}Fila;

typedef struct pista{
	int numeroPista;
	char codigoVoo[7];
	char tipoVoo;
	int tempo;
}Pista;

void preencheFila(int numeroVoos, int numeroAproximacoes, int numeroDecolagens, Voos *voo);
void ordenaFila(int numeroVoos, Voos *voo);
void inserirNaFila(Fila *f, Voos *voo);
void carregaFila(Fila *f, int numeroVoos, Voos *voo);
void inicializarPista(Pista *p);
void listaEventos(Voos *voo, int numeroVoos);
void emergencia(Fila *f, int *desviar);
void consomeCombustivel(Fila *f);
void Eventos(Fila *f, Pista *p, int *desviar);

char listaCodigos[64][7] = {"VG3001\0", "JJ4404\0", "LN7001\0", "TG1501\0", "GL7602\0", "TT1010\0", "AZ1009\0", "AZ1008\0",
							"AZ1010\0", "TG1506\0", "VG3002\0", "JJ4402\0", "GL7603\0", "RL7880\0", "AL0012\0", "TT4544\0",
							"TG1505\0", "VG3003\0", "JJ4403\0", "JJ4401\0", "LN7002\0", "AZ1002\0", "AZ1007\0", "GL7604\0",
							"AZ1006\0", "TG1503\0", "AZ1003\0", "JJ4403\0", "AZ1001\0", "LN7003\0", "AZ1004\0", "TG1504\0",
							"AZ1005\0", "TG1502\0", "GL7601\0", "TT4500\0", "RL7801\0", "JJ4410\0", "GL7607\0", "AL0029\0",
							"VV3390\0", "VV3392\0", "GF4681\0", "GF4690\0", "AZ1020\0", "JJ4435\0", "VG3010\0", "LF0920\0",
							"AZ1065\0", "LF0978\0", "RL7867\0", "TT4502\0", "GL7645\0", "LF0932\0", "JJ4434\0", "TG1510\0",
							"TT1020\0", "AZ1098\0", "BA2312\0", "VG3030\0", "BA2304\0", "KL5609\0", "KL5610\0", "KL5611\0"};

int main(int argc, char const *argv[]) {


	int  hora = 6, min = 0, desviar = 0;
	int horaInicial = 0, minInicial = 0, contador = 0;
	Voos voo[LIMITE];
	Fila f;
	f.primeiro = NULL;
	f.ultimo = NULL;
	Voos *aux;
	srand(time(NULL));
	int numeroVoos, voosAtendidos = 0;
	int numeroAproximacoes = rand() %(LIMITE-41) + 10;
	int numeroDecolagens = rand() %(LIMITE-41) + 10;
	numeroVoos = numeroAproximacoes + numeroDecolagens;
	printf("Numero de voos: %d\n", numeroVoos);
	preencheFila(numeroVoos, numeroAproximacoes, numeroDecolagens, voo);
	listaEventos(voo, numeroVoos);
	//printaFila(numeroVoos, voo);

	ordenaFila(numeroVoos, voo);

	carregaFila(&f, numeroVoos, voo);

	Pista pista[3];

	inicializarPista(pista);
	//printf("")
	//printf("\nPrintando ordenada.\n");
	printf("\n---------------------------------------------------------");
	printf("\nAeroporto Internacional de Brasilia.\n");
	printf("Hora inicial: %.2d:%.2d\n", hora, min);
	printf("Fila de Pedidos: \n");
	for(aux = f.primeiro;aux != NULL;aux = aux->prox){
		printf("[ %s - %c - %d ]\n", aux->codigo, aux->modoDeVoo, aux->combustivel);
	}
	//Printando os eventos.
	printf("NVoos: %d\n", numeroVoos);
	printf("NAproximacoes: %d\n", numeroAproximacoes);
	printf("NDecolagens: %d\n", numeroDecolagens);
	printf("\n---------------------------------------------------------\n");
	printf("Listagem de Eventos: \n");
	emergencia(&f, &desviar);
	Eventos(&f, pista, &desviar);

	//Loop responsável por controlar os eventos, considerando as pistas, tempo e o tipo de voo "A" ou "D".
	do {
		for(int i = 0; i < 3; i++){
			if(pista[i].tempo == 0){
				printf("Código do voo: %s\n", pista[i].codigoVoo);
				printf("Status: ");
				if(pista[i].tipoVoo == 'A'){
					printf("aeronave pousou\n");
					horaInicial = hora;
					minInicial = min - (3*UnidadeTempo);
				}
				else {
					printf("aeronave decolou\n");
					horaInicial = hora;
					minInicial = min - (2*UnidadeTempo);
				}
				if(minInicial < 0){
					minInicial = minInicial + 60;
					horaInicial--;
				}
				printf("Horario do inicio do procedimento: %.2d:%.2d\n", horaInicial, minInicial);
				printf("Numero da Pista: %d\n\n", pista[i].numeroPista);
				voosAtendidos++;

				/*anterior = NULL;
				aux = f.primeiro;
				while(strcmp(aux->codigo, pista[i].codigoVoo) != 0){
				aux = aux->prox;
				anterior = aux;
				}
				for(aux = f.primeiro; strcmp(aux->codigo, pista[i].codigoVoo) == 0; aux = aux->prox){
					anterior = aux;
				}
				if(anterior == NULL){
					f.primeiro = aux->prox;
					free(aux);
				}else{
					anterior->prox = aux->prox;
					free(aux);
				}*/
			}
		}
		contador++;

		if(contador > 9){
			consomeCombustivel(&f);
			contador = 0;
		}

		emergencia(&f, &desviar);
		min += UnidadeTempo;
		if(min >= 60){
			hora++;
			min -= 60;
		}

		Eventos(&f, pista, &desviar);
		for(int i = 0; i < 3; i++){
			pista[i].tempo = pista[i].tempo - UnidadeTempo;
		}
	//Condição que controla os eventos.
	}
	while(f.primeiro != NULL || (pista[0].tempo != 0 && pista[1].tempo != 0 && pista[2].tempo != 0));

	return 0;
}


//Voos voo[LIMITE];

int inicio, final;

void preencheFila(int numeroVoos, int numeroAproximacoes, int numeroDecolagens, Voos *voo) {

	inicio = 0;
	final = 0;

	int i, j, anterior[numeroVoos];

	for(i = 0;i < numeroVoos; i++){

		int numAleatorio = rand()%65;
		for (j = 0; j < i; j++){
			while(numAleatorio == anterior[j]){
				numAleatorio = rand()%65;
			}
		}
		anterior[i] = numAleatorio;
		strcpy(voo[i].codigo, listaCodigos[i]);
		final++;
	}
	for(i = 0; i < numeroAproximacoes; i++){

		voo[i].modoDeVoo = 'A';
		voo[i].combustivel = rand()%13; // Gerando valores aleatórios de combustivel de 0 a 12 para o modo de voo "A".

	}

	for(i = numeroAproximacoes; i < numeroVoos; i++){

		voo[i].modoDeVoo = 'D';
		voo[i].combustivel = 12; //Fixando o valor de combustível igual a 12 para o modo de voo "D".

	}
}
//Função que ordena a fila por prioridade de combustivel 0.
void ordenaFila(int numeroVoos, Voos *voo) {

	int i, j, menor;
	Voos troca[LIMITE];

	for(i = 0; i < (numeroVoos-1); i++){
		menor = i;
		for(j = (i+1); j < numeroVoos; j++){
			if(voo[j].combustivel < voo[menor].combustivel){
				menor = j;
			}
		}
		strcpy(troca[i].codigo, voo[i].codigo);
		troca[i].modoDeVoo = voo[i].modoDeVoo;
		troca[i].combustivel = voo[i].combustivel;

		strcpy(voo[i].codigo, voo[menor].codigo);
		voo[i].modoDeVoo = voo[menor].modoDeVoo;
		voo[i].combustivel = voo[menor].combustivel;

		strcpy(voo[menor].codigo, troca[i].codigo);
		voo[menor].modoDeVoo = troca[i].modoDeVoo;
		voo[menor].combustivel = troca[i].combustivel;

	}

}
//Função que printa a fila de forma organizada mostrando a identificação do voo, o modo de voo e a quantidade de combustível.
/*void printaFila(int numeroVoos, Voos *voo){
	int i = 0;

	for(i = 0;i < numeroVoos; i++){
		printf("%s\n", voo[i].codigo);
		printf("%c\n", voo[i].modoDeVoo);
		printf("%d\n", voo[i].combustivel);
		printf("\n");
	}

}*/

void inserirNaFila(Fila *f, Voos *voo) {

	if(f->primeiro == NULL){
		f->primeiro = voo;
		f->ultimo = voo;
		voo->prox = NULL;
	}
	else {
		f->ultimo->prox = voo;
		f->ultimo = voo;
	}
}

void carregaFila(Fila *f, int numeroVoos, Voos *voo) {

	int i;

	for(i = 0; i < numeroVoos; i++){
		Voos *novo = (Voos*)malloc(sizeof(Voos));
		strcpy(novo->codigo, voo[i].codigo);
		novo->modoDeVoo = voo[i].modoDeVoo;
		novo->combustivel = voo[i].combustivel;
		novo->prox = NULL;
		inserirNaFila(f, novo);
	}
}

void inicializarPista(Pista *p) {

	int i;
	for(i = 0; i < 3; i++){
		p[i].numeroPista = i+1;
		strcpy(p[i].codigoVoo, "000000\0"); //Criando lista vazia.
		p[i].tempo = 0;
	}
}
//Função responsável por embaralhar a ordem da fila.
void listaEventos(Voos *voo, int numeroVoos) {

	Voos troca;
	int i;
	int random;

	for(i = 0; i < numeroVoos; i++){
		random = rand()%(numeroVoos);

		troca = voo[i];
		voo[i] = voo[random];
		voo[random] = troca;

		/*strcpy(troca[i].codigo, voo[i].codigo);
		troca[i].modoDeVoo = voo[i].modoDeVoo;
		troca[i].combustivel = voo[i].combustivel;
		strcpy(voo[i].codigo, voo[random].codigo);
		voo[i].modoDeVoo = voo[random].modoDeVoo;
		voo[i].combustivel = voo[random].combustivel;
		strcpy(voo[random].codigo, troca[i].codigo);
		voo[random].modoDeVoo = troca[i].modoDeVoo;
		voo[random].combustivel = troca[i].combustivel;*/
	}
}
//Função responsável pela situação de emergencia.
void emergencia(Fila *f, int *desviar) {

	Voos *aux, *anterior = NULL;
	int contadorEmergencias = 0;
	for(aux = f->primeiro;aux != NULL;aux = aux->prox){
		if (aux->combustivel == 0){
			if( aux != f->primeiro){
				anterior->prox = aux->prox;
				aux->prox = f->primeiro;
				f->primeiro = aux;
			}
			contadorEmergencias++;
		}
		anterior = aux;
	}

	if (contadorEmergencias > 2){
		printf("ALERTA GERAL DE DESVIO DE AERONAVE!!!");
		*desviar = 1;
	}
	else {
		*desviar = 0;
	}
}
//Função responsável por diminuir o combustível.
void consomeCombustivel(Fila *f) {

	Voos *aux;
	for(aux = f->primeiro;aux != NULL;aux = aux->prox){
		if(aux->modoDeVoo == 'A'){
			aux->combustivel--;
		}
	}
}
//Função responsável pelos eventos totais.
void Eventos(Fila *f, Pista *p, int *desviar) {

	Voos *aux, *anterior = NULL;
	int inseriu = 0, insereInicio = 0;
	int i;
	for(aux = f->primeiro;aux != NULL;aux = aux->prox){
		if(aux->modoDeVoo == 'A'){
			inseriu = 0;
			for(i = 0; i < 2; i++){
				if(inseriu == 1){
					break;
				}
				else if(p[i].tempo == 0){
					strcpy(p[i].codigoVoo, aux->codigo);
					p[i].tipoVoo = aux->modoDeVoo;
					p[i].tempo = 3*UnidadeTempo;
					if(anterior == NULL){
						f->primeiro = aux->prox;
						insereInicio = 1;
					}
					else {
						anterior->prox = aux->prox;
						insereInicio = 0;
					}
					inseriu++;
				}
				else {
					//Nothing to do.
				}
			}
			if(inseriu == 0){
				if(*desviar == 1){
					if(p[2].tempo == 0){
						strcpy(p[2].codigoVoo, aux->codigo);
						p[2].tipoVoo = aux->modoDeVoo;
						p[2].tempo = 3*UnidadeTempo;
						if(anterior == NULL){
							f->primeiro = aux->prox;
							insereInicio = 1;
						}
						else {
							anterior->prox = aux->prox;
							insereInicio = 0;
						}
						inseriu++;
					}
					if(inseriu == 0){
						printf("ALERTA  CRÍTICO,  AERONAVE  IRÁ  CAIR!\n");
						f->primeiro = aux->prox;
						//	free(aux);
					}
				}
			}
		}
		else {
			inseriu = 0;
			for(i = 0; i < 3; i++){
				if(inseriu == 1){
					break;
				}
				else if(p[i].tempo == 0){
					strcpy(p[i].codigoVoo, aux->codigo);
					p[i].tipoVoo = aux->modoDeVoo;
					p[i].tempo = 2*UnidadeTempo;
					if(anterior == NULL){
						f->primeiro = aux->prox;
						insereInicio = 1;
					}
					 else {
						anterior->prox = aux->prox;
						insereInicio = 0;
					}
					inseriu++;
				}
				else {
					//Nothing to do.
				}
			}
		}
		if (insereInicio == 1){
			anterior = NULL;
		}
		else {
			anterior = aux;
		}
	}
}
