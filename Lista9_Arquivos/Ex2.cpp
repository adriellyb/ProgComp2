#include <stdio.h>
#include <string.h>

char inverteString(char vet[]) {
    int aux, fim, tam = strlen(vet);
	
    for(int i = 0, fim = tam - 1; i < tam/2; i++, fim--){
        aux = vet[i];
        vet[i] = vet[fim];
        vet[fim] = aux;
    }
    printf("%s", vet);
    return *vet;
}

void inverteArquivo(char *entrada, char *saida) {
	
	FILE *entra, *sai;
	char linha[50];
	
	entra = fopen(entrada, "r");
	sai = fopen(saida, "w+");
	
	if(entra == NULL) {
		printf("Arquivo nao pode ser aberto");
	}

	fflush(entra);
	while(!feof(entra)) {
		fgets(linha, 50, entra);
		inverteString(linha);
		fputs(linha, sai);
	}
	
	fclose(sai);
	fclose(entra);
}

int main(void) {
	
	inverteArquivo("Ex2entrada.txt", "Ex2saida.txt");
	
	return 0;
}
