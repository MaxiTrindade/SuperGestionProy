#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

void menuVenta(); /// LO ARMÉ ASÍ PORQUE CREO QUE RESULTA MÁS CÓMODO Y ORDENADO QUE EL MENÚ PRINCIPAL SEA EL PRIMERO.
void menuArticulo();
void menuClientes();
void menuEmpleados();
Usuario* menuUsuarios(Usuario*);
void menuAdministracion(Usuario*);
void menuInformes();
void menuCompra();
void menuProveedores();
void menuPromociones();

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

        system("CLS");
        cout<<"\n"<<setw(52)<<"S U P E R - G E S T I O N  "<<(char)5<<setw(30);
        cout<<setw(53);for(int i=0;i<25;i++) cout<<(char)223; cout<<setw(19)<<"USUARIO: "<<User->getNombre()<<endl;
        cout<<ends<<(char)201; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)187<<endl;
        cout<<ends<<(char)186<<setw(43)<<"MENU PRINCIPAL"<<setw(22)<<"FECHA: ";
        Imprimir* mostrar = new Imprimir();
        Fecha fechaSys = fechaSistema(fechaSys);
        mostrar->fecha(fechaSys); cout<<ends<<(char)186<<endl;

        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(32)<<"A) EMPLEADOS"<<setw(20)<<"F) COMPRAS"<<setw(24)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(31)<<"B) CLIENTES"<<setw(25)<<"G) PROVEEDORES"<<setw(20)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(32)<<"C) ARTICULOS"<<setw(21)<<"H) USUARIOS"<<setw(23)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(29)<<"D) VENTAS"<<setw(30)<<"I) ADMINISTRACION"<<setw(17)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(34)<<"E) PROMOCIONES"<<setw(19)<<"J) INFORMES"<<setw(23)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(40)<<"S) SALIR"<<setw(36)<<(char)186<<endl;
        cout<<ends<<(char)200; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)188<<endl;

        cout<<endl<<setw(42)<<"OPCION: ";
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
            case 'E': case 'e':   menuPromociones();
                break;
            case 'F': case 'f':   menuCompra();
                break;
            case 'G': case 'g':   menuProveedores();
                break;
            case 'H': case 'h':   User = menuUsuarios(User);
                break;
            case 'I': case 'i':   menuAdministracion(User);
                break;
            case 'J': case 'j':   menuInformes();
                break;
            case 'S': case 's': return;
            default:
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

        cout<<"\n"<<setw(52)<<"S U P E R - G E S T I O N  "<<(char)5<<setw(30);
        cout<<setw(53);for(int i=0;i<25;i++) cout<<(char)223; cout<<endl;
        cout<<ends<<(char)201; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)187<<endl;
        cout<<ends<<(char)186<<setw(43)<<"MENU ARTICULOS"<<setw(33)<<(char)186<<endl;

        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"1- CARGAR ARTICULO"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"2- EDITAR ARTICULO"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(47)<<"3- MOSTRAR POR CODIGO"<<setw(29)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(44)<<"4- MOSTRAR TODOS"<<setw(32)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(43)<<"5- DAR DE BAJA"<<setw(33)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(40)<<"0- SALIR"<<setw(36)<<(char)186<<endl;
        cout<<ends<<(char)200; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)188<<endl;

        cout<<endl<<setw(42)<<"OPCION: ";

        opc=getch();
        switch(opc){
            case '1': if(art->cargar())
                        archivo->guardar(art,arti);
                break;
            case '2':
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
        cout<<"\n"<<setw(52)<<"S U P E R - G E S T I O N  "<<(char)5<<setw(30);
        cout<<setw(53);for(int i=0;i<25;i++) cout<<(char)223; cout<<endl;
        cout<<ends<<(char)201; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)187<<endl;
        cout<<ends<<(char)186<<setw(43)<<"MENU CLIENTES"<<setw(33)<<(char)186<<endl;

        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"1- CARGAR CLIENTE"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"2- EDITAR CLIENTE"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(47)<<"3- MOSTRAR POR CODIGO"<<setw(29)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(44)<<"4- MOSTRAR TODOS"<<setw(32)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(43)<<"5- DAR DE BAJA"<<setw(33)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(40)<<"0- SALIR"<<setw(36)<<(char)186<<endl;
        cout<<ends<<(char)200; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)188<<endl;

        cout<<endl<<setw(42)<<"OPCION: ";
        opc=getch();
        switch(opc){
            case '1':   if(cli->cargar())
                            archivo->guardar(cli,clie);
                break;
            case '2':
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
        cout<<"\n"<<setw(52)<<"S U P E R - G E S T I O N  "<<(char)5<<setw(30);
        cout<<setw(53);for(int i=0;i<25;i++) cout<<(char)223; cout<<endl;
        cout<<ends<<(char)201; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)187<<endl;
        cout<<ends<<(char)186<<setw(43)<<"MENU EMPLEADOS"<<setw(33)<<(char)186<<endl;

        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"1- CARGAR EMPLEADO"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"2- EDITAR EMPLEADO"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(47)<<"3- MOSTRAR POR CODIGO"<<setw(29)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(44)<<"4- MOSTRAR TODOS"<<setw(32)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(48)<<"5- MOSTRAR POR SECCION"<<setw(28)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(43)<<"6- DAR DE BAJA"<<setw(33)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(40)<<"0- SALIR"<<setw(36)<<(char)186<<endl;
        cout<<ends<<(char)200; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)188<<endl;

        cout<<endl<<setw(42)<<"OPCION: ";
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
        cout<<"\n"<<setw(52)<<"S U P E R - G E S T I O N  "<<(char)5<<setw(30);
        cout<<setw(53);for(int i=0;i<25;i++) cout<<(char)223; cout<<endl;
        cout<<ends<<(char)201; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)187<<endl;
        cout<<ends<<(char)186<<setw(42)<<"MENU VENTAS"<<setw(34)<<(char)186<<endl;

        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(44)<<"1- CARGAR VENTA"<<setw(32)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"2- MOSTRAR TODAS"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(48)<<"3- MOSTRAR POR CODIGO"<<setw(28)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(49)<<"4- MOSTRAR POR CLIENTE"<<setw(27)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(49)<<"5- MOSTRAR POR ARTICULO"<<setw(27)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(47)<<"6- MOSTRAR POR FECHA"<<setw(29)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(40)<<"0- SALIR"<<setw(36)<<(char)186<<endl;
        cout<<ends<<(char)200; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)188<<endl;

        cout<<endl<<setw(42)<<"OPCION: ";
        opc=getch();
        system("CLS");
        switch(opc){
            case '1': /*estado = venta->cargar();
                    if(estado == grabo or estado == bajaLogica){
                        archivo->guardar(venta,vent);
                    }*/
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

void menuCompra(){

    int estado;
    char opc='1';
    Compra *compra = new Compra();
    Archivo* archivo = new Archivo();

    while(opc!='0'){

        system("CLS");
        cout<<"\n"<<setw(52)<<"S U P E R - G E S T I O N  "<<(char)5<<setw(30);
        cout<<setw(53);for(int i=0;i<25;i++) cout<<(char)223; cout<<endl;
        cout<<ends<<(char)201; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)187<<endl;
        cout<<ends<<(char)186<<setw(42)<<"MENU VENTAS"<<setw(34)<<(char)186<<endl;

        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(44)<<"1- CARGAR COMPRA"<<setw(32)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(50)<<"2- MOSTRAR TODAS LAS COMPRAS"<<setw(26)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(51)<<"3- MOSTRAR COMPRAS INCORRECTAS"<<setw(25)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(46)<<"4- MOSTRAR POR CODIGO"<<setw(30)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(40)<<"0- SALIR"<<setw(36)<<(char)186<<endl;
        cout<<ends<<(char)200; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)188<<endl;

        cout<<endl<<setw(42)<<"OPCION: ";
        opc=getch();

        switch(opc){
            case '1': estado = compra->cargar();
                    if(estado == 0 or estado == 1){
                        archivo->guardar(compra,comp);
                    }
                break;
            case '2': archivo->listarTodos(comp);
                break;
            case '3':
            case '4': //archivo->listarXCodigo(comp);
                break;
            case '0':
                break;
            default:
                break;
        }
    }
}

