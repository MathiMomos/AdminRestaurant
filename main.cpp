#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
#include <clocale>
#include <fstream>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(hConsole, pos);
}

void dibujarRecuadro(int x, int y, int ancho, int alto) {
    // Borde superior
    gotoxy(x, y);
    cout << "+" << string(ancho - 2, '-') << "+";

    // Lados y espacio interior
    for (int i = 1; i < alto - 1; ++i) {
        gotoxy(x, y + i);
        cout << "|" << string(ancho - 2, ' ') << "|";
    }

    // Borde inferior
    gotoxy(x, y + alto - 1);
    cout << "+" << string(ancho - 2, '-') << "+";
}

void menu() {
    system("cls");
    cout<<"\n                                               MACCHIAVELLO'S RESTAURANT";
    cout<<"\n                                                     MENU PRINCIPAL";

    string opciones[] = {
            "1. CREAR ORDEN",
            "2. MODIFICAR ORDEN",
            "3. BUSCAR ORDEN",
            "4. GENERAR BOLETA",
            "5. ELIMINAR ORDEN",
            "0. SALIR DEL SISTEMA"
    };

    for (int i = 0; i < 6; i++) {
        if (i == 5) { // Colorear la opcion 5
            SetConsoleTextAttribute(hConsole, 116);  //116: texto rojo, fondo gris claro
        } else {
            SetConsoleTextAttribute(hConsole, 112); //112: texto negro, fondo gris claro
        }
        dibujarRecuadro(45, 4 + i * 3, 30, 3);
        gotoxy(45 + (30 - opciones[i].length()) / 2, 4 + i * 3 + 1);
        cout << opciones[i];
    }
    SetConsoleTextAttribute(hConsole, 112);

    // Recuadro para "Ingrese Opcion"
    dibujarRecuadro(48, 24, 24, 3);
    gotoxy(50, 25);
    cout << "  Ingrese Opcion: ";

}//menu principal

void version(){
    cout<<"Versión "<<1<<"."<<9<<"."<<1<<" - Solo para desarrolladores -  No distribuir!"<<endl;
    cout<<"\n\t\t            ADMINISTRADOR DE RESTAURANTES - MACCHIAVELLO'S RESTAURANT"<<endl<<endl;
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
    SetConsoleTextAttribute(hConsole, 125); // 117=morado 124=rosado 125=magenta
    //cout<<"                              +---------------------------------------------------+"<<endl;
    cout<<"                              |                 => Menu de platos <=              |"<<endl;
    cout<<"                              +---------------------------------------------------+"<<endl;
    cout<<"                              |  ID    NOMB. ITEM                        PRECIO   |"<<endl;
    cout<<"                              +---------------------------------------------------+"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    for(int i=1; i<=5;i++){

        switch(i){
            ///Entradas
            case 1:{
                nombreplato ="Caldo de Gallina";
                precio = 8.00;
                break;
            }
            case 2:{
                nombreplato= "Sopa de Wantán";
                precio =8.00;
                break;
            }
            case 3:{
                nombreplato="Tequeños";
                precio =5.50;
                break;
            }
            case 4:{
                nombreplato="Wantán c/ salsa Tamarindo";
                precio =6.50;
                break;
            }
            case 5:{
                nombreplato="Yucas fritas c/ Huancaína";
                precio =7.00;
                break;
            }
        }
        id=i+100;
        c[i].nos=nombreplato;
        c[i].pr=precio;
        gotoxy(33, i+7);cout<<id;
        cout<<"   "<<c[i].nos;
        gotoxy(73, i+7);cout<<"S/."<<c[i].pr<<endl;
    }
    cout<<"                              +---------------------------------------------------+"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;

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
                nombreplato="Tallarín Saltado";
                precio = 18.00;
                break;
            }
        }
        id=i+200;
        c[i].nos=nombreplato;
        c[i].pr=precio;
        gotoxy(33, i+13);cout<<id;
        cout<<"   "<<c[i].nos;
        gotoxy(73, i+13);cout<<"S/."<<c[i].pr<<endl;

    }
    cout<<"                              +---------------------------------------------------+"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |"<<endl;
    cout<<"                              |                                                   |";
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
        gotoxy(33, i+24);cout<<id;
        cout<<"   "<<c[i].nos;
        gotoxy(73, i+24);cout<<"S/."<<c[i].pr<<endl;
    }
    cout<<"                              +---------------------------------------------------+"<<endl<<endl;
    SetConsoleTextAttribute(hConsole, 112);
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
        ped[num_orden][num_cliente].nombre_item="Sopa de Wantán";
        ped[num_orden][num_cliente].precio_item=8.00;
        break;
    }
    case 103:{
        ped[num_orden][num_cliente].nombre_item="Tequeños";
        ped[num_orden][num_cliente].precio_item=5.50;
        break;
    }
    case 104:{
        ped[num_orden][num_cliente].nombre_item="Wantán c/ salsa Tamarindo";
        ped[num_orden][num_cliente].precio_item=6.50;
        break;
    }
    case 105:{
        ped[num_orden][num_cliente].nombre_item="Yucas fritas c/ Huancaina";
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
        ped[num_orden][num_cliente].nombre_item="Tallarín Saltado";
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
    		///Nada
    	}else {
    		cout<<" Código inválido..."<<endl;
    		cod_verificador=1;
    	}
    	break;
	}
    case 1:{
    	if(menu_modo==0) {
    		///Nada
    	}else {
    		cout<<" Código inválido..."<<endl;
    		cod_verificador=1;
    	}
		break;
	}
	case 2: {
    	if(menu_modo==0) {
    		///Nada
    	}else {
    		cout<<" Código inválido..."<<endl;
    		cod_verificador=1;
    	}
	   break;
    }
    default:{
        cout<<" Código inválido..."<<endl;
        cod_verificador=1;
        break;
    }
	}
}

