#define true 1
#define false 0

void lerDoArquivo(double **M, char modo) {

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
		for(i = 0; i < 536; i++) {
			for(j = 0; j < 50; j++) {
				fscanf("%lf ", M[i][j]);
			}
		}
	}
}

void alocaVetorEntradas(double *p, int tam) {
	p = (double *) calloc(tam, sizeof(double));
}

void randomGenerationArchives(double *V, double **M, int *vetorRecorrencia, int tam) {

	int i, linha;
	linha = rand()%50;

	while(vetorRecorrencia[linha] == true) {
		linha = rand()%50;
	}

	vetorRecorrencia[linha] = true;

	for(i = 0; i < tam; i++) {
		V[i] = M[i][linha];
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
