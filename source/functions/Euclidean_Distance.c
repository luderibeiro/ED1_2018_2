

/* Esta função é responsável pelo cálculo da distância euclidiana entre um vetor caracterítica normalizado (uma imagem sendo testada) e outros dois vetores que caracterizam as duas classes de imagem.
 * Retorna "g" se a imagem é classificada como sendo da classe Grass. Retorna "a" se a imagem for classificada como sendo da classe Asphalt. */

char Euclidean_Distance(double **feature_Vectors, double *avg_Grass, double *avg_Asphalt,int index, int sizeVector){
    double grass_dist;
    double asphalt_dist;
    double sum_grass = 0;
    double sum_asphalt = 0;
    int i;

    for (i = 0;i < sizeVector;i++){
        sum_grass += pow((feature_Vectors[index][i] - *(avg_Grass+i)),2);
        sum_asphalt += pow((feature_Vectors[index][i] - *(avg_Asphalt+i)),2);
    }
    grass_dist = sqrt(sum_grass);
    asphalt_dist = sqrt(sum_asphalt);

    if (asphalt_dist > grass_dist){
        return 'g';
    }
    else {
        return 'a';
    }

}



