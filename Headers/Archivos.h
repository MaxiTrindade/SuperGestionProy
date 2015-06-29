#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

void Archivo::guardar(void* objeto,int num){   //// EN ESTA FUNCION SE HAN COMENTADO LAS ENUMERACIONES DE LAS CLASES AUN NO CREADAS ////

    FILE* archivo;

    switch(num){
        case arti:
        {
            Articulo* articulo = (Articulo*)objeto;
            archivo = fopen("Articulos.dat","ab");
            fwrite(articulo,sizeof(Articulo),1,archivo);
        }
            break;

        case clie:
        {
            Cliente* cliente = (Cliente*)objeto;
            archivo = fopen("Clientes.dat","ab");
            fwrite(cliente,sizeof(Cliente),1,archivo);
        }
            break;

        case prov:
        {
            Proveedor* proveedor = (Proveedor*)objeto;
            archivo = fopen("Proveedores.dat","ab");
            fwrite(proveedor,sizeof(Proveedor),1,archivo);
        }
            break;

        case empl:
        {
            Empleado* empleado = (Empleado*)objeto;
            archivo = fopen("Empleados.dat","ab");
            fwrite(empleado,sizeof (Empleado),1,archivo);
        }
            break;

        case comp:
        {
            Compra* compra = (Compra*)objeto;
            archivo = fopen("Compras.dat","ab");
            fwrite(compra,sizeof (Compra),1,archivo);
        }
            break;

        case vent:
        {
            Venta* venta = (Venta*)objeto;
            archivo = fopen("Ventas.dat","ab");
            fwrite(venta,sizeof (Venta),1,archivo);
        }
            break;

        case usua:
        {
            Usuario* usuario = (Usuario*)objeto;
            archivo = fopen("Usuarios.dat","ab");
            fwrite(usuario,sizeof (Usuario),1,archivo);
        }
            break;

        case prom:
        {
            Promocion* promo = (Promocion*)objeto;
            archivo = fopen("Promos.dat","ab");
            fwrite(promo,sizeof (Promocion),1,archivo);
        }
            break;

        case artXVen:
        {
            ArtXVenta* ArtxVen = (ArtXVenta*)objeto;
            archivo = fopen("ArtXVentas.dat","ab");
            fwrite(ArtxVen,sizeof (ArtXVenta),1,archivo);
        }
            break;

        case artXCom:
        {
            ArtXCompra* ArtxCom = (ArtXCompra*)objeto;
            archivo = fopen("ArtXCompra.dat","ab");
            fwrite(ArtxCom,sizeof(Articulo),1,archivo);
        }
            break;

    }
    fclose(archivo);
}

void Archivo::listarTodos(int num){

    FILE* archivo;
    system("cls");
    Imprimir* mostrar = new Imprimir();

    switch(num){

        case arti:{
            Articulo* articulo = new Articulo();
            archivo = fopen("Articulos.dat","rb");
            while(fread(articulo,sizeof (Articulo),1,archivo)){

                if(articulo->getEstado() == true){

                    mostrar->articulo(articulo);
                }
            }
            system("pause");
        }
            break;

        case clie:{
            Cliente* cliente = new Cliente();
            archivo = fopen("Clientes.dat","rb");
            while(fread(cliente,sizeof (Cliente),1,archivo)){

                if(cliente->getEstado() == true){

                    mostrar->cliente(cliente);
                }
            }
            system("pause");
        }
            break;

        case vent:{
            Venta* venta = new Venta();
            archivo = fopen("Ventas.dat","rb");
            while(fread(venta,sizeof (Venta),1,archivo)){

                mostrar->venta(venta);
            }
            system("pause");
        }
            break;

        case empl:{
            Empleado* empleado = new Empleado();
            Imprimir* mostrar = new Imprimir();
            archivo = fopen("Empleados.dat","rb");
            while(fread(empleado,sizeof (Empleado),1,archivo)){
                if(empleado->getEstado() == true){

                    mostrar->empleado(empleado);
                }
            }
            system("pause");
        }
            break;

        case usua:{
            Usuario* user = new Usuario();
            archivo = fopen("Usuarios.dat","rb");
            while(fread(user,sizeof (Usuario),1,archivo)){

                if(user->getEstado() == true){
                    mostrar->usuario(user);
                }
            }
            system("pause");
        }
            break;

        case prov:{
            Proveedor* proveedor = new Proveedor();
            archivo = fopen("Proveedores.dat","rb");
            while(fread(proveedor,sizeof (Proveedor),1,archivo)){

                    mostrar->proveedor(proveedor);
            }
            system("pause");
        }
            break;

        case prom:{
            Promocion* promo = new Promocion();
            archivo = fopen("Promos.dat","rb");
            while(fread(promo,sizeof (Promocion),1,archivo)){

                if(promo->getEstado() == true){
                    mostrar->promocion(promo);
                }
            }
            system("pause");
        }
            break;
    }
    fclose(archivo);
}

