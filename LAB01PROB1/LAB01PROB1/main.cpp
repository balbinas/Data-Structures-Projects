//
//  main.cpp
//  LAB01PROB1
//
//  Created by Balbina Santana on 23/1/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//


#include <iostream>
#include<time.h>

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

int repetidos(int num[], int longitud)
{
    int x =0;
    for(int y=1; y<longitud; y++)
	{
		if(num[x] != num[y])
		{
			num[x+1] = num[y];
			x++;
		}
	}
	return x+1;
}

int main(int argc, const char * argv[]){
    
	srand(time(NULL));
	int num[25];
	llenar(num, 25);
	desplegar(num, 25);
	ordena(num, 25);
	desplegar(num, 25);
	int cantidad = repetidos(num,25);
	desplegar(num, cantidad);
	return 0;
}