void menuProveedores(){
    char opc='1';
    Proveedor* pro = new Proveedor();
    Archivo* archivo = new Archivo();

    while(opc!='0'){

        system("CLS");
        cout<<"\n"<<setw(52)<<"S U P E R - G E S T I O N  "<<(char)5<<setw(30);
        cout<<setw(53);for(int i=0;i<25;i++) cout<<(char)223; cout<<endl;
        cout<<ends<<(char)201; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)187<<endl;
        cout<<ends<<(char)186<<setw(44)<<"MENU PROVEEDORES"<<setw(32)<<(char)186<<endl;

        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"1- CARGAR PROVEEDOR"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"2- EDITAR PROVEEDOR"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(46)<<"3- MOSTRAR POR CODIGO"<<setw(30)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(44)<<"4- MOSTRAR TODOS"<<setw(32)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(48)<<"5- MOSTRAR POR CATEGORIA"<<setw(28)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(40)<<"0- SALIR"<<setw(36)<<(char)186<<endl;
        cout<<ends<<(char)200; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)188<<endl;

        cout<<endl<<setw(42)<<"OPCION: ";
        opc=getch();

        system("CLS");
        switch(opc){
            case '1':   if(pro->cargar())
                            archivo->guardar(pro,prov);
                break;
            case '2':
                break;
            case '3':  // archivo->listarXCodigo(prov);
                break;
            case '4':   archivo->listarTodos(prov);
                break;
            case '5':
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
        system("CLS");
        cout<<"\n"<<setw(52)<<"S U P E R - G E S T I O N  "<<(char)5<<setw(30);
        cout<<setw(53);for(int i=0;i<25;i++) cout<<(char)223; cout<<endl;
        cout<<ends<<(char)201; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)187<<endl;
        cout<<ends<<(char)186<<setw(43)<<"MENU USUARIOS"<<setw(33)<<(char)186<<endl;

        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"1- AGREGAR USUARIO"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(45)<<"2- LISTAR USUARIOS"<<setw(31)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(44)<<"3- CAMBIAR CLAVE"<<setw(32)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(41)<<"4- ELIMINAR"<<setw(35)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(44)<<"5- CAMBIAR SESION"<<setw(32)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(40)<<"0- SALIR"<<setw(36)<<(char)186<<endl;
        cout<<ends<<(char)200; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)188<<endl;

        cout<<endl<<setw(42)<<"OPCION: ";

        Usuario* Usu = new Usuario();

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
            case '0': return User;
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

    while(opc != 'S' and opc != 's'){

        system("CLS");
        cout<<"\n"<<setw(52)<<"S U P E R - G E S T I O N  "<<(char)5<<setw(30);
        cout<<setw(53);for(int i=0;i<25;i++) cout<<(char)223; cout<<setw(19)<<"USUARIO: "<<User->getNombre()<<endl;
        cout<<ends<<(char)201; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)187<<endl;
        cout<<ends<<(char)186<<setw(45)<<"MENU ADMINISTRACION"<<setw(31)<<(char)186<<endl;

        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(46)<<"1- RECUPERAR REGISTRO"<<setw(30)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(49)<<"2- BAJA FISICA DE USUARIOS"<<setw(27)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(51)<<"3- REALIZAR COPIA DE SEGURIDAD"<<setw(25)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(44)<<"4- RESTAURAR COPIA"<<setw(32)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(51)<<"5- CAMBIAR COLOR DEL PROGRAMA"<<setw(25)<<(char)186<<endl;
        cout<<ends<<(char)186<<setw(76)<<(char)186<<endl;
        cout<<ends<<(char)204; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)185<<endl;
        cout<<ends<<(char)186<<setw(40)<<"0- SALIR"<<setw(36)<<(char)186<<endl;
        cout<<ends<<(char)200; for(int i=0;i<75;i++) cout<<(char)205; cout<<(char)188<<endl;

        cout<<endl<<setw(42)<<"OPCION: ";
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
            case '5': User->cambiarColor();
                break;
            case '0': return;
            default:
                break;
        }
    }
}

