//Ítalo Marangooni de Souza
//11811EAU014
//MTP_2018-2
#include <stdio.h>
typedef
	unsigned long long int
Bytes8;

typedef
	struct LCG{ Bytes8 a, c, m, rand_max, atual; }
LCG;

void semente(LCG*r, Bytes8 seed){
	//constantes do POSIX [de]rand48, glibc [de]rand48[_r]
	//ULL transforma a constante 'int' em 'unsigned long long int'
	r->a = 0x5DEECE66DULL;
	r->c = 11ULL;
	r->m = (1ULL << 48);
	r->rand_max = r->m - 1;
	r->atual = seed;
}

Bytes8 lcg_rand(LCG*r){
	r->atual = (r->a * r->atual + r->c) % r->m;
	return r->atual;
}

double lcg_rand_01(LCG * r){
	return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG*r){
	int i;
	for(i=0; i<tam; i++)
	vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float soma(float *inicio_vetor, float *fim_vetor){
	float E=0;
	float *parcela = inicio_vetor;
	while(parcela != fim_vetor)
		{
			E += *parcela;
			parcela++;
		}
	return E;
}

float produto(float *inicio_vetor, float *fim_vetor){
	float P=1;
	float *parcela = inicio_vetor;
	while(parcela != fim_vetor)
		{
			P *= *parcela;
			parcela++;
		}
	return P;
}
int main(){
	LCG random; semente(&random, 123456);
	printf("Serao gerados 50 numeros aleatorios.\n");
	float vet[50];
	gera_numeros(vet, 50, 0.5, 1.5, &random);
	int opc;
	scanf("%d",&opc);
	if(opc == 1)
	printf("%f",soma(vet, vet+50));
	if(opc == 2)
	printf("%f",produto(vet, vet+50));
}
