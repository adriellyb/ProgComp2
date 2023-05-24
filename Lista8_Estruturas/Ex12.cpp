#include <stdio.h>
#include <stdlib.h>

// criando lista de jogadores
typedef struct _JOGADOR {
	int pontos;
	char nome[42];
	struct _JOGADOR *prox;  // próx. elemento da lista
} JOGADOR;

void inserir(JOGADOR *head);

int main(void) {
	JOGADOR *head = NULL;	// ponteiro que encabeça a lista
	JOGADOR *p;			// ponteiro que percorre a lista
	
	p = head;
	
	return 0;
}
