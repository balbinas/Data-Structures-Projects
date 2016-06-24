//
//  main.cpp
//  Puntos Extras
//
//  Created by Balbina Santana    A00812215
//         and Francisco Tijerina A01139134


#include <iostream>
#include "MiArrego.h"
#include <time.h>
using namespace std;


void iDirecta (MiArreglo &a, int cantidad)
{
    for ( int i = 1; i < cantidad; i++ ){
        int aux = a[i];
        int j = i - 1;
        while ( j >= 0 && aux < a[j] ) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = aux;
    }
    cout <<endl <<"Numeros ordenados: " <<a;
}

int main(int argc, const char * argv[])
{

    srand(time(NULL));
    MiArreglo arr(20);
    cout <<"Numeros: ";
    for(int k=0; k<20; k++)
    {
        arr[k] = rand() % 9 + 1;
        cout<< arr[k] << " ";
    }
    
    iDirecta(arr, 20);
    
    int c[10] = {0};
    for(int j=0; j<20; j++)
    {
        c[arr[j]]++;
    }
    
    for(int i=1; i<10; i++)
    {
        cout <<"Repeticiones del numero " <<i <<": " <<c[i] <<endl;
    }

        
    
    return 0;
}