void Archivo::listarXCodigo(int num){

    int cod,aux=0;
    Imprimir* mostrar = new Imprimir();

    system("cls");
    cout<<"LISTAR POR CODIGO"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"INGRESE EL CODIGO A LISTAR: ";
    cin>>cod;
    cout<<"---------------------------"<<endl;

    FILE* archivo;
    switch(num){

        case arti:{
            Articulo* articulo = new Articulo();
            archivo = fopen("Articulos.dat","rb");
            while(fread(articulo,sizeof (Articulo),1,archivo)){

                if(articulo->getCodigo() == cod && articulo->getEstado() == true){

                    mostrar->articulo(articulo);
                    system("pause");
                    aux = -1;
                }
            }
        }
            break;
        case clie:{
            Cliente* cliente = new Cliente();
            archivo = fopen("Clientes.dat","rb");
            while(fread(cliente,sizeof (Cliente),1,archivo)){

                if(cliente->getCodigo() == cod && cliente->getEstado() == true){
                    mostrar->cliente(cliente);
                    system("pause");
                    aux = -1;
                }
            }
        }
            break;
        case vent:{
            Venta* venta = new Venta();
            archivo = fopen("Ventas.dat","rb");
            while(fread(venta,sizeof (Venta),1,archivo)){

                if(venta->getCodigo() == cod){
                    mostrar->venta(venta);
                    system("pause");
                    aux = -1;
                }
            }
        }
            break;

        case empl:{
            Empleado* empleado = new Empleado();
            Imprimir* mostrar = new Imprimir();
            archivo = fopen("Empleados.dat","rb");
            while(fread(empleado,sizeof (Empleado),1,archivo)){
                if(empleado->getCodigo() == cod && empleado->getEstado() == true){

                    mostrar->empleado(empleado);
                    system("pause");
                    aux = -1;
                }
            }
        }
            break;

        case prom:{
            Promocion* promo = new Promocion();
            archivo = fopen("promos.dat","rb");
            while(fread(promo,sizeof (Promocion),1,archivo)){

                if(promo->getCodigo() == cod && promo->getEstado() == true){
                    mostrar->promocion(promo);
                    system("pause");
                    aux = -1;
                }
            }
        }
    }

    if(aux != -1){
        Imprimir* mostrar = new Imprimir();
        mostrar->noExisteCodigo();
    }
    fclose(archivo);
}

