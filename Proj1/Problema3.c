//15/0137770 - Lude Ribeiro
//14/0156909 - Nathalia Lorena Cardoso
#include <stdio.h>

//FUNÇÃO AUXILIAR
    void torreHanoi(int disco, char origemA, char destinoC, char auxiliarB){

    if(disco==1){
        printf("Mova o disco 1 da torre %c para %c\n", origemA, destinoC);}

    else{
        return
        torreHanoi(disco-1, origemA, auxiliarB, destinoC),
        printf("Mova o disco %d da torre %c para %c\n", disco, origemA, destinoC),
        torreHanoi(disco-1, auxiliarB, destinoC, origemA);}
      }


//FUNÇÃO PRINCIPAL
    int main(){
    int disco;

        printf("Insira o número de discos: ");
        scanf("%d", &disco);
        printf("Para resolver a Torre de Hanoi:\n");

    torreHanoi(disco, 'A', 'C', 'B');

    return 0;
}
