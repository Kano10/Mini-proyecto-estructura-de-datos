#include "ListArr.h"

ListArr::ListArr(int size, int tamaño){
    this->size = size;
    this->tamaño = tamaño;
    for (int i = 0; i < size; i++)
    {
        ArrayListArr* nuevoArray = ArrayListArr(tamaño);
        nuevoArray->next = nullptr;
        if(first == nullptr){
            first = nuevoArray;
            end = nuevoArray;
        }else{
            end->next = nuevoArray;
            end = nuevoArray;
        }
    }
    ListArr.~NodoListArr();
    ListArr.reHacerNodos(); 
}

ListArr::~ListArr(){

}

int ListArr::size(){
    return size;
}

void ListArr::insert_left(){

}

void ListArr::insert_right(){
    
}

void ListArr::insert(){

}

void ListArr::print(){
    ArrayListArr* aux==first;//Se parte desde el primero
    int contAux=0;
    while (contAux<=ListArr.size())//Pasará por todos los arrays, hasta que ya no se cumpla esta condición
    {
        for (int i = 0; i < aux->enUso; i++)
        {
            cout<<aux->array[i]<<endl;
        }
        aux==aux->next;
    } 
}

bool ListArr::find(int v){
    if(first==nullptr){//Si no hay arrays, no existe el valor
        return false;
    }
    ArrayListArr* aux==first;//Se parte desde el primero
    int contAux=0;
    while (contAux<=ListArr.size())//Pasará por todos los arrays, hasta que ya no se cumpla esta condición
    {
        for (int i = 0; i < aux->enUso; i++)
        {
            if(aux->array[i]==v){//Chequea las posiciones
                return true;
            }
        }
        aux==aux->next;//Si no se encontró en el primer array, aux pasa a ser el siguiente array
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