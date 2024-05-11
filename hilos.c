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

//int cont = 0;

typedef struct data DATA;

void *quickSort(void *arg);


int main(int argc, char **argv) {
	
	srand(time(NULL));
	
	DATA st_data;
	
	//int a[10] = {7,1,2,5,11,8,3,13,9,0};
	int tam, num, i, j;
	
	printf("\nIngrese el tamano del arreglo: ");
	scanf("%d", &tam);

	for(i=0 ; i<tam ; i++){
		
		num = rand() % 21;
		
		for(j=0 ; j<i ; j++){
			if(num == st_data.a[j]){
				num = rand() % 21;
				j = 0;
			}
		}
		
		st_data.a[i] = num;
	}
	
	//IMPRESION DEL ARREGLO DESORDENADO
	
	printf("\n\nIMPRESION DEL ARREGLO DESORDENADO\n");
	for(i=0 ; i<tam ; i++){
		printf("  %d", st_data.a[i]);
	}
	
	//LLAMADO DE LA FUNCION DE ORDENAMIENTO
	st_data.inicio = 0;
	st_data.fin = tam-1;
	st_data.thread_id = 0;
	
	quickSort(&st_data);
	
	//IMPRESION DEL ARREGLO ORDENADO
	
	printf("\n\nIMPRESION DEL ARREGLO ORDENADO\n");
	for(i=0 ; i<tam ; i++){
		printf("  %d", st_data.a[i]);
	}
	
	return 0;
}
			//	  j	i
//16 3 6 9 4 14 11 19 20



void *quickSort(void *arg){
	
	printf("\nIngrese\n ");
	
	DATA *st = (DATA *)arg;

	int base = st->a[st->inicio];
	int i = st->inicio;
	int j = st->fin;
	int inicio = st->inicio;
	int fin = st->fin;
	int aux;
		
	if(i<j){
		
		while(i < j){
			while(st->a[i] <= base ){
				i++;
			}
			
			while(st->a[j] > base){
				j--;
			}
			
			if(i<j){
				aux = st->a[i];
				st->a[i] = st->a[j];
				st->a[j] = aux;
			}
		}
		
		aux = st->a[j];
		st->a[j] = st->a[st->inicio];
		st->a[st->inicio] = aux;
		
		
		st->fin = j-1;
		st->thread_id = 1;
		st->inicio = inicio;
		printf("%d inicio", st->inicio);
		
		pthread_create(&st->thread_id, NULL, quickSort, &st);
		pthread_join(st->thread_id, NULL);
		
		
		st->inicio = i;
		st->thread_id = 2;
		st->fin = fin;
		printf("%d fin \n", st->fin);
		
		pthread_create(&st->thread_id, NULL, quickSort, &st);
		pthread_join(st->thread_id, NULL);
	}	
	
}

