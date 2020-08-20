#include <iostream>
using namespace std;

int buscar_indice(int v[], int t, int legajo_buscado) {

	for (int i = 0; i < t; ++i) {
		if (v[i] == legajo_buscado || v[i] == 0) {
			return i;
		}
	}
}

void puntoA(int legajos[], int inscripciones[], int t) {
	for (int i = 0; i < t; ++i) {
		if (legajos[i] != 0) {
			cout << "Legajo: " << legajos[i] << endl << "Cantidad: " << inscripciones[i] << endl;
		}
	}
}


int main() {
	int legajo, nota, legajos[380] = {}, inscripciones[380] = {}, indice;

	cout << "Legajo: ";
	cin >> legajo;

	while (legajo != 0) {
		cout << "Nota: ";
		cin >> nota;

		indice = buscar_indice(legajos, 380, legajo);
		legajos[indice] = legajo;
		inscripciones[indice]++;

		cout << "Legajo: ";
		cin >> legajo;
	}

	cout << endl;

	puntoA(legajos, inscripciones, 380);


	return 0;
}