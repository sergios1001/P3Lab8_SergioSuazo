#ifndef SOLDADO_H
#define SOLDADO_H
#include <string>
using namespace std;
class Soldado
{
	public:
		Soldado(string,int,int);
		int getVida();
		void setVida(int);
		int getFuerza();
		string getNombre();
		
		virtual int Atacar(bool);
		virtual void Defender(int,bool);
		
		~Soldado();
	protected:
		int vida,fuerza;
		string nombre;
		friend class ArchivoBinario;
};

#endif
