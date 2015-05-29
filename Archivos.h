#ifndef ARCHIVOS_H
#define ARCHIVOS_H



#endif // ARCHIVOS_H

class Archivos{

    public: Archivos(){}


    ///// FUNCIONES DE VALIDACIÓN /////
    public: bool existe(Articulo art, int code){
        FILE* Articulos = fopen("Articulos.dat","rb");

        if(Articulos==NULL) {
            fclose(Articulos);
            return false;
        }
        while(fread(&art,sizeof art,1,Articulos)){
            if(code == art.getCodigo()){
                fclose(Articulos);
                return true;
            }
        }
        fclose(Articulos);
        return false;
    }

    ///// FUNCIONES DE OPERATORIA /////
    public: void ordenar(Articulo articulo){
        Articulo aux;
        FILE* registro = fopen("Articulos.dat","rb+");
        if(registro == NULL) {cout<<"Error de Archivo"; exit(1);}
        fseek(registro,0,2);
        long tam = ftell(registro)/sizeof articulo;
        fseek(registro,0,0);
        for(int i=0;i<tam;i++){
            fseek(registro,i*sizeof articulo,0);
            while(fread(&articulo,sizeof articulo,1,registro)){
                int posicionador = i;
                aux = articulo;
                while(fread(&articulo,sizeof articulo,1,registro)){
                    posicionador++;
                    if(articulo.getCodigo()<aux.getCodigo()){
                        fseek(registro,i*sizeof articulo,0);
                        fwrite(&articulo,sizeof articulo,1,registro);
                        fseek(registro,posicionador*sizeof articulo,0);
                        fwrite(&aux,sizeof articulo,1,registro);
                        aux = articulo;
                        fclose(registro);
                        fopen("Articulos.dat","rb+");
                        fseek(registro,(posicionador+1)*sizeof articulo,0);
                    }
                }
            }
        }
        fclose(registro);
    }

    public: void escribir(Articulo art){
        FILE* Articulos = fopen("Articulos.dat","ab");
        if(Articulos==NULL) {
            system("cls");
            cout<<"\n Error al generar el archivo Articulos \n\n ";
            system("pause");
            fclose(Articulos);
            return;
        }
        fwrite(&art,sizeof art,1,Articulos);
        fclose(Articulos);
    }

    public: void mostrarTodos(Articulo art){
        FILE* Articulos = fopen("Articulos.dat","rb");

        if(Articulos==NULL) {
            system("cls");
            cout<<"\n No se han cargado Articulos";
            system("pause");
            return;
        }

        ordenar(art);
        fseek(Articulos,0,2);
        long tam = ftell(Articulos)/sizeof art;
        fseek(Articulos,0,0);
        int NumArt = 1;
        while(fread(&art,sizeof art,1,Articulos)){
            cout<<"\n ARTICULO: "<<NumArt<<" de "<<tam<<" (VOLVER: ESC)\n\n";
            cout<<" CODIGO: "<<art.getCodigo()<<endl;
            cout<<" NOMBRE: "<<art.getNombre()<<endl;
            cout<<" SECCION: "<<art.getSeccion()<<endl;
            cout<<" PRECIO: $"<<art.getPrecio()<<endl;
            cout<<" STOCK: "<<art.getStock()<<endl<<endl;

            if(getch()=='\033'){
                int pasar = (int)getch();

                switch(pasar){
                    case 27:
                        cout<<"Se apreto escape"; system("pause");
                        break;
                    case 75:
                        cout<<"Se apreto izquierda"; system("pause");
                        break;
                    case 77:
                        cout<<"Se apreto derecha"; system("pause");
                        break;
                    default:
                        break;
                }
            }

        }
        fclose(Articulos);
    }
    public: void mostrar(Articulo art, int code){
        FILE* Articulos = fopen("Articulos.dat","rb");
        if(Articulos==NULL) {
            system("cls");
            cout<<"\n No se han cargado articulos";
            exit(1);
        }
        while(fread(&art,sizeof art,1,Articulos)){
            if(code == art.getCodigo()){
                cout<<art.getCodigo()<<endl;
                cout<<art.getNombre()<<endl;
                cout<<art.getSeccion()<<endl;
                cout<<art.getPrecio()<<endl;
                cout<<art.getStock()<<endl<<endl;
            }
        }
        fclose(Articulos);
    }
    public: void editar(Articulo art, int code){
        FILE* Articulos = fopen("Articulos.dat","rb");
        if(Articulos==NULL) {
            system("cls");
            cout<<"\n No se han cargado articulos";
            exit(1);
        }
        while(fread(&art,sizeof art,1,Articulos)){
            if(code == art.getCodigo()){

                ////SEGUIR EDITANDO
            }
        }
        fclose(Articulos);
    }
    void eliminar(){}

};
