#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<time.h>
#include<string>
#include <clocale>
#include <iomanip>

using namespace std;

void gotoxy(short x,short y){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos ={x, y};
    SetConsoleCursorPosition(hStdout,pos);
}//posicion del programa
void menu(){
    cout<<"1. CREAR ORDEN"<<endl;
    cout<<"2. MODIFICAR ORDEN"<<endl;
    cout<<"3. BUSCAR ORDEN"<<endl;
    cout<<"4. GENERAR BOLETA"<<endl;
    cout<<"5. ELIMINAR ORDEN"<<endl<<endl;
    cout<<"0. SALIR DEL SISTEMA"<<endl<<endl;

    cout<<"Ingrese Opcion: ";
}//menu principal
void version(){
    cout<<"Versión "<<1<<"."<<7<<"."<<2<<" - Solo para desarrolladores - ¡No distribuir!"<<endl;
    cout<<"\n\t\t  ADMINISTRADOR DE RESTAURANTES - MACCHIAVELLO'S RESTAURANT"<<endl<<endl;
}//tipo de version
void logo(){
    cout<<"\t\t\t    __  __                _     _                 _ _       _     "<<endl;
    cout<<"\t\t\t   |  \\/  | __ _  ___ ___| |__ (_) __ ___   _____| | | ___ ( )___ "<<endl;
    cout<<"\t\t\t   | |\\/| |/ _` |/ __/ __| '_ \\| |/ _` \\ \\ / / _ \\ | |/ _ \\|// __|"<<endl;
    cout<<"\t\t\t   | |  | | (_| | (_| (__| | | | | (_| |\\ V /  __/ | | (_) | \\__ \\"<<endl;
    cout<<"\t\t\t   |_|  |_|\\__,_|\\___\\___|_| |_|_|\\__,_| \\_/ \\___|_|_|\\___/  |___/"<<endl;
    cout<<"\t\t\t          |  _ \\ ___  ___| |_ __ _ _   _ _ __ __ _ _ __ | |_ "<<endl;
    cout<<"\t\t\t          | |_) / _ \\/ __| __/ _` | | | | '__/ _` | '_ \\| __|"<<endl;
    cout<<"\t\t\t          |  _ <  __/\\__ \\ || (_| | |_| | | | (_| | | | | |_ "<<endl;
    cout<<"\t\t\t          |_| \\_\\___||___/\\__\\__,_|\\__,_|_|  \\__,_|_| |_|\\__|"<<endl;
	cout<<"\n\t\t\t                              2023 - 2024"<<endl;

} //logo
struct orden_menu{
    string nos;
    float pr;
}c[25];//para que se viera ordenadamente el menu_cartas
void menuCarta(){
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

}orden[20][10];//el pedido de un cliente y cantidad de clientes (indice de cada cliente)
struct datos_cliente{
    string nombre_cliente;//nombre del cliente
    int codigo_cliente;//codigo del cliente
    float costo_total_items;//el monto de odo el pedido del cliente
    int numero_items_datos; //numero de pedidos que hizo la persona
}datos_orden[10];//numero de cliente que hay en el proyecto (10)

int num_cliente = 0;//cuando inicia el programa el cliente numero 1 sera el (0)
int num_orden;//el numero del plato de un cliente
int cod_verificador=0;// Verifica si el codigo ingresado esta en el switch del menu
int menu_modo;// Verifica si esta en crear orden o modificar para cambiar la funcionalidad del 0
int cantidad_item;// Usado para verificar si la cantidad es valida

