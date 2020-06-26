#include <iostream>
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

int main(int argc, char** argv) {
	int option=0;
	while( option != 7 ) {
		
		switch( option = menu() ){ 
		
			case 1:{
				
				
				break;
			}
			case 2:{
				
				break;	
			} 
			    
			case 3:{
				
				break;
			}
			case 4:{
				break;
			}
			case 5:{
				break;
			}
			case 6:{
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
