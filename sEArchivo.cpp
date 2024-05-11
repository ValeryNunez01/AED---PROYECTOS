#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>

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
	nodo *a = NULL;	
};

using namespace std;
//typedef nodo * apu_nodo;

int main(int argc, char** argv) {
	
	nodo *auxiliar2 = NULL, *actual = NULL;
	
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
	int tam;
	int ant = 1;
	int pos = 1;
	int posLen = 1;
 	
	
	nodo *auxiliar = new nodo();
	
	char chars[ss[0].length() + 1];
    strcpy(chars, ss[0].c_str());
	strcpy(auxiliar->sentencia, chars);
	
	nodo *raiz = new nodo();
	
	raiz = auxiliar;
	
	while(i < 2){
		
		tam = 0;
		
		while(idPadres[pos] == ant){
			tam++;
			pos++;
		}
		ant = idPadres[pos];
		//cout<<"idPadres:"<<idPadres[pos]<<endl;
		//cout<<"tam: "<<tam<<endl;
		auxiliar->a = (nodo*)malloc(tam*sizeof(nodo));
		
		for(cont=0 ; cont<tam ; cont++){
			nodo *auxiliar2 = new nodo();
			
			char chars[ss[posLen].length() + 1];
    		strcpy(chars, ss[posLen].c_str());
			strcpy(auxiliar2->sentencia, chars);
			
			cout<<"SF "<<idPadres[pos]<<" :"<<auxiliar2->sentencia<<endl;
			auxiliar->a[cont] = *auxiliar2;
			posLen++;
		}
		
		auxiliar = &auxiliar->a[0];
		//auxiliar = auxiliar 

		i++;
	}
	cout<<"hola"<<endl;
	
	cout<<raiz->sentencia<<endl;
	auxiliar = &raiz->a[0];
	cout<<"nivel 1: "<<auxiliar->sentencia<<endl;
	auxiliar = &raiz->a[1];
	cout<<"nivel 1: "<<auxiliar->sentencia<<endl;
	
	auxiliar = &auxiliar->a[0];
	cout<<"S: "<<auxiliar->sentencia<<endl;


	
	return 0;
}













