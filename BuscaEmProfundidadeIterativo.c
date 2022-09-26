// Busca em profundidade
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dfs.html

#include <stdio.h>
#include <stdlib.h>

/* V�rtices de grafos s�o representados por objetos do tipo vertex. */
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
// O algoritmo de busca DFS visita todos os v�rtices e todos os arcos do grafo numa determinada ordem e 
// atribui um n�mero a cada v�rtice: o k-�simo v�rtice descoberto recebe o n�mero k?.

// A fun��o GRAPHdfs() abaixo � uma implementa��o do algoritmo.  A busca poderia come�ar por qualquer v�rtice, 
// mas � natural come��-la pelo v�rtice 0.  A numera��o dos v�rtices � registrada em um vetor  pre[]  indexado pelos v�rtices.

// Para simplificar o c�digo, trataremos o vetor pre[] como vari�vel global e suporemos que o n�mero de v�rtices 
// n�o passa de 1000.  (Veja abaixo o exerc�cio Aloca��o din�mica.) Tamb�m trataremos como vari�vel global o contador cnt 
// usada para a numera��o:
	
static int cnt; // aqui vai simular a pilha!!!!
int pre[1000];

/* A fun��o GRAPHdfs() faz uma busca em profundidade no grafo G. Ela atribui um n�mero de ordem pre[x] 
a cada v�rtice x de modo que o k-�simo v�rtice descoberto receba o n�mero de ordem k.  (C�digo inspirado 
no programa 18.3 de Sedgewick.) */
void GRAPHdfs( Graph G) 
{ 
   cnt = 0;
   vertex v;
   for (v = 0; v < G->V; ++v) 
      pre[v] = -1;
   for (v = 0; v < G->V; ++v)
      if (pre[v] == -1) 
         dfsR( G, v); // come�a nova etapa
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

// A fun��o GRAPHdfs() � apenas um inv�lucro; a busca propriamente dita � realizada pela fun��o recursiva dfsR().  
// Em geral, nem todos os v�rtices est�o ao alcance do primeiro v�rtice visitado em GRAPHdfs(), e portanto a fun��o dfsR() 
// precisa ser invocada v�rias vezes por GRAPHdfs().  Cada uma dessas invoca��es define uma [!] etapa da busca.

/* A fun�ao dfsR() visita todos os v�rtices de G que podem ser alcan�ados a partir do v�rtice v sem passar por 
v�rtices j� descobertos. A fun��o atribui cnt+k a pre[x] se x � o k-�simo v�rtice descoberto. (O c�digo sup�e que G � 
representado por listas de adjac�ncia.) */
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
// Por exemplo, eis o vetor de listas de adjac�ncia do grafo 
// cujos arcos s�o  0-1 0-5 1-0 1-5 2-4 3-1 5-3 :

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
// Veja a matriz de adjac�ncias (com - no lugar de 0) e as listas de adjac�ncia do grafo:

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


