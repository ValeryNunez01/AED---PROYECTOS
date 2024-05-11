#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX 50

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct nodo{
	char sentencia[MAX];
	nodo *apu_der, *apu_izq; 
};

typedef nodo *apu_nodo;

int main(int argc, char *argv[]) {
	
		
	apu_nodo raiz = NULL, auxiliar = NULL, actual = NULL;
	
	raiz = new(nodo);
	raiz->sentencia;
	
	auxiliar = new(nodo);
	auxiliar->sentencia;
	
	raiz->apu_der = auxiliar;
	
	auxiliar = new(nodo);
	auxliar -> sentencia;
	
	raiz -> apu_izq = auxiliar;
	
	actual = raiz->apu_der;
	
	
	
	printf("");
	printf("\n----Ingresa el numero de la opcion a elegir---\n");
	
	while(apu-der != NULL || apu_izq != NULL){
		
	}
	

	
	return 0;
}

