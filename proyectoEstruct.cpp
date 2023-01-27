#include <iostream>
#include <string>

using namespace std;

//Procedimiento que indica cualquier dato invalido introducido
void ErrorSeleccion()
{
	system ("cls");
	cout<<"No valido \n";
	system ("pause");
}

//Funcion que devuelve un indice en la matriz de clientes
int Buscar (int cantidadClientes, string datosCliente[][4])
{
	system("cls");
	int retVal=-1;
	string cedula;
	cout<<"Digite la cedula del cliente a buscar: ";
	cin>>cedula;
	for(int i=0;i<cantidadClientes;i++)
	{
		if(cedula==datosCliente[i][0])
		{
      		cout<<"Cedula: "<<datosCliente[i][0]<<"\n"<<"Nombre completo: "<<datosCliente[i][1]<<"\n"
				<<"Telefono: "<<datosCliente[i][2]<<"\n"<<"Correo: "<<datosCliente[i][3]<<"\n";
			system("pause");
			retVal=i;
			break;
		}
	}
	if (retVal==-1)
	{
		ErrorSeleccion();
	}
	return retVal;	
}

///////////////////////////////////Procedimientos y funciones de gestión de facturas///////////////////////////////////////////

//Procedimiento que aplica los reportes a la factura
void MenuReportes (bool arregloReportes[])
{
	bool menu;
	int opcion;
	while (menu)
	{
		if (!arregloReportes[0])
		{
			cout<<"1-Daños en cama \n";
		}
		if (!arregloReportes[1])
		{
			cout<<"2-Daños en los muebles \n";
		}
		if (!arregloReportes[2])
		{
			cout<<"3-Daños en la infraestructura \n";
		}
		if (!arregloReportes[3])
		{
			cout<<"4-Daños en el baño \n";
		}
		if (!arregloReportes[4])
		{
			cout<<"5-Daños en equipos electrónicos \n";
		}
		if (!arregloReportes[5])	
		{
			cout<<"6-Hurto de artículos de cama \n";
		}
		if (!arregloReportes[6])
		{
			cout<<"7-Hurto de articulos de habitacion \n";
		}
		if (!arregloReportes[7])
		{
			cout<<"8-Hurto en toallas\n";
		}
		if (!arregloReportes[8])
		{
			cout<<"9-Hurto en electrónicos \n";
		}
		cout<<"10-Salir \n"
			<<"Digite la opcion: ";
		cin>>opcion;
		switch (opcion)
		{
			case 1:
				arregloReportes[0]=true;
				break;
			case 2:
				arregloReportes[1]=true;
				break;
			case 3:
				arregloReportes[2]=true;
				break;
			case 4:
				arregloReportes[3]=true;
				break;
			case 5:
				arregloReportes[4]=true;
				break;
			case 6:
				arregloReportes[5]=true;
				break;
			case 7:
				arregloReportes[6]=true;
				break;
			case 8:
				arregloReportes[7]=true;
				break;
			case 9:
				arregloReportes[8]=true;
				break;
			case 10:
				menu=false;
				break;
			default:
				ErrorSeleccion();
				break;
		}
	}
}

//Funcion que convierte un arreglo de valores a las diferentes monedas y retorna su símbolo
string ConversionMonedas (float arregloValores[])
{
	//Se inicializa en 1 por si se desea emitir en dolares, no hacer cambios
	float valorMoneda=1;
	int moneda;
	//nombre y simbolo, se retorna el simbolo para la impresion de la moneda
	string nombreMoneda, simboloMoneda="USD";
	do
	{
		cout<<"1.Dolar\n"
			<<"2.Euro\n"
			<<"3.Colon"
			<<"Digite la moneda en la que emitira la factura:";
		cin>>moneda;
	}while ((moneda!=1)||(moneda!=2)||(moneda!=3));
	if (moneda==2)
	{
		nombreMoneda="euro";
		simboloMoneda="EUR";
	}
	if (moneda==3)
	{
		nombreMoneda="colon";
		simboloMoneda="CRC";
	}
	if ((moneda==2)||(moneda==3))
	{
		do
		{
			cout<<"Digite el valor de "<<nombreMoneda<<":";
			cin>>valorMoneda;
		}while (valorMoneda<1);
	}
	//Conversion del precio bruto
	arregloValores[0]=arregloValores[0]*valorMoneda;
	//Conversion del valor de la multa
	arregloValores[1]=arregloValores[1]*valorMoneda;
	//Conversion del valor de los impuestos
	arregloValores[2]=arregloValores[2]*valorMoneda;
	//Conversion del precio total
	arregloValores[3]=arregloValores[3]*valorMoneda;
	return simboloMoneda;
}

