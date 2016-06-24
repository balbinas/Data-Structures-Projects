//
//  main.cpp
//  Programa 3 AD parte 2
//
//  Created by Balbina Santana on 24/2/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cctype>
#include "AD.h"
using namespace std;

void insercionDirecta (AD& a, int cantidad)
{
    for ( int i = 1; i < cantidad; i++ ){
        string aux = a[i];
        int j = i - 1;
        while ( j >= 0 && aux < a[j] ) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = aux;
    }
}

void eliminar(AD& a, int n){
    AD b(n);
    for(int i = 0;i<n;i++){
        for(int j = 0; j<a[i].length();j++){
            if(!ispunct(a[i][j]))
                b[i]+=tolower(a[i][j]);
        }
    }
    b.setCantidad(a.laCantidad());
    a=b;
}

int main()
{
    ifstream archivoEntrada;
    ofstream archivoSalida;
    archivoEntrada.open("Datos.txt");
    
    AD tex(100);
    int num = -1;
    string texto;
    while(archivoEntrada)
    {
        num++;
        archivoEntrada >>texto;
        tex.agregaFinal(texto);
    }
    
    eliminar(tex, num);
    
    insercionDirecta(tex, num);
    int c=1;
    int cp=0;
    
    archivoSalida.open("Reporte.txt");
    for(int k = 1;k<num;k++){
        cp++;
        if(tex[k]==tex[k-1]){
            cp--;
            c++;
        }
        else{
            archivoSalida<<c<<" "<<tex[k-1]<<endl;
            if (tex[k][0]!=tex[k-1][0]){
                char a = toupper(tex[k-1][0]);
                archivoSalida<<"Total de palabras con "<<a<<": "<<cp<<endl;
                cp=0;
            }
            c=1;
        }
    }
    archivoSalida.close();
}

    /*
     string linea;
     int contador[27];
     while(archivoEntrada >> linea)
    {
        int aux = 0;
        for(int k=0; k<linea.length(); k++)
        {
            aux = k-1;
            if(linea[aux] == ' ' || aux == -1)
            switch(linea[k])
        {
            case 'a':
                contador[1]++;
                break;
            case 'b':
                contador[2]++;
                break;
            case 'c':
                contador[3]++;
                break;
            case 'd':
                contador[4]++;
                break;
            case 'e':
                contador[5]++;
                break;
            case 'f':
                contador[6]++;
                break;
            case 'g':
                contador[7]++;
                break;
            case 'h':
                contador[8]++;
                break;
            case 'i':
                contador[9]++;
                break;
            case 'j':
                contador[10]++;
                break;
            case 'k':
                contador[11]++;
                break;
            case 'l':
                contador[12]++;
                break;
            case 'm':
                contador[13]++;
                break;
            case 'n':
                contador[14]++;
                break;
            case 'o':
                contador[15]++;
                break;
            case 'p':
                contador[16]++;
                break;
            case 'q':
                contador[17]++;
                break;
            case 'r':
                contador[18]++;
                break;
            case 's':
                contador[19]++;
                break;
            case 't':
                contador[20]++;
                break;
            case 'u':
                contador[21]++;
                break;
            case 'v':
                contador[22]++;
                break;
            case 'w':
                contador[23]++;
                break;
            case 'x':
                contador[24]++;
                break;
            case 'y':
                contador[25]++;
                break;
            case 'z':
                contador[26]++;
                break;
        }
        }
        
        
    }
*cout <<contador[1];
    int k =0;
    while(!archivoEntrada.eof())
    {
        k++;
        for(int j=0; j<k; j++)
        {
        getline(archivoEntrada, texto[k]);
        cout <<texto <<endl;
        }
    }
    
    for(int k=0; k<texto.laCantidad(); k++)
    {
    texto = archivoEntrada.get();
    cout <<"texto: " <<texto;
    }
    AD texto;
    char letra;
    for(int k=0; k<!archivoEntrada.eof();k++ )
    {
        *texto[k] = archivoEntrada.get();
        cout <<*texto <<endl;
    }
    //if(!ispunct(letra))
    {
        
    }
    archivoEntrada.close();
    
    ofstream archivoSalida;
    archivoSalida.open("Reporte.txt");
    
    archivoSalida.close();
    
    switch (letra)
    {
        case 'a':
            for(k=0;k<cantidad;k++)
            letra[suma[j]]++;
            archivoSalida <<"Total de palabras con A: " <<a <<endl;
    }*/

