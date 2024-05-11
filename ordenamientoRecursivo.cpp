#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void *quickSort(/*int a[], int inicio, int fin*/ void *arg){
	
	int base = a[inicio];
	int i = inicio;
	int j = fin;
	int aux;
	
	pthread_t proceso1;
	pthread_t proceso2;
	

	if(i<j){
		while(i < j){
			while(a[i] <= base ){
				i++;
			}
			
			while(a[j] > base){
				j--;
			}
			
			if(i<j){
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
				//			  j	i		
				//3   1 2 5 0 7 8 13 9 11
			}
			
			//aux = a[j];
			//a[j] = a[inicio];
			//a[j] = aux;
			//0,
		}
		
		//a[inicio] = a[j];
		//a[j] = base;
		aux = a[j];
		a[j] = a[inicio];
		a[inicio] = aux;
			
		pthread_create(&proceso1, NULL, &quickSort, (void *)&a, (void *)&inicio, (void *)&(j-1));
		//quickSort(a, inicio, j-1);
		pthread_create(&proceso2, NULL, &quickSort, (a, i, fin));
		//3
		//quickSort(a, i, fin);
		pthread_join(proceso1, NULL);
		pthread_join(proceso2, NULL);
	}
		
	
}


int main(int argc, char** argv) {
	
	srand(time(NULL));
	
	pthread_t hilo;
	
	//int a[10] = {7,1,2,5,11,8,3,13,9,0};
	int tam, num;
	
	printf("\nIngrese el tamano del arreglo: ");
	scanf("%d", &tam);
	
	int a[tam];
	
	//ASIGNACION DE ELEMENTOS NO REPETIDOS AL ARREGLO
	
	for(int i=0 ; i<tam ; i++){
		
		num = rand() % 21;
		
		for(int j=0 ; j<i ; j++){
			if(num == a[j]){
				num = rand() % 21;
				j = 0;
			}
		}
		
		a[i] = num;
	}
	
	//IMPRESION DEL ARREGLO DESORDENADO
	
	printf("\n\nIMPRESION DEL ARREGLO DESORDENADO\n");
	for(int i=0 ; i<tam ; i++){
		printf("  %d", a[i]);
	}
	
	//LLAMADO DE LA FUNCION DE ORDENAMIENTO
	
	quickSort(a, 0, tam-1);
	
	//IMPRESION DEL ARREGLO ORDENADO
	
	printf("\n\nIMPRESION DEL ARREGLO ORDENADO\n");
	for(int i=0 ; i<tam ; i++){
		printf("  %d", a[i]);
	}
	
	return 0;
}