//Funcion que retorna la fecha en la que se emitió la factura
string FechaFactura()
{
	string retFecha;
	int dia, mes, diasLimiteMes;
	do
	{
		cout<<"Digite el mes de efectuada esta factura: ";
		cin>>mes;
	}while ((mes<1)||(mes>12));
	//evalua los diferentes meses y les asigna según la cantidad de días de cada uno, un valor a una variable 
	switch (mes)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			diasLimiteMes=31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			diasLimiteMes=30;
			break;
		case 2:
			diasLimiteMes=28;
			break;
	}
	do
	{
		cout<<"Digite el dia de efectuada esta factura: ";
		cin>>dia;
	}while ((dia<1)||(dia>diasLimiteMes));
	//concatena el dia y el mes y lo retorna
	retFecha=dia+"/"+mes;
	return retFecha;
}

//Funcion que calcula las multas según el arreglo de datos booleanos que representa los reportes
float CalculoMultas(float precioBruto, bool arregloReportes [])
{
	float porcentaje=0, multa=0;
	int cantidadToallas;
	if (arregloReportes[0])
	{
		porcentaje=22*precioBruto;
		porcentaje=porcentaje/100;
		multa=multa+porcentaje;
	}
	if (arregloReportes[1])
	{
		porcentaje=87*precioBruto;
		porcentaje=porcentaje/100;
		multa=multa+porcentaje;
	}
	if (arregloReportes[2])
	{
		porcentaje=39*precioBruto;
		porcentaje=porcentaje/100;
		multa=multa+porcentaje;
	}
	if (arregloReportes[3])
	{
		porcentaje=25*precioBruto;
		porcentaje=porcentaje/100;
		multa=multa+porcentaje;
	}
	if (arregloReportes[4])
	{
		multa=multa+578;
	}
	if (arregloReportes[5])
	{
		multa=multa+110;
	}
	if (arregloReportes[6])
	{
		multa=multa+196;
	}
	if (arregloReportes[7])
	{
		cout<<"Cantidad de toallas robadas: ";
		cin>>cantidadToallas;
		multa=multa+20*cantidadToallas;
	}
	if (arregloReportes[6])
	{
		multa=multa+500;
	}
	//retorna la multa, esta será 0 en caso de no haber reportes activos
	return multa;
}

//Procedimiento que recorre las matrices de clientes reservando para buscar las reservaciones que ha hecho en cliente, en las diferentes habitaciones
void ConteoReservaciones (string idCliente, int cantidadHabitacionesTipo[], string clienteHab1[][365], string clienteHab2[][365], string clienteHab3[][365],
int cantidadReservada[])
{
	//recorre la matriz de reservaciones en habitaciones tipo 1
	for (int i=0;i<cantidadHabitacionesTipo[0];i++)
	{
		for (int j=0;i<365;i++)
		{
			if (clienteHab1[i][j]==idCliente)
			{
				//en caso de encontrar al cliente seleccionado para facturar, incrementa al contador en la posicion 0
				cantidadReservada[0]++;
				//borra al cliente para que no se facture de nuevo la reservacion en futuras reservaciones
				clienteHab1[i][j]="";
			}
		}
	}
	//realiza lo mismo con los tipos 2 y 3
	for (int i=0;i<cantidadHabitacionesTipo[1];i++)
	{
		for (int j=0;i<365;i++)
		{
			if (clienteHab2[i][j]==idCliente)
			{
				cantidadReservada[0]++;
				clienteHab2[i][j]="";
			}
		}
	}
	for (int i=0;i<cantidadHabitacionesTipo[2];i++)
	{
		for (int j=0;i<365;i++)
		{
			if (clienteHab3[i][j]==idCliente)
			{
				cantidadReservada[0]++;
				clienteHab3[i][j]="";
			}
		}
	}
}

