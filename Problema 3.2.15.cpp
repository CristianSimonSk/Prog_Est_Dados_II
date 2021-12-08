// Cristian Augusto Simon

/*
Problema 15 .Faça uma função recursiva que calcule o valor da serie S descrita a seguir para um valor n>0 a ser fornecido como parametro para a mesma. 
S= 2 + 5/2 + 10/3 + ... + 1+N²/N;
*/
#include <stdlib.h>
#include<stdio.h>
int i=0;
float s = 2, x=0, y=0;  //s= 2
float calcula(float n){     //n=5
	float aux;
	if (n < 0){
		n *= -1;
	}
	aux= (1+n*n)/n; //  aux = 3
	
	while (aux >= ((5+x)/(2+y))){
		x=x+5;
		y++;
		s = s + ((5+x)/(2+y));
	}	
	s = s + aux;
	printf ("%.2f\n", s);
}
main(){
	float n=5;
	float *ps= &s;
	calcula(n);
	getchar();	
}

