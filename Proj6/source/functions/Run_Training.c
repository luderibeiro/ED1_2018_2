
/* Esta função chama as funções necessárias para o treinamento do sistema.
 * Para o treinamento, 25 imagens da classe Asphalt e 25 imagens da classe Grass. */

void Run_Training (double *avg_GrassVectors, double *avg_AsphaltVectors, int *rand_grass,int *rand_asphalt, int sizeVector){

    char *p_img;
    char img_grass[25] = "..\\DataSet\\grass\\grass_";//Molds
    char img_asphalt[30]  = "..\\DataSet\\asphalt\\asphalt_";
    char img[35];
    int i,x,y;
    int lines,columns;
    int pos,degree,gray_Levels;
    int **mat_img;
    int **MCO;//Matriz de Co-Ocorrência
    double contrast,energy,homogeneity;
    double **feature_Vectors_Grass;//Vetor caracterítica do conjunto de treinamento; Cada linha representa uma imagem.
    double **feature_Vectors_Asphalt;//Vetor caracterítica do conjunto de treinamento.

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
    for (i = 0;i < 25;i++){
        feature_Vectors_Grass[i] = (double *) calloc(sizeVector,sizeof(double));
        feature_Vectors_Asphalt[i] = (double *) calloc(sizeVector,sizeof(double));
    }

    //Treinando Classe Grass
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

        //Tamanho da imagem e Níveis de Cinza
        gray_Levels = SizeOf_Gray_Levels_IMG(&lines,&columns,p_img);

        //Alocando matriz para a imagem
        mat_img = Alloc_Dealloc_IMG(mat_img,lines,columns,'A');

        //Alocando matriz para MCO
        MCO = Alloc_Dealloc_MCO(MCO,gray_Levels,'A');

        //Carregar imagem
        Upload_Image(lines,columns,mat_img,p_img);

        //Executar ILBP
        Get_Neighborhood_ILBP(mat_img,lines,columns,feature_Vectors_Grass,i);

        //Executar GLCM
        pos = 512;
        for (degree = 0;degree <= 315;degree += 45){
            Algorithm_GLMC(mat_img,lines,columns,MCO,&energy,&contrast,&homogeneity,degree,gray_Levels);
            feature_Vectors_Grass[i][pos] = contrast;
            feature_Vectors_Grass[i][pos+1] = energy;
            feature_Vectors_Grass[i][pos+2] = homogeneity;
            pos += 3;
        }

        //Desalocando matriz da imagem
        mat_img = Alloc_Dealloc_IMG(mat_img,lines,columns,'D');

        //Desalocando MCO
        MCO = Alloc_Dealloc_MCO(MCO,gray_Levels,'D');

    }
    //Normalização e Média dos vetores característica
    Normalization_Feature_Vectors (feature_Vectors_Grass,sizeVector);
    Average_Vectors(feature_Vectors_Grass,avg_GrassVectors,sizeVector);

    //Printar na base de dados

    printarArquivoGrass(feature_Vectors_Grass);

    //Treinando Classe Asphalt

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
    //Normalização e Média dos vetores característica
    Normalization_Feature_Vectors(feature_Vectors_Asphalt,sizeVector);
    Average_Vectors(feature_Vectors_Asphalt,avg_AsphaltVectors,sizeVector);


    //Printar na base de dados

    printarArquivoAsphalt(feature_Vectors_Asphalt);

    //Desalocação

    for (i = 0;i < 25;i++){
        free(feature_Vectors_Grass[i]);
        free(feature_Vectors_Asphalt[i]);
    }

    free(feature_Vectors_Grass);
    free(feature_Vectors_Asphalt);

}
