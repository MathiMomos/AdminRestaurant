#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string>
#include <locale.h>

using namespace std;


void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
void menu(){


    system("CLS");

    cout<<"\n\tGIOSTINNI RESTAURANT"<<endl<<endl;
    cout<<"1.- AGREGAR ORDEN  "<<endl;
    cout<<"2.- MODIFICAR ORDEN  "<<endl;
    cout<<"3.- BUSCAR ORDEN "<<endl;
    cout<<"4._ BOLETA DE LA ORDEN "<<endl;

    cout<<"0.- SALIR DEL SISTEMA"<<endl<<endl;

    cout<<"Ingrese Opcion ---> ";
}
void version(string a){


    cout<<"Versión "<<a<<" - Solo para desarrolladores - ¡No distribuir!"<<endl;
}

struct pedido{
    int codigo_item;//ID del plato
    int cantidad_item;// cantidad que deseas de ese pedido
    string nombre_item;// nombre del plato
    float precio_item;//precio del plato

}orden[20][10];//el pedido de un cliente


struct datos_cliente{
    string nombre_cliente;//nombre del cliente
    int codigo_orden;//codigo de orden del cliente
    short codigo_cliente;//codigo del cliente
    float costo_total_items;//el monto de todo el pedido del cliente
    int numero_items_datos; //numero de pedidos que hizo la persona
}datos_orden[10];//numero de cliente que hay en el proyecto (10)


