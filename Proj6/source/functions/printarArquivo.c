
void printarArquivoAsphalt(double **vet){
    int i,j;
    FILE *arq;
    arq = fopen("baseDadosAsphalt.txt","a+");

    for (i = 0;i < 25;i++){
        for (j = 0;j < 536;j++){
            fprintf(arq,"%.20lf ",vet[i][j]);
        }
        fprintf(arq,"\n");
    }
    fclose(arq);
}


void printarArquivoGrass(double **vet){
    int i,j;
    FILE *arq;
    arq = fopen("baseDadosGrass.txt","a+");

    for (i = 0;i < 25;i++){
        for (j = 0;j < 536;j++){
            fprintf(arq,"%.20lf ",vet[i][j]);
        }
        fprintf(arq,"\n");
    }
    fclose(arq);
}

