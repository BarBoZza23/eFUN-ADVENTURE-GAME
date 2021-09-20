#include <iostream>
#include <string>
#include <string.h>
#include "Perivallon.h"
#include "Hrwas.h"
#include "Antikeimeno.h"
#include "Sakidio.h"

using namespace std;

int main(int argc, char** argv)
{
	//INITIALIZING ALL MY VARIABLES
	int epanalipsi = 1;
	int epilogh = 99;
	int st = 0;
	string stoxos = "";
	string antikeimeno = "";
	string antikeimeno2 = "";
	string onomArxeiou = "input.txt";
	string onomArxeiou2 = "output.txt";

	//INITIALIZING ALL MY OBJECTS
	Sakidio* s = new Sakidio();
	Perivallon* p = new Perivallon();

	Hrwas* h = new Hrwas("Pikridas", s, p);

	//READING OBJECTS FROM FILE 
	h->diavaseCSV(onomArxeiou);
	
	cout << "KALWS ORISATE SE ENA MAGIKO PAIXNIDI" << endl;
	
	//INFINITE LOOP FOR REPEATING GAME OPTIONS
	while (epanalipsi)
	{
		cout << "---------- MENU EPILOGWN ----------" << endl;
		cout << "1) KATHORISMOS STOXOS PAIXNIDIOU" << endl;
		cout << "2) PROVOLI ANTIKEIMENWN SAKIDIOU " << endl;
		cout << "3) PROVOLI ANTIKEIMENWN PERIVALLONTOS" << endl;
		cout << "4) PARTE ANTIKEIMENO APO PERIVALLON" << endl;
		cout << "5) PETAKSTE ANTIKEIMENO APO SAKIDIO " << endl;
		cout << "6) SYNDYASTE ANTIKEIMENA APO SAKIDIO" << endl;
		cout << "7) SYNDIASTE ANTIKEIMENA APO PERIVALLON" << endl;
		cout << "8) APOTHIKEYSTE TREXOUSAS KATASTASHS" << endl;
		cout << "9) EPANEKKINISH PAIXNIDIOU" << endl;
		cout << "0) TERMATISMOS PAIXNIDIOU " << endl;
		cout << "TI THA EPILEKSETE??? [0-9]" << endl;
		cin >> epilogh;

		switch (epilogh)
		{
		case 1:
		//DEFINE THE FINAL GOAL OF THE GAME
			stoxos = h->orismosStoxou();
			break;
		case 2:
		//REVEAL ALL THE OBJECTS FROM THE BACKPACK
			cout << endl;
			h->ektypwseSakidio();
			cout << s;
			cout << endl;
			break;
		case 3:
		//REVEAL ALL THE OBJECTS FROM THE ENVIROMENT
			cout << endl;
			h->ektypwsePerivallon();
			cout << p;
			cout << endl;
			break;
		case 4:
		//PICK UP AN OBJECT FROM THE ENVIROMENT
			cout << endl;
			cout << "PIO ANTIKEIMENO THELETE NA SHKWSETE APO TO PERIVALLON? " << endl;
			cout << "GRAPSTE KEFALAIA GREEKLISH" << endl;
			cout << "EPILOGH ANTIKEIMENOU: ";
			cin >> antikeimeno;
			st = s->prosthikiAntikeimenou(antikeimeno, onomArxeiou);
			if (st == 1) { p->afaireshAntikeimenou(antikeimeno); }
			cout << endl;
			break;
		case 5:
		//RETRACT [CHOICE 1] OR DESTROY [CHOICE 2] AN OBJECT FROM THE BACKPACK 
			cout << endl;
			cout << "1) APLH AFAIRESH ANTIKEIMENOU APO TO SAKIDIO" << endl;
			cout << "2) KATASTROFH ANTIKEIMENOU" << endl;
			cout << "EPILOGH: ";
			cin >> st;
			if (st == 1)
			{
				cout << "PIO ANTIKEIMENO THELETE NA AFAIRESETE APO TO SAKIDIO? " << endl;
				cout << "GRAPSTE KEFALAIA GREEKLISH" << endl;
				cout << "EPILOGH ANTIKEIMENOU: ";
				cin >> antikeimeno;
				st = s->afaireshAntikeimenou(antikeimeno);
				if (st == 1) { p->prosthikiAntikeimenou(antikeimeno, onomArxeiou); }
				cout << endl;
			}
			else if (st == 2)
			{
				cout << "PIO ANTIKEIMENO THELETE NA KATASTREPSETE APO TO SAKIDIO? " << endl;
				cout << "GRAPSTE KEFALAIA GREEKLISH" << endl;
				cout << "EPILOGH ANTIKEIMENOU: ";
				cin >> antikeimeno;
				s->afaireshAntikeimenou(antikeimeno);
				cout << endl;
			}
			else
			{
				cout << endl;
				cout << "LATHOS EPILOGH!!!" << endl;
				cout << endl;
			}
			break;
		case 6:
		//COMBINE OBJECTS FROM THE BACKPACK
			cout << endl;
			cout << "SYNDYASMOS ANTIKEIMENWN APO SAKIDIO" << endl;
			cout << "DWSTE MOU TO 1o ANTIKEIMENO" << endl;
			cout << "EPILOGH ANTIKEIMENOU: ";
			cin >> antikeimeno;
			cout << "DWSTE MOU TO 2o ANTIKEIMENO" << endl;
			cout << "EPILOGH ANTIKEIMENOU: ";
			cin >> antikeimeno2;
			s->syndyaseAntikeimena(antikeimeno, antikeimeno2, stoxos);
			cout << endl;
			break;
		case 7:
		//COMBINE OBJECTS FROM THE ENVIROMENT
			cout << endl;
			cout << "SYNDYASMOS ANTIKEIMENWN APO PERIVALLON" << endl;
			cout << "DWSTE MOU TO 1o ANTIKEIMENO" << endl;
			cout << "EPILOGH ANTIKEIMENOU: ";
			cin >> antikeimeno;
			cout << "DWSTE MOU TO 2o ANTIKEIMENO" << endl;
			cout << "EPILOGH ANTIKEIMENOU: ";
			cin >> antikeimeno2;
			p->syndyaseAntikeimena(antikeimeno, antikeimeno2, stoxos);
			cout << endl;
			break;
		case 8:
		//STORE GAME PROGRESS FROM A FILE
			cout << endl;
			cout << "APOTHIKEYSH THS POREIAS TOU PAIXNIDIOU" << endl;
			h->grapseCSV(onomArxeiou2);
			cout << endl;
			break;
		case 9:
		//RESTART OF THE GAME
			cout << endl;
			cout << "EPANEKKINHSH TOU PAIXNIDIOU" << endl;
			h->epanekinnisi(onomArxeiou);
			cout << endl;
			break;
		case 0:
		//END OF THE GAME
			cout << endl;
			cout << "EYXARISTOUME POU PEKSATE MAZI MAS" << endl;
			cout << "ELPIZOUME NA SAS XSANADOUME SYNTOMA" << endl;
			epanalipsi = 1;
			cout << endl;
			exit(0);
		default:
		//DEFAULT CHOICE WHICH SHOWS AN ERROR MESSAGE
			cout << endl;
			cout << "!!! LATHOS EPILOGH !!!" << endl;
			cout << endl;
			break;
		}
	}
	return 0;
}
