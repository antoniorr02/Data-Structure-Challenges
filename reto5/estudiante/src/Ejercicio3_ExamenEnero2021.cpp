#include <iostream>
#include <vector>
#include <list>
#include "bintree.h"

using namespace std;

bool camino_especial (bintree<int> A, bintree<int> :: node n, int k) {
    vector<list<int>> caminos;
    bool encontrado = false;
    bintree<int>::preorder_iterator it = A.begin_preorder();
    for (; *it != *n; ++it); // Obtengo el iterador del nodo.

    int cont = 0;
    for (; it != A.end_preorder(); ++it) {
        caminos[cont].push_back(*it); // metemos en las list los diferentes caminos
        if (it.is_leaf()) {
            cont++; // significa que comenzaremos un nuevo camino porque el que estabamos recorriendo termina al encontrar una hoja.
            caminos[cont].push_back(*n); // el nodo aparece en todos los caminos
        }
    } // esto tiene un fallo y es que se pierden partes del camino, pues solo funcionará cuando no haya hijos a la derecha en mitad del recorrido

///////////////////////////////////////////////// Forma correcta.

//        if (n.null())
//            return encontrado; // falso
//    for (; it != A.end_preorder(); ++it) {
//        if (!n.left().null())
//            n = n.left();
//        else if (!n.right().null())
//            n = n.right();
//        else {
//            while ((!n.parent().null()) &&
//                   (n.parent().right() == n ||
//                    n.parent().right().null()))
//                n = n.parent();
//            if (n.parent().null())
//                n = typename bintree<int>::node();
//            else
//                n = n.parent().right();
//        }
//    } // Debería de ir insertando con push_back en las diferentes listas y segun como avanzara el iterador ir cambiando de lista
////////////////////////////////////////////////

    int suma_camino = 0;
    for (int i = 0; i < caminos.size(); i++) {
        for (auto a = caminos[i].begin(); a != caminos[i].end(); ++i) {
            suma_camino += *a;
        }
        if (suma_camino == k) {
            for (auto a = caminos[i].begin(); a != caminos[i].end(); ++i) {
                cout << *a << " ";
            } // Imprime camino especial
            i = caminos.size(); // sale del bucle al encontrar el camino
            encontrado = true;
        } else {
            suma_camino = 0;
        }
    }

    return encontrado;
}

vector<list<int> >getCaminos(bintree<int>::node n,list<int> prefijo){
    if (n.null()){
        vector<list<int> > aux;
        aux.push_back(prefijo);
        return aux;
    }
    else {
        vector<list<int> > izq, der;
        if ((n.left().null()) && n.right().null()) {
            izq.push_back(prefijo);
            return izq;
        }
        if (!(n.left().null())) {
            list<int> aux = prefijo;
            aux.push_back(*(n.left()));
            izq = getCaminos(n.left(), aux);
        }
        if (!(n.right().null())) {
            list<int> aux = prefijo;
            aux.push_back(*(n.right()));
            der = getCaminos(n.right(), aux);
        }
        for (auto it = izq.begin(); it != izq.end(); ++it)
            der.push_back(*it);

        return der;
    }
}


int main() {}