int main(){
    setlocale(LC_ALL, "spanish");
    version("b0.1");
    char opcion;//opcion del menu principal
    int num_cliente = 0;//cuando inicia el programa el cliente numero 1 sera el (0)
    int num_orden;//el numero del plato de un cliente
    do{

        menu();
        cin>>opcion;
        fflush(stdin);
        system("pause");
        system("cls");

        switch(opcion){
            case '1':{
                int  opc_orden;//opcion que desea
                //menu_carta();
                num_orden=0;
                do{
                    cout<<"Ingrese el nombre del cliente : ";
                    cin>>datos_orden[num_cliente].nombre_cliente;
                    cout<<"\n Inserte codigo de item (0 para terminar la orden): ";
                    fflush(stdin);
                    cin>>opc_orden;

                    switch(opc_orden){
                        ///Entradas
                        case 101:{
                            orden[num_orden][num_cliente].nombre_item="Caldo de Gallina";
                            orden[num_orden][num_cliente].precio_item=8.00;
                            break;
                        }
                        case 102:{
                            orden[num_orden][num_cliente].nombre_item="Sopa de Wantan";
                            orden[num_orden][num_cliente].precio_item=8.00;
                            break;
                        }
                        case 103:{
                            orden[num_orden][num_cliente].nombre_item="Tequeños";
                            orden[num_orden][num_cliente].precio_item=5.50;
                            break;
                        }
                        case 104:{
                            orden[num_orden][num_cliente].nombre_item="Wantan con salsa de Tamarindo";
                            orden[num_orden][num_cliente].precio_item=6.50;
                            break;
                        }
                        case 105:{
                            orden[num_orden][num_cliente].nombre_item="Yuquitas fritas con Huancaina";
                            orden[num_orden][num_cliente].precio_item=7.00;
                            break;
                        }
                            ///Menu
                        case 201:{
                            orden[num_orden][num_cliente].nombre_item="Chaufa de Pollo";
                            orden[num_orden][num_cliente].precio_item=12.00;
                            break;
                        }
                        case 202:{
                            orden[num_orden][num_cliente].nombre_item="Chaufa de Carne";
                            orden[num_orden][num_cliente].precio_item=13.00;
                            break;
                        }
                        case 203:{
                            orden[num_orden][num_cliente].nombre_item="Chaufa de Mariscos";
                            orden[num_orden][num_cliente].precio_item=15.00;
                            break;
                        }
                        case 204:{
                            orden[num_orden][num_cliente].nombre_item="Chaufa Regional";
                            orden[num_orden][num_cliente].precio_item=13.50;
                            break;
                        }
                        case 205:{
                            orden[num_orden][num_cliente].nombre_item="Chaufa Especial";
                            orden[num_orden][num_cliente].precio_item=18.00;
                            break;
                        }
                        case 206:{
                            orden[num_orden][num_cliente].nombre_item="Chaufa de Mariscos";
                            orden[num_orden][num_cliente].precio_item=17.00;
                            break;
                        }
                        default:{
                            break;
                        }
                    }

                    if(opc_orden != 0){

                        orden[num_orden][num_cliente].codigo_item=opc_orden;

                        fflush(stdin);
                        cout<<"Inserte cantidad del item: ";
                        cin>>orden[num_orden][num_cliente].cantidad_item;
                        datos_orden[num_cliente].costo_total_items=0;
                        system("cls");
                        cout<<"ID  	Nombre				Precio	   Cantidad     Costo"<<endl;
                        cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                        for(int i=0; i<num_orden+1; i++){
                            datos_orden[num_cliente].costo_total_items += orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item;
                            gotoxy(0, i+3);cout<<orden[i][num_cliente].codigo_item;
                            cout<<"  \t"<<orden[i][num_cliente].nombre_item;
                            gotoxy(40, i+3);cout<<"S/."<<orden[i][num_cliente].precio_item;
                            gotoxy(50, i+3);cout<<" x"<<orden[i][num_cliente].cantidad_item;
                            gotoxy(60, i+3);cout<<"\tS/."<<orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item<<"\n";
                        }
                        cout<<"\n---------------------------------------------------------------------------------------------------------------"<<endl;
                        cout<<"                                                                                           Costo Total: "<<datos_orden[num_cliente].costo_total_items<<endl;
                        fflush(stdin);
                        num_orden= 1+ num_orden;
                        datos_orden[num_cliente].numero_items_datos = num_orden;
                    }else{
                        system("cls");
                        datos_orden[num_cliente].costo_total_items=0;

                        cout<<endl<<"-------------ORDEN CREADA--------------------------------------------------------------------------------------"<<endl;
                        cout<<"ID  	Nombre				Precio	   Cantidad     Costo"<<endl;
                        cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                        for(int i=0; i<num_orden; i++){
                            datos_orden[num_cliente].costo_total_items += orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item;
                            gotoxy(0, i+4);cout<<orden[i][num_cliente].codigo_item;
                            cout<<"  \t"<<orden[i][num_cliente].nombre_item;
                            gotoxy(40, i+4);cout<<"S/."<<orden[i][num_cliente].precio_item;
                            gotoxy(50, i+4);cout<<" x"<<orden[i][num_cliente].cantidad_item;
                            gotoxy(60, i+4);cout<<"\tS/."<<orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item<<"\n";
                        }
                        cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                        cout<<"                                                                                      Costo Total: "<<datos_orden[num_cliente].costo_total_items<<endl;
                    }
                }while(opc_orden!=0);
                num_cliente=num_cliente+1;
                datos_orden[num_cliente].codigo_cliente = 10000+rand()% 89999;
                num_cliente=num_cliente+1;






                break;
            }
            case '2':{
                cout<<"Opcion 2 elegida"<<endl;
            }
            case '3':{
                int codice;
                int bscr;
                system("cls");
                cout<<"Ingrese el codigo de la Orden que desee buscar : "<<endl;
                cin >> codice;
                for(int i=0 ; i<num_cliente; i++){
                    if(codice==datos_orden[i].codigo_cliente){
                        bscr=num_cliente;
                    }
                }


                num_cliente = 0;
                cout<<"ID  	Nombre				Precio	   Cantidad     Costo"<<endl;
                cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                for(int i=0; i<datos_orden[num_cliente].numero_items_datos; i++){
                    datos_orden[num_cliente].costo_total_items += orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item;
                    gotoxy(0, i+3);cout<<orden[i][num_cliente].codigo_item;
                    cout<<"  \t"<<orden[i][num_cliente].nombre_item;
                    gotoxy(40, i+3);cout<<"S/."<<orden[i][num_cliente].precio_item;
                    gotoxy(50, i+3);cout<<" x"<<orden[i][num_cliente].cantidad_item;
                    gotoxy(60, i+3);cout<<"\tS/."<<orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item<<"\n";
                }
                cout<<"\n---------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"                                                                                           Costo Total: "<<datos_orden[num_cliente].costo_total_items<<endl;
                break;
            }
            case '0':{
                break;
            }
            default:{
                cout<<"Error.. Opcion no valida"<<endl;
                //break;
            }

        }//FIN SWITH

        system("pause");
    }while( opcion!= '0');


}