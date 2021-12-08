// Cristian Augusto Simon

/*
Problema 6 Implemente funções recursivas para as funções acima.
*/
//Obs fiz uma lista com 3 elementos com a função recursiva que subtrai 5, até chegar ao 0 ou resto.
#include <stdlib.h>
#include<stdio.h>
int j=0;
struct Lista {
	int valor;
	struct Lista *prox;
	};		
struct Lista subrai_5_ate_0(struct Lista *pont){
	if (pont->valor >= 5){
			pont->valor = pont->valor - 5;
			j++;
			subrai_5_ate_0(pont);			
	}	
	if (pont->valor < 5){
			printf("\nForam subraidos 5,  %d vezes\n", j);
			printf("Ficou de resto  %d\n", pont->valor);
			j=0;
			pont= pont->prox;
	}
	return (subrai_5_ate_0(pont));
}
main(){
	struct Lista x, y, z;
	struct Lista *pont = &x;
	x.valor=100;
	y.valor= 150;
	z.valor= 200;
	x.prox= &y;
	y.prox= &z;
	z.prox= NULL;
	
	subrai_5_ate_0(pont);
	
	getchar();
}
