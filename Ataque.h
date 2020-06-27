#ifndef ATAQUE_H
#define ATAQUE_H

#include "Soldado.h"

class Ataque : public Soldado
{
	public:
		Ataque(int,int,int,int,string);
		
		int Atacar(bool);
		void Defender(int,bool);
		int getVelocidad();
		int getExtra();
		
		~Ataque();
	protected:
		int extra,velocidad;
		friend class ArchivoBinario;
};

#endif
