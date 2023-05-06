/* 2. Entrada e Saída no console */

/* 
Diretiva include 

Para aessar as bibliotecas que contém estas funções o programa usa a diretiva #include <umnomequalquer.h> 
no iníciodo programa.

Programadores usam < e > para incluir os arquivos de cabeçalho padrão e aspas "" para a inclusão de arquivos do
próprio projeto.
*/
#include <stdio.h>
//#include "minhasfuncoes.h"

int main(void) {
	
	/*
	printf faz com que dados sejam escritos na saída padrão, que normalmente é a tela do computador.
	*/
	int ano_atual = 2023 ;
	printf ( "Estamos no ano %d ", ano_atual );
	
	/*
		%c Caracter simples
		%d Inteiro decimal com sinal
		%i Inteiro decimal com sinal
		%E Real em notação científica com E
		%e Real em notação científica com e
		%f Real em ponto flutuante
		%G %E ou %f, o que for mais curto
		%g %g ou %f, o que for mais curto
		%o Inteiro em base octal
		%s Cadeia Caracteres
		%u Inteiro decimal sem sinal
		%x Inteiro em base hexadecimal (letras minúsculas)
		%X Inteiro em base hexadecimal (letras maiúsculas)
		%p Endereço de memória
		%% Imprime o caractere %
	*/
	
	/*
	A função scanf é utilizada para entrada de dados a partir do teclado.
	*/
	int dia, mes, ano;
	int lidos;
	
	printf("Entre com uma data no formato dd/mm/aaaa\n");
	/* 
	No caso de scanf os argumentos são os endereços das variáveis que irão receber os valores lidos.
	*/
	lidos = scanf("%d/%d/%d", &dia, &mes, &ano);
	
	printf("Li %d dados\n", lidos);
	printf("Li a data %02d --- %02d --- %04d\n", dia, mes, ano);
	

	/*
	Para ler e escrever caracteres do teclado as funções de entradae saída mais simples são getchar e putchar.
	*/
	char c;
	
	printf("Entre com um algarismo entre 0 e 9.\n");
	c = getchar();
	
	printf("O caractere lido foi o ") ;
	putchar(c);
	
	return 0 ;
}




