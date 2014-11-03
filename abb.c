#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no *esq;
    struct no *dir;
    int valor;
}no;


no* busca(no* r, int k) {
    if (r == NULL)
	return NULL;
    else if(r->valor > k) 
        return busca(r->esq, k);
    else if(r->valor < k)    
	return busca(r->dir, k);
    else  return r;
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


int altura(no *raiz){
if(raiz==NULL)
return 0;
else {
return  altura(raiz->esq)+ altura(raiz->dir) +1;
}
}

int main()
{
    //int *retorno;
    int menu;
    int inserirNumero;
    int buscaNumero;
    int removerNumero;
    no *raiz = NULL;
    printf("\n Digite uma opção do menu\n");
    printf("\n 1 - para inserir dado na arvore\n");
    printf("\n 2 - para buscar elemento na arvore \n");
    printf("\n 3 - para remover elemento na arvore \n");
    printf("\n 4 - para imprimir os elementos da arvore em pre-ordem \n");
    printf("\n 5 - para imprimir os elementos da arvore em ordem-simetrica \n");
    printf("\n 6 - para imprimir os elementos da arvore em pos-ordem \n");
    //menu = getchar();
    scanf("%d", &menu);
    while(menu < 7){
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
	busca(raiz,buscaNumero);
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
	default:
	break;
	}
	

    printf("\n 1 - para inserir dado na arvore\n");
    printf("\n 2 - para buscar elemento na arvore \n");
    printf("\n 3 - para remover elemento na arvore \n");
    printf("\n 4 - para imprimir os elementos da arvore em pre-ordem \n");
    printf("\n 5 - para imprimir os elementos da arvore em ordem-simetrica \n");
    printf("\n 6 - para imprimir os elementos da arvore em pos-ordem \n");
    scanf("%d", &menu);
}
    printf("\n Saindo do programa\n");
    return 0;
}
