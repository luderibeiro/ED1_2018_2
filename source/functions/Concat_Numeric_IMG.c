
/* Esta função é responsável por concatenar o número de uma imagem em uma string contendo o restante do endereço da imagem.
 * Assim, formando o endereço da imagem.
 * Retorna por referência o endereço da imagem. */


void Concat_Numeric_IMG (char *img, int num_img){
     int dg,digits = 0;

    while (digits < 2){
        if (digits == 0){
            dg = num_img / 10;
        }
        else{
            if (digits == 1){
                dg = num_img % 10;
            }
        }
        switch(dg){
            case 0:
                strcat(img,"0");
                break;
            case 1:
                strcat(img,"1");
                break;
            case 2:
                strcat(img,"2");
                break;
            case 3:
                strcat(img,"3");
                break;
            case 4:
                strcat(img,"4");
                break;
            case 5:
                strcat(img,"5");
                break;
            case 6:
                strcat(img,"6");
                break;
            case 7:
                strcat(img,"7");
                break;
            case 8:
                strcat(img,"8");
                break;
            case 9:
                strcat(img,"9");
                break;
        }
        digits++;
    }
    strcat(img,".txt");
}
