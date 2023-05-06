/* 3. Operadores e Expressoes */
#include <stdio.h>

int main(void) {
	
	int i = 5;
	
	/* Menos un�rio => muda o sinal de uma expressao */
	printf("%d\n", -i);	 // (-1) * 5 = -5
	
	/* Incremento*/
	printf("%d\n", ++i); // 5 + 1 = 6
	
	/* Decremento*/
	printf("%d\n", --i); // 6 - 1 = 5
	
	/* Operador && => O resultado da express�o � verdadeiro se e somente se todas as vari�veis forem iguais a verdadeiro.*/
	int k = 3 , j = -5;
	float z = 3.0;
	int resultado;
	
	resultado = (10>5) && (k<j) && (z!=0); // 0 pois k>0
	printf ("O resultado vale %d.\n", resultado);
	
	/* Operador || => Para que o resultado da express�o seja verdade basta que uma das vari�veis seja verdade.*/
	float x = 3.0;
	int n = 55, l=0;
	
	resultado = (l!=0) || (x==0) || (n<100);  // 1
	printf ("O resultado vale %d.\n", resultado);
	
	/* Operador ! => Este operador � un�rio e quando aplicado � uma vari�vel ele troca seu valor. */
	int dia = 25, ano = 1959;

	resultado = !((dia < 30) && (ano > 1950));
	printf ("O resultado vale %d.\n" ,resultado); // 0 pois !1
	
	/* Deslocamento => Um deslocamento para a direita � equivalente a uma divis�o por 2. Deslocamento para a esquerda � equivalente a uma
	multiplica��o por 2. Assim a = a * 2; e a = a � 1; s�o equivalentes.  */
	unsigned int c = 7;
	int d = -7;
	
	c = c<<1; 
	printf("%3d = %08X\n ", c, c);
	c = c>>1; 
	printf("%3d = %08X\n ", c, c) ;
	d = d<<1; 
	printf("%3d = %08X\n ", d, d) ;
	d = d>>1; 
	printf("%3d = %08X\n ", d, d) ;
	
	/* Operador por v�rgula => A express�o come�a a ser avaliada da esquerda para a direita.
	Exp1 --------> ExpN */
	int ex = (x = 5, x += 2, x * 10);
	printf("ex = %d\n", ex); // 70
	
	/* Operador sizeof() => O operador sizeof() � um operador un�rio que retorna o tamanho em >>bytes<< da 
	express�o ou tipo fornecido entre par�nteses. */
	#define DIM 10
	i = 0;
	float f = 3.0;
	char ch = 'a';
	int v[DIM];
	
	printf("Tamanho int %d\n", sizeof i);
	printf("Tamanho float %d\n", sizeof f);
	printf("Tamanho double %d\n", sizeof(double));
	printf("Tamanho char %d\n", sizeof ch);
	printf("Tam do vetor de %d inteiros %d\n", DIM, sizeof(v));
	
	
	
	
	
	
	
	
	
	return 0;
}
