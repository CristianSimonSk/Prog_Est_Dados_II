//Cristian Augusto Simon


//Questão 1 

// Usei apenas como base o seu código abp_iterativa.c
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define MAX 4

struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};
typedef struct arv Arv;

int raiz; 

int vazia(Arv* a)
{
	return a==NULL;
}
//A árvore é representada pelo ponteiro para o nó raiz. A árvore vazia é inicializada
//atribuindo-se NULL a variável que representa a árvore. Uma função simples de
//inicialização é mostrada abaixo:
Arv* init (void)
{
	return NULL;
}

Arv* insere (Arv* a, int v)
{
	if (a==NULL) {
		a = (Arv*)malloc(sizeof(Arv));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else if (v < a->info)
		a->esq = insere(a->esq,v);
	else /* v < a->info */
		a->dir = insere(a->dir,v);
	return a;
}

void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == raiz)
			printf("<");
		printf("%d", a->info); /* mostra raiz */
		printf("<");
		imprime_alt(a->esq); /* mostra sae */
		printf(">");
		printf("<");
		imprime_alt(a->dir); /* mostra sad */
		printf(">");
		if (a->info == 6)
			printf(">");
	}
}

void imprimeRDE (Arv* a)
{
	if (a != NULL) {
		printf("%d  ",a->info);
		imprimeRDE(a->dir);
		imprimeRDE(a->esq);
	}
}

struct arv1 {
	Arv* end_a;
};
typedef struct arv1 Arv1;

int empilha (Arv1* pilha, Arv* a, int topo) {
	//printf("Empilhando %d\n",a->info);
	pilha[++topo].end_a = a; 
	return topo;
}

int contaNodos (Arv* a, int* conta) {
	if (a != NULL) {
		contaNodos(a->esq, conta); 
		*conta+=1; //printf("%d %d; ",a->info, *conta); 
		contaNodos(a->dir, conta); 
	}
	return *conta;
}

Arv* desempilha (Arv1* pilha, int topo) {
	return pilha[topo].end_a;
}

void imprimeRDE_iterativa (Arv* a) {

 	int conta = 0;
 	Arv1* pilha = (Arv1*) malloc(contaNodos(a, &conta)*sizeof(Arv1));
 	int topo = 0; 
	int visitados = 0;	
	while(visitados < conta) {
		while (a != NULL) {
			topo = empilha (pilha, a, topo);
			printf("%d  ",a->info); visitados++;
			if(a->dir == NULL) break;
			a = a->dir;
		}
		//puts("fdp"); 
		a = desempilha (pilha, topo--); 
		while(a->esq == NULL) a = desempilha (pilha, topo--);
		a = a->esq;
	}
}



void main() {
setlocale (LC_ALL,"portuguese");
Arv* arv = init();
arv = insere(arv, 6);
arv = insere(arv, 8);
arv = insere(arv, 2);
arv = insere(arv, 1);
arv = insere(arv, 4);
arv = insere(arv, 3);
arv = insere(arv, 20);
arv = insere(arv, 10);
arv = insere(arv, 15);
raiz = 6;
puts("");
puts("\nArvore original: \n");
imprime_alt (arv); puts("\n");
puts("\nvoid imprimeRDE (Arv* a) recursiva: \n");
imprimeRDE (arv);
puts("\n\nvoid imprimeRDE (Arv* a) iterativa: \n");
imprimeRDE_iterativa (arv);
}
