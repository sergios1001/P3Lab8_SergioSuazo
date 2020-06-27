#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "Soldado.h"

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <vector>
using std::vector;


class Archivo
{
	public:
		Archivo(string);
		//escritura / salida
		virtual bool guardarSoldado(Soldado*,int );
		virtual bool abrirEscritura(int);
		bool cerrarEscritura();
		//lectura /entrada
		
		//abrir archivo
		virtual bool abrirLectura();
		//cerrar archivo
		bool cerrarLectura();
		
		
		//Leer todos los registros del archivo
		//cargar todos los registros en vector de apuntadores

		virtual vector<Soldado*> leerSoldados();
		
		
		
		
		
	protected:
		string fileName;
		ofstream outputFile;
		int modoEscritura;
		ifstream inputFile;
		
};

#endif
