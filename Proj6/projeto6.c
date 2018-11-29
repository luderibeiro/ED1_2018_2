#include <stdio.h>
#include <math.h>


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
double valorIntermediario (NEURONIO* pn, int sizeV, int* entradaV) {

	int i;
	double n = 0;

	for (i = 0; i < sizeV i++) {
		n += *(entradaV + i)*pn->W[i];

	}
	n += pn->b;
	return n;
}


int main () {

	double n;
	printf("Digite o n: \n");
	scanf("%lf",&n);
	double funcao = funcaouncaoLogistica(n);
	double funcaoDerivada = derivadaDafuncaouncaoLogistica(n);

	printf("Valor de funcao: %.4lf\n", funcao );
	printf("Valor da derivada da funcao: %.2lf\n", funcaoDerivada );


	return 0;
}
