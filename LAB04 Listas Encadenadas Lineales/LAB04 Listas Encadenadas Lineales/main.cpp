//
//  main.cpp
//  LAB04 Listas Encadenadas Lineales
//
//  Created by Balbina Santana on 27/2/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
using namespace std;
#include "ListaLineal.h"


int main()
{
    ListaLineal L;
    int valor;
    for(int k=1; k<=15; k++)
        L.meterInicioLista(k);
    L.despliegaLista();
    cout <<"Valor?: ";
    cin >>valor;
    if(L.buscaLista(valor))
        cout <<"Sipi";
    else cout <<"Nop";
    cout<<endl;
    for(int k=50; k<55; k++)
        L.meterFinalLista(k);
    L.despliegaLista();
    
    ListaLineal Q = L;
    Q.despliegaLista();
    L.despliegaLista();
    
    ListaLineal W;
    W = L;
    W.despliegaLista();
    L.despliegaLista();
    
    if(W == L)
        cout <<"Iguales";
    else cout<<"Ups!";
    cout <<endl;
    W.meterInicioLista(88);
    
    if(W == L)
        cout <<"Iguales";
    else cout<<"Ups!";
    cout <<endl;
    W.meterInicioLista(88);
    return 0;
}

