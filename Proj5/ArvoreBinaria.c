#include <stdio.h>
#include <stdlib.h>

struct No
{
    int numero;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No;

void criarArvore(No **pRaiz)
{
    *pRaiz = NULL;
}
void insercao(No **pRaiz, int numero2)
{
	if (*pRaiz == NULL)
	{
	      *pRaiz=(No *)malloc(sizeof (No));
	      (*pRaiz)->esquerda=NULL;
	      (*pRaiz)->direita=NULL;
	      (*pRaiz)->numero=numero2;
	}
	else
        {
		if (numero2 < ((*pRaiz)->numero))
		{
			insercao(&((*pRaiz)->esquerda), numero2);
		}
		else
		{
			insercao(&((*pRaiz)->direita), numero2);
		}
	}
}


int main () {

    int **pRaiz;
	int numero2;
	criarArvore();
	insercao();
