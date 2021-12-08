// Cristian Augusto Simon

/*
Problema 8
Um deque (Double Ended Queue) é um conjunto de itens a partir do qual podem ser eliminados e inseridos
itens em ambas as extremidades. Chame as duas extremidades de um deque esq e dir. Escreva quatro funções 
em C, RemDir, RemEsq, InsDir, InsEsq, para remover e inserir elementos nas extremidades esquerda e direita 
de um deque. Certifique-se de que as funções funcionem corretamente para o deque vazio e detectem o estouro
(overflow) e o underflow (tentativa de remoção quando a fila está vazia). Faça implementações com um deque 
representado como um vetor, como uma lista simples e como uma lista duplamente encadeada.
*/
#include <stdlib.h>
#include<stdio.h>
#include <locale.h>
int i=0;

struct No{
	int info;
	struct No *prox;
};

struct Lista{
	struct No *pri;
	struct No *ult;
};

struct Lista* cria(void){
	
	struct Lista* l = (struct Lista*) malloc(sizeof(struct Lista));
	l->pri = NULL;
	l->ult = NULL;
	return l;
}
struct No* insEsq(struct No *pri, int v){
	
	struct No* p = (struct No*) malloc(sizeof(struct No));
	p->info = v;
	p->prox = NULL;
	if (pri != NULL)
		pri->prox = p;
	return p;
}

struct No* insDir(struct No *ult, int v){
	
	struct No* p = (struct No*) malloc(sizeof(struct No));
	p->info = v;
	p->prox = NULL;
	if (ult != NULL)
		ult->prox = p;
	return p;
}
struct No* retEsq(struct No *pri){
	
	struct No *p = pri->prox;
	free(pri);
	puts("Removido com sucesso.");
	return p;
}

struct No* retDir(struct No *ult){
	struct No *p = ult->prox;
	free(ult);
	puts("Removido com sucesso.");
	return p;
}

void insereEsq(struct Lista *l, int valor){
	
	l->pri = insEsq(l->pri, valor);
	if (l->ult==NULL) 
		l->ult = l->pri;
}

void insereDir(struct Lista *l, int valor){
	
	l->ult = insDir(l->ult, valor);
	if (l->pri==NULL) 
		l->pri = l->ult;
}

void imprime(struct Lista *dq){
	struct No* q;
	printf("\n##############################################\n");
	puts("Os valores são:");
	for (q=dq->pri; q!=NULL; q=q->prox){
		printf("%d\t",q->info);
	}
	printf("\n##############################################\n");
}

int menu (struct Lista *dq, int op, struct No *pri, struct No *ult){
	int valor;
	printf("\n=============================================\n");
	puts("Insira :\n 1- Para adicionar um Valor no inicio da Lista. \n 2- Para adicionar um Valor no final da Lista. \n 3- Para remover um Valor no inicio da Lista. \n 4- Para remover um Valor no final da Lista. \n 5- Para ver a Lista.  \n 0- Para sair.");
	printf("\n=============================================\n\n");
	if(i==0){
		scanf("%d",&op);
		switch (op){
			case 0 : exit(1); break;
			case 1 : {
					puts("Insira o valor que deseja adicionar");
					scanf("%d",&valor);
					insereEsq(dq, valor); break;
					}
			case 2 : {
					puts("Insira o valor que deseja adicionar");
					scanf("%d",&valor);
					insereDir(dq, valor); break;
					}
			case 3 : retEsq(pri); break;	
			case 4 : retDir(ult); break;	
			case 5 : imprime(dq); break;	
			default : puts("Opção Invalida"); break;
		}
		return op;
	}
	if(i!=0){
		scanf("%d",&op);
		switch (op){
			case 0 : exit(1); break;
			case 1 : {
					puts("Insira o valor que deseja adicionar");
					scanf("%d",&valor);
					insereEsq(dq, valor); break;
					}
			case 2 : {
					puts("Insira o valor que deseja adicionar");
					scanf("%d",&valor);
					insereDir(dq, valor); break;
					}	
			case 3 : retEsq(pri); break;	
			case 4 : retDir(ult); break;	
			case 5 : imprime(dq); break;	
			default : puts("Opção Invalida"); break;
		}
		return op;
	}
}
main(){
	int op=1;
	struct No *pri;
	struct No *ult;
	struct Lista *dq;
	setlocale (LC_ALL,"portuguese");
	dq = cria();
	while (op=!0){
		menu(dq, op, pri, ult);
	}
	getchar();
}
