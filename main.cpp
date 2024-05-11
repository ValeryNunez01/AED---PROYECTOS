//autora: Valery Aylin Núñez Ramírez

#include <iostream>

struct nodo{
	int valor;
	nodo *apu_sig;
};

typedef nodo *apu_nodo;

int main(int argc, char** argv) {
	
	int op, va, value;
	bool conElementos = false;
	
	apu_nodo actual, inicio, auxiliar, final;
	
	
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
						actual -> apu_sig = final;
						actual = auxiliar;
					}	
						
				
							
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
				
			case 3:
				actual = inicio;
				auxiliar = new(nodo);
				auxiliar -> val = 25;
				while(apu_sig != NULL && actual->apu_sig->valor < 25){
					actual = actual->apu_sig;
				}
				auxiliar -> apu_sig = actual->apu_sig;
				actual -> apu_sig = auxiliar;
				
				
				/*printf("Insertar inicio");
				
				printf("Valor a insertar: ");
				scanf("%i", &va);
				
				final = actual;
				
				if(conElementos == false){
						actual = new(nodo);
						actual -> valor = va;
						actual -> apu_sig = NULL;
						inicio = actual;
						conElementos = true;
					}else{
						auxiliar = new(nodo);
						auxiliar -> valor = va;
						auxiliar -> apu_sig = inicio;
						inicio = auxiliar;
						actual = inicio;
						//actual = final;
					}*/
			
			 /*
				printf("Buscar valor: ");
				scanf("%i", &value);
				
				bool encontrado = false;
				actual = inicio;
				
				while(encontrado == false && actual != NULL){
					if(actual->valor == value){
						printf("Valor encontrado");
						encontrado = true;
					}
					actual = actual -> apu_sig;		
				}
				
				if(encontrado == false){
					printf("Valor no encontrado");
				}
				*/
				break;
			/*	
			case 4:
				printf("Insertar inicio");
				
				printf("Valor a insertar: ");
				scanf("%i", &va);
				
				if(conElementos == false){
						actual = new(nodo);
						actual -> valor = va;
						actual -> apu_sig = NULL;
						inicio = actual;
						conElementos = true;
					}else{
						auxiliar = new(nodo);
						auxiliar -> valor = va;
						auxiliar -> apu_sig = inicio->apu_sig;
						inicio = auxiliar;
					}
			break;
				*/
				
				
		}
	
	}while(op != 5);
	
	printf("\n\nGracias :)");
	
	/*
	auxiliar = inicio;
	inicio = inicio->apu_sig;
	delete(auxiliar);
	*/
	
	
	/*
		actual = inicio;
		while(apu_sig != NULL){
			auxiliar = actual;
			actual = actual->apu_sig;
			delete(auxiliar);
			
			
		}
		delete(actual);
		
			
	
	*/

	return 0;
}







