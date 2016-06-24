//
//  AD.h
//  Programa 3 Arreglos dinamicos
//
//  Created by Balbina Santana on 23/2/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#ifndef Programa_3_Arreglos_dinamicos_AD_h
#define Programa_3_Arreglos_dinamicos_AD_h
using namespace std;

class AD
{
    friend ostream& operator<<(ostream& os, const AD& a)
    {
        for(int k=0; k<a.cantidad; k++)
            os << a.componente[k] <<" ";
            os << endl;
            return os;
    }

private:
    string *componente;
    int capacidad;
    int cantidad;
public:
    AD()
    {
        componente = new string[capacidad];
        capacidad = 2;
        cantidad = 0;
    }
    AD(int n)
    {
        n = capacidad;
        componente = new string[n];
        cantidad = 0;
        if(componente == NULL)
            cout <<"No hay espacio de memoria";
    }
    ~AD(){delete [] componente;}
    
    int laCapacidad()
    {
        return capacidad;
    }
    int laCantidad()
    {
        return cantidad;
    }
    void setCantidad(int cant)
        {
            cantidad = cant;
        }
    void agregaFinal(string dato)
    {
        if(componente != NULL)
        {
            componente[cantidad] = dato;
            cantidad++;
        }
    }
    void redimensiona()
    {
        capacidad = capacidad + 16;
        string *nuevo = componente;
        componente = new string[capacidad];
        for(int k=0; k<capacidad-16;i++)
            componente[i] = nuevo[i];
        delete [] nuevo;
    }
    AD(const AD& a)
    {
        capacidad = a.capacidad;
        cantidad = a.cantidad;
        componente = new string[capacidad];
        for(int k=0; k<cantidad-1; k++)
            componente[k] = a.componente[k];
    }
            
    
   
    AD& operator = (const AD& a)
    {
        if(this != &a)
        {
            delete [] componente;
            capacidad = a.capacidad;
            cantidad = a.cantidad;
            componente = new string [cantidad];
            for(int k =0; k<cantidad; k++)
                componente[k] = a.componente[k];
        }
        return *this;
    }
            string& operator [](int casilla)
        { return componente[casilla]; }
};
#endif
