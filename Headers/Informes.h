#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void Informe::vectorEnCero(int* vect,int tam){
    for(int i=0;i<tam;i++)
        vect[i]=0;
}

void Informe::porcArtCargados(){

    system("cls");
    Articulo* Art = new Articulo();
    Archivo* archivo = new Archivo();

    FILE* archivoArt = fopen("Articulos.dat","rb");
    if(archivoArt==NULL){
        cout<<"\n No hay Articulos Disponibles para Informar\n\n ";
        system("pause");
        fclose(archivoArt);
        return;
    }

    int cantArticulos = archivo->contarRegistros(arti);

    if(cantArticulos==0){
        cout<<"\n No hay Articulos Disponibles para Informar\n\n ";
        system("pause");
        fclose(archivoArt);
        return;
    }

    int vectArticulos[14];
    vectorEnCero(vectArticulos,14);

    while(fread(Art,sizeof (Articulo),1,archivoArt))
        if(Art->getEstado())
            vectArticulos[Art->getSeccion()]++;


    cout<<"\n DISTRIBUCION DE ARTICULOS REGISTRADOS (POR SECCION)\n\n ";

    for(int i=0;i<14;i++){
        float Porcentaje = (float)vectArticulos[i]*(100/(float)cantArticulos);
        switch(i){
            case almacen:      cout<<"      ALMACEN "; break;
            case carniceria:   cout<<"   CARNICERIA "; break;
            case verduleria:   cout<<"   VERDULERIA "; break;
            case electronica:  cout<<"  ELECTRONICA "; break;
            case jugueteria:   cout<<"   JUGUETERIA "; break;
            case construccion: cout<<" CONSTRUCCION "; break;
            case panaderia:    cout<<"    PANADERIA "; break;
            case congelados:   cout<<"   CONGELADOS "; break;
            case bazar:        cout<<"        BAZAR "; break;
            case sanitarios:   cout<<"   SANITARIOS "; break;
            case bebidas:      cout<<"      BEBIDAS "; break;
            case libreria:     cout<<"     LIBRERIA "; break;
            case limpieza:     cout<<"     LIMPIEZA "; break;
            case textil:       cout<<"       TEXTIL "; break;
        }
        for(int i=0;i<Porcentaje/2;i++)
            cout<<(char)178;
        cout<<" "<<setprecision(3)<<Porcentaje<<"%"<<"  ("<<vectArticulos[i]<<")"<<endl<<endl<<ends;
    }
    system("pause");

}


#endif // INFORMES_H_INCLUDED
