

class ArrayListArr
{
private:
	struct ArrayListArr{
		int enUso;
		int array[tamaño];
		ArrayListArr* next;
		ArrayListArr(ArrayListArr* next = nullptr){
			this.next = next;
		}
	};

public:
	ArrayListArr();
	~ArrayListArr();
	
};



// Mi propuesta de cambio
/*
#ifndef ARRAYLISTARR_H
#define ARRAYLISTARR_H

class ArrayListArr{
private:
	int enUso;
	int tam;
	int* array;
	ArrayListArr* next;

public:
	ArrayListArr(int tam); //como el tamaño es b este se ingresa por tam dentro de los nodos y arbol
	~ArrayListArr();
	int getUsado(); //Se usara para acceder a enUso dentro de otras clases
	int getTam();	//Se usara para acceder a tam dentro de otras clases
	ArrayListArr* getNext();	//Tener disponible el next en otras clases
	void insertAt(int data, int i);	//insertar en posicion i, para clase nodo solo se llama a esta
};
#endif
*/
