//Cristian Augusto Simon


//Questão 3 

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define MAX 4

struct arv {
	int info;
	struct arv* esq;
	struct arv* dir;
};
typedef struct arv Arv;

int raiz; 

int vazia(Arv* a)
{
	return a==NULL;
}
//A árvore é representada pelo ponteiro para o nó raiz. A árvore vazia é inicializada
//atribuindo-se NULL a variável que representa a árvore. Uma função simples de
//inicialização é mostrada abaixo:
Arv* init (void)
{
	return NULL;
}

Arv* insere (Arv* a, int v)
{
	if (a==NULL) {
		a = (Arv*)malloc(sizeof(Arv));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else if (v < a->info)
		a->esq = insere(a->esq,v);
	else /* v < a->info */
		a->dir = insere(a->dir,v);
	return a;
}

void imprime_alt (Arv* a)
{
	if (!vazia(a)){
		if (a->info == raiz)
			printf("<");
		printf("%d", a->info); /* mostra raiz */
		printf("<");
		imprime_alt(a->esq); /* mostra sae */
		printf(">");
		printf("<");
		imprime_alt(a->dir); /* mostra sad */
		printf(">");
		if (a->info == 6)
			printf(">");
	}
}

imprime_dist(Arv* a, int i, int m){
	Arv* aux;
	Arv* aux2;
	Arv* aux3;
	Arv* aux4;
	Arv* aux5;
	Arv* aux6;
	Arv* aux7;
	if(i==0){
		printf("%d",raiz);
		return 0;
	}
	if(i==1){
		aux = a->esq;
		printf("%d  ",aux->info);
		aux = a->dir;
		printf("%d  ",aux->info);
		return 0;
	}
	
	if(i==2){
		aux = a->esq;
		aux2= aux->esq;
		aux3= aux->dir;
		if(aux2 != NULL)printf("%d  ",aux2->info);
		if(aux3 != NULL)printf("%d  ",aux3->info);
		aux = a->dir;
		aux2= aux->esq;
		aux3= aux->dir;
		if(aux2 != NULL)printf("%d  ",aux2->info);
		if(aux3 != NULL)printf("%d  ",aux3->info);
		
		return 0;
	}
	if(i==3){
		aux = a->esq;
		aux2= aux->esq;
		aux3= aux->dir;
		aux4= aux2->esq;
		aux5= aux2->dir;
		if(aux4 != NULL)printf("%d  ",aux4->info);
		if(aux5 != NULL)printf("%d  ",aux5->info);
		aux4= aux3->esq;
		aux5= aux3->dir;
		if(aux4 != NULL)printf("%d  ",aux4->info);
		if(aux5 != NULL)printf("%d  ",aux5->info);
		
		aux = a->dir;
		aux2= aux->esq;
		aux3= aux->dir;
		aux4= aux2->esq;
		aux5= aux2->dir;
		if(aux4 != NULL)printf("%d  ",aux4->info);
		if(aux5 != NULL)printf("%d  ",aux5->info);
		aux4= aux3->esq;
		aux5= aux3->dir;
		if(aux4 != NULL)printf("%d  ",aux4->info);
		if(aux5 != NULL)printf("%d  ",aux5->info);
		
		return 0;
	}
	/*if(i==4){
		aux = a->esq;
		aux2= aux->esq;
		aux3= aux->dir;
		aux4= aux2->esq;
		aux5= aux2->dir;
		if(aux4 != NULL)printf("%d  ",aux4->info);
		if(aux5 != NULL)printf("%d  ",aux5->info);
		aux4= aux3->esq;
		aux5= aux3->dir;
		if(aux4 != NULL)printf("%d  ",aux4->info);
		if(aux5 != NULL)printf("%d  ",aux5->info);
		
		aux = a->dir;
		aux2= aux->esq;
		aux3= aux->dir;
		aux4= aux2->esq;
		aux5= aux2->dir;
		if(aux4 != NULL)printf("%d  ",aux4->info);
		if(aux5 != NULL)printf("%d  ",aux5->info);
		aux4= aux3->esq;
		aux5= aux3->dir;
		if(aux4 != NULL)printf("%d  ",aux4->info);
		if(aux5 != NULL)printf("%d  ",aux5->info);
		
		return 0;
	}
	*/
	if(i==5){
		printf("  ");
		return 0;
	}
		
}
	
void imprime (Arv* a)
{
	if (a != NULL) {
		imprime(a->esq);
		printf("%d\n",a->info);
		imprime(a->dir);
	}
}

void main() {
setlocale (LC_ALL,"portuguese");
Arv* arv = init();
arv = insere(arv, 6);
arv = insere(arv, 8);
arv = insere(arv, 2);
arv = insere(arv, 1);
arv = insere(arv, 4);
arv = insere(arv, 3);
arv = insere(arv, 20);
arv = insere(arv, 10);
arv = insere(arv, 15);
raiz = 6;
puts("");
puts("Arvore original: \n");
imprime_alt (arv); puts("\n");

for(int i=0; i<6;i++){
printf("\nk = %d: ", i);

imprime_dist(arv,i,0);
}
}