void Archivo::eliminar(int num){

    int cod;

    cout<<"ELIMINAR UN REGISTRO "<<endl;
    cout<<"INGRESE EL CODIGO A ELIMINAR: ";
    cin>>cod;

    FILE* archivo;
    switch(num){

        case arti:{
            Articulo* articulo = new Articulo();
            archivo = fopen("Articulos.dat","rb+");
            while(fread(articulo,sizeof (Articulo),1,archivo)){

                if(articulo->getCodigo() == cod && articulo->getEstado() == true){
                    articulo->setEstado(false);
                    fseek(archivo,-sizeof (Articulo),1);
                    fwrite(articulo,sizeof (Articulo),1,archivo);
                    fclose(archivo);
                    cout<<"EL REGISTRO HA SIDO ELIMINADO SATISFACTORIAMENTE! "<<endl;
                    system("pause");
                }
            }
        }
            break;

        case clie:{
            Cliente* cliente = new Cliente();
            archivo = fopen("Clientes.dat","rb+");
            while(fread(cliente,sizeof (Cliente),1,archivo)){

                if(cliente->getCodigo() == cod && cliente->getEstado() == true){
                    cliente->setEstado(false);
                    fseek(archivo,-sizeof (Cliente),1);
                    fwrite(cliente,sizeof (Cliente),1,archivo);
                    fclose(archivo);
                    cout<<"EL REGISTRO HA SIDO ELIMINADO SATISFACTORIAMENTE! "<<endl;
                    system("pause");
                }
            }
        }
            break;

        case empl:{
            Empleado* empleado = new Empleado();
            archivo = fopen("Empleados.dat","rb+");
            while(fread(empleado,sizeof (Empleado),1,archivo)){

                if(empleado->getCodigo() == cod && empleado->getEstado() == true){
                    empleado->setEstado(false);
                    fseek(archivo,-sizeof (Empleado),1);
                    fwrite(empleado,sizeof (Empleado),1,archivo);
                    fclose(archivo);
                    cout<<"EL REGISTRO HA SIDO ELIMINADO SATISFACTORIAMENTE! "<<endl;
                    system("pause");
                }
            }
        }
            break;

        case prom:{
            Promocion* promo = new Promocion();
            archivo = fopen("Promos.dat","rb+");
            while(fread(promo,sizeof (Promocion),1,archivo)){

                if(promo->getCodigo() == cod && promo->getEstado() == true){
                    promo->setEstado(false);
                    fseek(archivo,-sizeof (Promocion),1);
                    fwrite(promo,sizeof (Promocion),1,archivo);
                    fclose(archivo);
                    cout<<"EL REGISTRO HA SIDO ELIMINADO SATISFACTORIAMENTE! "<<endl;
                    system("pause");
                }
            }
        }
            break;
    }
}

int Archivo::contarRegistros(int num){
    FILE* archivo;
    int contador = 0;
    switch(num){

        case vent:{
            Venta* venta = new Venta();
            archivo = fopen("Ventas.dat","rb");
            while(fread(venta,sizeof (Venta),1,archivo)){
                if(venta->getEstado())
                    contador++;
            }
        }
            break;

        case arti:{
            Articulo* articulo = new Articulo();
            archivo = fopen("Articulos.dat","rb");
            while(fread(articulo,sizeof (Articulo),1,archivo)){
                if(articulo->getEstado())
                    contador++;
            }
        }
            break;

        case prom:{
            Promocion* promo = new Promocion();
            archivo = fopen("Promos.dat","rb");
            while(fread(promo,sizeof (Promocion),1,archivo)){
                if(promo->getEstado())
                    contador++;
            }
        }
            break;

    }
    return contador;
}

bool Archivo::comprobarRegistro(int num,int codigo){
    FILE* archivo;

    switch(num){
        case clie:{
            Cliente* cliente = new Cliente();
            archivo = fopen("Clientes.dat","rb");
            while(fread(cliente,sizeof (Cliente),1,archivo)){
                if(codigo == cliente->getCodigo()){
                    fclose(archivo);
                    return true;
                }
            }
        }
            break;

        case arti:{
            Articulo* articulo = new Articulo();
            archivo = fopen("Articulos.dat","rb");
            while(fread(articulo,sizeof (Articulo),1,archivo)){
                if(codigo == articulo->getCodigo()){
                    fclose(archivo);
                    return true;
                }
            }
        }
            break;

        case empl:{
            Empleado* empleado = new Empleado();
            archivo = fopen("Empleados.dat","rb");
            while(fread(empleado,sizeof (Empleado),1,archivo)){
                if(codigo == empleado->getCodigo()){
                    fclose(archivo);
                    return true;
                }
            }
        }
            break;

        case vent:{
            Venta* venta = new Venta();
            archivo = fopen("Ventas.dat","rb");
            while(fread(venta,sizeof (Venta),1,archivo)){
                if(codigo == venta->getCodigo()){
                    fclose(archivo);
                    return true;
                }
            }
        }
            break;
    }
    return false;
}

