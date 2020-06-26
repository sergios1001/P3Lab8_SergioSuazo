#ifndef ATAQUE_H
#define ATAQUE_H

#include "Soldado.h"

class Ataque : public Soldado
{
	public:
		Ataque(int,int,int,int);
		
		int Atacar(bool);
		void Defender(int,bool);
		
		~Ataque();
	protected:
		int extra,velocidad;
};

#endif
