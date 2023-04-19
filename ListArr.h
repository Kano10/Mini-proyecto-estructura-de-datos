#include "ArrayListArr.h"
#include "NodoListArr.h"

class ListArr
{
private:
	int size;//para saber cuantos arrays hay y así saber cuantos nodos resumen se deben tener
	


public:
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
	virtual bool find(int v) = 0;//busca el valor v en todo el ListArr
};
