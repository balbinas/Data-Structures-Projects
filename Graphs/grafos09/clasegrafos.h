//
//  clasegrafos.h
//  grafos09
//
//  Created by Balbina Santana on 24/4/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//
/*
#ifndef grafos09_clasegrafos_h
#define grafos09_clasegrafos_h
#define MAX_NOD
#include <iostream>
using namespace std;

class Nodo{
public:
    Nodo *sig;
    string info;
    Nodo( ) { sig = NULL; }
    Nodo (string dato) { info = dato; sig = NULL; }
    Nodo (string dato, Nodo *Siguiente)
    {
        info = dato; sig = Siguiente;
    }
};

class Grafo{
private:
    Nodo *inicio;
    string grafos[50][50];
    bool arco[50][50];
    int cantidadNodos;
    bool status[MAX_NOD];
public:
    Grafo(){
        inicio = NULL;
        grafos[49][49];
        arco[49][49] = false;
        cantidadNodos = 0;
        status[MAX_NOD];
    }
bool grafoVacio(){
    return inicio == NULL;
}
void meterNodo(string node){
    //agrega nodo
    Nodo *nuevo = new Nodo(node);
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
void meterArco(int arc){
    //agrega arco
}
void sacarNodo(){
    //borrar nodo
    Nodo *p = inicio ->sig;
    if(inicio == inicio->sig) //solo hay un nodo
        inicio = NULL;
    else
        inicio->sig = p->sig;
    delete p;
}
void sacarArco(){
    //sacar arco
}
bool buscaNodo(string node){
    //esta o no esta;
    if(inicio->sig->info != NULL){return true;}
    return false;
}
    bool status[MAX_NOD];
    fill_n(status, MAX_NOD, false);
    //status false = en espera ... true = procesado
void depthFirst(){
    status = "en espera";
    Nodo *p = inicio;
    while(!grafoVacio()){
        cout<<p->info<<" ";
        p=p->sig;
        status = "procesando";
    }
    Nodo *nuevo = new Nodo(node);
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
};
#endif
*/


#ifndef PracticeOne_Grafo_h
#define PracticeOne_Grafo_h

#include <stack>
#include <queue>
using namespace std;
typedef stack <string> Stack;
typedef queue <string> Queue;

class Grafo {
#define MAX_NOD 50
    
private:
    string info[MAX_NOD];
    bool links[MAX_NOD][MAX_NOD];
public:
    Grafo(){
        fill_n(links, MAX_NOD, false);
        fill_n(info, MAX_NOD, "nil");
    }
    bool grafoVacio(){
        for(int i = 0;i<MAX_NOD;i++)
            if(info[i]!="nil")
                return false;
        return true;
    }
    bool grafoLleno(){
        for(int i = 0;i<MAX_NOD;i++)
            if(info[i]=="nil")
                return false;
        return true;
    }
    
    void meterNodo(string a){
        if(!grafoLleno())
            for(int i = 0;i<MAX_NOD;i++)
                if(info[i]=="nil"){
                    info[i] = a;
                    i = MAX_NOD;
                }
    }
    void meterArco(string a, string b){
        if (buscaNodo(a) && buscaNodo(b) ){
            links[indexNodo(a)][indexNodo(b)] = true;
            links[indexNodo(b)][indexNodo(a)] = true;
        }
    }
    void sacarNodo(string a){
        for(int i = 0;i<MAX_NOD;i++)
            if(info[i]==a){
                info[i]="nil";
                for(int j = 0; j<MAX_NOD;j++){
                    links[i][j]=false;
                    links[j][i]=false;
                }
            }
    }
    
    void sacarArco(string a, string b){
        if (buscaNodo(a) && buscaNodo(b) ){
            links[indexNodo(a)][indexNodo(b)] = false;
            links[indexNodo(b)][indexNodo(a)] = false;
        }
    }
    int indexNodo(string a){
        for(int i = 0;i<MAX_NOD;i++)
            if(info[i]==a){
                return i;
            }
        return -1;
    }
    bool buscaNodo(string a){
        for(int i = 0;i<MAX_NOD;i++)
            if(info[i]==a){
                return true;
            }
        return false;
    }
    void depthFirst(){
        int status[MAX_NOD];
        fill_n(status, MAX_NOD, 0);
        //status 0 en espera, 1 listo, 2 procesado
        Queue p;
        p.push(info[0]);
        status[0] = 1;
        dep(status, 0, p);
    }
    void dep(int status[], int index, Queue p){
        
        
    }
    void breadthFirst() {
        Stack p;
        
    }
};
#endif


