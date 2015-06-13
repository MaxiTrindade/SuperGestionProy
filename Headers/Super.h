#ifndef SUPER_H_INCLUDED
#define SUPER_H_INCLUDED

//// SI SE LA REQUIERE, AQUI SE DEFINE LA CLASE "SUPER" ////

enum Tipo{
    arti,
    clie,
    prov,
    empl,
    comp,
    vent,
    usua,
    prom,
    artXVen
};

enum estadoVenta{
    incorrecto,
    grabo,
    bajaLogica
};

class Validacion{

    public:
        bool regresar(int);
        bool regresar(char*);
        bool regresar(float);
        bool positivo(int);
        bool positivo(float);
        bool rango(int,int,int);
};

class Fecha{
    private:
        int dia,mes,anio;
    public:
        int getDia();
        int getMes();
        int getAnio();
        void setDia(int);
        void setMes(int);
        void setAnio(int);

    bool ingresoFecha();
    bool validaFecha(int,int,int);
};

class ArtXVenta{
    private:
        int codArt,cantidad,codVent;
        float subTot;
    public:
        int getCodArt(){return codArt;}
        int getCantidad(){return cantidad;}
        int getCodVent(){return codVent;}
        float getSubTot(){return subTot;}
        void setCodArt(int x){this->codArt=x;}
        void setCantidad(int x){this->cantidad=x;}
        void setCodVent(int x){this->codVent=x;}
        void setSubTot(float x){this->subTot=x;}
};

class Venta{
    private:
        int formaPago,codigo,codEmp,codCli;
        float total;
        bool estado;
       // Fecha fechaVenta;
    public:
        int getCodigo(){return codigo;}
        int getCodEmp(){return codEmp;}
        int getCodCli(){return codCli;}
        int getFormaPago(){return formaPago;}
        float getTotal(){return total;}
        bool getEstado(){return estado;}
        void setCodigo(int codigo){this->codigo=codigo;}
        void setCodEmp(int codEmp){this->codEmp=codEmp;}
        void setCodCli(int codCli){this->codCli=codCli;}
        void setFormaPago(int formaPago){this->formaPago=formaPago;}
        void setTotal(int total){this->total=total;}
        void setEstado(bool estado){this->estado=estado;}
        int cargar();

};

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
        void setNombre(char nombre[20]);
        void setStock(int stock);
        void setPrecio(float precio);
        void setSeccion(int seccion);
        void setEstado(bool estado);
        void setCodigo(int codigo);
        char* getNombre();
        int getStock();
        float getPrecio();
        int getSeccion();
        bool getEstado();
        int getCodigo();
        //// FUNCIONES ADICIONALES ////
        bool cargar();
};

class Cliente{
    private:
        int codCli, localidad;
        char nombre[20],apellido[20],dire[20];
        bool estado;

    public:
        void setCodigo(int codigo);
        void setLocalidad(int localidad);
        void setNombre(char nombre[20]);
        void setApellido(char apellido[20]);
        void setDire(char dire[20]);
        void setEstado(bool estado);
        int getCodigo();
        int getLocalidad();
        char* getNombre();
        char* getApellido();
        char* getDire();
        bool getEstado();
        bool cargar();
};

class Empleado{

    private:
        int codigo,area;
        char nombre[20],apellido[20];
        Fecha ingreso,nacimiento;
        bool estado;
        float sueldo;

    public:
        int getCodigo();
        int getArea();
        char * getNombre();
        char * getApellido();
        Fecha getIngreso();
        Fecha getNacimiento();
        bool getEstado();
        float getSueldo();
        void setCodigo(int);
        void setArea(int);
        void setNombre(char *);
        void setApellido(char *);
        void setEstado(bool);
        void setSueldo(float);
        void setIngreso(int,int,int);
        void setNacimiento(int,int,int);

        //// FUNCIONES ADICIONALES ////

        bool cargar();
};

class Archivo{

    public:
        void guardar(void*,int);
        void listarTodos(int);
        void listarXCodigo(int);
        void eliminar(int);
        int contarRegistros(int);
        bool comprobarRegistro(int,int);
        void* buscarRegistro(int,int);
        void editarStock(void*,int,int);
        void editar(int);
};

class Usuario{

    private:
        char nombre[20],clave[20];
        Fecha fechaUsuario;
        bool estado;

    public:
        char* getNombre();
        char* getClave();
        bool getEstado();
        void setNombre(char nombre[20]);
        void setClave(char clave[20]);
        void setEstado(bool estado);
        void login();
        void cambiarClave();
};


#endif // SUPER_H_INCLUDED
