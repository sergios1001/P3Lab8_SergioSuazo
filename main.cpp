#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>  
#include "Soldado.h"
#include "Ataque.h"
#include "Soporte.h"
#include "Archivo.h"
#include "ArchivoBinario.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu(){
	int retValue=0;
	
	while(retValue < 1 || retValue > 7){
		
		cout<<"         MENU"<<endl
			<<"1.- Crear Soldado"<<endl
			<<"2.- Eliminar Soldados"<<endl
			<<"3.- Listar Soldados"<<endl
			<<"4.- Guardar Soldados"<<endl
			<<"5.- Cargar Soldados"<<endl
			<<"6.- Simulacion"<<endl
			<<"7.- Salir"<<endl
			<<"Ingrese una opcion entre 1 y 7: ";
			
			cin>>retValue;

			
			if(retValue >= 1 && retValue <= 7){
				break;
			}
				
			else{
						
				cout<<endl<<"Opcion incorrecta, elija nuevamente "<<endl;
			}
					
	}//end while
	
	
	return retValue;
}

vector<Soldado*> equipo1;
vector<Soldado*> equipo2;

int main(int argc, char** argv) {
	int option=0;
	while( option != 7 ) {
		
		switch( option = menu() ){ 
		
			case 1:{
				int equipo,tipo;
				cout<<"A que equipo desea agregar el soldado (1 o 2) ?: ";
				cin>> equipo;
				cout<<"Que tipo de soldado desea crear?"<<endl
				<<"1- Ataque"<<endl
				<<"2- Soporte"<<endl
				<<"Ingrese su eleccion(1 o 2): ";
				cin>> tipo;
				
				if(equipo==1)
				{
					if(tipo==1)
					{
						string nombre;
						int vida,fuerza,velocidad,extra;
						cout<<"Nombre: ";
						cin>>nombre;
						cout<<"Vida: ";
						cin>>vida;
						cout<<"Fuerza: ";
						cin>>fuerza;
						cout<<"Velocidad: ";
						cin>>velocidad;
						cout<<"Fuerza extra: ";
						cin>>extra;
						
						equipo1.push_back(new Ataque(velocidad,extra,vida,fuerza,nombre));
						
						cout<<"Se creo el soldado exitosamente!"<<endl;
					}
					else
					{
						string nombre;
						int vida,fuerza,camuflaje,blindaje;
						cout<<"Nombre: ";
						cin>>nombre;
						cout<<"Vida: ";
						cin>>vida;
						cout<<"Fuerza: ";
						cin>>fuerza;
						cout<<"Camuflaje: ";
						cin>>camuflaje;
						cout<<"Blindaje: ";
						cin>>blindaje;
						
						equipo1.push_back(new Soporte(blindaje,camuflaje,vida,fuerza,nombre));
						
						cout<<"Se creo el soldado exitosamente!"<<endl;

					}
					
				}
				else
				{
					if(tipo==1)
					{
						string nombre;
						int vida,fuerza,velocidad,extra;
						cout<<"Nombre: ";
						cin>>nombre;
						cout<<"Vida: ";
						cin>>vida;
						cout<<"Fuerza: ";
						cin>>fuerza;
						cout<<"Velocidad: ";
						cin>>velocidad;
						cout<<"Fuerza extra: ";
						cin>>extra;
						
						equipo2.push_back(new Ataque(velocidad,extra,vida,fuerza,nombre));
						
						cout<<"Se creo el soldado exitosamente!"<<endl;
					}
					else
					{
						string nombre;
						int vida,fuerza,camuflaje,blindaje;
						cout<<"Nombre: ";
						cin>>nombre;
						cout<<"Vida: ";
						cin>>vida;
						cout<<"Fuerza: ";
						cin>>fuerza;
						cout<<"Camuflaje: ";
						cin>>camuflaje;
						cout<<"Blindaje: ";
						cin>>blindaje;
						
						equipo2.push_back(new Soporte(blindaje,camuflaje,vida,fuerza,nombre));
						
						cout<<"Se creo el soldado exitosamente!"<<endl;
					}
				}
				
				
				break;
			}
			case 2:{
				int equipo,elim;
				cout<<"Desea eliminar un soldado del equipo 1 o 2?: ";
				cin>>equipo;
				
				if(equipo==1)
				{
					for(int i=0;i<equipo1.size();i++)
					{
						cout<<i<<"- "<<equipo1[i]->getNombre()<<endl;
					}
					cout<<"Seleccione el Soldado que desea eliminar: ";
					cin>>elim;
					
					equipo1.erase(equipo1.begin()+elim);
					cout<<"El soldado se elimino exitosamente"<<endl;
				}
				else
				{
					for(int i=0;i<equipo2.size();i++)
					{
						cout<<i<<"- "<<equipo2[i]->getNombre()<<endl;
					}
					cout<<"Seleccione el Soldado que desea eliminar: ";
					cin>>elim;
					
					equipo2.erase(equipo2.begin()+elim);
					cout<<"El soldado se elimino exitosamente"<<endl;
				}
				break;	
			} 
			    
			case 3:{
				int equipo;
				cout<<"Que equipo desea listar (1 o 2) ?: ";
				cin>> equipo;
				if(equipo==1)
				{
					for(int i=0;i<equipo1.size();i++)
					{
						cout<<i<<"- "<<equipo1[i]->getNombre()<<", "<<equipo1[i]->getVida()<<", "<<equipo1[i]->getFuerza()<<endl;
					}
				}
				else
				{
					for(int i=0;i<equipo2.size();i++)
					{
						cout<<i<<"- "<<equipo2[i]->getNombre()<<", "<<equipo2[i]->getVida()<<", "<<equipo2[i]->getFuerza()<<endl;
					}
				}
				
				break;
			}
			case 4:{//guardar soldados
				ArchivoBinario* soldados1 = new ArchivoBinario("Equipo1.bin");
	
				soldados1->abrirEscritura(0);
				for(int i=0;i<equipo1.size();i++)
				{
					int tipo=0;
					Ataque *sA = dynamic_cast<Ataque*>(equipo1[i]);
						if(sA == 0)
						{
							tipo = 1;
							soldados1->guardarSoldado(equipo1[i],tipo);
						}
						else
						{
							tipo = 2;
							soldados1->guardarSoldado(equipo1[i],tipo);
						}
				}
				soldados1->cerrarEscritura(); //buffer flush
				
				ArchivoBinario* soldados2 = new ArchivoBinario("Equipo2.bin");
	
				soldados2->abrirEscritura(0);
				for(int i=0;i<equipo2.size();i++)
				{
					int tipo=0;
					Ataque *sA = dynamic_cast<Ataque*>(equipo2[i]);
						if(sA == 0)
						{
							tipo = 1;
							soldados2->guardarSoldado(equipo2[i],tipo);
						}
						else
						{
							tipo = 2;
							soldados2->guardarSoldado(equipo2[i],tipo);
						}
				}
				soldados2->cerrarEscritura(); //buffer flush
				
				cout<<"Se guardaron los soldados exitosamente"<<endl;
				
				break;
			}
			case 5:{// cargar soldados
					
					//equipo1
					ArchivoBinario* binFile;
					equipo1.clear();
					binFile = new ArchivoBinario("Equipo1.bin");
					binFile->abrirLectura();
					equipo1 = binFile->leerSoldados();
					binFile->cerrarLectura();
					
					//equipo2
					ArchivoBinario* binFile2;
					equipo2.clear();
					binFile2 = new ArchivoBinario("Equipo2.bin");
					binFile2->abrirLectura();
					equipo2 = binFile2->leerSoldados();
					binFile2->cerrarLectura();
				break;
			}
			case 6:{
				int turno = 0;
				while(equipo1.size()>0||equipo2.size()>0)
				{
					if(turno%2==0)
					{
						int atacar,defender,damage;
						bool tipo1,tipo2;
						atacar = rand() % equipo1.size();
						defender = rand() % equipo2.size();
						
						//Definir tipo del atacador
						Ataque *sA = dynamic_cast<Ataque*>(equipo1[atacar]);
						if(sA == 0)
						{
							tipo1 = false;
						}
						else
						{
							tipo1 = true;
						}
						
						//Definir tipo del defensor
						Ataque *sB = dynamic_cast<Ataque*>(equipo2[defender]);
						if(sB == 0)
						{
							tipo2= false;
						}
						else
						{
							tipo2 = true;
						}
						
						damage=equipo1[atacar]->Atacar(tipo2);
						equipo2[defender]->Defender(damage,tipo1);
						
						if(equipo2[defender]->getVida()<=0)
						{
							equipo2.erase(equipo2.begin()+defender);
							cout<<"El equipo 2 perdio un soldado"<<endl;
						}
					}
					else
					{
						int atacar,defender,damage;
						bool tipo1,tipo2;
						atacar = rand() % equipo2.size();
						defender = rand() % equipo1.size();
						
						//Definir tipo del atacador
						Ataque *sA = dynamic_cast<Ataque*>(equipo1[defender]);
						if(sA == 0)
						{
							tipo1 = false;
						}
						else
						{
							tipo1 = true;
						}
						
						//Definir tipo del defensor
						Ataque *sB = dynamic_cast<Ataque*>(equipo2[atacar]);
						if(sB == 0)
						{
							tipo2= false;
						}
						else
						{
							tipo2 = true;
						}
						
						damage=equipo2[atacar]->Atacar(tipo1);
						equipo1[defender]->Defender(damage,tipo2);
						
						if(equipo1[defender]->getVida()<=0)
						{
							equipo1.erase(equipo1.begin()+defender);
							cout<<"El equipo 1 perdio un soldado"<<endl;
						}
					}
					turno++;
				}
				break;
			}
			case 7:{

				//salir
				cout<<"Saliendo del programa..."<<endl;
				break;
			}
						
		}//switch
	
	}//while
	return 0;
}
