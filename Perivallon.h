#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "Antikeimeno.h"

using namespace std;

class Perivallon
{
private:
	vector <Antikeimeno*> pAntikeimena;
public:
	friend class Hrwas;

	//DEFAULT EMPTY CONSTRUCTOR
	Perivallon();

	//COPY CONSTRUCTOR
	Perivallon(const Perivallon& per);

	//METHODOS GIA ARXIKOPOIHSH TOU PERIVALLONTOS
	//METHOD WHICH INITIALIZES THE ENVIROMENT
	void prostheseAntikeimeno(Antikeimeno* x);

	//METHODOS PROSTHIKIS ANTIKEIMENOU STO PERIVALLON
	//METHOD WHICH ADDS AN OBJECT TO THE ENVIROMENT
	int prosthikiAntikeimenou(string onoma, string onomaArxeiou);
	
	//METHODOS AFAIRESHS ANTIKEIMENOU APO TO PERIVALLON
	//METHOD WHICH RETRACTS AN OBJECT FROM THE ENVIROMENT
	int afaireshAntikeimenou(string onoma);
	
	//METHODOS SYNDIASMOU ANTIKEIMENWN APO TO PERIVALLON
	//METHOD WHICH COMBINES OBJECTS FROM THE ENVIROMENT
	void syndyaseAntikeimena(string ant1, string ant2, string stoxos);

	//METHODOS APOTHIKEYSHS PROODOU SAKIDIOU SE ARXEIO
	//METHOD WHICH STORES THE PROGRESS OF THE BACKPACK TO A FILE
	void grapseAntikeimena(string onomArxeiou2);

	//METHODOS DIAGARFHS PERIEXOMENWN PERIVALLONTOS
	//METHOD WHICH RETRACTS OBJECTS FROM THE ENVIROMENT 
	void epanekkinishPerivallontos();

	//METHODOS EMFANISHS TWN ANTIKEIMENWN TOU SAKIDIOU
	//METHOD WHICH PRINTS ALL THE OBJECTS FROM THE BACKPACK
	friend ostream& operator <<(ostream& channel, Perivallon const& x);

	//METHODOS EMFANISHS TWN ANTIKEIMENWN TOU SAKIDIOU
	//METHOD WHICH PRINTS ALL THE OBJECTS FROM THE BACKPACK
	void ektypwseAntikeimena();
};
