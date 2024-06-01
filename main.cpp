#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

void menu();
void version(string);

struct orden{
    int codigo_item, cantidad_item;
    string nombre_item;
    char nombre_cliente[20];
    float precio_item;
};

int main() {
    setlocale(LC_ALL, "spanish");
    version("b1.1");
    menu();
    int op;
    float costo_total;
    cin>>op;
    switch(op) {
        case 1:{
            int n=20;
            orden ord[n];

            fflush(stdin);
            cout<<"Ingrese el nombre del cliente: ";
            cin.getline(ord[n].nombre_cliente, 20);

            fflush(stdin);
            for(int i=0; i<n; i++){
                cout<<"Inserte codigo de item (0 para terminar la orden): ";
                fflush(stdin);

                cin>>ord[i].codigo_item;
                fflush(stdin);
                switch(ord[i].codigo_item){

                    ///Entradas
                    case 101:{
                        ord[i].nombre_item="Caldo de Gallina";
                        ord[i].precio_item=8.00;
                        break;
                    }
                    case 102:{
                        ord[i].nombre_item="Sopa de Wantan";
                        ord[i].precio_item=8.00;
                        break;
                    }
                    case 103:{
                        ord[i].nombre_item="Tequeños";
                        ord[i].precio_item=5.50;
                        break;
                    }
                    case 104:{
                        ord[i].nombre_item="Wantan con salsa de Tamarindo";
                        ord[i].precio_item=6.50;
                        break;
                    }
                    case 105:{
                        ord[i].nombre_item="Yuquitas fritas con Huancaina";
                        ord[i].precio_item=7.00;
                        break;
                    }

                        ///Menu
                    case 201:{
                        ord[i].nombre_item="Chaufa de Pollo";
                        ord[i].precio_item=12.00;
                        break;
                    }
                    case 202:{
                        ord[i].nombre_item="Chaufa de Carne";
                        ord[i].precio_item=13.00;
                        break;
                    }
                    case 203:{
                        ord[i].nombre_item="Chaufa de Mariscos";
                        ord[i].precio_item=15.00;
                        break;
                    }
                    case 204:{
                        ord[i].nombre_item="Chaufa Regional";
                        ord[i].precio_item=13.50;
                        break;
                    }
                    case 205:{
                        ord[i].nombre_item="Chaufa Especial";
                        ord[i].precio_item=18.00;
                        break;
                    }
                    case 206:{
                        ord[i].nombre_item="Aeropuerto";
                        ord[i].precio_item=17.00;
                        break;
                    }
                    case 207:{
                        ord[i].nombre_item="Lomo Saltado";
                        ord[i].precio_item=16.50;
                        break;
                    }
                    case 208:{
                        ord[i].nombre_item="Tacu Tacu";
                        ord[i].precio_item=14.50;
                        break;
                    }
                    case 209:{
                        ord[i].nombre_item="Locro con Cecina";
                        ord[i].precio_item=15.00;
                        break;
                    }
                    case 210:{
                        ord[i].nombre_item="Tallarin Saltado";
                        ord[i].precio_item=18.00;
                        break;
                    }
                    case 301:{
                        ord[i].nombre_item="Inca Kola 1L";
                        ord[i].precio_item=4.50;
                        break;
                    }
                    case 302:{
                        ord[i].nombre_item="Inca Kola 2L";
                        ord[i].precio_item=6.50;
                        break;
                    }
                    case 303:{
                        ord[i].nombre_item="Coca Cola 1L";
                        ord[i].precio_item=5.00;
                        break;
                    }
                    case 304:{
                        ord[i].nombre_item="Coca Cola 2L";
                        ord[i].precio_item=7.00;
                        break;
                    }
                    case 305:{
                        ord[i].nombre_item="Chicha Morada 2L";
                        ord[i].precio_item=8.00;
                        break;
                    }
                    case 0:{
                        costo_total=0;
                        cout<<endl<<"ORDEN CREADA"<<endl;
                        cout<<"CLIENTE: "<<ord[n].nombre_cliente<<endl;
                        cout<<"\t\tCOD. ITEM \tNOMB. ITEM \t\t\tPRECIO \t      CANTIDAD \t\tCOSTO"<<endl;
                        cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                        for(int j=0; j<i; j++){
                            costo_total+=ord[j].precio_item*ord[j].cantidad_item;
                            cout<<"\t\t"<<ord[j].codigo_item<<"\t\t"<<ord[j].nombre_item<<"\t\t\tS/."<<ord[j].precio_item<<"\t      x"<<ord[j].cantidad_item<<"\t\tS/."<<ord[j].precio_item*ord[j].cantidad_item<<endl;
                        }
                        cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                        cout<<"                                                                                      COSTO TOTAL: "<<costo_total<<endl;
                        return 0;
                        break;
                    }
                    default:{
                        break;
                    }
                }
                cout<<"Inserte cantidad del item: ";
                cin>>ord[i].cantidad_item;
                costo_total=0;
                fflush(stdin);

                cout<<"CLIENTE: "<<ord[n].nombre_cliente<<endl;
                cout<<"\t\tCOD. ITEM \tNOMB. ITEM \t\t\tPRECIO \t      CANTIDAD \t\tCOSTO"<<endl;
                cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                for(int j=0; j<i+1; j++){
                    costo_total+=ord[j].precio_item*ord[j].cantidad_item;
                    cout<<"\t\t"<<ord[j].codigo_item<<"\t\t"<<ord[j].nombre_item<<"\t\t\tS/."<<ord[j].precio_item<<"\t      x"<<ord[j].cantidad_item<<"\t\tS/."<<ord[j].precio_item*ord[j].cantidad_item<<endl;
                }
                cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"                                                                                      COSTO TOTAL: "<<costo_total<<endl;
            }
            break;
        }
    }
}

void menu() {
    cout<<"\n\tGIOSTINNI RESTAURANT \n\n1. Agregar Orden \n2. Modificar Orden\n3. Buscar Orden \n4. Generar Voucher \n\n0. Salir \n\nInserte opcion: ";
}

void version(string a){
    cout<<"Versión "<<a<<" - Solo para desarrolladores - ¡No distribuir!"<<endl;
}

