
//Alocação e Desalocação da Matriz de Co-Ocorrência

int **Alloc_Dealloc_MCO(int **MCO,int gray_Levels,char mod){
    int i;
    int j;
    int **mat_MCO;
    switch (mod){

        case 'A':
            mat_MCO = (int **) malloc(gray_Levels * sizeof(int *));
            for (i = 0;i < gray_Levels;i++){
                mat_MCO[i] = (int *) malloc(gray_Levels * sizeof(int));
            }

            break;

        case 'D':
            for (i = 0;i < gray_Levels;i++){
                free(MCO[i]);
            }
            free(MCO);
            mat_MCO = NULL;
            break;
    }

    return(mat_MCO);

}
