// P6.c
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

int main()
{
	unsigned int N;
	Ponto * p;
	printf("Quantos pontos deseja? ");
	scanf("%u", &N);	getchar();
	p = gera(N);
	mostrar_pontos(p, p + N);
	free(p);
	return 0;
}
