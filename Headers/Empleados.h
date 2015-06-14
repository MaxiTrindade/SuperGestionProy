#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

int Empleado::getCodigo() {return codigo;}

int Empleado::getArea() {return area;}

char* Empleado::getNombre() {return nombre;}

char* Empleado::getApellido() {return apellido;}

Fecha Empleado::getIngreso(){return this->ingreso;}

Fecha Empleado::getNacimiento() {return this->nacimiento;}

bool Empleado::getEstado() {return estado;}

float Empleado::getSueldo(){return sueldo;}

void Empleado::setCodigo(int codigo){this->codigo=codigo;}

void Empleado::setArea(int area){this->area=area;}

void Empleado::setNombre(char *nombre){strcpy(this->nombre,nombre);}

void Empleado::setApellido(char *apellido){strcpy(this->apellido,apellido);}

void Empleado::setEstado(bool x){estado=x;}

void Empleado::setSueldo(float sueldo){this->sueldo=sueldo;}

void Empleado::setIngreso(int d,int m,int a){
    this->ingreso.setDia(d);
    this->ingreso.setMes(m);
    this->ingreso.setAnio(a);
}

void Empleado::setNacimiento(int d,int m,int a){
    this->nacimiento.setDia(d);
    this->nacimiento.setMes(m);
    this->nacimiento.setAnio(a);
}


        //// FUNCIONES ADICIONALES ////

bool Empleado::cargar(){
    bool flag;
    int legajoX,areaX;
    char nombreX[20],apellidoX[20];
    float sueldoX;
    Fecha nac,ing;
    Archivo *archivo = new Archivo();
    Validacion *validar = new Validacion();
    Imprimir *mostrar = new Imprimir();

    flag=true;
    while(flag){
        mostrar->textoCargaEmp(legajoX,nombreX,apellidoX,nac,ing,areaX,sueldoX,1);
        cin>>legajoX;
        if(validar->regresar(legajoX)) return false;
        if(validar->positivo(legajoX)){
            flag=archivo->comprobarRegistro(empl,legajoX);
            if(flag)mostrar->existeCodigo();
                else flag=false;
        }
        else mostrar->textoNoPositivo();
    }
    mostrar->textoCargaEmp(legajoX,nombreX,apellidoX,nac,ing,areaX,sueldoX,2);
    cin.ignore();
    cin.getline(nombreX,19);
    if(validar->regresar(nombreX)) return false;
    mostrar->textoCargaEmp(legajoX,nombreX,apellidoX,nac,ing,areaX,sueldoX,3);
    cin.getline(apellidoX,19);
    if(validar->regresar(apellidoX)) return false;

    mostrar->textoCargaEmp(legajoX,nombreX,apellidoX,nac,ing,areaX,sueldoX,4);
    cout<<endl;
    flag=nac.ingresoFecha();
    if(flag==false) return false;

    mostrar->textoCargaEmp(legajoX,nombreX,apellidoX,nac,ing,areaX,sueldoX,5);
    cout<<endl;
    flag=ing.ingresoFecha();
    if(flag==false) return false;

    flag=false;
    while(flag==false){
        mostrar->textoCargaEmp(legajoX,nombreX,apellidoX,nac,ing,areaX,sueldoX,6);
        cin>>areaX;
        if(validar->regresar(areaX)) return false;
        flag=validar->positivo(areaX);
        flag=validar->rango(areaX,1,4);
        if(flag==false) mostrar->textoRangoInvalido(1,4);
    }

    flag=false;
    while(flag==false){
        mostrar->textoCargaEmp(legajoX,nombreX,apellidoX,nac,ing,areaX,sueldoX,7);
        cin>>sueldoX;
        if(validar->regresar(sueldoX)) return false;
        flag=validar->positivo(sueldoX);
        if(flag==false) mostrar->textoNoPositivo();
    }

    setCodigo(legajoX);
    setNombre(nombreX);
    setApellido(apellidoX);
    setNacimiento(nac.getDia(),nac.getMes(),nac.getAnio());
    setIngreso(ing.getDia(),ing.getMes(),ing.getAnio());
    setArea(areaX);
    setSueldo(sueldoX);
    setEstado(true);
    return true;
}


#endif // EMPLEADOS_H_INCLUDED
