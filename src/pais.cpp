#include "pais.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

pais::pais(string id, string name)
{
    this->name = name;
    this->id = id;
}
string pais::setId(string id)
{
    this->id = id;
}
string pais::getId()
{
    return this->id;
}
// Setter y Getter de name
string pais::setName(string name)
{
    this->name = name;
}
string pais::getName()
{
    return this->name;
}

void pais::menu()
{
    bitacora metodoAccion;
    bool repetir = true;
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION PAIS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso de pais"<<endl;
	cout<<"\t\t\t 2. Despliegue pais"<<endl;
	cout<<"\t\t\t 3. Modificar pais"<<endl;
	cout<<"\t\t\t 4. Buscar pais"<<endl;
	cout<<"\t\t\t 5. Borrar pais" <<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otro pais(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		metodoAccion.insertarAccion("705", "ING PAIS");
		break;
	case 2:
		desplegar();
		metodoAccion.insertarAccion("706", "DES PAIS");
		break;
	case 3:
		modificar();
		metodoAccion.insertarAccion("707", "UPD PAIS");
		break;
	case 4:
		buscar();
		metodoAccion.insertarAccion("708", "SRCH PAIS");
		break;
	case 5:
		borrar();
		metodoAccion.insertarAccion("709", "DEL PAIS");
		break;
	case 6:
		repetir=false;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void pais::insertar()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles del Pais ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa ID de Pais     : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre del Pais     : ";
	cin>>name;
	file.open("Pais.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name << "\n";
	file.close();
}
void pais::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de los Paises -------------------------"<<endl;
	file.open("Pais.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> name;
		while(!file.eof())
		{
			total++;
			cout<<"\t\t\t Id del Pais: "<<id<<endl;
			file >> id;
			cout<<"\t\t\t Nombre de pais: "<<name<<endl;
			file >> name;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void pais::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion de Paises-------------------------"<<endl;
	file.open("Pais.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name << "\n";
			}
			else
			{
				cout<<"\t\t\tIngresa ID de Pais     : ";
	            cin>>id;
	            cout<<"\t\t\tIngresa Nombre del Pais     : ";
	            cin>>name;
	            file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name << "\n";
				found++;
			}
			file >> id >> name;

		}
		file1.close();
		file.close();
		remove("Pais.txt");
		rename("Record.txt","Pais.txt");
	}
}
void pais::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Pais.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Pais Buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de Pais buscado------------------------"<<endl;
		cout<<"\nIngrese id del pais que quiere buscar: ";
		cin>>participant_id;
		file >> id >> name;;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\t\t\t Id: "<<id<<endl;
				cout<<"\t\t\t Nombre pais: "<<name<<endl;
				found++;
			}
			file>> id >> name;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t pais no encontrado...";
		}
		file.close();
	}
}
void pais::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles Pais a Borrar-------------------------"<<endl;
	file.open("Pais.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la pais que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id pais no encontrado...";
		}
		file1.close();
		file.close();
		remove("Pais.txt");
		rename("Record.txt","Pais.txt");
	}
}

