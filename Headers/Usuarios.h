#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

char* Usuario::getNombre(){
    return nombre;
}

char* Usuario::getClave(){
    return clave;
}

/// FALTA HACER FECHA. SUS RESPECTIVOS GETTERS Y SETTERS

bool Usuario::getEstado(){
    return estado;
}

void Usuario::setNombre(char* nombre){
    strcpy(this->nombre,nombre);
}

void Usuario::setClave(char* clave){
    strcpy(this->clave,clave);
}

void Usuario::setEstado(bool estado){
    this->estado=estado;
}

Usuario* Usuario::login(){

    char nombre[20],clave[20];
    Usuario* Usu = new Usuario();
    Usuario* User = new Usuario();
    Archivo* archi = new Archivo();
    int Aux=0;

    FILE* archivo = fopen("Usuarios.dat","rb");
    if(archivo == NULL){
        Usu->setNombre("UTN");
        Usu->setClave("UTN");
        Usu->setEstado(true);
        fclose(archivo);
        archi->guardar(Usu,usua);
    }
    fclose(archivo);

    while(Aux == 0){

        system("cls");

        cout<<"\n Si ingresa -1, puede utilizar el programa como usuario invitado." << endl;

        cout<<"\n "<<(char)201; for(int i=0;i<30;i++) cout<<(char)205; cout<<(char)187;
        cout<<"\n "<<(char)186; for(int i=0;i<30;i++) cout<<" "; cout<<(char)186;
        cout<<"\n "<<(char)186; for(int i=0;i<3;i++) cout<<" ";cout<<"USUARIO:";for(int i=0;i<19;i++) cout<<" " ;cout<<(char)186;
        cout<<"\n "<<(char)186; for(int i=0;i<30;i++) cout<<" "; cout<<(char)186;
        cout<<"\n "<<(char)186; for(int i=0;i<3;i++) cout<<" ";cout<<"CLAVE:";for(int i=0;i<21;i++) cout<<" " ;cout<<(char)186;
        cout<<"\n "<<(char)186; for(int i=0;i<30;i++) cout<<" "; cout<<(char)186;
        cout<<"\n "<<(char)200; for(int i=0;i<30;i++) cout<<(char)205; cout<<(char)188;
        gotoxy(14,5);

        cin>>nombre;

        if (strcmp(nombre,"-1") == 0){
            gotoxy(0,11);
            cout <<"\n Ha ingresado como usuario invitado." << endl << endl;
            strcpy(nombre,"INVITADO");
            system("pause");
            Usu->setNombre(nombre);
            Usu->setClave(clave);
            Usu->setEstado(false);
            return Usu;
        }
        else{
            FILE* FileUser = fopen ("Usuarios.dat","rb");

            while(fread(User,sizeof (Usuario),1,FileUser)){

                if(strcmp(User->getNombre(),nombre) ==0 && User->getEstado() == true){

                    Aux = 1;

                    gotoxy(12,7);
                    cin >> clave;

                    if(strcmp(User->getClave(),clave) ==0){
                        gotoxy(0,11);
                        cout <<"\n Ha ingresado correctamente! " << endl << endl;
                        system("pause");
                        fclose(FileUser);
                        Usu->setNombre(nombre);
                        Usu->setClave(clave);
                        Usu->setEstado(true);
                        return Usu;
                    }
                    else{
                        gotoxy(0,11);
                        cout<<"\n La clave ingresada es incorrecta! " << endl << endl;
                        system("pause");
                    }
                }
            }
            if (Aux == 0){
                gotoxy(0,11);
                cout<<"\n No es un nombre de usuario valido." << endl << endl;
                system("pause");
            }

            Aux = 0;

            fclose(FileUser);
        }
    }
}

bool Usuario::cargar(){

    Usuario* User = new Usuario();
    Archivo* archivo = new Archivo();
    Validacion* Validar = new Validacion();
    char nombre[20],clave[20];
    bool estado;

    system("cls");
    cout<<"\n AGREGAR USUARIO ";
    cout<<"\n ----------------";
    cout <<"\n Nombre de Usuario: ";
    cin>>nombre;

    if (Validar->regresar(nombre))
        return false;

    if(User->comprobarUsuario(nombre)){
        cout<<"\n Ya existe ese nombre de usuario " << endl << endl;
        system("pause");
        return false;
    }
    cout << "\n Clave: ";
    cin>>clave;

    if (Validar->regresar(clave))
        return false;


    cout << endl << "Usuario cargado con exito! " << endl << endl;
    system("pause");
    setNombre(nombre);
    setClave(clave);
    setEstado(true);
    return true;
}

