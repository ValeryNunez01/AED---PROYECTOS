#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nodo{
	int num;
	int id;
	int state;	
	//nodo;
};
	
typedef nodo *apu_nodo;



//CREACIÓN DE MATRIZ DE ADYACENCIA

void matrizAdyacencia(int arregloNods[][], int nodos){
	
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

void impresionMatrizAdyacencia(int[] arregloNodos){
		
	printf("\nMATRIZ DE ADYACENCIA\n\n");

	for(i=0 ; i<nodos ; i++){
		printf("\nNODO [%d]\t", i+1);
		
		for(j=0 ; j<nodos ; j++){
			printf("%d\t", arregloNodos[i][j]);
		}
	}
	
}

int buscarCamino(int fila, int columna, int[] matrix){
	
}



int main(int argc, char** argv) {
	
		
	int nodos;
	
	printf("Numero de nodos: ");
	scanf("%d", &nodos);
	
	int arregloNodos[5][5];
	
	matrizAdyacencia(arregloNodos, nodos);

	
	return 0;
}

