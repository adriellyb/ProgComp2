/* 2. Entrada e Sa�da no console */

/* 
Diretiva include 

Para aessar as bibliotecas que cont�m estas fun��es o programa usa a diretiva #include <umnomequalquer.h> 
no in�ciodo programa.

Programadores usam < e > para incluir os arquivos de cabe�alho padr�o e aspas "" para a inclus�o de arquivos do
pr�prio projeto.
*/
#include <stdio.h>
//#include "minhasfuncoes.h"

int main(void) {
	
	/*
	printf faz com que dados sejam escritos na sa�da padr�o, que normalmente � a tela do computador.
	*/
	int ano_atual = 2023 ;
	printf ( "Estamos no ano %d ", ano_atual );
	
	/*
		%c Caracter simples
		%d Inteiro decimal com sinal
		%i Inteiro decimal com sinal
		%E Real em nota��o cient�fica com E
		%e Real em nota��o cient�fica com e
		%f Real em ponto flutuante
		%G %E ou %f, o que for mais curto
		%g %g ou %f, o que for mais curto
		%o Inteiro em base octal
		%s Cadeia Caracteres
		%u Inteiro decimal sem sinal
		%x Inteiro em base hexadecimal (letras min�sculas)
		%X Inteiro em base hexadecimal (letras mai�sculas)
		%p Endere�o de mem�ria
		%% Imprime o caractere %
	*/
	
	/*
	A fun��o scanf � utilizada para entrada de dados a partir do teclado.
	*/
	int dia, mes, ano;
	int lidos;
	
	printf("Entre com uma data no formato dd/mm/aaaa\n");
	/* 
	No caso de scanf os argumentos s�o os endere�os das vari�veis que ir�o receber os valores lidos.
	*/
	lidos = scanf("%d/%d/%d", &dia, &mes, &ano);
	
	printf("Li %d dados\n", lidos);
	printf("Li a data %02d --- %02d --- %04d\n", dia, mes, ano);
	

	/*
	Para ler e escrever caracteres do teclado as fun��es de entradae sa�da mais simples s�o getchar e putchar.
	*/
	char c;
	
	printf("Entre com um algarismo entre 0 e 9.\n");
	c = getchar();
	
	printf("O caractere lido foi o ") ;
	putchar(c);
	
	return 0 ;
}