bool Usuario::comprobarUsuario(char* nombre){

    Usuario* User = new Usuario();
    FILE* archivo = fopen("Usuarios.dat","rb");
    while(fread(User,sizeof (Usuario),1,archivo)){
        if(strcmp(User->getNombre(),nombre)==0){
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
}

bool Usuario::comprobarClave(char* nombre, char* clave){

    Usuario* User = new Usuario();
    FILE* archivo = fopen("Usuarios.dat","rb");
    while(fread(User,sizeof (Usuario),1,archivo)){
        if(strcmp(User->getNombre(),nombre)==0 && strcmp(User->getClave(),clave)==0){
            fclose(archivo);
            return true;
        }
    }
    fclose(archivo);
}

void Usuario::cambiarClave(){

    int Aux=1;
    Usuario* Usaux = new Usuario();
    Validacion* Validar = new Validacion();
    char Clave[20],ClaveAux[20],Nombre[20];

    while (Aux == 1){

        system("cls");
        cout<<"\n CAMBIAR CLAVE";
        cout<<"\n ---------------------" << endl;

        cout<<"\n Ingrese nombre actual: ";
        cin>>Nombre;
        if(Validar->regresar(Nombre))
            return;
        if(Usaux->comprobarUsuario(Nombre)){

            cout<<"\n Ingrese clave actual: ";
            cin>>Clave;
            if(Validar->regresar(Clave))
                return;

            if(Usaux->comprobarClave(Nombre,Clave)){

                cout<<"\n Ingrese la nueva clave:";
                cin>>Clave;
                if(Validar->regresar(Clave))
                    return;

                cout<<"\n Reingrese la nueva clave:";
                cin>>ClaveAux;
                if(Validar->regresar(ClaveAux))
                    return;

                if(strcmp(Clave,ClaveAux) ==0){
                    FILE* FileUsuario = fopen ("Usuarios.dat","rb+");

                    while(fread(Usaux,sizeof (Usuario),1,FileUsuario)){
                        if(strcmp(Usaux->getNombre(),Nombre) ==0){
                            Usaux->setClave(Clave);
                            fseek(FileUsuario,-sizeof (Usuario),1);
                            fwrite(Usaux,sizeof (Usuario),1,FileUsuario);
                            fclose(FileUsuario);
                            return;
                        }
                    }
                    fclose(FileUsuario);
                }
                else{
                    cout <<"\n Las dos claves son diferentes. " << endl << endl;
                    system("pause");
                }
            }
            else{
                cout <<"\n La clave es incorrecta. " << endl << endl;
                system("pause");
            }
        }
        else{
            cout <<"\n El nombre de usuario es inexistente. " << endl << endl;
            system("pause");
        }
    }
}

void Usuario::eliminar(){

    char nombre[20];
    Validacion* Validar = new Validacion();

    system("cls");
    cout<<"\n ELIMINAR USUARIO ";
    cout<<"\n ----------------" << endl;
    cout<<"\n Ingrese el nombre del usuario a eliminar: ";
    cin >> nombre;

    if(Validar->regresar(nombre))
        return;

    Usuario* user = new Usuario();
    FILE* archivo = fopen("Usuarios.dat","rb+");
    while(fread(user,sizeof (Usuario),1,archivo)){

        if(strcmp(user->getNombre(),nombre) == 0 && user->getEstado() == true){

            user->setEstado(false);
            fseek(archivo,-sizeof (Usuario),1);
            fwrite(user,sizeof (Usuario),1,archivo);
            fclose(archivo);
            cout<<"/n EL REGISTRO HA SIDO ELIMINADO SATISFACTORIAMENTE! "<<endl;
            system("pause");
        }
    }
}

#endif // USUARIOS_H_INCLUDED
