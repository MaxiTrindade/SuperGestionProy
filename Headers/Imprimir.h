#ifndef IMPRIMIR_H_INCLUDED
#define IMPRIMIR_H_INCLUDED

class Imprimir{

    public:
        void fecha(Fecha fecha){
            cout<<fecha.getDia()<<"/"<<fecha.getMes()<<"/"<<fecha.getAnio()<<endl;
        }

        void textoCargaArt(int cod, int stk, int sec, float pre, char nom[20],int num){
            system("cls");
            cout<<"\n INGRESAR ARTICULO: (Volver: Ingrese -1)\n";
            cout<<" ---------------\n\n";
            cout<<" CODIGO: ";  if(num == 1) return; cout<<cod<<endl;
            cout<<" NOMBRE: ";  if(num == 2) return; cout<<nom<<endl;
            cout<<" SECCION: "; if(num == 3) return; cout<<sec<<endl;
            cout<<" PRECIO: $"; if(num == 4) return; cout<<pre<<endl;
            cout<<" STOCK: ";   if(num == 5) return;
        }

        void textoCargaCli(int cod, int loc, char nom[20], char ape[20], char dire[20],int num){
            system("cls");
            cout<<"\n INGRESAR CLIENTE: (Volver: Ingrese -1)\n";
            cout<<" ---------------\n\n";
            cout<<" CODIGO: ";  if(num == 1) return; cout<<cod<<endl;
            cout<<" NOMBRE: ";  if(num == 2) return; cout<<nom<<endl;
            cout<<" APELLIDO: "; if(num == 3) return; cout<<ape<<endl;
            cout<<" DIRECCION: "; if(num == 4) return; cout<<dire<<endl;
            cout<<" LOCALIDAD: "; if(num == 5) return;
        }

        void textoCargaVen(int Ven,int Emp,int Cli,int Art,int cant,int formaPago,float total,int num){
            system("cls");
            cout<<"\n INGRESAR VENTA: (Volver: Ingrese -1)\n";
            cout<<" ---------------\n\n";
            cout<<" CODIGO DE VENTA: ";  if(num == 1) return; cout<<Ven<<endl;
            cout<<" CODIGO DE EMPLEADO: ";  if(num == 2) return; cout<<Emp<<endl;
            cout<<" CODIGO DE CLIENTE: "; if(num == 3) return; cout<<Cli<<endl;
            cout<<" CODIGO DE ARTICULO: "; if(num == 4) return; cout<<Art<<endl;
            cout<<" FORMA DE PAGO: "; if(num == 5) return; cout<<formaPago<<endl;
            cout<<" TOTAL: "; if(num == 6) return;
        }

        void textoCargaEmp(int legajo,char nombre[20],char apellido[20],Fecha nacimiento,Fecha ingreso,int area,float sueldo,int num){
            system("cls");
            cout<<"\n INGRESAR EMPLEADO: (Volver: Ingrese -1)\n";
            cout<<" ---------------\n\n";
            cout<<" LEGAJO: ";  if(num == 1) return; cout<<legajo<<endl;
            cout<<" NOMBRE: ";  if(num == 2) return; cout<<nombre<<endl;
            cout<<" APELLIDO: "; if(num == 3) return; cout<<apellido<<endl;
            cout<<" NACIMIENTO: "; if(num == 4) return; fecha(nacimiento);
            cout<<" INGRESO: ";   if(num == 5) return; fecha(ingreso);
            cout<<" AREA: "; if(num == 6) return; cout<<area<<endl;
            cout<<" SUELDO: $";if(num == 7) return; cout<<sueldo<<endl;
        }

        void textoNoPositivo(){
            system("cls");
            cout<<"\n El numero ingresado es invalido.\n Se requiere de un valor positivo\n\n ";
            system("pause");
        }

        void textoRangoInvalido(int minimo, int maximo){
            system("cls");
            cout<<"\n El valor ingresado es incorrecto.\n Se admiten valores entre "<<minimo<<" y "<<maximo<<"\n\n ";
            system("pause");
        }

        void noExisteCodigo(){
            system("CLS");
            cout<<"ESTE CODIGO NO EXISTE"<<endl;
            system("PAUSE");
        }

        void existeCodigo(){
            system("CLS");
            cout<<"ESTE CODIGO YA EXISTE"<<endl;
            system("PAUSE");
        }

        void articulo(Articulo* obj){
            cout<<"CODIGO: "<<obj->getCodigo()<<endl;
            cout<<"NOMBRE: "<<obj->getNombre()<<endl;
            cout<<"SECCION: "<<obj->getSeccion()<<endl;
            cout<<"PRECIO: $: "<<obj->getPrecio()<<endl;
            cout<<"STOCK: "<<obj->getStock()<<endl<<endl;
            cout<<"---------------------------"<<endl;
        }

        void cliente(Cliente *obj){
            cout<<"CODIGO: "<<obj->getCodigo()<<endl;
            cout<<"NOMBRE: "<<obj->getNombre()<<endl;
            cout<<"APELLIDO: "<<obj->getApellido()<<endl;
            cout<<"DIRECCION: "<<obj->getDire()<<endl;
            cout<<"LOCALIDAD: "<<obj->getLocalidad()<<endl<<endl;
            cout<<"---------------------------"<<endl;
        }

        void venta(Venta *obj){
            cout<<"CODIGO: "<<obj->getCodigo()<<endl;
            cout<<"CODIGO DE CLIENTE: "<<obj->getCodCli()<<endl;
            cout<<"CODIGO DE EMPLEADO: "<<obj->getCodEmp()<<endl;
            cout<<"FORMA DE PAGO: "<<obj->getFormaPago()<<endl;
            cout<<"TOTAL: "<<obj->getTotal()<<endl<<endl;
            cout<<"---------------------------"<<endl;
        }

        void empleado(Empleado *obj){

            Imprimir* mostrar = new Imprimir();

            cout<<"CODIGO: "<<obj->getCodigo()<<endl;
            cout<<"NOMBRE: "<<obj->getNombre()<<endl;
            cout<<"APELLIDO: "<<obj->getApellido()<<endl;
            cout<<"FECHA DE NACIMIENTO: "; mostrar->fecha(obj->getNacimiento());
            cout<<"FECHA DE INGRESO: "; mostrar->fecha(obj->getIngreso());
            cout<<"AREA: "<<obj->getArea()<<endl;
            cout<<"SUELDO: "<<obj->getSueldo()<<endl;
            cout<<"---------------------------"<<endl;
        }
};

#endif // IMPRIMIR_H_INCLUDED
