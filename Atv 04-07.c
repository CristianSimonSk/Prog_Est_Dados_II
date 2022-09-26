/*Cristian Augusto Simon*/

/*Problema 4
Faça um programa que, a partir das características do Grafo inserido, escolha o algoritmo de Djiktra ou
Bellman-Ford para sua execução.
Enviar o que for possível para rodrigodevit@inf.ufsm.br até 22:30h de 04/07/2022; o restante pode ser enviado
até a próxima aula.
*/

#include <stdio.h>
#include <stdlib.h>

/* Vértices de grafos são representados por objetos do tipo vertex. */
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

vertex pa[1000];
int dist[1000];


void GRAPHsptD0( Graph G, vertex s) 
{ 
   vertex v;
   for (v = 0; v < G->V; ++v) 
      pa[v] = -1;
   pa[s] = s, dist[s] = 0; 

   vertex y;	
   while (1) {
      int min = INFINITY;
      vertex x;
      vertex v;
      for (v = 0; v < G->V; ++v) {
         if (pa[v] == -1) continue;
         link a;
         for (a = G->adj[v]; a != NULL; a = a->next) {
            if (pa[a->w] != -1) continue;
            if (dist[v] + a->cst < min) {
               min = dist[v] + a->cst;
               x = v, y = a->w;
               
            }
         }
      }
      if (min == INFINITY)  break;
      pa[y] = x, dist[y] = min;
      printf("x %d y %d dist %d\n", x, y, min);
   }

}


#include <stdio.h>
#include <stdlib.h>
#define vertex2 int
#define INTMAX 1000000000
typedef struct node2 *link2;

struct graph2 {
   int V; 
   int A; 
   link2 *adj; 
};

typedef struct graph2 *Graph2;

struct node2 { 
   vertex2 w; 
   link2 next; 
   int cst2; // custo!
};

static link2 NEWnode2( vertex2 w, link2 next, int cst2) { 
   link2 a = malloc( sizeof (struct node2));
   a->w = w; 
   a->next = next;     
   a->cst2 = cst2;
   return a;                         
}

Graph2 GRAPHinit2( int V) { 
   vertex2 v;	
   Graph2 G2 = malloc( sizeof *G2);
   G2->V = V; 
   G2->A = 0;
   G2->adj = malloc( V * sizeof (link2));
   for (v = 0; v < V; ++v) 
      G2->adj[v] = NULL;
   return G2;
}

void GRAPHinsertArc2( Graph2 G2, vertex2 v, vertex2 w, int cst2) { 
   link2 a;
   for (a = G2->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G2->adj[v] = NEWnode2( w, G2->adj[v], cst2);
   G2->A++;
}

vertex2 pa2[1000];
int dist2[1000];

#define vertex2 int
/* Este módulo implementa uma fila de vértices. A fila reside no segmento queue[begin..end-1] de um vetor queue[0..N-1]. Vamos supor que temos sempre 0 = begin = end = N. (O código abaixo é uma adaptação do programa 4.11 do volume 1 do livro de Sedgewick.) */
static vertex2 *queue; 
static int begin2, end2;

void QUEUEinit( int N) { 
   queue = malloc( N * sizeof (vertex2));
   begin2 = end2 = 0; 
}

int QUEUEempty( void) { 
   return begin2 == end2; 
}

void QUEUEput( vertex2 v) {
   queue[end2++] = v;
}

vertex2 QUEUEget( void) { 
   return queue[begin2++];
}

void QUEUEfree( void) {
   free( queue);
}

int GRAPHcptBF2( Graph2 G2, vertex2 s, vertex2 *pa, int *dist2)
{
   QUEUEinit(1000);
   int onqueue[1000];
   for (vertex2 u = 0; u < G2->V; ++u)
      pa2[u] = -1, dist2[u] = INTMAX, onqueue[u] = 0;
   pa2[s] = s, dist2[s] = 0;
   QUEUEput( s);
   onqueue[s] = 1;
   vertex2 V = G2->V;
   QUEUEput( V);
   int k = 0;

   while (1) { 
      vertex2 v = QUEUEget( );
      if (v < V) {
         for (link2 a = G2->adj[v]; a != NULL; a = a->next) {
            if (dist2[v] + a->cst2 < dist2[a->w]) {
               dist2[a->w] = dist2[v] + a->cst2; 
               pa[a->w] = v;
               if (onqueue[a->w] == 0) {
                  QUEUEput( a->w);
                  onqueue[a->w] = 1;
               }
            }
         }
      } else {
         if (QUEUEempty( )) return 1; 
         if (++k >= G2->V) return 0; 
         QUEUEput( V);
         for (vertex2 u = 0; u < G2->V; ++u) 
            onqueue[u] = 0;
      }
   }
}

main() {
 
  	Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 1, 10);
	GRAPHinsertArc(G, 0, 2, 5);
	GRAPHinsertArc(G, 1, 3, 1);
	GRAPHinsertArc(G, 2, 1, 3);
	GRAPHinsertArc(G, 2, 3, 8);
	GRAPHinsertArc(G, 2, 4, 2);
	GRAPHinsertArc(G, 3, 4, 4);
	GRAPHinsertArc(G, 3, 5, 4);
	GRAPHinsertArc(G, 4, 5, 6);

	GRAPHsptD0(G, 0); 
	
	Graph2 G2 = GRAPHinit2(6);
	GRAPHinsertArc2(G2, 0, 1, -4);
	GRAPHinsertArc2(G2, 0, 2, 2);
	GRAPHinsertArc2(G2, 1, 3, 5);
	GRAPHinsertArc2(G2, 2, 1, 1);
	GRAPHinsertArc2(G2, 2, 3, 8);
	GRAPHinsertArc2(G2, 2, 4, 10);
	GRAPHinsertArc2(G2, 3, 4, 2);
	GRAPHinsertArc2(G2, 3, 5, 6);
	GRAPHinsertArc2(G2, 4, 5, 2); 
	
	vertex2 v;
	for (v = 0; v < G->V; ++v)
		printf("v %d pa[v] %d dist[v] %d \n", v, pa[v], dist[v]);
	
	
}
