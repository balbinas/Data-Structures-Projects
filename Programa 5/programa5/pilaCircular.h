//
//  pilaCircular.h
//  programa5
//
//  Created by Balbina Santana on 26/4/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#ifndef programa5_pilaCircular_h
#define programa5_pilaCircular_h

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Nodo
{
public:
    Nodo *sig;
    int info;
    Nodo( )
    {
        sig = NULL;
    }
    Nodo (int dato)
    {
        info = dato;
        sig = NULL;
    }
    Nodo (int dato, Nodo *Siguiente)
    {
        info = dato;
        sig = Siguiente;
    }
    
};

class PilaCircular
{
private:
    Nodo *inicio;
    
public:
    PilaCircular()
    {
        inicio=NULL;
    }
    
    
    //regresa el ultimo valor agregado a la pila
    int observaPila()
    {
        return inicio->sig->info;
    }
    //verifica si la pila esta vacia
    bool pilaVacia()
    {
        return inicio==NULL;
    }
    //Agrega un nodo a la pila
    void meterPila(int valor)
    {
        Nodo *nuevo= new Nodo(valor);
        if (inicio==NULL)
        {
            nuevo->sig=nuevo;
            inicio=nuevo;
        }
        else
        {
            nuevo->sig=inicio->sig;
            inicio->sig=nuevo;
        }
    }
    void sacarPila()
    {
        Nodo *p=inicio->sig;
        if (inicio==inicio->sig)//solo hay un nodo
        {
            inicio=NULL;
        }
        else
            inicio->sig=p->sig;
        delete p;
    }
    void despliega()
    {
        Nodo *p=inicio->sig;
        while (p!=inicio)
        {
            cout<<p->info;
            p=p->sig;
        }
        cout<<p->info;
    }
    
    ~PilaCircular()
    {
        while (!pilaVacia())
            sacarPila();
    }
};

void sumaPila(PilaCircular &Pa, PilaCircular &Pb, PilaCircular &Pc)
{
    int Da, Db, Dc;
    int aux;
    int cont=0;
    while (!Pa.pilaVacia() && !Pb.pilaVacia())
    {
        Da = Pa.observaPila();
        Db = Pb.observaPila();
        Pa.sacarPila();
        Pb.sacarPila();
        
        aux = Da + Db + cont;
        
        if (aux<=9)
        {
            Dc = aux;
            cont = 0;
        }
        else
        {
            cont = 1;
            Dc = aux - 10;
        }
        Pc.meterPila(Dc);
    }
    if(cont == 1)
    {
        Pc.meterPila(cont);
    }

}

#endif
