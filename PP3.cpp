/*Prova da Semana 3 - Programação e Estruturas de Dados II
Problema:
Encontre os três maiores elementos distintos em um vetor.
Considere o protótipo:
Função para imprimir e retornar os três maiores elementos de um vetor 
Lista3m mostra3maiores(int arr[], int arr_size) {}
Exemplo:
Entrada: arr[] = {46, 5, 8, 6, 100, 23, 17, 45, 1, 10, 33, 2};
Saída : 100, 46, 45 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
mostrarmaior (int arr[]){
	int i, maior;
	maior = arr[0];
	for(i=0; i<12; i++){
		if (arr[i] > maior){
			maior = arr[i];
		}	
	}
	for(i=0; i<12; i++){
		if (arr[i] == maior){
			arr[i]=0;
		}	
	}
	printf("\nO MAIOR ELEMENTO EH O %d\n",maior);
}

mostrarsegmaior (int arr[]){
	int i, maior2;
	maior2 = arr[0];
	for(i=0; i<12; i++){
		if (arr[i] > maior2){
			maior2 = arr[i];
		}	
	}
	for(i=0; i<12; i++){
		if (arr[i] == maior2){
			arr[i]=0;
		}	
	}
	printf("\nO SEGUNDO MAIOR ELEMENTO EH O %d\n",maior2);
}
mostrartercmaior (int arr[]){
	int i, maior3;
	maior3 = arr[0];
	for(i=0; i<12; i++){
		if (arr[i] > maior3){
			maior3 = arr[i];
		}	
	}
	for(i=0; i<12; i++){
		if (arr[i] == maior3){
			arr[i]=0;
		}	
	}
	printf("\nO TERCEIRO MAIOR ELEMENTO EH O %d\n",maior3);	
}

main (){
	int arr[] = {46, 5, 8, 6, 100, 23, 17, 45, 1, 10, 33, 2};
mostrarmaior(arr);
mostrarsegmaior(arr);
mostrartercmaior(arr);
system("pause");		
}
