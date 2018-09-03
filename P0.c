/* P0.c */
/* Ítalo Marangoni de Souza */
/* 11811EAU014 */

#include <stdio.h>

int main(int argc, char ** argv) {

int i;

if(argc>1){
if(argc > 2)
for(i=0;i<argv[2][0]-'0';i++)
printf("valeu, %s\n", argv[1]);
else
printf("saudacoes, %s\n", argv[1]);
}
else
printf("ola!\n");
return 0;
}
