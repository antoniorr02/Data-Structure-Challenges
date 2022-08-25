#include "bintree.h"
#include <list>
#include <iostream>
#include <cmath>

/**
 * @brief Función recursiva que comprueba si dos arboles tienen las mismas ramificaciones
 * @param ab1   Arbol bintree
 * @param v1    Raiz del arbol 1
 * @param ab2   Arbol bintree
 * @param v2    Raiz del arbol 2
 * @return true si tienen la misma estructura y false en caso contrario
*/

template <class T>
bool misma_estructura(bintree<T>& ab1, typename bintree<T>::node v1, bintree<T>& ab2, typename bintree<T>::node v2) {
    bool misma_estrtc = true;
    if (!v1.null() && !v2.null()) {
        misma_estrtc = (misma_estructura(ab1, v1.left(), ab2, v2.left()) && misma_estructura(ab1, v1.right(), ab2, v2.right()));
    } else {
        misma_estrtc = (v1.null() == v2.null());
    }
    return misma_estrtc;
}

/**
 * @brief Función que comprueba si un arbol es menor que otro. Esto solo lo realiza para arboles con las mismas ramificaciones
 * @param ab1   Arbol bintree
 * @param ab2   Arbol bintree
 * @return true si tienen la misma estructura y ab1 es menor que ab2 y false en caso contrario
*/

template <class T>
bool es_inferior(bintree<T>& ab1, bintree<T>& ab2) {
    bool es_inferior = misma_estructura(ab1, ab1.root(), ab2, ab2.root());
    for (bintree<int>::preorder_iterator it1 = ab1.begin_preorder(), it2 = ab2.begin_preorder(); it1 != ab1.end_preorder() && it2 != ab2.end_preorder() && es_inferior; ++it1, ++it2) {
        if (*it1 >= *it2) {
            es_inferior = false;
        }
    }
    return es_inferior;
}

int main() {

    bintree<int> Arb1(8);
    Arb1.insert_left(Arb1.root(), 2);
    Arb1.insert_right(Arb1.root(), 9);
    Arb1.insert_left(Arb1.root().left(), 6);
    Arb1.insert_right(Arb1.root().left(), 8);
    Arb1.insert_right(Arb1.root().left().right(), 4);
    Arb1.insert_left(Arb1.root().right(), 1);

    bintree<int> Arb2(20);
    Arb2.insert_left(Arb2.root(), 20);
    Arb2.insert_right(Arb2.root(), 20);
    Arb2.insert_left(Arb2.root().left(), 20);
    Arb2.insert_right(Arb2.root().left(), 20);
    Arb2.insert_right(Arb2.root().left().right(), 20);
    Arb2.insert_left(Arb2.root().right(), 20);

    std::cout << "Es inferior: " << es_inferior(Arb1, Arb2);
}