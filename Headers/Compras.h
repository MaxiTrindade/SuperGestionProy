#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED

int Compra::getCodigo(){
    return codigo;
}

int Compra::getCodPro(){
    return codPro;
}

float Compra::getTotal(){
    return total;
}

Fecha Compra::getFechaCompra(){
    return fechaCompra;
}

bool Compra::getEstado(){
    return estado;
}

void Compra::setCodigo(int codigo){
    this->codigo=codigo;
}

void Compra::setCodPro(int codProv){
    this->codPro=codProv;
}

void Compra::setTotal(float total){
    this->total=total;
}

void Compra::setEstado(bool estado){
    this->estado=estado;
}

void Compra::setFechaCompra(int d,int m,int a){
    this->fechaCompra.setDia(d);
    this->fechaCompra.setMes(m);
    this->fechaCompra.setAnio(a);
}

int Compra::cargar(){

    Validacion *validar = new Validacion();
    Articulo *articulo = new Articulo();
    Proveedor *proveedor = new Proveedor();
    Archivo *archivo = new Archivo();
    ArtXCompra *artXcomp = new ArtXCompra();


    float total=0,subTot,precio;
    int codigo,codProv,codArt,cantidad,posArt,*vecCant,*vecCod,tamVec,i;
    Fecha fechaCompra;
    bool flag=true,flag2=true,flag3=true,flag4=false,estado;
    /*  FLAG= PERMITE ACCESO AL WHILE "GLOBAL" PARA LA CARGA DE ARTICULOS
        FLAG2=PERMITE ACCESO AL INGRESO DEL CODIGO DE ARTICULO Y LA CANTIDAD COMPRADA
        FLAG3=EN CASO DE QUE EL ARTICULO INGRESADO SEA DISTINTO DE 0 Y 1 INGRESA AL ARCHIVO ARTXCOMP
    */
    //CREO UN VECTOR DONDE SE VAN A GUARDAR LAS CANTIDADES COMPRADAS
    //Y OTRO DONDE SE VAN A GUARDAR LOS CODIGOS DE LOS ARCHIVOS, NECESARIO PARA PODER
    //BUSCAR LOS REGISTROS Y MODIFICARLOS
    tamVec=archivo->contarRegistros(arti);
    vecCant=(int*)malloc(sizeof(int)*tamVec);
    vecCod=(int*)malloc(sizeof(int)*tamVec);

    if(vecCant==NULL || vecCod==NULL) exit (1);
    //PONGO EN 0 EL VECTOR
    for(i=0;i<tamVec;i++) vecCant[i]=0;
    for(i=0;i<tamVec;i++) vecCod[i]=0;

    system("CLS");
    cout<<"NUEVA COMPRA"<<endl;
    cout<<"--------------------------------"<<endl;
    codigo=archivo->contarRegistros(comp)+1;
    cout<<"CODIGO DE COMPRA: "<<codigo<<endl;

    while(flag){
        cout<<"CODIGO DE PROVEEDOR: ";
        cin>>codProv;
        if(validar->regresar(codProv)){
                free(vecCod);
                free(vecCant);
                return -1;
        }
        if(archivo->comprobarRegistro(prov,codProv)) flag=false;
        else {
            cout<<"ESTE PROVEEDOR NO EXISTE"<<endl<<endl;
        }
    }

    proveedor=(Proveedor*)archivo->buscarRegistro(prov,codProv);//BUSCO EL PROVEEDOR PARA USAR EL NUMERO DE CATEGORIA
                                                    //QUE LE CORRESPONDE.
    cout<<"FECHA DE LA COMPRA"<<endl;
    if(!fechaCompra.ingresoFecha()){
            free(vecCod);
            free(vecCant);
            return -1;
    }

    flag=true;
    while(flag){
        flag2=true;
        flag3=true;
        while(flag2){
            cout<<"CODIGO ARTICULO: ";
            cin>>codArt;
            if(validar->regresar(codArt) || codArt==0) {
                estado=false; //LO SETEA COMO FALSE PORQUE AL SALIR EN MEDIO DE LA EJECUCION SE LO
                flag=false;                            //CONSIDERA UN ERROR
                flag2=false;
                flag3=false;
                if(codArt==0) flag4=true; cantidad=0;
            }

            else{
                if(!archivo->comprobarRegistro(arti,codArt))
                    cout<<"CODIGO INEXISTENTE"<<endl<<endl;
                else{
                    articulo=(Articulo*)archivo->buscarRegistro(arti,codArt);
                    if(articulo->getSeccion()==proveedor->getCategoria())
                        flag2=false;
                    else
                        cout<<"ESTE ARTICULO NO ES DISTRIBUIDO POR EL PROVEEDOR INDICADO"<<endl<<endl;
                }
            }
        }


        if(codArt!=0 && codArt!=-1) flag2=true;
        while(flag2){
            cout<<"CANTIDAD: ";
            cin>>cantidad;
            if(validar->regresar(cantidad)) {
                flag=false;
                flag2=false;
                flag3=false;
                flag4=false;
                estado=false;
            }
            if(validar->positivo(cantidad)){
                //GUARDAMOS LA CANTIDAD EN EL VECTOR. LA POSISION DENTRO DEL ARCHIVO
                //Y DENTRO DEL VECTOR SON LAS MISMAS
                posArt=archivo->buscarPosicion(arti,codArt);
                vecCant[posArt]+=cantidad;
                vecCod[posArt]=codArt;

                cout<<"PRECIO: ";
                cin>>precio;
                subTot=precio*cantidad;
                cout<<"SUBTOTAL: "<<subTot<<endl;
                total+=subTot;
                flag2=false;
            }
        }

        if(flag3){
            artXcomp->setCodComp(codigo);
            artXcomp->setCodArt(codArt);
            artXcomp->setCantidad(cantidad);
            artXcomp->setSubTot(subTot);
            archivo->guardar(artXcomp,artXCom);
            cout<<"------------------------"<<endl<<endl;
        }
    }
    if(flag4){ //ESTE FLAG DETERMINA SI LAS CANTIDADES SE GUARDAN O NO
        for(i=0;i<tamVec;i++){
            if(vecCod[i]!=0){
                articulo=(Articulo*)archivo->buscarRegistro(arti,vecCod[i]);
                articulo->setStock(articulo->getStock()+vecCant[i]);
                archivo->editar(arti,articulo,i);
            }
        }
        estado=true;
    }

    setCodigo(codigo);
    setCodPro(codProv);
    setTotal(total);
    setFechaCompra(fechaCompra.getDia(),fechaCompra.getMes(),fechaCompra.getAnio());
    setEstado(estado);
    free(vecCod);
    free(vecCant);
    return 1;

}

#endif // COMPRAS_H_INCLUDED
