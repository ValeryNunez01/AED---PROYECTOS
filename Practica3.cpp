//Autora: Valery Aylin Núñez Ramírez

#include <iostream>

struct nodo{
	int valor;
	nodo *apu_sig;
};

typedef nodo *apu_nodo;

int main(int argc, char** argv) {
	
	apu_nodo actual, inicio, auxiliar, final;
	int op, value;
	
	do{
		printf("\n\nMenu: \n1. Insertar al inicio\n2. Insertar al final\n3. Mostrar lista\n4. Insertar ordenado(De mayor a menor)\n5. Salir\n\nOpcion: ");
		scanf("%i", &op);
		
		switch(op){
			
			case 1:
				
				printf("\n\n1. INSERTAR AL INICIO");
				printf("\n\nValor a insertar: ");
				scanf("%i", &value);
				
				auxiliar = new(nodo);
				auxiliar -> valor = value;
								
				if(inicio == NULL){
					auxiliar -> apu_sig = NULL;
					inicio = auxiliar;
					actual = inicio;
				}else{
					auxiliar -> apu_sig = inicio;
					inicio = auxiliar;
				}
				
				printf("\n*** INSERTADO CORRECTAMENTE ***\n");
				
				break;
				
			case 2:
				
				printf("\n\n2. INSERTAR AL FINAL");
				printf("\n\nValor a insertar: ");
				scanf("%i", &value);
				
				auxiliar = new(nodo);
				auxiliar -> valor = value;
				auxiliar -> apu_sig = NULL;
					
				if(inicio == NULL){
					inicio = auxiliar;
					actual = inicio;
				}else{
					actual -> apu_sig = auxiliar;
					actual = auxiliar;					
				}
				
				printf("\n*** INSERTADO CORRECTAMENTE ***\n");
				
				break;
				
			case 3:
				
				printf("\n\n3. MOSTRAR LISTA\n");
				
				auxiliar = actual;
				actual = inicio;
								
				while(actual != NULL){
					printf("\nValor = %i", actual -> valor);
					actual = actual -> apu_sig;
				}
				
				actual = auxiliar;
				
				break;	
				
			case 4:
				
				printf("\n\n1. INSERTAR ORDENADO (MAYOR A MENOR)");
				printf("\n\nValor a insertar: ");
				scanf("%i", &value);
				
				auxiliar = new(nodo);
				auxiliar -> valor = value;
				if(inicio == NULL){
					auxiliar -> apu_sig = NULL;
					inicio = auxiliar;
					actual = inicio;
				}else{
					
					final = actual;
					actual = inicio;
					
					if(actual -> valor <= value){
						auxiliar -> apu_sig = actual;
						inicio = auxiliar;
					}else{
						while(actual -> apu_sig != NULL && actual -> apu_sig -> valor > value){
							actual = actual -> apu_sig;
						}
						
						auxiliar -> apu_sig = actual -> apu_sig;
						actual -> apu_sig = auxiliar;
					}
					
				}
				
				actual = final;
				
				/*
				auxiliar = new(nodo);
				auxiliar -> valor = value;
				
				if(inicio == NULL){
					auxiliar -> apu_sig = NULL;
					inicio = auxiliar;
					actual = inicio;
				}else{
					
					final = actual;
					actual = inicio;
					
					if(actual->valor > value){
						auxiliar -> apu_sig = inicio;
						inicio = auxiliar;
					}else{
						
						while(actual -> apu_sig != NULL && actual -> apu_sig -> valor < value){
							actual = actual -> apu_sig;
						}
						
						auxiliar -> apu_sig = actual -> apu_sig;
						actual -> apu_sig = auxiliar;
					}
			
					actual = final;
				}
				*/
				break;
				
				case 5:
					break;
				
				default:
					printf("******* OPCION INGRESADA INVALIDA *******");
				
						
		}
	}while(op!=5);
	
	
	return 0;
}





























