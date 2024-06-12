#ifndef ENTRENADOR_H
#define ENTRENADOR_H
#include <iostream>

using namespace std;


class entrenador
{
     public:
        entrenador();
        entrenador(string id, string name1, string name2, string apellido1, string apellido2, string fechaNacimiento);
        void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();

    protected:

    private:
        string id, name1, name2, apellido1, apellido2, fechaNacimiento;
};

#endif // ENTRENADOR_H
