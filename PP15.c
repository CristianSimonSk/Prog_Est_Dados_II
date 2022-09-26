// Busca em profundidade

#include <stdio.h>
#include <stdlib.h>

/* Vértices de grafos são representados por objetos do tipo vertex. */
#define vertex int
#define N 10000

int graph[N];
int visited[N];

int min(int a, int b){
	if(a < b) return a;
	return b;
}

void addedge(int u, int v)
{
    graph[u-1] = v-1;
    graph[v-1] = u-1;
}

void dfs(int node, int a[], int mini){
	if(mini != a[node]){
		printf("\nValor minimo entre %d e %d ",mini,a[node]);
		mini = min(mini,a[node]);
		printf(" eh %d",mini);
	}
	
	visited[node] = 1;
	
	int v = graph[node];
		if(!visited[v]){
			dfs(v,a,mini);
	}
}

minimumSumConectedComponents(int a[],int n){
	int sum = 0, i = 0;
	
	for(;i<n; i++){
		if(!visited[i]){
			int mini = a[i];
			dfs(i,a,mini);
			sum +=mini;
		}
	}
	return sum;
}

main() {
	
	int a[] = {1, 6, 2, 7, 3, 8, 4, 9, 5, 10};
	addedge(1,2);
	addedge(3,4);
	addedge(5,6);
	addedge(7,8);
	addedge(9,10);
	
	int n = sizeof(a) / sizeof(a[0]);
	
	printf("\n\nA soma para visitar todos minima eh %d\n",minimumSumConectedComponents(a,n));	
	
	return 0;
}


