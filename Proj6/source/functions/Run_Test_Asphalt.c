

/* Imagens de teste: 25 imagens da classe Asphalt.
 * Esta função chama as funções necessárias para o teste do sistema.
 * Esta função retorna o número de imagens que foram classificadas corretamente. */

int Run_Test_Asphalt(int *choice_asphalt,double *avg_Grass,double *avg_Asphalt, int sizeVector){

    char *p_img;
    char img[35];
    char class_Img;
    char img_asphalt[30]  = "..\\DataSet\\asphalt\\asphalt_";//Mold
    int lines,columns,pos,degree,gray_Levels;
    int aux[51];
    int i,x,y,z;
    double contrast,energy,homogeneity;
    int correct = 0;
    int ts_asphalt[25];
    int **MCO;//Matriz de Co-Ocorrência
    int **mat_img;
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

    //Realiza os testes
    for (i = 0;i < 25;i++){
        for (x = 0;x < 35;x++){
            img[x] = '\0';
        }
        for (x = 0;x < 27;x++){
            img[x] = img_asphalt[x];
        }

        Concat_Numeric_IMG(p_img,ts_asphalt[i]);

        //Tamanho da imagem e Níveis de Cinza
        gray_Levels = SizeOf_Gray_Levels_IMG(&lines,&columns,p_img);

        //Alocando matriz para a imagem
        mat_img = Alloc_Dealloc_IMG(mat_img,lines,columns,'A');

        //Alocando matriz para MCO
        MCO = Alloc_Dealloc_MCO(MCO,gray_Levels,'A');

        //Carregar imagem
        Upload_Image(lines,columns,mat_img,p_img);

        // Executar ILBP
        Get_Neighborhood_ILBP(mat_img,lines,columns,feature_Vectors_Asphalt,i);

        //Executar GLCM
        pos = 512;
        for (degree = 0;degree <= 315;degree += 45){
            Algorithm_GLMC(mat_img,lines,columns,MCO,&energy,&contrast,&homogeneity,degree,gray_Levels);
            feature_Vectors_Asphalt[i][pos] = contrast;
            feature_Vectors_Asphalt[i][pos+1] = energy;
            feature_Vectors_Asphalt[i][pos+2] = homogeneity;
            pos += 3;
        }

        //Desalocando matriz da imagem
        mat_img = Alloc_Dealloc_IMG(mat_img,lines,columns,'D');

        //Desalocando MCO
        MCO = Alloc_Dealloc_MCO(MCO,gray_Levels,'D');

    }

    //Normalização dos vetores característica
    Normalization_Feature_Vectors(feature_Vectors_Asphalt,sizeVector);

    //Printar na base de dados

    printarArquivoAsphalt(feature_Vectors_Asphalt);

    //Executa classificação da imagem
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

    return (correct);

}
