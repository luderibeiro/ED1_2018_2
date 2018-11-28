/*Author: Gustavo Nogueira
 *Date: 28/12/2017
 */

/*This function opens the file that contains the pixels of an image to count the number of rows and columns of the array that will store the pixels of each image.
 *In "l" mode, the number of rows will be returned. In "c" mode, the number of columns will be returned.*/

void SizeOf_Matrix(int *lines,int *columns,char *img){

    int ln = 0;
    int cl = 0;

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
        fscanf(file_aux, "%*d%c", &character);
        if (character == '\n')
            ln++;
    }

    *lines = ln;
    *columns = cl;

}