void* Archivo::buscarRegistro(int num,int codigo){
    FILE* archivo;

    switch(num){
        case clie:{
            Cliente* cliente = new Cliente();
            archivo = fopen("Clientes.dat","rb");
            while(fread(cliente,sizeof (Cliente),1,archivo)){
                if(codigo == cliente->getCodigo()){
                    fclose(archivo);
                    return cliente;
                }
            }
        }
            break;

        case arti:{
            Articulo* articulo = new Articulo();
            archivo = fopen("Articulos.dat","rb");
            while(fread(articulo,sizeof (Articulo),1,archivo)){
                if(codigo == articulo->getCodigo()){
                    fclose(archivo);
                    return articulo;
                }
            }
        }
            break;

        case empl:{
            Empleado* empleado = new Empleado();
            archivo = fopen("Empleados.dat","rb");
            while(fread(empleado,sizeof (Empleado),1,archivo)){
                if(codigo == empleado->getCodigo()){
                    fclose(archivo);
                    return empleado;
                }
            }
        }
            break;

        case vent:{
            Venta* venta = new Venta();
            archivo = fopen("Ventas.dat","rb");
            while(fread(venta,sizeof (Venta),1,archivo)){
                if(codigo == venta->getCodigo()){
                    fclose(archivo);
                    return (void*) venta;
                }
            }
        }
            break;
    }
}

void Archivo::alta(){

    int cod,num;

    cout<<"DAR DE ALTA UN REGISTRO "<<endl;
    cout<<"INGRESE EL TIPO DE REGISTRO(0-ARTICULO,1-CLIENTE,3-EMPLEADO): "<<endl;
    cin>>num;
    cout<<"INGRESE EL CODIGO A DAR DE ALTA: ";
    cin>>cod;

    FILE* archivo;
    switch(num){

        case arti:{
            Articulo* articulo = new Articulo();
            archivo = fopen("Articulos.dat","rb+");
            while(fread(articulo,sizeof (Articulo),1,archivo)){

                if(articulo->getCodigo() == cod && articulo->getEstado() == false){
                    articulo->setEstado(true);
                    fseek(archivo,-sizeof (Articulo),1);
                    fwrite(articulo,sizeof (Articulo),1,archivo);
                    fclose(archivo);
                    cout<<"EL REGISTRO HA SIDO DADO DE ALTA SATISFACTORIAMENTE! "<<endl;
                    system("pause");
                }
            }
        }
            break;

        case clie:{
            Cliente* cliente = new Cliente();
            archivo = fopen("Clientes.dat","rb+");
            while(fread(cliente,sizeof (Cliente),1,archivo)){

                if(cliente->getCodigo() == cod && cliente->getEstado() == false){
                    cliente->setEstado(true);
                    fseek(archivo,-sizeof (Cliente),1);
                    fwrite(cliente,sizeof (Cliente),1,archivo);
                    fclose(archivo);
                    cout<<"EL REGISTRO HA SIDO DADO DE ALTA SATISFACTORIAMENTE! "<<endl;
                    system("pause");
                }
            }
        }
            break;

        case empl:{
            Empleado* empleado = new Empleado();
            archivo = fopen("Empleados.dat","rb+");
            while(fread(empleado,sizeof (Empleado),1,archivo)){

                if(empleado->getCodigo() == cod && empleado->getEstado() == false){
                    empleado->setEstado(true);
                    fseek(archivo,-sizeof (Empleado),1);
                    fwrite(empleado,sizeof (Empleado),1,archivo);
                    fclose(archivo);
                    cout<<"EL REGISTRO HA SIDO DADO DE ALTA SATISFACTORIAMENTE! "<<endl;
                    system("pause");
                }
            }
        }
            break;
    }
}

