#include "Soldado.h"

Soldado::Soldado(int _vida,int _fuerza)
{
	vida=_vida;
	fuerza=_fuerza;
}

int Soldado::getVida(){
	return vida;
}

void Soldado::setVida(int _vida){
	vida=_vida;
}

int Soldado::getFuerza(){
	return fuerza;
}

int Soldado::Atacar(bool tipo){
	return 0;
}

void Soldado::Defender(int,bool){
	
}

Soldado::~Soldado()
{
}
