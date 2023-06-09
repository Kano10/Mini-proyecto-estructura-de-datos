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
		
		
		Nodo(){
			this->listArrIzq = nullptr;
			this->listArrDer = nullptr;
			this->nodoIzq = nullptr;
			this->nodoDer = nullptr;
		}
	};
	int usado;//cuantos numeros se han usado debajo de ese nodo
	int capacidad;//la capacidad abajo del nodo
	Nodo* nodo;

public:
	NodoListArr();
	~NodoListArr();
	void eliminarNodos(NodoListArr* nodo);
	void setEnUso(int n);//Para definir cuantos espacios se están usando
	int getEnUso();//Para saber cuantos están en uso
	void setCapacidad();//Para definir la capacidad total
	int getCapacidad();//Para saber la capacidad
	void punterosArray();//define los punteros a los arrays de abajo
	NodoListArr* getNodoIzquierdo();
	NodoListArr* getNodoDerecho();
	ArrayListArr* getArrayIzq();
	ArrayListArr* getArrayDer();
	void setNodoIzquierdo(NodoListArr* node);
	void setNodoDerecho(NodoListArr* nodo);
	void setArrayIzquierdo(NodoListArr* aux1, ArrayListArr* aux2);
	void setArrayDerecho(NodoListArr* aux1, ArrayListArr* aux2);
};
#endif
