//AUTORA: Núñez Ramírez Valery Aylin

#include <iostream>
#include <time.h>
#include <stdlib.h>

struct nodo{
	int valor;
	nodo *apu_sig, *apu_ant;
};
	
typedef nodo *apu_nodo;

int main(int argc, char** argv) {
	
	srand (time(NULL)); 
	
	int tam, n, res, pos;
	int cont = 0;
	apu_nodo inicio = NULL, actual = NULL, auxiliar = NULL, final = NULL;
		
	printf("\nTamano del arreglo: ");
	scanf("%d", &tam);
	
	apu_nodo a[tam];
	int num[tam];
	
	while(cont < tam){
		a[cont] = NULL;
		cont++;
	}
	
	//GENERACION DE NUMEROS ALEATORIOS
	
	cont = 0;
	
	while(cont < tam){
		n = rand() % 21;
		
		for(int i=0 ; i<cont ; i++){
			if(n == num[i]){
				n = rand() % 21;
				i=0;
			}
		}
		num[cont] = n;
		cont++;
	}
	
	printf("\n\nARREGLO DE NUMEROS ALEATORIOS\n\n");
		
	for(int i=0 ; i<tam ; i++){
		printf("%d  ", num[i]);
	}	

	cont = 0;
	
	while(cont < tam){
		
		pos = num[cont] % tam;
		
		auxiliar = new(nodo);
		auxiliar -> valor = num[cont];
				
		if(a[pos] == NULL){
			
			a[pos] = auxiliar;
			
			auxiliar -> apu_sig = NULL;
			auxiliar -> apu_ant = NULL;
			inicio = auxiliar;
			actual = inicio;
			
		}else{
			actual = a[pos];
			while(actual -> apu_sig != NULL){
				actual = actual -> apu_sig;
			}
			auxiliar -> apu_sig = NULL;
			auxiliar -> apu_ant = actual;
			actual -> apu_sig = auxiliar;
		}

		cont++;

	}
	
	//IMPRESION

	printf("\nDATOS INGRESADOS\n");
	
	for(int i=0 ; i<tam ; i++){
		printf("\n[%d] -> ", i);
	
		if(a[i] != NULL){
			auxiliar = a[i];
			
			while(auxiliar != NULL){
				printf("%d ", auxiliar -> valor);
				auxiliar = auxiliar -> apu_sig;	
			}
			
		}

	}
	
	//BUSQUEDA
	
	res = 0;
	
	while(res == 0){
		
		cont = 0;
		
		printf("\n\nNumero buscado: ");
		scanf("%d", &n);
		
		pos = n % tam;
		
		auxiliar = a[pos];
		
		while(auxiliar != NULL){
			if(auxiliar -> valor == n){
				cont = 1;
			}
			
			auxiliar = auxiliar -> apu_sig;	
		}
		
		if(cont != 1){
			printf("\n\nNUMERO NO ENCONTRADO");
		}else{
			printf("\n\nNUMERO ENCONTRADO");
		} 
		
		printf("\nSi desea buscrar otro escriba 0: ");
		scanf("%d", &res);
	}
	
	return 0;
}
