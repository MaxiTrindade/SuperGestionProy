#ifndef ARTICULOS_H_INCLUDED
#define ARTICULOS_H_INCLUDED

class Articulo{

    private:
        int Codigo;
        int Stock;         //////////////////////////////////////
        int Seccion;       //// PROPIEDADES DE LOS ARTÍCULOS ////
        char Nombre[20];   //////////////////////////////////////
        float Precio;
        bool Estado;

    public:
        ///// GETTERS Y SETTERS /////
        void setCodigo(int Codigo){
            this->Codigo = Codigo;
        }
        void setStock(int Stock){
            this->Stock = Stock;
        }
        void setSeccion(int Seccion){
            this->Seccion = Seccion;
        }
        void setNombre(char* Nombre){
            strcpy(this->Nombre,Nombre);
        }
        void setPrecio(float Precio){
            this->Precio = Precio;
        }
        void setEstado(bool Estado){
            this->Estado = Estado;
        }
        int getCodigo(){
            return Codigo;
        }
        int getStock(){
            return Stock;
        }
        int getSeccion(){
            return Seccion;
        }
        char* getNombre(){
            return Nombre;
        }
        float getPrecio(){
            return Precio;
        }
        bool getEstado(){
            return Estado;
        }


        void cargar(){

            int codigo,stock,seccion; float precio; char nombre[20];

            cout<<"Codigo: ";
            cin>>codigo;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<"Stock: ";
            cin>>stock;
            cout<<"Precio: $";
            cin>>precio;
            cout<<"Seccion: ";
            cin>>seccion;

            setCodigo(codigo);
            setNombre(nombre);
            setSeccion(seccion);
            setStock(stock);
            setPrecio(precio);
            setEstado(true);

        }
};

#endif // ARTICULOS_H_INCLUDED
