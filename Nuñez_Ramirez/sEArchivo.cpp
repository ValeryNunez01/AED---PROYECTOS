//AUTORA: NÚÑEZ RAMÍREZ VALERY AYLIN
 
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>

#define NOMBRE_ARCHIVO "conocimiento.csv"
#define MAX 50
#define S 67

struct nodo{
	char sentencia[MAX];
	nodo *a = NULL;	
};

using namespace std;

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
		string idNodo, idPadre, nivel, s;
		
		getline(stream, idNodo, delimitador);
		getline(stream, idPadre, delimitador);
		getline(stream, s, delimitador);
		
		istringstream(idNodo) >> idNodos[cont];
		istringstream(idPadre) >> idPadres[cont];
		ss[cont] = s;
		
		cont++;
		
	}
	
	//CREACION Y LLENADO DE ARBOL
	//cont = 0;
	int i = 0;
	int tam;
	int ant = 1;
	int pos = 1;
	//int posLen = 1;
	//int n = 2;
 	
	
	nodo *auxiliar;
	nodo *raiz = new nodo();
	nodo *nodos;
	nodos = (nodo*)malloc(S*sizeof(nodo));
	
	//LLENADO DE ARREGLO DE NODOS
	while(i < S){
		
		auxiliar = new nodo();
	
		char chars[ss[i].length() + 1];
	    strcpy(chars, ss[i].c_str());
		strcpy(auxiliar->sentencia, chars);
	
		tam = 0;
		
		while(idPadres[pos] == ant){
			tam++;
			pos++;
		}
		
		ant = idPadres[pos];
		auxiliar->a = (nodo*)malloc(tam*sizeof(nodo));
		nodos[i] = *auxiliar;
		i++;
	}
	
	raiz = &nodos[0];
	
	auxiliar = new nodo();
	
	i = 1;
	pos = 1;
	int j;
	int veces = 0;
	int p = 0;
	int hijos = 1;
	int poss = 0;
	
	while(veces < S){
	
		tam = 0;
		
		while(idPadres[i] == p){
			tam++;
			i++;
		}
		
		p = idPadres[i];
		
		for(j=0 ; j<tam ; j++){
			auxiliar  = &nodos[poss];
			auxiliar->a[j] = nodos[hijos];
			hijos++;
		}
		
		poss = idPadres[i];
		veces = i;
	
	}
	
	cout<<raiz->sentencia<<endl;
	auxiliar = &raiz->a[0];
	cout<<"nivel 1: "<<auxiliar->sentencia<<endl;
	auxiliar = &raiz->a[0];
	auxiliar = &auxiliar->a[0];
	cout<<"nivel 2: "<<auxiliar->sentencia<<endl;
	
	return 0;
}


/*

0,-1,¿A donde ir?
1,0,Patos
2,0,Gatos
3,1,Patitos con pelos
4,2,Gatitos

*/












