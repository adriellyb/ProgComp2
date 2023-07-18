#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE_MAX 400
#define LIN 10
#define COL 40

typedef struct _FILMES {
	char nome[40];
	int sala;
	int lugaresDisponiveis;
	char mapaSala[LIN][COL];
} FILMES;

typedef struct _INGRESSOS {
	int tipo; 				// 1 - normal, 2 - meia, 3 - itasil 
	float preco;
} INGRESSOS;

void registrarFilmes(FILMES listaFilmes[]) {
	
	int i, j, k;
	
	// registrando primeiro filme
	strcpy(listaFilmes[0].nome, "Velozes e Furiosos 137");
	listaFilmes[0].sala = 1;
	listaFilmes[0].lugaresDisponiveis = CAPACIDADE_MAX;
	
	// registrando segundo filme
	strcpy(listaFilmes[1].nome, "The Flash");
	listaFilmes[1].sala = 2;
	listaFilmes[1].lugaresDisponiveis = CAPACIDADE_MAX;
	
	// registrando terceiro filme
	strcpy(listaFilmes[2].nome, "Tranformers");
	listaFilmes[2].sala = 3;
	listaFilmes[2].lugaresDisponiveis = CAPACIDADE_MAX;
	
	// inicializando mapa das salas
	for(k = 0; k < 3; k++) {
		for(i = 0; i < LIN; i++) {
			for(j = 0; j < COL; j++) {
				listaFilmes[k].mapaSala[i][j] = '0';
			}
		}		
	}
	
}

int selecionarFilme(FILMES listaFilmes[]) {
	int numSala, i;
	
	for(i = 0; i < 3; i++) {
        printf("%d - %s (Lugares Disponiveis: %d)\n", i + 1, listaFilmes[i].nome, listaFilmes[i].lugaresDisponiveis);
    }
    printf("0 - Sair\n");
	printf("\n-> Selecione a sala para o filme que deseja ver: ");
	scanf("%d", &numSala);
	
	if(numSala == 0 || numSala == 1 || numSala == 2 || numSala == 3) {
		return numSala;
	}
	else {
		printf("\nEsta sala nao existe! Por favor, selecione novamente.\n\n");
		selecionarFilme(listaFilmes);
	}
}

int qtdIngressos(FILMES *filme) {
	
	int totalIngressos;
	printf("-> Quantidade total de ingressos desejados: ", filme->lugaresDisponiveis);
	scanf("%d", &totalIngressos);
	
	if (totalIngressos <= filme->lugaresDisponiveis && totalIngressos > 0) {
		printf("\nVoce selecionou %d ingesso(s)\n\n", totalIngressos);
		filme->lugaresDisponiveis = filme->lugaresDisponiveis - totalIngressos;
		
		return totalIngressos;
	} else {
		printf("\nQuantidade desejada indisponivel! Por favor, selecione novamente.\n\n");
		qtdIngressos(filme);
	}
}