void menuMostrar(int num_cliente, int num_orden, pedido orden[][10], datos_cliente datos_orden[], int gotoy, int indexmax) {
	datos_orden[num_cliente].costo_total_items=0;
	cout<<"                   ---------------------------------------------------------------------------"<<endl;
	cout<<"                     ID  	NOMB. ITEM                      PRECIO	   CANTIDAD     COSTO"<<endl;
	cout<<"                   ---------------------------------------------------------------------------"<<endl;
	for(int i=0; i<num_orden+indexmax; i++){
		int j=i;//posible cambio para poner el menu de la carta
		datos_orden[num_cliente].costo_total_items += orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item;
		gotoxy(21, j+gotoy);cout<<orden[i][num_cliente].codigo_item;
		cout<<"  \t"<<orden[i][num_cliente].nombre_item;
		gotoxy(65, j+gotoy);cout<<"S/."<<orden[i][num_cliente].precio_item;
		gotoxy(77, j+gotoy);cout<<" x"<<orden[i][num_cliente].cantidad_item;
		gotoxy(84, j+gotoy);cout<<"\tS/."<<orden[i][num_cliente].precio_item * orden[i][num_cliente].cantidad_item<<"\n";
	}
	cout<<"                   ---------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                 TOTAL: S/."<<datos_orden[num_cliente].costo_total_items<<endl;
}// Muestra la orden que se esta creando, siendo modificada o terminada

