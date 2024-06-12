#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Usuario { // Se define la clase Usuario
public:
    Usuario(); // Se define el constructor de la clase, el cual recibe como parámetros un usuario y una contraseña

    string setUusuario(string nombre); // Se define el método setUsuario, que permite establecer el valor del atributo usuario
    string getUusuario(); // Se define el método getUsuario, que permite obtener el valor del atributo usuario
    string setContrasena(string pass); // Se define el método setContrasena, que permite establecer el valor del atributo contrasena
    string getContrasena(); // Se define el método getContrasena, que permite obtener el valor del atributo contrasena

    void menuUsuarios(); // Se define el método menuUsuarios, que muestra el menú de opciones para el usuario
    void ingresarUsuarios(); // Se define el método ingresarUsuarios, que permite ingresar un nuevo usuario
    void desplegarUsurios(); // Se define el método desplegarUsuarios, que permite mostrar todos los usuarios registrados
    void modificarUsuarios(); // Se define el método modificarUsuarios, que permite modificar los datos de un usuario
    void borrarUsurios(); // Se define el método borrarUsuarios, que permite eliminar un usuario
    void buscar();
    bool verificarUsuario(); // Se define el método verificarUsuario, que verifica si el usuario y la contraseña son correctos

    string getUsuarioAutenticado();


private:
    string usuario, contrasena; // Se definen los atributos usuario y contrasena como privados, para que sólo puedan ser accedidos desde dentro de la clase
    string usuarioAutenticado;
};

#endif

