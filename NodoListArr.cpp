#include "NodoListArr.h"

//Constructor
NodoListArr::NodoListArr(){
	this->usado = 0;
	this->capacidad = 0;
	this->nodo = nullptr;
}

void NodoListArr::eliminarNodos(NodoListArr* nodo){
	if(nodo==nullptr){
		return;
	}
	eliminarNodos(nodo->getNodoIzquierdo(nodo));
	eliminarNodos(nodo->getNodoDerecho(nodo));
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
	this->capacidad = nodo->listArrIzq->getTam() + nodo->listArrDer->getTam();
}

//Retorno de capacidad
int NodoListArr::getCapacidad(){
	return this->capacidad;
}

/* retornar array
ArrayListArr NodoListArr::getArray(){
	return this->array;
}
*/

void NodoListArr::punterosArray() {}

NodoListArr* NodoListArr::getNodoIzquierdo(NodoListArr* nodo){
	return nodo->nodo->nodoIzq;
}
NodoListArr* NodoListArr::getNodoDerecho(NodoListArr* nodo){
	return nodo->nodo->nodoDer;
}
void NodoListArr::setNodoIzquierdo(NodoListArr* nodo){
	nodo->nodo->nodoIzq=new NodoListArr();
}
void NodoListArr::setNodoDerecho(NodoListArr* nodo){
	nodo->nodo->nodoDer=new NodoListArr();
}
