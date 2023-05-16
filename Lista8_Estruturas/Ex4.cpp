#include <stdio.h>
#include <math.h>

typedef struct _PONTO {
	float x, y;
} PONTO;

typedef struct _CIRCUNFERENCIA {
	float raio;
	PONTO centro;
} CIRCUNFERENCIA;

int main(void) {
	CIRCUNFERENCIA c1;
	PONTO p1;
	double dist;
	
	// lendo coordenadas do ponto
	printf("Entre com as coordenadas do ponto p1\n");
	scanf("%f %f", &p1.x, &p1.y);
	
	// lendo raio do circulo
	printf("Entre com o raio do circulo c1\n");
	scanf("%f", &c1.raio);
	
	// lendo coordenadas do circulo
	printf("Entre com as coordenadas do centro do circulo c1\n");
	scanf("%f %f", &c1.centro.x, &c1.centro.y);
	
	// calculando distancia entre o ponto p1 e o centro da circunferencia c1
	dist = sqrt(pow((c1.centro.x - p1.x), 2) + pow((c1.centro.y - p1.y), 2));
	
	// verificando se ponto p1 esta contido na circunferencia c1
	if(dist <= c1.raio) {
		printf("\nO ponto p1 ESTA contido na circunferencia c1\n");
	}
	else {
		printf("\nO ponto p1 NAO ESTA contido na circunferencia c1\n");
	}
	
	return 0;
}
