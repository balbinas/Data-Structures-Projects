//
//  main.cpp
//  LAB02PROB03
//
//  Created by Balbina Santana on 29/1/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

void agrega(string lista[], int &cant, string palabra)
{
    int y = cant-1;
    if(y < 0)
    {
        lista[0] = palabra;
        cant++;
    }
    else
    {
        while(y>=0 && palabra < lista[y])
        {
            lista[y+1]=lista[y];
            y--;
        }
        lista[y+1] = palabra;
        cant++;
    }
}

int main(int argc, const char * argv[])
{
    string pal[50], palabra;
    int cantidad = 0;
    
    do {
        cin >>palabra;
        if (palabra == "fin"){return 0;}
        agrega(pal, cantidad, palabra);
        cout <<"LISTA: ";
        for (int m=0; m<cantidad; m++) {
        cout <<pal[m] << " ";
        }
        cout << endl;
    }while(palabra != "fin");
    
    return 0;
}

