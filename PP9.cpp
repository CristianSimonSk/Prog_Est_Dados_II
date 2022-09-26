// Cristian Augusto Simon

/* Problema 9
Considere uma �rvore bin�ria de busca que armazena valores inteiros. Nesta estrutura, pode ocorrer repeti��es
de um mesmo valor. Assim, os valores associados aos n�s da sub-�rvore � esquerda s�o menores que o valor
associado � raiz e os valores dos n�s da sub-�rvore � direita s�o maiores ou iguais. O tipo que representa um
n� da arvore � dado por:
 struct arv {
 int info;
 struct arv* esq;
 struct arv* dir;
 } ;
 typedef struct arv Arv;
a) Implemente a implanta��o de uma �rvore bin�ria de busca.
b) Escreva uma fun��o que retome o n�mero de ocorr�ncias de um dado valor x na �rvore. A fun��o deve tirar
proveito da ordena��o da �rvore e obedecer ao seguinte prot�tipo:
 int ocorrenciasx (Arv* a, int x);
c) Escreva uma fun��o que imprima os valores associados �s folhas da �rvore em ordem n�o crescente (isto
�, do maior para o menor, podendo haver repeti��es). A fun��o deve obedecer ao seguinte prot�tipo:
 int imprime_folhas (Arv* a);
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arv {
	char info;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv;

int raiz; 

Arv* init (void)
{
	return NULL;
}

void imprime (Arv* a)
{
	if (a != NULL) {
		imprime(a->esq);
		printf("%d\n",a->info);
		imprime(a->dir);
	}
}

Arv* busca (Arv* r, int v)
{
	if (r == NULL) return NULL;
	else if (r->info > v) return busca (r->esq, v);
	else if (r->info < v) return busca (r->dir, v);
	else return r;
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


Arv* retira (Arv* r, int v)
{
	if (r == NULL)
		return NULL;
	else if (r->info > v)
		r->esq = retira(r->esq, v);
	else if (r->info < v)
		r->dir = retira(r->dir, v);
	else { /* achou o elemento */
		if (r->esq == NULL && r->dir == NULL) { /* elemento sem filhos */
			free (r);
			r = NULL;
		}		
		else if (r->esq == NULL) { /* s� tem filho � direita */
			Arv* t = r;
			r = r->dir;
			free (t);
		}
		else if (r->dir == NULL) { /* s� tem filho � esquerda */
			Arv* t = r;
			r = r->esq;
			free (t);
		}
		else { /* tem os dois filhos */
			Arv* pai = r;
			Arv* f = r->esq;
			while (f->dir != NULL) {
				pai = f;
				f = f->dir;
			}
			r->info = f->info; /* troca as informa��es */
			f->info = v;
			r->esq = retira(r->esq,v);
		}	
	}
	return r;
}

int vazia(Arv* a)
{
	return a==NULL;
}

void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == raiz)
			printf("<");
		printf("%d", a->info); 
		printf("<");
		imprime_alt(a->esq); 
		printf(">");
		printf("<");
		imprime_alt(a->dir); 
		printf(">");
		if (a->info == 6)
			printf(">");
	}
}	

int ocorrenciasx (Arv* r, int v, int i)
{
	if (r == NULL) return i;
	
	else if(r->info == v){
		i++;
		retira(r, r->info);
		return ocorrenciasx (r->dir, v, i);
	}
	else if (r->info > v) {
		retira(r, r->info);
	return ocorrenciasx (r->esq, v, i);
	}
	else if (r->info < v) {
		retira(r, r->info);
	return ocorrenciasx (r->dir, v, i);
	}
	else return 0;
}

int imprime_folhas (Arv* a){
	
}

main() {
	int i = 0;
	Arv* arv = init();
	arv = insere(arv, 5);
	arv = insere(arv, 8);
	arv = insere(arv, 10);
	arv = insere(arv, 10);
	arv = insere(arv, 2);
	arv = insere(arv, 4);
	arv = insere(arv, 10);
	arv = insere(arv, 10);
	arv = insere(arv, 10);
	arv = insere(arv, 10);
	raiz = 6; imprime (arv);
	puts("");
	imprime_alt (arv);
	Arv* aux = arv;
	printf("\nO numero 10 aparece %d vezes.\n",ocorrenciasx(aux, 10, i));
	
}



