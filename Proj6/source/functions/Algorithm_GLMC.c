
//Gera as MCOs e retorna as métricas GLCM

void Algorithm_GLMC(int **mat_img,int lines,int columns,int **MCO,double *energy, double *contrast, double *homogeneity,int degree,int gray_levels){
    int i,j;
    int px_ref,px_cmp;

    //Zerando variáveis
    *contrast = 0;
    *energy = 0;
    *homogeneity = 0;

    for (i = 0;i < gray_levels;i++){
        for (j = 0;j < gray_levels;j++){
            MCO[i][j] = 0;
        }
    }

    //Gerando MCO
    switch (degree){
        case 0:
            for (i = 0;i < lines;i++){
                for (j = 0;j < (columns - 1);j++){
                    px_ref = mat_img[i][j];
                    px_cmp = mat_img[i][j+1];
                    MCO[px_ref][px_cmp] = MCO[px_ref][px_cmp] +1;//Alterando a frequência
                }
            }
            break;
        case 45:
            for (i = 1;i < lines;i++){
                for (j = 0;j < (columns - 1);j++){
                    px_ref = mat_img[i][j];
                    px_cmp = mat_img[i-1][j+1];
                    MCO[px_ref][px_cmp] = MCO[px_ref][px_cmp] +1;//Alterando a frequência
                }
            }
            break;
        case 90:
            for (i = 1;i < lines;i++){
                for (j = 0;j < columns ;j++){
                    px_ref = mat_img[i][j];
                    px_cmp = mat_img[i-1][j];
                    MCO[px_ref][px_cmp] = MCO[px_ref][px_cmp] +1;//Alterando a frequência
                }
            }
            break;
        case 135:
            for (i = 1;i < lines;i++){
                for (j = 1;j < columns ;j++){
                    px_ref = mat_img[i][j];
                    px_cmp = mat_img[i-1][j-1];
                    MCO[px_ref][px_cmp] = MCO[px_ref][px_cmp] +1;//Alterando a frequência
                }
            }
            break;
        case 180:
            for (i = 0;i < lines;i++){
                for (j = 1;j < columns ;j++){
                    px_ref = mat_img[i][j];
                    px_cmp = mat_img[i][j-1];
                    MCO[px_ref][px_cmp] = MCO[px_ref][px_cmp] +1;//Alterando a frequência
                }
            }
            break;
        case 225:
            for (i = 0;i < (lines - 1);i++){
                for (j = 1;j < columns ;j++){
                    px_ref = mat_img[i][j];
                    px_cmp = mat_img[i+1][j-1];
                    MCO[px_ref][px_cmp] = MCO[px_ref][px_cmp] +1;//Alterando a frequência
                }
            }
            break;
        case 270:
            for (i = 0;i < (lines - 1);i++){
                for (j = 0;j < columns ;j++){
                    px_ref = mat_img[i][j];
                    px_cmp = mat_img[i+1][j];
                    MCO[px_ref][px_cmp] = MCO[px_ref][px_cmp] +1;//Alterando a frequência
                }
            }
            break;
        case 315:
            for (i = 0;i < (lines - 1);i++){
                for (j = 0;j < (columns - 1) ;j++){
                    px_ref = mat_img[i][j];
                    px_cmp = mat_img[i+1][j+1];
                    MCO[px_ref][px_cmp] = MCO[px_ref][px_cmp] +1;//Alterando a frequência
                }
            }
            break;

    }

    //Métricas GLCM
    //Ordem no vetor característica: Contraste - Energia - Homogeneidade
    for (i = 0;i < gray_levels;i++){
        for (j = 0;j < gray_levels;j++){

            *contrast += (double)  pow(abs(i - j),2) * MCO[i][j];//Contraste
            *energy += (double) pow(MCO[i][j],2);//Energia
            *homogeneity += (double) MCO[i][j] * (MCO[i][j]/(1 + pow(abs(i - j),2)));//Homogeneidade

        }
    }

}
