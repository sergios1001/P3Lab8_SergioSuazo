#include "Soldado.h"

Soldado::Soldado(string _nombre,int _vida,int _fuerza)
{
	vida=_vida;
	fuerza=_fuerza;
	nombre=_nombre;
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
string Soldado::getNombre()
{
	return nombre;
}

int Soldado::Atacar(bool tipo){
	return 0;
}

void Soldado::Defender(int,bool){
	
}

Soldado::~Soldado()
{
}
