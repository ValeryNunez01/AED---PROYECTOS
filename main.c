#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Menu
//Insertar Nodo
//Borrar Nodo
//Insertar al inicio
//mostrar todos los nodos
//mostrar un nodo en específico
//insertar un nodo en el orden que le corresponde

struct nodo{
	int valor;
	nodo *apu_sig;
};

typedef nodo *apu_nodo;

int main(int argc, char *argv[]) {
	
	apu_nodo actual, inicio, auxiliar;
	int op, value;
	
	do{
		printf("Menu: \n1. Insertar Nodo\n2. Insertar al inicio\n3. Insertar segun el valor\n\nOpcion: ");
		scanf("%i", op);
		
		switch(op){
			case 1:
				printf("\n\n1. INSERTAR NODO");
				printf("\nValor a insertar: ");
				scanf("%i", value);
				
				auxiliar = new(nodo);
				auxiliar -> valor = value;
					
				if(inicio == NULL){
					auxiliar -> apu_sig = NULL;
					inicio = auxiliar;
					actual = inicio;
				}else{
					auxiliar -> apu_sig = NULL;
					actual -> apu_sig = auxiliar;
					actual = auxiliar;					
				}
				
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
		}
	}while(op!=6);
	
	
	return 0;
}
