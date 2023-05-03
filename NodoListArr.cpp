#include "NodoListArr.h"

//Constructor
NodoListArr::NodoListArr(){
	this->usado = 0;
	this->capacidad = 0;
	this->nodo = nullptr;
}

//Destructor
NodoListArr::~NodoListArr(){
	
}


//El enUso de cada nodo es la suma del enUso de sus dos hijos
void NodoListArr::setEnUso(){
	this->usado = nodo->listArrIzq->getUsado() + nodo->listArrDer->getUsado();
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

void NodoListArr::punterosArray() {}

