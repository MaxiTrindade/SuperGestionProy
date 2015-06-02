#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class Venta{
    /// PROTOTIPO CLASE VENTA SOLO GETTERS Y SETTERS. HACER CARGA EN GRUPO
    private:
        int codVent,codEmp,codCli,codArt,cantidad,formaPago;
        float total;

    public:

        void setCodVent(int codVent){
            this->codVent=codVent;
        }

        void setCodEmp(int codEmp){
            this->codEmp=codEmp;
        }

        void setCodCli(int codCli){
            this->codCli=codCli;
        }

        void setCodArt(int codArt){
            this->codArt=codArt;
        }

        void setCantidad(int cantidad){
            this->cantidad=cantidad;
        }

        void setFormaPago(int formaPago){
            this->formaPago=formaPago;
        }

        void setTotal(int total){
            this->total=total;
        }

        int getCodVent(){
            return codVent;
        }

        int getCodEmp(){
            return codEmp;
        }

        int getCodCli(){
            return codCli;
        }

        int getCodArt(){
            return codArt;
        }

        int getCantidad(){
            return cantidad;
        }

        int getFormaPago(){
            return formaPago;
        }

        float getTotal(){
            return total;
        }

        /// FUNCIONES EXTRA

        void cargar(){}
};

#endif // VENTAS_H_INCLUDED
