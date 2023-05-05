#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int A = 100, *B, **C /* Ponteiro para ponteiro por isso os dois asteriscos (**) */, ***D;
	
	B = &A;
	C = &B;
	D = &C;
	
	printf("Endereco de A: %p\t\tConteudo de A: %d\n", &A, A);
	printf("Endereco de B: %p\t\tConteudo de B: %p\n", &B, B);
	printf("Conteudo apontado por B: %d\n", *B);
	printf("Endereco de C: %p\t\tConteudo de C: %p\n", &C, C);
	printf("Conteudo apontado por C: %d\n", **C);
	return 0;
}
