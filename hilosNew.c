#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAXIMA_LONGITUD 1000

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct data{
	pthread_t thread_id;
	int a[MAXIMA_LONGITUD];
	int inicio;
	int fin;
};

typedef struct data DATA;

void *quickSort(/*int a[], int inicio, int fin*/ void *arg){
	
	DATA st_data;
	
	int base = st_data.a[st_data.inicio];
	int i = st_data.inicio;
	int j = st_data.fin;
	int aux;
	
	pthread_t proceso1;
	pthread_t proceso2;
	

	if(i<j){
		while(i < j){
			while(st_data.a[i] <= base ){
				i++;
			}
			
			while(st_data.a[j] > base){
				j--;
			}
			
			if(i<j){
				aux = st_data.a[i];
				st_data.a[i] = st_data.a[j];
				st_data.a[j] = aux;
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
		aux = st_data.a[j];
		st_data.a[j] = st_data.a[st_data.inicio];
		st_data.a[st_data.inicio] = aux;
		
		//st_data.inicio = inicio;
		st_data.fin = j-1;
			
		pthread_create(&proceso1, NULL, quickSort, &st_data);
		//quickSort(a, inicio, j-1);
	
		st_data.inicio = i;
		//st_data.fin = fin;
		
		pthread_create(&proceso2, NULL, quickSort, &st_data);
		
		//quickSort(a, i, fin);
		pthread_join(proceso1, NULL);
		pthread_join(proceso2, NULL);
	}
		
	
}


int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	int tam, num;
	DATA std_data;
	
//	pthread_t hilo;
	
	//int a[10] = {7,1,2,5,11,8,3,13,9,0};
	
	
	printf("\nIngrese el tamano del arreglo: ");
	scanf("%d", &tam);

	for(int i=0 ; i<tam ; i++){
		
		num = rand() % 21;
		
		for(int j=0 ; j<i ; j++){
			if(num == std_data.a[j]){
				num = rand() % 21;
				j = 0;
			}
		}
		
		std_data.a[i] = num;
	}
	
	//IMPRESION DEL ARREGLO DESORDENADO
	
	printf("\n\nIMPRESION DEL ARREGLO DESORDENADO\n");
	for(int i=0 ; i<tam ; i++){
		printf("  %d", a[i]);
	}
	
	//LLAMADO DE LA FUNCION DE ORDENAMIENTO
	
	
	//quickSort(a, 0, tam-1);
	
	//IMPRESION DEL ARREGLO ORDENADO
	
	printf("\n\nIMPRESION DEL ARREGLO ORDENADO\n");
	for(int i=0 ; i<tam ; i++){
		printf("  %d", a[i]);
	}
	
	return 0;
}


