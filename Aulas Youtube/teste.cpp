#include <stdio.h>
#include <stdlib.h>

typedef struct _JOGADOR {
	int pontos;
//	char nome[42];
} JOGADOR;

int main(void) {
	JOGADOR jogadores[5];
	int p = 100;
	
	for(int i = 0; i < 5; i++) {
		jogadores[i].pontos = p;
		p += 100;
	}
	
	printf("Jogador [%d] => Pontos: %d\n", 0, jogadores[0].pontos);
	
	JOGADOR temp;
	*temp = *jogadores;
	*jogadores = *(jogadores+2);
	*(jogadores+2) = *temp;
	
	printf("Jogador [%d] => Pontos: %d\n", 0, jogadores[0].pontos);
	
	return 0;
	
}
