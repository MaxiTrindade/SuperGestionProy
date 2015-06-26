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
        gotoxy(34,7);
        cout<<endl<<setw(22)<<(char)201; for(int i=0;i<30;i++) cout<<(char)205; cout<<(char)187;
        cout<<endl<<setw(22)<<(char)186; for(int i=0;i<30;i++) cout<<" "; cout<<(char)186;
        cout<<endl<<setw(22)<<(char)186; for(int i=0;i<3;i++) cout<<" ";cout<<"USUARIO:";for(int i=0;i<19;i++) cout<<" " ;cout<<(char)186;
        cout<<endl<<setw(22)<<(char)186; for(int i=0;i<30;i++) cout<<" "; cout<<(char)186;
        cout<<endl<<setw(22)<<(char)186; for(int i=0;i<3;i++) cout<<" ";cout<<"CLAVE:";for(int i=0;i<21;i++) cout<<" " ;cout<<(char)186;
        cout<<endl<<setw(22)<<(char)186; for(int i=0;i<30;i++) cout<<" "; cout<<(char)186;
        cout<<endl<<setw(22)<<(char)200; for(int i=0;i<30;i++) cout<<(char)205; cout<<(char)188;
        gotoxy(34,10);

        cin>>nombre;

        FILE* FileUser = fopen ("Usuarios.dat","rb");

        while(fread(User,sizeof (Usuario),1,FileUser)){

            if(strcmp(User->getNombre(),nombre) ==0 && User->getEstado() == true){

                Aux = 1;

                gotoxy(32,12);
                cin >> clave;

                if(strcmp(User->getClave(),clave) ==0){
                    fclose(FileUser);
                    Usu->setNombre(nombre);
                    Usu->setClave(clave);
                    Usu->setEstado(true);
                    Usu->setColor(User->leerColor());
                    system(User->getColor());
                    return Usu;
                }
                else{
                    gotoxy(20,16);
                    cout<<"La clave ingresada es incorrecta.";
                    gotoxy(22,18); system("pause");
                }
            }
        }
        if (Aux == 0){
            gotoxy(20,16);
            cout<<"No es un nombre de usuario valido.";
            gotoxy(22,18); system("pause");
        }

        Aux = 0;

        fclose(FileUser);
    }
}

bool cerrarSesion(){
    system("cls");
    Usuario* user = new Usuario();
    cout<<"\n Confirma que desea cerrar la sesion?\n\n SI (S) - NO (OTRO)\n\n ";
    char opcion = (char)getch();
    switch (opcion){
        case 'S': case 's':
            cout<<"\n Se ha cerrado la sesion\n\n ";
            system("pause");
            return true;
        default: return false;
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

    if(strcmp(nombre,"UTN")==0){
        system("cls");
        cout<<"\n\n No se puede eliminar al usuario 'UTN' (Predeterminado)\n\n ";
        system("pause"); return;
    }

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
            cout<<"\n EL REGISTRO HA SIDO ELIMINADO SATISFACTORIAMENTE! "<<endl;
            system("pause");
        }
    }
}

void Usuario::cambiarColor(){
    char color[9] = "COLOR ";
    bool flag=true;
    char opc;

    while(flag){
        system(color);
        strcpy(color,"COLOR ");
        system("cls");
        cout<<"COLORES DE FONDO"<<endl<<endl;
        cout<<"0---NEGRO"<<endl;
        cout<<"1---AZUL"<<endl;
        cout<<"2---VERDE"<<endl;
        cout<<"3---AGUAMARINA"<<endl;
        cout<<"4---ROJO"<<endl;
        cout<<"5---PURPURA"<<endl;
        cout<<"6---AMARILLO"<<endl;
        cout<<"7---BLANCO"<<endl;
        cout<<"8---GRIS"<<endl;
        cout<<"9---AZUL CLARO"<<endl<<endl;
        cout<<"OTRO---SALIR"<<endl<<endl;
        cout<<"OPCION: ";
        opc=getch();

        switch(opc){
            case '0':   strcat(color,"0");
                        break;
            case '1':   strcat(color,"1");
                        break;
            case '2':   strcat(color,"2");
                        break;
            case '3':   strcat(color,"3");
                        break;
            case '4':   strcat(color,"4");
                        break;
            case '5':   strcat(color,"5");
                        break;
            case '6':   strcat(color,"6");
                        break;
            case '7':   strcat(color,"7");
                        break;
            case '8':   strcat(color,"8");
                        break;
            case '9':   strcat(color,"9");
                        break;
            default:
                return;
        }
        system("CLS");
        cout<<"COLORES DE TEXTO"<<endl<<endl;
        cout<<"A---Verde claro"<<endl;
        cout<<"B = Aguamarina claro"<<endl;
        cout<<"C = Rojo claro"<<endl;
        cout<<"D = Purpura claro"<<endl;
        cout<<"E = Amarillo claro"<<endl;
        cout<<"F = Blanco brillante"<<endl<<endl;
        cout<<"OTRO = SALIR"<<endl<<endl;
        cout<<"OPCION: ";
        opc=getch();
        switch(opc){
            case 'a': case 'A':  strcat(color,"A");
                break;
            case 'b': case 'B':  strcat(color,"B");
                break;
            case 'c': case 'C':  strcat(color,"C");
                break;
            case 'd': case 'D':  strcat(color,"D");
                break;
            case 'e': case 'E':  strcat(color,"E");
                break;
            case 'f': case 'F':  strcat(color,"F");
                break;
            default:
                return;
        }
        system("CLS");
        setColor(color);

        FILE* archivo = fopen("Usuarios.dat","rb+");
        Usuario* user = new Usuario();
        while(fread(user,sizeof(Usuario),1,archivo))
            if(strcmp(user->nombre,this->nombre) == 0){
                fseek(archivo,-sizeof(Usuario),1);
                fwrite(this,sizeof(Usuario),1,archivo);
                fclose(archivo);
            }

    }
}

char* Usuario::leerColor(){
    Usuario user;
    FILE* archivo = fopen("Usuarios.dat","rb");
    while(fread(&user,sizeof (Usuario),1,archivo))
        if(strcmp(user.getNombre(),this->getNombre())== 0)
           return (user.color);
}

#endif // USUARIOS_H_INCLUDED
