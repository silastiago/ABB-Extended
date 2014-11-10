#include "abb.c"

int main() {

    int i = 0;
    int level;
    int menu;
    int inserirNumero;
    int buscaNumero;
    int resultBusca;
    int removerNumero;
    int nodoArvore;
    int alturaArvore;
    int qtdFolhas;
    int lugar;
    int localizacao;
    no *root = NULL;

    printf("\n Digite uma opção do menu\n");
    printf("\n 1 - para inserir dado na arvore\n");
    printf("\n 2 - para buscar elemento na arvore \n");
    printf("\n 3 - para remover elemento na arvore \n");
    printf("\n 4 - para imprimir os elementos da arvore em pre-ordem \n");
    printf("\n 5 - para imprimir os elementos da arvore em ordem-simetrica \n");
    printf("\n 6 - para imprimir os elementos da arvore em pos-ordem \n");
    printf("\n 7 - para imprimir os elementos da arvore em ordem decrescente\n");
    printf("\n 8 - para saber a quantidade de nodos na arvore\n");
    printf("\n 9 - para saber a altura da arvore \n");
    printf("\n 10 - para saber se a arvore é cheia \n");
    printf("\n 11 - para saber se a arvore é completa \n");
    printf("\n 12 - para saber a quantidade de folhas da arvore\n");
    printf("\n 13 - para saber o enesimoElemento numa determinada posicao na arvore\n");
    printf("\n 14 - para saber a sequencia dos elementos em nivel\n");
    scanf("%d", &menu);
    
    while(menu < 15){
		switch (menu){
			case 1:
			//printf("\n Digite o valor a ser inserido na arvore\n");
			//scanf("%d", &inserirNumero);
			//inserirNo(&raiz,inserirNumero);

			//Inserundo valores para testes
			inserirNo(&raiz,8);	
			inserirNo(&raiz,3);
			inserirNo(&raiz,1);
			inserirNo(&raiz,6);
			inserirNo(&raiz,4);
			inserirNo(&raiz,7);
			inserirNo(&raiz,10);
			inserirNo(&raiz,9);
			inserirNo(&raiz,11);
			break;

			case 2:
			//char buscar_numero;
		        printf("\n Digite o valor a ser buscado na arvore\n");
				scanf("%d", &buscaNumero);	
				resultBusca = busca(raiz,buscaNumero);
			//printf("Elemento %d nao não consta na arvore.\n",resultBusca);
			break;
			case 3:
		        printf("\n Digite o valor a ser removido da arvore\n");
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
				printf("\n Imprimindo em pos-ordem\n");
				pesquisaInvertida(raiz);
			break;
			case 8:
				nodoArvore = nodo(raiz);
		        printf("arvore tem %d nodos.\n",nodoArvore);
			break;
			case 9:
				alturaArvore = altura(*raiz);
		        printf("A arvore tem altura igual a: %d .\n",alturaArvore);
			break;
			case 10:
				ehCheia();
			break;
			case 11:
				ehCompleta(*raiz);
			break;
			case 12:
				qtdFolhas = contarFolhas(raiz);
				printf("A arvore tem %d folhas.\n",qtdFolhas);
			break;
			case 13:
				printf("Digite o valor a ser buscado.\n");
				scanf("%d", &lugar); 
				localizacao = posicao(raiz, 1, lugar);
				printf("Achou é igual a: %d",localizacao);
			break;
			case 14:
				printf("Os elementos em nivel são: ");
				while(i <= altura(*raiz)){
					i++;
					toString(raiz, i);
				}
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
	    printf("\n 7 - para imprimir os elementos da arvore em ordem decrescente\n");
	    printf("\n 8 - para saber a quantidade de nodos na arvore\n");
	    printf("\n 9 - para saber a altura da arvore \n");
	    printf("\n 10 - para saber se a arvore é cheia \n");
	    printf("\n 11 - para saber se a arvore é completa \n");
	    printf("\n 12 - para saber a quantidade de folhas da arvore\n");
	    printf("\n 13 - para saber o enesimoElemento numa determinada posicao na arvore\n");
	    printf("\n 14 - para saber a sequencia dos elementos em nivel\n");
	    scanf("%d", &menu);
	}
    printf("\n Saindo do programa\n");
    return 0;
}