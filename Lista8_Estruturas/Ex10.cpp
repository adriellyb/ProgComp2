#include <stdio.h>
#include <stdlib.h>

typedef struct _JOGADOR {
	int pontos;
	char nome[42];
} JOGADOR;

void imprimirJogadores(JOGADOR *jogadores) {
	
	int i;
	
	for(i = 0; i < 5; i++) {
		printf("Jogador %d => Nome: %s\tPontos: %d\n", i, (jogadores + i)->nome, (jogadores + i)->pontos);
	}
}

int main(void) {
	
	JOGADOR jogadores[5];
	int i;
	
	// lendo vetor jogadores
	for(i = 0; i < 5; i++) {
		fgets((jogadores + i)->nome, 41, stdin);
		scanf("%d", &(jogadores + i)->pontos);
		getchar();
	}
	
	// imprimindo vetor jogadores
	imprimirJogadores(jogadores);
	
	return 0;
}

//Luiz
//180
//Marcos
//55
//Julio
//125
//Pedro
//200
//Junior
//70
