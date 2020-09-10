#include <iostream>
#include <cstdio>
#include "captura.h"

using namespace std;


const char* FILE_CAPTURA = "datos/capturas.dat";


int cantidad_capturas() {
	int cantidad;
	FILE* pFile;

	pFile = fopen(FILE_CAPTURA, "rb");

	if (pFile == NULL) {
		return 0;
	}

	fseek(pFile, 0, SEEK_END);

	cantidad = ftell(pFile) / sizeof(Captura);

	fclose(pFile);

	return cantidad;
}


void mostrar_captura(Captura reg) {

	cout << "Codigo: " << reg.id<< endl;
	cout << "Codigo Parcipante: " << reg.idParticipante << endl;
	cout << "Hora: " << reg.hora << endl;
	cout << "Especie: " << reg.especie << endl;
	cout << "Peso: " << reg.peso << endl;
	cout << "Longitud: " << reg.longitud << endl;
	cout << "Estado: " << reg.estado<< endl;
	
}

void listar_capturas() {
	FILE* pFile;

	pFile = fopen(FILE_CAPTURA, "rb");

	if (pFile == NULL) {

		return;
	}

	Captura reg;

	while (fread(&reg, sizeof(Captura), 1, pFile) == 1) {

		if (reg.estado) {
			mostrar_captura(reg);
			cout << endl;
		}

		
	}


	fclose(pFile);
}


Captura cargar_captura() {
	Captura reg;

	reg.id = cantidad_capturas() + 1;

	cout << "Codigo : " << reg.id << endl;

	// TODO: Validar existencia del participante
	cout << "Codigo Parcipante: ";
	cin >> reg.idParticipante;

	// TODO: Validar todo... xD
	cout << "Hora: ";
	cin >> reg.hora;

	cout << "Especie: ";
	cin >> reg.especie;

	cout << "Peso: ";
	cin >> reg.peso;

	cout << "Longitud: ";
	cin >> reg.longitud;

	reg.estado = true;

	return reg;
}


bool guardar_captura(Captura reg) {

	FILE* pFile;
	bool bGrabo = true;

	pFile = fopen(FILE_CAPTURA, "ab");

	if (pFile == NULL) {
		return false;
	}

	bGrabo = fwrite(&reg, sizeof(Captura), 1, pFile);

	fclose(pFile);

	return bGrabo;
}



bool guardar_captura(Captura reg, int pos) {
	FILE* pFile;
	bool bGrabo = true;

	pFile = fopen(FILE_CAPTURA, "rb+");

	if (pFile == NULL) {
		return false;
	}

	fseek(pFile, pos * sizeof(Captura), SEEK_SET);

	bGrabo = fwrite(&reg, sizeof(Captura), 1, pFile);

	fclose(pFile);

	return bGrabo;
}






bool baja_captura() {
	bool bGrabo = true;

	int id, pos;

	cout << "Ingrese Codigo de Captura: ";
	cin >> id;

	pos = buscar_captura(id);

	if (pos != -1) {
		Captura reg;

		reg = leer_captura(pos);
		reg.estado = false;

		bGrabo = guardar_captura(reg, pos);
	}
	else {
		bGrabo = false;
	}

	return bGrabo;
}

int buscar_captura(int id) {
	FILE* pFile;

	pFile = fopen(FILE_CAPTURA, "rb");

	if (pFile == NULL) {
		return -1;
	}

	Captura reg;
	int index = 0;
	while (fread(&reg, sizeof(Captura), 1, pFile) == 1) {
		if (reg.id == id) {
			fclose(pFile);
			return index;
		}

		index++;
	}
	fclose(pFile);
	return -1;
}


Captura leer_captura(int pos) {
	FILE* pFile;
	Captura reg = {};

	pFile = fopen(FILE_CAPTURA, "rb");

	if (pFile == NULL) {
		return reg;
	}

	fseek(pFile, pos*sizeof(Captura), SEEK_SET);

	fread(&reg, sizeof(Captura), 1, pFile);

	fclose(pFile);

	return reg;
}