//
//  main.cpp
//  programa5
//
//  Created by Balbina Santana on 26/4/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "pilaCircular.h"

using namespace std;
int main()
{
    ifstream ArchivoEntrada;
    string nombre;
    PilaCircular Pa, Pb, Pc;
    char numero;
    int x;
    bool pasa = false;
    
    //cout<<"nombre del archivo de entrada?:"<<endl;
    //cin>>nombre;
    //nombre = "/Users/Balbina/Desktop/" + nombre;
    //prueba: nombre.c_str()
    ArchivoEntrada.open("/Users/Balbina/Desktop/texto.txt");
    
    while (!ArchivoEntrada.eof())
    {
        ArchivoEntrada.get(numero);
        if (numero == '\n' && !ArchivoEntrada.eof() )
        {
            pasa = true;
        }
        if (!pasa)
        {
            x= atoi(&numero);
            Pa.meterPila(x);
        }
        else
        {
            x = atoi(&numero);
            Pb.meterPila(x);
        }
    }
    ArchivoEntrada.close();
    
    sumaPila(Pa, Pb, Pc);
    Pc.despliega();
    return 0;
}
