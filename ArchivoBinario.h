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
		
	//	virtual bool guardarAlumno(Alumno*);
		virtual bool guardarPersona(Persona*);
		virtual bool abrirEscritura(int);
		
		
		virtual bool abrirLectura();
	//virtual vector<Alumno*> leerAlumnos();
		virtual vector<Persona*> leerPersonas();
		
	protected:
};

#endif
