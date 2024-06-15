#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nodo{
	int value;
	nodo *apu_der = NULL, *apu_izq = NULL, *padre = NULL;	
};

typedef nodo *apu_nodo;

void insertarNodo(apu_nodo actual, apu_nodo aux){
	
	if(actual != NULL){
		//printf("%i", actual->value);
		if(actual->value < aux->value){
			if(actual->apu_der == NULL){
				actual->apu_der = aux;
				aux->padre = actual;
			}else{
				actual = actual->apu_der;
				insertarNodo(actual, aux);
			}
		}else{
			if(actual->apu_izq == NULL){
				actual->apu_izq = aux;
				aux->padre = actual;
			}else{
				actual = actual->apu_izq;
				insertarNodo(actual, aux);
			}
		}
	}
}
/*
void imprimirPorNivel(apu_nodo actual){
	if(actual != NULL){
		printf("%i\n", actual);
		if(actual->apu_izq != NULL && apu_izq != NULL){
			printf("%i\n", actual->apu_izq);	
		}else
	}
}*/

void verArbol(apu_nodo arbol, int cont){
    if(arbol!=NULL){
    	
    	verArbol(arbol->apu_der, cont+1);
    	for(int i=0 ; i<cont ; i++){
    		printf("   ");
		}	
    	printf("%i\n", arbol->value);
    	verArbol(arbol->apu_izq, cont+1);
    }
}

apu_nodo casoUno(apu_nodo auxiliar){
	if(auxiliar == NULL){
		return NULL;
	}
	if(auxiliar->apu_izq != NULL){
		return casoUno(auxiliar->apu_izq);
	}else{
		return auxiliar;
	}
}

void destruirNodo(apu_nodo nodo){
	nodo->apu_izq = NULL;
	nodo->apu_der = NULL;
	
	delete nodo;
}

void casoDos(apu_nodo auxiliar, apu_nodo reemplazo){
	if(auxiliar->padre != NULL){
		if(auxiliar->value == auxiliar->padre->apu_izq->value){
			auxiliar->padre->apu_izq = reemplazo;
		}else if(auxiliar->value == auxiliar->padre->apu_der->value){
			auxiliar->padre->apu_der = reemplazo;
		}
	}
	if(reemplazo != NULL){
		reemplazo->padre = auxiliar->padre;
	}
}

void eliminarNodo(apu_nodo nodoNoDeseado){
	if(nodoNoDeseado->apu_der != NULL && nodoNoDeseado->apu_izq != NULL){
		apu_nodo suplente = casoUno(nodoNoDeseado->apu_der);
		nodoNoDeseado->value = suplente->value;
		eliminarNodo(suplente);
	}else if(nodoNoDeseado->apu_izq != NULL){
		casoDos(nodoNoDeseado, nodoNoDeseado->apu_izq);
		destruirNodo(nodoNoDeseado);
	}else if(nodoNoDeseado->apu_der != NULL){
		casoDos(nodoNoDeseado, nodoNoDeseado->apu_der);
		destruirNodo(nodoNoDeseado);
	}else{
		casoDos(nodoNoDeseado, NULL);
		destruirNodo(nodoNoDeseado);
	}	
}

void eliminar(apu_nodo auxiliar, int n){
	if(auxiliar == NULL){
		return;
	}else if(n < auxiliar->value){
		eliminar(auxiliar->apu_izq, n);
	}else if(n > auxiliar->value){
		eliminar(auxiliar->apu_der, n);
	}else{
		eliminarNodo(auxiliar);
	}
}

int main(int argc, char** argv) {
	
	apu_nodo raiz = NULL, actual = NULL, auxiliar = NULL;
	int num, op;
	
	do{
		
		printf("Elija una opcion: \n 1. Insertar Nodo\n 2. Eliminar hoja\n 3. Imprimir\n 4. Salir\nOpcion: ");
		scanf("%i", &op);
		
		switch(op){
			case 1:
				
				printf("Numero a insertar: ");
				scanf("%i", &num);
				
				auxiliar = new(nodo);
				auxiliar->value = num;
				
				if(raiz == NULL){
					raiz = auxiliar;
				}else{
					insertarNodo(raiz, auxiliar);
				}
				
				break;
			case 2:
				printf("Numero a eliminar: ");
				scanf("%i", &num);
				eliminar(raiz, num);
				break;
			case 3:
				
				if(raiz == NULL){
					printf("No hay elementos para mostrar :()\n");
				}else{
					verArbol(raiz, 0);	
				}

				break;
				
			default:
				printf("Opcion invalida");
		}
		
	}while(op != 4);

	
	//Insertar nodo

	
	return 0;
}

