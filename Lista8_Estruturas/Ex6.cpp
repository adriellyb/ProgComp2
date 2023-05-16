#include <stdio.h>

typedef struct _TEMPO {
	int hora, minuto, segundo;
} TEMPO;

int main(void) {
	
	TEMPO t1, t2, t3;
	int t1_total, t2_total, t3_total;
	
	// lendo tempos t1 e t2
	printf("Digite as horas, minutos e segundos do tempo t1\n");
	scanf("%d %d %d", &t1.hora, &t1.minuto, &t1.segundo);
	printf("Digite as horas, minutos e segundos do tempo t2\n");
	scanf("%d %d %d", &t2.hora, &t2.minuto, &t2.segundo);
	
	// somando tempo total em segundos
	t1_total = (t1.hora * 60 * 60) + (t1.minuto * 60) + t1.segundo;
	t2_total = (t2.hora * 60 * 60) + (t2.minuto * 60) + t2.segundo;
	
	// calculando em horas, minutos e seguntos o tempo t3
	t3_total = t1_total + t2_total;
	t3.hora = t3_total / 3600;
	t3.minuto = (t3_total % 3600) / 60;
	t3.segundo = (t3_total % 3600) % 60;
	
	// imprimindo tempo t3
	printf("\nTempo t3: %02d:%02d:%02d\n", t3.hora, t3.minuto, t3.segundo);	
	
	return 0;
}
