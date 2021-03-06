#ifndef IMPRIMIR_H_INCLUDED
#define IMPRIMIR_H_INCLUDED

void gotoxy(int,int);

class Imprimir{

    public:
        void fecha(Fecha fecha){
            cout<<fecha.getDia()<<"/"<<fecha.getMes()<<"/"<<fecha.getAnio();
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

        void textoCargaProv(char *nombre,char *direc,char *email,char *desc,char *tel,int cat,int codigo,int num){
            system("cls");
            cout<<"\n INGRESAR PROVEEDOR: (Volver: Ingrese -1)\n";
            cout<<" ---------------\n\n";
            cout<<" CODIGO: "; if(num == 0) return; cout<<codigo<<endl;
            cout<<" NOMBRE: ";  if(num == 1) return; cout<<nombre<<endl;
            cout<<" DECRIPCION: ";  if(num == 2) return; cout<<desc<<endl;
            cout<<" DIRECCION: ";   if(num == 3) return; cout<<direc<<endl;
            cout<<" TELEFONO: "; if(num == 4) return; cout<<tel<<endl;
            cout<<" E-MAIL: "; if(num == 5) return; cout<<email<<endl;
            cout<<" CATEGORIA DE ARTICULOS: "; if(num == 6) return; cout<<cat<<endl;
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

        void usuario(Usuario *obj){

            Imprimir* mostrar = new Imprimir();

            cout<<"NOMBRE: "<<obj->getNombre()<<endl;
            cout<<"FECHA DE REGISTRO: ";
            mostrar->fecha(obj->getFecha());
            cout<<"---------------------------"<<endl;
        }

        void proveedor(Proveedor *obj){
            cout<<"CODIGO: "<<obj->getCodigo()<<endl;
            cout<<"NOMBRE: "<<obj->getNombre()<<endl;
            cout<<"DESCRIPCION: "<<obj->getDesc()<<endl;
            cout<<"DIRECCION: "<<obj->getDirec()<<endl;
            cout<<"TELEFONO: "<<obj->getTelefono()<<endl;
            cout<<"EMAIL: "<<obj->getEmail()<<endl;
            cout<<"CATEGORIA: "<<obj->getCategoria()<<endl;
            cout<<"-------------------------------"<<endl;
        }

        void compra(Compra *obj){
            Imprimir *mostrar = new Imprimir();

            cout<<"CODIGO COMPRA: "<<obj->getCodigo()<<endl;
            cout<<"FECHA COMPRA: ";mostrar->fecha(obj->getFechaCompra());
            cout<<"CODIGO PROVEEDOR: "<<obj->getCodPro()<<endl;
            cout<<"TOTAL: $"<<obj->getTotal()<<endl;
            cout<<"-------------------------------"<<endl<<endl;

        }

        void opcionesListarCod(){
            cout<<"\t \t <-- \t \t \t \t -->"<<endl;
            cout<<"\t \t \t INGRESE 0 PARA SALIR"<<endl;
        }

        void artXventa(ArtXVenta *obj){
            cout<<"CODIGO DE ARTICULO: "<<obj->getCodArt()<<endl;
            cout<<"CANTIDAD: "<<obj->getCantidad()<<endl;
            cout<<"SUBTOTAL: "<<obj->getSubTot()<<endl<<endl;
            cout<<"---------------------------"<<endl;
        }

        void promocion(Promocion *promo){

            Imprimir* mostrar = new Imprimir();

            cout<<" CODIGO: "<<promo->getCodigo()<<endl;
            if(promo->getN()!=0){
                cout<<" N : " <<promo->getN()<<endl;
                cout<<" M : " <<promo->getM()<<endl;
            }
            cout<<" PORCENTAJE DE DESCUENTO: "<<100-(promo->getDesc()*100)<<"%"<<endl;
            if(promo->getCategoria()!=0)
                cout<<" CATEGORIA DEL ARTICULO: "<<promo->getCategoria()<<endl;
            else{
                cout<<" CODIGO DE ARTICULO: "<<promo->getCodArt()<<endl;
            }
            cout<<" FECHA DE INICIO: ";
            mostrar->fecha(promo->getFechaInicio());
            cout<<endl<<" FECHA DE FIN: ";
            mostrar->fecha(promo->getFechaFin());
            cout<<endl<<"---------------------------"<<endl;

        }

        void limpiarLinea(int x,int y,int cantLineas){
            int i,j;

            for(i=0;i<cantLineas;i++){//FOR DE CANTIDAD DE LINEAS QUE SE BORRAN
                gotoxy(x,--y);
                for(j=0;j<=40;j++) {//FOR DE CANTIDAD DE ESPACIOS QUE SE BORRAN
                    cout<<" ";
                }
            }
            gotoxy(x,y); //SE REGRESA AL PRINCIPIO DE LA ULTIMA LINEA BORRADA
        }
};

void gotoxy(int x,int y){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}

int wherex(){
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return csbi.dwCursorPosition.X;
}

int wherey(){
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return csbi.dwCursorPosition.Y;
}

void pedirCoord(COORD &pos){
    pos.X=wherex();
    pos.Y=wherey();
}

#endif // IMPRIMIR_H_INCLUDED