void Archivo::BajaFisica(){

    int opc=0,num=0;
    char bkp[20],dat[20];
    Validacion* validar = new Validacion();

    system("cls");
    cout << "ELIMINAR REGISTROS DEL ARCHIVO " << endl;
    cout << "INGRESE EL NUMERO DE ARCHIVO QUE QUIERE ELIMINAR " << endl;
    cout << "1-ARTICULOS 2-CLIENTES 3-EMPLEADOS 4-USUARIOS 5-TODO: ";
    cin>>opc;
    if(validar->regresar(opc))
        return;

    if(opc==5){
        opc=1;
        num=5;
    }

    switch(opc){

        case 1:{
            Articulo* reg = new Articulo();
            Articulo* aux = new Articulo();
            strcpy(bkp,"BKP/Articulos.bkp");
            strcpy(dat,"Articulos.dat");

            FILE* backup = fopen(bkp,"wb");
            FILE* archivo = fopen(dat,"rb");

            while(fread(reg,sizeof (Articulo),1,archivo)){
                fwrite(reg,sizeof (Articulo),1,backup);
            }
            fclose(backup);
            fclose(archivo);

            backup = fopen(bkp,"rb");
            archivo = fopen(dat,"wb+");

            while(fread(aux,sizeof (Articulo),1,backup)){
                if(aux->getEstado() == true){
                    fwrite(aux,sizeof (Articulo),1,archivo);
                }
            }
            fclose(backup);
            fclose(archivo);
            if(num!=5){
                break;
            }
        }
        case 2:{
            Cliente* reg = new Cliente();
            Cliente* aux = new Cliente();
            strcpy(bkp,"BKP/Clientes.bkp");
            strcpy(dat,"Clientes.dat");

            FILE* backup = fopen(bkp,"wb");
            FILE* archivo = fopen(dat,"rb");

            while(fread(reg,sizeof (Cliente),1,archivo)){
                fwrite(reg,sizeof (Cliente),1,backup);
            }
            fclose(backup);
            fclose(archivo);

            backup = fopen(bkp,"rb");
            archivo = fopen(dat,"wb+");

            while(fread(aux,sizeof (Cliente),1,backup)){
                if(aux->getEstado() == true){
                    fwrite(aux,sizeof (Cliente),1,archivo);
                }
            }
            fclose(backup);
            fclose(archivo);
            if(num!=5){
                break;
            }
        }
        case 3:{
            Empleado* reg = new Empleado();
            Empleado* aux = new Empleado();
            strcpy(bkp,"BKP/Empleados.bkp");
            strcpy(dat,"Empleados.dat");

            FILE* backup = fopen(bkp,"wb");
            FILE* archivo = fopen(dat,"rb");

            while(fread(reg,sizeof (Empleado),1,archivo)){
                fwrite(reg,sizeof (Empleado),1,backup);
            }
            fclose(backup);
            fclose(archivo);

            backup = fopen(bkp,"rb");
            archivo = fopen(dat,"wb+");

            while(fread(aux,sizeof (Empleado),1,backup)){
                if(aux->getEstado() == true){
                    fwrite(aux,sizeof (Empleado),1,archivo);
                }
            }
            fclose(backup);
            fclose(archivo);
            if(num!=5){
                break;
            }
        }
        case 4:{
            Usuario* reg = new Usuario();
            Usuario* aux = new Usuario();
            strcpy(bkp,"BKP/User.bkp");
            strcpy(dat,"Usuarios.dat");

            FILE* backup = fopen(bkp,"wb");
            FILE* archivo = fopen(dat,"rb");

            while(fread(reg,sizeof (Usuario),1,archivo)){
                fwrite(reg,sizeof (Usuario),1,backup);
            }
            fclose(backup);
            fclose(archivo);

            backup = fopen(bkp,"rb");
            archivo = fopen(dat,"wb+");

            while(fread(aux,sizeof (Usuario),1,backup)){
                if(aux->getEstado() == true){
                    fwrite(aux,sizeof (Usuario),1,archivo);
                }
            }
            fclose(backup);
            fclose(archivo);
            break;
        }
    }

    cout<<endl<<"La actualizacion ha sido exitosa! "<<endl<<endl;
    system("pause");
////////////////////////////////////////////////////////////////////////////////////
///ESTO SIRVE SOLO PARA FINES PRACTICOS, LISTA EL ARCHIVO DE USUARIOS. HAY QUE BORRARLO
}

