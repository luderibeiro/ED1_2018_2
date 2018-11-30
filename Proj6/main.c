#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define true 1
#define false 0
#define LEARNING_RATE 1

typedef int bool;


typedef struct{
    double b;//Vies
    double *W;//Pesos
    int sizeW;//Tamanho do vetor de pesos
    double grad;//Gradiente
    double s;//Saida
}NEURONIO;

void readFromFile(double *M, char modo) {

	FILE *arq;
    int i, j;
	if(modo == 'A') {
		arq = fopen("baseDadosAsphalt.txt", "r");
		if(arq == NULL) {
			printf("ERRO! Arquivo nao existe!\n");
		}
	} else {
		arq = fopen("baseDadosGrass.txt", "r");
		if(arq == NULL) {
			printf("ERRO! Arquivo nao existe!\n");
		}
	}
    for(i = 0; i < 50; i++) {
		for(j = 0; j < 536; j++) {
			fscanf(arq, "%lf ", (M+i*536+j));
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


NEURONIO* alocaNeuronios(int sizeLayer){

	NEURONIO *nr;
	nr = (NEURONIO *) malloc(sizeof(NEURONIO)*sizeLayer);
	return nr;

}

double* allocateW(int sizeW){
	double* tempW = (double*) malloc(sizeof(double)*sizeW);
	return tempW;
}

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
double intermediateValue (NEURONIO* pn, double* inputP, int sizeV) {

	int i;
	double n = 0.0f;

	for (i = 0;i < sizeV;i++){
        //printf("Vi = %lf / Wi = %lf\n",inputP[i],pn->W[i]);
	}

	for (i = 0; i < sizeV; i++) {
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

void randomValues(NEURONIO *Layer,int sizeLayer){
    int i,j;

    for (i = 0;i < sizeLayer;i++){
        for (j = 0;j < Layer[i].sizeW;j++){
           Layer[i].W[j] = (rand()%32000 - 16000);
        }
        Layer[i].b = (rand()%32000 - 16000);
    }
}

double feedFoward(NEURONIO *inputLayer,NEURONIO *hiddenLayer,NEURONIO *outputLayer,
                  double *inputP,double expectedValue,int sizeHLayer,double *classification){
    int i;
    double n;//Valor intermedi�rio
    double tempInputHidden[536]; //Relocar a cada camada
    double *tempInputOutput;//Alocar conforme entrada

    tempInputOutput = (double*) malloc(sizeHLayer*sizeof(double));
    printf("Feed Foward\n");
    //Camada de entrada
    for (i = 0;i < 536;i++){
        n = intermediateValue(&inputLayer[i],inputP,536);
        //printf("Entrada: VALOR: %lf - N: %lf\n",activationFunction(n),n);
        inputLayer[i].s = activationFunction(n);
        tempInputHidden[i] = inputLayer[i].s;
    }

    //Camada oculta
    for (i = 0;i < sizeHLayer;i++){
        n = intermediateValue(&hiddenLayer[i],tempInputHidden,536);
        //printf("OCULTA: VALOR: %lf - N: %lf\n",activationFunction(n),n);
        hiddenLayer[i].s = activationFunction(n);
        tempInputOutput[i] = hiddenLayer[i].s;
    }

    //Camada de sa�da
    //NEURONIO* pn, double* inputP, int sizeV
    n = intermediateValue(outputLayer,tempInputOutput,sizeHLayer);
    outputLayer->s = activationFunction(n);

    printf("Saida: %lf\n",outputLayer->s);
    *classification = outputLayer->s;
    return (expectedValue - outputLayer->s);//Erro
}

void backPropagation(NEURONIO *inputLayer,NEURONIO *hiddenLayer,NEURONIO *outputLayer,
    double *inputP,int sizeHLayer,double erroF){
    int i,j;
    double sum;

    printf("Back propagation\n");
    //Calculando Gradientes

    //Gradiente da �ltima camada
    outputLayer->grad = dxActivationFunction(outputLayer->s) * erroF;

    //Gradientes da camada oculta
    for (i = 0;i < sizeHLayer;i++){
       hiddenLayer[i].grad = dxActivationFunction(hiddenLayer->s) * outputLayer->grad * outputLayer->W[i];
    }

    //Gradientes da camada de entrada

    for (i = 0;i < 536;i++){
        sum = 0.0f;
        for (j = 0;j < sizeHLayer;j++){
            sum += hiddenLayer[j].grad * hiddenLayer[j].W[i];
        }
        inputLayer[i].grad = dxActivationFunction(inputLayer[i].s) * sum;
    }

    //Ajustando pesos(W)

    //Camada de sa�da
    for (i = 0;i < sizeHLayer;i++){
        outputLayer->W[i] = outputLayer->W[i] + LEARNING_RATE * hiddenLayer[i].s * outputLayer->grad;
    }

    //Camada de oculta
    for (i = 0;i < sizeHLayer;i++){
        for (j = 0;j < 536;j++){
            hiddenLayer[i].W[j] = hiddenLayer[i].W[j] + LEARNING_RATE * inputLayer[j].s * hiddenLayer[i].grad;
        }
    }

    //Camada de entrada
    for (i = 0;i < 536;i++){
        for (j = 0;j < 536;j++){
            inputLayer[i].W[j] = inputLayer[i].W[j] + LEARNING_RATE * inputP[j] * inputLayer[i].grad;
        }
    }

    //Ajustando escalares(b)

    //Camada de sa�da
    outputLayer->b = outputLayer->b + LEARNING_RATE * outputLayer->grad;

    //Camada de oculta
    for (i = 0;i < sizeHLayer;i++){
        hiddenLayer[i].b = hiddenLayer[i].b + LEARNING_RATE * hiddenLayer[i].grad;
    }

    //Camada de entrada
    for(i = 0;i < 536;i++){
        inputLayer[i].b = inputLayer[i].b + LEARNING_RATE * inputLayer[i].grad;
    }
}

int main(){

    srand(time(NULL));
    int epoca,feature;
    int sizeHLayer, i;
    double error[50];
    double classification;

    NEURONIO inputLayer[536];
    NEURONIO *hiddenLayer;
    NEURONIO outputLayer;
    scanf("%d", &sizeHLayer);

    //Alocando a camada oculta
    hiddenLayer = alocaNeuronios(sizeHLayer);

    //alocando o vetor de Ws
    for(i = 0; i < 536; i++){
        inputLayer[i].W = allocateW(536);
    }

    for(i = 0; i < sizeHLayer; i++){
        hiddenLayer[i].W = allocateW(536);
    }

    outputLayer.W = allocateW(sizeHLayer);


    int arrayRecurrenceGrass[50] = {};
    int arrayRecurrenceAsphalt[50] = {};

    double matrixGrass[50][536];
    double matrixAsphalt[50][536];
    double inputP[536];


    int correct_Asphalt = 0;
    int correct_Grass = 0;

    //w´s e b´s aleatórios
    for (i = 0;i < 536;i++){
        inputLayer[i].sizeW = 536;
    }

    for (i = 0;i < sizeHLayer;i++){
        hiddenLayer[i].sizeW = 536;
    }

    outputLayer.sizeW = sizeHLayer;

    readFromFile(&matrixGrass[0][0],'G');
    readFromFile(&matrixAsphalt[0][0],'A');

    randomValues(inputLayer,536);
    randomValues(hiddenLayer,sizeHLayer);
    randomValues(&outputLayer,1);

    double erroEp = 1;
    for (epoca = 0;(epoca < 1000)&&(erroEp > 0.20f);epoca++){
        for (feature = 0;feature < 50;feature+=2){

            randomGenerationArchives(inputP,&matrixAsphalt[0][0],arrayRecurrenceAsphalt);
            error[feature] = feedFoward(inputLayer,hiddenLayer,&outputLayer,inputP,0.0f,sizeHLayer,&classification);
            printf("erro: %lf\n", error[feature]);
            backPropagation(inputLayer,hiddenLayer,&outputLayer,inputP,sizeHLayer,error[feature]);
            printf("classification: %lf\n",classification);
            if (classification <= 0.5f) correct_Asphalt++;


            randomGenerationArchives(inputP,&matrixGrass[0][0],arrayRecurrenceGrass);
            error[feature+1] = feedFoward(inputLayer,hiddenLayer,&outputLayer,inputP,1.0f,sizeHLayer,&classification);
            printf("erro: %lf\n", error[feature+1]);
            backPropagation(inputLayer,hiddenLayer,&outputLayer,inputP,sizeHLayer,error[feature+1]);
            printf("classification: %lf\n",classification);
            if (classification > 0.5f) correct_Grass++;

        }
        //Erro quadratico medio
        erroEp = MSE (error);

        printf("corretos asfalto: %d, corretos grama: %d\n", correct_Asphalt, correct_Grass);
    }

    return 0;
}
