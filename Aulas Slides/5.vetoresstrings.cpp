/* 5. Vetores e Strings */
#include <stdio.h>
#include <string.h>
#define TAM 80

int main(void) {
	
	// cadeia de caracteres
	/* entrada: 
		Física Geral III - F-328 Primeiro Semestre de 2013 IFGW - UNICAMP
		Capacitores e Dielétricos -- Corrente e Resistência Elétrica
	*/
	
	// exercicio 1
	char str1[TAM], str2[TAM];
	
	gets(str1);
	gets(str2);
	
	// truncado
	(str2[0] > str1[0]) ? printf("%s\n%s\n\n", str1, str2) : printf("%s\n%s\n\n", str2, str1) ;
	
	// quantas letras 'a' e quantas maiusculas
	int cont1 = 0, cont2 = 0, numM1 = 0, numM2 = 0;
	
	for(int i = 0; i < strlen(str1); i++) {
		if(str1[i] == 'a') {
			cont1++;
		}
		
		if(str1[i] >= 'A' && str1[i] <= 'Z') {
			numM1++;
		}
	}
	
	for(int i = 0; i < strlen(str2); i++) {
		if(str2[i] == 'a') {
			cont2++;
		}
		
		if(str2[i] >= 'A' && str2[i] <= 'Z') {
			numM2++;
		}
	}
	
	printf("Num de 'a' na string 1: %d\n", cont1);
	printf("Num de 'a' na string 2: %d\n\n", cont2);
	printf("Num de maiusculas na string 1: %d\n", numM1);
	printf("Num de maiusculas na string 2: %d\n\n", numM2);
	
	return 0;
}
