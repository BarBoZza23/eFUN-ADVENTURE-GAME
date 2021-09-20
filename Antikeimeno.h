#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Antikeimeno
{
private:
	string onoma;
	string kwdikos;
	string topothesia;
public:
	//DEFAULT EMPTY CONSTRUCTOR
	Antikeimeno();
	
	//DEFAULT FULL CONSTRUCTOR
	Antikeimeno(string _kwdikos, string _onoma, string _topothesia);
	
	//DEFAULT COPY CONSTRUCTOR
	Antikeimeno(const Antikeimeno& x);
	
	//GETTERS
	string getOnoma() const { return onoma; }
	string getKwdiko() const { return kwdikos; }
	string getTopothesia() const { return topothesia; }
	
	//SETTERS
	void setOnoma(string _onoma) { onoma = _onoma; }
	void setKwdikos(string _kwdikos) { kwdikos = _kwdikos; }
	void setTopothesia(string _topothesia) { topothesia = _topothesia; }
};