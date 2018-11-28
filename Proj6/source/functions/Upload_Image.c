
/* Esta função é responsável por carregar as imagens. */

void Upload_Image(int lines,int columns,int **mat_img,char *img){

    int i,j,w;
    int ln,cl;
    int pixel;
    char character;
    FILE *file_img;

    printf("\n%s\n",img);

    file_img = fopen(img,"r");
    if (file_img == NULL){
        printf("\nCould not open file\n");
        exit(1);
    }

    //Lendo a Imagem
    for (i = 0;i < lines;i++){
        for (j = 0;j < columns;j++){
            fscanf(file_img, "%d%c", &pixel, &character);
            mat_img[i][j] = pixel;
        }
    }

    fclose(file_img);

}

