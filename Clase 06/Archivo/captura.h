#pragma once

struct Captura {
	int id;
	int idParticipante;
	int hora;
	int especie;
	float peso;
	float longitud;
	bool estado;
};

int cantidad_capturas();

Captura cargar_captura();
void mostrar_captura(Captura );
void listar_capturas();

bool baja_captura();

bool guardar_captura(Captura);
bool guardar_captura(Captura, int);

bool leer_captura(Captura*, int);
Captura leer_captura(int);

int buscar_captura(int);

