//Cristian Augusto Simon

#include <stdlib.h>
#include <stdio.h>

typedef struct no {
  int v;
  int bal;   /* hdir - hesq */
  struct no *esq, *dir;
} No;

int altura(No* t) {
  if (t == NULL)
    return 0;
  int hesq = altura(t->esq);  
  int hdir = altura(t->dir);
  return hesq > hdir ? hesq + 1 : hdir + 1;
}

No* cria(int v, No* esq, No* dir) {
  No* n = (No*) malloc (sizeof(No));
  n->v = v;
  n->bal = altura(dir) - altura(esq);
  n->esq = esq;
  n->dir = dir;
  return n;
}

/* Versão ineficiente! Você sabe implementar outra? */
/* Não verifica se é uma árvore de busca. */
int verifica_AVL(No* t) {
  if (t == NULL)
    return 1;
  return abs(altura(t->dir) - altura(t->esq)) <= 1;
}

void escreve(No* r) {
  if (r != NULL) {
    escreve(r->esq);
    printf("%d(%d)", r->v, r->bal);
    escreve(r->dir);
  }
}

void escreve_verifica(No* t) { 
  printf("R%d\n",t->v); // C�digo incluido por mim
  if (!verifica_AVL(t)) 
    printf("Não é AVL!\n");
  escreve(t); 
  printf("\n");
}

void LL(No** r) {
  No* b = *r;
  No* a = b->esq;
  b->esq = a->dir;
  a->dir = b;
  a->bal = 0;
  b->bal = 0;
  *r = a;
}

void RR(No** r) {
  No* a = *r;
  No* b = a->dir;
  a->dir = b->esq;
  b->esq = a;
  a->bal = 0;
  b->bal = 0;
  *r = b;
}

void LR(No** r) {
  No *c = *r;
  No *a = c->esq;
  No *b = a->dir;
  c->esq = b->dir;
  a->dir = b->esq;
  b->esq = a;
  b->dir = c;
  switch(b->bal) {
  case -1:
    a->bal = 0;
    c->bal = 1;
    break;
  case 0:
    a->bal = 0;
    c->bal = 0;
    break;
  case +1:
    a->bal = -1;
    c->bal = 0;
    break;
  }
  b->bal = 0;
  *r = b;
}

void RL(No** r) {
  No *a = *r;
  No *c = a->dir;
  No *b = c->esq;
  c->esq = b->dir;
  a->dir = b->esq;
  b->esq = a;
  b->dir = c;
  switch(b->bal) {
  case -1:
    a->bal = 0;
    c->bal = 1;
    break;
  case 0:
    a->bal = 0;
    c->bal = 0;
    break;
  case +1:
    a->bal = -1;
    c->bal = 0;
    break;
  }
  b->bal = 0;
  *r = b;  
}


/* *cresceu indica se a árvore cresceu 
   após a inserção */
int aux_insere(No** t, int v, int *cresceu) {
  if (*t == NULL) {
    *t = cria(v, NULL, NULL);
    *cresceu = 1;
    return 1;
  }
    
  if (v == (*t)->v) 
    return 0;

  if (v < (*t)->v) {
    if (aux_insere(&(*t)->esq, v, cresceu)) {
      if (*cresceu) {
	switch ((*t)->bal) {
	case -1:
	  if ((*t)->esq->bal == -1)
	    LL(t);
	  else
	    LR(t);
	  *cresceu = 0;
	  break;
	case 0:
	  (*t)->bal = -1;
	  *cresceu = 1;
	  break;
	case +1:
	  (*t)->bal = 0;
	  *cresceu = 0;
	  break;
	}
      }
      return 1;
    }
    else
      return 0;
  }
  
  if (aux_insere(&(*t)->dir, v, cresceu)) {
      if (*cresceu) {
	switch ((*t)->bal) {
	case -1:
	  (*t)->bal = 0;
	  *cresceu = 0;
	  break;
	case 0:
	  (*t)->bal = +1;
	  *cresceu = 1;
	  break;
	case +1:
	  if ((*t)->dir->bal == +1)
	    RR(t);
	  else
	    RL(t);
	  *cresceu = 0;
	  break;
	}
      }
      return 1;
    }
    else
      return 0;

 
}

/* Retorna 1 se inseriu ou 0 se 
   o elemento ẽ repetido. */
int insere(No **t, int v) {
  int cresceu;
  return aux_insere(t, v, &cresceu);
}

void imprime (No* a)
{
	if (a != NULL) {
		imprime(a->esq);
		printf("%d\n - ",a->v);
		imprime(a->dir);
	}
}

void imprime_RED (No* a)
{
	printf("<");
	if (a != NULL) {
		printf("%d",a->v);
		imprime_RED(a->esq);
		printf(">");
		printf("<");
		imprime_RED(a->dir);
		printf(">");
	}
}

void imprime_cresc (No* a)
{
	if (a != NULL) {
		imprime_cresc(a->esq);
		printf("%d  ",a->v);
		imprime_cresc(a->dir);
	}
}

void imprime_decres (No* a)
{
	if (a != NULL) {
		imprime_decres(a->dir);
		printf("%d  ",a->v);
		imprime_decres(a->esq);
	
	}
}


int main() {
  No* t = cria(1, NULL, NULL);  escreve_verifica(t);	puts("\n----- ");
  insere(&t, 3);	escreve_verifica(t);	puts("\n----- ");
  insere(&t, 2);	escreve_verifica(t);	puts("\n----- ");
  insere(&t, 5);	escreve_verifica(t);	puts("\n----- ");
  insere(&t, 4);	escreve_verifica(t);	puts("\n----- ");
  puts("\n----- ");
  puts("\nArvore Original ");
  imprime_RED(t);
  puts("\n----- ");
  puts("\nNODOS EM CRESCENTE ");
  imprime_cresc(t);
  puts("\n----- ");
  puts("\nNODOS EM CRESCENTE ");
  imprime_decres(t);
  return 0;
}
