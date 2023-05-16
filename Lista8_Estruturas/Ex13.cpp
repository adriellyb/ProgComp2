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

int main(void) {
	
	FRACAO f1, f2, soma, subt, prod, div;
	
	// lendo numerador e denominador de f1 e f2
	printf("Insira o numerador e denominador da fracao f1\n");
	scanf("%d %d", &f1.numerador, &f1.denominador);
	printf("Insira o numerador e denominador da fracao f2\n");
	scanf("%d %d", &f2.numerador, &f2.denominador);
	
	if(f1.denominador == 0 || f2.denominador == 0) {
		printf("\nCalculo nao pode ser feito, pois denominador eh igual a 0.\n");
	} else {
		// soma
		soma.denominador = MMC(f1.denominador, f2.denominador);
		soma.numerador = ((soma.denominador / f1.denominador) * f1.numerador) +
						((soma.denominador / f2.denominador) * f2.numerador);
		printf("\nSoma = %d/%d\n", soma.numerador, soma.denominador);
		
		// subtracao
		subt.denominador = MMC(f1.denominador, f2.denominador);
		subt.numerador = ((subt.denominador / f1.denominador) * f1.numerador) -
						((subt.denominador / f2.denominador) * f2.numerador);
		printf("Subtracao = %d/%d\n", subt.numerador, subt.denominador);
		
		// produto
		prod.numerador = f1.numerador * f2.numerador;
		prod.denominador = f1.denominador * f2.denominador;
		printf("Produto = %d/%d\n", prod.numerador, prod.denominador);
		
		// divisao
		div.numerador = f1.numerador * f2.denominador;
		div.denominador = f1.denominador * f2.numerador;
		printf("Divisao = %d/%d\n", div.numerador, div.denominador);
	}
	
	return 0;
}
