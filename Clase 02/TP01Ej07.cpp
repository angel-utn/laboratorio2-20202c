#include <iostream>
using namespace std;

void puntoA(bool mat[][6], int tam) {

	cout << "    1 2 3 4 5 6" << endl;

	for (int f = 0; f < tam; f++) {
		cout << f + 100 << " ";
		for (int c = 0; c < 6; c++) {

			if (mat[f][c]) {
				cout << "X ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}

void puntoB(bool mat[][6], int tam) {
	bool todofalso = true;
	cout << endl;

	for (int f = 0; f < tam; f++) {
		todofalso = true;
		for (int c = 0; c < 6; c++) {
			if (mat[f][c]) {
				todofalso = false;
			}
		}

		if (todofalso) {
			cout << f + 100 << endl;
		}
	}
}

int main() {
	
	int socio, cuota;
	bool pagos[50][6] = {};

	cout << "Ingrese N Socio: ";
	cin >> socio;

	while (socio >= 100 && socio <= 149){

		cout << "Ingrese N Cuota: ";
		cin >> cuota;

		pagos[socio - 100][cuota - 1] = true;

		cout << "Ingrese N Socio: ";
		cin >> socio;
	}

	puntoA(pagos, 5);
	puntoB(pagos, 5);

	return 0;
}

