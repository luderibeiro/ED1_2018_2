//Nathalia Lorena Cardoso - 14/0156909  Lude Yuri Ribeiro - 15/0137770
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int** alocarMatriz(int lines, int columns) {

    int i,j;
    int **m = (int**)malloc(lines * sizeof(int*));
    for (i = 0; i < lines; i++) {
        m[i] = (int*) malloc(columns * sizeof(int));
        for (j = 0; j < columns; j++) {
            m[i][j] = 0;
        }
    }
    return m;
}

int rotacaoBinaria(char *binario) {
    int i, j, valor, menor;
    char troca;
    menor = atoi(binario);
    for(i = 0; i < 8; i++) {
        troca = binario[9];
        for(j = 9; j >= 0; j--) {
            binario[j] = binario[j-1];
        }
        binario[0] = troca;
        valor = atoi(binToDec(binario));
        if(valor<menor)
            menor = valor;
    }
    return menor;
}

void ILBP(int **matrizArquivo) {
    int i, j, k, l, valorMenor;
    for(i = 1; i < 1024; i++) {
        for(j = 1; j < 1024; j++) {
            float mediaVizinhanca = 0.0;
            for(k = i-1; k <= i+1; k++) { //looping responsável por guardar a soma dos vizinhos
                for(l = j-1; l <= j+1; l++) {
                    mediaVizinhanca += matrizArquivo[k][l];
                }
            }
            char binario[9] = {};
            mediaVizinhanca /= 9;
            for(k = i-1; k <= i+1; k++) { //looping responsável por guardar o binário
                for(l = j-1; l <= j+1; l++) {
                    if(matrizArquivo[k][l] > mediaVizinhanca)
                        strcat(binario, '1');
                    else
                        strcat(binario, '0');
                }
            }
            valorMenor = rotacaoBinaria(binario);
        }
    }

}
//////////////////////////////////////////////////// MAIN //////////////////////////////////////////////////////////////

int main(){

    char nomeArquivo[80] = "/home/luderibeiro/Documentos/2019.1/ED1/ED1_2018_2/Proj2/DataSet/";
    FILE *arq;

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

    int **matrizArquivo = alocarMatriz(1025, 1025);
    printf("Teste\n");
    strcat(nomeArquivo, asphaltFile[5]);
    matrizArquivo = fopen(nomeArquivo,"r");
    //passando valores para matriz
    for(int i=0;i<1025;++i){
        for(int j=0;j<1025;++j){
            fscanf(arq,"%d%*c",&matrizArquivo[i][j]);
        }
    }
    fclose(arq);

    return 0;
}

int binToDec(char *bin){
    int somatorio = 0;
    int x = 8;
    for(int i = 0; i < 9 ;i++){

        if(bin[i] == 49){ // como jogo um binario no formato char comparando com um inteiro tive que compara com 48  => "0"
            somatorio += pow(2, x);                                                                           //49 => "1"
        }
        x--;
    }
    return somatorio;
}
