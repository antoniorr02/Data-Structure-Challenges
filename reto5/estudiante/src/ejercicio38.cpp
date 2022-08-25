//
// Created by antonio on 22/12/21.
//
#include <iostream>
#include "bintree.h"

using namespace std;

bool seleccion(bintree<int> & A) {
    bool check = true;
    bintree<int>::node a = A.root();
    int menor;
    for (bintree<int>::preorder_iterator it = A.begin_preorder(); it != A.end_preorder(); ++it) {
        if (!a.left().null() && !a.right().null()) {
            if (*a.left() < *a.right()) menor = *a.left();
            if (*a.left() > *a.right()) menor = *a.right();
            if (*a != menor) {
                check = false;
                it = A.end_preorder();
            }
        }

        if (!a.left().null()) {
            a = a.left();
        } else if (!a.right().null()) {
            a = a.right();
        } else {
            while ((!a.parent().null()) && (a.parent().right() == a || a.parent().right().null())) {
                a = a.parent();
            }
            if (a.parent().null()) {
                a = typename bintree<int>::node();
            } else {
                a = a.parent().right();
            }
        }

    }
    return check;
}

int main(int argc, char ** argv) {
    bintree<int> arbol(2);
    arbol.insert_left(arbol.root(), 5);
    arbol.insert_right(arbol.root(), 2);
    arbol.insert_left(arbol.root().left(), 5);
    arbol.insert_right(arbol.root().left(), 7);

    if(seleccion(arbol))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}