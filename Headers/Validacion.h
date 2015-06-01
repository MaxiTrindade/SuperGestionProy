#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED

class Validacion{

    public:
        bool Regresar(int numero){
            if(numero == -1) return true;
            else return false;
        }
        bool Regresar(char* palabra){
            if(strcmp(palabra,"-1")==0) return true;
            else return false;
        }
        bool Regresar(float numero){
            if(numero == -1) return true;
            else return false;
        }
        bool Positivo(int numero){
            if (numero>0) return true;
            else return false;
        }
        bool Rango(int numero,int minimo, int maximo){
            if(numero>=minimo && numero<=maximo)
                return true;
            return false;
        }
};
#endif // VALIDACION_H_INCLUDED
