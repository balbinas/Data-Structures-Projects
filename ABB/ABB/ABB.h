#ifndef ABB_ABB_h
#define ABB_ABB_h
class NodoArbol
{
public:
    int info;
    NodoArbol *izq, *der;
    NodoArbol( ){ izq = der = NULL; }
    NodoArbol(int dato)
    { info = dato; izq = der = NULL; }
};
class ABB
{
private:
    NodoArbol *raiz;
public:
    //Constructor
    ABB( ) { raiz = NULL; }
    //Destructor
    ~ABB( ) { }
    //Otros métodos de la clase
    bool busca (int valor)
    {
        NodoArbol * p = raiz;
        while (p != NULL)
        {
            if (p->info == valor)
                return true;
            else
                p=(p->info > valor? p->izq: p->der);
        }
        return false;
    }
    NodoArbol* encuentraPadre (int valor)
    {
        NodoArbol *padre, *hijo;
        hijo = raiz;
        padre = NULL;
        while (hijo != NULL && hijo->info != valor) { padre = hijo; hijo = (hijo->info > valor ? hijo->izq : hijo->der); } return padre;
    }
    void meterABB (int valor)
    {
        NodoArbol *padre = encuentraPadre(valor);
        NodoArbol *nuevo = new NodoArbol (valor);
        if( padre == NULL) //Agrega el primer nodo del árbol
            raiz = nuevo;
        else
        { //Agrega un nodo hoja
            if ( padre->info > valor )
                padre->izq = nuevo;
            else
                padre->der = nuevo;
        }
    }
    NodoArbol* predecesor (NodoArbol *actual)
    {
        NodoArbol *p = actual->izq;
        while (p->der != NULL )
            p = p->der;
        return p;
    }
    NodoArbol* sucesor (NodoArbol *actual)
    { NodoArbol *p = actual->der; while (p->izq != NULL ) p = p->izq; return p; }
    
    void sacarABB(int valor)
    {
        NodoArbol *padre = encuentraPadre(valor);
        NodoArbol *nodoABorrar;
        if (padre == NULL) nodoABorrar = raiz;
        else nodoABorrar=(padre->info > valor? padre->izq : padre->der);
        //Encontrar substituto cuando el nodo a borrar tiene 2 hijos
        if (nodoABorrar->izq != NULL && nodoABorrar->der != NULL) { NodoArbol *substituto = predecesor(nodoABorrar); int nuevovalor = substituto->info; sacarABB (substituto->info);
            nodoABorrar->info = nuevovalor; } else if (padre == NULL) {
            //Borra nodo raíz el cual solo tiene un hijo
            if (nodoABorrar->der == NULL)
                raiz = nodoABorrar->izq; else raiz = nodoABorrar->der; }
                else if (padre->info > valor) //Borra nodo con 0 o 1 hijo
                if (nodoABorrar->izq == NULL)
                    padre->izq = nodoABorrar->der;
                else padre->izq = nodoABorrar->izq;
            else if (nodoABorrar->der == NULL)
                padre->der =nodoABorrar->izq;
        else padre->der = nodoABorrar->der;
    }
    int menor()
    {//el arbol debe tener nodos
        NodoArbol *p = raiz;
        while(p->izq != NULL) p = p->izq;
        return p->info;
    }
    void ancestros(int valor)
    {//el valor existe
        NodoArbol *p = raiz;
        if(p->info == valor)
            cout <<"No hay ancestros" <<endl;
        else
        {
            cout <<"Los ancestros son: ";
            while(p->info != valor )
            {
                cout <<p->info <<" ";
                if(p->info < valor)
                    p = p->der;
                else p = p->izq;
            }
            cout <<endl;
            
        }
    }
    int cuentaNodos() { return sacaCuenta(raiz);}
    int sacaCuenta(NodoArbol *r)
    {
        if(r==NULL) return 0;
        return 1+ sacaCuenta(r->izq) + sacaCuenta(r->der);
    }
    int sumaNodos() {return sacaSuma(raiz);};
    int sacaSuma(NodoArbol *r)
    {
        if(r==NULL) return 0;
        return r->info + sacaSuma(r->izq) + sacaSuma(r->der);
    }

};

#endif
