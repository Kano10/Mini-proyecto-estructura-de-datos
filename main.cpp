#include "ListArr.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main(){
        ListArr* array = new ListArr(10, 5);
    cout<<"LISTARR CREADO"<<endl;
    //for(int i = 0; i < 10; ++i){
        array->insert(1, 0);
    //}
    array->print(array->getFirst());


    return 0;
}