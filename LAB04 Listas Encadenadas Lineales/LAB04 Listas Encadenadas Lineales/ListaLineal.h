//
//  ListaLineal.h
//  LAB04 Listas Encadenadas Lineales
//
//  Created by Balbina Santana on 27/2/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#ifndef LAB04_Listas_Encadenadas_Lineales_ListaLineal_h
#define LAB04_Listas_Encadenadas_Lineales_ListaLineal_h


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
        if(inicio ==NULL)
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
private:
    Nodo *inicio;

};

#endif
