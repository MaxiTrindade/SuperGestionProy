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
