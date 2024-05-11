#include <iostream>
#include <cstring>
#define MAX 50

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct nodo{
	char sentencia[MAX];
	nodo *apu_der = NULL, * apu_izq = NULL; 
};

typedef nodo *apu_nodo;

int main(int argc, char** argv) {
	
	apu_nodo raiz = NULL, auxiliar = NULL, actual = NULL;
	int res;
	
	//CREACION NODO RAIZ
	raiz = new(nodo);
	strcpy(raiz->sentencia, "¿Al aire libre?");

	//CREACION NODO IZQUIERDO RAIZ
	auxiliar = new(nodo);
	strcpy(auxiliar->sentencia, "Si");
	raiz->apu_izq = auxiliar;
	
	//CREACION NODO DERECHO RAIZ
	auxiliar = new(nodo);
	strcpy(auxiliar -> sentencia, "No");
	raiz -> apu_der = auxiliar;
	
	//CAMBIAMOS ACTUAL A NIVEL DOS LADO IZQUIERDO
	actual = raiz->apu_izq;
	
	//CREAMOS
	auxiliar = new(nodo);
	//
	strcpy(auxiliar->sentencia, "Amigo reciente");
	actual->apu_izq = auxiliar;
	//
	auxiliar->apu_der = NULL;
	actual->apu_izq = auxiliar;
	
	//CAMBIAMOS ACTUAL A NIVEL TRES LADO IZQUIERDO
	actual = actual->apu_izq;
	
	//CREACION DE NODO IZQUIERDO NIVEL 4
	auxiliar = new(nodo);
	strcpy(auxiliar->sentencia, "Si");
	actual->apu_izq = auxiliar;
	//CREACION DE NODO IZQUIERDO NIVEL 4
	auxiliar = new(nodo);
	strcpy(auxiliar->sentencia, "No");
	actual->apu_der = auxiliar;
	
	//CAMBIAMOS A RAIZ LADO DERECHO NIVEL 2
	actual = raiz->apu_der;
	//CREACION NODO IZQUIERDO EN NIVEL 3
	auxiliar = new(nodo);
	strcpy(auxiliar->sentencia, "Amigo reciente");
	actual->apu_izq = auxiliar;
	actual->apu_der = NULL;
	
	//CAMBIO DE NODO ACTUAL A NIVEL 3
	actual = actual->apu_izq;
	
	//CREACION DE NODO IZQUIERDO NIVEL 4
	auxiliar = new(nodo);
	strcpy(auxiliar->sentencia, "Si");
	actual->apu_izq = auxiliar;
	
	//CREACION DE NODO DERECHO NIVEL 4
	auxiliar = new(nodo);
	strcpy(auxiliar->sentencia, "No");
	actual->apu_der = auxiliar;
	

	
		//fflush
		//strcpy

	printf("\n----Ingresa el numero de la opcion a elegir---\n");
	printf("%s", raiz->sentencia);
	
	auxiliar = raiz;
	
	while(auxiliar->apu_der != NULL || auxiliar->apu_izq != NULL){
		
		if(auxiliar->apu_izq != NULL && auxiliar->apu_der != NULL){
			
			printf("OPCION:\n 1. %s\n2. %s\n", auxiliar->apu_izq->sentencia, auxiliar->apu_der->sentencia);
			scanf("%d", &res);
			if(res == 1){
				auxiliar = auxiliar->apu_izq;
			}else{
				auxiliar = auxiliar->apu_der;
			}	
		}else if(auxiliar->apu_izq != NULL && auxiliar->apu_der == NULL){
			
			printf("OPCION:\n 1. %s\n\n", auxiliar->apu_izq->sentencia);
			scanf("%d", res);
			
			auxiliar = auxiliar->apu_izq;
		
		}else if(auxiliar->apu_izq != NULL && auxiliar->apu_der == NULL){
			
			printf("OPCION:\n 1. %s\n", auxiliar->apu_der->sentencia);
			scanf("%d", res);
			
			auxiliar = auxiliar->apu_der;
		}
		
	}
	
	
	
	return 0;
}