int validarCarteiraEstudante(char numCarteira[]) {
	int numsInt[4], numsMult[4], fator = 2, soma_total = 0, DV;
	int i, j;
	
	// criando vetor inteiro com os 4 primeiros digitos	
	for(j = 0; j < 4; j++)
		numsInt[j] = numCarteira[j]-'0';
	
	for(i = 3; i >= 0; i--) {
		// multiplicando cada inteiro de tras pra frente com fator alternando
		numsMult[i] = numsInt[i] * fator;
		fator = fator == 2 ? 1 : 2;
		
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
	DV = soma_total % 10 == 0 ? 0 : 10 - (soma_total % 10);
	
	// verificando se DV eh iguail ao ultimo digito da carteira de estudante
	if(DV == numCarteira[4]-'0')
		return 1;
	else
		return 0;
}

int descontoIngressoMeia(INGRESSOS *listaIngressos, int totalIngressos) {
	int totalMeias, meiasValidas = 0, i, j = 0;
	char numCarteira[5];
	
	printf("-> Insira a quantidade de ingressos meia-entrada: ");
	scanf("%d", &totalMeias);
	
	if(totalMeias > 0 && totalMeias <= totalIngressos) {
		for(i = 0; i < totalMeias; i++) {
			printf("\n-> Insira o numero da carteira de estudante (Ingresso %d/%d): ", i+1, totalMeias);
			fflush(stdin);
			gets(numCarteira);

			if(numCarteira[0] == '0') {
				continue;
			}
			
			if(strlen(numCarteira) != 5){
				printf("\nCarteira de estudante deve ter apenas 5 digitos. Tente novamente.\n");
				i--;
			}
			else if(validarCarteiraEstudante(numCarteira)) {
				(listaIngressos + j)->preco = 10.00; // 50% de desconto
				(listaIngressos + j)->tipo = 2;
				meiasValidas++;		// contador de meias entradas validadas pela carteira de estudante
				j++;				// indice do vetor listaIngressos
			}
			else {
				printf("\nCarteira de estudante invalida! Tente novamente.\n");
				i--;
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
	int totalItasil, itasilValidos, codigoDoCliente, i, j = totalMeiasValidas, validador, k;  // i = indice dos ingressos itasil com codigo, j = indice do array de ingressos
	
	printf("\n-> Insira a quantidade de ingressos cliente Itasil: ");
	scanf("%d", &totalItasil);

	
	if(totalItasil > 0 && totalItasil <= totalIngressos-totalMeiasValidas) {

		int listaCodigosValidos[totalItasil];

		for(i = 0; i < totalItasil; i++) {
			printf("\n-> Insira o numero do codigo do cliente (Ingresso %d/%d): ", i+1, totalItasil);
			scanf("%d", &codigoDoCliente);

			if(codigoDoCliente == 0) {
				continue;
			}

			if(codigoDoCliente % 341 == 0 && codigoDoCliente % 001 == 0) {
				validador = 1;			// permite que um codigo utilizado n�o seja usado novamente
				for(k = 0; k < totalItasil; k++) {
					if(codigoDoCliente == listaCodigosValidos[k]) {
						printf("\nCodigo do cliente ja foi utilizado! Tente novamente.\n");
						validador = 0;
						i--;
						break;
					}
				}

				if(validador) {			// se validador = 0, nao sera permitido usar o codigo inserido pois o mesmo ja foi utilizado em outro ingresso
					listaCodigosValidos[i] = codigoDoCliente;
					(listaIngressos + j)->preco = 14.00; // 30% de desconto
					(listaIngressos + j)->tipo = 3;
					itasilValidos++;
					j++;				// indice do vetor listaIngressos
				}
			}
			else {
				printf("\nCodigo do cliente invalido! Tente novamente.\n");
				i--;
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
	
	return itasilValidos;
}

void exibirMapaDaSala(FILMES *filme) {
	
	int i, j, k;
	
	printf("\n\t\t\t-------------------- TELA -------------------\n\n   ");
	for(k = 0; k < COL; k++) {
		printf("%3d", k+1);
	}
	
	printf("\n\n");
	for(i = 0; i < LIN; i++) {
		printf("%3c", 'A'+i);
		for(j = 0; j < COL; j++) {
			printf("%3c", filme->mapaSala[i][j]);
		}
		printf("\n");
	}
}

void escolherPoltrona(FILMES *filme, int totalIngressos) {
	char poltrona;
	int  fileira, i;
	
	exibirMapaDaSala(filme);
	
	for(i = 0; i < totalIngressos; i++) {
		printf("\n-> Selecione a poltrona para o ingresso (%d/%d). As fileiras sao os numeros e as poltronas sao as letras", i+1, totalIngressos);
		printf("\n-> Escreva da seguinte forma fileira[ESPACO]poltrona: ");
		scanf("%d %c", &fileira, &poltrona);
		
		if(fileira < 0 || fileira > COL || (toupper(poltrona) < 'A' || toupper(poltrona) > 'J')) {
			printf("\nEssa poltrona nao existe! Tente novamente.\n\n");
			i--;
			continue;
		}
		
		if(filme->mapaSala[toupper(poltrona) - 'A'][fileira - 1] != 'X') {
			filme->mapaSala[toupper(poltrona) - 'A'][fileira - 1] = 'X';
		}
		else {
			printf("\nPoltrona ocupada! Por favor, selecione outra poltrona.\n\n");
			i--;
			fileira = 0;
           poltrona = '\0';
		}
		
		// exibindo mapa
		exibirMapaDaSala(filme);
	}
}

float totalAPagar(INGRESSOS *listaIngressos, int totalIngressos) {
	float valorTotal = 0;
	int i, j;
	
	for(i = 0; i < totalIngressos; i++) {
		if((listaIngressos + i)->tipo != 2 && (listaIngressos + i)->tipo != 3) {
			(listaIngressos + i)->preco = 20.00;
			(listaIngressos + i)->tipo = 1;
		}	
		valorTotal += (listaIngressos + i)->preco;
	}
	
	return valorTotal;
}

int main(void) {
	
	FILMES listaFilmes[3];
	registrarFilmes(listaFilmes);
	
	int numSala, totalIngressos, totalMeiasValidas, totalItasilValidos, i;
	float valorTotal;
	
	do {
		printf("###########  Bem-vindo a rede de cinemas Mariano Pinheiro  ###########\n\n");
		
		// selecionando o filme
		numSala = selecionarFilme(listaFilmes);
		
		if(numSala) {
			printf("\nVoce escolheu %s\n\n", listaFilmes[numSala-1].nome);
			
			// inserir lugares
			totalIngressos = qtdIngressos(&listaFilmes[numSala-1]);
			
			INGRESSOS listaIngressos[totalIngressos];
			
			// desconto meia entrada
			totalMeiasValidas = descontoIngressoMeia(listaIngressos, totalIngressos);

			// desconto itasil
			totalItasilValidos = descontoItasil(listaIngressos, totalIngressos, totalMeiasValidas);

			// selecionar poltronas sala
			escolherPoltrona(&listaFilmes[numSala-1], totalIngressos);
			
			// valor total a pagar
			valorTotal = totalAPagar(listaIngressos, totalIngressos);
			
			// resumo do pedido
			printf("\n--- Resumo do Pedido ---\n");
		    printf("Filme: %s (Sala %d)\n", listaFilmes[numSala-1].nome, listaFilmes[numSala-1].sala);
		    printf("Ingressos Inteira: %d\n", totalIngressos-totalMeiasValidas-totalItasilValidos);
		    printf("Ingressos Meia-entrada: %d\n", totalMeiasValidas);
		    printf("Ingressos Cliente Itasil: %d\n", totalItasilValidos);
		    printf("Valor total: R$%.2f\n", valorTotal);
		    printf("-----------------------\n\n");
			
			printf("Obrigado por escolher o Cinema Mariano Pinheiro. Agradecemos o seu pedido.\n\n\n");
		}
				
	} while(numSala != 0);
		
	return 0;
}
