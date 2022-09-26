//Gustavo Manfio Stefanello
//Cristian Augusto Simon
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define vertex int
#define INFINITY 1000000000
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
   float cst; // custo!
};

static link NEWnode( vertex w, link next, float cst) { 
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

void GRAPHinsertArc( Graph G, vertex v, vertex w, float cst) { 
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v], cst);
   G->A++;
}

vertex pa[1000];
float dist[1000];


void GRAPHcptD1(Graph G, vertex s, vertex *pa, float *dist)
{
   int mature[1000];
   vertex v;
   for (v = 0; v < G->V; ++v)
      pa[v] = -1, mature[v] = 0, dist[v] = INT_MAX;
   pa[s] = 0, dist[s] = 0;

   while (1) {
      // escolha de y:
      int min = INT_MAX;
      vertex y;
      vertex z;
      for (z = 0; z < G->V; ++z) {
         if (mature[z]) continue;
         if (dist[z] < min) 
            min = dist[z], y = z;
      }
      if (min == INT_MAX) break;
      // atualiza��o de dist[] e pa[]:
      link a;
      for (a = G->adj[y]; a != NULL; a = a->next) {
         if (mature[a->w]) continue;
         if (dist[y] + a->cst < dist[a->w]) {
            dist[a->w] = dist[y] + a->cst;
            pa[a->w] = y;
         }
      }
      mature[y] = 1;
      
   }
}
#define MAX 100000
int p[1000];
//int dist[1000];

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

main() {

char cidades[6][20] = {{"Frederico"},{"Sarandi"},{"PassoFundo"},{"Chapeco"},{"Lages"},{"Florianopolis"}};


    Graph G = GRAPHinit(6);
    GRAPHinsertArc(G, 0, 1, 94);
    GRAPHinsertArc(G, 1, 2, 77);
    GRAPHinsertArc(G, 2, 4, 280);
    GRAPHinsertArc(G, 0, 3, 119);
    GRAPHinsertArc(G, 3, 4, 330);
    GRAPHinsertArc(G, 4, 5, 231);
	
	GRAPHcptD1(G, 0, pa, dist); 
	float CustoTotal = 0;
	vertex v;


	
    printf("\n1-\n");
    for(v=0; v<G->V; v++){
		printf("\nde frederico ateh %s sao %f km",cidades[v],dist[v]); 
        //disttotal+=dist[v];
	}
  
	
    printf("\n\n3-\n");

	UGRAPHmstP0(G,p);
    for(v=0; v<G->V; ++v){
		link a = G->adj[p[v]];
			for (; a != NULL; a = a->next)
           		if (a->w == v) {
           			printf("\n  de %s ate %s sao: %f", cidades[p[v]], cidades[v], a->cst);
           				CustoTotal += a->cst;
				}
    }
    printf("\nA Km total do trajeto de adjacencias minimas %f km\n",CustoTotal);


    float somadist=0;
    printf("\ncaminho 1\n");
    printf("\nPasso fundo, %f a partir de Fw\n", dist[2]);
    somadist+=dist[2];
    GRAPHcptD1(G, 2, pa, dist);
    printf("\nFlorianopolis, %f a partir de Passo Fundo\n", dist[5]);
    somadist+=dist[5];
    printf("\ndistancia total %f\n", somadist);

    somadist = 0;

    printf("\n\ncaminho 2");
    GRAPHcptD1(G, 0, pa, dist);
    printf("\nChapeco, %f a partir de Fw\n", dist[3]);
    somadist+=dist[3];
    GRAPHcptD1(G, 3, pa, dist);
    printf("\nFlorianopolis, %f a partir de Chapeco\n", dist[5]);
    somadist+=dist[5];
    printf("\ndistancia total %f\n", somadist);
	
}
