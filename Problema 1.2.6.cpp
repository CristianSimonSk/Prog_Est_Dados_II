// Cristian Augusto Simon

/* Problema 1.2.6 (OBI2000) Quermesse Os alunos do �ltimo ano resolveram organizar uma quermesse para arrecadar fundos para a festa de formatura.
 A festa prometia ser um sucesso, pois o pai de um dos formandos, Te�filo, dono de uma loja de inform�tica, decidiu doar um computador para ser sorteado entre os que comparecessem. 
 Os alunos prepararam barracas de quent�o, pipoca, doces, ensaiaram a quadrilha e colocaram � venda ingressos numerados sequencialmente a partir de 1. 
 O n�mero do ingresso serviria para o sorteio do computador. Ficou acertado que Te�filo decidiria o m�todo de sorteio; em princ�pio o sorteio seria, claro, computadorizado.
  O local escolhido para a festa foi o gin�sio da escola. A entrada dos participantes foi pela porta principal, que possui uma roleta, onde passa uma pessoa por vez. 
  Na entrada, um funcion�rio inseriu, em uma lista no computador da escola, o n�mero do ingresso, na ordem de chegada dos participantes. 
  Depois da entrada de todos os participantes, Te�filo come�ou a trabalhar no computador para preparar o sorteio. 
  Verificando a lista de presentes, notou uma caracter�stica not�vel: havia apenas um caso, em toda a lista, em que o participante que possu�a o ingresso numerado com i, havia sido a i-�sima pessoa a entrar no gin�sio. 
  Te�filo ficou t�o encantado com a coincid�ncia que decidiu que o sorteio n�o seria necess�rio: esta pessoa seria o ganhador do computador. 1. 
  Tarefa) Conhecendo a lista de participantes, por ordem de chegada, sua tarefa � determinar o n�mero do ingresso premiado, sabendo que o ganhador � o �nico participante que tem o n�mero do ingresso igual � sua posi��o de entrada na festa. 
  2. Entrada) A entrada � composta de v�rios conjuntos de teste. A primeira linha de um conjunto de teste cont�m um n�mero inteiro positivo N que indica o n�mero de participantes da festa. 
  A linha seguinte cont�m a sequ�ncia, em ordem de entrada, dos N ingressos das pessoas que participaram da festa. O final da entrada � indicado quando N = 0. 
  Para cada conjunto de teste da entrada haver� um �nico ganhador. Exemplo de Entrada 4 4 5 3 1 10 9 8 7 6 1 4 3 2 12 10 0 3. Sa�da) Para cada conjunto de teste da entrada seu programa deve produzir tr�s linhas. 
  A primeira linha identifica o conjunto de teste, no formato "Teste n", onde n � numerado a partir de 1. 
  A segunda 5 linha deve conter o n�mero do ingresso do ganhador, conforme determinado pelo seu programa. A terceira linha deve ser deixada em branco. 
  A grafia mostrada no Exemplo de Sa�da, abaixo, deve ser seguida rigorosamente. Exemplo de Sa�da Teste 1 3 Teste 2 10 (esta sa�da corresponde ao exemplo de entrada acima)*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define MAX 1000 //Determinei a festa como 1000 participantes
main(){
	int vet1[MAX], vet2[MAX], ganhador[MAX]; ;
	int l, j, i=0, m,  op=1,op2=1, gg;
	
	setlocale (LC_ALL,"portuguese");
	for (l=0;l<MAX;l++){
		vet1[l]= 0;
		vet2[l]= 0;
		ganhador[l]= 0;
	}	
	while (op==1){
		puts ("Insira: \n 1- Para pr�ximo participante.\n 2- Para lista de ganhador(es) e Sair.");
		scanf("%d",&op);
		switch(op){
			case 1: {
				puts("Insira o numero do seu ingresso:");
				scanf("%d", &vet1[i]);
				vet2[i] = i+1; 
				i++; 
				break;
			}
			case 2 : {
				if (op=2){
					for (j=0;j<MAX;j++){
						if (vet1[j] == vet2[j]){
							ganhador[j] = vet1[j];	
						}
					}
				}
				puts("\nO(s) ganhador(es) foram:");
				for (m=0;m<MAX;m++){
					if(ganhador[m]!=0){
					printf("\n%d\n",ganhador[m]);
					}
				}
				break;
			}
			default : puts("Insira um numero valido");
		}
	}
	getchar();
}
	


