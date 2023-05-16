#include <stdio.h>
#include <stdlib.h>

typedef struct _JOGADOR {
	char time[40], esporte[40];
	int colocacao, idade;
} JOGADOR;

void imprimirVetor(JOGADOR *jogadores) {
	
	for(int i = 0; i < 2; i++) {
		printf("\nEsporte: %s", (jogadores + i)->esporte);
		printf("\nTime: %s", (jogadores + i)->time);
		printf("\nIdade: %d", (jogadores + i)->idade);
		printf("\nColocacao: %d\n", (jogadores + i)->colocacao);
	}
}

int main(void) {
	
	JOGADOR jogadores[2];
	
	for(int i = 0; i < 2; i++) {
		gets((jogadores + i)->esporte);
		gets((jogadores + i)->time);
		scanf("%d", &(jogadores + i)->idade);
		scanf("%d", &(jogadores + i)->colocacao);
		getchar();
	}
	
	imprimirVetor(jogadores);
	
	return 0;
}
