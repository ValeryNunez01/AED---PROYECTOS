#include <iostream>

struct nodo{
	int valor;
	nodo *apu_sig, *apu_ant;
};

typedef nodo *apu_nodo;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	apu_nodo inicio = NULL, actual = NULL, auxiliar = NULL, final = NULL, middle = NULL;
	int op, value;
	
	
	do{
		printf("Opcion: ");
		scanf("%i", &op);
				
		switch(op){
		
			case 1:
				//Insertar final: 
				printf("\n\n*********** INSERTAR FINAL ***********\n");
				printf("\nValor a insertar: ");
				scanf("%i", &value);
			
				auxiliar = new(nodo);
				auxiliar -> valor = value;
				
				if(inicio == NULL){
					auxiliar -> apu_sig = NULL;
					auxiliar -> apu_ant = NULL;
					inicio = auxiliar;
					actual = inicio;
					middle = inicio;
					final = inicio;
				}else{
					auxiliar -> apu_sig = NULL;
					auxiliar -> apu_ant = actual;
					actual -> apu_sig = auxiliar;
					actual = auxiliar;
				}
				
				printf("\n\n-------------- VALOR INSERTADO CORRECTAMENTE --------------\n");
				
				break;
				
			case 2:
				
				//Insertar inicio;
				printf("\n\n*********** INSERTAR INICIO ***********\n");
				printf("\nValor a insertar: ");
				scanf("%i", &value);
			
				auxiliar = new(nodo);
				auxiliar -> valor = value;
				
				if(inicio == NULL){
					auxiliar -> apu_sig = NULL;
					auxiliar -> apu_ant = NULL;
					inicio = auxiliar;
					actual = inicio;
					middle = inicio;
					final = inicio;
				}else{
					auxiliar -> apu_sig = inicio;
					auxiliar -> apu_ant = NULL;
					inicio -> apu_ant = auxiliar;
					inicio = auxiliar;
				}
				
				printf("\n\n-------------- VALOR INSERTADO CORRECTAMENTE --------------\n");
				//4 MUSLOS DOS PIERNAS Y EL APLANADO
				break;
			case 3:
				//Insertar segun valor
				printf("\n\n*********** INSERTAR DE MENOR A MAYOR ***********\n");
				printf("\nValor a insertar: ");
				printf("Valor: ");
				scanf("%i", &value);
				
				auxiliar = new(nodo);
				auxiliar -> valor = value;
				
				final = actual;
				actual = inicio;
				
				if(final -> valor >= value){
					auxiliar -> apu_sig = NULL;
					auxiliar -> apu_ant = final;
					final -> apu_sig = auxiliar;
					final = auxiliar;
				}else if(inicio -> valor <= value){
					auxiliar -> apu_sig = inicio;
					auxiliar -> apu_ant = NULL;
					inicio -> apu_ant = auxiliar;
					inicio = auxiliar;
				}else{
					
					while(actual -> apu_sig != NULL){
						if(actual -> valor >= value && actual -> apu_sig -> valor <= value){
							auxiliar -> apu_ant = actual;
							auxiliar -> apu_sig = actual -> apu_sig;
							actual -> apu_sig -> apu_ant = auxiliar;
							actual -> apu_sig = auxiliar;
							
							actual = final;
						}else{
							actual = actual -> apu_sig;
						}
					}
				}
							
				actual = final;
				
				printf("\n\n------ VALOR INSERTADO CORRECTAMENTE ------\n");
				
				break;
				
			case 4:
				
				//Borrar nodo
				//ACTUAL FINAL MIDDLE INICIO
				printf("\n\n*********** BORRAR NODO ***********\n");
				printf("\nValor a borrar: ");
				scanf("%i", &value);
				
				actual = inicio;
				
				if(actual == NULL){
					printf("\n\n------ LA LISTA ESTA VACIA ------\n");
				}else{
					if(actual -> valor == value){
						inicio = actual -> apu_sig;
						delete(actual);
						printf("\n\n------ VALOR ELIMINADO CORRECTAMENTE ------\n");
					}else if(actual != NULL){
						while(actual -> apu_sig != NULL && actual -> apu_sig -> valor != value){
							actual = actual -> apu_sig;
						}
						
						if(actual -> apu_sig == NULL){
							printf("\n\n------ VALOR NO ENCONTRADO ------\n");
						}else{
							actual -> apu_sig -> apu_ant = actual;
							auxiliar = actual -> apu_sig -> apu_sig;
							delete(actual -> apu_sig);
							actual -> apu_sig = auxiliar;
							printf("\n\n------ VALOR ELIMINADO CORRECTAMENTE ------\n");
						}
					}
				}
				
				
				actual = inicio;		
				
				while(actual -> apu_sig != NULL){
					actual = actual -> apu_sig;
				}
				
				final = actual;	
				
				actual = inicio;
				
				while(actual -> apu_sig != NULL && actual -> apu_sig -> valor % 2 != 0){
					actual = actual -> apu_sig;
				}
				
				middle = actual;
				
				actual = final;
				
				
				break;
				
			case 5:
				//Insertar según par o impar
				printf("\n\n*********** INSERTAR SEGUN PAR O IMPAR ***********\n");
				printf("\nValor a insertar: ");
				scanf("%i", &value);
				
				auxiliar = new(nodo);
				auxiliar -> valor = value;
				
				if(inicio == NULL){
					auxiliar -> apu_sig = NULL;
					auxiliar -> apu_ant = NULL;
					inicio = auxiliar;
					actual = inicio;
					middle = inicio;
					final = inicio;
				}else{
					//IMPAR PAR PAR CHECKED
					//PAR PAR IMPAR
					//PAR IMPAR 
					
					
					/*
					
					if(value < middle -> valor || value < middle -> apu_sig -> valor){
						printf("HOLA 2");
						auxiliar -> apu_sig = middle -> apu_sig;
						auxiliar -> apu_ant = middle;
						middle -> apu_sig = auxiliar;
						middle = auxiliar;
					}else 
					
					
					*/
					
					if(value%2 != 0){
						
						if((inicio -> valor % 2 == 0) || (inicio -> valor <= value && inicio -> valor%2 != 0)){
							auxiliar -> apu_sig = inicio;
							auxiliar -> apu_ant = NULL;
							inicio -> apu_ant = auxiliar;
							inicio = auxiliar;
						}else{
							actual = middle;
							
							while(actual != NULL && actual -> apu_ant -> valor <= value){
								actual = actual -> apu_ant;
							}
							
							auxiliar -> apu_sig = actual;
							auxiliar -> apu_ant = actual -> apu_ant;
							actual -> apu_ant -> apu_sig = auxiliar;
							actual -> apu_ant = auxiliar;
							
							actual = final;
						}
												
					}else{
						
						if((final -> valor % 2 != 0) || (final -> valor %2 == 0 && final -> valor <= value)){
							auxiliar -> apu_sig = NULL;
							auxiliar -> apu_ant = final;
							final -> apu_sig = auxiliar;
							final = auxiliar;
							actual = final;
						}else{
							final = actual;
							actual = middle;
							
							while(actual != NULL && actual -> apu_sig -> valor <= value){
								actual = actual -> apu_sig;
							}
							
							auxiliar -> apu_sig = actual -> apu_sig;
							auxiliar -> apu_ant = actual;
							actual -> apu_sig -> apu_ant = auxiliar;
							actual -> apu_sig = auxiliar;
							
							actual = final;
						}	
						
					}
					
					
				}
				
				printf("\n\n---------- VALOR INSERTADO CORRECTAMENTE ----------\n");
				
				
				
				break;
				
			case 6:
				
				//Mostrar lista
				
				printf("\n\n*********** MOSTRAR LISTA ***********\n");
				
				final = actual;
				actual = inicio;
				
				while(actual != NULL){
					printf("\nValor = %i\n", actual -> valor);
					actual = actual -> apu_sig;
				}
				
				actual = final;
				
				break;
			
			case 7:
				
				printf("\n\n*********** BORRAR LISTA ***********\n");
				
				actual = inicio;
				
				while(actual -> apu_sig != NULL){
					
					auxiliar = actual -> apu_sig -> apu_sig;
					//actual -> apu_sig -> apu_sig -> apu_ant = actual;
					//final = actual -> apu_sig;
					delete(actual -> apu_sig);
					actual -> apu_sig = auxiliar;
					
				}
				
				delete(actual);
				
				actual = NULL;
				final = NULL;
				inicio = NULL;
				middle = NULL;
				auxiliar = NULL;
				
				printf("\n\n---------- LISTA ELIMINADA CORRECTAMENTE ----------\n");
				
				break;
		}
		
	}while(op != 8);
	
	return 0;
}


/*
	Insertar final: 
	
	auxiliar = new(nodo);
	auxiliar -> valor = 5;
	auxiliar -> apu_sig = inicio;
	incio -> apu_ant = auxiliar;
	inicio = auxiliar;
	incio -> apu_ant = NULL;
	
	*/
	
	/*
	Insertar en medio:
	
	auxiliar = new(nodo);
	auxilliar -> valor = 15;
	auxiliar -> apu_sig = actual->apu_sig;
	auxliar -> apu_ant = actual;
	actual -> apu_sig -> apu_ant = auxiliar;
	actual -> apu_sig = auxiliar;
	
	*/
	
	/*
	Borrar el nodo INCIO:
	
	auxiliar = incio;
	inicio = inicio -> apu_sig;
	inicio -> apu_ant = NULL;
	delete(auxiliar);
	auxiliar = NULL;
	
	*/
	
	/*
	Borrar el nodo de en medio:
	
	actual -> apu_sig -> apu_sig -> apu_ant = actual;
	actual -> apu_sig = actual -> apu_sig -> apu_sig;
	auxiliar = actual -> apu_sig;
	delete(auxiliar);
	
	*/
	
	/*
	mayor a menor.
	auxiliar = new(nodo);
	40
	
	*/
	