void Archivo::backup(){

    int cod;
    system("cls");
    cout << "\n COPIA DE SEGURIDAD ";
    cout << "\n ------------------"<<endl;
    cout << "\n Esta seguro que desea realizar copias de seguridad de todos los archivos?" << endl;
    cout << "\n 1 - SI / OTRO - NO: ";
    cin >> cod;
    if(cod != 1){
        return;
    }
///////////////////////////////////////////////////////////////////////////////////////////////
    ///CLIENTE
    Cliente* client = new Cliente();

    FILE* FileClientes = fopen("BKP/Clientes.bkp","wb");
    FILE* FileCli = fopen("Clientes.dat","rb");

    while(fread(client,sizeof(Cliente),1,FileCli)){
        fwrite(client,sizeof(Cliente),1,FileClientes);
    }
    fclose(FileCli);
    fclose(FileClientes);
    ///ARTICULOS
    Articulo* Arti = new Articulo();

    FILE* FileArticulo = fopen("BKP/Articulos.bkp","wb");
    FILE* FileArti = fopen("Articulos.dat","rb");

    while(fread(Arti,sizeof(Articulo),1,FileArti)){
        fwrite(Arti,sizeof(Articulo),1,FileArticulo);
    }
    fclose(FileArti);
    fclose(FileArticulo);
    ///EMPLEADOS
    Empleado* emp = new Empleado();

    FILE* Filempleado = fopen("BKP/Empleados.bkp","wb");
    FILE* Filemp = fopen("Empleados.dat","rb");

    while(fread(emp,sizeof(Empleado),1,Filemp)){
        fwrite(emp,sizeof(Empleado),1,Filempleado);
    }
    fclose(Filemp);
    fclose(Filempleado);
    ///VENTAS
    Venta* Vent = new Venta();

    FILE* FileVentas = fopen("BKP/Ventas.bkp","wb");
    FILE* FileVent = fopen("Ventas.dat","rb");

    while(fread(Vent,sizeof(Venta),1,FileVent)){
        fwrite(Vent,sizeof(Venta),1,FileVentas);
    }
    fclose(FileVent);
    fclose(FileVentas);
    ///USUARIOS
    Usuario* Usu = new Usuario();

    FILE* FileUsuario = fopen("BKP/Usuarios.bkp","wb");
    FILE* FileUsu = fopen("Usuarios.dat","rb");

    while(fread(Usu,sizeof(Usuario),1,FileUsu)){
        fwrite(Usu,sizeof(Usuario),1,FileUsuario);
    }
    fclose(FileUsu);
    fclose(FileUsuario);

    cout << endl << "\n El respaldo ha sido exitoso! " << endl << endl;
    system("pause");
}

