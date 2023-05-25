#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _JOGADOR {
	int pontos;
	char nome[42];
	struct _JOGADOR *prox;
} JOGADOR;

void listar(JOGADOR *atual) {
    while(atual != NULL)    /* Enquanto nao chega no fim da lista */
    {
        printf("\n\nPontos: %d\tNome: %s \n", atual->pontos, atual->pontos);
        atual = atual->prox;     /* Faz noatual apontar para o proximo no */
    }
}

void inserirJogador(JOGADOR *head) {
	JOGADOR *atual, *novo;
	
	// inserindo elemento na lista
	char nome[42];
	int pontos;
	
	printf("Insira o nome do jogador:\n");
	fflush(stdin);
	fgets(nome, 41, stdin);
	printf("Insira os pontos do jogador:\n");
	scanf("%d", &pontos);
	
	if(head == NULL) {
		head = (JOGADOR*)malloc(sizeof(JOGADOR));
		if(!head) {
			printf("Sem memoria\n");
			exit(1);
		}
		strcpy(head->nome, nome);
		head->pontos = pontos;
		head->prox = NULL;
	}
	else {
		atual = head;
		novo = (JOGADOR*)malloc(sizeof(JOGADOR));
		if(!novo) {
			printf("Sem memoria\n");
			exit(1);
		}
		while(atual->prox != NULL) {
			atual = atual->prox;
		}
		strcpy(novo->nome, nome);
		novo->pontos = pontos;
		novo->prox = NULL;
		
		atual->prox = novo;
	}
}

int main(void) {
	JOGADOR *atual, *head = NULL;
	int i = 0;
	
	/* Desaloca a memoria alocada para os elementos da lista */
//    atual = head;
//    while(atual != NULL)
//    {
//        head = atual->prox;
//        free(atual);
//        atual = head;
//    }
	
	while (i < 3) {
        inserirJogador(head);
        i++;
    }
    
    listar(atual);
	
	return 0;
}








