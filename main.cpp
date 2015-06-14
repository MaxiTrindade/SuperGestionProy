#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iomanip>
using namespace std;
#include "Headers/Super.h"
#include "Headers/Imprimir.h"
#include "Headers/Validacion.h"
#include "Headers/Fecha.h"
#include "Headers/Articulos.h"
#include "Headers/Empleados.h"
#include "Headers/Clientes.h"
#include "Headers/Ventas.h"
#include "Headers/Usuarios.h"
#include "Headers/Archivos.h"
#include "Headers/Menues.h"


int main(){
    system("COLOR 1C");
    presentacion();
    system("COLOR 1C");
    Usuario* User = new Usuario();
    User=User->login();
    menuPrincipal(User);
    return 0;
}
