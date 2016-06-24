//
//  main.cpp
//  grafos09
//
//  Created by Balbina Santana on 24/4/13.
//  Copyright (c) 2013 Balbina Santana. All rights reserved.
//

#include <iostream>
#include "clasegrafos.h"
using namespace std;

int main(int argc, const char * argv[])
{
    Grafo uno;
    uno.meterNodo("A");
    uno.meterNodo("B");
    uno.meterNodo("C");
    uno.meterNodo("D");
    uno.meterNodo("E");
    uno.depthFirst();
    uno.sacarNodo("A");
    
    return 0;
}

