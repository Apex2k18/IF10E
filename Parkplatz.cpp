#include <iostream>
#include <windows.h>
#include <stdlib.h>

#define GRUEN           0x0002
#define ROT             0x0004
#define NORMAL          0x0007
#define HELLBLAU        0x0009

using namespace std;

//Array Definition und Initialiesierung
int Lkw_P[50] = {0,1,0,1,0,2}; 

//Funktionen Deklaration
void Statusuebersicht(); 
void Farbe(WORD color);  
void Parkplatzbelegung(int parkplatzNr);
void Reservierung();

int main()
{
	//Variablen
	char weiter = 0;

	//Ausgabe (Layout)
	Farbe(NORMAL);
	cout << endl << "MELDUNG:" << endl;

	//Aufruf Funktionen
	do
	{
		cout << "\r\n\r\n";
		Statusuebersicht();
		cout << "\r\n";

		Reservierung();

		cout << "Wollen sie die Liste noch ein mal ausgaben?\t\t <J/N>\t:";
		cin >> weiter;
	} 
	while (weiter == 'j' || weiter == 'J');
	return 0;
}


//Funktion zum Setzen der Ausgabefarben des Textes
void Farbe(WORD color)
{
	SetConsoleTextAttribute(::GetStdHandle(STD_OUTPUT_HANDLE), color);
}



//Ausgabe aller Parkplätze, Belegstatus und belegstunden
void Statusuebersicht() 
{
	int sizeLkw_P = size(Lkw_P);
	for (int i = 0; i < sizeLkw_P; i+=0)
	{
		for (int j = 0; j < 3; j++)
		{
			Parkplatzbelegung(i);
			i++;
			if (i == sizeLkw_P)
			{
				break;
			}
		}
		cout << "\r\n";
	}
}


//Ausgabe der Eigenschaft eines Parkplatzes
void Parkplatzbelegung(int parkplatzNr)
{
	int eigenschaftParkplatz = Lkw_P[parkplatzNr];
	switch (eigenschaftParkplatz)
	{
	case 0: cout << "P-Nr: " << parkplatzNr + 1 << "= frei\t\t";
		break;
	case 1: cout << "P-Nr: " << parkplatzNr + 1 << "= belegt\t\t";
		break;
	case 2: cout << "P-Nr: " << parkplatzNr + 1 << "= reserviert\t\t";
		break;
	default: cout << "Falscher Eintrag Vorhanden.";
		break;
	}
}


//Resawieren eines Parkplatzes
void Reservierung ()
{
	int parkplatzeigenschaftNeu;
	int parkplatzNr;
	char weiter;

	cout << "Wollen sie einen Parplatzt reservieren, freigenen oder als besetzt fest legen?\r\n<J/N>\t:";
	cin >> weiter;

		if (weiter == 'j' || weiter == 'J')
		{
			cout << "Welchen Parkpatz moechtest du geändert haben?\t:";
			cin >> parkplatzNr;
			cout << "Frei = 0, belegt = 1, Reserviert = 2\t:";
			cin >> parkplatzeigenschaftNeu;
			cout << "\r\n\r\n";

			Lkw_P[parkplatzNr-1] = parkplatzeigenschaftNeu;
		}
}