//Nathalia Lorena Cardoso - 14/0156909  Lude Yuri Ribeiro - 15/0137770
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

char nomeArquivo[95] = "/home/luderibeiro/Documentos/2019.1/ED1/ED1_2018_2/Proj2/DataSet/";

int** alocarMatriz(int Linhas,int Colunas){

  int i;
  int **m = (int**) calloc(Linhas, sizeof(int*));
  for (i = 0; i < Linhas; i++){
       m[i] = (int*) calloc(Colunas, sizeof(int));
  }
return m; //Retorna o Ponteiro para a Matriz Alocada
}

void liberaMatriz (int l, int n, int **m)
{
    int  i;  /* variavel auxiliar */
    if (m == NULL)
        exit(-1);
    if (l < 1 || n < 1) {  /* verifica parametros recebidos */
        printf ("** Erro: Parametro invalido **\n");
    }
    for (i=0; i<l; i++) free (m[i]); /* libera as linhas da matriz */
    free (m);      /* libera a matriz (vetor de ponteiros) */
}

int binToDec(int *vetorBinario){ //pegar o valor em decimal baseado no binario concatenado
    int somatorio = 0, i;
    for(i = 0; i < 9; i++) {
        somatorio += vetorBinario[i] * pow(2, 9-i);
    }
    // printf("somatorio %d\n", somatorio);
    //printf("%d\n", somatorio);
    // getc(stdin);
    return somatorio;
}

