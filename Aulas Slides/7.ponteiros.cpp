/* 7. Ponteiros */
#include <stdio.h>
#include <stdlib.h>

void atribuicoes() {
	int vetor[] = { 10, 20, 30, 40, 50 } ;
	int *p1, *p2;
	int i = 100;
	
	p1 = &vetor[2]; // esta passando para o ponteiro p1 o endereco de memoria do vetor na posicao 2
	printf("%d\n", *p1); // * -> esta imprimindo o valor da variavel localizada no endereco apontado pelo ponteiro.
	
	p2 = &i;  // endereco ponteiro: 0x24, conteudo ponteiro: 0x0C (endereco da variavel i)
	printf ("%d\n", *p2); // imprimindo conteudo de 0x0C (conteudo de i) = 100
	
	p2 = p1 ; // conteudo ponteiro p2 = conteudo ponteiro p1 = endereco de vetor[2]
	printf("%d\n", *p2); // imprimindo conteudo do endereco de vetor[2] = 30
}

void increm_decrem() {
	int vetor[] = { 10, 20, 30, 40, 50 } ;
	int *p1;
	
	p1 = &vetor[2];
	
	/* p1++ -> passe a apontar para o proximo numero inteiro */
	p1++;					// endereco de vetor[2+1]
	printf("\n%d\n", *p1);	// 40
	p1 = p1 + 1;			// endereco de vetor[3+1]
	printf("%d\n", *p1);	// 50
}

void operacoes() {
	/* A diferenca entre ponteiros fornece quantos elementos do tipo do ponteiro existem entre os dois ponteiros.*/
	float vetor[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	float *p1, *p2;
	
	p1 = &vetor[2]; /* endereco do terceiro elemento */
	p2 = vetor; 	/* endereco do primeiro elemento */
	printf("\nDiferenca entre ponteiros %d\n\n", p1 - p2 );
}

void pont_vetores() {
	float v[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 };
	int i;
	float *pv;	// ponteiro variável -> seus valores podem ser alterados
	
	for(i = 0 ; i < 7 ; i++) {
		printf("%.1f ", v[i]);		// imprime os valores do vetor
	}
	
	printf ("\n");
	
	for(i = 0 ; i < 7 ; i++) {
		printf("%.1f ", *(v+i));	// imprime os valores do vetor
	}
	
	printf ("\n");
	
	for (i = 0, pv = v; i < 7; i++, pv++) { // pv assume valor inicial do vetor e incrementa +1 a cada loop
		printf("%.1f ", *pv);		// imprime os valores do vetor
	}
}

int aloc_dinamica() {
	/*
	void *malloc(size_t size) -> Reserva size bytes na memoria para ALGUM ITEM de um programa.
	O valor armazenado no espaco eh indefinido.
	
	void *calloc(size_t num, size_t size) -> Reserva espaco na memoria para UM VETOR DE N ITENS do programa.
	Cada item tem tamanho size.
	
	void free(void *pont) -> O espaco apontado por pont eh devolvido ao sistema para uso -> DESALOCACAO.
	
	void realloc(void *pont, size_t size) -> A funcao ALTERA O TAMANHO do objeto na memoria apontado por pont para o tamanho especificado por size.
	*/
	
	float *v; 
	int i, tam;

	printf("\n\nQual o tamanho do vetor?");
	scanf("%d", &tam);
	
	v = (float *)calloc(tam, sizeof(float));
	
	if(!v) {
		return 1;
	}
	
	for (i = 0; i < tam; i++) {
		printf("Elemento %d?", i);
		scanf("%f", v+i);
		printf("Li valor %f\n", *(v+i));
	}
	free(v);
	
	return 0;
}

#define LIN 3
#define COL 4
int matrizes() {
	/*
	A expressao matriz+(i*COL+j) calcula a posicao do elemento matriz[i][j] a partir do primeiro elemento da matriz que esta
	no endereco inicial matriz.
	*/
	int * matriz ;
	int i, j;
	
	matriz = (int *)malloc(LIN*COL*sizeof(int));
	
	if (!matriz) {
		printf("\n\nErro.\n");
		return 1;
	}
	
	printf ("\n\n");
	
	for(i = 0; i < LIN ; i ++) {
		for (j = 0; j < COL ; j ++) {
			printf ("Elemento %d %d = ", i, j);
			scanf ("%d", matriz+(i*COL+j));
		}
	}
	
	return 0;
}


int main(void) {
	
	/* Atribuicoes com ponteiros */
	atribuicoes();

	/* Incrementando e decrementando ponteiros */
	increm_decrem();
	
	/* Operacoes aritmeticas */
	operacoes();
	
	/* Ponteiros e vetores */
	pont_vetores();
	
	/* Alocacao dinamica */
//	aloc_dinamica();
	
	/* Matrizes e ponteiros */
	matrizes();
	
	return 0;
}
