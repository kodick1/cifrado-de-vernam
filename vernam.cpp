#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>

using namespace std;
void cifradoverman();
void automatico();
void manual();
void descifradoverman(string,string);
main() {

	
	int opcion,opcion2;
	do{
		cout<<"\nMenu:"<<endl;
		cout<<"1. cifrar palabra vernam"<<endl;
		cout<<"2. descifrar palabra vernam"<<endl;
		cout<<"3.- Salir\n"<<endl;
		cout<<"Ingrese Opcion: ";
		cin>>opcion;
		switch(opcion){
			case 1: cifradoverman();
			break;
			case 2: 
			system("cls");
			do{
				
						cout<<"\nDescifrar:"<<endl;
						cout<<"1. descifrado manual"<<endl;
						cout<<"2. descifrado automatico"<<endl;
						cout<<"3.- Salir\n"<<endl;
						cout<<"Ingrese Opcion: ";
						cin>>opcion2;
						switch(opcion2){
							case 1:manual();
							break;
							case 2:automatico();
							break;
							default:cout<<"opcion incorrecta";
						}
				
			}while(opcion2!=3);
			break;
			case 3: cout<<"adios";
			break;
			system("cls");				
			default: cout<<"opcion incorrecta";
		}
	}while(opcion!=3);
}

void cifradoverman (){
	char texto[64];
	char clave[64];
	int letra;
	int ban=0;
	fflush(stdin);
	cout<<"\nescriba la palabra que cifrara\n";
	cin.getline(texto,64);
	while(ban==0){
		cout<<"escriba la clave\n";
		cin.getline(clave,64);
		if(strlen(texto)==strlen(clave)){
			ban=1;
		}
		else{
			cout<<"la clave es de diferente tamaño al texto\n";
		}
	}	
	ofstream Escritura ("cifrado.txt",ios::out);
	Escritura<<"clave\n";
	Escritura<<clave;
	Escritura<<"\n";
	Escritura<<"mensaje cifrado\n";
	cout<<"el texto cifrado es: ";
	for(int i=0;i<=strlen(texto)-1;i++){
		fflush(stdin);
		letra=texto[i]^clave[i];
		cout<<letra<<" ";
		Escritura<<letra<<" ";
	}
}
void descifradoverman(string txt,string pass ){	
	char clave[64];
	char texto[190];
	strcpy(clave,pass.c_str());	
	strcpy(texto,txt.c_str());	
	string numero="";
	char cifrado[64];
	char descifrado[64];
	int letra1;
	int a=0;
	char separador[]={' ','\0'};
	fflush(stdin);
	for(int i=0;i<strlen(texto);i++)
	{
		if(texto[i+1]!=separador[0]&&texto[i+1]!=separador[1]){
			numero=numero+texto[i];
		}
		else
		{
			numero=numero+texto[i];
			stringstream geek(numero);
			geek>>letra1;
			cifrado[a]=letra1;
			numero="";
			a=a+1;
		}
	}
	for(int i=0;i<=strlen(clave)-1;i++)
		descifrado[i]=cifrado[i]^clave[i];	
	cout<<"el texto descifrado es: "<<descifrado<<"\n";
	system("PAUSE");
	system("cls");
}
void automatico(){
	string linea,clave,cifrado;
	int i=0;
	ifstream leer ("cifrado.txt");
	if(leer.is_open())
	{
		while(getline(leer,linea))
		{
			if(i==1)
				clave=linea;			
			if(i==3)
				cifrado=linea;
			i++;						
		}
		leer.close();
		descifradoverman(cifrado,clave);
	}
	else
	cout<<"El Archivo no existe";
}
void manual(){
	string texto,clave;
	cout<<"escriba la palabra que descifrara\n";
	getline(cin,texto);
	getline(cin,texto);
	cout<<"escriba la clave\n";
	getline(cin,clave);
	descifradoverman(texto,clave);
}
