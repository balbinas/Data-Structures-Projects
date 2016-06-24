//
//  main.cpp
//  ArreglosDinamicos
//
//  Created by Balbina Santana on 6/2/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
#include "MiArreglo.h"
using namespace std;

int main(int argc, const char * argv[])
{
    /*MiArreglo arr(15);
    for(int k=0; k < arr.lalongitud(); k++)
    {
        arr.meteValor(k, k);
    }
    for(int k=0; k < arr.lalongitud(); k++)
    {
        cout <<arr.dameValor(k) <<" ";
        cout <<endl;
    }
    return 0; */
    
    MiArreglo arr(15);
    for(int k=0; k < arr.lalongitud(); k++)
        arr[k] = k*k;
    
    MiArreglo arrB = arr;
    cout <<"Contenido del arreglo" <<endl;
    cout <<arr;
    //cout <<"Teclea los valores del arreglo" <<endl;
    //cin >>arr;
    //cout <<"El nuevo contenido del arreglo" <<endl;
    //cout <<arr;
    cout <<"Contenido del arreglo B" <<endl;
    cout <<arrB;
    
    cout <<endl;
    return 0;
}

