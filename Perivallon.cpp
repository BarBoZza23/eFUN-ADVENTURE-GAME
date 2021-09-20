#include "Perivallon.h"

Perivallon::Perivallon()
{

}

Perivallon::Perivallon(const Perivallon& per)
{
	pAntikeimena = per.pAntikeimena;
}

void Perivallon::prostheseAntikeimeno(Antikeimeno* x)
{
	pAntikeimena.push_back(x);
}

int Perivallon::prosthikiAntikeimenou(string onoma, string onomaArxeiou)
{
	vector<Antikeimeno*>::iterator per;
	ifstream file(onomaArxeiou.c_str());
	string line, word;
	vector <string> tokens;
	Antikeimeno* it1;
	int found = 0;
	int prosthiki = 0;
	int i = 2;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			tokens.clear();
			stringstream s(line);

			while (getline(s, word, ','))
			{
				tokens.push_back(word);
			}
			it1 = new Antikeimeno(tokens[0], tokens[1], tokens[2]);

			it1->setKwdikos(tokens[0]);
			it1->setOnoma(tokens[1]);
			it1->setTopothesia(tokens[2]);

			if (found != 1)
			{
				for (per = pAntikeimena.begin(); per != pAntikeimena.end(); per++)
				{
					if (strcmp((*per)->getOnoma().c_str(), onoma.c_str()) == 0)
					{
						cout << "TO ANTIKEIMENO " << onoma << " HDH YPARXEI STO PERIVALLON" << endl;
						found = 1;
						break;
					}
					else if (strcmp((it1)->getOnoma().c_str(), onoma.c_str()) == 0)
					{
						prosthiki = 1;
						found = 1;
						it1->setTopothesia("PERIVALLLON");
						pAntikeimena.push_back((it1));
						break;
					}
				}
			}
			else
			{
				break;
			}

		}

		if (prosthiki == 1)
		{
			cout << "EPITYXHS PROSTHIKI ANTIKEIMENOU " << onoma << " STO PERIVALLON" << endl;
			return 1;
		}
		else
		{
			cout << "TO ANTIKEIMENO ME ONOMA " << onoma << " DEN MPIKE STO PERIVALLON" << endl;
			return 0;
		}
	}
	else
	{
		cout << "!!!! PROVLIMA ANOIGMATOS ARXEIOY !!!!" << endl;
	}

	return 0;
}

int Perivallon::afaireshAntikeimenou(string onoma)
{
	vector<Antikeimeno*>::iterator per;
	int afairesh = 0;

	for (per = pAntikeimena.begin(); per != pAntikeimena.end(); per++)
	{
		if (strcmp((*per)->getOnoma().c_str(), onoma.c_str()) == 0)
		{
			afairesh = 1;
			per = pAntikeimena.erase(per);
			break;
		}
	}
	if (afairesh == 1)
	{
		cout << "EPITYXHS AFAIRESH ANTIKEIMENOU " << onoma <<" APO TO PERIVALLON"<< endl;
		return 1;
	}
	else
	{
		cout << "DEN VRETHIKE ANTIKEIMENO ME ONOMA " << onoma << " STO PERIVALLON" << endl;
		return 0;
	}
}

