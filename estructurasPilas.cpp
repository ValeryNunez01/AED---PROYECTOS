//AUTORA : Nuñez Ramirez Valery Aylin

#include <iostream>

struct nodo{
	int valor;
	nodo *apu_ant;
};

//Una estructura de pila básicameente es la misma idea que una estructura de colas con la diferencia de que entrada y salida es prácticamente la misma cosa
//Lo anterior facilita la idea de podeer ocupar una sola varibale para referisnos a estas dos últimas, la cual nombraremos como tope.

//Si nosotro queremos mostrar o extraer algun nodo, este siempre extraerá o mostrará el último nodo agregado a la estructura. Por otro lado 
// si nosotros queremos insertar algun nodo este lo insertará después del ultimo nodo insertado.



///TAREA: HACER LAS VALIDACIONES DE SI SE AGREGÓ O NO NUESTRO NODO(QUE ES PARA EL CASO DE QUE YA NO QUEDA ESPACIO EN LA MEMORIA Y PUES SE DECIDIDE NO )

typedef nodo *apu_nodo;
int main(int argc, char** argv) {

	printf("ESTRUCTURA DE PILAS");	
	
	apu_nodo tope = NULL, auxiliar = NULL;
	int op, value;
	
	
	do{
		printf("\n\nMENU: \n1. AGREGAR NODO\n2. MOSTRAR NODO\n3. EXTRAER NODO \n4. SALIR\n\nOpcion: ");
		scanf("%i", &op);
				
		switch(op){
		
			case 1:
				
				/*
Insercion con validacion

axiliar = new(nodo);

if(auxiliar == NULL){
	printf("NO SE PUDO AGREGAR");
}else{
	auxiliar -> valor = value;
	auxiliar -> apu_ant = tope;
	tope = auxiliar;
}
*/
				
				//Insertar nodo  
				
				printf("\n\n*********** AGREGAR NODO ***********\n");
				printf("\nValor a insertar: ");
				scanf("%i", &value);
			
				auxiliar = new(nodo);
				auxiliar -> valor = value;
				auxiliar -> apu_ant = NULL;
				
				if(auxiliar == NULL){
					printf("MEMORIA LLENA, NO SE PUDO INSERTAR");
				}else{
					auxiliar -> apu_ant = tope;
					tope = auxiliar;
					printf("NODO INSERTADO CON EXITO :)");
				}
				
				
				
				break;
			
			case 2:
				
				//MOSTRAR TOPE
				printf("\n\n*********** MOSTRAR NODO ***********\n");
				if(tope == NULL){
					printf("PILA VACIA, NADA QUE MOSTRAR");
				}else{
					printf("\nVALOR = %d", tope -> valor);
				}
				
				break;
				
			case 3:
				
				//Extraer nodo
				
				printf("\n\n*********** EXTRAER NODO ***********\n");
				
				if(tope == NULL){
					printf("PILA VACIA, NADA QUE ELIMINAR");
				}else{
					auxiliar = tope -> apu_ant;
					delete(tope);
					tope = auxiliar;
				}
				
				printf("NODO EXRAIDO CON EXITO :)");
				
				break;
				
			case 4:
				
				printf("\n\n*********** USTED HA SALIDO DEL MENU :) ***********\n");
				
				break;
				
				
		}
	}while(op != 4);

	
	return 0;
}
