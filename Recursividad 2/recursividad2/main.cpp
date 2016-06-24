//
//  main.cpp
//  recursividad2
//
//  Created by Balbina Santana on 12/4/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
using namespace std;

void despliega1(int a[], int longitud)
{
    if(longitud > 0)
    {
        cout <<a[longitud - 1] << " ";
        despliega1(a,longitud - 1);
    }
}

int sumatoria(int a[], int longitud)
{
    if (longitud == 1)
        return a[0];
    return a[longitud-1] + sumatoria(a, longitud - 1);
}

int main(int argc, const char * argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    int suma = sumatoria(a,9);
    cout <<"Suma = " <<suma <<endl;
    despliega1(a,9);
    return 0;
}

