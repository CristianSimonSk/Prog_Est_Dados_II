// Algoritmo de Prim
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/prim.html

#include <stdio.h>
#include <stdlib.h>

/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int
#define MAX 100000

struct arvgen {
	int info;
	struct arvgen *prim;
	struct arvgen *prox;
};

typedef struct arvgen ArvGen;

ArvGen* cria (int c)
{
	ArvGen *a =(ArvGen *) malloc(sizeof(ArvGen));
	a->info = c;
	a->prim = NULL;
	a->prox = NULL;
	return a;
}

void insere (ArvGen* a, ArvGen* sa)
{	// a == pai; sa == filho
	sa->prox = a->prim;
	a->prim = sa;
}

void imprime (ArvGen* a)
{
	ArvGen* p;
	printf("%d\n",a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
		imprime(p);
}

void imprime_alt (ArvGen* a)
{
	ArvGen* p;
	printf("<%d",a->info);
	for (p=a->prim; p!=NULL; p=p->prox)
		imprime_alt(p);
	printf(">");	
}

//A operação para buscar a ocorrência de uma dada informação na árvore é exemplificada
//abaixo:
int busca (ArvGen* a, int c)
{
	ArvGen* p;
	if (a->info==c)
		return 1;
	else {
		for (p=a->prim; p!=NULL; p=p->prox) {
			if (busca(p,c))
			return 1;
		}
	}
	return 0;
}

// A última operação apresentada é a que libera a memória alocada pela árvore. O único
//cuidado que precisamos tomar na programação dessa função é a de liberar as subárvores
//antes de liberar o espaço associado a um nó (isto é, usar pós-ordem).
void libera (ArvGen* a)
{
	ArvGen* p = a->prim;
	while (p!=NULL) {
		ArvGen* t = p->prox;
		libera(p);
		p = t;
	}
	free(a);
}

/*	ArvGen* a = cria('a'); 0
	ArvGen* b = cria('b'); 1
	ArvGen* c = cria('c'); 2
	ArvGen* d = cria('d'); 3
	ArvGen* e = cria('e'); 4
	ArvGen* f = cria('f'); 5
	ArvGen* g = cria('g'); 6
	ArvGen* h = cria('h'); 7
	ArvGen* i = cria('i'); 8
	ArvGen* j = cria('j'); 9*/
	
typedef struct node *link;

struct graph {
   int V; 
   int A; 
   link *adj; 
};

typedef struct graph *Graph;

struct node { 
   vertex w; 
   link next; 
   int cst; // custo!
};

static link NEWnode( vertex w, link next, int cst) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   a->cst = cst;
   return a;                         
}

Graph GRAPHinit( int V) { 
   vertex v;	
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = malloc( V * sizeof (link));
   for (v = 0; v < V; ++v) 
      G->adj[v] = NULL;
   return G;
}

void GRAPHinsertArc( Graph G, vertex v, vertex w, int cst) { 
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v], cst);
   G->A++;
}

vertex pa[1000], p[1000];
int dist[1000];

void UGRAPHmstP0(Graph G, vertex *pa) { 
   for (vertex w = 0; w < G->V; ++w) pa[w] = -1;
   pa[0] = 0; 
   while (1) {
      int min = MAX;
      vertex x, y;
      for (vertex v = 0; v < G->V; ++v) {
         if (pa[v] == -1) continue;
         for (link a = G->adj[v]; a != NULL; a = a->next)
            if (pa[a->w] == -1 && a->cst < min) {
               min = a->cst;
               x = v, y = a->w;
            }
      }
      if (min == MAX) break;
      // A
      pa[y] = x;
   }
}

void main() {

  	Graph G = GRAPHinit(8);
	GRAPHinsertArc(G, 5, 4, 35);
	GRAPHinsertArc(G, 7, 4, 37);
	GRAPHinsertArc(G, 7, 5, 28);
	GRAPHinsertArc(G, 0, 7, 16);
	GRAPHinsertArc(G, 1, 5, 32);
	GRAPHinsertArc(G, 0, 4, 38);
	GRAPHinsertArc(G, 2, 3, 17);
	GRAPHinsertArc(G, 7, 1, 19);
	GRAPHinsertArc(G, 0, 2, 26); 
	GRAPHinsertArc(G, 1, 2, 36);
	GRAPHinsertArc(G, 1, 3, 29);
	GRAPHinsertArc(G, 7, 2, 34);
	GRAPHinsertArc(G, 2, 6, 40);
	GRAPHinsertArc(G, 3, 6, 52);
	GRAPHinsertArc(G, 0, 6, 58);
	GRAPHinsertArc(G, 6, 4, 93);
	
	vertex v;
	UGRAPHmstP0(G, p);

	ArvGen* a = cria(0);
	ArvGen* a1 = cria(1);
	ArvGen* a2 = cria(2);
	ArvGen* a3 = cria(3);
	ArvGen* a4 = cria(4);
	ArvGen* a5 = cria(5);
	ArvGen* a6 = cria(6);
	ArvGen* a7 = cria(7);
	
	/* monta a hierarquia */
	insere(a,a2);
	insere(a,a7);
	insere(a2,a3);
	insere(a2,a6);
	insere(a7,a1);
	insere(a7,a5);
	insere(a5,a4);

	puts("\n--- Codigo de PRIM IME/USP ---\n");
	int custoTotal = 0;
	for(vertex v = 0; v < G->V; ++v){
		if(v != p[v]){
			printf("\n v %d seu pai eh %d e o",v,p[v]);
			link a = G->adj[p[v]];
			for(;a != NULL; a = a->next){
				if(a->w == v){
					printf("custo %d",a->cst);
					custoTotal += a->cst;
				}
			}
		}
	}
	printf("\nCusto total da travessia nesta MST eh: %d", custoTotal);

	puts("\n\nArvore n-aria resultante:\n");
	imprime_alt (a);	
	
}

