#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

void Cliente::setCodigo(int codigo){
    this->codCli=codigo;
}

void Cliente::setLocalidad(int localidad){
    this->localidad=localidad;
}

void Cliente::setNombre(char nombre[20]){
    strcpy(this->nombre,nombre);
}

void Cliente::setApellido(char apellido[20]){
    strcpy(this->apellido,apellido);
}

void Cliente::setDire(char dire[20]){
    strcpy(this->dire,dire);
}

void Cliente::setEstado(bool estado){
    this->estado=estado;
}

int Cliente::getCodigo(){
    return codCli;
}

int Cliente::getLocalidad(){
    return localidad;
}

char* Cliente::getNombre(){
    return nombre;
}

char* Cliente::getApellido(){
    return apellido;
}

char* Cliente::getDire(){
    return dire;
}

bool Cliente::getEstado(){
    return estado;
}

bool Cliente::cargar(){

    int codCli, localidad;
    char nombre[20],apellido[20],dire[20];
    Validacion* validar = new Validacion();
    Imprimir* Mostrar = new Imprimir();
    Archivo* archivo = new Archivo();

    bool reintentar = true;
    while(reintentar){
        Mostrar->textoCargaCli(codCli,localidad,nombre,apellido,dire,1);
        cin>>codCli;
        if(validar->regresar(codCli)) return false;
        if(!archivo->comprobarRegistro(clie,codCli)){
            if(validar->positivo(codCli)) reintentar = false;
            else Mostrar->textoNoPositivo();
        }
        else Mostrar->existeCodigo();
    }

    cout<<" NOMBRE: ";
    cin>>nombre;
    if(validar->regresar(nombre)) return false;

    cout<<" APELLIDO: ";
    cin>>apellido;
    if(validar->regresar(apellido)) return false;

    cout<<" DIRECCION: ";
    cin>>dire;
    if(validar->regresar(dire)) return false;

    reintentar = true;
    cout<<" LOCALIDAD: ";
    while(reintentar){
        cin>>localidad;
        if(validar->regresar(localidad)) return false;
        if(validar->rango(localidad,1,20)) reintentar = false;
        else{
            Mostrar->textoRangoInvalido(1,20);
            Mostrar->textoCargaCli(codCli,localidad,nombre,apellido,dire,5);
        }
    }


    cout<<"\n CLIENTE CARGADO CON EXITO!\n\n "; system("pause");

    setCodigo(codCli);
    setLocalidad(localidad);
    setNombre(nombre);
    setApellido(apellido);
    setDire(dire);
    setEstado(true);
    return true;
}


#endif // CLIENTES_H_INCLUDED
