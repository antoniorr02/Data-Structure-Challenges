#include<iostream>
#include<list>

using namespace std;

/**
 * @brief La función obtiene la máxima suma que se puede obtener a partir de m elementos de una lista.
 * @param L Lista sobre la que calcular la suma.
 * @param m Número de elementos a sumar.
 * @return int Con la suma máxima de m elementos consecutivos de L.
 *
 */
int max_sublist_m(list<int> &L, int m) {
	int suma = 0;
	int a = 0;
	for (auto it = L.begin(); it != L.end(); ++it) {
		int aux = 0;
		int i = 0;
		for (auto n = it; i < m && a+m < L.size(); ++n) {
			aux += *(n);
			i++;
		}
		if (suma < aux) {
			suma = aux;
		}
		a++;
	}
	return suma;
}

int main() {
	list<int> ejemplo = {1,2,-5,4,-3,2};
	
	for (auto it = ejemplo.begin(); it != ejemplo.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	int suma = max_sublist_m(ejemplo, 4);
	cout << "La máxima suma que se puede obtener es: " << suma << endl;
	return 0;

}	