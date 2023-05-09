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
            end->setNext(nuevoArray);
            end = nuevoArray;
        }
    }
    ArrayListArr* aux = first;
    for (int i = 0; i < size; ++i)
    {
        aux=aux->getNext();
    }
    root = new NodoListArr();
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
    if(!first->ocupado(0)) first->insertAt(v, 0);
    else{
        if(first->getUsado() != first->getTam()){
            for(int j = first->getTam() - 1; j > 0; --j) first[j] = first[j - 1];
            first->insertAt(v, 0);
        }
        else{
            int ultimo = first->arrayPosicion(first->getTam() - 1);
            for(int j = first->getTam() - 1; j > 0; --j) first[j] = first[j - 1];
            first->insertAt(v, 0);

            //crear nuevo nodo de array e insertar ultimo
            ArrayListArr *nuevo = newArray();
            nuevo->insertAt(ultimo, 0);
            nuevo->setNext(first->getNext());
            first->setNext(nuevo);
            
        }
    }
}

void ListArr::insert_right(int v){
    if(end->getUsado() < end->getTam()) end->insertAt(v, end->getUsado());
    else{
        ArrayListArr *nuevo = newArray();
        end->setNext(nuevo);
        end = nuevo;
    }
}

void ListArr::insert(int v, int i){
    NodoListArr *aux = root;
    //Ir pasando de nodo en nodo hasta llegar al del array correspondiente;
    while(aux->getNodoIzquierdo() != nullptr || aux->getNodoDerecho() != nullptr){
        if (aux->getNodoIzquierdo() != nullptr && aux->getNodoIzquierdo()->getEnUso() > i) {
            aux = aux->getNodoIzquierdo();
        }else{
            if (aux->getNodoIzquierdo() != nullptr) {
                i -= aux->getNodoIzquierdo()->getEnUso();
                            aux = aux->getNodoDerecho();
            }
        }
    }
    //Trabajar en el nodo con el array ya encontrado;
    ArrayListArr *array = new ArrayListArr(tamaño);
    //Determinar en cuál de los arrays de los hijos izquierdo o derecho se encuentra el índice.
    if (i < aux->getArrayIzq()->getTam()) {
        array = aux->getArrayIzq();
    }else{
        i -= aux->getArrayIzq()->getUsado();
        array = aux->getArrayDer();

    }
    //si la posicion esta disponible insertar
    if(!array->ocupado(i)){
        array->insertAt(v, i);
    //mover elementos para insertar
    }else{
        //insertar sin necesidad de crear otro nodo
        if(array->getUsado() != array->getTam()){
            for(int j = array->getTam() - 1; j > i; --j){
                array[j] = array[j - 1];
            }
            array->insertAt(v,i);
        }
        //finsertar craendo nuevo nodo por el array lleno
        else{
            int ultimo = array->arrayPosicion(array->getTam() - 1);
            for(int j = array->getTam() - 1; j > i; --j){
                array[j] = array[j - 1];
            }
            array->insertAt(v,i);
            //crear nuevo nodo de array e insertar ultimo
            ArrayListArr *nuevo = newArray();
            nuevo->insertAt(ultimo, 0);
            nuevo->setNext(array->getNext());
            array->setNext(nuevo);
        }
    }
}

