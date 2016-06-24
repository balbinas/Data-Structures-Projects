//
//  MiArrego.h
//  Puntos Extras
//
//  Created by Balbina Santana on 20/2/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#ifndef Puntos_Extras_MiArrego_h
#define Puntos_Extras_MiArrego_h
#include <iostream>
using namespace std;

class MiArreglo
{
    friend ostream& operator << (ostream& os, const MiArreglo& a)
    {
        for(int k=0; k<a.longitud; k++)
            os << a.arreglo[k] <<" ";
            os << endl;
            return os;
    }
            friend istream& operator >>(istream& is, MiArreglo& a)
        {
            for(int k=0; k<a.longitud; k++)
            {
                is >>a.arreglo[k];
                is.ignore();
            }
            return is;
        }
            private:
            int *arreglo;
            int longitud;
            public:
            MiArreglo()
        {// crea un arreglo de 10 casillas
            arreglo = new int [10];
            longitud = 10;
        }
            
            MiArreglo(int longitud)
        {
            arreglo = new int[longitud];
            this -> longitud = longitud;
        }
            MiArreglo(const MiArreglo& a)
        {//crear el arreglo
            longitud = a.longitud;
            arreglo = new int [longitud];
            //copiar los valores de a en el arreglo
            for(int k=0; k<longitud; k++)
                arreglo[k] = a.arreglo[k];
        }
            
            ~MiArreglo() {delete [] arreglo; }
            int lalongitud() {return longitud; }
            void meteValor(int casilla, int valor)
        {
            arreglo[casilla] = valor;
        }
            int dameValor(int casilla)
        {
            return arreglo[casilla];
        }
            int& operator [](int casilla) { return arreglo[casilla]; }
            MiArreglo& operator= (const MiArreglo a)
        {
            //verificar que el this i a sean diferentes
            if(this != &a)
            {
                //hacer la asignacion
                //dado que son objetos diferentes, hay que hacer la copia
                //borrar el area dinamica del this
                delete [] arreglo;
                //---------HACER LA COPIA---------//
                //crear el arreglo
                longitud = a.longitud;
                arreglo = new int [longitud];
                //copiar los valores de a en el arreglo
                for(int k=0; k<longitud; k++)
                    arreglo[k] = a.arreglo[k];
                
            }
            return *this;
        }
            
            };


#endif
