#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED


int Venta::cargar(){

    Imprimir *mostrar = new Imprimir();
    Venta *venta = new Venta();
    Validacion *validar = new Validacion();
    ArtXVenta *subVenta = new ArtXVenta();
    Articulo * art = new Articulo();
    Archivo *archivo = new Archivo();

    bool flag=true,flag2=true,flag3=true;

    int formaPago,codigo,codEmp,codCli,codArt,cantidad,stock=0,ingreso;
    float total=0;

    system("CLS");
    cout<<"NUEVA VENTA"<<endl;
    cout<<"----------------------"<<endl;
    codigo=archivo->contarRegistros(vent)+1;
    cout<<"CODIGO DE VENTA: "<<codigo<<endl<<endl;

    while(flag){

        cout<<"CODIGO DE CLIENTE: ";
        cin>>codCli;
        if(validar->regresar(codCli)){return incorrecto;}
          if(validar->positivo(codCli)){
                if(!archivo->comprobarRegistro(clie,codCli)){
                cout<<"El archivo no existe!!!"<<endl;
                system("pause");
                }
                else{flag=false;}
            }
    }
    flag=true;

    while(flag){

        cout<<"CODIGO DE EMPLEADO: ";
        cin>>codEmp;
        if(validar->regresar(codEmp)){return incorrecto;}
        if(validar->positivo(codEmp)){

            if(!archivo->comprobarRegistro(empl,codEmp)){
            cout<<"El archivo no existe!!!"<<endl;
            system("pause");
            }
            else{flag=false;}
        }
    }

    cout<<"-----------------------"<<endl;

    flag=true;

    while(flag){

        flag2=true;
        flag3=true;

        while(flag2){
            cout<<"ARTICULO: ";
            cin>>codArt;
            if(codArt==0){
                flag2=false;
                flag3=false;
            }
            if(validar->regresar(codArt)){return bajaLogica;}
            if(validar->positivo(codArt)){
                if(!archivo->comprobarRegistro(arti,codArt)){
                cout<<"El archivo no existe!!!"<<endl;
                system("pause");
                }
                else{flag2=false;}
            }
        }

        flag2=true;

        if(codArt==0){
            flag2=false;
            flag=false;
        }

        while(flag2){
            cout<<"CANTIDAD: ";
            cin>>cantidad;
            if(validar->regresar(cantidad)){return bajaLogica;}
            if(validar->positivo(cantidad))
            art=(Articulo*) archivo->buscarRegistro(arti,codArt);
            else{
                mostrar->textoNoPositivo();
            }
            if((art->getStock()-cantidad)<0){
                cout<<"No hay stock suficiente para la cantidad requerida. "<<endl;
                cout<<"Quedan disponibles: " << art->getStock() << endl;
                cout<<"Desea ingresar nuevamente? Presione 1 de ser asi, otro numero para salir. ";
                cin>>ingreso;
                if(ingreso != 1){
                    flag2=false;
                    flag3=false;
                }
            }
            else{
                flag2=false;
                art->setStock(art->getStock()-cantidad);
                archivo->editarStock(art,arti,codArt);
            }
        }

        if(flag3){

            subVenta->setCodArt(codArt);
            subVenta->setCodVent(codigo);
            subVenta->setCantidad(cantidad);
            total+=art->getPrecio()*cantidad; /// TIRA CUALQUIERA
            cout<<"PRECIO: "<<art->getPrecio()<<endl;
            cout<<"SUBTOTAL: "<<total<<endl<<endl;
            archivo->guardar(subVenta,artXVen);
        }
    }

    flag = true;

    cout<<"------------------------"<<endl;
    cout<<endl<<"TOTAL: "<<total<<endl;

    while(flag){
        cout<<"FORMA DE PAGO: ";
        cin>>formaPago;
        if(validar->regresar(formaPago)){return incorrecto;}
        if(validar->positivo(formaPago)){flag = false;}
    }

    this->setCodigo(codigo);
    this->setCodCli(codCli);
    this->setCodEmp(codEmp);
    this->setFormaPago(formaPago);
    this->setTotal(total);
    this->setEstado(estado);
    system("pause");
    return grabo;
}

#endif // VENTAS_H_INCLUDED

