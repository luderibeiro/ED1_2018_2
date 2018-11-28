#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions/Header_Functions.h"
#include "functions/Alloc_Dealloc_IMG.c"
#include "functions/Alloc_Dealloc_MCO.c"
#include "functions/Run_Training.c"
#include "functions/Run_Test_Grass.c"
#include "functions/Run_Test_Asphalt.c"
#include "functions/SizeOf_Gray_Levels_IMG.c"
#include "functions/Concat_Numeric_IMG.c"
#include "functions/Choice_Rand_IMG.c"
#include "functions/Upload_Image.c"
#include "functions/Convert_Binary_Decimal.c"
#include "functions/Lower_ILBP.c"
#include "functions/Algorithm_GLMC.c"
#include "functions/Get_Neighborhood_ILBP.c"
#include "functions/Calculate_ILBP.c"
#include "functions/printarArquivo.c"
#include "functions/Normalization_Feature_Vectors.c"
#include "functions/Average_Vectors.c"
#include "functions/Euclidean_Distance.c"
#define IMG 25//Número de imagens no conjunto (treinamento ou teste) de uma classe (grama ou asfalto)
#define SIZE_VECTOR 536
/*Author: Gustavo Nogueira
 *Date: 01/10/2018
 */

/*
Este algoritmo tem a função de classificar duas classes de imagens (grama ou asfalto). Usando o algoritmo ILBP e GLCM.*/

int main(){

    double avg_GrassVectors[536];//Vetor média da classe Grama
    double avg_AsphaltVectors[536];//Vetor média da classe Asfalto
    int choice_grass[25];//Armazenar imagens selecionadas para o conjunto de treinamento
    int choice_asphalt[25];//Armazenar imagens selecionadas para o conjunto de treinamento
    int correct_Grass;
    int correct_Asphalt;
    double hit_rate;
    double rate_ac;
    double rate_rej;

    printf("  Classificador de imagens (asfalto ou grama)\n");
    printf("------------------------------------------------------------------\n");

    printf("Realizando treinamento do sistema...");
    Run_Training(&avg_GrassVectors[0],&avg_AsphaltVectors[0],&choice_grass[0],&choice_asphalt[0],SIZE_VECTOR);
    printf("\nTreinamento concluido!\n");

    printf("------------------------------------------------------------------\n");
    printf("Realizando teste...");
    correct_Grass = Run_Test_Grass(&choice_grass[0],&avg_GrassVectors[0],&avg_AsphaltVectors[0],SIZE_VECTOR);
    correct_Asphalt = Run_Test_Asphalt(&choice_asphalt[0],&avg_GrassVectors[0],&avg_AsphaltVectors[0],SIZE_VECTOR);
    printf("\nTeste concluido!\n");

    hit_rate = ((correct_Asphalt + correct_Grass)*100)/50.0;
    rate_ac = 100 - ((correct_Asphalt*100)/25.0);
    rate_rej = 100 - ((correct_Grass*100)/25.0);
    printf("------------------------------------------------------------------\n");
    printf("                              METRICAS                             \n");
    printf("------------------------------------------------------------------\n");
    printf("Taxa de acerto: %.2lf%%\n",hit_rate);
    printf("Taxa de falsa aceitacao: %.2lf%%\n",rate_ac);//Imagens pertencentes à classe "asfalto", mas foram classificadas como "grama".
    printf("Taxa de falsa rejeicao: %.2lf%%\n",rate_rej);//Imagens que pertencem à classe "grama", mas foram classificadas como sendo "asfalto".
    printf("------------------------------------------------------------------\n");

    return 0;

}

