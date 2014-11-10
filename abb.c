#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int busca(no* a, int c){
    if(ABB_vazia(a)){
        printf("Elemento %d nao consta na arvore.\n",c);
        return 0;
    }
    /* árvore vazia: não encontrou */
    else {
        printf("Elemento %d consta na arvore.\n",c);
        return a->valor == c || busca(a->esq,c) || busca(a->dir,c);
    }
}

void inserirNo(no **raiz,int elemento) {
    if(*raiz == NULL) {
        no *aux = (no *)malloc(sizeof(no));
        aux->valor = elemento;
        aux->dir = aux->esq = NULL;
        *raiz = aux;
        printf("Elemento %d foi inserido com sucesso.\n",elemento);
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
    printf("Elemento %d ja existe na arvore.\n",elemento);
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
int posicao(no *raiz, int tam, int n) {
    if(raiz == NULL) return;
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
    int count;
    int enesimoValor;

    for (count = 0; count <= n-1; count++) {
        if(raiz == NULL) break;
        pesquisaOrdemSimetrica(raiz->esq);
        enesimoValor = raiz->valor;
        pesquisaOrdemSimetrica(raiz->dir);
    }
    return enesimoValor;
}