#include "NodoListArr.h"
#include <iostream>
using namespace std;

//Constructor
NodoListArr::NodoListArr(){
	this->usado = 0;
	this->capacidad = capacidad;
	this->nodo = new Nodo();

}

void NodoListArr::eliminarNodos(NodoListArr* nodo){
	if(nodo==nullptr){
		return;
	}
	eliminarNodos(nodo->getNodoIzquierdo());
	eliminarNodos(nodo->getNodoDerecho());
}

//Destructor
NodoListArr::~NodoListArr(){
	
}


//El enUso de cada nodo es la suma del enUso de sus dos hijos
void NodoListArr::setEnUso(int n){
	usado = n;
}

//Retorno de usado
int NodoListArr::getEnUso(){
    return this->usado;
}

//La capacidad es la suma de los tam maximos de sus hijos 
void NodoListArr::setCapacidad(){
	int aux;
	if(nodo->listArrIzq != nullptr){
		aux=nodo->listArrIzq->getTam();
		if(nodo->listArrDer!=nullptr){
			aux= aux+ nodo->listArrDer->getTam();
		}
	}
	this->capacidad =aux;
}

//Retorno de capacidad
int NodoListArr::getCapacidad(){
	return this->capacidad;
}

//retornar arrays
ArrayListArr* NodoListArr::getArrayIzq(){
	cout<<"flag1 getArrayIzq en NodoListArr.cpp"<<endl;
	if(nodo->listArrIzq==nullptr){
		cout<<"flag2 metodo getArrayIzq en NodoListArr.cpp"<<endl;
	}
	cout<<"flag3 metodo getArrayIzq en NodoListArr.cpp"<<endl;
	return this->nodo->listArrIzq;
}

ArrayListArr* NodoListArr::getArrayDer(){
	cout<<"flag1 metodo getArrayDer en NodoListArr.cpp"<<endl;
	return this->nodo->listArrDer;
}

void NodoListArr::punterosArray() {}

NodoListArr* NodoListArr::getNodoIzquierdo(){
	return this->nodo->nodoIzq;
}
NodoListArr* NodoListArr::getNodoDerecho(){
	return this->nodo->nodoDer;
}
void NodoListArr::setNodoIzquierdo(NodoListArr* node){
	node->nodo->nodoIzq=new NodoListArr();
}
void NodoListArr::setNodoDerecho(NodoListArr* nodo){
	nodo->nodo->nodoDer=new NodoListArr();
}

void NodoListArr::setArrayIzquierdo(NodoListArr* aux1, ArrayListArr* aux2){
	aux1->nodo->listArrIzq=aux2;
}

void NodoListArr::setArrayDerecho(NodoListArr* aux1, ArrayListArr* aux2){
	aux1->nodo->listArrIzq=aux2;
}