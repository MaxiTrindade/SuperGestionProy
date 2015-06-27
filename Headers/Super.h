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
    artXVen,
    artXCom
};

enum TipoArt{
    almacen,
    carniceria,
    verduleria,
    panaderia,
    congelados,
    bebidas,
    electronica,
    bazar,
    jugueteria,
    sanitarios,
    libreria,
    textil,
    limpieza,
    construccion
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

Fecha fechaSistema(Fecha fechaSys){
  time_t tiempo;
  char cad[80];
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  fechaSys.setDia(tmPtr->tm_mday);
  fechaSys.setMes(tmPtr->tm_mon+1);
  fechaSys.setAnio(1900+tmPtr->tm_year);

  return fechaSys;
}

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
        Fecha fechaVenta;
    public:
        int getCodigo(){return codigo;}
        int getCodEmp(){return codEmp;}
        int getCodCli(){return codCli;}
        int getFormaPago(){return formaPago;}
        Fecha getFecha(){return fechaVenta;}
        float getTotal(){return total;}
        bool getEstado(){return estado;}
        void setCodigo(int codigo){this->codigo=codigo;}
        void setCodEmp(int codEmp){this->codEmp=codEmp;}
        void setCodCli(int codCli){this->codCli=codCli;}
        void setFormaPago(int formaPago){this->formaPago=formaPago;}
        void setTotal(int total){this->total=total;}
        void setEstado(bool estado){this->estado=estado;}
        void setFecha(Fecha fecha){this->fechaVenta=fecha;}
        bool cargar();

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
        void editar(int,void*,int);
        void alta();
        void BajaFisica();
        void backup();
        void restaurarCopia();
        int buscarPosicion(int,int);
        void listadosVentas(int);

};

class Usuario{

    private:
        char nombre[20],clave[20];
        bool estado;
        char color[9] = "COLOR 0F";
    public:
        char* getNombre();
        char* getClave();
        bool getEstado();
        char* getColor(){return color;}
        void setNombre(char* nombre);
        void setClave(char* clave);
        void setEstado(bool estado);
        void setColor(char* color){strcpy(this->color,color);}
        bool cargar();
        Usuario* login();
        bool cerrarSesion();
        void cambiarClave();
        bool comprobarUsuario(char* nombre);
        bool comprobarClave(char* nombre, char* clave);
        void eliminar();
        void cambiarColor();
        char* leerColor();
};

class Administracion{
    public:
};

class Informe{

    public:
        void vectorEnCero(int*,int);
        void porcArtCargados();

};

class Proveedor{
    private:
        char nombre[30],desc[50],telefono[15],email[30],direc[50];
        int categoria,codigo;
    public:
        char* getNombre();
        char* getDesc();
        char* getTelefono();
        char* getEmail();
        char* getDirec();
        int getCategoria();
        int getCodigo();
        void setNombre(char*);
        void setDesc(char*);
        void setTelefono(char*);
        void setEmail(char*);
        void setDirec(char*);
        void setCategoria(int);
        void setCodigo(int);
        bool cargar();
};

class Compra{
    private:
        int codigo,codPro;
        float total;
        Fecha fechaCompra;
        bool estado;
    public:
        int getCodigo();
        float getTotal();
        int getCodPro();
        Fecha getFechaCompra();
        bool getEstado();
        void setCodigo(int);
        void setCodPro(int);
        void setTotal(float);
        void setFechaCompra(int,int,int);
        void setEstado(bool);
        int cargar();
};

class ArtXCompra{
    private:
        int codArt,cantidad,codComp;
        float subTot;
    public:
        int getCodArt(){return codArt;}
        int getCantidad(){return cantidad;}
        int getCodComp(){return codComp;}
        float getSubTot(){return subTot;}
        void setCodArt(int x){this->codArt=x;}
        void setCantidad(int x){this->cantidad=x;}
        void setCodComp(int x){this->codComp=x;}
        void setSubTot(float x){this->subTot=x;}
};

class Promocion{
    private:
        int n, m,cat,cod,codArt;
        float desc;
        bool estado;
        Fecha inicio,fin;
    public:
        void setCodigo(int cod){this->cod=cod;}
        void setN(int n){this->n=n;}
        void setM(int m){this->m=m;}
        void setDesc(float desc){this->desc=desc;}
        void setEstado(bool estado){this->estado=estado;}
        void setFechaInicio(Fecha inicio){
            this->inicio.setDia(inicio.getDia());
            this->inicio.setMes(inicio.getMes());
            this->inicio.setAnio(inicio.getAnio());
        }

        void setFechaFin(Fecha fin){
            this->fin.setDia(fin.getDia());
            this->fin.setMes(fin.getMes());
            this->fin.setAnio(fin.getAnio());
        }
        void setCategoria(int cat){this->cat=cat;}
        void setCodArt(int art){this->codArt=art;}
        int getCodigo(){return cod;}
        int getN(){return n;}
        int getM(){return m;}
        float getDesc(){return desc;}
        bool getEstado(){return estado;}
        Fecha getFechaInicio(){return inicio;}
        Fecha getFechaFin(){return fin;}
        int getCategoria(){return cat;}
        int getCodArt(){return codArt;}
        bool cargarNXM();
        bool cargarPorcentaje();
        bool cargarArticulo();
};

#endif // SUPER_H_INCLUDED
