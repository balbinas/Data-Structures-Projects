//
//  PilaCircular.h
//  PilaCircular
//
//  Created by Balbina Santana on 13/3/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#ifndef PilaCircular_PilaCircular_h
#define PilaCircular_PilaCircular_h

class Nodo{
public:
    Nodo *sig;
    int info;
    Nodo( ) { sig = NULL; }
    Nodo (int dato) { info = dato; sig = NULL; }
    Nodo (int dato, Nodo *Siguiente)
    {
        info = dato; sig = Siguiente;
    }
};

class PilaCircular{
public:
    PilaCircular() {inicio = NULL;}
    ~PilaCircular()
    {
        while(!pilaVacia()) sacarPila();
    }
    //regresa el ultimo valor agregado a la pila
    int observaPila(){return inicio ->sig ->info;}
    //verifica si la pila esta vacia
    bool pilaVacia() {return inicio == NULL;}
    //agrega un nodo a la pila
    void meterPila(int valor)
    {
        Nodo *nuevo = new Nodo(valor);
        if(inicio == NULL)
        {
            nuevo -> sig = nuevo;
            inicio = nuevo;
        }
        else {
            nuevo->sig = inicio->sig;
            inicio->sig = nuevo;
        }
    }
    //sacar un nodo de la pila
    void sacarPila()
    {
        Nodo *p = inicio ->sig;
        if(inicio == inicio->sig) //solo hay un nodo
            inicio = NULL;
        else
            inicio->sig = p->sig;
        delete p;
    }
private:
    Nodo *inicio;
};

#endif
