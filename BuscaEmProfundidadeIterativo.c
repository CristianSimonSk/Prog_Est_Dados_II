// Busca em profundidade
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dfs.html

#include <stdio.h>
#include <stdlib.h>

/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int

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
};

static link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
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

void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next) 
      if (a->w == w) return;
   G->adj[v] = NEWnode( w, G->adj[v]);
   G->A++;
}

// Busca DFS
// O algoritmo de busca DFS visita todos os vértices e todos os arcos do grafo numa determinada ordem e 
// atribui um número a cada vértice: o k-ésimo vértice descoberto recebe o número k?.

// A função GRAPHdfs() abaixo é uma implementação do algoritmo.  A busca poderia começar por qualquer vértice, 
// mas é natural começá-la pelo vértice 0.  A numeração dos vértices é registrada em um vetor  pre[]  indexado pelos vértices.

// Para simplificar o código, trataremos o vetor pre[] como variável global e suporemos que o número de vértices 
// não passa de 1000.  (Veja abaixo o exercício Alocação dinâmica.) Também trataremos como variável global o contador cnt 
// usada para a numeração:
	
static int cnt; // aqui vai simular a pilha!!!!
int pre[1000];

/* A função GRAPHdfs() faz uma busca em profundidade no grafo G. Ela atribui um número de ordem pre[x] 
a cada vértice x de modo que o k-ésimo vértice descoberto receba o número de ordem k.  (Código inspirado 
no programa 18.3 de Sedgewick.) */
void GRAPHdfs( Graph G) 
{ 
   cnt = 0;
   vertex v;
   for (v = 0; v < G->V; ++v) 
      pre[v] = -1;
   for (v = 0; v < G->V; ++v)
      if (pre[v] == -1) 
         dfsR( G, v); // começa nova etapa
}


void GRAPHbfs( Graph G, vertex s) 
{ 
   int cnt = 0;
   vertex v;
   for (v = 0; v < G->V; ++v)
      num[v] = -1;
   QUEUEinit(1000);
   num[s] = cnt++; // descoberto!
   printf("Descoberto %d\n", num[s]); 
   QUEUEput( s); 

   //while (!QUEUEempty( )) {
   while (!QUEUEempty( )) {
   	  //puts("AQUI!") ;
      vertex v = QUEUEget( ); 
      link a;
      for (a = G->adj[v]; a != NULL; a = a->next)
         if (num[a->w] == -1) {
            num[a->w] = cnt++; // descoberto!
            printf("Descoberto %d\n", num[a->w]); 
            QUEUEput( a->w); 
         }
   }
   QUEUEfree( ); 
}

// A função GRAPHdfs() é apenas um invólucro; a busca propriamente dita é realizada pela função recursiva dfsR().  
// Em geral, nem todos os vértices estão ao alcance do primeiro vértice visitado em GRAPHdfs(), e portanto a função dfsR() 
// precisa ser invocada várias vezes por GRAPHdfs().  Cada uma dessas invocações define uma [!] etapa da busca.

/* A funçao dfsR() visita todos os vértices de G que podem ser alcançados a partir do vértice v sem passar por 
vértices já descobertos. A função atribui cnt+k a pre[x] se x é o k-ésimo vértice descoberto. (O código supõe que G é 
representado por listas de adjacência.) */
void dfsR( Graph G, vertex v) 
{ 
   pre[v] = cnt++; // descoberto!
   printf("Descoberto %d\n", pre[v]);
   link a;
   for (a = G->adj[v]; a != NULL; a = a->next) {
      vertex w = a->w;
      if (pre[w] == -1)
         dfsR( G, w); 
   }
}

main() {
// Por exemplo, eis o vetor de listas de adjacência do grafo 
// cujos arcos são  0-1 0-5 1-0 1-5 2-4 3-1 5-3 :

//	0: 5 1
//	1: 5 0
//	2: 4
//	3: 1
//	4:  
//	5: 3
//	Graph G = GRAPHinit(6);
//	GRAPHinsertArc(G, 0, 5);
//	GRAPHinsertArc(G, 0, 1);
//	GRAPHinsertArc(G, 1, 5);
//	GRAPHinsertArc(G, 1, 0);
//	GRAPHinsertArc(G, 2, 4);
//	GRAPHinsertArc(G, 3, 1);
//	GRAPHinsertArc(G, 5, 3);

// Exemplo A.  Considere o grafo G definido pelos arcos  0-1 1-2 1-3 2-4 2-5 .   
// Veja a matriz de adjacências (com - no lugar de 0) e as listas de adjacência do grafo:

// - 1 - - - -    0:  1								0
// - - 1 1 - -    1:  2 3							1
// - - - - 1 1    2:  4 5						2		3
// - - - - - -    3:						4		5
// - - - - - -    4:
// - - - - - -    5:
	Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 1);
	GRAPHinsertArc(G, 1, 2);
	GRAPHinsertArc(G, 1, 3);
	GRAPHinsertArc(G, 2, 4);
	GRAPHinsertArc(G, 2, 5);
	GRAPHdfs(G);	
	//void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
	//void GRAPHshow( Graph G); // implementar
	//void GRAPHshowAll( Graph G); // implementar
}


