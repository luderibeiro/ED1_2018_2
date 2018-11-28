

/* Esta função é responsável pelo cálculo da média dos vetores caracterítica.*/

void Average_Vectors (double **feature_Vectors, double *avg_Vectors, int sizeVector){
    int x,y;
    double sum = 0;

    for (y = 0;y < sizeVector;y++){
        for (x = 0;x < 25;x++){
            sum += feature_Vectors[x][y];
        }
        *(avg_Vectors + y) = sum / 25.0;
        sum = 0;
    }
}
