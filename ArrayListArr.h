#ifndef ARRAYLISTARR_H
#define ARRAYLISTARR_H

class ArrayListArr{
private:
	int enUso;
	int tam;
	int* array;
	bool* estaOcupado; //saber si el espacio esta disponible con true o false.
	ArrayListArr* next;

public:
	ArrayListArr(int tam); //como el tamaño es b este se ingresa por tam dentro de los nodos y arbol
	~ArrayListArr();
	int getUsado(); //Se usara para acceder a enUso dentro de otras clases
	int getTam();	//Se usara para acceder a tam dentro de otras clases
	ArrayListArr* getNext();	//Tener disponible el next en otras clases
	
	bool ocupado(int i); //preguntar si espacio esta disponible
	void setOcupado(int i, bool value); //marcar casilla ocupada cuando se inserte
	
	void setNext(ArrayListArr* nuevo);
	//segun yo setNext solo necesita nuevo y no el end
	
	int arrayPosicion(int p);//retorna la posicion p del array
	void insertAt(int data, int i);	//insertar en posicion i, para clase nodo solo se llama a esta
};
#endif



