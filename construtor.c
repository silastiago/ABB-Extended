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

// EXECUTA COMANDOS DO ARQUIVO DE COMANDOS
void executarComandos(no *p_raiz, no raiz) {
	char url[]="arquivodecomandos.txt";
	FILE *arq;
	arq = fopen(url, "r");

	char comando[30];
	int valor;

	while ((fscanf(arq, "%s", &comando)) != EOF) {
		if (comando == "IMPRIMA") {
			pesquisaOrdemSimetrica(p_raiz);
		}
		if (comando == "MEDIANA") {
			mediana(p_raiz);
		}
		if (comando == "CHEIA") {
			ehCheia();
		}
		if (comando == "COMPLETA") {
			ehCompleta(raiz);
		}
		if (comando == "TOSTRING") {
			toStringALL(p_raiz)
		}

	}
}








