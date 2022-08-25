//
// Created by antonio on 21/12/21.
//
#include <iostream>
#include "bintree.h"

using namespace std;

/**
 * Para la resolución del ejercicio me he basado en el iterator()++ en pre-orden, buscando el nodo que queremos
 * y aumentando o decrementando el entero n inicializado a 0 según nos movemos niveles por el árbol.
 */

template <class T>
int enquenivel(bintree<T>& arbol, typename bintree<T>::node w) {

    int n = 0;

    auto a = arbol.root();

    if (a.null()) {
        n = 0;
    }

    for (auto it = arbol.begin_preorder(); *it != *w; ++it) {
        if (!a.left().null()) {
            a = a.left();
            n++;
        } else if (!a.right().null()) {
            a = a.right();
            n++;
        } else {
            while ((!a.parent().null()) && (a.parent().right() == a || a.parent().right().null())) {
                n--;
                a = a.parent();
            }
            if (a.parent().null()) {
                a = typename bintree<T>::node();
            } else {
                a = a.parent().right();
            }
        }
    }
    return n;
}

int main(int argc, char ** argv) {
    bintree<char> arbol('a');
    arbol.insert_left(arbol.root(), 'b');
    arbol.insert_left(arbol.root().left(), 'c');
    arbol.insert_left(arbol.root().left().left(), 'd');
    arbol.insert_left(arbol.root().left().left().left(), 'e');
    arbol.insert_right(arbol.root(), 'f');

    bintree<char>::node nodo('e');

    cout << "La profundidad es: " << enquenivel(arbol, nodo) << endl;
}