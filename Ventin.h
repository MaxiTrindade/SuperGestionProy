#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

void Venta::cargar(){
    Imprimir *mostrar = new Imprimir();
    Venta *venta = new Venta();
    Validacion *validar = new Validacion();
    ArtXVenta *subVenta = new ArtXVenta();
    Articulo art;
    Archivo *archivo = new Archivo();
    bool flag=true;

    int formaPago,codigo,codEmp,codCli,codArt,cantidad;
    float total=0;

    system("CLS");
    cout<<"NUEVA VENTA"<<endl<<endl;
    codigo=archivo->contarVentas()+1;
    cout<<"CODIGO DE VENTA: "<<codigo<<endl;
    cout<<"CODIGO CLIENTE: ";
    cin>>codCli;
    cout<<"CODIGO EMPLEADO: ";
    cin>>codEmp;
    while(flag){

           while(flag){

                cout<<"ARTICULO: ";
                cin>>codArt;
                if(validar->regresar(codArt)) return;
                if(codArt==0)
                if(archivo->comprobarArticulo(codArt)==false){
                    cout<<"**********************"<<endl;
                    cout<<"ESTE CODIGO NO EXISTE"<<endl;
                    cout<<"**********************"<<endl;
                    system("PAUSE");
                }
                else
                    flag = false;

           }

           flag = true;

        while(flag){
            cout<<"CANTIDAD: ";
            cin>>cantidad;
            if(validar->regresar(cantidad)) return;
            if()
        }
        art=archivo->buscarArticulo(codArt);

        subVenta->setCodArt(codArt);
        subVenta->setCantidad(cantidad);
        subVenta->setCodVent(codigo);
        subVenta->setSubTot(art.getPrecio()*cantidad);
        archivo->guardar(subVenta,-1);
        total+=art.getPrecio()*cantidad;
        cout<<endl<<"SUBTOTAL: "<<total<<endl;
    }
    venta->setCodigo(codigo);
    venta->setCodCli(codCli);
    venta->setCodEmp(codEmp);
    venta->setFormaPago(formaPago);
    venta->setTotal(total);
    cout<<endl<<"TOTAL: "<<total<<endl;
    system("pause");
}
#endif // VENTAS_H_INCLUDED

