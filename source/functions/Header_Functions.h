/*Author: Gustavo Nogueira
 *Date: 28/12/2017
 */
#ifndef HEADER_FUNCTIONS_H_INCLUDED
#define HEADER_FUNCTIONS_H_INCLUDED

void Run_Training (double *, double *, int *,int *, int );

int Run_Test_Grass (int *,double *,double *, int );

int Run_Test_Asphalt(int *,double *,double *, int );

int SizeOf_Gray_Levels_IMG(int *,int *,char *);

void Concat_Numeric_IMG (char *, int );

int Choice_Rand_IMG(int *,int i);

int **Alloc_Dealloc_IMG(int **,int ,int ,char );

int **Alloc_Dealloc_MCO(int **,int ,char );

void Upload_Image(int ,int ,int **,char *);

void Get_Neighborhood_ILBP(int **, int , int ,double **,int );

void Algorithm_GLMC(int **,int ,int ,int **,double *, double *, double *,int ,int );

int Convert_Binary_Decimal(int *);

int Lower_ILBP(int *);

int Calculate_ILBP(int *);

//
void printarArquivoGrass(double **);
void printarArquivoAsphalt(double **);

void Normalization_Feature_Vectors (double **,int );

void Average_Vectors (double **, double *, int );

char Euclidean_Distance(double **, double *, double *,int , int );

void Execution_Report (double hit_rate, double rate_ac, double rate_rej,int correct_Asphalt, int correct_Grass);

#endif // HEADER_FUNCTIONS_H_INCLUDED
