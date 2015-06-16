#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

void menuVenta(); /// LO ARMÉ ASÍ PORQUE CREO QUE RESULTA MÁS CÓMODO Y ORDENADO QUE EL MENÚ PRINCIPAL SEA EL PRIMERO.
void menuArticulo();
void menuClientes();
void menuEmpleados();
Usuario* menuUsuarios(Usuario*);
void menuAdministracion(Usuario*);

void presentacion(){
    cout<<"\n\n";
    cout<<"\t"<<(char)201; for(int i=0 ; i<65 ; i++) cout<<(char)205; cout<<(char)187<<endl;
    for(int i=0;i<2;i++)
    cout<<"\t"<<(char)186<<"                                                                 "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"                    S U P E R - G E S T I O N  "<<(char)5<<"                 "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"                    ";for(int i=0;i<25;i++) cout<<(char)223;cout<<"                    "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"                                                                 "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"                                                                 "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"              (VERSION BETA - PROTOTIPO DE PROYECTO)             "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"                                                                 "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"               REALIZADO POR:  Bernardi Federico                 "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"                               Montero Ramiro                    "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"                               Trindade Maximiliano              "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"                                                                 "<<(char)186<<"\n";
    cout<<"\t"<<(char)186<<"                                                                 "<<(char)186<<"\n";
    cout<<"\t"<<(char)200; for(int i=0 ; i<65 ; i++) cout<<(char)205; cout<<(char)188<<"\n\n\n\t\t\t";

    system("pause");
}

void menuPrincipal(Usuario* User){
    char opc='1';

    while(opc!='S' or opc!= 's'){
        system("CLS");

        cout<<"MENU PRINCIPAL"<<setw(15)<<"USUARIO: " << User->getNombre()<<endl;
        cout<<"---------------------"<<endl;
        cout<<"A) EMPLEADOS"<<endl;
        cout<<"B) CLIENTES"<<endl;
        cout<<"C) ARTICULOS"<<endl;
        cout<<"D) VENTAS"<<endl;
        cout<<"E) PROMOCIONES"<<endl;
        cout<<"F) COMPRAS"<<endl;
        cout<<"G) PROVEEDORES"<<endl;
        cout<<"H) USUARIOS"<<endl;
        cout<<"I) ADMINISTRACION"<<endl;
        cout<<"J) INFORMES"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"S) SALIR"<<endl<<endl;
        cout<<"OPCION: ";
        opc=getch();
        system("CLS");
        switch(opc){
            case 'A': case 'a':   menuEmpleados();
                break;
            case 'B': case 'b':   menuClientes();
                break;
            case 'C': case 'c':   menuArticulo();
                break;
            case 'D': case 'd':   menuVenta();
                break;
            case 'E': case 'e':
            case 'F': case 'f':
            case 'G': case 'g':
            case 'H': case 'h':   User=menuUsuarios(User);
                break;
            case 'I': case 'i':   menuAdministracion(User);
                break;
            case 'J': case 'j': {
                system("cls"); cout<<"\n MENU DISPONIBLE SOLO EN LA VERSION COMPLETA...\n\n ";
                system("pause");
            }
                break;
            case 'S': case 's': return;
            default: cout << "\n La opcion ingresada es incorrecta. \n\n "; system("pause");
                break;
        }
    }
}

void menuArticulo(){

    char opc='1';
    Articulo* art = new Articulo();
    Archivo * archivo = new Archivo();

    while(opc!='0'){
        system("CLS");
        cout<<"---------------------"<<endl;
        cout<<"MENU ARTICULO"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1) CARGAR ARTICULO"<<endl;
        cout<<"2) EDITAR ARTICULO"<<endl;
        cout<<"3) MOSTRAR POR CODIGO"<<endl;
        cout<<"4) MOSTRAR TODOS"<<endl;
        cout<<"5) DAR DE BAJA"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"OPCION: ";
        opc=getch();
        switch(opc){
            case '1': if(art->cargar())
                        archivo->guardar(art,arti);
                break;
            case '2': archivo->editar(arti);
                break;
            case '3': archivo->listarXCodigo(arti);
                break;
            case '4': archivo->listarTodos(arti);
                break;
            case '5': archivo->eliminar(arti);
                break;
            case '0':
                break;
            default:
                break;
        }
    }
}

void menuClientes(){

    char opc='1';
    Cliente* cli = new Cliente();
    Archivo* archivo = new Archivo();

    while(opc!='0'){
        system("CLS");
        cout<<"---------------------"<<endl;
        cout<<"MENU CLIENTES"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1) CARGAR CLIENTE"<<endl;
        cout<<"2) EDITAR CLIENTE"<<endl;
        cout<<"3) MOSTRAR POR CODIGO"<<endl;
        cout<<"4) MOSTRAR TODOS"<<endl;
        cout<<"5) DAR DE BAJA"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"OPCION: ";
        opc=getch();
        switch(opc){
            case '1':   if(cli->cargar())
                            archivo->guardar(cli,clie);
                break;
            case '2':   archivo->editar(clie);
                break;
            case '3':   archivo->listarXCodigo(clie);
                break;
            case '4':   archivo->listarTodos(clie);
                break;
            case '5':   archivo->eliminar(clie);
                break;
            case '0':
                break;
            default:
                break;
        }
    }
}

