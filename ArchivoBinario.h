#ifndef ARCHIVOBINARIO_H
#define ARCHIVOBINARIO_H

#include "Archivo.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

class ArchivoBinario : public Archivo
{
	public:
		ArchivoBinario(string);
		
		virtual bool guardarSoldado(Soldado*,int);

		virtual bool abrirEscritura(int);
		
		
		virtual bool abrirLectura();
		virtual vector<Soldado*> leerSoldados();
		
	protected:
};

#endif
