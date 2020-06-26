#ifndef SOLDADO_H
#define SOLDADO_H

class Soldado
{
	public:
		Soldado(int,int);
		int getVida();
		void setVida(int);
		int getFuerza();
		
		virtual int Atacar(bool);
		virtual void Defender(int,bool);
		
		~Soldado();
	protected:
		int vida,fuerza;
};

#endif
