// 

/*Problema:
Dada uma árvore binária (AB), converta-a em uma lista duplamente encadeada (LDE). Os ponteiros esquerda
e direita nos nós da AB devem ser usados como ponteiros anteriores e próximos, respectivamente, na LDE
convertida. A ordem dos nós na LDE deve ser a mesma da ABP. O primeiro nó da travessia ERD (nó mais à
esquerda na AB) deve ser o nodo cabeça da LDE. Ex.:
*/

#include <stdio.h>
#include <string.h>

struct arv {
	char info;
	struct arv* esq;
	struct arv* dir;
};

typedef struct arv Arv;

Arv* inicializa(void)
{
	return NULL;
}

Arv* cria(char c, Arv* sae, Arv* sad){
	Arv* p=(Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

int vazia(Arv* a)
{
	return a==NULL;
}

void imprime (Arv* a)
{
	if (!vazia(a)){
		printf("%c ", a->info); 
		imprime(a->esq); 
		imprime(a->dir); 
	}
}	

void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == 'a')
			printf("<");
		printf("%c", a->info); 
		printf("<");
		imprime_alt(a->esq); 
		printf(">");
		printf("<");
		imprime_alt(a->dir); 
		printf(">");
		if (a->info == 'a')
			printf(">");
	}
}	

Arv* libera (Arv* a){
	if (!vazia(a)){
		libera(a->esq); 
		libera(a->dir); 
		free(a); 
	}
	return NULL;
}


int altura(Arv* a) {
   if (a == NULL) 
      return -1; 
   else {
      int he = altura (a->esq);
      int hd = altura (a->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

int busca (Arv* a, char c){
	if (vazia(a))
		return 0; 
	else
		return a->info==c || busca(a->esq,c) || busca(a->dir,c);
}

struct lista {
		int info;
		// entrada para a lista duplamente encadeada
		struct lista* prox;
	};

typedef struct lista Lista;

Lista *inicio = NULL, *fim = NULL;

/* função de inicialização: retorna uma lista vazia */
Lista* inicializa (void)
{
	return NULL;
}

// l = inicializa(); /* inicia lista vazia */


/* inserção no início: retorna a lista atualizada */
Lista* insere (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	if (inicio == NULL) // lista vazia!
		inicio = novo;
	novo->info = i;
	novo->prox = l;
	fim = novo;
	return novo;
}

/* função imprime: imprime valores dos elementos */
void imprime (Lista* l)
{
	Lista* p; /* variável auxiliar para percorrer a lista */
	int i;

	for (p = l; p != NULL; p = p->prox)  // for (i=0;i<N;i++)
		printf("info = %d\n", p->info);  //		printf(vet[i];);
		
/*	p = l;	
	do {
		printf("info = %d\n", p->info);
		p = p->prox;
	} while (p != NULL);*/	
	puts("");
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int vazia (Lista* l)
{
	if (l == NULL)
		return 1;
	else
		return 0;
}

/* função busca: busca um elemento na lista */
Lista* busca (Lista* l, int v)
{
	Lista* p;
	
	for (p=l; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;
	return NULL; /* não achou o elemento */
}

void libera (Lista* l)
{
	Lista* p = l;

	while (p != NULL) {
		Lista* t = p->prox; /* guarda referência para o próximo elemento */
	
		free(p); /* libera a memória apontada por p */
		p = t; /* faz p apontar para o próximo */
	}
}

int main (void) {
	Arv* a1= cria('25',inicializa(),inicializa()); 
	Arv* a2= cria('30',inicializa(),inicializa()); 
	Arv* a3= cria('36',inicializa(),inicializa()); 
	Arv* a4= cria('12',a1,a2; 
	Arv* a5= cria('15',a3,inicializa());
	Arv* a = cria('10',a4,a5 ); 
	imprime(a);
	puts("");
	imprime_alt(a);
/*
	printf("\nint altura(Arv* a) %d", altura(a));
	printf("\nint busca (Arv* a, char c) %d", busca (a, 'a'));
	printf("\nint busca (Arv* a, char c) %d", busca (a, 'x'));
	libera(a);
	Lista* l; 
	l = inicializa(); 
	l = insere(l, 101); printf("INICIO: %d FIM: %d\n",inicio->info,fim->info);
	l = insere(l, 116); printf("INICIO: %d FIM: %d\n",inicio->info,fim->info);
	l = insere(l, 282); printf("INICIO: %d FIM: %d\n",inicio->info,fim->info);
	l = insere(l, 153); printf("INICIO: %d FIM: %d\n",inicio->info,fim->info);

	
	imprime(l); 


	
	libera(l);*/
	return 0;
}
