
/* Converte um n�mero bin�rio em um n�mero decimal.
 * Retorna o n�mero decimal. */

int Convert_Binary_Decimal(int *vet){
    int number = 0;
    int x,y;
    for (x = 0;x < 9;x++){
        number += *(vet+x) * pow(2,x);
    }
    return number;
}
