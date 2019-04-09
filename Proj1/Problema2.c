//15/0137770 - Lude Ribeiro
//14/0156909 - Nathalia Lorena Cardoso
#include <stdio.h>
#include <stdlib.h>

float notas[10];
int contador,aprovados_reprovados[2], vetorAPR[10], percent_aprvReprov[2] = {};

void recebe_notas(float *notas, int qtdElementosVetor, int *vetorAPR){
	for(int x = 0; x < qtdElementosVetor; x++){
		if(notas[x] >= 6)
			vetorAPR[x] = 1; //aluno aprovado
		else
			vetorAPR[x] = 0; //aluno reprovador
	}
}

void conta_notas(int *ponteiroVetorAPR, int qtdElementosVetor,int *aprovados_reprovados){
	for(int x = 0; x< qtdElementosVetor; x++){
        if(ponteiroVetorAPR[x] > 0)//aluno aprovado
			aprovados_reprovados[1] += 1 ;
		else
			aprovados_reprovados[0] += 1;
	}
}

int percent_aprov(int *aprovados_reprovados, int *percent_aprvReprov){

	int totAlunos = aprovados_reprovados[0]+aprovados_reprovados[1];
	percent_aprvReprov[1] = (100 * aprovados_reprovados[1])/(totAlunos);
	percent_aprvReprov[0] = (100* aprovados_reprovados[0])/(totAlunos);

	if(percent_aprvReprov[1] > 50)
		return 1;
	else
		return 0;
}

void main(){
    printf("entre com as 10 notas do aluno: \n");
	contador = 0;

	while(contador <= 9){
		scanf("%f",&notas[contador]);
		contador++;
	}

	recebe_notas(notas,10,vetorAPR);
	conta_notas(vetorAPR, 10, aprovados_reprovados);
	int result = percent_aprov(aprovados_reprovados, percent_aprvReprov);
	printf("Aprovados = %d \n",aprovados_reprovados[1]);
	printf("Reprovados = %d \n",aprovados_reprovados[0]);
	printf("Percentual de aprovados = %d%%  \n",percent_aprvReprov[1]);
	printf("Percentual de reprovados = %d%% \n",percent_aprvReprov[0]);
	if(result > 0)
		printf("Mais da metade da turma foi aprovada! \n");
	else
		printf("Mais da metade da turma foi reprovada! \n");
}
