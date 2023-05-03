#ifndef LISTARR_H
#define LISTARR_H


#include "ArrayListArr.h"
#include "NodoListArr.h"

class ListArr
{
private:
	int size;//para saber cuantos arrays hay y así saber cuantos nodos resumen se deben tener
	int tamaño;//el tamaño que tendrán los arrays, todos tendrán el mismo tamaño al definirse al inicio.
	ArrayListArr* first;//Apuntará al último ArrayListArr
	ArrayListArr* end;//apuntará al primer ArrayListArr


public:
	//METODOS QUE NOS PIDEN IMPLEMENTAR
	ListArr();
	~ListArr();
	virtual int size() = 0;//Cantidad de elementos en el ListArr
	virtual void insert_left(int v) = 0;//insertar un valor a la izquierda
	//con el puntero extra que se creo esto se facilita
	virtual void insert_right(int v) = 0;// insertar un valor a la derecha
	//lo mismo que el método anterior, pero con el puntero al final
	virtual void insert(int v, int i) = 0;//insertar valor v en el indice i
	//para este caso, al insertar un nuevo
	virtual void print() = 0;//imprime los valores en pantalla de todo
	//esto se podría hacer simplemente recorriendo los arrays sin usar los nodos resumen
	virtual bool find(int v) = 0;//busca el valor v en todo el ListArr
	virtual int delete_left() = 0;//eliminar y retornar elemento de la izquierda
	virtual int delete_right() = 0;//eliminar y retornar elemento de la derecha

	/*Las funciones delete podrían hacerse mediante los punteros de inicio y final que hay en ArrayListArr, aunque luego de eliminar un elemento se deberá cambiar los valores de los nodos resumenes, para lo 
	cual recomiendo llamar a reHacerNodos() a menos que se les ocurra algo mejor*/


	//METODOS QUE NECESITAMOS PARA PODER IMPLEMENTAR LOS ANTERIORES
	virtual void setTamano() = 0;//Para defini el tamaño que será igual para todos los arrays.
	virtual void newArray() = 0;//Para crear un nuevo array, usar variable tamaño para crear el array y agregar que size sume 1 cada vez que se llama la funcion.
	//además, si se inserta una cantidad de elementos que no cabe en los arrays que tenemos se deben crear más para poder almacenar los valores, este método se deberá usar en esos casos.
	virtual void reHacerNodos() = 0;//Cuando se hagan nuevos arrays, es más fácil (o al menos por lo que pienso yo) re hacer todos los nodos resumenes luego de terminar de crear los nuevos arrays y eliminar los nodos resumenes viejos.
	//dentro de está misma función se podría agregar la eliminación de nodos resumenes, no es necesario crear otro método de eliminación de nodos.

};
#endif