void ListArr::print(ArrayListArr* puntero){
    ArrayListArr* aux=puntero;
    int contAux=0;
    for (int i = 0; i < aux->getUsado(); i++){
        cout<<aux->arrayPosicion(i)<<endl;
    }
    if(aux->getNext()!=nullptr){
        print(aux->getNext());
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
    if (first == nullptr) { // lista vacía
        return -1; // o cualquier valor que quieras retornar en este caso
    }

    int value = first->arrayPosicion(0); // obtener el valor a eliminar
    first->insertAt(0, 0); // reemplazar el primer valor con un 0

    if (first->getUsado() == 0) { // si el primer array está vacío

        ArrayListArr* temp = first; // guardar el puntero al primer array
        first = first->getNext(); // mover el puntero al siguiente array
        delete temp; // liberar la memoria del primer array vacío
    }
    size--; // disminuir el tamaño de la lista
    return value; // retornar el valor eliminado
}

int ListArr::delete_right(){
    if (end == nullptr) { // lista vacía
        return -1; // o cualquier valor que quieras retornar en este caso
    }

    ArrayListArr* last = end;
    int value = last->arrayPosicion(last->getUsado() - 1); // obtener el valor a eliminar
    last->insertAt(0, last->getUsado() - 1); // reemplazar el último valor con un 0

    if (last->getUsado() == 0) { // si el último array está vacío

        ArrayListArr* temp = end; // guardar el puntero al último array
        end = end->getNext(); // mover el puntero al array anterior
        delete temp; // liberar la memoria del último array vacío
    }
    size--; // disminuir el tamaño de la lista
    return value; // retornar el valor eliminado
}

void ListArr::setTamano(int n){//Creo que este se podría quitar, basta con fijar el tamañao en el constructor.
    tamaño = n;
}

ArrayListArr* ListArr::newArray(){//Se tiene que usar para los metodos insert
    ArrayListArr *nuevo = new ArrayListArr(this->tamaño);
    this->size++;
    getRoot()->eliminarNodos(getRoot());
    setRoot();
    return nuevo;
}

NodoListArr* ListArr::reHacerNodos(int n){//Se tiene que utilizar para los metodos insert, delete y constructor
    //OJO AQUI. cuando se quiera usar este metodo con el getSize(), se debe usar ceil(getSize()) para que redondee al proximo entero, esto es para casos como por ejemplo el 5,
    //si se tienen arrays, se puede saber que se necesitan 3 nodos, pero n/2 da 2.5, entonces al usar ceil da 3 y no 2.5 
    if (n == 0) return NULL;
    
    int altura = ceil(log2(n + 1));
    int nodos = 2*altura - 1;
    NodoListArr* root = new NodoListArr();
    queue<NodoListArr*> q;
    
    q.push(root);
    for (int i = 1; i < nodos; i += 2) {
        NodoListArr* padre = q.front();
        q.pop();

        padre->setNodoIzquierdo(padre);
        padre->setNodoDerecho(padre);

        q.push(padre->getNodoIzquierdo());
        q.push(padre->getNodoDerecho());
    }

    
    vaciarHojas();
    rellenarHojas(root);
    rellenarNodos();
    rellenarArbol(root);
    return root;
}


NodoListArr* ListArr::getRoot(){
    return root;
}

void ListArr::setRoot(){
    root = reHacerNodos(ceil(getSize()/2));
}

void ListArr::vaciarHojas(){
    hojas.clear();
}

void ListArr::rellenarHojas(NodoListArr* nodo){
//cuando se llame a esta función, su primer llamado debe ser usando el root.
    if (!nodo) return;
    if (!nodo->getNodoIzquierdo() && !nodo->getNodoDerecho()) {
    
        hojas.push_back(nodo);
        return;
    }
    rellenarHojas(nodo->getNodoIzquierdo());
    rellenarHojas(nodo->getNodoDerecho());
}

void ListArr::rellenarNodos(){
    ArrayListArr* aux = first;
    for (int i = 0; i < hojas.size(); i++){
        int suma1=0;
        int suma2=0;
        suma1 += aux->getUsado();
        suma2 += aux->getTam();
        if(aux->getNext()!=nullptr){
            hojas[i]->setArrayIzquierdo(hojas[i], aux);
            hojas[i]->getArrayIzq();//FLAGS
            aux = aux->getNext();
            suma1 += aux->getUsado();
            suma2 += aux->getTam();
            hojas[i]->setArrayDerecho(hojas[i],aux);
            hojas[i]->setEnUso(suma1);
            hojas[i]->getArrayDer();//FLAGS
        }else{
            hojas[i]->setArrayIzquierdo(hojas[i], aux);
            hojas[i]->setEnUso(suma1);
            hojas[i]->getArrayIzq();//FLAGS
        }
    }
}

void ListArr::rellenarArbol(NodoListArr* nodo){
    if(!nodo){
    return;
    }
    if(!nodo->getNodoIzquierdo() && !nodo->getNodoDerecho()){
        return;
    }
    if(nodo->getNodoIzquierdo()!=nullptr){
        rellenarArbol(nodo->getNodoIzquierdo());
    }
    if(nodo->getNodoDerecho()!=nullptr){
        rellenarArbol(nodo->getNodoDerecho());
        nodo->setCapacidad();
    }else{
        nodo->setCapacidad();
    }
}

ArrayListArr* ListArr::getFirst(){
    return first;
}