

/* Esta função é responsável por selecionar aleatoriamente imagens para o conjunto de treinamento.
 * Retorna por referência um vetor contendo o número de imagens que já foram escolhidas. */

int Choice_Rand_IMG(int *vet_img,int i){

    int img_rand;
    int x, totdif;

    srand((unsigned)time(NULL));
    do {
        totdif = 0;
        img_rand = (1 + rand()%(50));//a + (Rand() (mod b-a)); Generate random numbers in a range(a,b).
        for (x = 0;x < 25;x++){
            if (img_rand != *(vet_img+x)){
                totdif++;
            }
            else {
                break;
            }
        }
        if (totdif == 25){
            *(vet_img+i) = img_rand;
        }

    }while (totdif != 25);

    return (img_rand);

}
