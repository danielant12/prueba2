#include <iostream>
#include <fstream>
#include <string>
#include "Usuarios.h"
#include "bitacora.h"
#include "pais.h"
#include "entrenador.h"
#include "resultados.h"
#include "aplicaciones.h"

using namespace std;

void menu();
void menuCatalogos();
void menuProcesos();
void menuInformes();

Usuario ingreso;


int main() {


    int opcion;
    do{
        system("cls");
        cout <<"\t\t\t----------------------------------"<<endl;
        cout <<"\t\t\t |           Bienvenido          |"<<endl;
        cout <<"\t\t\t----------------------------------"<<endl;
        cout<<"\t\t\t 1. Autenticacion"<<endl;
        cout<<"\t\t\t 2. CRUD Usuarios"<<endl;
	    cout<<"\t\t\t 3. Salir"<<endl;
	    cout<<"\t\t\t-------------------------------"<<endl;
	    cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl; // Se imprime una línea indicando que se debe elegir una opción
	    cout<<"\t\t\t-------------------------------"<<endl;
	    cout<<"Ingresa tu Opcion: ";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
        {
            bool usuarioCorrecto = ingreso.verificarUsuario();
            if (usuarioCorrecto){
            menu();
            }
            break;
        }
        case 2:
            ingreso.menuUsuarios();
            break;
        case 3:
            cout<<"\n\n\n\t\t\tGracias por usar nuestro programa!!!\n\n\n"<<endl;
            system("pause");
            exit(0);
            break;
        }
    }while(opcion!= 3);


    return 0;
}
void menu()
{

    fstream file2;
    // Obtiene el tiempo actual
    time_t tiempoActual = time(0);

    //Convierte el tiempo actual a una estructura tm local
    tm* fechaHoraLocal = localtime(&tiempoActual);

    file2.open("Bitacora.txt", ios::app | ios::out);

    int choice;
	char x;
	do
    {
	system("cls");
	string usuarioAutenticado = ingreso.getUsuarioAutenticado();
    cout << "Usuario Autenticado: " <<usuarioAutenticado<< "\n"<< endl; // Mostrar el nombre de usuario autenticado
    cout <<"\t\t\t--------------------------------------"<<endl;
    cout <<"\t\t\t |   BIENVENIDO AL MENU PRINCIPAL   |"<<endl;
    cout <<"\t\t\t |Daniel Antonio Chacón Morataya |"<<endl;
    cout <<"\t\t\t |9959-22-1827                      |"<<endl;
    cout <<"\t\t\t--------------------------------------"<<endl;
	cout<<"\t\t\t 1. Catalogos"<<endl;
	cout<<"\t\t\t 2. Procesos"<<endl;
	cout<<"\t\t\t 3. Informes"<<endl;
	cout<<"\t\t\t 4. Salir"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;
    switch(choice){
    case 1:
        menuCatalogos();
        break;
    case 2:
        menuProcesos();
        break;
    case 3:
        menuInformes();
        break;
    case 4:
	    file2 << "\t\t\tHora en que salio del programa: " << fechaHoraLocal->tm_hour << ":" << fechaHoraLocal->tm_min << ":" << fechaHoraLocal->tm_sec <<"\n" << endl;
	    main();
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;
    }

	getch();
    }while(choice!= 3);
    file2.close();
}
void menuCatalogos()
{
    Usuario ingreso;

    bool salir = false;
    int choice;
    char x;
	do
    {
        system("cls");
    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE CATALOGO|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. CRUD PAIS"<<endl;
	cout<<"\t\t\t 2. CRUD ENTRENADOR"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;
	cout<<"\t\t\t (Usted explico que eran solo dos CRUDS)"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
            string id, name;
            pais crudPais(id, name);
            crudPais.menu();
        }
		break;
	case 2:
	    {
	        string id, name1, name2, apellido1, apellido2, fechaNacimiento;
	        entrenador crudEntrenador(id, name1, name2, apellido1, apellido2, fechaNacimiento);
	        crudEntrenador.menu();
	    }
		break;
    case 3:
	    menu();
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 6);
}

void menuProcesos()
{
    Usuario ingreso;

    bitacora consulta;

    //aplicaciones Aplicaciones;


    bool salir = false;
    int choice;
	do
    {
    system("cls");
    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE PROCESOS|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Resultado de un Partido"<<endl;
	cout<<"\t\t\t 2. Consulta de Bitacora"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
            resultados Resultados;
            Resultados.desplegar();
        }
		break;
	case 2:
        consulta.desplegarBitacora();
		system("pause");
		menuProcesos();
		break;
    case 3:
	    menu();
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 5);
}
void menuInformes()
{
    Usuario ingreso;

    bitacora metodoAccion;

    bool salir = false;
    int choice;
    char x;
	do
    {
    system("cls");
    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE INFORMES  |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Aplicaciones"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
            aplicaciones Aplicaciones;
            Aplicaciones.menu();
        }
		break;
	case 2:
	    menu();
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 3);
}