int main(){
    HWND console = GetConsoleWindow();
    MoveWindow(console, 550, 200, 960, 600, TRUE); //posicion y tama o de la ventana

    system("color 70"); //empieza el programa con color de fondo gris (7) y color de texto negro (0)
    srand(time(NULL));
    setlocale(LC_ALL, "spanish");
    char opcion;//opcion del menu principal
	float pago_cliente;// Pago del cliente
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	logo();
	Sleep(2*1000);
    do{
        system("cls");
        version();
        menu();
        fflush(stdin);
        opcion=getch();
        switch(opcion){
            case '1': {
	            system("cls");
            	int  opc_orden;//opcion de terminar o seguir con la orden
            	num_orden=0;
            	menu_modo=0;
                version();
                cout<<" Nombre del Cliente: ";
                cin>>datos_orden[num_cliente].nombre_cliente;

                do{
                    do{
                        cod_verificador=0;
                        cout<<"\n (0) Terminar Orden \n\n (1) Eliminar un Item\n\n (2) Mostrar Carta \n\n\n Código de Item: ";
                        fflush(stdin);
                        cin>>opc_orden;
                	    menuElegir(opc_orden, num_orden, num_cliente, orden);
                    }while(cod_verificador==1);

                    if(opc_orden!= 0 && opc_orden!=1 && opc_orden!=2){
                        orden[num_orden][num_cliente].codigo_item=opc_orden;

                    	do {
                    		cout<<"\n Cantidad: ";
                    		cin>>cantidad_item;
                    		if(cantidad_item<=0) {
                                cout<<endl;
                    			cout<<" "<<cantidad_item<<" , Cantidad inválida..."<<endl;
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
                			cout<<"\n\n Orden vacía\n\n Regresando al Menu Principal..."<<endl;
                    		opc_orden=0;
                    		Sleep(3*1000);
						}else{
							int codigo_eliminar, cont_elim=0 , opc_eliminar=1;
	                		system("cls");
	                        version();
							menuMostrar(num_cliente, num_orden, orden, datos_orden, 7, 0);

	                		cout<<"\n Código de Item a Eliminar: ";
	                		cin>>codigo_eliminar;

	                		while(opc_eliminar!=0 && datos_orden[num_cliente].numero_items_datos!=cont_elim){

	                			if(orden[cont_elim][num_cliente].codigo_item==codigo_eliminar){
								cout<<"\n Item de Código "<<orden[cont_elim][num_cliente].codigo_item<<" Eliminado"<<endl;
                                Sleep(2*1000);
								opc_eliminar=0;
								}
								cont_elim=cont_elim+1;
							}

							if(opc_eliminar!=0){
								cout<<"\n\n Código de Item No Encontrado..." << endl;
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
                    		cout<<"\n\n Orden vacía\n\n Regresando al Menu Principal..."<<endl;
                    		opc_orden=0;
                    		Sleep(2*1000);
						}else{
							system("cls");
	                        datos_orden[num_cliente].costo_total_items=0;

	                        version();
							cout<<"\t\t\t\t\t\tORDEN CREADA"<<endl;
							menuMostrar(num_cliente, num_orden, orden, datos_orden, 8, 0);
							datos_orden[num_cliente].codigo_cliente = 1000+rand()% 8999;
                			cout<<"\n\nCÓDIGO GENERADO : "<< datos_orden[num_cliente].codigo_cliente<<endl;
							num_cliente=num_cliente+1;
                            cout<<endl;
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
							//Nada
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
                cout<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                cout<<"\t\t\t\t    |       CÓDIGO       |      CLIENTE     |"<<endl;
                cout<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                for(int i=0 ; i<num_cliente; i++){
                    gotoxy(36, i+7);cout<<"|        "<<datos_orden[i].codigo_cliente;
                    gotoxy(57, i+7);cout<<"|       "<<datos_orden[i].nombre_cliente<<endl;
                    gotoxy(76, i+7);cout<<"| ";
                }
                cout<<endl<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                cout<<endl<<" Código de Orden: ";
                cin>>codice;
                for(int i=0 ;i<num_cliente; i++){
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
						cout<<"\n\n (0) Volver al Menú \n\n (1) Agregar Item \n\n (2) Mostrar la Carta \n\n (3) Eliminar Item \n\n\n Ingrese Opcion : ";
        				fflush(stdin);
        				cin>>opcm;

                    	switch(opcm){
                    		case 1:{
                    			int agregar_orden;// poner codigo a adido
                    			int agregarm=datos_orden[bscr].numero_items_datos;
                                do {
                                    cod_verificador=0;
                                    cout<<"\n Código de Item : ";
                                    fflush(stdin);
                                    cin >> agregar_orden;
                                    menuElegir(agregar_orden, agregarm, bscr, orden);

                                }while(cod_verificador==1);

			                    orden[agregarm][bscr].codigo_item=agregar_orden;

                    			do {
                    				cout<<"\n Cantidad: ";
                    				fflush(stdin);
                    				cin>>cantidad_item;
                    				if(cantidad_item<=0) {
                    					cout<<" Cantidad Inválida..."<<endl;
                    				}
                    			}while(cantidad_item<=0);
                    			orden[agregarm][bscr].cantidad_item=cantidad_item;

			                    datos_orden[bscr].costo_total_items=0;
			                    system("cls");
			                    fflush(stdin);
			                    version();
		                        cout<<"\t\t\t\t\t\tORDEN MODIFICADA"<<endl;
                    			menuMostrar(bscr, datos_orden[bscr].numero_items_datos, orden, datos_orden, 8, 1);
			                    datos_orden[bscr].numero_items_datos=1+agregarm;
			                    system ("pause");
								break;
							}
                            case 2:{
                            system("cls");
                            version();
                            menuCarta();//fin_if
                            system("pause");
                            system("cls");
                            break;
                            }
							case 3:{
                    			int eliminarm;
								int sacar_id=0;

								cout<<"\n Código de Item a Eliminar: ";
								fflush(stdin);
								cin>>eliminarm ;
								int opc_el=1;
								while(opc_el!=0 && datos_orden[bscr].numero_items_datos!=sacar_id){
	                				if(orden[sacar_id][bscr].codigo_item==eliminarm){
										cout<<"\n Item de Código "<<orden[sacar_id][bscr].codigo_item<<" Eliminado"<<endl<<endl;
										opc_el=0;
										system("pause");
									}
									sacar_id=sacar_id+1;
								}
								if(opc_el!=0){
									cout<<"\n Código de Item no Encontrado" << endl;
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
                                    cout<<"\t\t\t\t\t\tORDEN MODIFICADA"<<endl;
									menuMostrar(bscr, datos_orden[bscr].numero_items_datos, orden, datos_orden, 8, 0);
			                       system("pause");
								}
								break;
							}
							case 0:{
								system("cls");
                				version();
                				cout<<"\n\n Regresando...";
                				Sleep(2*1000);

								break;
							}

						}//fin switch
					}while( opcm!=0);//fin do modificar
                }else if(opc_buscar==0) {
                    system("cls");
                    version();
                    cout<<"\n\n Código no Existente\n\n Regresando al Menu Principal..."<<endl;
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
                cout<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                cout<<"\t\t\t\t    |       CÓDIGO       |      CLIENTE     |"<<endl;
                cout<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                for(int i=0 ; i<num_cliente; i++){
                    gotoxy(36, i+7);cout<<"|        "<<datos_orden[i].codigo_cliente;
                    gotoxy(57, i+7);cout<<"|       "<<datos_orden[i].nombre_cliente<<endl;
                    gotoxy(76, i+7);cout<<"| ";
                }
                cout<<endl<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                cout<<endl<<" Código de Orden: ";
                cin>>codice;
                for(int i=0 ; i<num_cliente; i++){
                    if(codice==datos_orden[i].codigo_cliente){
                        bscr=i;
                        opc_buscar=1;
                    }
                }

                if(opc_buscar==1){
                    system("cls");
                    version();
                    cout<<"\t\t\t\t\t    CÓDIGO DE CLIENTE ENCONTRADO"<<endl;
                	cout<<"\t\t   ---------------------------------------------------------------------------"<<endl;
                    cout<<"\t\t    Cliente: "<< datos_orden[bscr].nombre_cliente << endl;
                    cout<<"\t\t    Código: "<< datos_orden[bscr].codigo_cliente<<endl;
                    cout<<"\t\t    Numero de Ordenes: "<<datos_orden[bscr].numero_items_datos<<endl;
                    menuMostrar(bscr, datos_orden[bscr].numero_items_datos, orden, datos_orden, 12, 0);
                    cout<<endl;
                    cout<<endl;
                    /*cout<<endl<<" Desea generar la boleta de esta orden? (SI: 1/NO: 0): "; cin>>generar_boleta;
                    if(generar_boleta==1){
                    	do {
                    		cout<<"Ingresar efectivo con el que pagar  el cliente: "; cin>>pago_cliente;
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
                        cout<<"BOLETA N : "<< datos_orden[bscr].codigo_cliente<<endl;
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
                    cout<<"\n\n Código no Existente\n\n Regresando al Menú Principal..."<<endl;
                    Sleep(2*1000);
                }
                break;
            }//FIN CASE 3
            case '4':{
                int codice=0;//codigo registrado
                int bscr, opc_buscar=0;
                system("cls");
                version();
                cout<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                cout<<"\t\t\t\t    |       CÓDIGO       |      CLIENTE     |"<<endl;
                cout<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                for(int i=0 ; i<num_cliente; i++){
                    gotoxy(36, i+7);cout<<"|        "<<datos_orden[i].codigo_cliente;
                    gotoxy(57, i+7);cout<<"|       "<<datos_orden[i].nombre_cliente<<endl;
                    gotoxy(76, i+7);cout<<"| ";
                }
                cout<<endl<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                cout<<endl<<" Código de Orden: ";
                cin >> codice;
                for(int i=0 ; i<num_cliente; i++){
                    if(codice==datos_orden[i].codigo_cliente){
                        bscr=i;
                        opc_buscar=1;
                    }
                }

                if(opc_buscar==1){
	                do {
	                	cout<<"\n Total a Pagar: S/"<<datos_orden[bscr].costo_total_items;
						cout<<"\n\n Pago: S/"; cin>>pago_cliente;
						if(datos_orden[bscr].costo_total_items>pago_cliente) {
							cout<<"\n Pago Insuficiente"<<endl;
						}
					}while(datos_orden[bscr].costo_total_items>pago_cliente);

	                system("cls");
                    system("color f0");
                    logo();
                    cout<<"\t\t                           MACCHIAVELLO'S RESTAURANT S.L."<<endl;
                    cout<<"\t\t                           RUC No.: 17732301232"<<endl;
                    cout<<"\t\t                           Chorrillos - Lima"<<endl;
                    cout<<"\t\t                           Telef: 123-4567"<<endl;
                    cout<<"\t\t                           info@macchiavellosresutaurant.com"<<endl;
                    cout<<"                           -----------------------------------------------------------------"<<endl;
                    cout<<"                           CLIENTE: "<< datos_orden[bscr].nombre_cliente << endl;
                    cout<<"                           BOLETA N : "<< datos_orden[bscr].codigo_cliente<<endl;
                    cout<<"                           -----------------------------------------------------------------"<<endl;
                    cout<<"                            UDS   DESCRIPCION                          PREC/UDS     COSTO"<<endl;
                    cout<<"                           -----------------------------------------------------------------"<<endl;
                    for(int i=0; i<datos_orden[bscr].numero_items_datos; i++){
                        gotoxy(27, i+22);cout<<" x"<<orden[i][bscr].cantidad_item;
                        gotoxy(34, i+22);cout<<orden[i][bscr].nombre_item;
                        gotoxy(71, i+22);cout<<"S/."<<orden[i][bscr].precio_item;
                        gotoxy(84, i+22);cout<<"S/."<<orden[i][bscr].precio_item * orden[i][bscr].cantidad_item<<"\n";
                    }
                    cout<<"                           -----------------------------------------------------------------"<<endl;
                    cout<<"                                                                      OP. GRAVADA: S/."<<datos_orden[bscr].costo_total_items*0.82<<endl;
                    cout<<"                                                                        IGV (18%): S/."<<datos_orden[bscr].costo_total_items*0.18<<endl;
                    cout<<"                                                                    TOTAL A PAGAR: S/."<<datos_orden[bscr].costo_total_items<<endl;
	            	cout<<"                                                                             PAGO: S/."<<pago_cliente<<endl;
	            	cout<<"                                                                           VUELTO: S/."<<pago_cliente-datos_orden[bscr].costo_total_items<<endl;

	                system("pause");
	                system("cls");
                    system("color 70");
	                version();
	                cout<<"\n\nRegresando al Menu Principal..."<<endl;
	                Sleep(2*1000);

                	ofstream boletaGenerada;
					string boleta_nombre="BOLETA_"+to_string(datos_orden[bscr].codigo_cliente)+".txt";
					boletaGenerada.open(boleta_nombre, ios ::app);//Abro el archivo
						if (boletaGenerada.is_open()) {
							boletaGenerada<<"\t\t                           MACCHIAVELLO'S RESTAURANT S.L."<<endl;
							boletaGenerada<<"\t\t                           RUC No.: 17732301232"<<endl;
							boletaGenerada<<"\t\t                           Chorrillos - Lima"<<endl;
							boletaGenerada<<"\t\t                           Telef: 123-4567"<<endl;
							boletaGenerada<<"\t\t                           info@macchiavellosresutaurant.com"<<endl;
							boletaGenerada<<"                           -----------------------------------------------------------------"<<endl;
							boletaGenerada<<"                           CLIENTE: "<<datos_orden[bscr].nombre_cliente<<endl;
							boletaGenerada<<"                           BOLETA N°: "<<datos_orden[bscr].codigo_cliente<<endl;
							boletaGenerada<<"                           -----------------------------------------------------------------"<<endl;
							boletaGenerada<<"                            UDS   DESCRIPCION                          PREC/UDS     COSTO"<<endl;
							boletaGenerada<<"                           -----------------------------------------------------------------"<<endl;

							for(int i=0; i<datos_orden[bscr].numero_items_datos; i++){
							    boletaGenerada<< "                            x"<<orden[i][bscr].cantidad_item
								               <<"  "<<orden[i][bscr].nombre_item
							                   <<"\t\t\tS/."<<orden[i][bscr].precio_item
								               <<"\tS/."<<orden[i][bscr].precio_item * orden[i][bscr].cantidad_item<<"\n";
				        }

				        boletaGenerada<<"                           -----------------------------------------------------------------" << endl;
				        boletaGenerada<<"                                                                      OP. GRAVADA: S/."<<datos_orden[bscr].costo_total_items*0.82<<endl;
				        boletaGenerada<<"                                                                        IGV (18%): S/."<<datos_orden[bscr].costo_total_items*0.18<<endl;
				        boletaGenerada<<"                                                                    TOTAL A PAGAR: S/."<<datos_orden[bscr].costo_total_items<<endl;
				        boletaGenerada<<"                                                                             PAGO: S/."<<pago_cliente<<endl;
				        boletaGenerada<<"                                                                           VUELTO: S/."<<pago_cliente-datos_orden[bscr].costo_total_items<<endl;
				    boletaGenerada.close();//Cierro el archivo para que no se crashee xd
				    cout << "\nBoleta Guardada en el Archivo: " << boleta_nombre << endl;
					Sleep(2*1000);
				} else {
				    cout << "\nNo se Pudo Crear el Archivo Para Guardar la Boleta..." << endl;
					Sleep(2*1000);
				}
				}else{
					system("cls");
                    version();
                    cout<<"\n\n Codigo no Existente\n\n Regresando al Menu Principal..."<<endl;
                    Sleep(2*1000);
				}
                break;
            }
        	case '5':{
        	int codice=0;//codigo registrado
                int bscr , opc_buscar=0;
                system("cls");
                version();
                cout<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                cout<<"\t\t\t\t    |       CODIGO       |      CLIENTE     |"<<endl;
                cout<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                for(int i=0 ; i<num_cliente; i++){
                    gotoxy(36, i+7);cout<<"|        "<<datos_orden[i].codigo_cliente;
                    gotoxy(57, i+7);cout<<"|       "<<datos_orden[i].nombre_cliente<<endl;
                    gotoxy(76, i+7);cout<<"| ";
                }
                cout<<endl<<"\t\t\t\t    +--------------------+------------------+"<<endl;
                cout<<endl<<" Codigo de Orden: ";
            	fflush(stdin);
                cin>>codice;
                for(int i=0 ; i<num_cliente; i++){
                    if(codice==datos_orden[i].codigo_cliente){
                        bscr=i;
                        opc_buscar=1;
                    }
                }
                if(opc_buscar==1){
                	for(int j=bscr; j<num_cliente-1; j++) {
                		datos_orden[j]=datos_orden[j+1];
                		for(int k=0; k<20; k++){
                			orden[k][j]=orden[k][j+1];
                		}
                	}
                	num_cliente=num_cliente-1;
                	cout<<" Orden Eliminada"<<endl;
                	Sleep(2*1000);
				}else{
					system("cls");
                    version();
                    cout<<"\n\n Codigo no Existente\n\n Regresando al Menu Principal..."<<endl;
                    Sleep(2*1000);
				}
                break;
            }
            case '0':{
                system("cls");
                version();
                cout<<"\n\n Cerrando...";
                Sleep(2*1000);
                return 0;
            }
            default:{
                cout<<"\n\n Opcion Inválida\n\n Reiniciando..."<<endl;
                Sleep(2*1000);
                break;
            }

        }//FIN SWITCH
    }while( opcion!='0');
}
