//
//  main.cpp
//  Programa4
//
//  Created by Balbina Santana on 7/3/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
#include "Conjunto.h"
using namespace std;

int main(int argc, const char * argv[])
    {
        Conjunto C1;
        for(int k=1; k<=5; k++)
            C1.agrega(k);
        Conjunto C2;
        C2.agrega(2);
        C2.agrega(2);
        C2.agrega(4);
        C2.agrega(5);
        C2.agrega(6);
        C1.despliega();
        C2.despliega();
        Conjunto D;
        D = C1 + C2;
        D.despliega();
        D = C1 - C2;
        D.despliega();
        D = C1 * C2;
        D.despliega();
    return 0;
}

