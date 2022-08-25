#include<iostream>
#include<list>

using namespace std;

/**
 * @brief La función obtiene la sublista más larga con elementos pares consecutivos.
 * @param L Lista sobre la que sacar la sublista.
 * @return list<int> Sublista de pares.
 *
 */
list<int> max_sublist_par(list<int> &L) {
	list<int> aux, sublista;
	for (auto it = L.begin(); it != L.end(); it++) {
		for (auto n = it; (*n)%2==0 && n != L.end(); n++) {
			aux.push_back(*n);
		}
		if (sublista.size() < aux.size()) {
			sublista = aux;
		}
		aux.clear();
	}
	return sublista;
}

int main() {
	list<int> ejemplo = {1,2,4,6,5,0,2,4};
	
	for (auto it = ejemplo.begin(); it != ejemplo.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	list<int> suma = max_sublist_par(ejemplo);
	cout << "La sublista con mayor cantidad de pares consecutivos es: { ";
	for (auto it = suma.begin(); it != suma.end(); it++) {
		cout << *it << " ";
	}	
	cout << "}" << endl;
	return 0;

}