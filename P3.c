//Ítalo Marangoni de Souza
// 11811EAU014
// MTP_2018-2

#include <stdio.h>

int main ()
{
char bits[256];
int cum=0, i;

printf ("Digite algo: ");
scanf ("%s", bits);
getchar();
for (i=0; bits[i] != '\0'; i++)
	{
	if(bits[i] >=48 && bits[i]<=57)
	{
		bits[i]=bits[i]-'0';
		cum= cum*10 + bits[i];
	}

}
printf ("Os numeros presentes sao: %d", cum);
return 0;
}
