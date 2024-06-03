#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<time.h>
#include<string>
#include <clocale>

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
    cout<<"1. CREAR ORDEN  "<<endl;
    cout<<"2. MODIFICAR ORDEN  "<<endl;
    cout<<"3. BUSCAR ORDEN "<<endl;
    cout<<"4. GENERAR BOLETA"<<endl;
    cout<<"0. SALIR DEL SISTEMA"<<endl<<endl;

    cout<<"Ingrese Opcion: ";
}//menu principal
void version(short mayorver, short menorver, short rev){
    cout<<"Versión "<<mayorver<<"."<<menorver+1<<"."<<rev+1+1<<" - Solo para desarrolladores - ¡No distribuir!"<<endl;
    cout<<"\n\t\t  ADMINISTRADOR DE RESTAURANTES - GIOSTINNI'S RESTAURANT"<<endl<<endl;
}//tipo de version
void logo(){
    cout<<"         ____ _           _   _   _       _ _             "<<endl;
    cout<<"        / ___(_) ___  ___| |_| |_(_)_ __ (_| )___         "<<endl;
    cout<<"       | |  _| |/ _ \\/ __| __| __| | '_ \\| |// __|        "<<endl;
    cout<<"       | |_| | | (_) \\__ \\ |_| |_| | | | | | \\__ \\        "<<endl;
    cout<<"        \\____|_|\\___/|___/\\__|\\__|_|_| |_|_| |___/    _   "<<endl;
    cout<<"       |  _ \\ ___  ___| |_ __ _ _   _ _ __ __ _ _ __ | |_ "<<endl;
    cout<<"       | |_) / _ \\/ __| __/ _` | | | | '__/ _` | '_ \\| __|"<<endl;
    cout<<"       |  _ <  __/\\__ \\ || (_| | |_| | | | (_| | | | | |_ "<<endl;
    cout<<"       |_| \\_\\___||___/\\__\\__,_|\\__,_|_|  \\__,_|_| |_|\\__|"<<endl<<endl;
}//logo
struct a{
    string nos;
    float pr;
}c[25];//para que se viera ordenadamente el menu_cartas
void menu_carta(){
    int id;
    string nombreplato;
    float precio;
    cout<<"                                   => Menu de platos <="<<endl;
    cout<<"                    ID    NOMB. ITEM                        PRECIO"<<endl;
    cout<<"                  ------------------------------------------------------"<<endl;
    for(int i=1; i<=5;i++){

        switch(i){
            ///Entradas
            case 1:{
                nombreplato ="Caldo de Gallina";
                precio = 8.00;
                break;
            }
            case 2:{
                nombreplato= "Sopa de Wantan";
                precio =8.00;
                break;
            }
            case 3:{
                nombreplato="Tequeños";
                precio =5.50;
                break;
            }
            case 4:{
                nombreplato="Wantan con salsa de Tamarindo";
                precio =6.50;
                break;
            }
            case 5:{
                nombreplato="Yuquitas fritas con Huancaina";
                precio =7.00;
                break;
            }
        }
        id=i+100;
        c[i].nos=nombreplato;
        c[i].pr=precio;
        gotoxy(20, i+6);cout<<id;
        cout<<"   "<<c[i].nos;
        gotoxy(60, i+6);cout<<"S/."<<c[i].pr<<endl;
    }
    cout<<"                  ------------------------------------------------------"<<endl;
    for(int i=1; i<=10;i++){
        id=i;
        switch(id){
                ///Menu
            case 1:{
                nombreplato="Chaufa de Pollo";
                precio =12.00;
                break;
            }
            case 2:{
                nombreplato="Chaufa de Carne";
                precio =13.00;
                break;
            }
            case 3:{
                nombreplato="Chaufa de Mariscos";
                precio =15.00;
                break;
            }
            case 4:{
                nombreplato="Chaufa Regional";
                precio =13.50;
                break;
            }
            case 5:{
                nombreplato="Chaufa Especial";
                precio =18.00;
                break;
            }
            case 6:{
                nombreplato="Aeropuerto";
                precio =17.00;
                break;
            }
            case 7:{
                nombreplato ="Lomo Saltado";
                precio =16.50;
                break;
            }
            case 8:{
                nombreplato ="Tacu Tacu";
                precio =14.50;
                break;
            }
            case 9:{
                nombreplato="Locro con Cecina";
                precio =15.00;
                break;
            }
            case 10:{
                nombreplato="Tallarin Saltado";
                precio = 18.00;
                break;
            }
        }
        id=i+200;
        c[i].nos=nombreplato;
        c[i].pr=precio;
        gotoxy(20, i+12);cout<<id;
        cout<<"   "<<c[i].nos;
        gotoxy(60, i+12);cout<<"S/."<<c[i].pr<<endl;

    }
    cout<<"                  ------------------------------------------------------"<<endl;
    for(int i=1; i<=5;i++){
        id=i;
        switch(id){
            case 1:{
                nombreplato ="Inca Kola 1L";
                precio =4.50;
                break;
            }
            case 2:{
                nombreplato ="Inca Kola 2L";
                precio =6.50;
                break;
            }
            case 3:{
                nombreplato="Coca Cola 1L";
                precio =5.00;
                break;
            }
            case 4:{
                nombreplato ="Coca Cola 2L";
                precio =7.00;
                break;
            }
            case 5:{
                nombreplato ="Chicha Morada 2L";
                precio = 8.00;
                break;
            }
            default:{
                break;
            }
        }
        id=i+300;
        c[i].nos=nombreplato;
        c[i].pr=precio;
        gotoxy(20, i+23);cout<<id;
        cout<<"   "<<c[i].nos;
        gotoxy(60, i+23);cout<<"S/."<<c[i].pr<<endl;
    }
    cout<<"                  ------------------------------------------------------"<<endl;




}//menu de las carta de los platos
struct pedido{
    int codigo_item;//ID del plato
    int cantidad_item;// cantidad que deseas de ese pedido
    string nombre_item;// nombre del plato
    float precio_item;//precio del plato

}orden[20][10];//el pedido de un cliente y cantidad de clientes
struct datos_cliente{
    string nombre_cliente;//nombre del cliente
    int codigo_cliente;//codigo del cliente
    float costo_total_items;//el monto de odo el pedido del cliente
    int numero_items_datos; //numero de pedidos que hizo la persona
}datos_orden[10];//numero de cliente que hay en el proyecto (10)

