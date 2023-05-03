#include "ArrayListArr.h"

//Constructor para cada elemento
ArrayListArr::ArrayListArr(int tam){
	this->tam = tam;
	this->enUso = 0;
	this->next = nullptr;
	this->array = new int[tam];
}

//Elminarlos
ArrayListArr::~ArrayListArr(){
	this->tam = 0;
	this->enUso = 0;
	this->next = nullptr;
	delete[] array;
}

//Retorno de enUso
int ArrayListArr::getUsado(){
	return enUso;
}

//Retorno de tam
int ArrayListArr::getTam(){
	return tam;
}

//Retornar el siguiente array enlazado
ArrayListArr* ArrayListArr::getNext(){
	return next;
}

void ArrayListArr::setNext(ArrayListArr* nuevo, ArrayListArr* end){
		end->next = nuevo;
		end = nuevo;
}

int ArrayListArr::arrayPosicion(int p){
	return array[p];
}
//Solo insertar cuando i tiene valor entre 0 y el tam para no acceder a algo que no existe
void ArrayListArr::insertAt(int data, int i){
	if(0 <= i && i < tam){
		array[i] = data;
	}
	//se debe agregar algopara cuando la posición esté ocupada
	//igual diria que creo más conveniente que este metodo esté en ListArr no mas, ya que por ahi se puede tener acceso a los nodos y a los arrays
}
