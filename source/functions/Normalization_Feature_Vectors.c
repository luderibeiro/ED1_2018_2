

/* Normaliza��o min-max
 * Esta fun��o � respons�vel por normalizar os vetores caracter�sticas, agrupando assim os dados em um pequeno intervalo de valores.
 * Retorna por refer�ncia o vetor caracter�stica normalizado. */

void Normalization_Feature_Vectors (double **feature_Vectors,int sizeVector){
    int x,y,z;
    double max = 0,min = 0;

    for (x = 0;x < 25;x++){
        max = feature_Vectors[x][0];
        min = feature_Vectors[x][0];
        for (z = 0;z < sizeVector;z++){
            if (max < feature_Vectors[x][z]){
                max = feature_Vectors[x][z];
            }
            else {
                if (min > feature_Vectors[x][z]){
                    min = feature_Vectors[x][z];
                }
            }
        }

        for (y = 0;y < sizeVector;y++){
            feature_Vectors[x][y] = (feature_Vectors[x][y] - min)/(max - min);
        }

    }

}


