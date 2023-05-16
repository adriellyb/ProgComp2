#include <stdio.h>

typedef struct _TEMPO {
	int hora, minuto, segundo;
} TEMPO;

comparaTempo(TEMPO t1, TEMPO t2) {
	
	int t1_total, t2_total, valor;
	
	// somando tempo total em segundos
	t1_total = (t1.hora * 60 * 60) + (t1.minuto * 60) + t1.segundo;
	t2_total = (t2.hora * 60 * 60) + (t2.minuto * 60) + t2.segundo;
	
	// atribuindo e retornando valor
	if(t1_total > t2_total) {
		valor = 1;
	} else if(t1_total == t2_total){
		valor = 0;
	} else {
		valor = -1;
	}
	
	return valor;
}

int main(void) {
	
	TEMPO t1, t2;
	
	// lendo tempos t1 e t2
	printf("Digite as horas, minutos e segundos do tempo t1\n");
	scanf("%d %d %d", &t1.hora, &t1.minuto, &t1.segundo);
	printf("Digite as horas, minutos e segundos do tempo t2\n");
	scanf("%d %d %d", &t2.hora, &t2.minuto, &t2.segundo);
	
	printf("Valor retornado: %d\n", comparaTempo(t1, t2));
	
	return 0;
}
