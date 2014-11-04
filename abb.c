#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct no{
    struct no *esq;
    struct no *dir;
    int valor;
}no;


    no *raiz = NULL;

int ABB_vazia(no *r){
    if(r == NULL)
	return 1;
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


void inserirNo(no **raiz,int elemento)
{
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

no *DoisFilhos(no *root){
       if(root==NULL)
           return NULL;
       else if(root->esq == NULL)
               return root;
       else
           return DoisFilhos(root->esq);
}

void removerNo(no **raiz,int elemento)
{
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

void pesquisaOrdemSimetrica(no *raiz)
{
    if(raiz == NULL)
       return;
    pesquisaOrdemSimetrica(raiz->esq);
    printf("%d\n",raiz->valor);
    pesquisaOrdemSimetrica(raiz->dir);
}

void pesquisaPosOrdem(no *raiz)
{
    if(raiz == NULL)
       return;
    pesquisaPosOrdem(raiz->esq);
    pesquisaPosOrdem(raiz->dir);
    printf("%d\n",raiz->valor);
}

void pesquisaPreOrdem(no *raiz)
{
    if(raiz == NULL)
       return;
    printf("%d\n",raiz->valor);
    pesquisaPreOrdem(raiz->esq);
    pesquisaPreOrdem(raiz->dir);
}

int nodo(no *raiz){
if(raiz==NULL)

return 0;
else {
return  nodo(raiz->esq) + nodo(raiz->dir) +1;
}
}

int altura2(no raiz)
{
 int alturaDir;
 int alturaEsq;

 alturaDir = 0;
 alturaEsq = 0;

 if(raiz.esq != NULL)
   alturaEsq = altura2(*(raiz.esq));
 if(raiz.dir != NULL)
   alturaDir = altura2(*(raiz.dir));

if((alturaEsq - alturaDir < 2 && alturaEsq - alturaDir >= 0) || (alturaDir- alturaEsq < 2 && alturaDir- alturaEsq  >= 0)){
printf("Arvore completa \n");
return 1;
}
else {
printf("Arvore não é completa \n");
 return 0;
}
}

int ehCompleta(no raiz)
{
 int alturaDir;
 int alturaEsq;

 alturaDir = 0;
 alturaEsq = 0;

 if(raiz.esq != NULL)
   alturaEsq = altura2(*(raiz.esq));
 if(raiz.dir != NULL)
   alturaDir = altura2(*(raiz.dir));

if((alturaEsq - alturaDir < 2 && alturaEsq - alturaDir >= 0) || (alturaDir- alturaEsq < 2 && alturaDir- alturaEsq  >= 0)){
printf("Arvore completa \n");
return 1;
}
else {
printf("Arvore não é completa \n");
 return 0;
}
}



/*

int compara(int um, int outro)
{
 if(um - outro == 1 || outro - um == 1)
//printf("Arvore completa \n");
   return 0;
//printf("Arvore não é completa \n");
 return 1;
}

*/


int altura(no raiz)
{
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
int max(int um, int outro)
{
 if(um > outro)
   return um;
 return outro;
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
	printf("Arvore cheia \n");
	return 1;
	}else {
	printf("Arvore não é cheia \n");
	return 0;	
	}
}	


int main()
{
    //int *retorno;
    int menu;
    int inserirNumero;
    int buscaNumero;
    int resultBusca;
    int removerNumero;
    int posicaoElemento;
    int nodoArvore;
    int alturaArvore;
    int teste;


    printf("\n Digite uma opção do menu\n");
    printf("\n 1 - para inserir dado na arvore\n");
    printf("\n 2 - para buscar elemento na arvore \n");
    printf("\n 3 - para remover elemento na arvore \n");
    printf("\n 4 - para imprimir os elementos da arvore em pre-ordem \n");
    printf("\n 5 - para imprimir os elementos da arvore em ordem-simetrica \n");
    printf("\n 6 - para imprimir os elementos da arvore em pos-ordem \n");
    printf("\n 7 - para saber a quantidade de nodos na arvore\n");
    printf("\n 8 - para saber a altura da arvore\n");
    printf("\n 9 - para saber se a arvore é cheia \n");
    printf("\n 10 - para saber se a arvore é completa \n");
    scanf("%d", &menu);
    while(menu < 11){
	switch (menu){
	case 1:
	printf("\n Digite o valor a ser inserido na arvore\n");
	scanf("%d", &inserirNumero);
	inserirNo(&raiz,inserirNumero);
	break;
	case 2:
	//char buscar_numero;
        printf("\n Digite o valor a ser buscado na arvore\n");
	scanf("%d", &buscaNumero);
	//buscar_numero = getchar();	
	resultBusca = busca(raiz,buscaNumero);
	//printf("Elemento %d nao não consta na arvore.\n",resultBusca);
	break;
	case 3:
        printf("\n Digite o valor a ser removido da arvore\n");
	//remover_numero = getchar();	
	scanf("%d", &removerNumero);
	removerNo(&raiz,removerNumero);
	break;
	case 4:
	printf("\n Imprimindo em pre-ordem\n");
	pesquisaPreOrdem(raiz);
	break;
	case 5:
	printf("\n Imprimindo em ordem simetrica\n");
	pesquisaOrdemSimetrica(raiz);
	break;
	case 6:
	printf("\n Imprimindo em pos-ordem\n");
	pesquisaPosOrdem(raiz);
	break;
	case 7:
	nodoArvore = nodo(raiz);
        printf("arvore tem %d nodos .\n",nodoArvore);
	break;
	case 8:
	alturaArvore = altura(*raiz);
        printf("A arvore tem altura igual a: %d .\n",alturaArvore);
	break;
	case 9:
	ehCheia();
	break;
	case 10:
	ehCompleta(*raiz);
	break;
	default:
	break;
	}
	

    printf("\n 1 - para inserir dado na arvore\n");
    printf("\n 2 - para buscar elemento na arvore \n");
    printf("\n 3 - para remover elemento na arvore \n");
    printf("\n 4 - para imprimir os elementos da arvore em pre-ordem \n");
    printf("\n 5 - para imprimir os elementos da arvore em ordem-simetrica \n");
    printf("\n 6 - para imprimir os elementos da arvore em pos-ordem \n");
    printf("\n 7 - para saber a quantidade de nodos na arvore\n");
    printf("\n 8 - para saber a altura da arvore\n");
    printf("\n 9 - para saber se a arvore é cheia \n");
    printf("\n 10 - para saber se a arvore é completa \n");
    scanf("%d", &menu);
}
    printf("\n Saindo do programa\n");
    return 0;
}

