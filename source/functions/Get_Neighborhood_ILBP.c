
/*Esta função é responsável por percorrer a imagem, formando vizinhanças de oito. Para cada vizinhaça é chamada a função que gera o código ILBP.*/

void Get_Neighborhood_ILBP(int **mat_IMG, int lines, int columns,double **feature_Vectors,int vet_Index){
    int i,j;
    int mat_neighbors[3][3];
    int mat_bin[3][3];
    int vet_bin[9];
    int codILBP;

    //Busca a próxima vizinhaça de 8.
    for (i = 1;i < (lines-1);i++){
        for (j = 1;j < (columns - 1);j++){
            mat_neighbors[0][0] = mat_IMG[i-1][j-1];
            mat_neighbors[0][1] = mat_IMG[i-1][j];
            mat_neighbors[0][2] = mat_IMG[i-1][j+1];
            mat_neighbors[1][0] = mat_IMG[i][j-1];
            mat_neighbors[1][1] = mat_IMG[i][j];
            mat_neighbors[1][2] = mat_IMG[i][j+1];
            mat_neighbors[2][0] = mat_IMG[i+1][j-1];
            mat_neighbors[2][1] = mat_IMG[i+1][j];
            mat_neighbors[2][2] = mat_IMG[i+1][j+1];

            //Calcula o código ILBP
            codILBP = Calculate_ILBP(&mat_neighbors[0][0]);

            feature_Vectors[vet_Index][codILBP] = feature_Vectors[vet_Index][codILBP] + 1;//Aumenta a frequência do código.

        }
    }


}


