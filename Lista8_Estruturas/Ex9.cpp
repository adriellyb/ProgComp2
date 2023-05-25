#include <stdio.h>
#include <math.h>

typedef struct _PONTO {
	float x, y;
} PONTO;

typedef struct _CIRCUNFERENCIA {
	float raio;
	PONTO centro;
} CIRCUNFERENCIA;

void tangenteExterna(CIRCUNFERENCIA c1, CIRCUNFERENCIA c2) {
/* Distância entre centros das circunferências é igual a soma dos raios das mesmas */
	
	// calculando distancia entre o centro da circunferencia c1 e o centro da circunferencia c2
	float dist = sqrt(pow((c2.centro.x - c1.centro.x), 2) + pow((c2.centro.y - c1.centro.y), 2));
	
	// validando tangente externa
	if(dist == (c1.raio + c2.raio)) {
		printf("As circunfencias c1 e c2 sao tangentes entre si.\n");
	} else {
		printf("As circunfencias c1 e c2 nao sao tangentes entre si.\n");
	}
}

void secante(CIRCUNFERENCIA c1, CIRCUNFERENCIA c2) {
/* Distância entre os centros das circunferências deve ser menor que a soma das medidas de seus raios. */
	
	// calculando distancia entre o centro da circunferencia c1 e o centro da circunferencia c2
	float dist = sqrt(pow((c2.centro.x - c1.centro.x), 2) + pow((c2.centro.y - c1.centro.y), 2));
	
	// validando tangente externa
	if(dist < (c1.raio + c2.raio)) {
		printf("As circunfencias c1 e c2 sao secantes entre si.\n");
	} else {
		printf("As circunfencias c1 e c2 nao sao secantes entre si.\n");
	}
}

void internaOuExterna(CIRCUNFERENCIA c1, CIRCUNFERENCIA c2) {
/* Distância entre os centros das circunferências deve ser equivalente à diferença entre as medidas de seus raios. */
	
	// calculando distancia entre o centro da circunferencia c1 e o centro da circunferencia c2
	float dist = sqrt(pow((c2.centro.x - c1.centro.x), 2) + pow((c2.centro.y - c1.centro.y), 2));
	
	// validando tangente externa
	if(dist == abs(c1.raio - c2.raio)) {
		if(c1.raio > c2.raio) {
			printf("c1 eh a circunfencia externa e c2 eh a circunfencia interna.\n");
		}
		else {
			printf("c2 eh a circunfencia externa e c1 eh a circunfencia interna.\n");
		}
	} else {
		printf("As circunfencias c1 e c2 nao sao internas ou externas entre si.\n");
	}
}

int main(void) {
	CIRCUNFERENCIA c1, c2;
	
	// lendo coordenadas do centro e raio circulo c1
	printf("Entre com as coordenadas do centro do circulo c1\n");
	scanf("%f %f", &c1.centro.x, &c1.centro.y);
	printf("Entre com o raio do circulo c1\n");
	scanf("%f", &c1.raio);
		
	// lendo coordenadas do centro e raio circulo c2
	printf("Entre com as coordenadas do centro do circulo c2\n");
	scanf("%f %f", &c2.centro.x, &c2.centro.y);
	printf("Entre com o raio do circulo c2\n");
	scanf("%f", &c2.raio);
	
	//
	tangenteExterna(c1, c2);
	secante(c1, c2);
	internaOuExterna(c1, c2);
	
	return 0;
}
