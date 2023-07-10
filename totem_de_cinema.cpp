#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _FILMES {
	char nome[40];
	int sala;
	int total_lugares = 400;
} FILMES;

typedef struct _INGRESSOS {
	float preco;
} INGRESSOS;

FILMES listaFilmes[3];
void registrarFilmes() {
	
	// registrando primeiro filme
	strcpy(listaFilmes[0].nome, "Velozes e Furiosos 137");
	listaFilmes[0].sala = 1;
	listaFilmes[0].total_lugares = 400;
	
	// registrando segundo filme
	strcpy(listaFilmes[1].nome, "The Flash");
	listaFilmes[1].sala = 2;
	listaFilmes[1].total_lugares = 400;
	
	// registrando terceiro filme
	strcpy(listaFilmes[2].nome, "Tranformers");
	listaFilmes[2].sala = 3;
	listaFilmes[2].total_lugares = 400;
	
//	return *listaFilmes;
}

int selecionarFilme() {
	int num_sala;
	
	printf("Estes sao os filmes em cartaz:\nSala 1: Velozes e Furiosos 137\nSala 2: The Flash\nSala 3: Tranformers\n\n");
	printf("Qual filme deseja assistir? Digite a sala que corresponde ao filme desejado: ");
	
	scanf("%d", &num_sala);
	
	if(num_sala == 1 || num_sala == 2 || num_sala == 3) {
		return num_sala;
	}
	else if(num_sala == 0) {
		return num_sala;
	}
	else {
		printf("\nEsta sala nao existe! Tente novamente.\n\n");
		selecionarFilme();
	}
}

int qtdIngressos(FILMES *filme) {
	
	int qtd_ingressos;
	printf("Temos %d ingressos. Quantos ingressos deseja comprar? ", filme->total_lugares);
	scanf("%d", &qtd_ingressos);
	
	if (qtd_ingressos <= filme->total_lugares && qtd_ingressos > 0) {
		printf("\n\nVoce selecionou %d ingesso(s)\n\n", qtd_ingressos);
		filme->total_lugares = filme->total_lugares-qtd_ingressos;
		return qtd_ingressos;
	} else {
		printf("\n\nQuantidade desejada nao esta disponivel! Tente novamente.\n\n");
		qtdIngressos(filme);
	}
}

int descontoIngressos(int qtd_ingressos) {
	int meia, itasil;
	
	printf("Quantos ingressos são meia entrada?");
	scanf("%d", &meia);
	
	if(meia > 0 && meia <= qtd_ingressos) {
		for(int i = 0; i < meia; i++) {
			// adicionar codigo
		}
	}
}

int main(void) {
	
	registrarFilmes();
	int num_sala, qtd_ingressos;
	
	do {
		printf("Bem-vindo a rede de cinemas Cinesystem\n\n");
		
		// selecionando o filme
		num_sala = selecionarFilme();
		
		if(num_sala) {
			printf("\n\nVoce escolheu %s\n\n", listaFilmes[num_sala-1].nome);
			
			// inserir lugares
			qtd_ingressos = qtdIngressos(&listaFilmes[num_sala-1]);
//			printf("\n%d\n", listaFilmes[num_sala-1].total_lugares);
		}
				
	} while(num_sala != 0);
	
	
	
	return 0;
}
