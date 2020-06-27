#include "Archivo.h"
#include <sstream>
using std::stringstream;




Archivo::Archivo(string pFileName)
{
	fileName = pFileName;
}

//1.- Definir el separador de los campos
//2.- definir el separador de los registros
bool Archivo::guardarSoldado(Soldado* soldado,int a){
	if(outputFile.is_open()){
		
		return true;
	}else
		return false;
}

bool Archivo::cerrarEscritura(){

}

bool Archivo::abrirEscritura(int modo){

	return true;
}


		//abrir archivo
bool Archivo::abrirLectura(){
return true;
		}
		
bool Archivo::cerrarLectura(){
return true;
		}

	vector<Soldado*> Archivo::leerSoldados(){
			vector<Soldado*> retval;

				return retval;

		}
