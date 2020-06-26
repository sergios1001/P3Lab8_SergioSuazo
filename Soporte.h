#ifndef SOPORTE_H
#define SOPORTE_H

#include "Soldado.h"

class Soporte : public Soldado
{
	public:
		Soporte(int,int,int,int,string);
		
		int Atacar(bool);
		void Defender(int,bool);
		
		~Soporte();
	protected:
		int blindaje, camuflaje;
};

#endif
