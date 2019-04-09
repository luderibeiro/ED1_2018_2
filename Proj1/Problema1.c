//15/0137770 - Lude Ribeiro
//14/0156909 - Nathalia Lorena Cardoso
#include <stdio.h>
#include <stdlib.h>


int fneuronio(float *pENTRADAS, float *pPESOS, float *pLimiar, int LIMITE){
    float SOMAP = 0, limiar;
    int i = 0, neuronio = 1;
    limiar = *pLimiar;

    for(i = 0; i < 10; i++){
        SOMAP += pENTRADAS[i] * pPESOS[i];
    }
    if(limiar > SOMAP){
        neuronio = 0;
    }

    return neuronio;
}


int main(){
    float ENTRADAS[10], PESOS[10], limiarT = 0, *pENTRADAS = ENTRADAS, *pPESOS = PESOS, *pLimiar;
    int i, neuronio;

    pLimiar = &limiarT;
    printf("Digite 10 valores inteiros referente ao vetor de entradas:\n");
    for(i = 0; i < 10; i++){
        scanf("%f", &ENTRADAS[i]);
    }
    printf("Digite 10 valores inteiros referente ao vetor de pesos:\n");
    for(i = 0; i < 10; i++){
        scanf("%f", &PESOS[i]);
    }
    printf("DIgite o limiarT.\n");
    scanf("%f", &limiarT);

    neuronio = fneuronio(pENTRADAS, pPESOS, pLimiar, 10);

    if(neuronio == 1)
        printf("Neuronio ativado!\n");
    else
        printf("Neuronio inibido!\n");

    return 0;
}
