#include "ArchivoBinario.h"
#include "Soldado.h"
#include "Ataque.h"
#include "Soporte.h"

ArchivoBinario::ArchivoBinario(string fileName):Archivo(fileName)
{
	
}

bool ArchivoBinario::abrirLectura(){
	inputFile.open(fileName.c_str(),std::ios::binary);
			return inputFile.is_open();
}

bool ArchivoBinario::abrirEscritura(int modo){
	modoEscritura = modo;
	if(modoEscritura == 1)
		outputFile.open(fileName.c_str(), std::ios::app | std::ios::binary);
	else
			outputFile.open(fileName.c_str(), std::ios::binary);
			
	return outputFile.is_open();
}


vector<Soldado*> ArchivoBinario::leerSoldados(){
	 vector<Soldado*> retValue;
	 
	 
	 while(!inputFile.eof()){
	 	int nameSize=0;
	 	int vida=0;
	 	int fuerza=0;
	 	int velocidad=0;
	 	int extra=0;
	 	int blindaje=0;
	 	int camuflaje=0;
		  
	 	int tipo=0;
	 	
	 	//leer el tipo
	 	inputFile.read(reinterpret_cast<char*>(&tipo),sizeof(int));
	 	
	 	if(tipo==1){
	 		//leer el tamaño del nombre 
		 	inputFile.read(reinterpret_cast<char*>(&nameSize),sizeof(int));
		 	
		 	char buffer[100];
		 	//leer el nombre
		 	inputFile.read(buffer,nameSize);
		 	
		 	string nombre = buffer;
		 	
		 	//leer la vida
		 	inputFile.read(reinterpret_cast<char*>(&vida),sizeof(int));
		 	
		 	//leer la fuerza
		 	inputFile.read(reinterpret_cast<char*>(&fuerza),sizeof(int));
		 	
		 	//leer la velocidad
		 	inputFile.read(reinterpret_cast<char*>(&velocidad),sizeof(int));
		 	
		 	//leer la extra
		 	inputFile.read(reinterpret_cast<char*>(&extra),sizeof(int));
		 	
	 		retValue.push_back(new Ataque(velocidad,extra,vida,fuerza,nombre));
		 }
		 else
		 {
		 	//leer el tamaño del nombre 
		 	inputFile.read(reinterpret_cast<char*>(&nameSize),sizeof(int));
		 	
		 	char buffer[100];
		 	//leer el nombre
		 	inputFile.read(buffer,nameSize);
		 	
		 	string nombre = buffer;
		 	
		 	//leer la vida
		 	inputFile.read(reinterpret_cast<char*>(&vida),sizeof(int));
		 	
		 	//leer la fuerza
		 	inputFile.read(reinterpret_cast<char*>(&fuerza),sizeof(int));
		 	
		 	//leer la velocidad
		 	inputFile.read(reinterpret_cast<char*>(&blindaje),sizeof(int));
		 	
		 	//leer la extra
		 	inputFile.read(reinterpret_cast<char*>(&camuflaje),sizeof(int));
		 	
	 		retValue.push_back(new Soporte(blindaje,camuflaje,vida,fuerza,nombre));
		 }
	 	
	 }
	 
	 return retValue; 
}

 bool ArchivoBinario::guardarSoldado(Soldado* soldado, int tipo){
 	if(outputFile.is_open()){
 		
 		if(tipo==1){
 			
 			Ataque *sA = dynamic_cast<Ataque*>(soldado);
 			
	 		int sizeNombre = soldado->nombre.size();
	 		
	 		outputFile.write(reinterpret_cast<char*>(&tipo), (int)sizeof(int) );
	 		
	 		//guardar size nombre
	 		outputFile.write(reinterpret_cast<char*>(&sizeNombre), (int)sizeof(int) );
	 		
			//guardar el nombre 
			outputFile.write(soldado->nombre.data(),sizeNombre);
			
			//guardar vida
	 		outputFile.write(reinterpret_cast<char*>(&soldado->vida), (int)sizeof(int) );
	 		
	 		//guardar fuerza
	 		outputFile.write(reinterpret_cast<char*>(&soldado->fuerza), (int)sizeof(int) );
	 		
	 		//guardar velocidad
	 		outputFile.write(reinterpret_cast<char*>(&sA->velocidad), (int)sizeof(int) );
	 		
	 		//guardar extra
	 		outputFile.write(reinterpret_cast<char*>(&sA->extra), (int)sizeof(int) );
		}
		
		else if(tipo==2)
		{
			Soporte *sB = dynamic_cast<Soporte*>(soldado);
			
			int sizeNombre = soldado->nombre.size();
	 		
	 		outputFile.write(reinterpret_cast<char*>(&tipo), (int)sizeof(int) );
	 		
	 		//guardar size nombre
	 		outputFile.write(reinterpret_cast<char*>(&sizeNombre), (int)sizeof(int) );
	 		
			//guardar el nombre 
			outputFile.write(soldado->nombre.data(),sizeNombre);
			
			//guardar vida
	 		outputFile.write(reinterpret_cast<char*>(&soldado->vida), (int)sizeof(int) );
	 		
	 		//guardar fuerza
	 		outputFile.write(reinterpret_cast<char*>(&soldado->fuerza), (int)sizeof(int) );
	 		
	 		//guardar blindaje
	 		outputFile.write(reinterpret_cast<char*>(&sB->blindaje), (int)sizeof(int) );
	 		
	 		//guardar camuflaje
	 		outputFile.write(reinterpret_cast<char*>(&sB->camuflaje), (int)sizeof(int) );
		}
 		
				
		return true;
	}else
		return false;		
 }
