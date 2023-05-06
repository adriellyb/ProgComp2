/* 4. Controle */
#include <stdio.h>

int main(void) {
	
	/* switch => facilita a escrita de trechos de programa em que a selecao deve ser feita entre vaarias alternativas.
	!! SÓ PODE TESTAR IGUALDADE !! */
	float num1, num2, res;
	char op;
	
	printf("Por favor, entre com os operandos.\n");
	scanf("%f %f", &num1, &num2);
	getchar();
	
	printf("Qual a operacao \n");
	op = getchar();
	printf("A operacao eh %c\n", op);
	
	switch(op) {
		case '+':
			res = num1 + num2;
			break;
		case '-':
			res = num1 - num2;
			break;
		case '*':
			res = num1 * num2;
			break;
		case '/':
			if(num2 == 0.0) {
				printf("Divisao por zero.\n");
				return 1;
			}
			else {
				res = num1 / num2;
				break;
			}
		default:
			printf("Operacao invalida!\n");
			return 2;		
	} /* fim do switch */
	
	printf("O resultado da %c vale %f.\n", op, res);
	
	/* do-while 
	 
		do {
			bloco_de_comandos
		} while(expressao)
	
	*/
	int i = 1;
	do {
		printf("Numero %d\n", i);
		i++;
	} while(i <= 10);
	
	return 0;
}
