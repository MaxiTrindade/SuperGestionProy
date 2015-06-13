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

void Usuario::setNombre(char nombre[20]){
    strcpy(this->nombre,nombre);
}

void Usuario::setClave(char clave[20]){
    strcpy(this->clave,clave);
}

void Usuario::setEstado(bool estado){
    this->estado=estado;
}

void Usuario::login(){

    char nombre[20],clave[20];
    Usuario* Usu = new Usuario();
    Usuario* User = new Usuario();
    int Aux=0;

    FILE* archivo = fopen("Usuarios.dat","ab");
    if(archivo == NULL){
        Usu->setNombre("UTN");
        Usu->setClave("UTN");
        Usu->setEstado(true);
        fwrite(Usu,sizeof (Usuario),1,archivo);
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
            return;
        }
        else{
            FILE* FileUser = fopen ("Usuarios.dat","rb");

            while(fread(&User,sizeof User,1,FileUser)){

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
                        return;
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



#endif // USUARIOS_H_INCLUDED
