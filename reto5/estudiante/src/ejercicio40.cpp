//
// Created by antonio on 22/12/21.
//
#include <iostream>
#include "bintree.h"

using namespace std;

/**
 * No estoy seguro de si esta sería la solución al problema, pues me ha parecido
 * demasiado inmediata, pero al fin y al cabo estoy recorriendo un árbol en preorden
 * tal y como pide el enunciado.
 */

template <class T>
void RecorrerArbol(bintree<T>& arbol) {
    for (auto it = arbol.begin_preorder(); it != arbol.end_preorder(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char ** argv) {
    bintree<char> arbol('a');
    arbol.insert_left(arbol.root(), 'b');
    arbol.insert_left(arbol.root().left(), 'c');
    arbol.insert_left(arbol.root().left().left(), 'd');
    arbol.insert_left(arbol.root().left().left().left(), 'e');
    arbol.insert_right(arbol.root(), 'f');
    arbol.insert_right(arbol.root().left(), 'g');
    arbol.insert_right(arbol.root().right(), 'h');

    RecorrerArbol(arbol);
}