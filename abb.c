#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pilha.c"

typedef struct no{
    struct no *esq;
    struct no *dir;
    struct no *pai;
    int valor;
}no;

no *raiz = NULL;

int ABB_vazia(no *r){
    if(r == NULL) return 1;
    else return 0;
}

no* busca(no* raiz, int elemento) {
    if(raiz != NULL) {
        busca(raiz->esq, elemento);
        if (raiz->valor == elemento){
            return raiz;
        }
        busca(raiz->dir, elemento);
    }
}

void inserirNo(no **raiz,int elemento) {
    if(*raiz == NULL) {
        no *aux = (no *)malloc(sizeof(no));
        aux->valor = elemento;
        aux->dir = aux->esq = NULL;
        *raiz = aux;
        printf("%d foi inserido na ABB.\n",elemento);
        return;
    }
    if(elemento < (*raiz)->valor) {
        inserirNo(&(*raiz)->esq,elemento);
        return;
    }
    if(elemento > (*raiz)->valor) {
        inserirNo(&(*raiz)->dir,elemento);
        return;
    }
    printf("%d ja existe na ABB.\n",elemento);
}

no* DoisFilhos(no *root){
    if(root==NULL)
        return NULL;
    else if(root->esq == NULL)
        return root;
    else
        return DoisFilhos(root->esq);
}

void removerNo(no **raiz,int elemento) {
    if(*raiz == NULL){   
        printf("Numero nao existe na arvore!");
        return;
    }
    if(elemento < (*raiz)->valor){
        removerNo(&(*raiz)->esq,elemento);
    }
    else if(elemento > (*raiz)->valor){
        removerNo(&(*raiz)->dir,elemento);
    }
    else if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){
        no *aux= NULL;
        aux = DoisFilhos((*raiz)->dir);
        (*raiz)->valor = aux->valor;
        removerNo(&(*raiz)->dir,(*raiz)->valor);
    }
    else {
        no *aux = (*raiz);
        if((*raiz)->esq==NULL) {
            (*raiz) = (*raiz)->dir;
        }
        else {
            *raiz = (*raiz)->esq;
        }
        free(aux);
    }
}

void pesquisaOrdemSimetrica(no *raiz) {
    if(raiz == NULL)
        return;
    pesquisaOrdemSimetrica(raiz->esq);
    printf("%d \n",raiz->valor);
    pesquisaOrdemSimetrica(raiz->dir);
}

void pesquisaPosOrdem(no *raiz) {
    if(raiz == NULL)
        return;
    pesquisaPosOrdem(raiz->esq);
    pesquisaPosOrdem(raiz->dir);
    printf("%d\n",raiz->valor);
}

void pesquisaPreOrdem(no *raiz) {
    if(raiz == NULL)
        return;
    printf("%d\n",raiz->valor);
    pesquisaPreOrdem(raiz->esq);
    pesquisaPreOrdem(raiz->dir);
}

void pesquisaInvertida(no *raiz) {
    if(raiz == NULL)
        return;
    pesquisaInvertida(raiz->dir);
    printf("%d\n",raiz->valor);
    pesquisaInvertida(raiz->esq);
}

int nodo(no *raiz) {
    if(raiz==NULL) {
        return 0;
    }
    else {
        return  nodo(raiz->esq) + nodo(raiz->dir) +1;
    }
}

int contarFolhas(no *raiz){
    if(raiz == NULL)
        return 0;
    if(raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    return contarFolhas(raiz->esq) + contarFolhas(raiz->dir);
}

int altura(no raiz) {
    int alturaDir;
    int alturaEsq;

    alturaDir = 0;
    alturaEsq = 0;

    if(raiz.esq != NULL)
        alturaEsq = altura(*(raiz.esq));
    if(raiz.dir != NULL)
        alturaDir = altura(*(raiz.dir));

    return max(alturaEsq, alturaDir) + 1;
}

/* função auxiliar para saber quem é o maior*/
int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int ehCheia(){
    int alturaArvoreCheia;
    int nodoArvoreCheia;
    int resultado;
    //no *raiz = NULL;
    alturaArvoreCheia = altura(*raiz);

    //scanf("%d", &alturaArvoreCheia);
    resultado = (pow(2,alturaArvoreCheia))-1;   
    nodoArvoreCheia = nodo(raiz);
    if(resultado == nodoArvoreCheia){
        printf("Arvore é cheia \n");
    return 1;
    }
    else {
        printf("Arvore não é cheia \n");
    return 0;
  }
}   

// Verificar return para raiz NULL
// > Trocando temporariamente "return;" por "return -1;" 
int posicao(no *raiz, int tam, int n) {
    if(raiz == NULL) return -1;
    posicao(raiz->esq, tam, n);
    tam = tam + 1;
    if(n == raiz->valor) return tam;
    printf("%d \n", raiz->valor);
    if(n == raiz->valor)
    posicao(raiz->dir, tam, n);
}       

void toString(no* root, int level) {
    if(root == NULL) return;
    if(level == 1) printf("%d ", root->valor);
    else if (level > 1) {
    toString(root->esq, level-1);
    toString(root->dir, level-1);
    }
}

void ehCompleta(no raiz) {
    int alturaDir;
    int alturaEsq;
    alturaDir = 0;
    alturaEsq = 0;
    if(raiz.esq != NULL)
        alturaEsq = altura(*(raiz.esq));
    if(raiz.dir != NULL)
        alturaDir = altura(*(raiz.dir));
    if(alturaEsq - alturaDir < 2 && alturaEsq - alturaDir >= 0 || (alturaDir - alturaEsq < 2 && alturaDir - alturaEsq >= 0)){
        printf("A arvore é completa\n");
    }
    else {
        printf("A arvore não é completa\n");
    }
}

int enesimoElemento(int n, no* raiz) {
    //Cria uma lista com a quantidade de nos da arvore.
    int lista[nodo(raiz)];
    stack *p;
    int count = 0;
    int elemento;
    no *auxA = raiz;
    no *auxB;
    while((pilha_vazia(p) == 0) || auxA != NULL) {
        while(auxA != NULL) {
            push(p, auxA->valor);
            auxA = auxA->esq;
        }
        if(pilha_vazia(p) == 0) {
            elemento = pop(p); 
            lista[count] = elemento;
            count++;
            auxB = busca(auxA, elemento);
            auxA = auxB->dir;
        }
    }

    int enesimo = lista[n-1];
    printf("O %d-esimo e = %d\n", n, enesimo);
    return enesimo;
}


