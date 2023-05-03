#include "ListArr.h"
#include "ArrayListArr.h"
#include "NodoListArr.h"
#include <iostream>

using namespace std;

ListArr::ListArr(int size, int tamaño){
    this->size = size;
    this->tamaño = tamaño;
    for (int i = 0; i < size; i++)
    {
        ArrayListArr* nuevoArray = new ArrayListArr(tamaño);
        if(first == nullptr){
            first = nuevoArray;
            end = nuevoArray;
        }else{
            nuevoArray->setNext(nuevoArray,end);
        }
    }
    //~NodoListArr();
    reHacerNodos(); 
}

ListArr::~ListArr(){

}

int ListArr::getSize(){
    return size;
}

void ListArr::insert_left(int v){

}

void ListArr::insert_right(int v){
    
}

void ListArr::insert(int v, int i){

}

void ListArr::print(){
    ArrayListArr* aux;//Se parte desde el primero
    aux==first;
    int contAux=0;
    while (contAux<=getSize())//Pasará por todos los arrays, hasta que ya no se cumpla esta condición
    {
        for (int i = 0; i < aux->getUsado(); i++)
        {
            cout<<aux->arrayPosicion(i)<<endl;
        }
        aux==aux->getNext();
    } 
}

bool ListArr::find(int v){
    if(first==nullptr){//Si no hay arrays, no existe el valor
        return false;
    }
    ArrayListArr* aux=first;//Se parte desde el primero
    int contAux=0;
    while (contAux<=getSize())//Pasará por todos los arrays, hasta que ya no se cumpla esta condición
    {
        for (int i = 0; i < aux->getUsado(); i++)
        {
            if(aux->arrayPosicion(i)==v){//Chequea las posiciones
                return true;
            }
        }
        aux = aux->getNext();//Si no se encontró en el primer array, aux pasa a ser el siguiente array
    }
    return false;//si llega a salir del while es porque no está el valor
}

int ListArr::delete_left(){

}

int ListArr::delete_right(){

}

void ListArr::setTamano(int n){//Creo que este se podría quitar, basta con fijar el tamañao en el constructor.
    tamaño = n;
}

void ListArr::newArray(){//Se tiene que usar para los metodos insert

}

void ListArr::reHacerNodos(){//Se tiene que utilizar para los metodos insert, delete y constructor
    
}

NodoListArr* ListArr::getRoot(){
    return root;
}