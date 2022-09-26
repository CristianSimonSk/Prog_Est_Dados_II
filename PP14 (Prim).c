// Cristian Augusto Simon

// Algoritmo de Prim

#include <stdio.h>
#include <stdlib.h>
#define vertex int
#define MAX 100000
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

	
}

