
/*Esta função retorna a dimensão e níveis de cinza da imagem */

int SizeOf_Gray_Levels_IMG(int *lines,int *columns,char *img){

    int ln = 0;
    int cl = 0;
    int max_px = -1;
    int pixel;

    char character = '\0';
    FILE *file_img;
    FILE *file_aux;

    file_img = fopen(img,"r");
    file_aux = file_img;

    if (file_img == NULL){
        printf("\nCould not open file\n");
        exit(1);
    }

    //Número de colunas
    for (cl = 0;character != '\n';cl++){
        fscanf(file_img, "%*d%c", &character);
    }

    //Número de linhas
    while(!feof(file_aux)){
        fscanf(file_aux, "%d%c",&pixel,&character);
        if (character == '\n')
            ln++;
        if (pixel > max_px)
            max_px = pixel;
    }

    *lines = ln;
    *columns = cl;
    max_px++;
    return(max_px);
}
