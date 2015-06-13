#ifndef ARTICULOS_H_INCLUDED
#define ARTICULOS_H_INCLUDED

void Articulo::setNombre(char nombre[20]){
    strcpy(this->nombre,nombre);
}

void Articulo::setStock(int stock){
    this->stock = stock;
}

void Articulo::setPrecio(float precio){
    this->precio = precio;
}

void Articulo::setSeccion(int seccion){
    this->seccion = seccion;
}

void Articulo::setEstado(bool estado){
    this->estado = estado;
}

void Articulo::setCodigo(int codigo){
    this->codigo = codigo;
}

char* Articulo::getNombre(){
    return nombre;
}

int Articulo::getStock(){
    return stock;
}

float Articulo::getPrecio(){
    return precio;
}

int Articulo::getSeccion(){
    return seccion;
}

bool Articulo::getEstado(){
    return estado;
}

int Articulo::getCodigo(){
    return codigo;
}

        //// FUNCIONES ADICIONALES ////

bool Articulo::cargar(){

    int codigo,stock,seccion; float precio; char nombre[20];
    Validacion* validar = new Validacion();
    Imprimir* Mostrar = new Imprimir();
    Archivo* archivo = new Archivo();

    bool reintentar = true;
    while(reintentar){
        Mostrar->textoCargaArt(codigo,stock,seccion,precio,nombre,1);
        cin>>codigo;
        if(validar->regresar(codigo)) return false;
        if(!archivo->comprobarRegistro(arti,codigo)){
            if(validar->positivo(codigo)) reintentar = false;
            else Mostrar->textoNoPositivo();
        }
        else Mostrar->existeCodigo();
    }

    cout<<" NOMBRE: ";
    cin>>nombre;
    if(validar->regresar(nombre)) return false;

    reintentar = true;
    cout<<" SECCION: ";
    while(reintentar){
        cin>>seccion;
        if(validar->regresar(seccion)) return false;
        if(validar->rango(seccion,1,5)) reintentar = false;
        else{
            Mostrar->textoRangoInvalido(1,5);
            Mostrar->textoCargaArt(codigo,stock,seccion,precio,nombre,3);
        }
    }

    reintentar = true;
    cout<<" PRECIO: $";
    while(reintentar){
        cin>>precio;
        if(validar->regresar(precio)) return false;
        if(validar->positivo(precio)) reintentar = false;
        else{
            Mostrar->textoNoPositivo();
            Mostrar->textoCargaArt(codigo,stock,seccion,precio,nombre,4);
        }
    }

    reintentar = true;
    cout<<" STOCK: ";
    while(reintentar){
        cin>>stock;
        if(validar->regresar(stock)) return false;
        if(validar->positivo(stock)) reintentar = false;
        else{
            Mostrar->textoNoPositivo();
            Mostrar->textoCargaArt(codigo,stock,seccion,precio,nombre,5);
        }
    }

    cout<<"\n ARTICULO CARGADO CON EXITO!\n\n "; system("pause");

    setStock(stock);
    setPrecio(precio);
    setSeccion(seccion);
    setNombre(nombre);
    setCodigo(codigo);
    setEstado(true);
    return true;
}


#endif // ARTICULOS_H_INCLUDED

