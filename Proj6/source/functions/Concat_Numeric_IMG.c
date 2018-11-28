
/* Esta fun��o � respons�vel por concatenar o n�mero de uma imagem em uma string contendo o restante do endere�o da imagem.
 * Assim, formando o endere�o da imagem.
 * Retorna por refer�ncia o endere�o da imagem. */


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
