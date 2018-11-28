
//Alocação e Desalocação da Matriz que contém os pixels da imagem.

int **Alloc_Dealloc_IMG(int **p_img,int lines,int columns,char mod){
    int i;
    int j;
    int **mat_img;
    switch (mod){

        case 'A':
            mat_img = (int **) calloc(lines,sizeof(int *));
            for (i = 0;i < lines;i++){
                mat_img[i] = (int *) calloc(columns,sizeof(int));
            }
            break;

        case 'D':
            for (i = 0;i < lines;i++){
                free(p_img[i]);
            }
            free(p_img);
            p_img = NULL;
            break;
    }

    return(mat_img);

}
