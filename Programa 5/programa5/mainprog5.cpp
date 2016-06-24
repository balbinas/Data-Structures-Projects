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
            cout<<p->info<<" ";
            p=p->sig;
        }
        cout<<p->info<<" ";
    }

    ~PilaCircular()
    {
        while (!pilaVacia())
            sacarPila();
    }
};

void sumaPila(PilaCircular &PA, PilaCircular &PB, PilaCircular &PC)
{
    int NumPA, NumPB, NumPC;
    int aux;
    int sobra=0;
    while (!PA.pilaVacia()&&!PB.pilaVacia())
    {
        NumPA=PA.observaPila();
        NumPB=PB.observaPila();
        PA.sacarPila();
        PB.sacarPila();

        NumPC=NumPA+NumPB+sobra;

        if (NumPC<=9)
        {
            sobra=0;
            PC.meterPila(NumPC);
        }
        else
        {
            sobra=1;
            NumPC=NumPC-10;
            PC.meterPila(NumPC);
        }
    }
    if(sobra==1)
    {
        PC.meterPila(sobra);
    }
}

int main()
{
    ifstream ArchivoEntrada;
    string texto;
    PilaCircular PA, PB, PC;
    char numero;
    int x;

    cout<<"Teclea el nombre del archivo de entrada"<<endl;
    cin>>texto;
    //ArchivoEntrada.open(texto+".txt");
    ArchivoEntrada.open(texto.c_str());

    //ArchivoEntrada.get(numero);
    //    cout<< numero << "#" ;
    bool pasa = false;
    int cont=0;
    while (!ArchivoEntrada.eof())
    {
        ArchivoEntrada.get(numero);
        if (numero == '\n' && !ArchivoEntrada.eof() )
        {
        pasa = true;
        cont++;
        }

        if (pasa==false)
        {
        //cout<<numero;
        x= atoi(&numero);
        //cout<<x<<" ";
        if((x>=0&&x<=9))
        PA.meterPila(x);

      }

        //cout<<PA.observaPila();

       // cout<<endl<<endl;
        //PA.despliega();
    if (pasa && cont ==1)
    {
        x= atoi (&numero);
        if (x>=0&&x<=9)
        PB.meterPila(x);
        //cout<<PB.observaPila();
    }

    }
   // cout<<endl<<endl;
    //PB.despliega();
    sumaPila(PA,PB,PC);
    while(!PC.pilaVacia())
    {
        cout<<PC.observaPila();
        PC.sacarPila();
    }
    //PC.despliega();
    return 0;
}
