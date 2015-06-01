#ifndef ARTICULOS_H_INCLUDED
#define ARTICULOS_H_INCLUDED

class Articulo{

    private:
        //// PROPIEDADES DE LOS ARTICULOS ////
        int codigo;
        char nombre[20];
        int stock;
        float precio;
        int seccion;
        bool estado;

    public:
        //// GETTERS Y SETTERS ////
        void setNombre(char nombre[20]){
            strcpy(this->nombre,nombre);
        }
        void setStock(int stock){
            this->stock = stock;
        }
        void setPrecio(float precio){
            this->precio = precio;
        }
        void setSeccion(int seccion){
            this->seccion = seccion;
        }
        void setEstado(bool estado){
            this->estado = estado;
        }
        void setCodigo(int codigo){
            this->codigo = codigo;
        }
        char* getNombre(){
            return nombre;
        }
        int getStock(){
            return stock;
        }
        float getPrecio(){
            return precio;
        }
        int getSeccion(){
            return seccion;
        }
        bool getEstado(){
            return estado;
        }
        int getCodigo(){
            return codigo;
        }

        //// FUNCIONES ADICIONALES ////

        void cargar(){

            int codigo,stock,seccion; float precio; char nombre[20];
            Validacion* validar = new Validacion();
            Imprimir* Mostrar = new Imprimir();

            bool reintentar = true;
            while(reintentar){
                Mostrar->textoCargaArt(codigo,stock,seccion,precio,nombre,1);
                cin>>codigo;
                if(validar->Regresar(codigo)) return;
                if(validar->Positivo(codigo)) reintentar = false;
                else Mostrar->textoNoPositivo();
            }

            cout<<" NOMBRE: ";
            cin>>nombre;
            if(validar->Regresar(nombre)) return;

            reintentar = true;
            cout<<" SECCION: ";
            while(reintentar){
                cin>>seccion;
                if(validar->Regresar(seccion)) return;
                if(validar->Rango(seccion,1,5)) reintentar = false;
                else{
                    Mostrar->textoRangoInvalido(1,5);
                    Mostrar->textoCargaArt(codigo,stock,seccion,precio,nombre,3);
                }
            }

            reintentar = true;
            cout<<" PRECIO: $";
            while(reintentar){
                cin>>precio;
                if(validar->Regresar(precio)) return;
                if(validar->Positivo(precio)) reintentar = false;
                else{
                    Mostrar->textoNoPositivo();
                    Mostrar->textoCargaArt(codigo,stock,seccion,precio,nombre,4);
                }
            }

            reintentar = true;
            cout<<" STOCK: ";
            while(reintentar){
                cin>>stock;
                if(validar->Regresar(stock)) return;
                if(validar->Positivo(stock)) reintentar = false;
                else{
                    Mostrar->textoNoPositivo();
                    Mostrar->textoCargaArt(codigo,stock,seccion,precio,nombre,5);
                }
            }

            cout<<"\n ARTICULO CARGADO CON EXITO!\n\n "; system("pause");

            setStock(stock);
            setPrecio(precio);
            setSeccion(seccion);
            setNombre(nombre);
            setCodigo(codigo);
            setEstado(true);
        }
};

#endif // ARTICULOS_H_INCLUDED

