#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED

bool Validacion::regresar(int numero){
    if(numero == -1) return true;
    else return false;
}

bool Validacion::regresar(char* palabra){
    if(strcmp(palabra,"-1")==0) return true;
    else return false;
}

bool Validacion::regresar(float numero){
    if(numero == -1) return true;
    else return false;
}

bool Validacion::positivo(int numero){
    if (numero>0) return true;
    else return false;
}

bool Validacion::positivo(float numero){
    if (numero>0) return true;
    else return false;
}

bool Validacion::rango(int numero,int minimo, int maximo){
    if(numero>=minimo && numero<=maximo)
        return true;
    return false;
}


#endif // VALIDACION_H_INCLUDED
