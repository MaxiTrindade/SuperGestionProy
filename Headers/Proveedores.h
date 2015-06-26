#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

char* Proveedor::getNombre(){
    return nombre;
}

char* Proveedor::getTelefono(){
    return telefono;
}

char* Proveedor::getDirec(){
    return direc;
}

char* Proveedor::getEmail(){
    return email;
}

char* Proveedor::getDesc(){
    return desc;
}

int Proveedor::getCategoria(){
    return categoria;
}

int Proveedor::getCodigo(){
    return codigo;
}

void Proveedor::setNombre(char *nombre){
    strcpy(this->nombre,nombre);
}

void Proveedor::setTelefono(char *telefono){
    strcpy(this->telefono,telefono);
}

void Proveedor::setDesc(char *desc){
    strcpy(this->desc,desc);
}

void Proveedor::setEmail(char *email){
    strcpy(this->email,email);
}

void Proveedor::setDirec(char *direc){
    strcpy(this->direc,direc);
}

void Proveedor::setCategoria(int cat){
    this->categoria=cat;
}

void Proveedor::setCodigo(int codigo){
    this->codigo=codigo;
}

bool Proveedor::cargar(){

    char nombre[30],desc[50],telefono[15],email[30],direc[50];
    int cat,codigo;
    bool flag=true;
    Imprimir *mostrar = new Imprimir();
    Validacion *validar = new Validacion();
    Archivo *archivo = new Archivo();

    while(flag){
        mostrar->textoCargaProv(nombre,direc,email,desc,telefono,cat,codigo,0);
        cin>>codigo;
        if(validar->regresar(codigo)) return false;
        if(!archivo->comprobarRegistro(prov,codigo)){
            if(validar->positivo(codigo)) flag=false;
            else{
                mostrar->textoNoPositivo();
                mostrar->textoCargaProv(nombre,direc,email,desc,telefono,cat,codigo,0);
            }
        }
        else mostrar->existeCodigo();
    }

    mostrar->textoCargaProv(nombre,direc,email,desc,telefono,cat,codigo,1);
    cin.ignore();
    cin.getline(nombre,29);
    if(validar->regresar(nombre)) return false;

    mostrar->textoCargaProv(nombre,direc,email,desc,telefono,cat,codigo,2);
    cin.getline(desc,49);
    if(validar->regresar(desc)) return false;

    mostrar->textoCargaProv(nombre,direc,email,desc,telefono,cat,codigo,3);
    cin.getline(direc,49);
    if(validar->regresar(direc)) return false;

    mostrar->textoCargaProv(nombre,direc,email,desc,telefono,cat,codigo,4);
    cin.getline(telefono,14);
    if(validar->regresar(telefono)) return false;

    mostrar->textoCargaProv(nombre,direc,email,desc,telefono,cat,codigo,5);
    cin.getline(email,29);
    if(validar->regresar(email)) return false;

    flag=true;
    mostrar->textoCargaProv(nombre,direc,email,desc,telefono,cat,codigo,6);
    while(flag){
        cin>>cat;
        if(validar->regresar(cat)) return false;
        if(validar->rango(cat,1,11)) flag=false;
        else{
            mostrar->textoRangoInvalido(1,11);
            mostrar->textoCargaProv(nombre,direc,email,desc,telefono,cat,codigo,6);
        }
    }

    cout<<"\n PROVEEDOR CARGADO CON EXITO!\n\n "; system("pause");

    setCodigo(codigo);
    setNombre(nombre);
    setDesc(desc);
    setDirec(direc);
    setTelefono(telefono);
    setEmail(email);
    setCategoria(cat);
    return true;
}
#endif // PROVEEDORES_H_INCLUDED
