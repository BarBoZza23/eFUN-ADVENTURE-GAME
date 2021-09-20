#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "Antikeimeno.h"
#include "Perivallon.h"

using namespace std;

class Sakidio
{
private:
	vector <Antikeimeno*> antikeimena;
public:
	friend class Hrwas;

	//DEFAULT EMPTY CONSTRUCTOR
	Sakidio();

	//COPY CONSTRUCTOR
	Sakidio(const Sakidio& sack);

	//METHODOS GIA ARXIKOPOIHSH TOU SAKIDIOU
	//METHOD WHICH INITIALIZES THE BACKPACK
	void prostheseAntikeimeno(Antikeimeno* x);

	//METHODOS PROSTHIKIS ANTIKEIMENOU STO SAKIDIO
	//METHOD WHICH ADDS AN OBJECT TO THE BACKPACK
	int prosthikiAntikeimenou(string onoma, string onomArxeiou);

	//METHODOS AFAIRESHS ANTIKIEMENOU APO TO SAKIDIO
	//METHOD WHICH RETRACTS AN OBJECT FROM THE BACKPACK
	int afaireshAntikeimenou(string onoma);

	//METHODOS SYNDIASMOU ANTIKEIMENWN APO TO SAKIDIO
	//METHOD WHICH COMBINES OBJECTS FROM THE BACKPACK
	void syndyaseAntikeimena(string ant1, string ant2, string stoxos);

	//METHODOS APOTHIKEYSHS PROODOU SAKIDIOU SE ARXEIO
	//METHOD WHICH STORES THE PROGRESS OF THE BACKPACK TO A FILE
	void grapseAntikeimena(string onomArxeiou2);

	//METHODOS DIAGARFHS PERIEXOMENWN SAKIDIOU
	//METHOD WHICH RETRACTS OBJECTS FROM THE BACKPACK
	void epanekkininshSakidiou();

	//METHODOS EMFANISHS TWN ANTIKEIMENWN TOU SAKIDIOU
	//METHOD WHICH PRINTS ALL THE OBJECTS FROM THE BACKPACK
	void ektypwseAntikeimena();

	//METHODOS EMFANISHS TWN ANTIKEIMENWN TOU SAKIDIOU
	//METHOD WHICH PRINTS ALL THE OBJECTS FROM THE BACKPACK
	friend ostream& operator <<(ostream& channel, Sakidio const& x);
};