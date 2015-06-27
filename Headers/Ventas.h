#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED


bool Venta::cargar(){

    Validacion *validar = new Validacion();
    ArtXVenta *subVenta = new ArtXVenta();
    Articulo * art = new Articulo();
    Archivo *archivo = new Archivo();
    Imprimir *mostrar = new Imprimir();
    COORD cursor;

    bool flag=true,flag2=true,flag3=true,flag4,estado;

    int formaPago,codigo,codEmp,codCli,codArt,cantidad,*vecCant,*vecCod,i,tamVec,pos;
    float total=0,sub;

    tamVec=archivo->contarRegistros(arti);
    vecCant=(int*)malloc(sizeof (int) * tamVec);
    vecCod=(int*)malloc(sizeof (int) * tamVec);
    for(i=0;i<tamVec;i++){
        vecCant[i]=0;
        vecCod[i]=0;
    }

    system("CLS");
    cout<<"NUEVA VENTA"<<endl;
    cout<<"----------------------"<<endl;
    codigo=archivo->contarRegistros(vent)+1;
    cout<<"CODIGO DE VENTA: "<<codigo<<endl<<endl;

    while(flag){
        cout<<"CODIGO DE EMPLEADO: ";
        cin>>codEmp;
        if(validar->regresar(codEmp)) return false;
        if(archivo->comprobarRegistro(empl,codEmp)) flag=false;
        else{
            cout<<endl<<"NO EXISTE ESTE EMPLEADO"<<endl<<endl;
            system("pause");
            pedirCoord(cursor);
            mostrar->limpiarLinea(cursor.X,cursor.Y,5);
        }
    }

    flag=true;
    while(flag){
        cout<<"CODIGO DE CLIENTE: ";
        cin>>codCli;
        if(validar->regresar(codCli)) return false;
        if(archivo->comprobarRegistro(clie,codCli)) flag=false;
        else {
            cout<<endl<<"NO EXISTE ESTE CLIENTE"<<endl<<endl;;
            system("pause");
            pedirCoord(cursor);
            mostrar->limpiarLinea(cursor.X,cursor.Y,5);
        }
    }

    cout<<"FECHA DE LA VENTA"<<endl;
    if(!fechaVenta.ingresoFecha()){
            free(vecCod);
            free(vecCant);
            return false;
    }

    flag=true;
    while(flag){
        flag2=true;
        flag3=true;

        while(flag2){
            cout<<"CODIGO DE ARTICULO: ";
            cin>>codArt;
            if(validar->regresar(codArt) || codArt==0){
                flag=false;
                flag2=false;
                flag3=false;
                flag4=false;
                estado=false;
                if(codArt==0) flag4=true;
            }
            else{
                if(archivo->comprobarRegistro(arti,codArt)) flag2=false;
                else {
                    cout<<endl<<"NO EXISTE ESTE ARTICULO"<<endl<<endl;;
                    system("pause");
                    pedirCoord(cursor);
                    mostrar->limpiarLinea(cursor.X,cursor.Y,5);
                }
            }
        }

        if(codArt!=0 && codArt!=-1) flag2=true;
        while(flag2){
            cout<<"CANTIDAD: ";
            cin>>cantidad;
            if(validar->regresar(cantidad)){
                flag=false;
                flag2=false;
                flag3=false;
                flag4=false;
                estado=false;
            }
            else {
                if(cantidad<=0){
                    cout<<endl<<"LA CANTIDAD DEBE SER POSITIVA"<<endl<<endl;
                    system("pause");
                    pedirCoord(cursor);
                    mostrar->limpiarLinea(cursor.X,cursor.Y,5);
                }
                else{
                    art=(Articulo*)archivo->buscarRegistro(arti,codArt);
                    pos=archivo->buscarPosicion(arti,codArt);
                    if(art->getStock()-vecCant[pos]-cantidad<0){
                        cout<<endl<<"NO HAY STOCK PARA LA CANTIDAD INDICADA"<<endl;
                        cout<<"QUEDAN "<<art->getStock()<<endl;
                        system("pause");
                        pedirCoord(cursor);
                        mostrar->limpiarLinea(cursor.X,cursor.Y,6);
                        flag2=false;
                        flag3=false;
                        flag4=false;
                    }
                    else{
                        sub=cantidad*art->getPrecio();
                        total+=sub;
                        cout<<"Total: $"<<total<<endl;
                        vecCant[pos]+=cantidad;
                        vecCod[pos]=codArt;
                        flag2=false;
                    }
                }
            }
        }

        while(flag3){
            subVenta->setCodVent(codigo);
            subVenta->setCodArt(codArt);
            subVenta->setCantidad(cantidad);
            subVenta->setSubTot(sub);
            archivo->guardar(subVenta,artXVen);
            cout<<"-----------------------"<<endl;
            flag3=false;
        }

    }

        while(flag4){
            for(i=0;i<tamVec;i++){
                if(vecCod[i]!=0){
                    art=(Articulo*)archivo->buscarRegistro(arti,vecCod[i]);
                    art->setStock(art->getStock()-vecCant[i]);
                    archivo->editar(arti,art,i);
                }
            }
            estado=true;
            cout<<"FORMA DE PAGO: ";
            cin>>formaPago;
            flag4=false;
        }

    if(!estado) formaPago=0;
    this->setCodigo(codigo);
    this->setCodEmp(codEmp);
    this->setCodCli(codCli);
    this->setFormaPago(formaPago);
    this->setTotal(total);
    free(vecCod);
    free(vecCant);
    return true;




}

#endif // VENTAS_H_INCLUDED

