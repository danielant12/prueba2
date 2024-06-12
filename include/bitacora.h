#ifndef BITACORA_H
#define BITACORA_H

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

class bitacora
{
    public:
        bitacora();

        string setAccion(string accion);
        string getAccion();
        string setAplicacion(string aplicacion);
        string getAplicacion();

        void desplegarBitacora();
        void insertarAccion(string aplicacion, string accion);

    protected:

    private:
        string accion, aplicacion;
};

#endif // BITACORA_H
