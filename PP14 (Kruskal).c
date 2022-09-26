// Cristian Augusto Simon

// Algoritmo de Kruskal

#include <stdio.h>
#include <stdlib.h>

/* Vértices de grafos são representados por objetos do tipo vertex. */
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

vertex pa[1000];//, p[1000];
int dist[1000];

// Como representar a floresta geradora?  A representação por vetor de pais que 
// usamos em outros algoritmos é incômoda no caso do algoritmo de Kruskal. Adotaremos
// como representação uma simples lista das arestas da floresta, armazenada num vetor. 
// Cada aresta v-w será representada por uma struct edge, construída por uma função 
// EDGE():

typedef struct { 
    vertex v, w; 
    int c; 
} edge;

// Em C, as funções são globais por padrão. A palavra -chave "static" antes de um 
// nome de função a torna estática. Diferentemente das funções globais em C, o acesso 
// a funções estáticas é restrito ao arquivo onde são declaradas. Portanto, quando 
// queremos restringir o acesso às funções, as tornamos estáticas.

static edge EDGE( vertex v, vertex w, int c) {
   edge e;
   e.v = v, e.w = w; e.c = c;
   return e;
}

void UGRAPHmstK0(Graph G, edge mst[]) { 
   vertex chefe[1000];
   for (vertex v = 0; v < G->V; ++v){
        chefe[v] = v;
	}
   int k = 0;

   while (1) {
      	// a floresta tem arestas mst[0..k-1]
      	int min = MAX;
      	vertex x, y;
      	for (vertex v = 0; v < G->V; ++v) {
         	for (link a = G->adj[v]; a != NULL; a = a->next) {
            	vertex w = a->w; int c = a->cst;
            	if (v < w && chefe[v] != chefe[w] && c < min) {
               		min = c;
               		x = v, y = w;
            	}
         	}
      	}
      	if (min == MAX) return;
      	mst[k++] = EDGE(x, y, min);
      	vertex v0 = chefe[x], w0 = chefe[y]; // 1
      	for (vertex v = 0; v < G->V; ++v)    // 2
        	if (chefe[v] == w0)  {             // 3
        	chefe[v] = v0;                 // 4
      	}
   }
}


void main() {

  	Graph G = GRAPHinit(8);
	GRAPHinsertArc(G, 3, 5, 0);
	GRAPHinsertArc(G, 1, 7, 1);
	GRAPHinsertArc(G, 6, 7, 2);
	GRAPHinsertArc(G, 0, 2, 3);
	GRAPHinsertArc(G, 0, 7, 4);	
	GRAPHinsertArc(G, 0, 1, 5);
	GRAPHinsertArc(G, 3, 4, 6);
	GRAPHinsertArc(G, 5, 4, 7);
	GRAPHinsertArc(G, 4, 7, 8);
	GRAPHinsertArc(G, 0, 6, 9);
	GRAPHinsertArc(G, 4, 6, 9);
	GRAPHinsertArc(G, 0, 5, 11);

	
	edge mst[1000];	
	UGRAPHmstK0(G, mst);
	 
	puts("\n--- Codigo de KRUSKAL IME/USP ---\n");
	int custoTotal = 0;
	
	for (vertex v = 0; v < G->V; ++v){
        if (mst[v].v != mst[v].w){
        	printf("\nv %d w %d custo eh %d ",mst[v].v, mst[v].w, mst[v].c);
        	custoTotal += mst[v].c;
        }
    }
    //descartados
    for (vertex v = 0; v < G->V; ++v) {
        for (link a = G->adj[v]; a != NULL; a = a->next) {
            vertex w = a->w; int c = a->cst;
            int flag = 0;
            for(int i=0; i < G->V; ++i){
            	if(mst[i].c == c)
            		if(mst[i].w == w)
            			flag = 1;
           	}
           	if(!flag)
           		printf("\nDescartado v %d w %d custo %d",v,w,c);
        }
    }
		
	printf("\nCusto total da travessia nesta MST eh: %d", custoTotal);

}



