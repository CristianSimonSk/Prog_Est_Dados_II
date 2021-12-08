// Cristian Augusto Simon

/*
Problema 7 Implemente uma fila em C, onde cada item da fila consista em um número variável de inteiros.
*/
#include <stdlib.h>
#include<stdio.h>
#include <locale.h>
struct No{
	int info;
	struct No *prox;
};

struct Fila{
	struct No *ini;
	struct No *fim;
};

struct Fila* cria(void){
	
	struct Fila* f = (struct Fila*) malloc(sizeof(struct Fila));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

struct No* ins_fim(struct No *fim, int v){
	
	struct No* p = (struct No*) malloc(sizeof(struct No));
	p->info = v;
	p->prox = NULL;
	if (fim != NULL)
		fim->prox = p;
	return p;
}
struct No* ret_ini(struct No* ini){
	
	struct No *p = ini->prox;
	free(ini);
	return p;
}
void insere(struct Fila *f, int v){
	
	f->fim = ins_fim(f->fim, v);
	if (f->ini==NULL) 
		f->ini = f->fim;
}

void imprime(struct Fila *f){
	struct No* q;
	for (q=f->ini; q!=NULL; q=q->prox)
		printf("%d\t",q->info);
}

main(){
	int valor=1;
	struct Fila* f = cria();
	puts("Insira o valor que voce quer adicionar ou 0 para imprimir os valores inseridos:");
	while (valor != 0){
		scanf ("%d",&valor);
		if(valor>0)
		insere(f, valor);	
	}
	if (valor==0){
		printf("\n=================================================================================================================\n");
		puts("Em uma sequencia de Fila, esses sao os valores adicionados:");
		imprime(f);
		printf("\n=================================================================================================================\n");
	}
	getchar();
}
