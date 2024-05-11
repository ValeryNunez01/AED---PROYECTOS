#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define NOMBRE_ARCHIVO "conocimiento.csv"
#define MAX 50
#define S 5
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
#include <cstring>
#define MAX 50


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
	
	
	
	
	int *aNew[tamanioArray];
	int tamanos[tamanioArray];
	
	inicio = 0;
	fin = tamano / 2;
	
	aNew[0] = (int*) malloc(fin*sizeof(int));
	
	
	
	
		apu_nodo a[tam];
		
			a[pos] = auxiliar;
*/

struct nodo{
	char sentencia[MAX];
	int *a = NULL;	
};

using namespace std;
typedef nodo * apu_nodo;

int main(int argc, char** argv) {
	
	apu_nodo auxiliar = NULL;
	
	ifstream file;
	file.open("conocimiento.csv");
	string linea;
	char delimitador = ',';
	
	int idNodos[S], idPadres[S];
	string ss[S];
	int cont = 0;
	
	
	// OBTENCION DE INFORMACION
	while(getline(file, linea)){
		
		stringstream stream(linea);
		string idNodo, idPadre, s;
		
		getline(stream, idNodo, delimitador);
		getline(stream, idPadre, delimitador);
		getline(stream, s, delimitador);
		
		istringstream(idNodo) >> idNodos[cont];
		istringstream(idPadre) >> idPadres[cont];
		ss[cont] = s;
		
		cont++;
		
	}
	
	//CREACION Y LLENADO DE ARBOL
	cont = 0;
	int i = 0;
	int tam = 0;
	int ant = 0;
	while(i < S){
		auxiliar = new(nodo);
		auxiliar->a = (int*)malloc(tam*sizeof(int));
		//while(idPadres[cont] == ant){
		//	tam++;
		//}
		i++;
	}
	
	for(int i=0 ; i<5; i++){
		cout<<ss[i]<<" "<<endl;
	}
	
	return 0;
}













