#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int *v, int tam) {
	
	int i;
	
	for(i = 0; i < tam; i++) {
    	printf("%d ", *(v + i)); //imprimindo conteudo do apontado pelo ponteiro 
	}
	printf("\n\n");
}

void imprimirVetorLetras(char *v, int tam) {
	
	int i;
	
	for(i = 0; i < tam; i++) {
    	printf("%c ", *(v + i)); //imprimindo conteudo do apontado pelo ponteiro 
	}
}

void preencherVetorInt(int *v, int tam) {
	
	int i;
	
	for(i = 0; i < tam; i++) {
		printf("Digite um valor qualquer: ");
    	scanf("%d", v + i); //imprimindo conteudo do apontado pelo ponteiro 
	}
}

int main()
{
    /*int *valor1; // tipo ponteiro -> armazena endereco de memoria
    int valor2 = 50;
    char *letra1, letra2 = 'a';
    
    valor1 = &valor2;  // armazenando endereco de memmoria de valor2
    letra1 = &letra2;  // apontador para um tipo char armazenando o endereco de memoria de letra2
    
    printf("Valor da variavel valor2: %d\n", valor2);
    printf("Endereco da variavel valor2: %p\n", &valor2);
    printf("Conteudo da variavel valor1: %p\n", valor1);
    printf("Conteudo apontado pela variavel valor1: %d\n", *valor1);
    
    printf("\nValor da variavel letra2: %c\n", letra2);
    printf("Endereco da variavel letra2: %p\n", &letra2);
    printf("Conteudo da variavel letra1: %p\n", letra1);
    printf("Conteudo apontado pela variavel letra1: %c\n", *letra1);*/
    
    int vet[10] = {10,11,12,13,14,15,16,17,18,19}; // o vetor implicitamente eh um ponteiro
    char letras[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    
    preencherVetorInt(vet, 10);
    imprimirVetor(vet, 10);
    imprimirVetorLetras(letras, 10);
    
    
    return 0;
}