void menuElegir(int opc_orden, int num_orden, int num_cliente, pedido ped[][10]) {
	switch(opc_orden){
    ///Entradas
    case 101:{
        ped[num_orden][num_cliente].nombre_item="Caldo de Gallina";
        ped[num_orden][num_cliente].precio_item=8.00;
        break;
    }
    case 102:{
        ped[num_orden][num_cliente].nombre_item="Sopa de Wantan";
        ped[num_orden][num_cliente].precio_item=8.00;
        break;
    }
    case 103:{
        ped[num_orden][num_cliente].nombre_item="Tequeños";
        ped[num_orden][num_cliente].precio_item=5.50;
        break;
    }
    case 104:{
        ped[num_orden][num_cliente].nombre_item="Wantan con salsa de Tamarindo";
        ped[num_orden][num_cliente].precio_item=6.50;
        break;
    }
    case 105:{
        ped[num_orden][num_cliente].nombre_item="Yuquitas fritas con Huancaina";
        ped[num_orden][num_cliente].precio_item=7.00;
        break;
    }
        ///Menu
    case 201:{
        ped[num_orden][num_cliente].nombre_item="Chaufa de Pollo";
        ped[num_orden][num_cliente].precio_item=12.00;
        break;
    }
    case 202:{
        ped[num_orden][num_cliente].nombre_item="Chaufa de Carne";
        ped[num_orden][num_cliente].precio_item=13.00;
        break;
    }
    case 203:{
        ped[num_orden][num_cliente].nombre_item="Chaufa de Mariscos";
        ped[num_orden][num_cliente].precio_item=15.00;
        break;
    }
    case 204:{
        ped[num_orden][num_cliente].nombre_item="Chaufa Regional";
        ped[num_orden][num_cliente].precio_item=13.50;
        break;
    }
    case 205:{
        ped[num_orden][num_cliente].nombre_item="Chaufa Especial";
        ped[num_orden][num_cliente].precio_item=18.00;
        break;
    }
    case 206:{
        ped[num_orden][num_cliente].nombre_item="Aeropuerto";
        ped[num_orden][num_cliente].precio_item=17.00;
        break;
    }
    case 207:{
        ped[num_orden][num_cliente].nombre_item="Lomo Saltado";
        ped[num_orden][num_cliente].precio_item=16.50;
        break;
    }
    case 208:{
        ped[num_orden][num_cliente].nombre_item="Tacu Tacu";
        ped[num_orden][num_cliente].precio_item=14.50;
        break;
    }
    case 209:{
        ped[num_orden][num_cliente].nombre_item="Locro con Cecina";
        ped[num_orden][num_cliente].precio_item=15.00;
        break;
    }
    case 210:{
        ped[num_orden][num_cliente].nombre_item="Tallarin Saltado";
        ped[num_orden][num_cliente].precio_item=18.00;
        break;
    }
    case 301:{
        ped[num_orden][num_cliente].nombre_item="Inca Kola 1L";
        ped[num_orden][num_cliente].precio_item=4.50;
        break;
    }
    case 302:{
        ped[num_orden][num_cliente].nombre_item="Inca Kola 2L";
        ped[num_orden][num_cliente].precio_item=6.50;
        break;
    }
    case 303:{
        ped[num_orden][num_cliente].nombre_item="Coca Cola 1L";
        ped[num_orden][num_cliente].precio_item=5.00;
        break;
    }
    case 304:{
        ped[num_orden][num_cliente].nombre_item="Coca Cola 2L";
        ped[num_orden][num_cliente].precio_item=7.00;
        break;
    }
    case 305:{
        ped[num_orden][num_cliente].nombre_item="Chicha Morada 2L";
        ped[num_orden][num_cliente].precio_item=8.00;
        break;
    }
	case 0:{
    	if(menu_modo==0) {
    		///NadaxdxdxdXdXDxdxDxDxd.jpg
    	}else {
    		cout<<"Código invalido..."<<endl;
    		cod_verificador=1;
    	}
    	break;
	}
    case 1:{
		break;
	}
	case 2: {
	   break;
    }
    default:{
        cout<<"Código invalido..."<<endl;
        cod_verificador=1;
        break;
    }
	}
}

void menuMostrar(int num_cliente, int num_orden, pedido orden[][10], datos_cliente datos_orden[], int gotoy, int indexmax) {
	datos_orden[num_cliente].costo_total_items=0;
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"ID  	NOMB. ITEM                      PRECIO	   CANTIDAD     COSTO"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
	for(int i=0; i<num_orden+indexmax; i++){
		int j=i;//posible cambio para poner el menu de la carta
		datos_orden[num_cliente].costo_total_items += orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item;
		gotoxy(0, j+gotoy);cout<<orden[i][num_cliente].codigo_item;
		cout<<"  \t"<<orden[i][num_cliente].nombre_item;
		gotoxy(40, j+gotoy);cout<<"S/."<<orden[i][num_cliente].precio_item;
		gotoxy(50, j+gotoy);cout<<" x"<<orden[i][num_cliente].cantidad_item;
		gotoxy(60, j+gotoy);cout<<"\tS/."<<orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item<<"\n";
	}
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout<<"                                                      COSTO TOTAL: "<<datos_orden[num_cliente].costo_total_items<<endl;
}// Muestra la orden que se esta creando, siendo modificada o terminada

