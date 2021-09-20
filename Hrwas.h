#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Antikeimeno.h"
#include "Sakidio.h"
#include "Perivallon.h"

using namespace std;

class Hrwas
{
private:
	string onoma;
	Sakidio* s;
	Perivallon* p;

public:
	//DEFAULT EMPTY CONSTRUCTOR
	Hrwas();
	//DEFAULT FULL CONSTRUCTOR
	Hrwas(string _onoma, Sakidio* _s, Perivallon* _p);
	//DEFAULT COPY CONSTRUCTOR 
	Hrwas(const Hrwas& h);

	//METHODOS ORISMOU STOXOU PAIXNIDIOU
	//METHOD WHICH DEFINES THE FINAL GOAL OF THE GAME
	string orismosStoxou();

	//METHODOS DIAVASMATOS ANTIKEIMENWN APO ARXEIO
	//METHOD WHICH READS THE OBJECTS FROM A FILE
	void diavaseCSV(string onomaArxeiou);
	
	//METHODOS APOTHIKEYSHS ANTIKEIMWNWN SE ARXEIO
	//METHOD WHICH STORES THE OBJECTS TO A FILE
	void grapseCSV(string onomaArxeiou);

	//METHODOS ARXIKOPOIHSHS ANTIKEIMENWN SAKIDIOU
	//METHOD WHICH INITIALIZES ALL OBJECTS FROM THE BACKPACK
	void arxikopoihseSakidio(Antikeimeno* x);

	//METHODOS ARXIKOPOIHSHS ANTIKEIMENWN PERIVALLONTOS
	//METHOD WHICH INITIALIZES ALL OBJECTS FROM THE ENVIROMENT
	void arxikopoihsePerivallon(Antikeimeno* x);
	
	//METHODOS EKTYPWSHS DEDOMENWN SAKIDIOU
	//METHOD WHICH PRINTS ALL THE OBJECTS FROM THE BACKPACK 
	void ektypwseSakidio();

	//METHODOS EKTYPWSHS DEDOMENWN PERIVALLONTOS
	//METHOD WHICH PRINTS ALL THE OBJECTS FROM THE ENVIROMENT
	void ektypwsePerivallon();

	//METHODOS DIAGRAFHS DEDOMENWN
	//METHOD WHICH DELETES ALL THE OBJECTS
	void epanekinnisi(string onomArxeiou);
};
