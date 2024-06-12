#ifndef PAIS_H
#define PAIS_H
#include <iostream>
#include "bitacora.h"

using namespace std;


class pais
{
   public:
        pais();
        pais(string id, string name);
        string setName(string name);
        string getName();
        string setId(string id);
        string getId();
        void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();

    protected:

    private:
        string id, name;
};

#endif // PAIS_H
