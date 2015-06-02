#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class Clientes{
    private:
        int codCli, localidad;
        char nombre[20],apellido[20],dire[20];
        bool estado;

    public:
        void setCodigo(int codigo){
            this->codCli=codigo;
        }

        void setLocalidad(int localidad){
            this->localidad=localidad;
        }

        void setNombre(char nombre[20]){
            strcpy(this->nombre,nombre);
        }

        void setApellido(char apellido[20]){
            strcpy(this->apellido,apellido);
        }

        void setDire(char dire[20]){
            strcpy(this->dire,dire);
        }

        void setEstado(bool estado){
            this->estado=estado;
        }

        int getCodigo(){
            return codCli;
        }

        int getLocalidad(){
            return localidad;
        }

        char* getNombre(){
            return nombre;
        }

        char* getApellido(){
            return apellido;
        }

        char* getDire(){
            return dire;
        }

        bool getEstado(){
            return estado;
        }

        void cargar(){

            int codCli, localidad;
            char nombre[20],apellido[20],dire[20];
            Validacion* validar = new Validacion();
            Imprimir* Mostrar = new Imprimir();

            bool reintentar = true;
            while(reintentar){
                Mostrar->textoCargaCli(codCli,localidad,nombre,apellido,dire,1);
                cin>>codCli;
                if(validar->Regresar(codCli)) return;
                if(validar->Positivo(codCli)) reintentar = false;
                else Mostrar->textoNoPositivo();
            }

            cout<<" NOMBRE: ";
            cin>>nombre;
            if(validar->Regresar(nombre)) return;

            cout<<" APELLIDO: ";
            cin>>apellido;
            if(validar->Regresar(apellido)) return;

            cout<<" DIRECCION: ";
            cin>>dire;
            if(validar->Regresar(dire)) return;

            reintentar = true;
            cout<<" LOCALIDAD: ";
            while(reintentar){
                cin>>localidad;
                if(validar->Regresar(localidad)) return;
                if(validar->Rango(localidad,1,20)) reintentar = false;
                else{
                    Mostrar->textoRangoInvalido(1,20);
                    Mostrar->textoCargaCli(codCli,localidad,nombre,apellido,dire,5);
                }
            }


            cout<<"\n CLIENTE CARGADO CON EXITO!\n\n "; system("pause");

            setCodigo(codCli);
            setLocalidad(localidad);
            setNombre(nombre);
            setApellido(apellido);
            setDire(dire);
            setEstado(true);
        }
};

#endif // CLIENTES_H_INCLUDED