void Perivallon::syndyaseAntikeimena(string ant1, string ant2, string stoxos)
{
	vector<Antikeimeno*>::iterator per;
	Antikeimeno* it;
	int afairesh1 = 0;
	int afairesh2 = 0;
	int syndyasmos = 0;
	string ncode = "";
	string newAnt = "";


	if ((strcmp(ant1.c_str(), ant2.c_str())) != 0)
	{
		if ((strcmp(ant1.c_str(), "SPIRTA") == 0) || (strcmp(ant1.c_str(), "XSYLA") == 0))
		{
			if ((strcmp(ant2.c_str(), "XSYLA") == 0) || (strcmp(ant2.c_str(), "SPIRTA") == 0))
			{
				newAnt = "FWTIA";
				syndyasmos = 1;
			}
		}

		if ((strcmp(ant1.c_str(), "ANAPTIRAS") == 0) || (strcmp(ant1.c_str(), "XSYLA") == 0))
		{
			if ((strcmp(ant2.c_str(), "XSYLA") == 0) || (strcmp(ant2.c_str(), "ANAPTIRAS") == 0))
			{
				newAnt = "FWTIA";
				syndyasmos = 1;
			}
		}

		if ((strcmp(ant1.c_str(), "FWTIA") == 0) || (strcmp(ant1.c_str(), "PSARI") == 0))
		{
			if ((strcmp(ant2.c_str(), "PSARI") == 0) || (strcmp(ant2.c_str(), "FWTIA") == 0))
			{
				newAnt = "PSARAKI";
				syndyasmos = 1;
			}
		}

		if ((strcmp(ant1.c_str(), "FWTIA") == 0) || (strcmp(ant1.c_str(), "KREAS") == 0))
		{
			if ((strcmp(ant2.c_str(), "KREAS") == 0) || (strcmp(ant2.c_str(), "FWTIA") == 0))
			{
				newAnt = "KREATAKI";
				syndyasmos = 1;
			}
		}

		if ((strcmp(ant1.c_str(), "FWTIA") == 0) || (strcmp(ant1.c_str(), "KATSAROLA") == 0))
		{
			if ((strcmp(ant2.c_str(), "KATSAROLA") == 0) || (strcmp(ant2.c_str(), "FWTIA") == 0))
			{
				newAnt = "ZESTH_KATSAROLA";
				syndyasmos = 1;
			}
		}

		if ((strcmp(ant1.c_str(), "ZESTH_KATSAROLA") == 0) || (strcmp(ant1.c_str(), "PSARI") == 0))
		{
			if ((strcmp(ant2.c_str(), "PSARI") == 0) || (strcmp(ant2.c_str(), "ZESTH_KATSAROLA") == 0))
			{
				newAnt = "PSAROSOUPA";
				syndyasmos = 1;
			}
		}

		if ((strcmp(ant1.c_str(), "ZESTH_KATSAROLA") == 0) || (strcmp(ant1.c_str(), "KREAS") == 0))
		{
			if ((strcmp(ant2.c_str(), "KREAS") == 0) || (strcmp(ant2.c_str(), "ZESTH_KATSAROLA") == 0))
			{
				newAnt = "KREATOSOUPA";
				syndyasmos = 1;
			}
		}

		if ((strcmp(ant1.c_str(), "GANTZOS") == 0) || (strcmp(ant1.c_str(), "SXOINI") == 0))
		{
			if ((strcmp(ant2.c_str(), "SXOINI") == 0) || (strcmp(ant2.c_str(), "GANTZOS") == 0))
			{
				newAnt = "ANARIXISH";
				syndyasmos = 1;
			}
		}

		if ((strcmp(ant1.c_str(), "FWTIA") == 0) || (strcmp(ant1.c_str(), "XRIMATA") == 0))
		{
			if ((strcmp(ant2.c_str(), "XRIMATA") == 0) || (strcmp(ant2.c_str(), "FWTIA") == 0))
			{
				newAnt = "AFRAGKOS";
				syndyasmos = 1;
			}
		}

		if (syndyasmos == 0)
		{
			cout << endl;
			cout << "!!!! AYTA TA ANTIKEIMENA DEN SYNDYAZONTAI METAKSY TOUS !!!!" << endl;
			cout << endl;
		}
	}
	else
	{
		cout << endl;
		cout << "!!!! DEN SYNDYAZONTAI DYO IDIA ANTIKEIMENA !!!!" << endl;
		cout << endl;
	}

	if (syndyasmos == 1)
	{
		for (per = pAntikeimena.begin(); per != pAntikeimena.end(); per++)
		{
			if (strcmp((*per)->getOnoma().c_str(), ant1.c_str()) == 0)
			{
				ncode = (*per)->getKwdiko().c_str();
				afairesh1 = 1;
				per = pAntikeimena.erase(per);
				break;
			}
		}

		for (per = pAntikeimena.begin(); per != pAntikeimena.end(); per++)
		{
			if (strcmp((*per)->getOnoma().c_str(), ant2.c_str()) == 0)
			{
				ncode = (*per)->getKwdiko().c_str();
				afairesh2 = 1;
				per = pAntikeimena.erase(per);
				break;
			}
		}

		if (afairesh1 == 1)
		{
			cout << "EPITYXHS AFAIRESH ANTIKEIMENOU " << ant1 << endl;
		}
		else if (afairesh1 == 0)
		{
			cout << "DEN VRETHIKE ANTIKEIMENO ME ONOMA " << ant1 << endl;
		}

		if (afairesh2 == 1)
		{
			cout << "EPITYXHS AFAIRESH ANTIKEIMENOU " << ant2 << endl;
		}
		else if (afairesh2 == 0)
		{
			cout << "DEN VRETHIKE ANTIKEIMENO ME ONOMA " << ant2 << endl;
		}

		if (afairesh1 == afairesh2 == 1)
		{
			it = new Antikeimeno(ncode, newAnt, "PERIVALLON");
			pAntikeimena.push_back(it);
			cout << "TO NEO ANTIKEIMENO ME ONOMA " << newAnt << " MPIKE STO PERIVALLON" << endl;
		}
		else
		{
			cout << "TO NEO ANTIKEIMENO ME ONOMA " << newAnt << " DEN DHMIOURGITHIKE" << endl;
		}

		if (strcmp(newAnt.c_str(), stoxos.c_str()) == 0)
		{
			cout << endl;
			cout << endl;
			cout << "!!! SYGXARHTHRIA !!!" << endl;
			cout << "!!! KERDISATE TO PAIXNIDI !!!" << endl;
			cout << endl;
			cout << endl;
			exit(0);
		}
	}
}

void Perivallon::grapseAntikeimena(string onomArxeiou2)
{
	ofstream file(onomArxeiou2.c_str(),std::ios_base::app);
	vector<Antikeimeno*>::iterator per;
	int i = 0;
	if (file.is_open())
	{
		for (per = pAntikeimena.begin(); per != pAntikeimena.end(); per++)
		{
			file << (*per)->getKwdiko().c_str()
				<< "," << (*per)->getOnoma().c_str()
				<< "," << (*per)->getTopothesia().c_str() << endl;
		}
	}
	else
	{
		cout << "!!!! PROVLIMA ANOIGMATOS ARXEIOY !!!!" << endl;
	}
}

void Perivallon::epanekkinishPerivallontos()
{
	vector<Antikeimeno*>::iterator per;

	pAntikeimena.clear();
}

void Perivallon::ektypwseAntikeimena()
{
	cout << " ------------ ANTIKEIMENA PERIVALLONTOS ------------" << endl;

	vector <Antikeimeno*>::iterator it;
	int i = 1;
	for (it = pAntikeimena.begin(); it != pAntikeimena.end(); it++)
	{
		cout << i << "o) ANTIKEIMENO: " << (*it)->getKwdiko() << " " << (*it)->getOnoma() << endl;
		i++;
	}
}


ostream& operator <<(ostream& channel, Perivallon const& x)
{
	vector <Antikeimeno*>::iterator it;
	int i = 0;

	for ( i=0; i != x.pAntikeimena.size(); i++)
	{
		channel << i << "o) ANTIKEIMENO: " << (*it)->getKwdiko() << " " << (*it)->getOnoma() << endl;
		it++;
	}
	return channel;//RETURNS ADDRESS NOT OBJECTS
}