//Procedimiento que calcula los valores de las reservaciones y las imprime en la factura
void EmitirFactura(float preciosTipo[], string clienteHab1[][365],string clienteHab2[][365], string clienteHab3[][365], int cantidadClientes,
string datosCliente[][4], int cantidadHabitacionesTipo[])
{
	int indiceCliente;
	int cantidadReservada[3]{0,0,0};
	float multa=0, precioBruto, precioTotal,impuestos;
	float arregloValores[4];
	//inicializa los reportes en falso
	bool arregloReportes[9]{false,false,false,false,false,false,false,false,false};
	string idCliente, nombreCliente;
	string informacionFactura, fecha, simboloMoneda;
	//llama a la funcion buscar para seleccionar el cliente al que se le emite la factura
	indiceCliente=Buscar(cantidadClientes,datosCliente);
	if (indiceCliente!=-1)
	{
		//Llena los valores de id y nombre con los de la matriz de clientes
		idCliente=datosCliente[indiceCliente][0];
		nombreCliente=datosCliente[indiceCliente][1];
		//LLama al procedimiento de conteo de reservaciones para calcular los precios
		ConteoReservaciones(idCliente,cantidadHabitacionesTipo,clienteHab1,clienteHab2,clienteHab3,cantidadReservada);
		//calcula el precio en bruto
		arregloValores[0]=(preciosTipo[0]*cantidadReservada[0])+(preciosTipo[1]*cantidadReservada[1])+(preciosTipo[2]*cantidadReservada[2]);
		//Llama al menu de reportes
		MenuReportes(arregloReportes);
		//calcula la multa segun el arreglo de booleanos
		arregloValores[1]=CalculoMultas(precioBruto,arregloReportes);
		//calcula los impuestos sacando un 13% del precio en bruto
		arregloValores[2]=precioBruto*13;
		arregloValores[2]=impuestos/100;
		//calcula el total
		arregloValores[3]=precioBruto+multa+impuestos;
		fecha=FechaFactura();
		simboloMoneda=ConversionMonedas(arregloValores);
		cout<<"Factura por :\n"
			<<cantidadReservada[0]<<" reservaciones en una habitacion Basica\n"
			<<cantidadReservada[1]<<" reservaciones en una habitacion Basica con vista al mar\n"
			<<cantidadReservada[2]<<" reservaciones en una habitacion Premium\n"
			<<"A nombre de "<<nombreCliente<<", cedula "<<idCliente<<"\n"
			<<"Precio Bruto: "<<arregloValores[0]<<"\n"
			<<"Multa: "<<arregloValores[1]<<"\n"
			<<"Impuestos: "<<arregloValores[2]<<"\n"
			<<"Total: "<<arregloValores[3]<<"\n"
			<<"Fecha: "<<fecha;
		system("pause");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////Procedimientos y funciones de reservacion y gestion de habitaciones/////////////////////////

//Procedimiento que muestra la cantidad de habitaciones disponibles por cada tipo
void DetallesHabitacion (int cantidadHabitacionesTipo[])
{
	system ("cls");
	cout<<"Detalles de Habitacion \n"
		<<"1.Habitacion Basica (Disponibles: "<<cantidadHabitacionesTipo[0]<<")\n"
		<<"2.Habitacion Basica con vista al mar (Disponibles: "<<cantidadHabitacionesTipo[1]<<")\n"
		<<"3.Habitacion Premium (Disponibles: "<<cantidadHabitacionesTipo[2]<<")\n";
	system ("pause");
}

//Procedimiento que almacena las fechas de una reservación en la matriz de fechas
void AlmacenarFechas(int numHabitacion, string cedulaReservando, string fechasTipo1[][365],string fechasTipo2[][365],
string fechasTipo3[][365], string clienteHab1[][365],string clienteHab2[][365], string clienteHab3[][365],int tipoHabitacion,
int diasLimiteMes, int mes, int dia, int diasEstancia)
{
	bool procesoAlmacenamiento=false;
	string fecha;
	while (!procesoAlmacenamiento)
	{
		for (int i=0;i<diasEstancia;i++)
		{
			//aumenta en uno la fecha
			dia++;
			//si finaliza el mes, aumenta el mes y reinicia los dias
			if (dia>diasLimiteMes)
			{
				dia=1;
				mes++;
			}
			//concatena la fecha para almacenarla en alguna de las matrices
			fecha=dia+"/"+mes;
			/*recorre las matrices basado en el tipo de habitación elegido por el usuario y el numero de habitacion que retornó
			la funcion de busqueda de habitaciones*/
			switch (tipoHabitacion)
			{
				case 1:
					for (int i=0;i<365;i++)
					{
						//si encuentra un espacio vacío en la matriz, almacena el id del cliente y la fecha
						if (fechasTipo1[numHabitacion][i]=="/")
						{
							fechasTipo1[numHabitacion][i]=fecha;
							clienteHab1[numHabitacion][i]=cedulaReservando;
							break;
						}
					}
					break;
				case 2:
					for (int i=0;i<365;i++)
					{
						if (fechasTipo2[numHabitacion][i]=="/")
						{
							fechasTipo2[numHabitacion][i]=fecha;
							clienteHab2[numHabitacion][i]=cedulaReservando;
							break;
						}
					}
					break;
				case 3:
					for (int i=0;i<365;i++)
					{
						if (fechasTipo2[numHabitacion][i]=="/")
						{
							fechasTipo2[numHabitacion][i]=fecha;
							clienteHab2[numHabitacion][i]=cedulaReservando;
							break;
						}
					}
					break;
			}
			//finaliza el proceso de almacenamiento
			if (i==diasEstancia-1)
			{
				procesoAlmacenamiento=true;
			}
		}
	}
}

//Funcion que define si la fecha introducida en los parámetros existe en la matriz
bool BuscarFecha(int habitacionDisp, string fecha,int cantidadHabitacionesTipo[],string fechasTipo1[][365],string fechasTipo2[][365],
string fechasTipo3[][365],int tipoHabitacion)
{
	bool retVal=true;
	switch (tipoHabitacion)
	{
		//recorre la matriz de cada tipo de habitacion 
		case 1:
			for (int i=0;i<cantidadHabitacionesTipo[0];i++)
			{
				//en caso de ya estar registrada la fecha, devuelve un falso
				if (fechasTipo1[habitacionDisp][i]==fecha)
				{
					retVal=false;	
				}
			}
			break;
		case 2:
			for (int i=0;i<cantidadHabitacionesTipo[1];i++)
			{
				if (fechasTipo1[habitacionDisp][i]==fecha)
				{
					retVal=false;	
				}
			}
			break;
		case 3:
			for (int i=0;i<cantidadHabitacionesTipo[2];i++)
			{
				if (fechasTipo1[habitacionDisp][i]==fecha)
				{
					retVal=false;	
				}
			}
			break;
	}
	return retVal;
}

//Aumenta las fechas 
int ValidarFechas (int cantidadHabitacionesTipo[],string fechasTipo1[][365],string fechasTipo2[][365],string fechasTipo3[][365],
int tipoHabitacion, int diasLimiteMes, int mes, int dia, int diasEstancia)
{
	int retVal=0, cantidadHabitaciones=cantidadHabitacionesTipo[tipoHabitacion];
	bool procesoValidacion=true, fechaValida=false;
	string fecha; 
	while (procesoValidacion)
	{
		for (int i=0;i<diasEstancia;i++)
		{
			dia++;
			if (dia>diasLimiteMes)
			{
				dia=1;
				mes++;
			}
			if(mes>12)
			{
				retVal=-1;
			}
			if(retVal!=-1)
			{
				fecha=dia+"/"+mes;
				fechaValida=BuscarFecha(retVal,fecha,cantidadHabitacionesTipo,fechasTipo1,fechasTipo2,fechasTipo3,tipoHabitacion);
				if (!fechaValida)
				{
					retVal++;
					if (retVal==cantidadHabitaciones+1)
					{
						procesoValidacion=false;
						retVal=-1;
						break;
					}
				}
				if ((fechaValida)&&(i==diasEstancia-1))
				{
					procesoValidacion=false;
				}
			}
		}
	}
	return retVal;
}

void ValidacionFechaInicio(int cantidadHabitacionesTipo[], int tipoHabitacion,string fechasTipo1[][365],string fechasTipo2[][365],
string fechasTipo3[][365],int cantidadClientes, string datosCliente[][4], string clienteHab1[][365],
string clienteHab2[][365],string clienteHab3[][365], int indiceClienteReservando)
{
	bool validarMes=false;
	string cedulaReservando=datosCliente[indiceClienteReservando][0];
	int mes, dia, diasEstancia, diasLimiteMes, numHabitacion;
	while (!validarMes)
	{
		do
		{
			cout<<"Digite el mes de iniciada su estancia: ";
			cin>>mes;
		}while (mes<1);
		switch (mes)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				diasLimiteMes=31;
				validarMes=true;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				diasLimiteMes=30;
				validarMes=true;
				break;
			case 2:
				diasLimiteMes=28;
				validarMes=true;
				break;
			default:
				ErrorSeleccion();
				break;
		}
	}
	do
	{
		cout<<"Digite el dia de iniciada su estancia: ";
		cin>>dia;
	}while ((dia<1)||(dia>diasLimiteMes));
	do
	{
		cout<<"Digite los dias que durara su estancia: ";
		cin>>diasEstancia;
	}while (diasEstancia<1);
	numHabitacion=ValidarFechas(cantidadHabitacionesTipo, fechasTipo1, fechasTipo2, fechasTipo3, tipoHabitacion,diasLimiteMes,
	mes, dia, diasEstancia);
	if (numHabitacion!=-1)
	{
		AlmacenarFechas(numHabitacion, cedulaReservando, fechasTipo1, fechasTipo2, fechasTipo3,clienteHab1, clienteHab2, clienteHab3,tipoHabitacion,
		diasLimiteMes, mes, dia, diasEstancia);
		cout<<"Reservacion Exitosa!\n";
		system("pause");
	}
	else
	{
		system("cls");
		cout<<"Algo sucedió mal en su reservacion o no hay fechas disponibles\n";
		system("pause");
	}
}

//Procedimiento que configura la reservacion y llama a los procedimientos y funciones de validacion
void Reservacion (int cantidadHabitacionesTipo[],string fechasTipo1[][365],string fechasTipo2[][365],
string fechasTipo3[][365],int cantidadClientes, string datosCliente[][4], string clienteHab1[][365],
string clienteHab2[][365],string clienteHab3[][365])
{
	bool reservaExitosa=false;
	int indiceClienteReservando, tipoHabitacion;
	while (!reservaExitosa)
	{
		indiceClienteReservando=Buscar(cantidadClientes, datosCliente);
		if (indiceClienteReservando!=-1)
		{
			DetallesHabitacion(cantidadHabitacionesTipo);
			do
			{
				cout<<"Digite el tipo de Habitacion que desea reservar:";
				cin>>tipoHabitacion;
				if (tipoHabitacion==1||tipoHabitacion==2||tipoHabitacion==3)
				{
					break;
				}
				else
				{
					ErrorSeleccion();
				}
			}while (!reservaExitosa);
			ValidacionFechaInicio(cantidadHabitacionesTipo,tipoHabitacion,fechasTipo1,fechasTipo2,fechasTipo3,cantidadClientes,datosCliente,
			clienteHab1,clienteHab2,clienteHab3, indiceClienteReservando);
			break;
		}
		else
		{
			ErrorSeleccion();
			break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////Procedimientos y funciones de gestión de clientes///////////////////////////////////////////
int BuscarEspacio (int cantidadClientes, string datosCliente[][4])
{
	int retVal=-1;
	for(int i=0;i<cantidadClientes;i++)
	{
		if(datosCliente[i][0]=="")
		{
			retVal=i;
			break;
		}
	}
	return retVal;
}

bool ValidarCedula (string cedula, int cantidadClientes, string datosCliente[][4])
{
	bool retVal=false;
	for(int i=0;i<cantidadClientes;i++)
	{
		if(datosCliente[i][0]==cedula)
		{
			retVal=true;
			cout<<"cedula ya existe\n";
			system("pause");
			break;
		}
	}
	return retVal; 
}

void RecolectarDatos (bool ingresando,int indice,int cantidadClientes, string datosCliente[][4])
{
	system("cls");
	bool validarCedula;
	string nombre, apellido1, apellido2;
	string cedula, telefono, correo;
	cout<<"Digite la cedula del cliente: ";
	cin>>cedula;
	/*detecta si el parametro ingresando es verdadero, en ese caso, significa fue llamado por el procedimiento de 
	ingreso, por lo que debe validar la cedula*/
	if (ingresando)
	{
		do
		{
			validarCedula=ValidarCedula(cedula, cantidadClientes, datosCliente);
			if (validarCedula)
			{
				cout<<"Digite la cedula del cliente: ";
				cin>>cedula;
			}
			else
			{
				break;
			}
		}while (!validarCedula);
	}
	datosCliente[indice][0]=cedula;
	cout<<"Digite el nombre del cliente: ";
	cin>>nombre;
	cout<<"Digite el apellido del cliente: ";
	cin>>apellido1;
	cout<<"Digite el segundo apellido del cliente: ";
	cin>>apellido2;
	nombre=nombre+" "+apellido1+" "+apellido2;
	datosCliente[indice][1]=nombre;
	cout<<"Digite el telefono del cliente: ";
	cin>>telefono;
	datosCliente[indice][2]=telefono;
	cout<<"Digite el correo del cliente: ";
	cin>>correo;
	datosCliente[indice][3]=correo;
}

void Borrar (int cantidadClientes, string datosCliente[][4])
{
	int indiceBorrar=Buscar(cantidadClientes, datosCliente);
	if (indiceBorrar!=-1)
	{
		datosCliente[indiceBorrar][0]="";
		datosCliente[indiceBorrar][1]="";
		datosCliente[indiceBorrar][2]="";
		datosCliente[indiceBorrar][3]="";
	}
}

void Actualizar (int cantidadClientes, string datosCliente[][4])
{
	bool ingresando=false;
	int espacio=Buscar(cantidadClientes, datosCliente);
	system("cls");
	if (espacio!=-1)
	{
		RecolectarDatos(ingresando,espacio,cantidadClientes, datosCliente);
	}
	else
	{
		ErrorSeleccion();
	}
}

void Ingresar (int cantidadClientes, string datosCliente[][4])
{
	system("cls");
	int espacio;
	string cedula;
	bool ingresando=true;
	espacio=BuscarEspacio(cantidadClientes, datosCliente);
	if (espacio!=-1)
	{
		RecolectarDatos(ingresando,espacio,cantidadClientes, datosCliente);
	}
	else
	{
		ErrorSeleccion();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////Menu y sub menu's///////////////////////////////////////////////////////////////////////////

void MenuFacturacion(float preciosTipo[], string clienteHab1[][365],string clienteHab2[][365], string clienteHab3[][365], int cantidadClientes,
string datosCliente[][4], int cantidadHabitacionesTipo[])
{
	int opcion;
	bool menu=true;
	while (menu)
	{
		system("cls");
		cout<<"1.Emitir factura \n"
			<<"2.Salir \n"
			<<"Digite la opción: ";
		cin>>opcion;
		switch (opcion)
		{
			case 1:
				EmitirFactura(preciosTipo,clienteHab1, clienteHab2, clienteHab3, cantidadClientes, datosCliente, cantidadHabitacionesTipo);
				break;
			case 2:
				menu=false;
				break;
			default:
				ErrorSeleccion();
				break;
		}
	}
}

void MenuHabitaciones(int cantidadHabitacionesTipo[],string fechasTipo1[][365],string fechasTipo2[][365],
string fechasTipo3[][365],int cantidadClientes, string datosCliente[][4], string clienteHab1[][365],
string clienteHab2[][365],string clienteHab3[][365])
{
	bool menu=true;
	int opcion;
	while (menu)
	{
		system ("cls");
		cout<<"Menu de Habitaciones \n"
			<<"1.Reservar \n"
			<<"2.Ver detalles de Habitacion \n"
			<<"3.Salir \n"
			<<"Digite la opcion: ";
		cin>>opcion;
		switch (opcion)
		{
			case 1:
				Reservacion(cantidadHabitacionesTipo,fechasTipo1,fechasTipo2,fechasTipo3,cantidadClientes,datosCliente, 
				clienteHab1,clienteHab2,clienteHab3);
				break;
			case 2:
				DetallesHabitacion(cantidadHabitacionesTipo);
				break;
			case 3:
				menu=false;
				break;
			default:
				ErrorSeleccion();
				break;
		}
	}
}

void MenuClientes (int cantidadClientes, string datosCliente[][4])
{
	bool menu=true;
	int opcion;
	while (menu)
	{
		system("cls");
		cout<<"Menu Clientes\n"
			<<"1.Ingresar nuevo cliente\n"
			<<"2.Actualizar cliente\n"
			<<"3.Buscar cliente\n"
			<<"4.Borrar Cliente\n"
			<<"5.Salir\n"
			<<"Digite la opcion: ";
		cin>>opcion;
		switch (opcion)
		{
			case 1:
				Ingresar (cantidadClientes, datosCliente);
				break;
			case 2:
				Actualizar (cantidadClientes, datosCliente);
				break;
			case 3:
				Buscar (cantidadClientes, datosCliente);
				break;
			case 4:
				Borrar (cantidadClientes, datosCliente);
				break;
			case 5:
				menu=false;
				break;
			default:
				ErrorSeleccion();
				break;
		}
	}
}
///////////////////////////////////Procedimientos de arranque del sistema//////////////////////////////////////////////////////

void InicializarArreglosHabitacion(int cantidadHabitacionesTipo[],string fechasTipo1[][365],string fechasTipo2[][365],
string fechasTipo3[][365])
{
	for (int i=0;i<cantidadHabitacionesTipo[0];i++)
	{
		for (int j=0;j<365;j++)
		{
			fechasTipo1[i][j]="/";
		}
	}
	for (int i=0;i<cantidadHabitacionesTipo[1];i++)
	{
		for (int j=0;j<365;j++)
		{
			fechasTipo2[i][j]="/";
		}
	}
	for (int i=0;i<cantidadHabitacionesTipo[2];i++)
	{
		for (int j=0;j<365;j++)
		{
			fechasTipo2[i][j]="/";
		}
	}
}
void InicializarArreglosCliente (int cantidadClientes,int cantidadHabitacionesTipo[], string datosCliente[][4], 
string clienteHab1[][365],string clienteHab2[][365],string clienteHab3[][365])
{
	for (int i=0;i<cantidadClientes;i++)
	{
		for (int j=0;j<4;j++)
		{
			datosCliente[i][j]="";
		}
	}
	for (int i=0;i<cantidadHabitacionesTipo[0];i++)
	{
		for (int j=0;j<365;j++)
		{
			clienteHab1[i][j]="";
		}
	}
	for (int i=0;i<cantidadHabitacionesTipo[1];i++)
	{
		for (int j=0;j<365;j++)
		{
			clienteHab2[i][j]="";
		}
	}
	for (int i=0;i<cantidadHabitacionesTipo[2];i++)
	{
		for (int j=0;j<365;j++)
		{
			clienteHab3[i][j]="";
		}
	}
}

void MenuPrincipal (int cantidadClientes, int cantidadHabitacionesTipo[], float preciosTipo[])
{
	bool menu=true;
	int opcion, calculoHistoriales;
	string datosCliente[cantidadClientes][4];
	string fechasHabitacionTipo1[cantidadHabitacionesTipo[0]][365];
	string fechasHabitacionTipo2[cantidadHabitacionesTipo[1]][365];
	string fechasHabitacionTipo3[cantidadHabitacionesTipo[2]][365];
	string clienteHabitacionTipo1[cantidadHabitacionesTipo[0]][365];
	string clienteHabitacionTipo2[cantidadHabitacionesTipo[1]][365];
	string clienteHabitacionTipo3[cantidadHabitacionesTipo[2]][365];
	InicializarArreglosCliente(cantidadClientes, cantidadHabitacionesTipo, datosCliente, clienteHabitacionTipo1,clienteHabitacionTipo2,
	clienteHabitacionTipo3);
	InicializarArreglosHabitacion(cantidadHabitacionesTipo, fechasHabitacionTipo1,fechasHabitacionTipo2,fechasHabitacionTipo3);
	while (menu)
	{
		system("cls");
		cout<<"Menu Principal\n"
			<<"1.Menu de Habitaciones\n"
			<<"2.Menu de Clientes\n"
			<<"3.Facturacion\n"
			<<"4.Salir\n"
			<<"Digite la opcion: ";
		cin>>opcion;
		switch (opcion)
		{
			case 1:
				MenuHabitaciones(cantidadHabitacionesTipo,fechasHabitacionTipo1,fechasHabitacionTipo2,fechasHabitacionTipo3,
				cantidadClientes,datosCliente, clienteHabitacionTipo1,clienteHabitacionTipo2,clienteHabitacionTipo3);
				break;
			case 2:
				MenuClientes(cantidadClientes, datosCliente);
				break;
			case 3:
				MenuFacturacion(preciosTipo,clienteHabitacionTipo1, clienteHabitacionTipo2, clienteHabitacionTipo3, cantidadClientes, 
				datosCliente, cantidadHabitacionesTipo);
				break;
			case 4:
				menu=false;
				break;
			default:
				ErrorSeleccion();
				break;
		}
	}
}

//Procedimiento con las pciones de administrador
void Inicio ()
{
	int cantidadClientes;
	int cantidadTipoHabitacion[3];
	float preciosTipo[3];
	cout<<"Opciones del administrador \n";
	do
	{
		cout<<"Digite la cantidad de clientes que el sistema soporta: " ;
		cin>>cantidadClientes;
	}while (cantidadClientes<1);
	do
	{
		cout<<"Digite la cantidad de habitaciones de tipo Basica: ";
		cin>>cantidadTipoHabitacion[0];
	}while (cantidadTipoHabitacion[0]<1);
	do
	{
		cout<<"Digite el precio de habitacion:";
		cin>>preciosTipo[0];
	}while (preciosTipo[0]<1);
	do
	{
		cout<<"Digite la cantidad de habitaciones de tipo Premium: ";
		cin>>cantidadTipoHabitacion[1];
	}while (cantidadTipoHabitacion[1]<1);
	do
	{
		cout<<"Digite el precio de habitacion:";
		cin>>preciosTipo[2];
	}while (preciosTipo[2]<1);
	do
	{
		cout<<"Digite la cantidad de habitaciones de tipo Premium con vista al mar: ";
		cin>>cantidadTipoHabitacion[2];		
	}while (cantidadTipoHabitacion[2]<1);
	do
	{
		cout<<"Digite el precio de habitacion:";
		cin>>preciosTipo[0];
	}while (preciosTipo[0]<1);
	MenuPrincipal (cantidadClientes, cantidadTipoHabitacion, preciosTipo);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Main
int main ()
{
	Inicio();
}

