//
//  Conjunto.h
//  Programa4
//
//  Created by Balbina Santana  A00812215 on 7/3/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#ifndef Programa4_Conjunto_h
#define Programa4_Conjunto_h
#include <iostream>
using namespace std;

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

class ListaLineal{
    friend bool operator == (const ListaLineal& L1, const ListaLineal& L2)
    {
        Nodo *p1 = L1.inicio;
        Nodo *p2 = L2.inicio;
        while(p1 != NULL && p2 !=NULL)
        {
            if(p1-> info != p2->info)
                return false;
            p1 = p1->sig;
            p2 = p2->sig;
        }
        return (p1 == p2);
    }
public:
    ListaLineal ( ) { inicio = NULL;} //crea la lista
    ListaLineal(const ListaLineal& L)
    {
        Nodo *p = L.inicio;
        inicio = NULL; //inicio del this al que le voy a copiar la lista
        while( p != NULL)
        {
            meterFinalLista(p->info);
            p = p->sig;
        }
    }
    ~ListaLineal( )
    {
        while(!listaVacia()) sacarInicioLista();
    }
    bool listaVacia( ) { return inicio == NULL; }
    int observaLista() { return inicio -> info; }
    void meterInicioLista(int valor)
    {//Caso1: listaVacia ... Caso2: Lista con nodos (para checar que jale el programa)
        Nodo *nuevo = new Nodo(valor, inicio);
        inicio = nuevo;
    }
    void sacarInicioLista()
    {//Precondicion: la lista debe tener nodos
        //Caso1: sacar un nodo ... Caso2: sacar el ultimo nodo
        Nodo *p = inicio;
        inicio = inicio -> sig;
        delete p;
    }
    void despliegaLista()
    {
        Nodo *p = inicio;
        while(p != NULL)
        {
            cout <<p -> info <<" ";
            p = p ->sig;
        }
        cout <<endl;
    }
    bool buscaLista(int valor)
    {
        Nodo *p = inicio;
        while( p!= NULL && p->info !=valor) p = p->sig;
        return (p !=NULL);
    }
    void meterFinalLista(int valor)
    {
        Nodo *nuevo = new Nodo(valor);
        if(inicio == NULL)
            inicio = nuevo;
        else
        {
            Nodo *p = inicio;
            while(p->sig != NULL) p = p->sig;
            p->sig = nuevo;
        }
    }
    ListaLineal& operator = (const ListaLineal& L)
    {
        if(this != &L)
        {
            while( inicio != NULL) sacarInicioLista();
                Nodo *p = L.inicio;
            inicio = NULL; //inicio del this al que le voy a copiar la lista
            while( p != NULL)
            {
                meterFinalLista(p->info);
                p = p->sig;
            }
        }
        return *this;
    }
    Nodo *inicio;
    
};

class Conjunto{
    friend Conjunto operator+ (Conjunto & C1, Conjunto & C2){
        Conjunto x;
        x.elementos = C1.elementos;
        x.cardinalidad = C1.cardinalidad;
        Nodo *p = C2.elementos.inicio;
        while(p!=NULL)
        {
            if(!x.elementos.buscaLista(p->info))
            {
                x.agrega(p->info);
                x.cardinalidad++;
            }
            p = p -> sig;
        }
        return x;
    }
    friend Conjunto operator- (Conjunto & C1, Conjunto & C2){
        Conjunto x;
        Nodo *p = C1.elementos.inicio;
        while(p!=NULL)
        {
            if(!C2.elementos.buscaLista(p->info))
            {
                x.agrega(p->info);
                x.cardinalidad++;
            }
            p = p -> sig;
        }
        return x;
    }
    friend Conjunto operator* (Conjunto & C1, Conjunto & C2){
        Conjunto x;
        Nodo *p = C1.elementos.inicio;
        while(p!=NULL)
        {
            if(C2.elementos.buscaLista(p->info))
            {
                x.agrega(p->info);
                x.cardinalidad++;
            }
            p = p -> sig;
        }
        return x;
    }
private:
    int cardinalidad;
    ListaLineal elementos;
public:
    Conjunto(){
        cardinalidad = 0;
    }
    int laCardinaldad(){
        return cardinalidad;
    }
    void agrega(int valor){
        if(!elementos.buscaLista(valor))
        {
            elementos.meterInicioLista(valor);
            cardinalidad++;
        }
    }
    bool pertenencia(int valor){
        return elementos.buscaLista(valor);
    }
    void despliega(){
        elementos.despliegaLista();
    }
    
};

#endif
