/*Author: Gustavo Nogueira
 *Date: 28/12/2017
 */

/*Test grade: 25 images of Asphalt class.
 *This function calls the functions required for system test.
 *This function returns the number of images that were sorted correctly.*/

int Run_Test_Asphalt(int *choice_asphalt,double *avg_Grass,double *avg_Asphalt, int sizeVector,int gray_Levels){

    char *p_img;
    char img[35];
    char class_Img;
    char img_asphalt[30]  = "..\\DataSet\\asphalt\\asphalt_";//Mold
    int lines,columns;
    int aux[51];
    int i,x,y,z;//Accountants
    int different;
    int correct = 0;
    int ts_asphalt[25];
    int **mat_img;//Stores the pixels of the image
    double **feature_Vectors_Asphalt;

    p_img = &img[0];

    //Definindo imagens que serão utilizadas para o teste.
    y = 0;
    for (x = 0;x < 51;x++){
        aux[x] = 0;
    }
    for (z = 0;z < 25;z++){
            aux[*(choice_asphalt+z)] = *(choice_asphalt+z);
    }
    for (x = 1;x < 51;x++){
            if (aux[x] == 0){
                ts_asphalt[y] = x;
                y++;
            }
    }

    //Alocação dos vetores caracteríticas.
    feature_Vectors_Asphalt = (double **) calloc(25,sizeof(double *));
    for (x = 0;x < 25;x++){
        feature_Vectors_Asphalt[x] = (double *) calloc(sizeVector,sizeof(double));
    }


    //Call functions needed to read the pixels of the images.
    for (i = 0;i < 25;i++){
        for (x = 0;x < 35;x++){
            img[x] = '\0';
        }
        for (x = 0;x < 27;x++){
            img[x] = img_asphalt[x];
        }

        Concat_Numeric_IMG(p_img,ts_asphalt[i]);

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

    //Normalização dos vetores característica
    Normalization_Feature_Vectors(feature_Vectors_Asphalt,sizeVector);

    //Performs image classification
    for (x = 0;x < 25;x++){
        class_Img = Euclidean_Distance(feature_Vectors_Asphalt,avg_Grass,avg_Asphalt,x,sizeVector);
        if (class_Img == 'a'){
            correct++;
        }
    }
    //Desalocação

    for (i = 0;i < 25;i++){
        free(feature_Vectors_Asphalt[i]);
    }
    free(feature_Vectors_Asphalt);

    return (correct);

}
