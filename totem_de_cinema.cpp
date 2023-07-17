#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACIDADE_MAX 400
#define PRECO_NORMAL 20.00
#define LIN 40
#define COL 10

typedef struct _FILMES {
	char nome[40];
	int sala;
	int total_lugares = CAPACIDADE_MAX;
	char mapaSala[LIN][COL];
} FILMES;

typedef struct _INGRESSOS {
	int tipo; 				// 1 - normal, 2 - meia, 3 - itasil 
	float preco = PRECO_NORMAL;
	char poltrona[4];
} INGRESSOS;

FILMES listaFilmes[3];
void registrarFilmes() {
	
	// registrando primeiro filme
	strcpy(listaFilmes[0].nome, "Velozes e Furiosos 137");
	listaFilmes[0].sala = 1;
	
	// registrando segundo filme
	strcpy(listaFilmes[1].nome, "The Flash");
	listaFilmes[1].sala = 2;
	
	// registrando terceiro filme
	strcpy(listaFilmes[2].nome, "Tranformers");
	listaFilmes[2].sala = 3;
	
	// inicializando mapa das salas
	for(int k = 0; k < 3; k++) {
		for(int i = 0; i < LIN; i++) {
			for(int j = 0; j < COL; j++) {
				listaFilmes[k].mapaSala[i][j] = '0';
			}
		}		
	}
	
}

int selecionarFilme() {
	int numSala;
	
	printf("Estes sao os filmes em cartaz:\nSala 1: Velozes e Furiosos 137\nSala 2: The Flash\nSala 3: Tranformers\n\n");
	printf("-> Qual filme deseja assistir? Digite a sala que corresponde ao filme desejado: ");
	
	scanf("%d", &numSala);
	
	if(numSala == 1 || numSala == 2 || numSala == 3) {
		return numSala;
	}
	else if(numSala == 0) {
		return numSala;
	}
	else {
		printf("\nEsta sala nao existe! Tente novamente.\n\n");
		selecionarFilme();
	}
}

int qtdIngressos(FILMES *filme) {
	
	int totalIngressos;
	printf("-> Temos %d ingressos. Quantos ingressos deseja comprar? ", filme->total_lugares);
	scanf("%d", &totalIngressos);
	
	if (totalIngressos <= filme->total_lugares && totalIngressos > 0) {
		printf("\nVoce selecionou %d ingesso(s)\n\n", totalIngressos);
		filme->total_lugares = filme->total_lugares-totalIngressos;
		return totalIngressos;
	} else {
		printf("\nQuantidade desejada indisponivel! Tente novamente.\n\n");
		qtdIngressos(filme);
	}
}

int validarCarteiraEstudante(char numCarteira[]) {
	int numsInt[4], numsMult[4], fator = 2, soma_total = 0, DV;
	
	// criando vetor inteiro com os 4 primeiros digitos	
	for(int i = 0; i < 4; i++)
		numsInt[i] = numCarteira[i]-'0';
	
	for(int i = 3; i >= 0; i--) {
		// multiplicando cada inteiro de tras pra frente com fator alternando
		numsMult[i] = numsInt[i] * fator;
		fator == 2 ? fator = 1 : fator = 2;
		
		// verificando se o numero multiplicado eh maior que 9
		if(numsMult[i] > 9) {
			// sendo maior que 9, ocorre o somatorio de seus algarismos
			int soma_2digitos = 0, numero = numsMult[i];
			while( numero != 0) {
				soma_2digitos += numero % 10;
				numero = numero / 10;	
			}
			numsMult[i] = soma_2digitos;
		}
		// somando numeros multiplicados
		soma_total += numsMult[i];
	}
	
	//	verificando se o resto da divisao entre a soma e 10 eh igual a 0. Caso seja, o digito verificador (DV) vale 0, senao DV = 10 - resto da divisao 
	soma_total % 10 == 0 ? DV = 0 : DV = 10 - (soma_total % 10);
	
	// verificando se DV eh iguail ao ultimo digito da carteira de estudante
	if(DV == numCarteira[4]-'0')
		return 1;
	else
		return 0;
}

int descontoIngressoMeia(INGRESSOS *listaIngressos, int totalIngressos) {
	int totalMeias, meiasValidas = 0, i = 0, j = 0;
	char numCarteira[5];
	
	printf("-> Quantos ingressos sao meia entrada? ");
	scanf("%d", &totalMeias);
	
	if(totalMeias > 0 && totalMeias <= totalIngressos) {
		while(i < totalMeias) {
			printf("\n-> Insira o numero da carteira de estudante (Ingresso %d/%d): ", i+1, totalMeias);
			fflush(stdin);
			gets(numCarteira);

			if(numCarteira[0] == '0') {
				i++;
				continue;
			}

			if(validarCarteiraEstudante(numCarteira)) {
				(listaIngressos + j)->preco = 10.00; // 20.00 * 0.5 (50% de desconto)
				(listaIngressos + j)->tipo = 2;
				meiasValidas++;
				j++;
				i++;
			}
			else {
				printf("\nCarteira de estudante invalida! Tente novamente.\n");
			}
		}
	}
	else if(totalMeias == 0) {
		return 0;
	}
	else {
		printf("\nQuantidade invalida!\n\n");
		descontoIngressoMeia(listaIngressos, totalIngressos);
	}

	return meiasValidas;
}