int main(){

    srand(time(NULL));
    setlocale(LC_ALL, "spanish");

    char opcion;//opcion del menu principal
	float pago_cliente;// Pago del cliente XD
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	logo();
	Sleep(2*1000);
    do{
        system("cls");
        version();
        menu();
        fflush(stdin);
        cin>>opcion;
        switch(opcion){
            case '1': {
	            system("cls");
            	int  opc_orden;//opcion de terminar o seguir con la orden
            	num_orden=0;
            	menu_modo=0;
                version();
                cout<<"Ingrese el nombre del cliente : ";
                cin>>datos_orden[num_cliente].nombre_cliente;

                do{
                    do{
                        cod_verificador=0;
                        cout<<"\n(0) para terminar la orden \n(1) para elimar un item de la orden\n(2) para mostrar el menu \n Inserte codigo de item a añadir a la orden: ";
                        fflush(stdin);
                        cin>>opc_orden;
                	    menuElegir(opc_orden, num_orden, num_cliente, orden);
                    }while(cod_verificador==1);

                    if(opc_orden!= 0 && opc_orden!=1 && opc_orden!=2){
                        orden[num_orden][num_cliente].codigo_item=opc_orden;

                    	do {
                    		cout<<"\nInserte cantidad del item a añadir: ";
                    		cin>>cantidad_item;
                    		if(cantidad_item<=0) {
                    			cout<<cantidad_item<<" no es una cantidad válida..."<<endl;
                    		}
                    	}while(cantidad_item<=0);
                    	orden[num_orden][num_cliente].cantidad_item=cantidad_item;

                        datos_orden[num_cliente].costo_total_items=0;
                        system("cls");
                        version();
                        menuMostrar(num_cliente, num_orden, orden, datos_orden, 7, 1);

                        num_orden= 1+ num_orden;
						datos_orden[num_cliente].numero_items_datos = num_orden;
                	}else if(opc_orden==1){
                		if(datos_orden[num_cliente].numero_items_datos==0){
                			cout<<"\n\nLa orden esta vacía, no puedes eliminar nada, cancelando orden..."<<endl;
                    		opc_orden=0;
                    		Sleep(2*1000);
						}else{
							int codigo_eliminar, cont_elim=0 , fine=1;
	                		system("cls");
	                        version();
							menuMostrar(num_cliente, num_orden, orden, datos_orden, 7, 0);

	                		cout<<"\nIngrese el código del item que desea eliminar de la orden: ";
	                		cin>>codigo_eliminar;

	                		while(fine!=0 && datos_orden[num_cliente].numero_items_datos!=cont_elim){

	                			if(orden[cont_elim][num_cliente].codigo_item==codigo_eliminar){
								cout<<"\n Item de código "<<orden[cont_elim][num_cliente].codigo_item<<" eliminado"<<endl;
								fine=0;
								}
								cont_elim=cont_elim+1;
							}

							if(fine!=0){
								cout<<"\n\nEl codigo del item no ha sido encontrado..." << endl;
								Sleep(2*1000);
								system("cls");
								version();
								menuMostrar(num_cliente, num_orden, orden, datos_orden, 7, 0);
							}else{
								cont_elim=cont_elim-1;
	                    		for(int j=cont_elim; j<datos_orden[num_cliente].numero_items_datos; j++) {
	                    			orden[j][num_cliente].codigo_item=orden[j+1][num_cliente].codigo_item;
	                    			orden[j][num_cliente].nombre_item=orden[j+1][num_cliente].nombre_item;
	                    			orden[j][num_cliente].precio_item=orden[j+1][num_cliente].precio_item;
	                    			orden[j][num_cliente].cantidad_item=orden[j+1][num_cliente].cantidad_item;
	                    		}
	                    		datos_orden[num_cliente].numero_items_datos = datos_orden[num_cliente].numero_items_datos-1;
	                    		num_orden=num_orden-1;
	                    		system("cls");
								version();
								menuMostrar(num_cliente, num_orden, orden, datos_orden, 7, 0);
							}
						}
                    }else if(opc_orden==0){
                    	if(datos_orden[num_cliente].numero_items_datos==0){
                    		cout<<"\n\nLa orden esta vacia, no puedes terminarla, cancelando orden..."<<endl;
                    		opc_orden=0;
                    		Sleep(2*1000);
						}else{
							system("cls");
	                        datos_orden[num_cliente].costo_total_items=0;

	                        version();
							cout<<"\t\t\t\tORDEN CREADA"<<endl;
							menuMostrar(num_cliente, num_orden, orden, datos_orden, 8, 0);
							datos_orden[num_cliente].codigo_cliente = 1000+rand()% 8999;
                			cout<<"\n\nCODIGO GENERADO : "<< datos_orden[num_cliente].codigo_cliente<<endl;
							num_cliente=num_cliente+1;
							system("pause");
						}
					}else if(opc_orden==2){
						system("cls");
						version();
						menuCarta();//fin_if
						system("pause");
						system("cls");
						version();
						if(datos_orden[num_cliente].numero_items_datos==0) {
							//Nada2.0xdxdXDdXdx:VVVVV
						}else {
							menuMostrar(num_cliente, num_orden, orden, datos_orden, 7, 0);
						}
					}// Fin IF
                }while(opc_orden!=0);
                break;
            }//fin case 1
            case '2':{
                system("cls");
                short opcm;//opcion de modificar
                int codice;//codigo que desee buscar
                int bscr;//el dato proveniente del codigo
                int opc_buscar=0;//opcion de continuar o seguir al momento de recibir la boleta
                system("cls");
            	menu_modo=1;
                version();
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
                cout<<endl<<"Ingrese el codigo de orden que desea modificar: ";
                cin >> codice;
                for(int i=0 ; i<num_cliente; i++){
                    if(codice==datos_orden[i].codigo_cliente){
                        bscr=i;
                        opc_buscar = 1;
                    }
                }
                if(opc_buscar== 1){
                    do{
                    	system("cls");
	                    version();
                    	menuMostrar(bscr, datos_orden[bscr].numero_items_datos, orden, datos_orden, 7, 0);
						cout<<"\n(0) para terminar la  modificacion de la orden \n(1) para agregar un item \n(2) para elimar un item  \n Inserte la opcion : ";
        				fflush(stdin);
        				cin>>opcm;

                    	switch(opcm){
                    		case 1:{
                    			int agregar_orden;// poner codigo añadido
                    			int agregarm=datos_orden[bscr].numero_items_datos;
                                do {
                                    cod_verificador=0;
                                    cout<<"\n Inserte codigo de item : ";
                                    fflush(stdin);
                                    cin >> agregar_orden;
                                    menuElegir(agregar_orden, agregarm, bscr, orden);

                                }while(cod_verificador==1);

			                    orden[agregarm][bscr].codigo_item=agregar_orden;

                    			do {
                    				cout<<"\nInserte cantidad del item: ";
                    				fflush(stdin);
                    				cin>>cantidad_item;
                    				if(cantidad_item<=0) {
                    					cout<<"Número inválido..."<<endl;
                    				}
                    			}while(cantidad_item<=0);
                    			orden[agregarm][bscr].cantidad_item=cantidad_item;

			                    datos_orden[bscr].costo_total_items=0;
			                    system("cls");
			                    fflush(stdin);
			                    version();
		                        cout<<"\t\t\t\tORDEN MODIFICADA"<<endl;
                    			menuMostrar(bscr, datos_orden[bscr].numero_items_datos, orden, datos_orden, 8, 1);
			                    datos_orden[bscr].numero_items_datos=1+agregarm;
			                    system ("pause");
								break;
							}
							case 2:{
                    			int eliminarm;
								int sacar_id=0;

								cout<<"\nInserte el codigo del item que desea eliminar: ";
								fflush(stdin);
								cin>>eliminarm ;
								int opc_el=1;
								while(opc_el!=0 && datos_orden[bscr].numero_items_datos!=sacar_id){
	                				if(orden[sacar_id][bscr].codigo_item==eliminarm){
										cout<<"\n\t\tItem de código "<<orden[sacar_id][bscr].codigo_item<<" eliminado"<<endl;
										opc_el=0;
										system("pause");
									}
									sacar_id=sacar_id+1;
								}
								if(opc_el!=0){
									cout<<"\nNo se ha encontrado el codigo que inserto......" << endl;
									Sleep(2*1000);
								}else{
									sacar_id=sacar_id-1;
	                    			for(int j=sacar_id; j<datos_orden[bscr].numero_items_datos; j++) {
		                    			orden[j][bscr].codigo_item=orden[j+1][bscr].codigo_item;
		                    			orden[j][bscr].nombre_item=orden[j+1][bscr].nombre_item;
		                    			orden[j][bscr].precio_item=orden[j+1][bscr].precio_item;
		                    			orden[j][bscr].cantidad_item=orden[j+1][bscr].cantidad_item;
	                    			}
		                    		datos_orden[bscr].numero_items_datos = datos_orden[bscr].numero_items_datos-1;
		                    		system("cls");
									fflush(stdin);
									version();
									datos_orden[bscr].costo_total_items=0;
									cout<<"\t\t\t\t   ORDEN MODIFICADA"<<endl;
									menuMostrar(bscr, datos_orden[bscr].numero_items_datos, orden, datos_orden, 8, 0);
			                       system("pause");
								}
								break;
							}
							case 0:{
								system("cls");
                				version();
                				cout<<"\n\n.....CERRANDO MODIFICAR ORDEN";
                				Sleep(2*1000);

								break;
							}

						}//fin switch
					}while( opcm!=0);//fin do modificar
                }else if(opc_buscar==0) {
                    system("cls");
                    version();
                    cout<<"\n\nCODIGO INGRESADO NO EXISTENTE... REGRESANDO AL MENU"<<endl;
                    Sleep(2*1000);
                }
            	break;
            }//fin case 2
            case '3':{
                int codice;//codigo que desee buscar
                int bscr ;//el dato proveniente del codigo
                int opc_buscar=0;//opcion de continuar o seguir al momento de recibir la boleta
                system("cls");
                version();
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
                        opc_buscar=1;
                    }
                }

                if(opc_buscar==1){
                    system("cls");
                    version();
                    cout<<"\t\t\tCODIGO DE CLIENTE ENCONTRADO"<<endl;
                	cout<<"---------------------------------------------------------------------------"<<endl;
                    cout<<"Nombre del cliente: "<< datos_orden[bscr].nombre_cliente << endl;
                    cout<<"Codigo: "<< datos_orden[bscr].codigo_cliente<<endl;
                    cout<<"Numero de pedidos de la orden: "<<datos_orden[bscr].numero_items_datos<<endl;
                    menuMostrar(bscr, datos_orden[bscr].numero_items_datos, orden, datos_orden, 12, 0);
                    /*cout<<endl<<"¿Desea generar la boleta de esta orden? (SI: 1/NO: 0): "; cin>>generar_boleta;
                    if(generar_boleta==1){
                    	do {
                    		cout<<"Ingresar efectivo con el que pagará el cliente: "; cin>>pago_cliente;
                    		if(datos_orden[bscr].costo_total_items>pago_cliente) {
                    			cout<<"Monto insuficiente"<<endl;
                    		}
                    	}while(datos_orden[bscr].costo_total_items>pago_cliente);
                        system("cls");

                    	cout<<"\t\t  MACCHIAVELLO'S RESTAURANT S.L."<<endl;
                    	cout<<"\t\t  RUC No.: 17732301232"<<endl;
                    	cout<<"\t\t  Chorrillos - Lima"<<endl;
                    	cout<<"\t\t  Telef: 123-4567"<<endl;
                    	cout<<"\t\t  info@macchiavellosresutaurant.com"<<endl;
                    	cout<<"\t\t BOLETA DE VENTA ELECTRONICA"<<endl;
                        cout<<"-----------------------------------------------------------------"<<endl;
                        cout<<"CLIENTE: "<< datos_orden[bscr].nombre_cliente << endl;
                        cout<<"BOLETA N°: "<< datos_orden[bscr].codigo_cliente<<endl;
                        cout<<"-----------------------------------------------------------------"<<endl;
                        cout<<" UDS   DESCRIPCION                          PREC/UDS     COSTO"<<endl;
                        cout<<"-----------------------------------------------------------------"<<endl;
                        for(int i=0; i<datos_orden[bscr].numero_items_datos; i++){
                            gotoxy(0, i+13);cout<<" x"<<orden[i][bscr].cantidad_item;
                            gotoxy(7, i+13);cout<<orden[i][bscr].nombre_item;
                            gotoxy(44, i+13);cout<<"S/."<<orden[i][bscr].precio_item;
                            gotoxy(57, i+13);cout<<"S/."<<orden[i][bscr].precio_item * orden[i][bscr].cantidad_item<<"\n";
                        }
                        cout<<"-----------------------------------------------------------------"<<endl;
                        cout<<"                                            OP. GRAVADA: S/."<<datos_orden[bscr].costo_total_items*0.82<<endl;
                        cout<<"                                              IGV (18%): S/."<<datos_orden[bscr].costo_total_items*0.18<<endl;
                        cout<<"                                                  TOTAL: S/."<<datos_orden[bscr].costo_total_items<<endl;
                    	cout<<"                                      PAGO CON EFECTIVO: S/"<<pago_cliente<<endl;
                    	cout<<"                                                 VUELTO: S/"<<pago_cliente-datos_orden[bscr].costo_total_items<<endl;
                        datos_orden[bscr].costo_total_items=0;
                        system("pause");
                    }else{
                        system("cls");
                        version();
                        cout<<"\n\nREGRESANDO AL MENU..."<<endl;
                        Sleep(2*1000);
                    }*/
					system("pause");
                }else if(opc_buscar==0){
                    system("cls");
                    version();
                    cout<<"\n\nCODIGO INGRESADO NO EXISTENTE... REGRESANDO AL MENU"<<endl;
                    Sleep(2*1000);
                }
                break;
            }//FIN CASE 3
            case '4':{
                int codice=0;//codigo registrado
                int bscr , opc_buscar=0;
                system("cls");
                version();
                cout<<""<<endl;
                cout<<"|--------------------|------------------|"<<endl;
                cout<<"| CODIGO DEL CLIENTE | NOMBRE CLIENTE   |"<<endl;
                cout<<"|--------------------|------------------|"<<endl;
                for(int i=0 ; i<num_cliente; i++){
                    gotoxy(0, i+8);cout<<"| "<<datos_orden[i].codigo_cliente;
                    gotoxy(21, i+8);cout<<"| "<<datos_orden[i].nombre_cliente<<endl;
                    gotoxy(40, i+8);cout<<"| ";
                }
                cout<<endl<<"|--------------------|------------------|"<<endl;
                cout<<endl<<"Inserte el codigo de la orden cual desee generar boleta: ";
                cin >> codice;
                for(int i=0 ; i<num_cliente; i++){
                    if(codice==datos_orden[i].codigo_cliente){
                        bscr=i;
                        opc_buscar=1;
                    }
                }
                if(opc_buscar==1){
	                do {
						cout<<"Ingresar efectivo con el que pagará el cliente: "; cin>>pago_cliente;
						if(datos_orden[bscr].costo_total_items>pago_cliente) {
							cout<<"Monto insuficiente"<<endl;
						}
					}while(datos_orden[bscr].costo_total_items>pago_cliente);

	                system("cls");
	                cout<<endl<<endl<<endl<<endl<<"\t\t  MACCHIAVELLO'S RESTAURANT S.L."<<endl;
	            	cout<<"\t\t  RUC No.: 17732301232"<<endl;
	                cout<<"\t\t  Chorrillos - Lima"<<endl;
	                cout<<"\t\t  Telef: 123-4567"<<endl;
	                cout<<"\t\t  info@macchiavellosresutaurant.com"<<endl;
	            	cout<<"\t\t BOLETA DE VENTA ELECTRONICA"<<endl;
	                cout<<"-----------------------------------------------------------------"<<endl;
	                cout<<"CLIENTE: "<< datos_orden[bscr].nombre_cliente << endl;
	                cout<<"BOLETA N°: "<< datos_orden[bscr].codigo_cliente<<endl;
	                cout<<"-----------------------------------------------------------------"<<endl;
	                cout<<" UDS   DESCRIPCION                          PREC/UDS     COSTO"<<endl;
	                cout<<"-----------------------------------------------------------------"<<endl;
	                for(int i=0; i<datos_orden[bscr].numero_items_datos; i++){
	                    gotoxy(0, i+12);cout<<" x"<<orden[i][bscr].cantidad_item;
	                    gotoxy(7, i+12);cout<<orden[i][bscr].nombre_item;
	                    gotoxy(44, i+12);cout<<"S/."<<orden[i][bscr].precio_item;
	                    gotoxy(57, i+12);cout<<"S/."<<orden[i][bscr].precio_item * orden[i][bscr].cantidad_item<<"\n";
	                }
	                cout<<"-----------------------------------------------------------------"<<endl;
	                cout<<"                                            OP. GRAVADA: S/"<<datos_orden[bscr].costo_total_items*0.82<<endl;
	                cout<<"                                              IGV (18%): S/"<<datos_orden[bscr].costo_total_items*0.18<<endl;
	                cout<<"                                                  TOTAL: S/"<<datos_orden[bscr].costo_total_items<<endl;
	            	cout<<"                                      PAGO CON EFECTIVO: S/"<<pago_cliente<<endl;
	            	cout<<"                                                 VUELTO: S/"<<pago_cliente-datos_orden[bscr].costo_total_items<<endl;

	                system("pause");
	                system("cls");
	                version();
	                cout<<"\n\nREGRESANDO AL MENU..."<<endl;
	                Sleep(2*1000);
				}else{
					system("cls");
                    version();
                    cout<<"\n\nCODIGO INGRESADO NO EXISTENTE... REGRESANDO AL MENU"<<endl;
                    Sleep(2*1000);
				}
                break;
            }
        	case '5':{
        	int codice=0;//codigo registrado
                int bscr , opc_buscar=0;
                system("cls");
                version();
                cout<<""<<endl;
                cout<<"|--------------------|------------------|"<<endl;
                cout<<"| CODIGO DEL CLIENTE | NOMBRE CLIENTE   |"<<endl;
                cout<<"|--------------------|------------------|"<<endl;
                for(int i=0 ; i<num_cliente; i++){
                    gotoxy(0, i+8);cout<<"| "<<datos_orden[i].codigo_cliente;
                    gotoxy(21, i+8);cout<<"| "<<datos_orden[i].nombre_cliente<<endl;
                    gotoxy(40, i+8);cout<<"| ";
                }
                cout<<endl<<"|--------------------|------------------|"<<endl;
                cout<<endl<<"Inserte el codigo de la orden que desea eliminar: ";
            	fflush(stdin);
                cin>>codice;
                for(int i=0 ; i<num_cliente; i++){
                    if(codice==datos_orden[i].codigo_cliente){
                        bscr=i;
                        opc_buscar=1;
                    }
                }
                if(opc_buscar==1){
                	for(int j=bscr; j<10; j++) {
                		datos_orden[j].codigo_cliente=datos_orden[j+1].codigo_cliente;
                		datos_orden[j].nombre_cliente=datos_orden[j+1].nombre_cliente;
                		for(int k=0; k<19; k++){
                			orden[k][j]=orden[k][j+1];//CASI AAAAAAAAAA
                		}
                	}
                	num_cliente=num_cliente-1;
				}else{
					system("cls");
                    version();
                    cout<<"\n\nCODIGO INGRESADO NO EXISTENTE... REGRESANDO AL MENU"<<endl;
                    Sleep(2*1000);
				}
                break;
            }
            case '0':{
                system("cls");
                version();
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