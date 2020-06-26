#include "Soporte.h"

Soporte::Soporte(int blindaje,int camuflaje,int vida,int fuerza):Soldado(vida,fuerza)
{
	this->blindaje=blindaje;
	this->camuflaje=camuflaje;
}

int Soporte::Atacar(bool tipo){
	if(tipo){
		return fuerza*(15 + camuflaje);
	}
	else
	{
		return fuerza * 10;
	}
}

void Soporte::Defender(int damage,bool tipo){
	if(tipo)
	{
		setVida(getVida()-(damage/(blindaje*2)));
	}
	else
	{
		setVida(getVida()-damage);
	}
}

Soporte::~Soporte()
{
}
