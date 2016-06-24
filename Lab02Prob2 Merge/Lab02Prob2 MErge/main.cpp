//
//  main.cpp
//  Lab02Prob2 MErge
//
//  Created by Balbina Santana on 25/1/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
#include <time.h>
using namespace std;

void llenar(int num[], int longitud)
{
	for(int k=0; k<longitud; k++)
		num[k] = rand() % 30 +1;
}

void desplegar(int num[], int longitud)
{
	for(int k=0; k<longitud; k++)
		cout <<num[k] <<" " ;
	cout <<endl;
}

void ordena(int num[], int cantidad)
{
	for ( int i = 0; i < cantidad - 1; i++) {
        //Busca el valor más chico
        int menor = num[i];
        int pos = i;
        for ( int j = i+1; j < cantidad; j++){
            if ( num[j] < menor ){ menor = num[j];
                pos = j; }
        }
        //intercambia el valor a[pos] = a[i];
        num[i] = menor;
    }
}

void merge(int c[], int a[],int tA, int b[], int tB)
{
    int x=0, y=0, z=0;
    while (x < tA && y < tB)
    {
        if (a[x] < b[y])
        {
            c[z] = a[x];
            x++;
        }
        else
        {
            c[z] = b[y];
            y++;
        }
        z++;
    }
    while (x < tA)
    {
        c[z] = a[x];
        x++;
        z++;
    }
    while (x < tB)
    {
        c[z] = b[y];
        y++;
        z++;
    }
}

int main(int argc, const char * argv[])
{

    //variables empiezan con i si son int d si son double
    
    srand(time(NULL));
    int tArrA, tArrB;
    cout <<"Cantidad de elementos del primer arreglo?";
    cin >>tArrA;
    int ArrA[tArrA];
    cout <<"Cantidad de elementos del segundo arreglo?";
    cin >>tArrB;
    int ArrB[tArrB];
    int ArrC[tArrA+tArrB];
    
    llenar(ArrA, tArrA);
    llenar(ArrB, tArrB);
    ordena(ArrA, tArrA);
    ordena(ArrB, tArrB);
    desplegar(ArrA, tArrA);
    desplegar(ArrB, tArrB);
    merge(ArrC, ArrA, tArrA, ArrB, tArrB);
    desplegar(ArrC, tArrA+tArrB);
    return 0;
}

