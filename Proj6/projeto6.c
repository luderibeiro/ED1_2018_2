#include <stdio.h>
#include <math.h>


double activationFunction (double n) {

	double funcao;

	funcao = (1/(1-exp(-n)));
	return funcao;

}
double dxActivationFunction (double n) {

 	double dx;
	dx = (-1.0f)*(exp(-n))/pow((1-exp(-n)),2);

	return dx;
}
double intermadiateValue (NEURONIO* pn, double* inputP, int sizeV) {

	int i;
	double n = 0;

	for (i = 0; i < sizeV i++) {
		n += inputP[i]*pn->W[i];

	}
	n += pn->b;
	return n;
}

double MSE (double* erros) {

	int i;
	double sum = 0;


	for (i = 0; i < 50; i++) {

		sum += pow(erros[i],2);
	}
	sum /= 50.0f;

	return sum;
}


int main () {

	double n;
	printf("Digite o n: \n");
	scanf("%lf",&n);
	double funcao = activationFunction(n);
	double funcaoDerivada = dxActivationFunction(n);

	printf("Valor de funcao: %.4lf\n", funcao );
	printf("Valor da derivada da funcao: %.2lf\n", funcaoDerivada );


	return 0;
}
