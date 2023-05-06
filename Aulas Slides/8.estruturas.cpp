/* Uma estrutura eh um conjunto de uma ou mais variaveis, que podem ser de tipos diferentes, agrupadas sob um unico nome. */
#include <stdio.h>

int main(void) {
	
	/* struct -> nicia a declaração da estrutura
		ALUNO -> identificador (facultativo) */
	struct ALUNO {
		char nome[40];
		int registro;
		int ano_entrada;
		char curso[20];
	} paulo;
	
	/* referenciar um elemento da estrutura */
	paulo.ano_entrada = 2023;
	printf("Ano de entrada: %d\n", paulo.ano_entrada);
	
	scanf("%d", &paulo.registro);
	printf("No de registro: %d\n", paulo.registro);
	
//	paulo.nome = "Paulo Correia";
//	printf("Nome: %s\n", paulo.nome);
	
	gets(paulo.curso);
	printf("Curso: %s\n", paulo.curso);
	
	
	return 0;
}
