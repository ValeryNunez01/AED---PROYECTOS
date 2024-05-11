//Autora: Valery Aylin Núñez Ramírez

#include <iostream>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Menu:

//Insertar Nodo
//Insertar al inicio
//insertar un nodo en el orden que le corresponde

//mostrar todos los nodos

//Borrar Nodo
//Borrar toda la lista


struct nodo{
	int valor;
	nodo *apu_sig;
};

typedef nodo *apu_nodo;

int main(int argc, char** argv) {
	
	apu_nodo actual, inicio, auxiliar, final;
	int op, value;
	
	do{
		printf("\n\nMenu: \n1. Insertar Nodo\n2. Insertar al inicio\n3. Insertar segun el valor\n4. Imprimir lista\n5. Borrar Nodo\n6. Borrar toda la lista\n\nOpcion: ");
		scanf("%i", &op);
		
		switch(op){
			
			case 1:
				
				printf("\n\n1. INSERTAR NODO");
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
				
				printf("\n***** INSERTADO CORRECTAMENTE *****\n");
				
				break;
				
			case 2:
				
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
				
				printf("\n***** INSERTADO CORRECTAMENTE *****\n");
				
				break;
				
			case 3:
				//pequeño error cuando esta antes
				printf("\n\n1. INSERTAR SEGUN EL VALOR");
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
					
					if(actual->valor > value){
						auxiliar -> apu_sig = inicio;
						inicio = auxiliar;
					}else{
						
						while(actual->apu_sig != NULL && actual -> apu_sig -> valor < value){
							actual = actual -> apu_sig;
						}
						
						auxiliar -> apu_sig = actual -> apu_sig;
						actual -> apu_sig = auxiliar;
					}
			
					actual = final;
				}
				
				
				break;
				
			case 4:
				
				printf("\n\n1. IMPRIMIR LISTA\n");
				
				auxiliar = actual;
				actual = inicio;
								
				while(actual != NULL){
					printf("\nValor = %i", actual -> valor);
					actual = actual -> apu_sig;
				}
				
				actual = auxiliar;
				
				break;
			case 5:
				
				printf("\n\n5. BORRAR NODO");
				printf("\n\nValor de nodo a borrar: ");
				scanf("%i", &value);
				
				final = actual;
				actual = inicio;
				
				
				if(actual == NULL){
					printf("\n***** NO SE PUEDE ELIMINAR DE UNA LISTA VACIA *****\n");
				}else{
				
					if(actual -> valor == value && actual != NULL){
						
						inicio = actual -> apu_sig;
						delete(actual);
						printf("\n***** NODO ELIMINADO CORRECTAMENTE *****\n");
						
					}else if(actual != NULL){
											
						while(actual -> apu_sig != NULL && actual -> apu_sig -> valor != value ){
							actual = actual -> apu_sig;
						}
						
						if(actual -> valor != value){
							printf("\n***** VALOR NO ENCONTRADO *****\n");
						}else{
							auxiliar = actual -> apu_sig -> apu_sig;
							delete(actual -> apu_sig);
							actual -> apu_sig = auxiliar;
							printf("\n***** NODO ELIMINADO CORRECTAMENTE *****\n");
						}
											
					}
					
				
				}
				
				actual = final;
				
				break;
			case 6:
				
				printf("\n\n6. BORRAR LISTA");
				
				actual = inicio;
				
				while(actual -> apu_sig != NULL){
					auxiliar = actual -> apu_sig -> apu_sig;
					delete(actual->apu_sig);
					actual -> apu_sig = auxiliar;
				}
				
				delete(actual);
				
				actual = NULL;
				final = NULL;
				auxiliar = NULL;
				inicio = NULL;
				
				printf("\n\n***** LISTA ELIMINADA CORRECTAMENTE *****\n");
				
				break;
			case 7:
				break;
			case 8:
				break;
		}
	}while(op!=7);
	
	
	return 0;
}
