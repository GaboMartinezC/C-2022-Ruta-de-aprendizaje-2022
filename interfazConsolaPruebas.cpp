#include <iostream> 
#include <conio.h>  
#include <ctime>

#define arriba 119 
#define mayusArriba 87 
#define abajo 115 
#define mayusAbajo 83
#define zeta 122
#define mayusZeta 90

using namespace std;

int contadorPalabras ( char cad [] )   
{
	int palabras=0;
	for (int i=1; cad[i]!='\0'; i++)
	{
		if (cad[i-1]==' '&&isalpha(cad[i]))
		{
			palabras++;
		}
	}
	if (isalpha(cad[0]))
	{
		palabras++;
	}
	return palabras;
}

int main(int argc, char** argv) 
{
	int opcion=1, cantPalabras=50, finalPr, inicioPr, minutos=1;
	char tecla, test[]="Tomar Prueba", config[]="Configurar Prueba", salir[]="Salir";
	char cinco[]="5 minutos", tres[]="3 minutos", uno[]="1 minuto";
	char cadena[131072];
	bool menu=true;
	do
	{
		switch (tecla)
		{
			case mayusArriba:
			case arriba:
				opcion--;
				if (opcion<1)
				{
					opcion=3;
				}
				break;
			case mayusAbajo:
			case abajo:
				opcion++;
				if (opcion>3)
				{
					opcion=1;
				}
				break;
		}
		system("cls");
		cout<<"YaboWrite++\n";
		if (opcion==1)
		{
			cout<<test<<"<== \n";
		}
		else
		{
			cout<<test<<"\n";
		}
		if (opcion==2)
		{
			cout<<config<<"<== \n";

		}
		else
		{
			cout<<config<<"\n";

		}
		if (opcion==3)
		{
			cout<<salir<<"<== \n";

		}
		else
		{
			cout<<salir<<"\n";
		}
		tecla=getch();
		if (tecla==zeta || tecla==mayusZeta)
		{
			switch (opcion)
			{
				case 1:
					for (int i=0; i<200;i++)
					{
						system ("cls");
						cout<<"Empieza en...\n";
					}
					for (int i=0; i<100;i++)
					{
						system ("cls");
						cout<<"3\n";
					}
					for (int i=0; i<100;i++)
					{
						system ("cls");
						cout<<"2\n";
					}
					for (int i=0; i<100;i++)
					{
						system ("cls");
						cout<<"1\n";
					}
					system ("cls");
					for (int i=0;i<2;i++)
					{
						time_t inicio = time(0);
						tm * time = localtime (&inicio);
						finalPr=time->tm_min;
						if (i==0)
						{
							cin.getline(cadena,131072);
							inicioPr=finalPr;
						}
					}
					cout<<contadorPalabras(cadena)<<" palabras\n";
					cout<<"En "<<finalPr-inicioPr<<" minutos \n";
					if (finalPr-inicioPr<minutos && contadorPalabras (cadena)==cantPalabras)
					{
						cout<<"Prueba exitosa! Bien hecho \n";
						system ("pause");
					}
					else 
					{
						cout<<"Has fallado la prueba! Sigue intentado \n";
						system ("pause");
					}
					break;
				case 2:
					cout<<"Digite la cantidad de palabras a digitar por minuto: ";
					cin>>cantPalabras;
					if (cantPalabras<1)
					{
						cantPalabras=50;
						cout<<"No valido\n";
						system("pause");
					}
					do
					{
						switch (tecla)
						{
							case mayusArriba:
							case arriba:
								opcion--;
								if (opcion<1)
								{
									opcion=3;
								}
								break;
							case mayusAbajo:
							case abajo:
								opcion++;
								if (opcion>3)
								{
									opcion=1;
								}
								break;
						}
						system ("cls");
						cout<<"Minutos \n";
						if (opcion==1)
						{
							cout<<cinco<<"<== \n";
						}
						else
						{
							cout<<cinco<<"\n";
						}
						if (opcion==2)
						{
							cout<<tres<<"<== \n";
						}
						else
						{
							cout<<tres<<"\n";
						}
						if (opcion==3)
						{
							cout<<uno<<"<== \n";
						}
						else
						{
							cout<<uno<<"\n";
						}
						tecla=getch();
						if (tecla==zeta || tecla==mayusZeta)
						{
							switch (opcion)
							{
								case 1:
									minutos=5;
									menu=false;
									break;
								case 2:
									minutos=3;
									menu=false;
									break;
								case 3:
									minutos=1;
									menu=false;
									break;
							}
						}
					}while (menu);
					system ("cls");
					cout<<"La prueba sera de "<<cantPalabras<<" palabras en "<<minutos<<" minutos \n";
					system("pause");
					menu=true;
					break;
				case 3:	
					menu=false;
					system("pause");
					break;
			}	
		}
	} while (menu);
	return 0;
}