int rotacaoBinaria(char *binario) {
    int i, j, valor, menor, troca[9] = {}, aux[9] = {};

    //transformando de string para inteiro
    for(i = 9; i > 0; i--) {
        aux[i] = atoi(&binario[i]);
        binario[i] = '\0';
        printf("%d\n", aux[i]);
    }
    valor = binToDec(troca);
    for(i = 0; i < 8; i++) {
        troca[0] = aux[9];
        for(j = 1; j < 10; i++) {
            troca[i] = aux[i-1];
        }
    }
    return menor;
}
//Implementando o ILBP
void ILBP(int **matrizArquivo, int *vetorRecorrencia) {
    int i, j, k, l, valorMenor;
    for(i = 1; i < 1024; i++) {
        for(j = 1; j < 1024; j++) {
            float mediaVizinhanca = 0;
            for(k = i-1; k <= i+1; k++) { //looping responsável por guardar a soma dos vizinhos
                for(l = j-1; l <= j+1; l++) {
                    mediaVizinhanca += matrizArquivo[k][l];
                    //printf("%f\n", mediaVizinhanca);
                }
            }

            mediaVizinhanca /= 9;
            //printf("%f\n", mediaVizinhanca);

            char *binario = calloc(9, sizeof(char));
            for(k = i-1; k <= i+1; k++) { //looping responsável por guardar o binário
                for(l = j-1; l <= j+1; l++) {
                    if(matrizArquivo[k][l] > mediaVizinhanca)
                        strcat(binario, "1");
                    else
                        strcat(binario, "0");
                }
            }
            printf("%s\n", binario);
            //printf("%s\n", binario);
            valorMenor = rotacaoBinaria(binario);
            vetorRecorrencia[valorMenor]++;
            free(binario);
        }
    }

}
//Implementando o GLCM
// void GLCM(int **matrizArquivo, int ***matrizGLCM) {
//     int i, j, k, l;
//     for(i = 0; i < 8; i++) {
//         for(j = 0; j < 256; j++) {
//             for(k = i-1; k <= i+1; k++) { //looping responsável por guardar a soma dos vizinhos
//                 for(l = j-1; l <= j+1; l++) {
//                     // matrizGLCM[]
//                 }
//             }
//         }
//     }
// }
//***********************************************************************************************************************************//
//******************************************************MAIN*************************************************************************//
//***********************************************************************************************************************************//
int main() {
    srand(time(NULL));
    FILE *arq;
    int **vetorRecorrencia = NULL, **matrizArquivo = NULL, ***matrizGLCM;
    int recorrenciaImagensAsphalt[50] = {}, recorrenciaImagensGrass[50] = {};
    int i, j, aux, imagemAsphalt, imagemGrass, asphalt;
    char lixo = 'a';
    char asphaltFile[50][15] = {"asphalt_01.txt", "asphalt_02.txt", "asphalt_03.txt", "asphalt_04.txt", "asphalt_05.txt",
                                "asphalt_06.txt", "asphalt_07.txt", "asphalt_08.txt", "asphalt_09.txt", "asphalt_10.txt",
                                "asphalt_11.txt", "asphalt_12.txt", "asphalt_13.txt", "asphalt_14.txt", "asphalt_15.txt",
                                "asphalt_16.txt", "asphalt_17.txt", "asphalt_18.txt", "asphalt_19.txt", "asphalt_20.txt",
                                "asphalt_21.txt", "asphalt_22.txt", "asphalt_23.txt", "asphalt_24.txt", "asphalt_25.txt",
                                "asphalt_26.txt", "asphalt_27.txt", "asphalt_28.txt", "asphalt_29.txt", "asphalt_30.txt",
                                "asphalt_31.txt", "asphalt_32.txt", "asphalt_33.txt", "asphalt_34.txt", "asphalt_35.txt",
                                "asphalt_36.txt", "asphalt_37.txt", "asphalt_38.txt", "asphalt_39.txt", "asphalt_40.txt",
                                "asphalt_41.txt", "asphalt_42.txt", "asphalt_43.txt", "asphalt_44.txt", "asphalt_45.txt",
                                "asphalt_46.txt", "asphalt_47.txt", "asphalt_48.txt", "asphalt_49.txt", "asphalt_50.txt"};
    char grassFile[50][13] = {"grass_01.txt", "grass_02.txt", "grass_03.txt", "grass_04.txt", "grass_05.txt",
                              "grass_06.txt", "grass_07.txt", "grass_08.txt", "grass_09.txt", "grass_10.txt",
                              "grass_11.txt", "grass_12.txt", "grass_13.txt", "grass_14.txt", "grass_15.txt",
                              "grass_16.txt", "grass_17.txt", "grass_18.txt", "grass_19.txt", "grass_20.txt",
                              "grass_21.txt", "grass_22.txt", "grass_23.txt", "grass_24.txt", "grass_25.txt",
                              "grass_26.txt", "grass_27.txt", "grass_28.txt", "grass_29.txt", "grass_30.txt",
                              "grass_31.txt", "grass_32.txt", "grass_33.txt", "grass_34.txt", "grass_35.txt",
                              "grass_36.txt", "grass_37.txt", "grass_38.txt", "grass_39.txt", "grass_40.txt",
                              "grass_41.txt", "grass_42.txt", "grass_43.txt", "grass_44.txt", "grass_45.txt",
                              "grass_46.txt", "grass_47.txt", "grass_48.txt", "grass_49.txt", "grass_50.txt"};

    //Looping para conjunto de treinamento
    for(aux = 0; aux < 50; aux++) {
        matrizArquivo = alocarMatriz(1025, 1025);
        vetorRecorrencia = alocarMatriz(50, 536);
        if(asphalt == 0){
            strcat(nomeArquivo, "asphalt/");
            imagemAsphalt = rand()%50;
            if (recorrenciaImagensAsphalt[imagemAsphalt] == 1) {
                while(recorrenciaImagensAsphalt[imagemAsphalt] == 1) { //Looping para evitar a repetição de imagem
                    imagemAsphalt = rand()%50;
                }
            }
            strcat(nomeArquivo, asphaltFile[imagemAsphalt]);
        }
        else{
            strcat(nomeArquivo, "grass/");
            imagemGrass = rand()%50;
            if(recorrenciaImagensGrass[imagemGrass] == 1) {
                while(recorrenciaImagensGrass[imagemGrass] == 1) {  //Looping para evitar a repetição de imagem
                    imagemGrass = rand()%50;
                }
            }
            strcat(nomeArquivo, grassFile[imagemGrass]);
        }
        arq = fopen(nomeArquivo, "r");
        //printf("%s\n", nomeArquivo);
        for(i = 0; i < 1025; ++i) {
            for(j = 0; j < 1025; j++) {
                fscanf(arq, "%d%c", &matrizArquivo[i][j], &lixo);
                //printf("%d ", matrizArquivo[i][j]);
            }
        }
        fclose(arq);
        ILBP(matrizArquivo, vetorRecorrencia[0]);
        //Alocando livro de resultados GLCM  // AINDA TEM QUE DAR FREE!!!!!!!!!!!!!!
        matrizGLCM = (int***) calloc(8, sizeof(int**));
        for(i = 0; i < 8; i++) {
            matrizGLCM[i] = (int**) calloc(256, sizeof(int*));
            for (j = 0; j < 256; j++){
                matrizGLCM[i][j] = (int*) calloc(256, sizeof(int));
            }
        }
        //GLCM(matrizArquivo, matrizGLCM);
        liberaMatriz(1025, 1025, matrizArquivo);
        nomeArquivo[66] = '\0'; //Para deixar a string limpa para poder trocar de pasta e arquivo depois
        if(asphalt == 0)
            asphalt = 1;
        else
            asphalt = 0;
    }

    return 0;
}

// for (i = 0; i < 1025; i++) {
//     for (j = 0; j < 1025; j++) {
//         printf("%d ", matrizArquivo[i][j]);
//     }
//     printf("\n");
// }
//getc(stdin);
