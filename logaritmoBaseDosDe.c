#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int tamano;
	
	printf("Tamano del arreglo: ");
	scanf("%d", &tamano);
	
	
	int tamanioArray = (tamano-1)*2;
	int cont, contNew, aux;
	int inicio;
	int fin;
	
	int i, j, k;
	int a[tamano];
	
	for(i =0 ; i<tamano ; i++){
		a[i] = 1;
	}
	int *aNew[tamanioArray];
	int tamanos[tamanioArray];
	
	inicio = 0;
	fin = tamano / 2;
	
	aNew[0] = (int*) malloc(fin*sizeof(int));
	printf("\n ");
	for(i=0 ; i<fin ; i++){
		aNew[0][i] = a[i];
	}
	
	tamanos[0] = fin;
	tamanos[1] = tamano - fin;
	
	cont = fin;
	inicio = fin;
	fin = tamano;
	
	aNew[1] = (int*) malloc((tamano-fin)*sizeof(int));
	
	for(i=0 ; i<fin ; i++){
		aNew[1][i] = a[cont];
		cont++;
	}
	
	cont = 0;
	contNew = 2;
	
	
	
	for(k = 0 ; k<9 ; k++){
		
		while(tamanos[cont] == 1){
			cont++;
		}
			
		inicio = 0;
		//2
		fin = tamanos[cont]/2;
		//2
		tamanos[contNew] = fin;
		aNew[contNew] = (int*) malloc((fin)*sizeof(int));
		
		for(i=inicio ; i<fin ; i++){
			aNew[contNew][i] = aNew[cont][i];
		}
		
		contNew++;
		tamanos[contNew] = tamanos[cont]-fin;
		aNew[contNew] = (int*) malloc((tamanos[cont]-fin)*sizeof(int));
		
		inicio = fin;
		fin = tamanos[cont];
		aux = 0;
			
		
		for(i=inicio ; i<fin ; i++){
			aNew[contNew][aux] = aNew[cont][i];
			aux++;
		}
	
		cont++;
		contNew++;
		
	}
	
	int potencia = 2;
	int nivel = 1;
	cont = 0;
	inicio=0;
	
	printf("\nNIVELES\n\n");
	
	while(cont < 4){
		
		printf("NIVEL: %d\n\n", nivel);
		
		for(i=inicio ; i<16 && i<potencia+inicio ; i++){
			for(j=0 ; j<tamanos[i] ; j++){
				printf(" %d ", aNew[i][j]);
			}
			
			printf("  ||  ");	
		}
		printf("\n\n");
		
		inicio += potencia;
		potencia *= 2;
		nivel++;
		cont++;
	}
	
	return 0;
}
