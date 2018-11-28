//Atualiza os valores das MCOs
void Generate_GLCM (int *matNeighb,int **MCO, int degree){
    int px_Ref,px_Cmp;

    px_Ref = *(matNeighb+1*3+1);//Pixel de Referência

    switch (degree){
        case 0:
            px_Cmp = *(matNeighb+1*3+2);
            MCO[px_Ref][px_Cmp]++;
            break;
        case 45:
            px_Cmp = *(matNeighb+0*3+2);
            MCO[px_Ref][px_Cmp]++;
            break;
        case 90:
            px_Cmp = *(matNeighb+0*3+1);
            MCO[px_Ref][px_Cmp]++;
            break;
        case 135:
            px_Cmp = *(matNeighb+0*3+0);
            MCO[px_Ref][px_Cmp]++;
            break;
        case 180:
            px_Cmp = *(matNeighb+1*3+0);
            MCO[px_Ref][px_Cmp]++;
            break;
        case 225:
            px_Cmp = *(matNeighb+2*3+0);
            MCO[px_Ref][px_Cmp]++;
            break;
        case 270:
            px_Cmp = *(matNeighb+2*3+1);
            MCO[px_Ref][px_Cmp]++;
            break;
        case 315:
            px_Cmp = *(matNeighb+2*3+2);
            MCO[px_Ref][px_Cmp]++;
            break;

    }

}
