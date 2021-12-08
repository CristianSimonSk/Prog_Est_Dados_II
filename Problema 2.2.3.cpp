// Cristian Augusto Simon

/* 
Problema 3 . Leia um vetor de 20 posições e em seguida um valor X qualquer. Seu programa deverá fazer uma busca do valor de X no vetor lido e informar a posição em que foi encontrado ou se não foi encontrado.
*/
#include <stdlib.h>
#include<stdio.h>
#include <locale.h>
#define MAX 5

main(){

	int vet[MAX];
	int x, i, j=0;
	setlocale (LC_ALL,"portuguese");
	puts("Insira 20 numeros inteiros:");
	for (i=0; i<MAX; i++){
		scanf ("%d",&vet[i]);
	}
	
	puts("Insira o numero que deseja opter a posição que foi adicionado:");
	scanf ("%d",& x);
	
	for (i=0; i<MAX; i++){
		if (vet[i]==x){
			printf("O valor %d esta na posição %d",x , i+1);
			j++;
		}
	}
	if (j==0){
		printf("O valor %d não foi encontrado",x );
	}	
}
