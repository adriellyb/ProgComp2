#include <stdio.h>
#include <stdlib.h>

typedef struct _FRACAO {
	int numerador, denominador;
} FRACAO;

int MMC(int n1, int n2) {
	
	int a, resto, mmc;
	
	for(a = 1; a > 0; a++) {
		resto = (n1 * a) % n2;
		if(resto == 0) break;
	}
	mmc = n1 * a;
	
	return mmc;
}

FRACAO soma(FRACAO a, FRACAO b) {
	
	FRACAO soma;
	
	soma.denominador = MMC(a.denominador, b.denominador);
	soma.numerador = ((soma.denominador / a.denominador) * a.numerador) +
					((soma.denominador / b.denominador) * b.numerador);
					
	return soma;
}

FRACAO subtracao(FRACAO a, FRACAO b) {
	
	FRACAO subt;
	
	subt.denominador = MMC(a.denominador, b.denominador);
	subt.numerador = ((subt.denominador / a.denominador) * a.numerador) -
					((subt.denominador / b.denominador) * b.numerador);
	
	return subt;
}

FRACAO multiplicacao(FRACAO a, FRACAO b) {
	FRACAO prod;
	
	prod.numerador = a.numerador * b.numerador;
	prod.denominador = a.denominador * b.denominador;
		
	return prod;
}

FRACAO divisao(FRACAO a, FRACAO b) {
	FRACAO div;
	
	div.numerador = a.numerador * b.denominador;
	div.denominador = a.denominador * b.numerador;
	
	return div;
}

int main(void) {
	
	FRACAO f1, f2;
	
	// lendo numerador e denominador de f1 e f2
	printf("Insira o numerador e denominador da fracao f1\n");
	scanf("%d %d", &f1.numerador, &f1.denominador);
	printf("Insira o numerador e denominador da fracao f2\n");
	scanf("%d %d", &f2.numerador, &f2.denominador);
	
	if(f1.denominador == 0 || f2.denominador == 0) {
		printf("\nCalculo nao pode ser feito, pois denominador eh igual a 0.\n");
	} else {
		// soma
		printf("\nSoma = %d/%d\n", soma(f1, f2).numerador, soma(f1, f2).denominador);
		
		// subtracao
		printf("Subtracao = %d/%d\n", subtracao(f1, f2).numerador, subtracao(f1, f2).denominador);
		
		// produto
		printf("Produto = %d/%d\n", multiplicacao(f1, f2).numerador, multiplicacao(f1, f2).denominador);
		
		// divisao
		printf("Divisao = %d/%d\n", divisao(f1, f2).numerador, divisao(f1, f2).denominador);
	}
	
	return 0;
}
