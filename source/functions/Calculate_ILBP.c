
/* Esta função é responsável por gerar cada código ILBP.
 * Ele recebe uma matriz contendo o pixel central e os outros pixels para formar a vizinhança de oito.
 * Retorna o código ILBP mais baixo gerado pela combinação de binários gerados pelo algoritmo ILBP. */

int Calculate_ILBP(int *matNeighb){
    double avg,sum = 0;
    int i,j;
    int mat_bin[3][3];
    int vet_bin[9];
    int codF_ILBP;

    //Limiarização Global.
    for (i = 0;i < 3;i++){
        for (j = 0;j < 3;j++){
            sum += *(matNeighb+i*3+j);
        }
    }
    avg = sum / 9.0;

    for (i = 0;i < 3;i++){
        for (j = 0;j < 3;j++){
            if (*(matNeighb+i*3+j) >= avg){
                mat_bin[i][j] = 1;
            }
            else {
                mat_bin[i][j] = 0;
            }
        }
    }
    vet_bin[8] = mat_bin[0][0];
    vet_bin[7] = mat_bin[0][1];
    vet_bin[6] = mat_bin[0][2];
    vet_bin[5] = mat_bin[1][2];
    vet_bin[4] = mat_bin[2][2];
    vet_bin[3] = mat_bin[2][1];
    vet_bin[2] = mat_bin[2][0];
    vet_bin[1] = mat_bin[1][0];
    vet_bin[0] = mat_bin[1][1];

    codF_ILBP = Lower_ILBP(&vet_bin[0]);

    return (codF_ILBP);

}
