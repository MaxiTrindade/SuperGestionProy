#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <conio.h>
using namespace std;
#include "Articulos.h"
#include "Archivos.h"

int main(){

    Articulo art;
    /*art.cargar();*/
    Archivos archivo;
    /*archivo.escribir(art);*/
    archivo.mostrarTodos(art);
    return 0;
}
