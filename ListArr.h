#ifndef LISTARR_H
#define LISTARR_H


#include "ArrayListArr.h"
#include "NodoListArr.h"
#include <vector>

class ListArr
{
private:
	int size;//para saber cuantos arrays hay y así saber cuantos nodos resumen se deben tener
	int tamaño;//el tamaño que tendrán los arrays, todos tendrán el mismo tamaño al definirse al inicio.
	NodoListArr* root;
	vector<NodoListArr*> hojas;


public:
	ArrayListArr* first;//Apuntará al último ArrayListArr
	ArrayListArr* end;//apuntará al primer ArrayListArr
	//METODOS QUE NOS PIDEN IMPLEMENTAR
	ListArr(int size, int tamaño);
	~ListArr();
	int getSize();//Cantidad de elementos en el ListArr
	void insert_left(int v) ;//insertar un valor a la izquierda
	//con el puntero extra que se creo esto se facilita
	void insert_right(int v) ;// insertar un valor a la derecha
	//lo mismo que el método anterior, pero con el puntero al final
	void insert(int v, int i) ;//insertar valor v en el indice i
	//para este caso, al insertar un nuevo
	void print() ;//imprime los valores en pantalla de todo
	//esto se podría hacer simplemente recorriendo los arrays sin usar los nodos resumen
	bool find(int v) ;//busca el valor v en todo el ListArr
	int delete_left() ;//eliminar y retornar elemento de la izquierda
	int delete_right() ;//eliminar y retornar elemento de la derecha

	/*Las funciones delete podrían hacerse mediante los punteros de inicio y final que hay en ArrayListArr, aunque luego de eliminar un elemento se deberá cambiar los valores de los nodos resumenes, para lo 
	cual recomiendo llamar a reHacerNodos() a menos que se les ocurra algo mejor*/


	//METODOS QUE NECESITAMOS PARA PODER IMPLEMENTAR LOS ANTERIORES
	void setTamano(int n) ;//Para defini el tamaño que será igual para todos los arrays.
	void newArray() ;//Para crear un nuevo array, usar variable tamaño para crear el array y agregar que size sume 1 cada vez que se llama la funcion.
	//además, si se inserta una cantidad de elementos que no cabe en los arrays que tenemos se deben crear más para poder almacenar los valores, este método se deberá usar en esos casos.
	NodoListArr* reHacerNodos(int n) ;//Cuando se hagan nuevos arrays, es más fácil (o al menos por lo que pienso yo) re hacer todos los nodos resumenes luego de terminar de crear los nuevos arrays y eliminar los nodos resumenes viejos.
	//dentro de está misma función se podría agregar la eliminación de nodos resumenes, no es necesario crear otro método de eliminación de nodos.
	void getRoot(NodoListArr* nodo);
	void setRoot();
	void vaciarHojas();
	void rellenarVector();
};
#endif
