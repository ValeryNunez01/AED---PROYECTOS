//AUTORA : Nuñez Ramirez Valery Aylin
#include <iostream>

struct nodo{
	int valor;
	nodo *apu_ant;
};

//Una estructura de colas sólo tiene un apu_nodo de tipo anterior y auxiliar.
//Cuando muestra, unicamente muesrtra el nodo final
//Cuando inserta unicamente puede insertar al inicio, nunca al final ni en medio.
//Extraer nodo significa borrar nocdo, pero sólo puede borrar el primer nodo.
//NO HAY CICLOS DENTRO DE LA ESTRUCTURA


typedef nodo *apu_nodo;
int main(int argc, char** argv) {
	
	printf("ESTRUCTURA DE COLAS");
	
	apu_nodo entrada = NULL, salida = NULL, auxiliar = NULL;
	int op, value;
	
	
	do{
		printf("\n\nMENU: \n1. AGREGAR NODO\n2. MOSTRAR NODO\n3. EXTRAER NODO \n4. SALIR\n\nOpcion: ");
		scanf("%i", &op);
				
		switch(op){
		
			case 1:
				
				//Insertar nodo  
				
				printf("\n\n*********** AGREGAR NODO ***********\n");
				printf("\nValor a insertar: ");
				scanf("%i", &value);
			
				auxiliar = new(nodo);
				auxiliar -> valor = value;
				auxiliar -> apu_ant = NULL;
				
				if(auxiliar == NULL){
					
				}else{
					if(salida == NULL){
						salida = auxiliar;
					}else{
						entrada -> apu_ant = auxiliar;
					}
					entrada = auxiliar;	
					
					printf("NODO INSERTADO CON EXITO :)");
				}
				
				break;
			
			case 2:
				
				//Mostrar nodo
				
				printf("\n\n*********** MOSTRAR NODO ***********\n");
				if(salida == NULL){
					printf("PILA VACIA, NADA QUE MOSTRAR");
				}else{
					printf("\nVALOR: %d", salida -> valor);
				}
				
				break;
				
			case 3:
				
				//Extraer nodo
				
				printf("\n\n*********** EXTRAER NODO ***********\n");
				if(salida == NULL){
					printf("PILA VACIA, NADA QUE ELIMINAR");
				}else{
					auxiliar = salida -> apu_ant;
					delete(salida);
					salida = auxiliar;
					printf("NODO EXRAIDO CON EXITO :)");
				}
				
				break;
				
			case 4:
				
				printf("\n\n*********** USTED HA SALIDO DEL MENU :) ***********\n");
				
				break;
				
				
		}
	}while(op != 4);

	
	return 0;
}


