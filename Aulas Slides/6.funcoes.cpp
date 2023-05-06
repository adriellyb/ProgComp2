/* 6. Funcoes */
#include <stdio.h>
#include <stdlib.h> //atoi

// passagem por valor 1
float imc(float alt, float peso) {
	
	float imc = peso / (alt * alt);
	
	return imc;
}
// passagem por valor 2
void classificacao(float imc) {
	if(imc < 17) {
		printf("Muito abaixo do peso\n");
	}
	else if(imc >= 17 && imc <18.5) {
		printf("Abaixo do peso\n");
	}
	else if(imc >= 18.5 && imc < 25) {
		printf("Peso normal\n");
	}
	else if(imc >= 25 && imc < 30) {
		printf("Acima do peso\n");
	}
	else if(imc >= 30) {
		printf("Obesidade\n");
	}
}

// recursividade => isto eh uma funcao pode chamar a si mesmo.
float elevar(float x, int n) {
	if(n <= 1) {
		return x;
	}
	else {
		return x * elevar(x, n-1);
	}
}

int main(void) {
	
	float alt, peso, x;
	int n;
	
	// imc
	printf("Entre com a altura (m) e o peso (kg):\n");
	scanf("%f %f", &alt, &peso);
	
	printf("\nSeu IMC atualmente eh %.1f\n", imc(alt, peso));
	
	classificacao(imc(alt, peso));
	
	printf("---------------------------------------\n");
	
	// potenciacao
	printf("Entre com a base e a potencia:\n");
	scanf("%f %d", &x, &n);
	
	printf("\n%.1f elevado a %d eh igual a %.1f\n", x, n, elevar(x, n));
	
	printf("---------------------------------------\n");
	
	return 0;
}

int main(int argc, char **argv) {
	
	// **argv ou *argv[] - vetor de cadeias de caracteres
	printf("Ola, eu sou %s\n", argv[0]); // diretorio do arquivo
	
	/* argc - eh uma variavel inteira que indica quantos argumentos foram fornecidos para a funcao.
	vale sempre pelo menos 1, porque o nome do programa eh sempre o primeiro argumento fornecido ao programa.
	*/
	printf("Ola, eu sou %d\n", argc);
	
	// atoi - Ascii To Int
	int numero = atoi(argv[0]);
	printf("Ola, eu sou %d\n", numero);
	
	return 0;
}
