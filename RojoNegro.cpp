#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct nodo{
	char color;
	nodo *apu_l, *apu_r;
	nodo *padre;
	int valor;
};

typedef nodo *apu_nodo;

apu_nodo rotacionDerecha(apu_nodo actual){
	apu_nodo aux = actual->apu_l;
	actual->apu_l = aux->apu_r;
	aux->apu_r->padre = actual;
	aux->apu_r = actuaL;
	aux->padre = actual->padre;
	
	return aux;
}

apu_nodo rotacionIzquierda(apu_nodo actual){
	apu_nodo aux = actual->apu_r;
	actual->apu_r = aux->apu_l;
	aux->apu_l->padre = actual;
	aux->apu_l = actual;
	aux->padre = actual->padre;
	
	return aux;
}

void asignarColor(apu_nodo actual){
	if(padre = NULL){
		actual->color = 'N';
	}elseif(!actual->apu_l && !actual->apu_r){
		actual->color = 'N';	
	}elseif(actual->apu_l != NULL || actual->apu_r != NULL){
		if(actual->apu_l->color == 'N'){
			
		}else{
			
		}
	}
}


apu_nodo obtenerAbuelo(apu_nodo aux){
	if(aux != NULL){
		if(aux->padre != NULL)
			return aux->padre->padre;
	}
	return NULL;
}

apu_nodo obtenerTio(apu_nodo aux){
	apu_nodo aux_abuelo = obtenerAbuelo(aux);
	
	if(aux_abuelo != NULL){
		if(aux == aux_abuelo->apu_l)
			return aux_abuelo->apu_r;
		else
			return aux_abuelo->apu_l
	}
	return NULL;
}

apu_nodo crearNodo(int valor, char color, apu_nodo padre){
	apu_nodo aux = new(nodo);
	
	aux->valor = valor;
	aux->color = color;
	
	aux->apu_l = NULL;
	aux->apu_r = NULL;
	
	aux->padre = padre;
	return aux;
}

 insertarNodo(){
	
}

int main(int argc, char** argv) {
	
	apu_nodo raiz = NULL;
	int op, valor;
	
	cout<<"Menu:\n1. Insertar\n2. Buscar\n3. Eliminar\n4. Salir"<<endl;
	cin>>op;
	switch(op){
		
		case 1:
			
			cout<<"Valor: ";
			cin>>valor;
			if(raiz == NULL)
				raiz = crearNodo(valor, 'N', NULL);
			else
				 insertarNodo(valor);
			
			break;
			
		case 2:
			buscarNodo();
			break;
		case 3:
			eliminarNodo();
			break;
			
		default:
			
	}
	
	return 0;
}


insertarNodo(){
	
}

