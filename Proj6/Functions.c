#define true 1
#define false 0

void readFromFile(double *M, char modo) {

	FILE *arq;
	if(modo == 'A') {
		arq = fopen("baseDadosAsphault.txt", "r");
		if(arq == NULL) {
			printf("ERRO! Arquivo nao existe!\n", );
		}
	} else {
		arq = fopen("baseDadosGrass.txt", "r");
		if(arq == NULL) {
			printf("ERRO! Arquivo nao existe!\n", );
		}
	}

	while(arq != EOF) {
		for(i = 0; i < 50; i++) {
			for(j = 0; j < 536; j++) {
				fscanf("%lf ", *(M+i*536+j));
			}
		}
	}
}

void alocaVetorEntradas(double *p, int tam) {
	p = (double *) calloc(tam, sizeof(double));
}

void randomGenerationArchives(double *V, double *M, int *recurrence) {

	//tam referente ao numero de colunas
	int i, linha;
	linha = rand()%50;

	while(recurrence[linha] == true) {
		linha = rand()%50;
	}

	recurrence[linha] = true;

	for(i = 0; i < 536; i++) {
		V[i] = *(M+linha*536+i);
	}
}

double funcaouncaoLogistica (double n) {

	double funcao;

	funcao = (1/(1+exp(-n)));
	return funcao;

}

double derivadaDafuncaouncaoLogistica (double n) {

	double funcaoDerivada;
	funcaoDerivada = (exp(-n))/pow((1+exp(-n)),2);

	return funcaoDerivada;
}

int main () {

	double n;
	printf("Digite o n: \n");
	scanf("%lf",&n);
	double funcao = funcaouncaoLogistica(n);
	double funcaoDerivada = derivadaDafuncaouncaoLogistica(n);

	printf("Valor de funcao: %.2lf\n", funcao );
	printf("Valor da derivada da funcao: %.2lf\n", funcaoDerivada );


	return 0;
}

NEURONIO* alocaNeuronios(int sizeLayer){

	NEURONIO *nr;
	nr = (NEURONIO *) malloc(sizeof(NEURONIO)*sizeLayer);
	return nr;

}

double* allocateW(int sizeW){
	double* tempW = (double*) malloc(sizeof(double)*sizeW);
	return tempW;
}