void menuInformes(){

    Informe* informar = new Informe();
    char opc='1';

    while(opc!='0'){
        system("CLS");
        cout<<"---------------------"<<endl;
        cout<<"MENU INFORMES"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1) BALANCE TOTAL DE COMPROBACION"<<endl;
        cout<<"2) DISTRIBUCION DE ARTICULOS POR SECCION"<<endl;
        cout<<"3) ARTICULOS MAS REDITUABLES"<<endl;
        cout<<"4) ARTICULOS AGOTADOS EN STOCK"<<endl;
        cout<<"5) EMPLEADOS CON MAS VENTAS"<<endl;
        cout<<"6) DAR DE BAJA"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"OPCION: ";
        opc=getch();
        system("CLS");
        switch(opc){
            case '1':
                break;
            case '2':   informar->porcArtCargados();
                break;
            case '3':
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

void menuPromociones(){

    Promocion* promo = new Promocion();
    Archivo* archi = new Archivo();
    char opc='1';

    while(opc!='0'){
        system("CLS");
        cout<<"---------------------"<<endl;
        cout<<"MENU PROMOCIONES"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1) AGREGAR PROMOCION NXM"<<endl;
        cout<<"2) AGREGAR PROMOCION PORCENTAJE X CATEGORIA ART"<<endl;
        cout<<"3) AGREGAR PROMOCION A UN ARTICULO EN PARTICULAR"<<endl;
        cout<<"4) ELIMINAR PROMOCION"<<endl;
        cout<<"5) LISTAR PROMOCIONES"<<endl;
        cout<<"6) LISTAR PROMOCIONES X CODIGO"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"OPCION: ";
        opc=getch();
        system("CLS");
        switch(opc){
            case '1':
                if(promo->cargarNXM()){
                    archi->guardar(promo,prom);
                }
                break;
            case '2':
                if(promo->cargarPorcentaje()){
                    archi->guardar(promo,prom);
                }
                break;
            case '3':
                if(promo->cargarArticulo()){
                    archi->guardar(promo,prom);
                }
                break;
            case '4': archi->eliminar(prom);
                break;
            case '5': archi->listarTodos(prom);
                break;
            case '6': archi->listarXCodigo(prom);
                break;
            case '0':
                break;
            default:
                break;
        }
    }
    cout<<(float)promo->getDesc() << endl;
    system("pause");
}


#endif // MENUES_H_INCLUDED
