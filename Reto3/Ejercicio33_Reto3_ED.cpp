#include<iostream>
#include<list>

using namespace std;

/**
 * @brief La función obtiene la máxima distancia que se puede obtener entre el mínimo y el máximo a partir de m elementos de una lista.
 * @param L Lista sobre la que calcular la distancia entre el máximo y el mínimo.
 * @return int Distancia entre el máximo y el mínimo.
 *
 */
int dminmax (list<int> & L) {
	int distancia;
	int pos_max, pos_min;
	int max, min; 
	max = min = L.front();
	
	int a = 0;
	for (auto it = L.begin(); it != L.end(); ++it) {
		a++;
		if (max < *it) {
			pos_max = a;
			max = *it;
		}
		if (min > *it) {
			pos_min = a;
			min = *it;
		}
	}
	cout << "Máximo: " << pos_max << endl;
	cout << "Mínimo: " << pos_min << endl;
	distancia = pos_max - pos_min;
	return distancia;
}

int main() {
	list<int> ejemplo = {5,9,3,2,4,1,6};
	
	for (auto it = ejemplo.begin(); it != ejemplo.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	int dist = dminmax(ejemplo);
	cout << "La distancia es: " << dist << endl;
	return 0;

}	