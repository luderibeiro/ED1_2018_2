
void Generate_Metrics_GLCM(double *metrics_GLCM,int **MCO_Degree_0,int **MCO_Degree_45,int **MCO_Degree_90,int **MCO_Degree_135,int **MCO_Degree_180,int **MCO_Degree_225,int **MCO_Degree_270,int **MCO_Degree_315){
    int i,j;

    //Ordem: Contraste - Energia - Homogeneidade --> Menor Grau para o Maior Grau

    for (i = 0;i < 24;i++){
        *(metrics_GLCM + i) = 0.0;
    }

    for (i = 0;i < 256;i++){
        for (j = 0;j < 256;j++){

            //Degree 0
            *(metrics_GLCM + 0) += (double)  pow(abs(i - j),2) * MCO_Degree_0[i][j];//Contraste
            *(metrics_GLCM + 1) += (double) pow(MCO_Degree_0[i][j],2);//Energia
            *(metrics_GLCM + 2) += (double) MCO_Degree_0[i][j] * (MCO_Degree_0[i][j]/(1 + pow(abs(i - j),2)));//Homogeneidade

            //Degree 45
            *(metrics_GLCM + 3) += (double) pow(abs(i - j),2) * MCO_Degree_45[i][j];//Contraste
            *(metrics_GLCM + 4) += (double) pow(MCO_Degree_45[i][j],2);//Energia
            *(metrics_GLCM + 5) += (double) MCO_Degree_45[i][j] * (MCO_Degree_45[i][j]/(1 + pow(abs(i - j),2)));//Homogeneidade

            //Degree 90
            *(metrics_GLCM + 6) += (double) pow(abs(i - j),2) * MCO_Degree_90[i][j];//Contraste
            *(metrics_GLCM + 7) += (double) pow(MCO_Degree_90[i][j],2);//Energia
            *(metrics_GLCM + 8) += (double) MCO_Degree_90[i][j] * (MCO_Degree_90[i][j]/(1 + pow(abs(i - j),2)));//Homogeneidade

            //Degree 135
            *(metrics_GLCM + 9) += (double) pow(abs(i - j),2) * MCO_Degree_135[i][j];//Contraste
            *(metrics_GLCM + 10) += (double) pow(MCO_Degree_135[i][j],2);//Energia
            *(metrics_GLCM + 11) += (double) MCO_Degree_135[i][j] * (MCO_Degree_135[i][j]/(1 + pow(abs(i - j),2)));//Homogeneidade

            //Degree 180
            *(metrics_GLCM + 12) += (double) pow(abs(i - j),2) * MCO_Degree_180[i][j];//Contraste
            *(metrics_GLCM + 13) += (double) pow(MCO_Degree_180[i][j],2);//Energia
            *(metrics_GLCM + 14) += (double) MCO_Degree_180[i][j] * (MCO_Degree_180[i][j]/(1 + pow(abs(i - j),2)));//Homogeneidade

            //Degree 225
            *(metrics_GLCM + 15) += (double) pow(abs(i - j),2) * MCO_Degree_225[i][j];//Contraste
            *(metrics_GLCM + 16) += (double) pow(MCO_Degree_225[i][j],2);//Energia
            *(metrics_GLCM + 17) += (double) MCO_Degree_225[i][j] * (MCO_Degree_225[i][j]/(1 + pow(abs(i - j),2)));//Homogeneidade

            //Degree 270
            *(metrics_GLCM + 18) += (double) pow(abs(i - j),2) * MCO_Degree_270[i][j];//Contraste
            *(metrics_GLCM + 19) += (double) pow(MCO_Degree_270[i][j],2);//Energia
            *(metrics_GLCM + 20) += (double) MCO_Degree_270[i][j] * (MCO_Degree_270[i][j]/(1 + pow(abs(i - j),2)));//Homogeneidade

            //Degree 315
            *(metrics_GLCM + 21) += (double) pow(abs(i - j),2) * MCO_Degree_315[i][j];//Contraste
            *(metrics_GLCM + 22) += (double) pow(MCO_Degree_315[i][j],2);//Energia
            *(metrics_GLCM + 23) += (double) MCO_Degree_315[i][j] * (MCO_Degree_315[i][j]/(1 + pow(abs(i - j),2)));//Homogeneidade

        }
    }

}
