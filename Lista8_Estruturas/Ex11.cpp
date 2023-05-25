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

void ordenandoPorPontos(JOGADOR *jogadores) {
	
	int i, j;
	JOGADOR temp;
	
	// ordenando valores do menor para o maior
	for(i = 0; i < 5; i++) {
        for(j = i; j < 5; j++) {
        	
        	if(jogadores[i].pontos < jogadores[j].pontos) {
        		temp = jogadores[i];
        		jogadores[i] = jogadores[j];
        		jogadores[j] = temp;
			}
        }
    }
    
    // imprimindo vetor jogadores
	imprimirJogadores(jogadores);
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
	ordenandoPorPontos(jogadores);
	
	return 0;
}
