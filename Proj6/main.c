#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define true 1
#define false 0
#define LEARNING_RATE 1

typedef int bool;


typedef struct{
    double b;//Viés
    double *W;//Pesos
    int sizeW;//Tamanho do vetor de pesos
    double grad;//Gradiente
    double s;//Saída
}NEURONIO;


void randomValues(NEURONIO *Layer,int sizeLayer){
    int i,j;

    for (i = 0;i < sizeLayer;i++){
        for (j = 0;j < Layer.sizeW;j++){
           Layer[i].W[j] = (rand()%32000 - 16000);
        }
        Layer[i].b = (rand()%32000 - 16000);
    }
}

double feedFoward(NEURONIO *inputLayer,NEURONIO *hiddenLayer,NEURONIO *outputLayer,
                  double *inputP,double expectedValue,int sizeHLayer,double *classification){
    int i;
    double n;//Valor intermediário
    double tempInputHidden[536]; //Relocar a cada camada
    double *tempInputOutput;//Alocar conforme entrada


    //Camada de entrada
    for (i = 0;i < 536;i++){
        n = intermediateValue(&inputLayer[i],inputP,536);
        inputLayer[i].s = activationFunction(n);
        tempInput[i] = inputLayer[i].s;
    }

    //Camada oculta
    for (i = 0;i < sizeHLayer;i++){
        n = intermediateValue(&hiddenLayer[i],tempInputHidden,536);
        hiddenLayer[i].s = activationFunction(n);
        tempInputOutput[i] = hiddenLayer[i].s;
    }

    //Camada de saída

    n = intermediateValue(&hiddenLayer[i],tempInputOutput,sizeHLayer);
    outputLayer->s = activationFunction(n);

    *classification = outputLayer->s;
    return (expectedValue - outputLayer->s);//Erro
}

void backPropagation(NEURONIO *inputLayer,NEURONIO *hiddenLayer,NEURONIO *outputLayer,double *inputP,int sizeHLayer,double erroF){
    int i,j;
    double sum;
    //Calculando Gradientes

    //Gradiente da última camada
    outputLayer->grad = dxActivationFunction(outputLayer->s) * erroF;

    //Gradientes da camada oculta
    for (i = 0;i < sizeHLayer;i++){
       hiddenLayer[i].grad = dxActivationFunction(hiddenLayer.s) * outputLayer->grad * outputLayer.W[i];
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

    //Camada de saída
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

    //Camada de saída
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
    int epoca,feature;
    int sizeHLayer;
    double error[50];
    double classification;

    NEURONIO inputLayer[536];
    NEURONIO *hiddenLayer;
    NEURONIO outputLayer;

    srand(time(NULL));

    arrayRecurrenceGrass[50] = {};
    arrayRecurrenceAsphalt[50] = {};

    double matrixGrass[50][536];
    double matrixAsphalt[50][536];
    double inputP[536];

    int correct_Asphalt = 0;
    int correct_Grass = 0;

    double erroEp;

    for (epoca = 0;(epoca < 1000)&&(erroEp > 0.20f);epoca++){
        for (feature = 0;feature < 50;feature+=2){

            randomGenerationArchives(inputP,&matrixAsphalt[0][0],arrayRecurrenceAsphalt);

            error[feature] = feedFoward(inputLayer,hiddenLayer,&outputLayer,inputP,0.0f,sizeHLayer,&classification);

            backPropagation(inputLayer,hiddenLayer,&outputLayer,inputP,sizeHLayer,error[feature]);

            NEURONIO *inputLayer,NEURONIO *hiddenLayer,NEURONIO *outputLayer,double *inputP,int sizeHLayer,double erroF

            if (classification <= 0.5f) correct_Asphalt++;

            randomGenerationArchives(inputP,&matrixGrass[0][0],arrayRecurrenceGrass);

            error[feature+1] = feedFoward(inputLayer,hiddenLayer,&outputLayer,inputP,1.0f,sizeHLayer,&classification);

            backPropagation(inputLayer,hiddenLayer,&outputLayer,inputP,sizeHLayer,error[feature+1]);

            if (classification > 0.5f) correct_Grass++;
        }
        //Erro quadratico medio
        erroEp = MSE (error);
    }

    return 0;
}