void Archivo::restaurarCopia(){

    int cod;
    system("cls");
    cout << "\n COPIA DE SEGURIDAD ";
    cout << "\n ------------------" << endl;
    cout << "\n Esta seguro que desea actualizar los archivos, con las copias de seguridad?" << endl;
    cout << "\n 1 - SI / OTRO - NO: ";
    cin >> cod;
    if(cod != 1){
        return;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////
    ///CLIENTE
    Cliente* Cli = new Cliente();

    FILE* FileCliente = fopen("BKP/Clientes.bkp","rb");
    FILE* FileCli = fopen("Clientes.dat","wb");

    while(fread(Cli,sizeof (Cliente),1,FileCliente)){
        fwrite(Cli,sizeof (Cliente),1,FileCli);
    }
    fclose(FileCli);
    fclose(FileCliente);
     ///ARTICULOS
    Articulo* Arti = new Articulo();

    FILE* FileArticulo = fopen("BKP/Articulos.bkp","rb");
    FILE* FileArti = fopen("Articulos.dat","wb");

    while(fread(Arti,sizeof (Articulo),1,FileArticulo)){
        fwrite(Arti,sizeof (Articulo),1,FileArti);
    }
    fclose(FileArti);
    fclose(FileArticulo);
    ///EMPLEADOS
    Empleado* Emp = new Empleado();

    FILE* FileEmpleado = fopen("BKP/Empleados.bkp","rb");
    FILE* FileEmp = fopen("Empleados.dat","wb");

    while(fread(Emp,sizeof (Empleado),1,FileEmpleado)){
        fwrite(Emp,sizeof (Empleado),1,FileEmp);
    }
    fclose(FileEmp);
    fclose(FileEmpleado);
    ///VENTAS
    Venta* Ven = new Venta();

    FILE* FileVenta = fopen("BKP/Ventas.bkp","rb");
    FILE* FileVen = fopen("Ventas.dat","wb");

    while(fread(Ven,sizeof (Venta),1,FileVenta)){
        fwrite(Ven,sizeof (Venta),1,FileVen);
    }
    fclose(FileVen);
    fclose(FileVenta);
    ///USUARIOS
    Usuario* Usu = new Usuario();

    FILE* FileUsuario = fopen("BKP/Usuarios.bkp","rb");
    FILE* FileUsu = fopen("Usuarios.dat","wb");

    while(fread(Usu,sizeof (Usuario),1,FileUsuario)){
        fwrite(Ven,sizeof (Usuario),1,FileUsu);
    }
    fclose(FileUsu);
    fclose(FileUsuario);
}

void Archivo::listadosVentas(int num){

    int cod;
    Validacion* validar = new Validacion();

    system("cls");
    cout<<"INGRESE EL CODIGO A LISTAR"<<endl;
    cin>>cod;
    if(validar->regresar(cod))
        return;

    Venta* venta = new Venta();
    Imprimir* mostrar = new Imprimir();

    FILE* archivo = fopen ("Ventas.dat","rb");

    if (num == clie){
        while(fread(venta,sizeof (Venta),1,archivo)){

            if(venta->getCodCli() == cod){
                mostrar->venta(venta);
            }
        }
    }

    if (num == arti){
        while(fread(venta,sizeof (Venta),1,archivo)){

            if(venta->getCodigo() == cod){

                ArtXVenta* artxven = new ArtXVenta();
                FILE* p = fopen("ArtXVentas.dat","rb");

                while(fread(artxven,sizeof (ArtXVenta),1,p)){

                    if(artxven->getCodVent() == cod){
                        mostrar->artXventa(artxven);
                    }
                }
                fclose(p);
                system("pause");
            }
        }
    }

    fclose(archivo);
    system("pause");
}

void Archivo::editar(int num,void *objeto,int pos){
    FILE *p;

    switch(num){
        case arti:{
            Articulo *art = (Articulo*)objeto;
            p=fopen("Articulos.dat","rb+");
            fseek(p,pos * sizeof (Articulo),1);
            fwrite(art,sizeof (Articulo),1,p);
            }
            break;

    }

    fclose(p);
    return;
}

int Archivo::buscarPosicion(int num,int codigo){
    FILE *p;
    int cont=0;

    switch(num){
        case arti:{
            Articulo *art = new Articulo();
            p=fopen("Articulos.dat","rb");
            while(fread(art,sizeof (Articulo),1,p)){
                if(codigo==art->getCodigo()){
                    fclose(p);
                    return cont;
                }
                cont++;
            }

        }

    }
}

Promocion Archivo::buscarMayor(Articulo* art,Fecha venta){

    float mayor=200;

    FILE* p = fopen("Promos.dat","rb");
    Promocion promo;
    Promocion promayor;

    while(fread(&promo,sizeof promo,1,p)){

        if(promo.getEstado() == true){

            if(venta.validaRango(promo.getFechaInicio(),promo.getFechaFin())){

                if(promo.getCategoria() == art->getSeccion() or promo.getCodArt() == art->getCodigo()){

                    if(promo.getDesc() < mayor){
                        mayor=promo.getDesc();
                        promayor = promo;
                    }
                }
            }
        }
    }
    if(mayor==200){
        promayor.setCodigo(0);
    }
    fclose(p);
    system("pause");
    return promayor;
}

#endif // ARCHIVOS_H_INCLUDED
