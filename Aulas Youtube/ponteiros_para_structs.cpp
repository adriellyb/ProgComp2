#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int dia, mes, ano;
} Data;

void imprimirData(Data *x) {
	
	printf("%d/%d/%d\n", x->dia, x->mes, x->ano); // para ponteiros em structs utilizados -> para acessar as variáveis
}

int main () {
	
	Data data;
	Data *p;
	
	p = &data;
	
	printf("data: %p\t p: %p\n", &data, p);
	
	data.dia = 11;
	data.mes = 1;
	data.ano = 1995;
	
	imprimirData(p);
	
	printf("%d/%d/%d\n", data.dia, data.mes, data.ano); // para structs utilizamos . para acessar suas variaveis
	
	return 0;
}
