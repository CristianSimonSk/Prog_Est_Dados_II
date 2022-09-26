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
		imprime(a->esq); 
		printf("%d ", a->info); 
		imprime(a->dir); 
	}
}	

void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == 'a')
			printf("<");
		printf("%d", a->info); 
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
Lista* l; 
Lista *inicio = NULL, *fim = NULL;

/* função de inicialização: retorna uma lista vazia */
Lista* inicializa2 (void)
{
	return NULL;
}

// l = inicializa(); /* inicia lista vazia */


/* inserção no início: retorna a lista atualizada */
Lista* insere2 (Lista* l, int i)
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
void imprime2 (Lista* l)
{
	Lista* p; /* variável auxiliar para percorrer a lista */
	int i;

	for (p = l; p != NULL; p = p->prox)  // for (i=0;i<N;i++)
		printf("%d  ", p->info);  //		printf(vet[i];);
		
/*	p = l;	
	do {
		printf("info = %d\n", p->info);
		p = p->prox;
	} while (p != NULL);*/	
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int vazia2 (Lista* l)
{
	if (l == NULL)
		return 1;
	else
		return 0;
}

/* função busca: busca um elemento na lista */
Lista* busca2 (Lista* l, int v)
{
	Lista* p;
	
	for (p=l; p!=NULL; p=p->prox)
		if (p->info == v)
			return p;
	return NULL; /* não achou o elemento */
}

void percore(Arv* a)
{ 	
	if (!vazia(a)){
		percore(a->esq);
		l = insere2(l, a->info); 
		percore(a->dir);
	}
}

/*Lista* imprime_2 (Arv* a) {     
Lista* p=inicializa2();     
if (!vazia(a)){         
imprime_2(a->esq);
p=insere(p,a->info);
imprime_2(a->dir);
}
imprime_lista(p);     
return p; }
*/
int main (void) {
	Arv* a1= cria(6,inicializa(),inicializa()); 
	Arv* a2= cria(5,inicializa(),inicializa()); 
	Arv* a3= cria(4,inicializa(),inicializa()); 
	Arv* a4= cria(3,a1,a2); 
	Arv* a5= cria(2,a3,inicializa());
	Arv* a = cria(1,a4,a5 ); 
	imprime(a);
	puts("");
	imprime_alt(a);
	puts(""); 
	imprime2(l); 

	return 0;
}
