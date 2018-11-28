
//Alocação e Desalocação da Matriz que contèm os pixels da imagem.
void Alloc_Dealloc(int **mat_img,int lines,int columns,char mod){
    int i;
    switch (mod){

        case 'A':
            mat_img = (int **) calloc(lines,sizeof(int *));
            for (i = 0;i < lines;i++){
                mat_img[i] = (int *) calloc(columns,sizeof(int));
            }
            break;

        case 'D':
            for (i = 0;i < lines;i++){
                free(mat_img[i]);
            }
            free(mat_img);
            break;
    }

}
