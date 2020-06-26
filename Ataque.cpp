#include "Ataque.h"

Ataque::Ataque(int velocidad,int extra,int vida,int fuerza,string nombre):Soldado(nombre,vida,fuerza)
{
	this->velocidad=velocidad;
	this->extra=extra;
}

int Ataque::Atacar(bool tipo){
	if(tipo){
		return fuerza*10;
	}
	else
	{
		return fuerza*(10+(velocidad * 2));
	}
}

void Ataque::Defender(int damage,bool tipo)
{
	if(tipo){
		setVida(getVida()-damage);
	}
	else
	{
		setVida(getVida()-(damage/this->extra));
	}
}

Ataque::~Ataque()
{
}
