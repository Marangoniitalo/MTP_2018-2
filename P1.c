// Ítalo Marangoni de Souza

// 11811EAU014

//P1.c

#include <stdio.h>

int main ()
{
	int estado=0, i=0; 
	char bits[256];
  
	printf ("Digite um numero binario: ");
	scanf ("%s", bits);
	
	while(bits[i] != '\0') 
	{
		if (estado == 0 && bits[i] == '0')
		{
			estado = 0; 
			i++;
		}
		
		if (estado == 0 && bits[i] == '1') 
		{
			estado = 1;
			i++;
		}
		
		if (estado == 1 && bits[i] == '0')
		{
			estado = 2; 
			i++;
		}
		
		if (estado == 1 && bits[i] == '1')
		{
			estado = 0;
			i++;
		}
		
		if (estado == 2 && bits[i] == '0')
		{
			estado = 1; 
			i++;
		}
		if (estado == 2 && bits[i] == '1')
		{
			estado = 2;
			i++;
		}
		
	}
	
	if (estado == 0)
	{
		printf ("O numero eh multiplo de 3.");
	}
	else 
	{
		printf ("O numero nao eh multiplo de 3.");
	}
	
	printf ("O numero digitado eh: %s", bits);
	return 0;}
