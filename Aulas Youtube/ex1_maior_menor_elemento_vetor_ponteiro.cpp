#include <stdio.h>
#include <stdlib.h>

void maiorMenor(int *vet, int tam, int *menor, int *maior) {
	
	int i;
	
	*menor = *vet;
	*maior = *vet;
	
	for(i = 1; i < tam; i++) {
		if(*menor > *(vet + i)) {
			*menor = *(vet + i);
		}
		
		if(*maior < *(vet + i)) {
			*maior = *(vet + i);
		}
	}
}

int main() {
	int menor, maior, v[10] = {23,44,92,78,10,35,64,81,72,33};
	
	printf("Menor: %d\tMaior: %d\n", menor, maior);
	maiorMenor(v, 10, &menor, &maior);
	printf("Menor: %d\tMaior: %d\n", menor, maior);
	
	
	return 0;
}
