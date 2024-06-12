#include "entrenador.h"
#include "bitacora.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

entrenador::entrenador(string id, string name1, string name2, string apellido1, string apellido2, string fechaNacimiento)
{
    this->id = id;
    this->name1 = name1;
    this->name2 = name2;
    this->apellido1 = apellido1;
    this->apellido2 = apellido2;
    this->fechaNacimiento = fechaNacimiento;
}
void entrenador::menu()
{
    bitacora metodoAccion;
    bool repetir = true;
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-----------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION ENTRENADOR  |"<<endl;
	cout<<"\t\t\t-----------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso de entrenador"<<endl;
	cout<<"\t\t\t 2. Despliegue entrenador"<<endl;
	cout<<"\t\t\t 3. Modificar entrenador"<<endl;
	cout<<"\t\t\t 4. Buscar entrenador"<<endl;
	cout<<"\t\t\t 5. Borrar entrenador" <<endl;
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
    		cout<<"\n\t\t\t Agrega otro entrenador(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		metodoAccion.insertarAccion("7010", "ING ENTRENADOR");
		break;
	case 2:
		desplegar();
		metodoAccion.insertarAccion("7020", "DES ENTRENADOR");
		break;
	case 3:
		modificar();
		metodoAccion.insertarAccion("7021", "UPD ENTRENADOR");
		break;
	case 4:
		buscar();
		metodoAccion.insertarAccion("7022", "SRCH ENTRENADOR");
		break;
	case 5:
		borrar();
		metodoAccion.insertarAccion("7023", "DEL ENTRENADOR");
		break;
	case 6:
		repetir = false;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}
void entrenador::insertar()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles del entrenador ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa ID de entrenador     : ";
	cin>>id;
	cout<<"\t\t\tIngresa Primer Nombre del entrenador     : ";
	cin>>name1;
	cout<<"\t\t\tIngresa Segundo Nobre del entrenador     : ";
	cin>>name2;
	cout<<"\t\t\tIngresa Primer Apellido del entrenador     : ";
	cin>>apellido1;
	cout<<"\t\t\tIngresa Segundo Apellido del entrenador     : ";
	cin>>apellido1;
	cout<<"\t\t\tIngresa Fecha de Nacimiento del entrenador     : ";
	cin>>fechaNacimiento;
	file.open("entrenador.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name1 <<std::left<<std::setw(15)<< name2 <<std::left<<std::setw(15)<< apellido1 <<std::left<<std::setw(15)<< apellido2 <<std::left<<std::setw(15)<< fechaNacimiento <<"\n";
	file.close();
}
void entrenador::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de los entrenadores -------------------------"<<endl;
	file.open("entrenador.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> name1 >> name2 >> apellido1 >> apellido2 >> fechaNacimiento;
		while(!file.eof())
		{
			total++;
			cout<<"\t\t\t Id del entrenador: "<<id<<endl;
			file >> id;
			cout<<"\t\t\t Nombre de entrenador: "<< name1 << " " << name2 << " " << apellido1 << " " << apellido2<<endl;
			file >> name1  >> name2  >> apellido1 >> apellido2;
			cout<<"\t\t\t Fecha de Nacimiento del entrenador: \n"<<fechaNacimiento<<endl;

		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void entrenador::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion de entrenadores-------------------------"<<endl;
	file.open("entrenador.txt",ios::in);
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
		file >> id >> name1 >> name2 >> apellido1 >> apellido2 >> fechaNacimiento;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name1 <<std::left<<std::setw(15)<< name2 <<std::left<<std::setw(15)<< apellido1 <<std::left<<std::setw(15)<< apellido2 <<std::left<<std::setw(15)<< fechaNacimiento <<"\n";
			}
			else
			{
				cout<<"\t\t\tIngresa ID de entrenador     : ";
	cin>>id;
	cout<<"\t\t\tIngresa Primer Nombre del entrenador     : ";
	cin>>name1;
	cout<<"\t\t\tIngresa Segundo Nobre del entrenador     : ";
	cin>>name2;
	cout<<"\t\t\tIngresa Primer Apellido del entrenador     : ";
	cin>>apellido1;
	cout<<"\t\t\tIngresa Segundo Apellido del entrenador     : ";
	cin>>apellido1;
	cout<<"\t\t\tIngresa Fecha de Nacimiento del entrenador     : ";
	cin>>fechaNacimiento;
	            file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name1 <<std::left<<std::setw(15)<< name2 <<std::left<<std::setw(15)<< apellido1 <<std::left<<std::setw(15)<< apellido2 <<std::left<<std::setw(15)<< fechaNacimiento <<"\n";
				found++;
			}
			file >> id >> name1 >> name2 >> apellido1 >> apellido2 >> fechaNacimiento;

		}
		file1.close();
		file.close();
		remove("entrenador.txt");
		rename("Record.txt","entrenador.txt");
	}
}
void entrenador::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("entrenador.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del entrenador Buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos de entrenador buscado------------------------"<<endl;
		cout<<"\nIngrese id del entrenador que quiere buscar: ";
		cin>>participant_id;
		file >> id >> name1 >> name2 >> apellido1 >> apellido2 >> fechaNacimiento;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\t\t\t Id del entrenador: \n"<<id<<endl;
			    cout<<"\t\t\t Nombre de entrenador: \n"<< name1 << " " << name2 << " " << apellido1 << " " << apellido2<<endl;
			    cout<<"\t\t\t Fecha de Nacimiento del entrenador: \n"<<fechaNacimiento<<endl;
				found++;
			}
			file >> id >> name1 >> name2 >> apellido1 >> apellido2 >> fechaNacimiento;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t entrenador no encontrado...";
		}
		file.close();
	}
}
void entrenador::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles entrenador a Borrar-------------------------"<<endl;
	file.open("entrenador.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del entrenador que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name1 >> name2 >> apellido1 >> apellido2 >> fechaNacimiento;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name1 <<std::left<<std::setw(15)<< name2 <<std::left<<std::setw(15)<< apellido1 <<std::left<<std::setw(15)<< apellido2 <<std::left<<std::setw(15)<< fechaNacimiento <<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name1 >> name2 >> apellido1 >> apellido2 >> fechaNacimiento;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id entrenador no encontrado...";
		}
		file1.close();
		file.close();
		remove("entrenador.txt");
		rename("Record.txt","entrenador.txt");
	}
}
