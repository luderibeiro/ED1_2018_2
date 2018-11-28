
/* Converte um número binário em um número decimal.
 * Retorna o número decimal. */

int Convert_Binary_Decimal(int *vet){
    int number = 0;
    int x,y;
    for (x = 0;x < 9;x++){
        number += *(vet+x) * pow(2,x);
    }
    return number;
}
