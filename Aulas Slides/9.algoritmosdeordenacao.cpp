#include <stdio.h>
#define TAM 5

void InsertionSort(int A[], int N) {

	int i, j, P, Tmp, cont = 0;
	
	for (P = 1; P < N; P++) {
		Tmp = A[P];
		for (j = P; j > 0 && A[j-1] > Tmp; j--)
			A[j] = A[j-1];
		A[j] = Tmp;
		cont++;
	}
	printf ("\nInsertion Sort\n");
	for (i = 0; i < N; i++)
		printf ("%d ", A[i]);
	
	printf ("\n\nTotal de loops: %d\n", cont);
}

void BubbleSort(int vetor[], int N) {
	
	int i, j, temp, cont = 0;
		
	for (i = 0; i < N; i++) {
		for (j = 0; j < N-1-i; j++) {
			if (vetor[j] > vetor[j+1]) {
				temp = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = temp;
			}
			cont++;
		}
	}
	printf ("\nBubble Sort\n");
	for (i = 0; i < N; i++)
		printf ("%d ", vetor[i]);
	
	printf ("\n\nTotal de loops: %d\n", cont);
}

int main (void) {
	int N, i;
	scanf("%d", &N);
	
	int vetor[N];
	
	for (i = 0; i < N; i ++)
		scanf ("%d", &vetor[i]);
	
	BubbleSort(vetor, N);
	InsertionSort(vetor, N);

	return 0;
}
