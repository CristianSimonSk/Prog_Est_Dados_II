// Considerar este c�digo, pois as fun��es de manipula��o de filas s�o aquelas propostas pelos autores:
// Busca em largura
// Fonte: https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/bfs.html

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

// Busca em largura
// Um algoritmo de busca � um algoritmo que percorre um grafo andando pelos arcos de um v�rtice a outro.  
// Depois de visitar a ponta inicial de um arco, o algoritmo percorre o arco e visita sua ponta final.  
// Cada arco � percorrido no m�ximo uma vez.
// H� muitas maneiras de organizar uma busca.  Cada estrat�gia de busca � caracterizada pela ordem em que os 
// v�rtices s�o visitados. Essa estrat�gia est� intimamente relacionada com os conceitos de dist�ncia e caminho m�nimo.

// Algoritmo de busca em largura
// A busca em largura come�a por um v�rtice, digamos s, especificado pelo usu�rio.  O algoritmo visita s, 
// depois visita todos os vizinhos de s, depois todos os vizinhos dos vizinhos, e assim por diante.

// O algoritmo numera os v�rtices, em sequ�ncia, na ordem em que eles s�o descobertos (ou seja, visitados 
// pela primeira vez).  Para fazer isso, o algoritmo usa uma fila (= queue) de v�rtices.  No come�o de cada itera��o, 
// a fila cont�m v�rtices que j� foram numerados mas t�m vizinhos ainda n�o numerados.  O processo iterativo consiste 
// no seguinte:

// enquanto a fila n�o estiver vazia
// 		retire um v�rtice v da fila
// 			para cada vizinho w de v
// 				se w n�o est� numerado
// 					ent�o numere w
// 						ponha w na fila
// No come�o da primeira itera��o, a fila cont�m o v�rtice s, com n�mero 0, e nada mais.

// A fila de v�rtices � manipulada pelas fun��es auxiliares QUEUEinit(), QUEUEput(), QUEUEget(), QUEUEempty() e QUEUEfree().  
// A primeira cria uma fila vazia, a segunda coloca um v�rtice na fila, a terceira tira um v�rtice da fila, a quarta 
// verifica se a fila est� vazia, e a �ltima libera o espa�o ocupado pela fila.
// A numera��o dos v�rtices � registrada num vetor  num[]  indexado pelos v�rtices.  Se v � o k-�simo v�rtice 
// descoberto ent�o num[v] recebe o valor k.	

static int num[1000];

//int fila[1000], f_fila, r_fila; // REPARE NA SIMPLICIDADE DA FILA!!!!!

/* Este m�dulo implementa uma fila de v�rtices. A fila reside no segmento queue[begin..end-1] de um vetor queue[0..N-1]. 
Vamos supor que temos sempre 0 = begin = end = N. (O c�digo abaixo � uma adapta��o do programa 4.11 do volume 1 do 
livro de Sedgewick.) */
static vertex *queue; 
static int begin, end;

void QUEUEinit( int N) { 
   queue = malloc( N * sizeof (vertex));
   begin = end = 0; 
}

int QUEUEempty( void) { 
   return begin == end; 
}

void QUEUEput( vertex v) {
   queue[end++] = v;
}

vertex QUEUEget( void) { 
   return queue[begin++];
}

void QUEUEfree( void) {
   free( queue);
}

/* A fun��o GRAPHbfs() implementa o algoritmo de busca em largura. Ela visita todos os v�rtices do grafo G 
que est�o ao alcance do v�rtice s e registra num vetor num[] a ordem em que os v�rtices s�o descobertos. Esta 
vers�o da fun��o sup�e que o grafo G � representado por listas de adjac�ncia.  (C�digo inspirado no programa 
18.9 de Sedgewick.) */
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

// Exemplo A.  Considere o grafo G definido pelos arcos  0-2 0-3 0-4 1-2 1-4 2-4 3-4 3-5 4-5 5-1.  Suponha que os 
// v�rtices est�o em ordem crescente de nomes em cada lista de adjac�ncia.  Submeta G � fun��o GRAPHbfs() com 
// segundo argumento 0.  Eis o estado da fila (coluna esquerda) e o estado do vetor num[] (coluna direita) no 
// in�cio de cada itera��o:

//queue            0 1 2 3 4 5
//0                0 - - - - -
//  2 3 4          0 - 1 2 3 -						  >	2 <
//    3 4          0 - 1 2 3 -						 /	V  \1
//      4 5        0 - 1 2 3 4						0->	4 </
//        5        0 - 1 2 3 4						 \	^	5
//          1      0 5 1 2 3 4						  >	3
//                 0 5 1 2 3 4
 	/*Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 2);
	GRAPHinsertArc(G, 0, 3);
	GRAPHinsertArc(G, 0, 4);
	GRAPHinsertArc(G, 1, 2);
	GRAPHinsertArc(G, 1, 4);
	GRAPHinsertArc(G, 2, 4);
	GRAPHinsertArc(G, 3, 4);
	GRAPHinsertArc(G, 3, 5);
	GRAPHinsertArc(G, 4, 5);
	GRAPHinsertArc(G, 5, 1);
	GRAPHbfs(G, 0); */
	
	// 0-2 0-3 0-4 1-2 1-4 2-4 3-4 3-5 4-5 5-1
	Graph G = GRAPHinit(6);
	GRAPHinsertArc(G, 0, 2);
	GRAPHinsertArc(G, 0, 3);
	GRAPHinsertArc(G, 0, 4);
	GRAPHinsertArc(G, 1, 2);
	GRAPHinsertArc(G, 1, 4);
	GRAPHinsertArc(G, 2, 4);
	GRAPHinsertArc(G, 3, 4);
	GRAPHinsertArc(G, 3, 5);
	GRAPHinsertArc(G, 4, 5);
	GRAPHinsertArc(G, 5, 1);
	GRAPHbfs(G, 0);	
	
	
	
	//0-2 0-3 0-4 1-2 1-4 2-4 3-4 3-5 4-5 5-1
	//void GRAPHremoveArc( Graph G, vertex v, vertex w); // implementar
	//void GRAPHshow( Graph G); // implementar
	//void GRAPHshowAll( Graph G); // implementar
}


