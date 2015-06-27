#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

int Fecha::getDia(){return dia;}
int Fecha::getMes(){return mes;}
int Fecha::getAnio(){return anio;}
void Fecha::setDia(int dia){this->dia=dia;}
void Fecha::setMes(int mes){this->mes=mes;}
void Fecha::setAnio(int anio){this->anio=anio;}

bool Fecha::ingresoFecha(){
    int d,m,a;
    Validacion validar;
    COORD cursor;
    Imprimir* mostrar = new Imprimir();

    while(true){
        cout<<" DIA: ";
        cin>>d;
        if(validar.regresar(d)) return false;
        cout<<" MES: ";
        cin>>m;
        if(validar.regresar(m)) return false;
        cout<<" A"<<(char)165<<"O: ";
        cin>>a;
        if(validar.regresar(a)) return false;
        if(validaFecha(a,m,d)){
            setDia(d);
            setMes(m);
            setAnio(a);
            return true;
        }
        else{
            system("pause");
            pedirCoord(cursor);
            mostrar->limpiarLinea(cursor.X,cursor.Y,5);
        }
    }
    return false;
}

bool Fecha::validaFecha(int a,int m,int d){
    bool flag=false;

    if(a>=1900){
        switch(m){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                    if(d>=1 && d<=31){flag=true;}
                        break;
            case 2: if((a%4==0)&&(a%100!=0)){
                            if(d>=1 && d<=29){flag=true;}
                    }
                     else {
                            if(a%400==0){
                                if(d>=1 && d<=29){flag=true;}}
                                else {
                                      if(d>0 && d<29){flag=true;}
                                      }}
                    break;
            case 4:
            case 6:
            case 9:
            case 11:
                     if(d>=1 && d<=30){flag=true;}
                     break;
            default: flag=false;
                     break;
        }
        if(flag==false){cout<<"FECHA INVALIDA, INGRESE NUEVAMENTE"<<endl;}
    }

    else{cout<<"A"<<(char)165<<"O INCORRECTO, INGRESE NUEVAMENTE"<<endl;}
    return flag;
}

Fecha fechaSys = fechaSistema(fechaSys);

#endif // FECHA_H_INCLUDED
