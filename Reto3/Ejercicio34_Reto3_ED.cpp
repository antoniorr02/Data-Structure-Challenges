#include<iostream>
#include<list>

using namespace std;

/**
 * @brief La función compara dos listas con lo que devuelve true si la lista L1 es mayor que la L2 en sentido “lexicográfico”.
 * @param L1 Primera lista.
 * @param L2 Segunda lista.
 * @return bool Si L1 > L2.
 *
 */
bool lexicord (list<int> L1, list<int> L2) {
	bool longer = false;
	list<int> copia1, copia2;
	copia1 = L1;
	copia2 = L2;
	
	bool cortar_bucle = false;
	while (!cortar_bucle) {
		if (copia1.front() != copia2.front()) {
			if (copia1.front() > copia2.front()) {
				longer = true;
				cortar_bucle = true;
			} else {
				longer = false;
				cortar_bucle = true;
			}
		} else if (!copia1.empty() && !copia2.empty()) {
			copia1.pop_front();
			copia2.pop_front();
		}
		if (copia1.empty() && copia2.empty()) cortar_bucle = true;
	}

	if(!cortar_bucle && (copia1.size() > copia2.size())) longer = true;


	return longer;
}

int main() {
	list<int> L1 = {1,3,3,4,5};
	list<int> L2 = {1,3,3}; 

	for (auto it = L1.begin(); it != L1.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	for (auto it = L2.begin(); it != L2.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	if(lexicord(L1, L2))
		cout << "L1 es mayor que L2" << endl;
	else
		cout << "L2 es mayor que L1" << endl;

	return 0;

}	