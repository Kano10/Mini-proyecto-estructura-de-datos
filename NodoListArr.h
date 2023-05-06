#ifndef NODOLISTARR_H
#define NODOLISTARR_H

#include "ArrayListArr.h"

class NodoListArr{
private:
	struct Nodo{
		NodoListArr* nodoIzq;//puntero al nodo de abajo a la izquierda
		NodoListArr* nodoDer;//puntero al nodo de abajo a la derecha
		ArrayListArr* listArrIzq;//Puntero al array de abajo a la izquierda
		ArrayListArr* listArrDer;//Puntero al array de abajo a la derecha
		
		//ArrayLstArr* array; solo tener un array por nodo
		
		
		Nodo(ArrayListArr* listArrIzq = nullptr, ArrayListArr* listArrDer = nullptr,NodoListArr* nodoIzq = nullptr, NodoListArr* nodoDer = nullptr){
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
	~NodoListArr();
	void setEnUso(int n, NodoListArr* nodo);//Para definir cuantos espacios se están usando
	int getEnUso();//Para saber cuantos están en uso
	void setCapacidad();//Para definir la capacidad total
	int getCapacidad();//Para saber la capacidad
	void punterosArray();//define los punteros a los arrays de abajo
	NodoListArr* getNodoIzquierdo(NodoListArr * nodo);
	NodoListArr* getNodoDerecho(NodoListArr* nodo);
	//ArrayListArr* getArray(); retornar el array cuando se necesite modificar
	void setNodoIzquierdo(NodoListArr* nodo);
	void setNodoDerecho(NodoListArr* nodo);
};
#endif

