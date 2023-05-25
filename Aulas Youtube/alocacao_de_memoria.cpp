#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void malloc_calloc() {
//	char *x;
	
	// memory alloc (malloc) -> 1 param -> qtd de bytes que precisa alocar
//	x = (int*)malloc(sizeof(int));

	// alloc (calloc) -> 2 params -> qtd de elementos, qtd de memoria
//	x = (char*)calloc(1, sizeof(char));
//	
//	if(x) {
//		printf("Endereco de memoria: %p", x);
//	}
//	else {
//		printf("Erro ao alocar memoria!\n");
//	}

}

int main() {
	
	int i, tam, *vet;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);
	srand(time(NULL)); // gerando num aleatorios
	
	vet = (int*)malloc(tam * sizeof(int));
	
	if(vet) {
		printf("Memoria alocada com sucesso!\n");
		for(i = 0; i < tam; i++) {
			*(vet + i) = rand() % 100;
		}
		
		for(i = 0; i < tam; i++) {
			*(vet + i) = rand() % 100;
			printf("v[%d] => Valor: %d\tEndereco: %p\n", i, *(vet + i), (vet + i));	
		}
	}
	else {
		printf("Erro ao alocar memoria!\n");
	}
	
	return 0;
}
