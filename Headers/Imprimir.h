#ifndef IMPRIMIR_H_INCLUDED
#define IMPRIMIR_H_INCLUDED

class Imprimir{

    public:
        void textoCargaArt(int cod, int stk, int sec, float pre, char nom[20],int num){
            system("cls");
            cout<<"\n CARGAR ARTICULO: (Volver: Ingrese -1)\n";
            cout<<" ---------------\n\n";
            cout<<" CODIGO: ";  if(num == 1) return; cout<<cod<<endl;
            cout<<" NOMBRE: ";  if(num == 2) return; cout<<nom<<endl;
            cout<<" SECCION: "; if(num == 3) return; cout<<sec<<endl;
            cout<<" PRECIO: $"; if(num == 4) return; cout<<pre<<endl;
            cout<<" STOCK: ";   if(num == 5) return;
        }

        void textoCargaCli(int cod, int loc, char nom[20], char ape[20], char dire[20],int num){
            system("cls");
            cout<<"\n CARGAR CLIENTE: (Volver: Ingrese -1)\n";
            cout<<" ---------------\n\n";
            cout<<" CODIGO: ";  if(num == 1) return; cout<<cod<<endl;
            cout<<" NOMBRE: ";  if(num == 2) return; cout<<nom<<endl;
            cout<<" APELLIDO: "; if(num == 3) return; cout<<ape<<endl;
            cout<<" DIRECCION: "; if(num == 4) return; cout<<dire<<endl;
            cout<<" LOCALIDAD: "; if(num == 5) return;
        }

        void textoCargaVen(int Ven,int Emp,int Cli,int Art,int cant,int formaPago,float total,int num){
        system("cls");
        cout<<"\n CARGAR VENTA: (Volver: Ingrese -1)\n";
        cout<<" ---------------\n\n";
        cout<<" CODIGO DE VENTA: ";  if(num == 1) return; cout<<Ven<<endl;
        cout<<" CODIGO DE EMPLEADO: ";  if(num == 2) return; cout<<Emp<<endl;
        cout<<" CODIGO DE CLIENTE: "; if(num == 3) return; cout<<Cli<<endl;
        cout<<" CODIGO DE ARTICULO: "; if(num == 4) return; cout<<Art<<endl;
        cout<<" CANTIDAD: "; if(num == 5) return; cout<<cant<<endl;
        cout<<" FORMA DE PAGO: "; if(num == 6) return; cout<<formaPago<<endl;
        cout<<" TOTAL: "; if(num == 7) return;
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

};


#endif // IMPRIMIR_H_INCLUDED
