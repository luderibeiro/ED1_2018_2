No* carregaArquivo(No* n){
	char nomeArquivo[9];
	printf("Digite o nome do arquivo: ", );
	scanf("%s\n", nomeArquivo);
	FILE *arquivo;
	arquivo = fopen(nomeArquivo,"r");
	rewind(arquivo);
	int i = 0;

	if(n == NULL){
		n = (No*) malloc(sizeof(No));
		n->esquerda = NULL;
		n->direita = NULL;
	}
	fread(&n->numero, sizeof(No), 1, arquivo);

	fclose(arquivo);
	return n;
}

void loadTreeFromFile(){

}

void showTree(){

}

void isFull(){

}

void searchValue(){

}

void getHeight(){

}

void removeValue(){

}

void printInOrder(){

}

void printPreOrder(){

}

void printPostOrder(){

}

void balanceTree(){

}

void liberaArvore(){

}
