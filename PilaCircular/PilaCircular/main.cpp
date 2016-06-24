//
//  main.cpp
//  PilaCircular
//
//  Created by Balbina Santana on 13/3/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
#include "PilaCircular.h"
using namespace std;

int main(int argc, const char * argv[])
{
    PilaCircular P;
    for(int k=0; k < 20; k= k+2)
        P.meterPila(k);
    
    PilaCircular Aux;
    while(!P.pilaVacia())
    {
        Aux.meterPila(P.observaPila());
        P.sacarPila();
    }
    while(!Aux.pilaVacia())
    {
        P.meterPila(Aux.observaPila());
        Aux.sacarPila();
    }
    
    while(!P.pilaVacia())
    {
        cout << P.observaPila() << " ";
        P.sacarPila();
    }
    return 0;
}

