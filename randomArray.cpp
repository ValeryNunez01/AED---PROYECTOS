//AUTORA: Valery Aylin Núñez Ramírez

#include <iostream>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	srand (time(NULL));  
	
	int num;
	int tam;
	int cont = 0;
	
	printf("Tamano del arreglo = ");
	scanf("%d", &tam);
	printf("\n\n");
	
	int array[tam];
	
	//GENERACION DE NUMEROS ALEATORIOS
	
	while(cont < tam){
		num = rand() % 1001;
		
		for(int i=0 ; i<cont ; i++){
			if(num == array[i]){
				num = rand() % 1001;
				i=0;
			}
		}
		array[cont] = num;
		cont++;
	}
	
	printf("\n\nARREGLO DE NUMEROS ALEATORIOS\n\n");
		
	for(int i=0 ; i<cont ; i++){
		printf("%d  ", array[i]);
	}
	
	
	//ORDENAMIENTO DE NUMEROS ALEATORIOS
	
	int aux;
	
	for(int i=0 ; i<tam ; i++){
		for(int i=0 ; i<(tam-1) ; i++){
			if(array[i+1]<array[i]){
				aux = array[i+1];
				array[i+1] = array[i];
				array[i] = aux;
			}
		}
	}
	
	printf("\n\nORDENADOS DE MENOR A MAYOR\n\n");
	for(int i=0 ; i<cont ; i++){
		printf("%d  ", array[i]);
	}
	
	
	return 0;
}
