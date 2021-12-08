#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void rearranjo(int vet[]){
 	int i, par=0, impar=1;
	for (i=0; i<10; i++){
 		if (vet[i]>0){
 			vet[par]= vet[i];
 			par=par+2;
		}
		if (vet[i]<0){
 			vet[par]= vet[i];
 			impar=impar+2;
		}
	}
}
void imprimir (int vet[]){
 	int i;
 	for (i=0; i<10; i++){
 	printf("\n%d,",vet[i]);
	}
}
main () {
	int vet[10] = {-1, 3, -5, 6, 3, 6, -7, -4, -9, 10};
	rearranjo(vet);
	imprimir (vet);
}
 
 

