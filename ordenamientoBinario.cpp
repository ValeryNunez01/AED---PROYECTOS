#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int tam, num;
	int final, inicio, actual;
	bool estado = false;
	
	printf("Tamano del arreglo: ");
	scanf("%d", &tam);	
	
	int a[8];
	
	printf("\nLLENADO DE ARREGLO: \n");

	for(int i=0 ; i<tam ; i++){
		printf("Elemento %d: ", i);
		scanf("%d", &num);
		
		for(int j=0 ; j<i ; j++){
			if(num == a[j]){
				printf("\n\nNUMERO REPETIDO, INGRESA OTRO\n\n");
				printf("\nElemento %d: ", i);
				scanf("%d", &num);
				j=-1;
			}
		}
		a[i] = num;
	}			
	
	printf("\nARREGLO INGRESADO: \n");
	for(int i=0 ; i<tam ; i++){
		printf("%d  ", a[i]);
	}
	
	int aux;
	
	for(int j=0 ; j<tam ; j++){
		for(int i=0 ; i<tam-1 ; i++){
			if(a[i] > a[i+1]){
				aux = a[i+1];
				a[i+1] = a[i];
				a[i] = aux;
			}
		}
	}
	
	printf("\nARREGLO ORDENADO: \n");
	for(int i=0 ; i<tam ; i++){
		printf("%d  ", a[i]);
	}
		

	//int a[8] = {-15, 0 , 2, 7, 34, 45, 47, 50};
	
	printf("\n\nNumero buscado: ");
	scanf("%d", &num);
	
	final = tam - 1;
	inicio = 0;
	
	while(inicio <= final){
		
		actual = (final+inicio)/2;
		
		if(a[actual] < num){
			inicio = actual + 1;
		}else if(a[actual] > num){
			final = actual - 1;
		}else if(a[actual] == num){
			estado = true;
			break;
		}
	}
	
	if(estado == true){
		printf("\n\nNUMERO %d ENCONTRADO", num);
	}else{	
		printf("\n\nNUMERO %d NO ENCONTRADO", num);
	}
	return 0;
}
