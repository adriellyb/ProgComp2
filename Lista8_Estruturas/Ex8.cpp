#include <stdio.h>

typedef struct _TEMPO {
	int hora, minuto, segundo;
} TEMPO;

int main(void) {
	
	TEMPO t[5];
	int t_total[5], i, j;
	
	// lendo tempos t1 e t2
	for(i = 0; i < 5; i++) {
		printf("Digite as horas, minutos e segundos do tempo t[%d]\n", i);
		scanf("%d %d %d", &t[i].hora, &t[i].minuto, &t[i].segundo);
	}
	
	// somando tempo total em segundos
	for(i = 0; i < 5; i++) {
		t_total[i] = (t[i].hora * 60 * 60) + (t[i].minuto * 60) + t[i].segundo;
	}
	
	// ordenando valores do menor para o maior
	for(i = 0; i < 5; i++) {
        for(j = i; j < 5; j++) {
            if(t_total[i] > t_total[j]) {
                int temp = t_total[i];
                t_total[i] = t_total[j];
                t_total[j] = temp;
            }
        }
    }
	
	// convertendo para horas, minutos e segundos
	for(i = 0; i < 5; i++) {
		t[i].hora = t_total[i] / 3600;
		t[i].minuto = (t_total[i] % 3600) / 60;
		t[i].segundo = (t_total[i] % 3600) % 60;
	
		// imprimindo tempo t3
		printf("\nt[%d]: %02d:%02d:%02d\n", i, t[i].hora, t[i].minuto, t[i].segundo);	
	}
	
	return 0;
}
