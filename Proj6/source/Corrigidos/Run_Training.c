/*Author: Gustavo Nogueira
 *Date: 28/12/2017
 */

/*This function calls the functions required for system training.
 *For the training, 25 images of the class Asphalt and 25 images of the class Grass.*/

void Run_Training (double *avg_GrassVectors, double *avg_AsphaltVectors, int *rand_grass,int *rand_asphalt, int sizeVector, int gray_Levels){

    char *p_img;
    char img_grass[25] = "..\\DataSet\\grass\\grass_";//Molds
    char img_asphalt[30]  = "..\\DataSet\\asphalt\\asphalt_";
    char img[35];
    int i,x,y;//Accountants
    int lines,columns;
    int **mat_img;//Stores the pixels of the image
    double **feature_Vectors_Grass;//Histogram of the training set; Each line represents an image.
    double **feature_Vectors_Asphalt;//Histogram of the training set.

    for (i = 0;i < 25;i++){
        rand_grass[i] = 0;
        rand_asphalt[i] = 0;
    }

    for (i = 0;i < sizeVector;i++){
        avg_GrassVectors[i] = 0;
        avg_AsphaltVectors[i] = 0;
    }

    //Alocação dos vetores caracteríticas.
    feature_Vectors_Grass = (double **) calloc(25,sizeof(double *));
    feature_Vectors_Asphalt = (double **) calloc(25,sizeof(double *));
    for (w = 0;w < 25;w++){
        feature_Vectors_Grass[w] = (double *) calloc(sizeVector,sizeof(double));
        feature_Vectors_Asphalt[w] = (double *) calloc(sizeVector,sizeof(double));
    }


    //Training Class Grass
    p_img = &img[0];

    for (i = 0;i < 25;i++){

        for (x = 0;x < 35;x++){
            img[x] = '\0';
        }

        for (x = 0;x < 23;x++){
            img[x] = img_grass[x];
        }

        //Sorteio da imagem
        rand_grass[i] = Choice_Rand_IMG(rand_grass,i);
        Concat_Numeric_IMG (p_img,rand_grass[i]);

        //Tamanho da imagem
        SizeOf_Matrix(&lines,&columns,p_img);

        //Alocando matriz para a imagem
        Alloc_Dealloc(mat_img,lines,columns,'A');

        //Carregar imagem
        Upload_Image(lines,columns,mat_img,p_img);

        //Executar ILBP e GLCM
        Get_Neighborhood_ILBP_GLCM(mat_img,lines,columns,feature_Vectors_Grass,sizeVector,i,gray_Levels);

        //Desalocando matriz da imagem
        Alloc_Dealloc(mat_img,lines,columns,'D');

    }
    //Normalização e Média dos vetores característica
    Normalization_Feature_Vectors (feature_Vectors_Grass,sizeVector);
    Average_Vectors(feature_Vectors_Grass,avg_GrassVectors,sizeVector);


    //Training Class Asphalt

    for (i = 0;i < 25;i++){
        for (x = 0;x < 35;x++){
            img[x] = '\0';
        }
        for (x = 0;x < 27;x++){
            img[x] = img_asphalt[x];
        }

        //Sorteio da imagem
        rand_asphalt[i] =  Choice_Rand_IMG (rand_asphalt,i);
        Concat_Numeric_IMG (p_img,rand_asphalt[i]);

        //Tamanho da imagem
        SizeOf_Matrix(&lines,&columns,p_img);

        //Alocando matriz para a imagem
        Alloc_Dealloc(mat_img,lines,columns,'A');

        //Carregar imagem
        Upload_Image(lines,columns,mat_img,p_img);

        // Executar ILBP e GLCM
        Get_Neighborhood_ILBP_GLCM(mat_img,lines,columns,feature_Vectors_Asphalt,sizeVector,i,gray_Levels);

        //Desalocando matriz da imagem
        Alloc_Dealloc(mat_img,lines,columns,'D');

    }
    //Normalização e Média dos vetores característica
    Normalization_Feature_Vectors(feature_Vectors_Asphalt,sizeVector);
    Average_Vectors(feature_Vectors_Asphalt,avg_AsphaltVectors,sizeVector);

    //Desalocação

    for (i = 0;i < 25;i++){
        free(feature_Vectors_Grass[i]);
        free(feature_Vectors_Asphalt[i]);
    }

    free(feature_Vectors_Grass);
    free(feature_Vectors_Asphalt);

}