void menuEmpleados(){

    char opc='1';
    Empleado* emp = new Empleado();
    Archivo* archivo = new Archivo();

    while(opc!='0'){
        system("CLS");
        cout<<"---------------------"<<endl;
        cout<<"MENU EMPLEADOS"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1) CARGAR EMPLEADO"<<endl;
        cout<<"2) EDITAR EMPLEADO"<<endl;
        cout<<"3) MOSTRAR POR CODIGO"<<endl;
        cout<<"4) MOSTRAR TODOS"<<endl;
        cout<<"5) MOSTRAR SECTOR"<<endl;
        cout<<"6) DAR DE BAJA"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"OPCION: ";
        opc=getch();
        system("CLS");
        switch(opc){
            case '1':   if(emp->cargar())
                            archivo->guardar(emp,empl);
                break;
            case '2':
                break;
            case '3':   archivo->listarXCodigo(empl);
                break;
            case '4':   archivo->listarTodos(empl);
                break;
            case '5':
                break;
            case '6':   archivo->eliminar(empl);
                break;
            case '0':
                break;
            default:
                break;
        }
    }
}

void menuVenta(){

    int estado;
    char opc='1';
    Venta *venta = new Venta();
    Archivo* archivo = new Archivo();

    while(opc!='0'){
        system("CLS");
        cout<<"---------------------"<<endl;
        cout<<"MENU VENTA"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1) CARGAR VENTA"<<endl;
        cout<<"2) MOSTRAR TODAS LAS VENTAS"<<endl;
        cout<<"3) MOSTRAR POR CODIGO"<<endl;
        cout<<"4) MOSTRAR VENTAS POR CLIENTE"<<endl;
        cout<<"5) MOSTRAR VENTAS POR ARTICULO"<<endl;
        cout<<"6) MOSTRAR VENTAS POR FECHA"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"OPCION: ";
        opc=getch();
        switch(opc){
            case '1': estado = venta->cargar();
                    if(estado == grabo or estado == bajaLogica){
                        archivo->guardar(venta,vent);
                    }
                break;
            case '2': archivo->listarTodos(vent);
                break;
            case '3': archivo->listarXCodigo(vent);
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '0':
                break;
            default:
                break;
        }
    }
}

Usuario* menuUsuarios(Usuario* User){

    char opc='1';
    Archivo* archivo = new Archivo();
    Usuario* Usu = new Usuario();

    while(opc!='S' and opc != 's'){

        if(strcmp(User->getNombre(),"INVITADO") ==0 or User->getEstado() == false){
            system("cls");
            cout << "\n ACCESO DENEGADO " << endl;
            cout << "\n No tiene los permisos necesarios para ingresar a este submenu " << endl << endl;
            system("pause");
            return User;
        }

        system("cls");
        cout<<"\n USUARIO: " << User->getNombre() << endl;
        cout<<" --------------------"<<endl;
        cout<<" 1 - AGREGAR USUARIOS"<<endl;
        cout<<" 2 - LISTAR USUARIOS"<<endl;
        cout<<" 3 - CAMBIAR CLAVE"<<endl;
        cout<<" 4 - ELIMINAR USUARIO"<<endl;
        cout<<" 5 - CAMBIO DE SESION"<<endl;
        cout<<" --------------------"<<endl;
        cout<<" S - VOLVER AL MENU PRINCIPAL\n";
        opc=getch();
        switch(opc){
            case '1': if(Usu->cargar())
                        archivo->guardar(Usu,usua);
                break;
            case '2': archivo->listarTodos(usua);
                break;
            case '3': User->cambiarClave();
                break;
            case '4': User->eliminar();
                break;
            case '5': User=Usu->login();
                break;
            case '0':
                break;
            case 'S': case 's': return User;
            default: cout << "\n La opcion ingresada es incorrecta. \n\n ";
                system("pause");
                break;
        }
    }
    return User;
}

void menuAdministracion(Usuario* User){

    char opc='1';
    Archivo* archivo = new Archivo();

    if(strcmp(User->getNombre(),"INVITADO") ==0 or User->getEstado() == false){
        system("cls");
        cout << "\n ACCESO DENEGADO " << endl;
        cout << "\n No tiene los permisos necesarios para ingresar a este submenu " << endl << endl;
        system("pause");
        return;
    }

    while(opc != 'S' and opc != 's'){

        system("cls");
        cout<<"\n ADMINISTRACION: " << User->getNombre() << endl;
        cout<<" ----------------------"<<endl;
        cout<<" 1 - RECUPERAR REGISTRO"<<endl;
        cout<<" 2 - BAJA FISICA DE USUARIOS"<<endl;
        cout<<" 3 - COPIA DE SEGURIDAD"<<endl;
        cout<<" 4 - RESTAURAR COPIA DE SEGURIDAD"<<endl;
        cout<<" ----------------------------"<<endl;
        cout<<" S - VOLVER AL MENU PRINCIPAL\n";
        opc=getch();
        switch(opc){
            case '1': archivo->alta();
                break;
            case '2': archivo->BajaFisica();
                break;
            case '3': archivo->backup();
                break;
            case '4': archivo->restaurarCopia();
                break;
            case 'S': case 's': return;
            default: cout << "\n La opcion ingresada es incorrecta. \n\n ";
                system("pause");
                break;
        }
    }
}

#endif // MENUES_H_INCLUDED
