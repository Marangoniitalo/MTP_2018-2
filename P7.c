// P7.c
// Ítalo Marangoni de Souza
// 11811EAU014
// MTP_2018-2

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
	float x, y;
}Ponto;

Ponto * gera(int N)
{
	Ponto * p = (Ponto *) calloc(N, sizeof(Ponto));
	int i;
	for(i = 0; i < N; i++)
	{
		p[i].x = cos(i * 2.0 * M_PI / (N - 1));
		p[i].y = sin(i * 2.0 * M_PI / (N - 1));
	}
	return p;
}
void mostrar_pontos(Ponto * p_inicial, Ponto * p_final)
{
	if(p_inicial < p_final)
	{
		printf("(%.3lf, %.3lf)", p_inicial -> x, p_inicial -> y);
		mostrar_pontos(p_inicial + 1, p_final);
	}
}
void grava_bin(Ponto * pini, int N) {
    FILE * arquivo;
    arquivo = fopen("pontos.dat", "wb");
    fwrite(pini, N, sizeof(Ponto), arquivo);
    fclose(arquivo);
}


Ponto * le_bin(char * nome_arquivo, unsigned int * pN) {
    Ponto * p = (Ponto *) malloc(sizeof(Ponto));
    unsigned int N = 0;
    FILE * arquivo;
    arquivo = fopen(nome_arquivo, "rb");
    while(1) {
        fread(p, 1, sizeof(Ponto), arquivo);
        if(feof(arquivo)) break;
        N++;
    }
    rewind(arquivo);
    p = (Ponto *) realloc(p, N*sizeof(Ponto));
    fread(p, N, sizeof(Ponto), arquivo);
    fclose(arquivo);
    *pN = N;
    return p;
}

int main()
{
	unsigned int N,opc;
	Ponto * p;
	printf("1 - Gravar arquivo; 2 - Ler arquivo: ");
    scanf("%u", &opc); getchar();
    if (opc == 1){
    	printf("Quantos pontos deseja? ");
	    scanf("%u", &N);	getchar();
    	p = gera(N);
    	grava_bin(p,N);
    	printf("Arquivo gravado");
	}
	if (opc == 2){
		p = le_bin("pontos.dat", &N);
		mostrar_pontos(p, p + N);
	}

	free(p);
	return 0;
}
