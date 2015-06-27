#ifndef PROMOCIONES_H_INCLUDED
#define PROMOCIONES_H_INCLUDED

bool Promocion::cargarNXM(){

    int N, M,cat,codigo;
    float porc;
    Fecha inicio,fin;
    Validacion* validar = new Validacion();
    Imprimir* Mostrar = new Imprimir();
    Archivo* archivo = new Archivo();

    cout<<"NUEVA PROMOCION"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"CODIGO DE PROMOCION: ";
    cin>>codigo;
    if(validar->regresar(codigo))
        return false;
    if(!validar->positivo(codigo)){
        Mostrar->textoNoPositivo();
        return false;
    }

    cout<<"INGRESE LA CANTIDAD DE ARTICULOS N: ";
    cin>>N;
    if(validar->regresar(N))
        return false;
    if(!validar->positivo(N)){
        cout<<"EL INGRESO DEBE SER POSITIVO"<<endl;
        system("pause");
        return false;
    }
    cout<<"INGRESE LA CANTIDAD DE ARTICULOS M: ";
    cin>>M;
    if(validar->regresar(M))
        return false;
    if(!validar->positivo(M)){
        cout<<"EL INGRESO DEBE SER POSITIVO"<<endl;
        system("pause");
        return false;
    }
    if(N<=M){
        cout<<"EL INGRESO N, DEBE SER MAYOR A M! "<<endl;
        system("pause");
        return false;
    }
    cout<<"CATEGORIA DE ARTICULO: ";
    cin>>cat;
    if(validar->regresar(cat))
        return false;
    if(!validar->rango(cat,0,13)){
        Mostrar->textoRangoInvalido(0,13);
        return false;
    }

    cout<<"FECHA DE INICIO DE LA PROMOCION "<<endl;
    if(!inicio.ingresoFecha())
        return false;
    cout<<"FECHA DE FIN DE LA PROMOCION "<<endl;
    if(!fin.ingresoFecha())
        return false;

    porc=(((float)M*100)/N)/100;
    setDesc(porc);
    setFechaFin(fin);
    setFechaInicio(inicio);
    setN(N);
    setM(M);
    setCodigo(codigo);
    setCategoria(cat);
    setEstado(true);
    return true;
}

bool Promocion::cargarPorcentaje(){

    int cat,codigo;
    float porc;
    Fecha inicio,fin;
    Validacion* validar = new Validacion();
    Imprimir* Mostrar = new Imprimir();
    Archivo* archivo = new Archivo();

    cout<<"NUEVA PROMOCION"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"CODIGO DE PROMOCION: ";
    cin>>codigo;
    if(validar->regresar(codigo))
        return false;
    if(!validar->positivo(codigo)){
        Mostrar->textoNoPositivo();
        return false;
    }

    cout<<"INGRESE EL PORCENTAJE DE DESCUENTO A APLICAR: ";
    cin>>porc;

    cout<<"CATEGORIA DE ARTICULO: ";
    cin>>cat;
    if(validar->regresar(cat))
        return false;
    if(!validar->rango(cat,0,13)){
        Mostrar->textoRangoInvalido(0,13);
        return false;
    }

    cout<<"FECHA DE INICIO DE LA PROMOCION "<<endl;
    if(!inicio.ingresoFecha())
        return false;
    cout<<"FECHA DE FIN DE LA PROMOCION "<<endl;
    if(!fin.ingresoFecha())
        return false;

    porc=((float)100-porc)/100;
    setDesc(porc);
    setFechaFin(fin);
    setFechaInicio(inicio);
    setCodigo(codigo);
    setN(0);
    setM(0);
    setCategoria(cat);
    setEstado(true);
    return true;
}

bool Promocion::cargarArticulo(){

    int cat,codigo,codArt;
    float porc;
    Fecha inicio,fin;
    Validacion* validar = new Validacion();
    Imprimir* Mostrar = new Imprimir();
    Archivo* archivo = new Archivo();

    cout<<"NUEVA PROMOCION"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"CODIGO DE PROMOCION: ";
    cin>>codigo;
    if(validar->regresar(codigo))
        return false;
    if(!validar->positivo(codigo)){
        Mostrar->textoNoPositivo();
        return false;
    }

    cout<<"INGRESE EL PORCENTAJE DE DESCUENTO A APLICAR: ";
    cin>>porc;

    cout<<"ARTICULO: ";
    cin>>codArt;
    if(validar->regresar(cat))
        return false;
    if(!archivo->comprobarRegistro(arti,codArt)){
        cout<<"EL CODIGO INGRESADO NO EXISTE"<<endl;
        system("pause");
        return false;
    }

    cout<<"FECHA DE INICIO DE LA PROMOCION "<<endl;
    if(!inicio.ingresoFecha())
        return false;
    cout<<"FECHA DE FIN DE LA PROMOCION "<<endl;
    if(!fin.ingresoFecha())
        return false;

    porc=((float)100-porc)/100;
    setDesc(porc);
    setFechaFin(fin);
    setFechaInicio(inicio);
    setCodigo(codigo);
    setN(0);
    setM(0);
    setCategoria(0);
    setCodArt(codArt);
    setEstado(true);
    return true;
}

#endif // PROMOCIONES_H_INCLUDED
