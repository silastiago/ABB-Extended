#include <stdio.h>
#include "abb.c"

// CONSTROI UMA ARVORE BINARIA DE BUSCA ATRAVEZ DE UM ARQUIVO DE ENTRADA
void construirDeArquivo(no **raiz) {
	char url[]="arquivodeentrada.txt";
	int elemento;
	FILE *arq;
	
	arq = fopen(url, "r");
	if(arq == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	    while((fscanf(arq, "%d ", &elemento))!= EOF) {
	    	inserirNo(raiz, elemento);
	    }

	fclose(arq);
}