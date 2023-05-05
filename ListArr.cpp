#include "ListArr.h"
#include "ArrayListArr.h"
#include "NodoListArr.h"
#include <iostream>
#include <queue>
#include <cmath>

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
    setRoot(); 
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

NodoListArr* ListArr::reHacerNodos(int n){//Se tiene que utilizar para los metodos insert, delete y constructor
    //OJO AQUI. cuando se quiera usar este metodo con el getSize(), se debe usar ceil(getSize()) para que redondee al proximo entero, esto es para casos como por ejemplo el 5,
    //si se tienen arrays, se puede saber que se necesitan 3 nodos, pero n/2 da 2.5, entonces al usar ceil da 3 y no 2.5 
    if (n == 0) return NULL;
    int altura = ceil(log2(n + 1));
    int nodos = pow(2, altura) - 1;
    NodoListArr* root = new NodoListArr();
    queue<NodoListArr*> q;
    q.push(root);
    nodos--;
    while (nodos > 0) {
        NodoListArr* nodo = q.front();
        q.pop();
        nodos--;
        nodo->setNodoIzquierdo(nodo);
        q.push(nodo->getNodoIzquierdo(nodo));
        if (nodos == 0) break;
        nodo->setNodoDerecho(nodo);
        q.push(nodo->getNodoDerecho(nodo));
        nodos--;
    }
    vaciarHojas();
    rellenarVector(root);
    return root;
}


void ListArr::getRoot(NodoListArr* nodo){
    nodo = root;
}

void ListArr::setRoot(){
    root = reHacerNodos(ceil(getSize()));
}

void ListArr::vaciarHojas(){
    hojas.clear();
}

void ListArr::rellenarVector(NodoListArr* nodo){
//cuando se llame a esta función, su primer llamado debe ser usando el root.
    if (!nodo) return;
    if (!nodo->getNodoIzquierdo(nodo) && !nodo->getNodoDerecho(nodo)) {
        hojas.push_back(nodo);
        return;
    }
    rellenarVector(nodo->getNodoIzquierdo(nodo));
    rellenarVector(nodo->getNodoDerecho(nodo));
}

void ListArr::rellenarNodos(){
    ArrayListArr* aux = first;
    for (int i = 0; i < hojas.size(); i++)
    {
        int suma=0;
        suma += aux->getUsado();
        if(aux->getNext()!=nullptr){
            aux = aux->getNext();
            suma += aux->getUsado();
            hojas[i]->setEnUso(suma,hojas[i]);
        }else{
            hojas[i]->setEnUso(suma, hojas[i]);
        }
    }
    

}