int descontoItasil(INGRESSOS *listaIngressos, int totalIngressos, int totalMeiasValidas) {
	int totalItasil, codigoDoCliente, i = 0, j = totalMeiasValidas, validador = 1;  // i = indice dos ingressos itasil com codigo, j = indice do array de ingressos
	
	printf("\n-> Quantos ingressos sao cliente Itasil? ");
	scanf("%d", &totalItasil);

	
	if(totalItasil > 0 && totalItasil <= totalIngressos-totalMeiasValidas) {

		int listaCodigosValidos[totalItasil];

		while(i < totalItasil) {
			printf("\n-> Insira o numero do codigo do cliente (Ingresso %d/%d): ", i+1, totalItasil);
			scanf("%d", &codigoDoCliente);

			if(codigoDoCliente == 0) {
				i++;
				continue;
			}

			if(codigoDoCliente % 341 == 0) {
				for(int k = 0; k < totalItasil; k++) {
					if(codigoDoCliente == listaCodigosValidos[k]) {
						printf("\nCodigo do cliente ja foi utilizado! Tente novamente.\n");
						validador = 0;
						break;
					}
				}

				if(validador) {
					listaCodigosValidos[i] = codigoDoCliente;
					(listaIngressos + j)->preco = 14.00; // 20.00 - (20.00 * 0.3) (30% de desconto)
					(listaIngressos + j)->tipo = 3;
					j++;
					i++;
				}
			}
			else {
				printf("\nCodigo do cliente invalido! Tente novamente.\n");
			}
		}
	}
	else if(totalItasil == 0) {
		return 0;
	}
	else {
		printf("\nQuantidade invalida!\n\n");
		descontoItasil(listaIngressos, totalIngressos, totalMeiasValidas);
	}
}

void exibirMapaDaSala(FILMES *filme) {
	
	printf("\n\tSala do filme %s\n\n   ", filme->nome);
	for(int k = 0; k < 10; k++) {
		printf("%3c", 'A'+k);
	}
	
	printf("\n");
	for(int i = 0; i < LIN; i++) {
		printf("%3d", i+1);
		for(int j = 0; j < COL; j++) {
			printf("%3c", filme->mapaSala[i][j]);
		}
		printf("\n");
	}
}

void escolherPoltrona(FILMES *filme, INGRESSOS *listaIngressos, int totalIngressos) {
	
	char poltrona[4], *letra, *num;
	int  linha, coluna, poltronasValidas = 0;
	
	exibirMapaDaSala(filme);
	
	do {
		printf("\n-> Selecione a poltrona para o ingresso (%d/%d). As fileiras sao os numeros e as poltronas sao as letras", poltronasValidas+1, totalIngressos);
		printf("\n-> Escreva da seguinte forma fileira[ESPACO]poltrona: ");
		
		// lendo localizacao da poltrona
		fflush(stdin);
		scanf("%[^\n]s", poltrona);
		
		// localizando linha
		num = strtok(poltrona, " ");
		linha = atoi(num)-1;
		
		//localizando coluna
		letra = strtok(NULL, " ");
		if(*letra >= 'a' && *letra <= 'z') *letra -= 32;
		coluna = (*letra) - 65;

		if(linha < 0 || linha > LIN-1 || coluna < 0 || coluna > COL-1) {
			printf("\nEssa poltrona nao existe! Tente novamente.\n\n");
		}
		if(filme->mapaSala[linha][coluna] != 'X') {
			filme->mapaSala[linha][coluna] = 'X';
			strcpy((listaIngressos + poltronasValidas)->poltrona, poltrona);
			poltronasValidas++;
		}
		else {
			printf("\nPoltrona ja selecionada! Tente novamente.\n\n");
		}
		
		// exibindo mapa
		exibirMapaDaSala(filme);
		
	} while(poltronasValidas < totalIngressos);
}

void totalAPagar(INGRESSOS *listaIngressos, int totalIngressos) {
	float valorFinal = 0;
	
	for(int i = 0; i < totalIngressos; i++) {
		valorFinal += (listaIngressos + i)->preco;
	}
	
	printf("\n\nValor total a pagar dos %d ingressos:\tR$ %.2f\n\n", totalIngressos, valorFinal);
}

int main(void) {
	
	registrarFilmes();
	int numSala, totalIngressos, totalMeiasValidas, totalItasilValidos;
	FILMES filmeSelecionado;
	
	do {
		printf("###########  Bem-vindo a rede de cinemas Mariano Pinheiro  ###########\n\n");
		
		// selecionando o filme
		numSala = selecionarFilme();
		filmeSelecionado = listaFilmes[numSala-1];
		
		if(numSala) {
			printf("\nVoce escolheu %s\n\n", filmeSelecionado.nome);
			
			// inserir lugares
			totalIngressos = qtdIngressos(&filmeSelecionado);
			
			INGRESSOS listaIngressos[totalIngressos];
			
			// desconto meia entrada
			totalMeiasValidas = descontoIngressoMeia(listaIngressos, totalIngressos);

			// desconto itasil
			descontoItasil(listaIngressos, totalIngressos, totalMeiasValidas);

			// selecionar poltronas sala
			escolherPoltrona(&filmeSelecionado, listaIngressos, totalIngressos);
			
			// valor total a pagar
			totalAPagar(listaIngressos, totalIngressos);
			
			printf("Obrigado por escolher o Cinema Mariano Pinheiro. Agradecemos o seu pedido.\n\n\n");
		}
				
	} while(numSala != 0);
		
	return 0;
}
