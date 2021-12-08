// Cristian Augusto Simon

/*
Problema 8
Escreva uma função chamada TPilha2 que recebe como parâmetro 2 pilhas (N e P) e um vetor de inteiros. 
Para cada um deles, como segue, faça:
se positivo, inserir na pilha P;
se negativo, inserir na pilha N;
se zero, retirar um elemento de cada pilha
*/

#include <stdlib.h>
#include<stdio.h>
#include <locale.h>

int i=0;
struct No {
	float info;
	struct No *prox;
};
struct Pilha {
	struct No *prim;
};
struct Pilha* cria (void){
	
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}
struct No* ins_ini (struct No* l, float valor){

	No* p = (struct No*) malloc(sizeof(struct No));
	p->info = valor;
	p->prox = l;
	return p;
}
struct No* ret_ini (struct No* l){
	
	No* p = l->prox;
	free(l);
	return p;
} 
struct Pilha push(struct Pilha* p, float valor){
	p->prim = ins_ini(p->prim, valor);
	return *p;
}
int vazia (Pilha* p){
	
	return (p->prim==NULL);
}

float pop (struct Pilha* p) {
	float v;
	if (vazia(p)) {
		printf("Pilha vazia.\n");
		exit(1);
	}
	v = p->prim->info;
	p->prim = ret_ini(p->prim);
	return v;
}
struct Pilha TPilha2 (struct Pilha *p, struct Pilha *n){
	float valor;
	puts("Digite o valor que deseja adicionar:  (caso 0- remove 1 valor positivo e 1 negativo)");
	scanf("%f",&valor);
	
	if(valor > 0){
		push (p, valor);
		return *p;
	}
	
	if(valor < 0){
		push (n, valor);
		return *n;
	}
	
	if(valor == 0){
		pop(p);
		pop(n);
		return *p;
		return *n;
	}
}
void resultados(struct Pilha *p, struct Pilha *n){
	struct No *q;
	printf("\n#############################################\n\n");
	printf("\nValores Positivos:\n");
	for (q=p->prim; q!=NULL; q=q->prox){
		printf("%.2f.\n",q->info);
	}	
		printf("\nValores Negativos:\n");
	for (q=n->prim; q!=NULL; q=q->prox){
		printf("%.2f.\n",q->info);
	}
	printf("\n#############################################\n\n");
}

int menu(struct Pilha *p, struct Pilha *n, int op){
	if(i==0){
		printf("\n=============================================\n");
		puts("Insira :\n 1- Para adicionar um Valor. \n 2- Para ler os Resultados. \n 0- Para sair.");
		printf("\n=============================================\n\n");
		scanf("%d",&op);
		switch (op){
			case 0 : exit(1); break;
			case 1 : TPilha2(p, n); break;
			case 2 : resultados(p, n); break;	
			default : puts("Opção Invalida"); break;
		}
		i++;
		return op;
	}
	if(i!=0){
		printf("\n=============================================\n");
		puts("Insira :\n 1- Para adicionar mais um Valor. \n 2- Para ler os Resultados. \n 0- Para sair."); ///Fiz SÓ pra deixar mais arrumadinho
		printf("\n=============================================\n\n");
		scanf("%d",&op);
		switch (op){
			case 0 : exit(1); break;
			case 1 : TPilha2(p, n); break;
			case 2 : resultados (p, n); break;	
			default : puts("Opção Invalida"); break;	
		}
	}
}

main(){
	int op=1;
	struct Pilha *p;
	struct Pilha *n;
	p = cria();
	n = cria();
	while (op != 0){
		menu(p, n, op);
	}	
}
