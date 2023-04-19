#include "ArrayListArr.h"

class NodoListArr{
private:
	struct Nodo{
		int usado;//cuantos numeros se han usado debajo de ese nodo
		int capacidad;//la capacidad abajo del nodo
		Nodo* nodoIzq;//puntero al nodo de abajo a la izquierda
		Nodo* nodoDer;//puntero al nodo de abajo a la derecha
		ArrayListArr* listArrIzq;//Puntero al array de abajo a la izquierda
		ArrayListArr* listArrDer;//Puntero al array de abajo a la derecha
		ArrayListArr(ArrayListArr* listArrIzq = nullptr, ArrayListArr* listArrIzq = nullptr,Nodo* nodoIzq = nullptr, Nodo* nodoDer = nullptr){
			this.listArrIzq = listArrIzq;
			this.listArrDer = listArrIzq;
			this.nodoIzq = nodoIzq;
			this.nodoDer = nodoDer;
		}
public:
	NodoListArr();
	~NodoListArr();
	virtual void setEnUso() = 0;//Para definir cuantos espacios se están usando
	virtual int getEnUso() = 0;//Para saber cuantos están en uso
	virtual void setCapacidad() = 0;//Para definir la capacidad total
	virtual int getCapacidad() = 0;//Para saber la capacidad
	virtual void punterosArray() = 0;//define los punteros a los arrays de abajo
	virtual void punterosNodos() = 0;//Por si el caso lo requiere, definir los punteros entre nodos 
	}



}