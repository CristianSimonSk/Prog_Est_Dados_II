/*
Prova da Semana 5 - Programação e Estruturas de Dados II
Problema:
Encontre o comprimento de uma lista encadeada de forma recursiva.
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
struct lista {
		int info;
		struct lista* prox;
	};

typedef struct lista Lista;

Lista* inicializa (void)
{
	return NULL;
}

Lista* insere(Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo->info = i;
	novo->prox = l;
	return novo;
}

int comprimento (Lista* l, int cont)
{
	
	if (l == NULL) {
        return 0;
    }
    else {
        return 1 + comprimento(l->prox, cont);			
	}
}
main(){
	int cont=0;
    Lista *l;
    l = inicializa(); 
    l = insere(l, 23); 
    l = insere(l, 28); 
    l = insere(l, 30);
    l = insere(l, 56); 
    l = insere(l, 56); 
    l = insere(l, 56); 

    comprimento(l, cont);
    printf("A quantidade de itens na lista eh %d.",cont);

	getchar();
}
