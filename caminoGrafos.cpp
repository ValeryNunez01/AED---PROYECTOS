#include <iostream>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nodo{
	int num;
	int id;
	int state;	
	//nodo;
};
	
typedef nodo *apu_nodo;

/*

//CREACIÓN DE MATRIZ DE ADYACENCIA

void matrizAdyacencia(apu_nodo arregloNodos[][5], int nodos){
	
	int i, j;
	int estado;
	
	printf("\n***Adyacencia (si = 1 / no = 0)***\n\n");
	
	for(i=0 ; i<nodos ; i++){
		
		printf("\n");
		for(j=0 ; j<nodos ; j++){
			printf("Estado [%d][%d]: ", i+1, j+1);
			scanf("%d", &estado);
			arregloNodos[i][j] = estado;
		}
	}
}

//IMPRESION DE MATRIZ DE ADYACENCIA

void impresionMatrizAdyacencia(int arregloNodos[][5], int nodos){
		
	printf("\nMATRIZ DE ADYACENCIA\n\n");
	
	int i, j;
		

	for(i=0 ; i<nodos ; i++){
		printf("\nNODO [%d]\t", i+1);
		
		for(j=0 ; j<nodos ; j++){
			printf("%d\t", arregloNodos[i][j]);
		}
	}
	
}
*/

bool buscarCamino(int fila, int columna, apu_nodo matrix[][5], int tam, int camino[25], int pos){
	
	int i, j;
	apu_nodo aux = NULL;
	
	if(pos != -1){
		
		for(i = 0 ; i<tam ; i++){
			for(j = 0 ; j<tam ; j++){
				aux = matrix[i][j]; 
				if(aux->state == 1 ){
					
				}
			}
		}
		
	}
	
	return false;

}



int main(int argc, char** argv) {
	
		
	int nodos;
	int camino[5*5];
	bool res;
	
	//printf("Numero de nodos: ");
	//scanf("%d", &nodos);
	
	apu_nodo auxiliar = NULL, arregloNodos[5][5];
	
	auxiliar = new(nodo);
	auxiliar->state = 0;
	arregloNodos[0][1] = auxiliar;
	camino[0] = 1;
	
	res = buscarCamino(0, 2, arregloNodos, 5, camino, 1);
	//matrizAdyacencia(arregloNodos, nodos);

	if(res = true){
		printf("si");
	}else{
		printf("no");
	}
	return 0;
}

