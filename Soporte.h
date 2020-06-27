#ifndef SOPORTE_H
#define SOPORTE_H

#include "Soldado.h"

class Soporte : public Soldado
{
	public:
		Soporte(int,int,int,int,string);
		
		int Atacar(bool);
		void Defender(int,bool);
		int getBlindaje();
		int getCamuflaje();
		
		~Soporte();
	protected:
		int blindaje, camuflaje;
		friend class ArchivoBinario;
};

#endif
