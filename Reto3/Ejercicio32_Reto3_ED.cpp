#include<iostream>
#include<list>

using namespace std;

/**
 * @brief La función traslada los primeros n elementos de la lista al final de la misma
 * @param L Lista a rotar
 * @param n Número de elementos a colocar al final de la lista.
 *
 */
void rotalista(list<int> & L, int n) {
	for (int i = 0; i < n; i++) {
		L.insert(L.end(),L.front());
		L.pop_front();
	}
}

int main() {
	list<int> ejemplo;
	for (int i = 0; i < 8; i++) {
		ejemplo.push_back(i);
	}
	cout << "Antes de rotar" << endl;
	for (auto it = ejemplo.begin(); it != ejemplo.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	rotalista(ejemplo, 2);
	cout << "Después de rotar la lista" << endl;
	for (auto it = ejemplo.begin(); it != ejemplo.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;

}