#include "construtor.c"

int showMenu() {
	int menu;

	printf("\n Digite uma opção do menu\n");
    printf("1 - Inserir\n");
    printf("2 - Buscar\n");
    printf("3 - Remover\n");
    printf("4 - Imprimir Pre-ordem \n");
    printf("5 - Imprimir Ordem-simetrica \n");
    printf("6 - Imprimir Pos-ordem \n");
    printf("7 - Imprimir Decrescente\n");
    printf("8 - Quantidade de nodos\n");
    printf("9 - Altura\n");
    printf("10 - Cheia \n");
    printf("11 - Completa \n");
    printf("12 - Quantidade de folhas\n");
    printf("13 - N-esimo elemento\n");
    printf("14 - Sequencia em nivel\n");
    scanf("%d", &menu);

    return menu;
}

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
    no *raiz = NULL;

    menu = showMenu();
    
    while(menu < 15){
		switch (menu){
			case 1:
			//printf("\n Digite o valor a ser inserido na arvore\n");
			//scanf("%d", &inserirNumero);
			//inserirNo(&raiz,inserirNumero);

			//Inserundo valores para testes
			/*inserirNo(&raiz,8);	
			inserirNo(&raiz,3);
			inserirNo(&raiz,1);
			inserirNo(&raiz,6);
			inserirNo(&raiz,4);
			inserirNo(&raiz,7);
			inserirNo(&raiz,10);
			inserirNo(&raiz,9);
			inserirNo(&raiz,11);
			*/

			construirDeArquivo(&raiz);

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
				printf("Informe um valor n para pesquisa do n-esimo elemento.\n");
				int n;
				scanf("%d", n);
				enesimoElemento(n, raiz);
				printf("O n-esimo elemento é: ");
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
	    menu = showMenu();

	}
    printf("\n Saindo do programa\n");
    return 0;
}