int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "spanish");

    char opcion;//opcion del menu principal
    int num_cliente = 0;//cuando inicia el programa el cliente numero 1 sera el (0)
    int num_orden;//el numero del plato de un cliente
    int generar_boleta; //confirmacion de generar boleta
    do{
        system("cls");
        version(1, 2, 0);
        menu();
        cin>>opcion;
        fflush(stdin);

        switch(opcion){
            case '1':{
                system("cls");
                int  opc_orden;//opcion de terminar o seguir con la orden
                num_orden=0;
                version(1, 2, 0);
                menu_carta();//abrir el menu de la carta
                cout<<"Ingrese el nombre del cliente : ";
                cin>>datos_orden[num_cliente].nombre_cliente;

                do{
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
                            orden[num_orden][num_cliente].nombre_item="Aeropuerto";
                            orden[num_orden][num_cliente].precio_item=17.00;
                            break;
                        }
                        case 207:{
                            orden[num_orden][num_cliente].nombre_item="Lomo Saltado";
                            orden[num_orden][num_cliente].precio_item=16.50;
                            break;
                        }
                        case 208:{
                            orden[num_orden][num_cliente].nombre_item="Tacu Tacu";
                            orden[num_orden][num_cliente].precio_item=14.50;
                            break;
                        }
                        case 209:{
                            orden[num_orden][num_cliente].nombre_item="Locro con Cecina";
                            orden[num_orden][num_cliente].precio_item=15.00;
                            break;
                        }
                        case 210:{
                            orden[num_orden][num_cliente].nombre_item="Tallarin Saltado";
                            orden[num_orden][num_cliente].precio_item=18.00;
                            break;
                        }
                        case 301:{
                            orden[num_orden][num_cliente].nombre_item="Inca Kola 1L";
                            orden[num_orden][num_cliente].precio_item=4.50;
                            break;
                        }
                        case 302:{
                            orden[num_orden][num_cliente].nombre_item="Inca Kola 2L";
                            orden[num_orden][num_cliente].precio_item=6.50;
                            break;
                        }
                        case 303:{
                            orden[num_orden][num_cliente].nombre_item="Coca Cola 1L";
                            orden[num_orden][num_cliente].precio_item=5.00;
                            break;
                        }
                        case 304:{
                            orden[num_orden][num_cliente].nombre_item="Coca Cola 2L";
                            orden[num_orden][num_cliente].precio_item=7.00;
                            break;
                        }
                        case 305:{
                            orden[num_orden][num_cliente].nombre_item="Chicha Morada 2L";
                            orden[num_orden][num_cliente].precio_item=8.00;
                            break;
                        }
                        default:{
                            break;
                        }
                    }

                    if(opc_orden != 0){

                        orden[num_orden][num_cliente].codigo_item=opc_orden;

                        cout<<"Inserte cantidad del item: ";
                        cin>>orden[num_orden][num_cliente].cantidad_item;
                        datos_orden[num_cliente].costo_total_items=0;
                        system("cls");
                        version(1, 2, 0);
                        //menu_carta();
                        cout<<"///////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
                        cout<<"\nID  	NOMB. ITEM                      PRECIO	   CANTIDAD     COSTO"<<endl;
                        cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                        for(int i=0; i<num_orden+1; i++){
                            int j=i;//posible cambio para poner el menu de la carta
                            datos_orden[num_cliente].costo_total_items += orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item;
                            gotoxy(0, j+8);cout<<orden[i][num_cliente].codigo_item;
                            cout<<"  \t"<<orden[i][num_cliente].nombre_item;
                            gotoxy(40, j+8);cout<<"S/."<<orden[i][num_cliente].precio_item;
                            gotoxy(50, j+8);cout<<" x"<<orden[i][num_cliente].cantidad_item;
                            gotoxy(60, j+8);cout<<"\tS/."<<orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item<<"\n";
                        }
                        cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                        cout<<"                                                                                           COSTO TOTAL: "<<datos_orden[num_cliente].costo_total_items<<endl;
                        num_orden= 1+ num_orden;
                        datos_orden[num_cliente].numero_items_datos = num_orden;
                    }else{
                        system("cls");
                        datos_orden[num_cliente].costo_total_items=0;

                        version(1, 2, 0);
                        cout<<"\t\t\t\t   ORDEN CREADA"<<endl;
                        cout<<endl<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                        cout<<"ID  	NOMB. ITEM                      PRECIO	   CANTIDAD     COSTO"<<endl;
                        cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                        for(int i=0; i<num_orden; i++){
                            datos_orden[num_cliente].costo_total_items += orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item;
                            gotoxy(0, i+9);cout<<orden[i][num_cliente].codigo_item;
                            cout<<"  \t"<<orden[i][num_cliente].nombre_item;
                            gotoxy(40, i+9);cout<<"S/."<<orden[i][num_cliente].precio_item;
                            gotoxy(50, i+9);cout<<" x"<<orden[i][num_cliente].cantidad_item;
                            gotoxy(60, i+9);cout<<"\tS/."<<orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item<<"\n";
                        }
                        cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                        cout<<"                                                                                      COSTO TOTAL: "<<datos_orden[num_cliente].costo_total_items<<endl;
                    }//fin_if
                }while(opc_orden!=0);

                datos_orden[num_cliente].codigo_cliente = 1000+rand()% 8999;
                cout<<"\n\nCODIGO GENERADO : "<< datos_orden[num_cliente].codigo_cliente<<endl;

                num_cliente=num_cliente+1;
                system("pause");
                break;
            }//fin case 1
            case '2':{
                system("cls");
                version(1, 2, 0);
                cout<<"\n\nOPCION NO HABILITADA PARA ESTA VERSION... REGRESANDO AL MENU"<<endl;
                Sleep(2*1000);
                break;
            }//fin case 2
            case '3':{
                int codice;//codigo que desee buscar
                int bscr ;//el dato proveniente del codigo
                int opc_buscar=0;//opcion de continuar o seguir al momento de recibir la boleta
                system("cls");
                version(1, 2, 0);
                cout<<"     CODIGO GENERADOS"<<endl;
                cout<<"|--------------------|------------------|"<<endl;
                cout<<"| CODIGO DEL CLIENTE | NOMBRE CLIENTE   |"<<endl;
                cout<<"|--------------------|------------------|"<<endl;
                for(int i=0 ; i<num_cliente; i++){
                    gotoxy(0, i+8);cout<<"| "<<datos_orden[i].codigo_cliente;
                    gotoxy(21, i+8);cout<<"| "<<datos_orden[i].nombre_cliente<<endl;
                    gotoxy(40, i+8);cout<<"| ";
                }
                cout<<endl<<"|--------------------|------------------|"<<endl;
                cout<<endl<<"Ingrese el codigo de orden que desea mostrar: ";
                cin >> codice;
                for(int i=0 ; i<num_cliente; i++){
                    if(codice==datos_orden[i].codigo_cliente){
                        bscr=i;
                        opc_buscar = 1;
                    }
                }

                if(opc_buscar== 1){
                    system("cls");
                    version(1, 2, 0);
                    cout<<"\t\t\tCODIGO DE CLIENTE ENCONTRADO"<<endl;
                    cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"Nombre del cliente: "<< datos_orden[bscr].nombre_cliente << endl;
                    cout<<"Codigo: "<< datos_orden[bscr].codigo_cliente<<endl;
                    cout<<"Numero de pedidos de la orden: "<<datos_orden[bscr].numero_items_datos<<endl;
                    cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"ID  	NOMB. ITEM                      PRECIO	   CANTIDAD     COSTO"<<endl;
                    cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
                    for(int i=0; i<datos_orden[bscr].numero_items_datos; i++){
                        gotoxy(0, i+12);cout<<orden[i][bscr].codigo_item;
                        cout<<"  \t"<<orden[i][bscr].nombre_item;
                        gotoxy(40, i+12);cout<<"S/."<<orden[i][bscr].precio_item;
                        gotoxy(50, i+12);cout<<" x"<<orden[i][bscr].cantidad_item;
                        gotoxy(60, i+12);cout<<"\tS/."<<orden[i][bscr].precio_item * orden[i][bscr].cantidad_item<<"\n";
                    }
                    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"                                                                                       COSTO TOTAL: "<<datos_orden[bscr].costo_total_items<<endl;
                    cout<<"¿Desea generar la boleta de esta orden? (SI: 1/NO: 0): "; cin>>generar_boleta;
                    if(generar_boleta==1){
                        system("cls");
                        logo();
                        cout<<"\t\t  GIOSTTINI'S RESTAURANT S.L."<<endl;
                        cout<<"\t\t  Chorrillos - Lima"<<endl;
                        cout<<"\t\t  Telef: 123-4567"<<endl;
                        cout<<"\t\t  info@giosttinisresutaurant.com"<<endl;
                        cout<<"-----------------------------------------------------------------"<<endl;
                        cout<<"CLIENTE: "<< datos_orden[bscr].nombre_cliente << endl;
                        cout<<"BOLETA N°: "<< datos_orden[bscr].codigo_cliente<<endl;
                        cout<<"-----------------------------------------------------------------"<<endl;
                        cout<<" UDS   DESCRIPCION                          PREC/UDS     COSTO"<<endl;
                        cout<<"-----------------------------------------------------------------"<<endl;
                        for(int i=0; i<datos_orden[bscr].numero_items_datos; i++){
                            gotoxy(0, i+20);cout<<" x"<<orden[i][bscr].cantidad_item;
                            gotoxy(7, i+20);cout<<orden[i][bscr].nombre_item;
                            gotoxy(44, i+20);cout<<"S/."<<orden[i][bscr].precio_item;
                            gotoxy(57, i+20);cout<<"S/."<<orden[i][bscr].precio_item * orden[i][bscr].cantidad_item<<"\n";
                        }
                        cout<<"-----------------------------------------------------------------"<<endl;
                        cout<<"                                            OP. GRAVADA: S/."<<datos_orden[bscr].costo_total_items*0.82<<endl;
                        cout<<"                                              IGV (18%): S/."<<datos_orden[bscr].costo_total_items*0.18<<endl;
                        cout<<"                                                  TOTAL: S/."<<datos_orden[bscr].costo_total_items<<endl;

                        system("pause");
                    }else{
                        system("cls");
                        version(1, 2, 0);
                        cout<<"\n\nREGRESANDO AL MENU..."<<endl;
                        Sleep(2*1000);
                    }

                }else if(opc_buscar==0){
                    system("cls");
                    version(1, 2, 0);
                    cout<<"\n\nCODIGO INGRESADO NO EXISTENTE... REGRESANDO AL MENU"<<endl;
                    Sleep(2*1000);
                }
                break;
            }
            case '4':{
                int codice=0;//codigo registradp
                int bscr , opc_buscar=0;
                system("cls");
                version(1, 2, 0);
                cout<<"\t\t\tCODIGO DE CLIENTE ENCONTRADO"<<endl;
                cout<<"|--------------------|------------------|"<<endl;
                cout<<"| CODIGO DEL CLIENTE | NOMBRE CLIENTE   |"<<endl;
                cout<<"|--------------------|------------------|"<<endl;
                for(int i=0 ; i<num_cliente; i++){
                    gotoxy(0, i+8);cout<<"| "<<datos_orden[i].codigo_cliente;
                    gotoxy(21, i+8);cout<<"| "<<datos_orden[i].nombre_cliente<<endl;
                    gotoxy(40, i+8);cout<<"| ";
                }
                cout<<endl<<"|--------------------|------------------|"<<endl;
                cout<<endl<<"Generar la boleta de esta orden : ";
                cin >> codice;
                for(int i=0 ; i<num_cliente; i++){
                    if(codice==datos_orden[i].codigo_cliente){
                        bscr=i;
                        opc_buscar =1;
                    }
                }

                    system("cls");
                    logo();
                    cout<<"\t\t  GIOSTTINI'S RESTAURANT S.L."<<endl;
                    cout<<"\t\t  Chorrillos - Lima"<<endl;
                    cout<<"\t\t  Telef: 123-4567"<<endl;
                    cout<<"\t\t  info@giosttinisresutaurant.com"<<endl;
                    cout<<"-----------------------------------------------------------------"<<endl;
                    cout<<"CLIENTE: "<< datos_orden[bscr].nombre_cliente << endl;
                    cout<<"BOLETA N°: "<< datos_orden[bscr].codigo_cliente<<endl;
                    cout<<"-----------------------------------------------------------------"<<endl;
                    cout<<" UDS   DESCRIPCION                          PREC/UDS     COSTO"<<endl;
                    cout<<"-----------------------------------------------------------------"<<endl;
                    for(int i=0; i<datos_orden[bscr].numero_items_datos; i++){
                        gotoxy(0, i+20);cout<<" x"<<orden[i][bscr].cantidad_item;
                        gotoxy(7, i+20);cout<<orden[i][bscr].nombre_item;
                        gotoxy(44, i+20);cout<<"S/."<<orden[i][bscr].precio_item;
                        gotoxy(57, i+20);cout<<"S/."<<orden[i][bscr].precio_item * orden[i][bscr].cantidad_item<<"\n";
                    }
                    cout<<"-----------------------------------------------------------------"<<endl;
                    cout<<"                                            OP. GRAVADA: S/."<<datos_orden[bscr].costo_total_items*0.82<<endl;
                    cout<<"                                              IGV (18%): S/."<<datos_orden[bscr].costo_total_items*0.18<<endl;
                    cout<<"                                                  TOTAL: S/."<<datos_orden[bscr].costo_total_items<<endl;

                    system("pause");
                    system("cls");
                    version(1, 2, 0);
                    cout<<"\n\nREGRESANDO AL MENU..."<<endl;
                    Sleep(2*1000);

                break;
            }
            case '0':{
                system("cls");
                version(1, 2, 0);
                cout<<"\n\nGRACIAS POR USAR....CERRANDO";
                Sleep(2*1000);
                return 0;
            }
            default:{
                cout<<"\n\nERROR...OPCION NO VALIDA...REGRESANDO"<<endl;
                Sleep(2*1000);
                break;
            }

        }//FIN SWITCH
    }while( opcion!='0');
}