#include <stdio.h>
#include <math.h>

typedef struct _PONTO {
	float x, y;
} PONTO;

int main(void) {
	PONTO p1, p2;
	double dist;
	
	// lendo coordenadas dos pontos p1 2 p2
	printf("Entre com as coordenadas do ponto p1\n");
	scanf("%f %f", &p1.x, &p1.y);
	printf("Entre com as coordenadas do ponto p2\n");
	scanf("%f %f", &p2.x, &p2.y);
	
	// calculando distancia entre pontos
	dist = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
	
	// imprimindo distancia entre os pontos p1 e p2
	printf("Distancia entre os pontos p1 e p2: %lf\n", dist);
	
	return 0;
}
