//AUTORA: Núñez Ramírez Valery Aylin

#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int nodos, i, j;
	int estado;
	
	printf("Numero de nodos: ");
	scanf("%d", &nodos);
	
	int arregloNodos[nodos][nodos];
	
	
	//INSERCIÓN DE NODOS
	
	printf("\n***Adyacencia (si = 1 / no = 0)***\n\n");
	
	for(i=0 ; i<nodos ; i++){
		
		printf("\n");
		for(j=0 ; j<nodos ; j++){
			printf("Estado [%d][%d]: ", i+1, j+1);
			scanf("%d", &estado);
			arregloNodos[i][j] = estado;
		}
	}
	
	
	//IMPRESION DE LA MATRIZ
	printf("\nMATRIZ DE ADYACENCIA\n\n");
	for(i=0 ; i<nodos ; i++){
		printf("         %d", i+1);
	}
	
	for(i=0 ; i<nodos ; i++){
		printf("\nNODO [%d]\t", i+1);
		
		for(j=0 ; j<nodos ; j++){
			printf("%d\t", arregloNodos[i][j]);
		}
	}
	
	
	return 0;
}
