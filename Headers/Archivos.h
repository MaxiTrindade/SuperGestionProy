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
/*
        case prov:
        {
            Proveedor* proveedor = (Proveedor*)objeto;
            archivo = fopen("Proveedores.dat","ab");
            fwrite(proveedor,sizeof(Proveedor),1,archivo);
        }
            break;
*/
        case empl:
        {
            Empleado* empleado = (Empleado*)objeto;
            archivo = fopen("Empleados.dat","ab");
            fwrite(empleado,sizeof (Empleado),1,archivo);
        }
            break;
/*
        case comp:
        {
            Compra* compra = (Compra*)objeto;
            archivo = fopen("Compras.dat","ab");
            fwrite(compra,sizeof (Compra),1,archivo);
        }
            break;
*/
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
/*
        case prom:
        {
            Promo* promo = (Promo*)objeto;
            archivo = fopen("Promos.dat","ab");
            fwrite(promo,sizeof (Promo),1,archivo);
        }
            break;
            */

        case artXVen:
        {
            ArtXVenta* ArtxVen = (ArtXVenta*)objeto;
            archivo = fopen("ArtXVentas.dat","ab");
            fwrite(ArtxVen,sizeof (ArtXVenta),1,archivo);
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
    }
    fclose(archivo);
}

void Archivo::listarXCodigo(int num){

    int cod,aux=0;

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

                    cout<<"CODIGO: "<<articulo->getCodigo()<<endl;
                    cout<<"NOMBRE: "<<articulo->getNombre()<<endl;
                    cout<<"SECCION: "<<articulo->getSeccion()<<endl;
                    cout<<"PRECIO: "<<articulo->getPrecio()<<endl;
                    cout<<"STOCK: "<<articulo->getStock()<<endl<<endl;
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

                    cout<<"CODIGO: "<<cliente->getCodigo()<<endl;
                    cout<<"NOMBRE: "<<cliente->getNombre()<<endl;
                    cout<<"APELLIDO: "<<cliente->getApellido()<<endl;
                    cout<<"DIRECCION: "<<cliente->getDire()<<endl;
                    cout<<"LOCALIDAD: "<<cliente->getLocalidad()<<endl<<endl;
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
                    cout<<"CODIGO: "<<venta->getCodigo()<<endl;
                    cout<<"CODIGO CLIENTE: "<<venta->getCodCli()<<endl;
                    cout<<"CODIGO EMPLEADO: "<<venta->getCodEmp()<<endl;
                    cout<<"FORMA DE PAGO: "<<venta->getFormaPago()<<endl;
                    cout<<"TOTAL: "<<venta->getTotal()<<endl<<endl;
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

                    cout<<"CODIGO: "<<empleado->getCodigo()<<endl;
                    cout<<"NOMBRE: "<<empleado->getNombre()<<endl;
                    cout<<"APELLIDO: "<<empleado->getApellido()<<endl;
                    cout<<"FECHA DE NACIMIENTO: "; mostrar->fecha(empleado->getNacimiento());
                    cout<<"FECHA DE INGRESO: "; mostrar->fecha(empleado->getIngreso());
                    cout<<"AREA: "<<empleado->getArea()<<endl;
                    cout<<"SUELDO: "<<empleado->getSueldo()<<endl<<endl;
                    system("pause");
                    aux = -1;
                }
            }
        }
            break;

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

void Archivo::editarStock(void* objeto,int num,int cod){

    FILE* archivo;

    switch(num){

        case arti:{
            Articulo* articulo = new Articulo();
            articulo = (Articulo*) objeto;
            Articulo* Arctic = new Articulo();
            archivo = fopen("Articulos.dat","rb+");
            while(fread(Arctic,sizeof (Articulo),1,archivo)){

                if(Arctic->getCodigo() == cod){
                    fseek(archivo,-sizeof (Articulo),1);
                    Arctic->setStock(articulo->getStock());
                    fwrite(Arctic,sizeof (Articulo),1,archivo);
                    fclose(archivo);
                    return;
                }
            }
        }
            break;
    }
    fclose(archivo);
}

void Archivo::editar(int num){

    int cod;

    FILE* archivo;
    cout<<"EDITAR POR CODIGO"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"INGRESE EL CODIGO A EDITAR: ";
    cin>>cod;
    cout<<"---------------------------"<<endl;

    switch(num){

        case arti:{

            Articulo* Arctic = new Articulo();
            Articulo* Art = new Articulo();
            archivo = fopen("Articulos.dat","rb+");
            while(fread(Arctic,sizeof (Articulo),1,archivo)){

                if(Arctic->getCodigo() == cod){
                    fseek(archivo,-sizeof (Articulo),1);
                    if(Art->cargar()){
                    cout<<"---------------------------"<<endl;
                    fwrite(Art,sizeof (Articulo),1,archivo);
                    fclose(archivo);
                    return;
                    }
                }
            }
        }
            break;
        case clie:{

            Cliente* Client = new Cliente();
            Cliente* Cli = new Cliente();
            archivo = fopen("Clientes.dat","rb+");
            while(fread(Client,sizeof (Cliente),1,archivo)){

                if(Client->getCodigo() == cod){
                    fseek(archivo,-sizeof (Cliente),1);
                    if(Cli->cargar()){
                    cout<<"---------------------------"<<endl;
                    fwrite(Cli,sizeof (Cliente),1,archivo);
                    fclose(archivo);
                    return;
                    }
                }
            }
        }
            break;
    }
    fclose(archivo);
}

void Archivo::alta(){

    int cod,num;

    cout<<"DAR DE ALTA UN REGISTRO "<<endl;
    cout<<"INGRESE EL TIPO DE REGISTRO(0-ARTICULO,1-CLIENTE,2-EMPLEADO): "<<endl;
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

    Usuario* Usu = new Usuario();
    Usuario* User = new Usuario();

    FILE* FileUser = fopen("User.bkp","wb");
    FILE* FileUsuario = fopen("Usuarios.dat","rb");

    while(fread(Usu,sizeof (Usuario),1,FileUsuario)){
        fwrite(Usu,sizeof (Usuario),1,FileUser);
    }
    fclose(FileUser);
    fclose(FileUsuario);

    FileUser = fopen("User.bkp","rb");
    FileUsuario = fopen("Usuarios.dat","wb+");

    while(fread(User,sizeof (Usuario),1,FileUser)){
        if(User->getEstado() == true){
            fwrite(User,sizeof (Usuario),1,FileUsuario);
        }
    }
    fclose(FileUser);
    fclose(FileUsuario);

    cout << endl << "La actualizacion ha sido exitosa! " << endl << endl;
    system("pause");
////////////////////////////////////////////////////////////////////////////////////
///ESTO SIRVE SOLO PARA FINES PRACTICOS, LISTA EL ARCHIVO DE USUARIOS. HAY QUE BORRARLO
    FileUsuario = fopen("Usuarios.dat","rb");
    while(fread(Usu,sizeof (Usuario),1,FileUsuario)){
        cout << Usu->getNombre();
        cout << Usu->getEstado();
        system("pause");
    }
    fclose(FileUsuario);
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
    ///COLECTIVOS
    Cliente* Cli = new Cliente();

    FILE* FileCliente = fopen("BKP/Clientes.bkp","rb");
    FILE* FileCli = fopen("Clientes.dat","wb");

    while(fread(Cli,sizeof (Cliente),1,FileCliente)){
        fwrite(Cli,sizeof (Cliente),1,FileCli);
    }
    fclose(FileCli);
    fclose(FileCliente);
}


#endif // ARCHIVOS_H_INCLUDED
