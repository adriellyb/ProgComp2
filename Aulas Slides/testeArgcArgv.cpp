#include <stdio.h>

int main(int argc, char *argv[]) {

    printf("\nMeu nome eh ");
    for(int i = 1; i < argc; i++) {
        printf("%c", *argv[i]);
    }

    printf("\n\n");

    return 0;
}

/*  Como executar codigo em C no cmd */
/*  1) Abrir o diretorio onde o arquivo esta armazenado no computador
    2) Executar o comando abaixo para compilar o arquivo .c/.cpp e gerar o .exe

        gcc -o teste testeArgcArgv.cpp

    3) Executar o .exe com o comando abaixo

        ./teste
*/