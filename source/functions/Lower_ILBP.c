

/* Esta função calcula o menor código ILBP gerado pela combinação de binários gerados pelo algoritmo ILBP.
 * Desta forma, garantindo a invariância na rotação da imagem. */

int Lower_ILBP(int *vet){
    int vet_aux[9];
    int x,y,z = 0;
    int lower_Code,aux,decimal_Value;

    lower_Code = Convert_Binary_Decimal(vet);
    for (z = 0;z < 9;z++){
        aux = *vet;
        for (x = 0;x < 9;x++){
            vet_aux[x] = *(vet+x);
        }
        for (x = 1;x < 9;x++){
            *(vet+x-1) = vet_aux[x];
        }
        vet[8] = aux;
        decimal_Value = Convert_Binary_Decimal(vet);
        if (decimal_Value < lower_Code){
            lower_Code = decimal_Value;
        }
    }
    return lower_Code;

}


