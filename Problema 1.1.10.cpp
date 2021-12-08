// Cristian Augusto Simon

/*
Problema 1.1.10 Foi feita uma pesquisa de audiência de canal de TV em várias casas de uma certa cidade, num determinado dia. 
Para cada casa visitada, é fornecido o número do canal (4,5,7,12) e o número de pessoas que o estavam assistindo naquela casa. 
Se a televisão estivesse desligada, nada era anotado, ou seja, esta casa não entrava na pesquisa. 
Fazer um algoritmo que: * leia um número indeterminado de dados, 
sendo que o flag corresponde ao número de canal igual a zero. * calcule a porcentagem de audiência para cada emissora * escreva o número do canal e a sua respectiva porcentagem
*/


#include <stdlib.h>
#include<stdio.h>
#include <locale.h>

void resultados (int c4, int c5, int c7, int c12, int p4, int p5, int p7, int p12){
	int soma = c4+c5+c7+c12, soma2 = p4+p5+p7+p12;
	float pc4, pc5, pc7, pc12;
	float pp4, pp5, pp7, pp12;
	
	pc4 = ((float)c4 * 100)/(float)soma;
	printf("\nA porcentagem de audiencia em relaçao a familias assistindo do canal 4 é %.2f %%.\n",pc4);
	pc5 = ((float)c5 * 100)/(float)soma;
	printf("\nA porcentagem de audiencia em relaçao a familias assistindo do canal 5 é %.2f  %%.\n",pc5);
	pc7 = ((float)c7 * 100)/(float)soma;
	printf("\nA porcentagem de audiencia em relaçao a familias assistindo do canal 7 é %.2f  %%.\n",pc7);
	pc12 = ((float)c12 * 100)/(float)soma;
	printf("\nA porcentagem de audiencia em relaçao a familias assistindo do canal 12 é %.2f  %%.\n",pc12);
	
	pp4 = ((float)p4 * 100)/(float)soma2;
	printf("\nA porcentagem de audiencia em relaçao a pessoas assistindo do canal 4 é %.2f  %%.\n",pp4);
	pp5 = ((float)p5 * 100)/(float)soma2;
	printf("\nA porcentagem de audiencia em relaçao a pessoas assistindo do canal 5 é %.2f  %%.\n",pp5);
	pp7 = ((float)p7 * 100)/(float)soma2;
	printf("\nA porcentagem de audiencia em relaçao a pessoas assistindo do canal 7 é %.2f  %%.\n",pp7);
	pp12 = ((float)p12 * 100)/(float)soma2;
	printf("\nA porcentagem de audiencia em relaçao a pessoas assistindo do canal 12 é %.2f  %%.\n",pp12);	
}
main(){
	int c4=0, c5=0, c7=0, c12=0;
	int p4=0, p5=0, p7=0, p12=0;
	int op=1, x;
	
	setlocale (LC_ALL,"portuguese");
	
	while (op>0){
		puts ("Insira: \n 1 PARA CANAL 4\n 2 PARA CANAL 5\n 3 PARA CANAL 7\n 4 PARA CANAL 12 \n 5 PARA TELEVISÃO DESLIGADA \n 0 PARA SAIR E SEGUIR PARA OS RESULTADOS");
		scanf("%d",&op);
		switch (op){
			case 0 : resultados(c4, c5, c7, c12, p4, p5, p7, p12); break;
			case 1 : puts("Insira quantas pessoas estao assistindo");
					 scanf("%d",&x);
					 c4++;
					 p4+=x;
					 break;
			case 2 : puts("Insira quantas pessoas estao assistindo");
					 scanf("%d",&x);
					 c5++;
					 p5+=x;
					 break;
			case 3 : puts("Insira quantas pessoas estao assistindo");
					 scanf("%d",&x);
					 c7++;
					 p7+=x;
					 break;
			case 4 : puts("Insira quantas pessoas estao assistindo");
					 scanf("%d",&x);
					 c12++;
					 p12+=x;
					 break;
			case 5 : break;
			default : puts("Insira um numero valido");	
		}
	}
	getchar();	
}
