//autora: Valery Aylin Núñez Ramírez

#include <iostream>

struct nodo{
	int valor;
	nodo *apu_sig;
};

typedef nodo *apu_nodo;

int main(int argc, char** argv) {
	
	int op, va;
	bool conElementos = false;
	
	apu_nodo actual, inicio, auxiliar;
	
	
	printf("MENU:");
	
	
	do{
		
		printf("\n\n1. Insertar nodo\n2. Mostrar lista\n3. Salir");
		printf("\n\nIngrese una opcion: ");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				printf("\n\nInsertar nodo\n");
				
				printf("Valor a insertar: ");
				scanf("%i", &va);
				
				auxiliar -> valor = va;
				auxiliar -> apu_sig = null;
				 
				if(inicio == null){
					actual = auxiliar;
					inicio = auxiliar;
				}else{
					actual -> apu_sig = 
				}
				
					/*
					if(conElementos == false){
						actual = new(nodo);
						actual -> valor = va;
						actual -> apu_sig = NULL;
						inicio = actual;
						conElementos = true;
					}else{
						auxiliar = new(nodo);
						auxiliar -> valor = va;
						auxiliar -> apu_sig = NULL;
						actual -> apu_sig = auxiliar;
						actual = auxiliar;
					}	
						*/
				
							
				printf("\n\nVALOR INGRESADO CON EXITO");
				
				break;
				
			case 2:
				printf("\n\nMostrar lista\n");
					
					/*printf("Valor inicio: %i", inicio->valor);
					printf("Valor auxiliar: %i", auxiliar->valor);
					printf("Valor actual: %i", actual->valor);*/
					
					
					actual = inicio;
					while(actual != NULL){
						printf("\nValor = %i", actual->valor);
						actual = actual -> apu_sig;
					}
				
				
				break;
		}
	
	}while(op != 3);
	
	printf("\n\nGracias :)");

	return 0;
}
































