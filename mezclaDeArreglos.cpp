//autora: Valery Aylin Núñez Ramírez

#include <iostream>
#include <time.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	srand(time(NULL));
	
	//LLENADO DE ARREGLOS DE MANERA ALEATORIA

	int tamA = (rand() % 11) + 1;
	int tamB = (rand() % 11) + 1;
	int tamC = tamA + tamB;
	
	int i,j;
	
	int a[tamA];
	int b[tamB];
	int c[tamC];
	
	for(i=0 ; i<tamA ; i++){
		a[i] = rand() % 21;
	}
	
	for(i=0 ; i<tamB ; i++){
		b[i] = rand() % 21;
	}
	
	printf("\n\tARREGLO A Y B SIN ORDENAR\n");
		
	printf("\n---ARREGLO A---\n");
	for(int i=0 ; i<tamA ; i++){
		printf("  %d  ", a[i]);
	}
	
	printf("\n");
	
	printf("\n---ARREGLO B---\n");
	for(int i=0 ; i<tamB ; i++){
		printf("  %d  ", b[i]);
	}
	
	//ORDENAMIENTO DE ARREGLOS
	//0 10 12 8 2
	for(i=0 ; i<tamA-1 ; i++){
		for(j=i ; j<tamA ; j++){
			if(a[i]>a[j]){
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}
	
	for(i=0 ; i<tamB-1 ; i++){
		for(j=i ; j<tamB ; j++){
			if(b[i]>b[j]){
				int aux = b[i];
				b[i] = b[j];
				b[j] = aux;
			}
		}
	}
	
	printf("\n\n\nARREGLO A Y B YA ORDENADOS");
		
	printf("\n\n---ARREGLO A---\n");
	for(int i=0 ; i<tamA ; i++){
		printf("  %d  ", a[i]);
	}
	
	printf("\n");
	
	printf("\n---ARREGLO B---\n");
	for(int i=0 ; i<tamB ; i++){
		printf("  %d  ", b[i]);
	}
	
	
	//int a[5] = {1,5,7,12,16};
	//int b[2] = {3,8};
	//int c[7];
	
	int inA = 0 , inB = 0, inC = 0;
	
	while(inC < tamC){
		
		if(inA < tamA && inB < tamB){
			if(a[inA] <= b[inB]){
				c[inC] = a[inA];
				inA++;
			}else{
				c[inC] = b[inB];
				inB++;
			}
		}else if(inA < tamA){
			c[inC] = a[inA];
			inA++;
		}else{
			c[inC] = b[inB];
			inB++;
		}
		
		inC++;
	} 
	
	printf("\n");
	
	printf("\n\n---ARREGLO C (MEZCLA DE A Y B)---\n");
	
	for(int i=0 ; i<tamC ; i++){
		printf("  %d  ", c[i]);
	}
		
	return 0;
}
