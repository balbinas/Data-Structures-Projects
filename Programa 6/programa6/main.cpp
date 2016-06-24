//
//  main.cpp
//  programa6
//
//  Created by Balbina Santana on 23/4/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
#include "FilaArreglo.h"
using namespace std;

int main(int argc, const char * argv[])
{
    /*FilaArreglo p;
    int valor;
    for (int k = 0; k < 10; k++) p.meterFila(k);
    while (! p.filaVacia()) {
        valor = p.observaFila();
        cout << valor << " ";
        p.sacarFila();
    }*/
    int N, valor;
    cout<<"N?";
    cin >>N;
    FilaArreglo p(N),q(N);
    for(int k=0; k<N; k++)
    {
        cout <<"Valor?";
        cin >>valor;
        if(valor % 2 == 0)
        p.meterFila(valor);
        else q.meterFila(valor);
    }
    cout<<"Numeros acomodados: ";
    while (! p.filaVacia()) {
        valor = p.observaFila();
        cout << valor << " ";
        p.sacarFila();
    }
    while (! q.filaVacia()) {
        valor = q.observaFila();
        cout << valor << " ";
        q.sacarFila();
    }
    return 0;
}

