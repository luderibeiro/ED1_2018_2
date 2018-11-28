/*Author: Gustavo Nogueira
 *Date: 28/12/2017
 */

/*Test grade: 25 images of Grass class.
 *This function calls the functions required for system test.
 *This function returns the number of images that were sorted correctly.*/

int Run_Test_Grass (int *choice_grass,double *avg_Grass,double *avg_Asphalt, int sizeVector,int gray_Levels){

    char *p_img;
    char img[35];
    char class_Img;
    char img_grass[25] = "..\\DataSet\\grass\\grass_";//Mold
    int aux[51];
    int lines,columns;
    int i,x,y,z;//Accountants
    int different;
    int correct = 0;
    int ts_grass[25];
    int **mat_img;//Stores the pixels of the image
    double **feature_Vectors_Grass;

    p_img = &img[0];

    //Definindo imagens que serão utilizadas para o teste.
    y = 0;
    for (x = 0;x < 51;x++){
        aux[x] = 0;
    }
    for (z = 0;z < 25;z++){
            aux[*(choice_grass+z)] = *(choice_grass+z);
    }
    for (x = 1;x < 51;x++){
            if (aux[x] == 0){
                ts_grass[y] = x;
                y++;
            }
    }

    //Alocação dos vetores caracteríticas.
    feature_Vectors_Grass = (double **) calloc(25,sizeof(double *));
    for (x = 0;x < 25;x++){
        feature_Vectors_Grass[x] = (double *) calloc(sizeVector,sizeof(double));
    }

    //Call functions needed to read the pixels of the images.
    for (i = 0;i < 25;i++){

        for (x = 0;x < 35;x++){
            img[x] = '\0';
        }

        for (x = 0;x < 23;x++){
            img[x] = img_grass[x];
        }

        Concat_Numeric_IMG(p_img,ts_grass[i]);

        //Tamanho da imagem
        SizeOf_Matrix(&lines,&columns,p_img);

        //Alocando matriz para a imagem
        Alloc_Dealloc(mat_img,lines,columns,'A');

        //Carregar imagem
        Upload_Image(lines,columns,mat_img,p_img);

        // Executar ILBP e GLCM
        Get_Neighborhood_ILBP_GLCM(mat_img,lines,columns,feature_Vectors_Grass,sizeVector,i,gray_Levels);

        //Desalocando matriz da imagem
        Alloc_Dealloc(mat_img,lines,columns,'D');


    }
    //Normalização dos vetores características
    Normalization_Feature_Vectors (feature_Vectors_Grass,sizeVector);


    //Performs image classification
    for (x = 0;x < 25;x++){
        class_Img = Euclidean_Distance(feature_Vectors_Grass,avg_Grass,avg_Asphalt,x,sizeVector);
        if (class_Img == 'g'){
            correct++;
        }
    }

    //Desalocação

    for (i = 0;i < 25;i++){
        free(feature_Vectors_Grass[i]);
    }
    free(feature_Vectors_Grass);

    return (correct);

}
