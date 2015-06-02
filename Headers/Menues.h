#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

void menuVenta(); /// LO ARMÉ ASÍ PORQUE CREO QUE RESULTA MÁS CÓMODO Y ORDENADO QUE EL MENÚ PRINCIPAL SEA EL PRIMERO
void menuArticulo();
void menuClientes();
void menuEmpleados();

void menuPrincipal(){
    char opc='1';

    while(opc!='0'){
        cout<<"---------------------"<<endl;
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1) EMPLEADOS"<<endl;
        cout<<"2) CLIENTES"<<endl;
        cout<<"3) ARTICULOS"<<endl;
        cout<<"4) VENTAS"<<endl;
        cout<<"5) PROMOCIONES"<<endl;
        cout<<"6) COMPRAS"<<endl;
        cout<<"7) PROVEEDORES"<<endl;
        cout<<"8) USUARIOS"<<endl;
        cout<<"9) ADMINISTRACION"<<endl;
        cout<<"10) INFORMES"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0) SALIR"<<endl<<endl;
        cout<<"OPCION: ";
        opc=getch();
        system("CLS");
        switch(opc){
            case '1':   menuEmpleados();
                        break;
            case '2':   menuClientes();
                        break;
            case '3':   menuArticulo();
                        break;
            case '4':   menuVenta();
                        break;
            case '5':
            case '6':
            case '7':
            case '8':
            case '0':
            default: cout << "La opcion ingresada es incorrecta. " << endl;
                break;
        }
        system("CLS");
    }

}

void menuVenta(){
    char opc='1';

    while(opc!='0'){
        cout<<"---------------------"<<endl;
        cout<<"MENU VENTA"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1) CARGAR VENTA"<<endl;
        cout<<"2) MOSTRAR POR CODIGO"<<endl;
        cout<<"3) MOSTRAR VENTAS POR CLIENTE"<<endl;
        cout<<"4) MOSTRAR VENTAS POR ARTICULO"<<endl;
        cout<<"5) MOSTRAR VENTAS POR FECHA"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"OPCION: ";
        opc=getch();
        switch(opc){
            case '1':
                        break;
            case '2':
            case '3':
            case '4':
            case '5':
            case '0':
            default:
                break;
        }
    }
}

void menuArticulo(){

    char opc='1';
    Articulo* Art = new Articulo();

    while(opc!='0'){
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
            case '1': Art->cargar();
                break;
            case '2':
            case '3':
            case '4':
            case '5':
            case '0':
            default:
                break;
        }
    }
}

void menuClientes(){

    char opc='1';
    Clientes* Cli = new Clientes();

    while(opc!='0'){
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
            case '1': Cli->cargar();
                        break;
            case '2':
            case '3':
            case '4':
            case '5':
            case '0':
            default:
                break;
        }
    }
}

void menuEmpleados(){

    char opc='1';

    while(opc!='0'){
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
            case '1':
                break;
            case '2':
                break;
            case '3':
            case '4':
                break;
            case '5':
            case '0':
                break;
            default:
                break;
        }
        system("CLS");
    }
}


#endif // MENUES_H_INCLUDED
