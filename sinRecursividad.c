#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int tamano = 9;
	int tamanioArray = (tamano-1)*2;
	int cont, contNew, aux;
	int inicio;
	int fin;
	
	int i, j, k;
	
	int a[9] = {7, 9, 2, 5, 11, 1, 18, 6, 21};
	int *aNew[tamanioArray];
	int tamanos[tamanioArray];
	
	inicio = 0;
	fin = tamano / 2;
	
	aNew[0] = (int*) malloc(fin*sizeof(int));
	
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
	
	for(k = 0 ; k<tamanioArray ; k++){
			printf("\nl");
		inicio = 0;
		fin = tamanos[cont]/2;

		tamanos[contNew] = fin;
		aNew[contNew] = (int*) malloc((fin)*sizeof(int));
		
		for(i=inicio ; i<fin ; i++){
			aNew[contNew][i] = aNew[cont][i];
		}
			printf("\nl");
		contNew++;
		tamanos[contNew] = tamanos[cont]-fin;
		aNew[contNew] = (int*) malloc((tamanos[cont]-fin)*sizeof(int));
	
		//cont++;
		
		inicio = fin;//2
		fin = tamanos[cont];//4
		aux = 0;
			printf("\nl");
		
		for(i=inicio ; i<fin ; i++){
			printf("  %d  ", aNew[cont][i]);
			aNew[contNew][aux] = aNew[cont][i];
			printf("  %d  ", aNew[contNew][aux]);
			aux++;
		}
		
		printf("\nl");
		k = 19;
		
		
	}
	
	
	
	
	for(j=0 ; j<tamanos[3] ; j++){
		printf(" %d - ", aNew[3][j]);
	}
	
	printf("impresion\n\n\n\n\n");
	for(i=0 ; i<7 ; i++){
		printf("TAMANO: %d", tamanos[i]);
		for(j=0 ; j<tamanos[i] ; j++){
			printf(" %d - ", aNew[i][j]);
		}
		
		printf("\n");
	}
	
	return 0;
}
