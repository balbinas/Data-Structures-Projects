//
//  FilaArreglo.h
//  programa6
//
//  Created by Balbina Santana on 23/4/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#ifndef programa6_FilaArreglo_h
#define programa6_FilaArreglo_h

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

class FilaArreglo{
public:
    FilaArreglo() {//constructor frente y fin = -1 = fila vacia
        frente = -1;
        fin = -1;
        MAX = 50;}
    FilaArreglo(int N){
        frente = -1;
        fin = -1;
        MAX = N;
    }
    bool filaVacia(){return frente == -1;}
    void meterFila(int valor){
        fin = (fin + 1) % MAX;
        datos[fin] = valor;
        if (frente == -1) frente++;
    }
    int observaFila(){return datos[frente];}
    void sacarFila(){
        if (frente == fin)
            frente = fin = -1;
        else frente = (frente + 1) % MAX;
    }
private:
    Nodo *inicio;
    int datos[50];
    int frente, fin, MAX; //indica casilla que se encuentra el primer elemento agregado a la fila
        //indica lugar ultimo nodo fila
};

#endif
