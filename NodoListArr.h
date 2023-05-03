#ifndef NODOLISTARR_H
#define NODOLISTARR_H

#include "ArrayListArr.h"

class NodoListArr{
private:
	struct Nodo{
		
		Nodo* nodoIzq;//puntero al nodo de abajo a la izquierda
		Nodo* nodoDer;//puntero al nodo de abajo a la derecha
		ArrayListArr* listArrIzq;//Puntero al array de abajo a la izquierda
		ArrayListArr* listArrDer;//Puntero al array de abajo a la derecha
		Nodo(ArrayListArr* listArrIzq = nullptr, ArrayListArr* listArrDer = nullptr,Nodo* nodoIzq = nullptr, Nodo* nodoDer = nullptr){
			this->listArrIzq = listArrIzq;
			this->listArrDer = listArrDer;
			this->nodoIzq = nodoIzq;
			this->nodoDer = nodoDer;
		}
	};
	int usado;//cuantos numeros se han usado debajo de ese nodo
	int capacidad;//la capacidad abajo del nodo
	Nodo* nodo;

public:
	NodoListArr();
	virtual ~NodoListArr();
	virtual void setEnUso();//Para definir cuantos espacios se están usando
	virtual int getEnUso();//Para saber cuantos están en uso
	virtual void setCapacidad();//Para definir la capacidad total
	virtual int getCapacidad();//Para saber la capacidad
	virtual void punterosArray();//define los punteros a los arrays de abajo

};
#endif

