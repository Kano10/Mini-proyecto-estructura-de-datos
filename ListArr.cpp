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
    for (int i = 0; i < size; i++){

        ArrayListArr* nuevoArray = new ArrayListArr(tamaño);
        if(first == nullptr){
        
            first = nuevoArray;
            end = nuevoArray;
        }else{
            nuevoArray->setNext(nuevoArray,end);
        }
    }
    getRoot()->eliminarNodos(getRoot());
    setRoot();//al hacer este llamado, se crea el arbol listo con la información en cada nodo
    //setRoot llama a reHacerNodos, el cual crea el arbol binario completo pero sin info, este luego llama a rellenarHojas, el cual almacena las hojas en un vector,
    //luego de completar ese metodo, se llama a rellenar nodos, en el que se rellena el arbol completo, usando el vector con la info que tiene, y además hace que las
    //hojas apunten a los arrays correspondientes.
}

ListArr::~ListArr(){
    
    //Destructor
    ArrayListArr* aux = end;
    while (aux != nullptr){
    
        ArrayListArr* a = aux;
        aux = aux->getNext();
        delete a;
    }
}

int ListArr::getSize(){
    return size;
}

void ListArr::insert_left(int v){

    if (count >= capacity){
        cout << "Error: ListArr is full" << endl;
        return;
    }
    
    for (int i = count; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    
    arr[0] = v;
    count++;
}

/*
void ListArr::insert_left(int v){
    if(!first.ocupado(0)) first.insertAt(v, 0);
    else{
        if(first.getUsado() != first.getTam()){
            for(int j = first.getTam() - 1; j > 0; --j) first[j] = first[j - 1];
            first.insertAt(v, 0);
        }
        else{
            int ultimo = first.arrayPosicion(first.getTam() - 1);
            for(int j = first.getTam() - 1; j > 0; --j) first[j] = first[j - 1];
            first.insertAt(v, 0);

            //crear nuevo nodo de array e insertar ultimo
            ArrayListArr *nuevo = newArray();
            nuevo.insertAt(ultimo, 0);
            nuevo.setNext(first.getNext());
            first.setNext(nuevo);
        }
    }
}
*/

void ListArr::insert_right(int v){
    
}

/*
void ListArr::insert_right(int v){
    if(end.getUsado() < end.getTam()) end.insertAt(v, end.getUsado());
    else{
        ArrayListArr *nuevo = newArray();
        end.setNext(nuevo);
        end = *nuevo;
    }
}
*/

void ListArr::insert(int v, int i){

    if (i >= size){
        
        newArray();
    }
    
    int pos = 0;
    ArrayListArr* aux = first;
    
    while (i >= tamaño){
    
        aux = aux->getNext();
        i -= tamaño;
        pos++;
    }
    
    aux->insert(v, i);
    NodoListArr* auxn = root;
    
    int cont = 0;
    
    getNodo(pos, auxn, cont);
    reHacerNodos(size);
}

/*
void ListArr::insert(int v, int i){
    NodoListArr *aux = root;
    //Ir pasando de nodo en nodo hasta llegar al del array correspondiente;
    while(aux->getNodoIzquierdo() != nullptr || aux->getNodoDerecho() != nullptr){
        if (aux->getNodoIzquierdo() != nullptr && aux->getNodoIzquierdo()->getUsado() > i) {
            aux = aux->getNodoIzquierdo();
        }
        else {
            if (aux->getNodoIzquierdo() != nullptr) {
                i -= aux->getNodoIzquierdo()->getUsado();
            }
            aux = aux->getNodoDerecho();
        }
    }
    //Trabajar en el nodo con el array ya encontrado;

    ArrayListArr *array = aux.getArray();
    //si la posicion esta disponible insertar
    if(!array.ocupado(i)) array.insertAt(v, i);
    //mover elementos para insertar
    else{
        //insertar sin necesidad de crear otro nodo
        if(array.getUsado() != array.getTam()){
            for(int j = array.getTam() - 1; j > i; --j) array[j] = array[j - 1];
        }
        //insertar craendo nuevo nodo por el array lleno
        else{
            int ultimo = array.arrayPosicion(array.getTam() - 1);
            for(int j = array.getTam() - 1; j > i; --j) array[j] = array[j - 1];

            //crear nuevo nodo de array e insertar ultimo
            ArrayListArr *nuevo = newArray();
            nuevo.insertAt(ultimo, 0);
            nuevo.setNext(array.getNext());
            array.setNext(nuevo);
        }
    }
}
*/

void ListArr::print(){
    ArrayListArr* aux;//Se parte desde el primero
    aux==first;
    int contAux=0;
    while (contAux<=getSize()){ //Pasará por todos los arrays, hasta que ya no se cumpla esta condición
        
        for (int i = 0; i < aux->getUsado(); i++){

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
    
    while (contAux<=getSize()){ //Pasará por todos los arrays, hasta que ya no se cumpla esta condición
    
        for (int i = 0; i < aux->getUsado(); i++){
            
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

ArrayListArr ListArr::newArray(){//Se tiene que usar para los metodos insert
    ArrayListArr *nuevo = new ArrayListArr();
    this.size++;
    return nuevo;
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
    rellenarHojas(root);
    return root;
}


NodoListArr* ListArr::getRoot(){
    return root;
}

void ListArr::setRoot(){
    root = reHacerNodos(ceil(getSize()));
}

void ListArr::vaciarHojas(){
    hojas.clear();
}

void ListArr::rellenarHojas(NodoListArr* nodo){
//cuando se llame a esta función, su primer llamado debe ser usando el root.
    if (!nodo) return;
    
    if (!nodo->getNodoIzquierdo(nodo) && !nodo->getNodoDerecho(nodo)) {
    
        hojas.push_back(nodo);
        return;
    }
    rellenarHojas(nodo->getNodoIzquierdo(nodo));
    rellenarHojas(nodo->getNodoDerecho(nodo));
}

void ListArr::rellenarNodos(){
    ArrayListArr* aux = first;
    for (int i = 0; i < hojas.size(); i++){

        int suma=0;
        suma += aux->getUsado();
        
        if(aux->getNext()!=nullptr){
        
            aux = aux->getNext();
            suma += aux->getUsado();
            hojas[i]->setEnUso(suma);
        }else{
        
            hojas[i]->setEnUso(suma);
        }
    }
}

int ListArr::rellenarArbol(NodoListArr* nodo){
    if(!nodo){
    return 0;
    }
    if(!nodo->getNodoIzquierdo(nodo) && !nodo->getNodoDerecho(nodo)){
        return nodo->getEnUso();
    }
    int izq = rellenarArbol(nodo->getNodoIzquierdo(nodo));
    int der = rellenarArbol(nodo->getNodoDerecho(nodo));
    int suma = izq + der;
    nodo->setEnUso(suma);
    nodo->setCapacidad();
    return nodo->getEnUso();
}
