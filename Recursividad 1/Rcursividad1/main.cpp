//
//  main.cpp
//  Rcursividad1
//
//  Created by Balbina Santana on 12/4/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
using namespace std;

void despliega(int numero)
{
    if(numero >= 0)
    {
        despliega(numero -1);
        cout <<numero <<" ";
    }
}

int main(int argc, const char * argv[])
{
    int numero;
    cout <<"Numero?: ";
    cin >>numero;
    despliega(numero);
    
    return 0;
}

