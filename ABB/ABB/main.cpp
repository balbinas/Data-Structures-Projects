//
//  main.cpp
//  ABB
//
//  Created by Balbina Santana on 12/4/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
    using namespace std;
#include "ABB.h"
    
    int main(int argc, const char * argv[])
    {
        
        ABB A;
        A.meterABB(5);
        A.meterABB(3);
        A.meterABB(1);
        A.meterABB(4);
        A.meterABB(8);
        A.meterABB(6);
        A.meterABB(9);
        /*cout << "Menor: " << A.menor() << endl;
        int numero;
        cout << "Numero: ";
        cin >> numero;
        A.ancestros(numero);
        if (A.busca(numero))
            cout << "Si se encuentra" << endl;
        else cout << "No se encuentra" << endl;
        A.sacarABB(5);
        A.sacarABB(9);
        A.sacarABB(3);
        A.sacarABB(6);
        */
        cout <<A.cuentaNodos();
        cout <<endl;
        cout <<A.sumaNodos();
        return 0;
}

