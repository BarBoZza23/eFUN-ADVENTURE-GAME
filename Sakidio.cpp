#include "Sakidio.h"

Sakidio::Sakidio()
{

}

Sakidio::Sakidio(const Sakidio& sack)
{
	antikeimena = sack.antikeimena;
}

void Sakidio::prostheseAntikeimeno(Antikeimeno* x)
{

	if (antikeimena.size() < 7)
	{
		antikeimena.push_back(x);
	}
	else
	{
		cout << "!!!! TO SAKIDIO EINAI GEMATO !!!!" << endl;
		cout << "!!!! AN THELETE NA PROSTHESETE ANTIKEIMENO, AFAIRESTE ENA PRWTA !!!!" << endl;
	}
}

int Sakidio::prosthikiAntikeimenou(string onoma, string onomArxeiou)
{
	vector<Antikeimeno*>::iterator sak;
	ifstream file(onomArxeiou.c_str());
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
			it1 = new Antikeimeno(tokens[0], tokens[1],tokens[2]);

			it1->setKwdikos(tokens[0]);
			it1->setOnoma(tokens[1]);
			it1->setTopothesia(tokens[2]);

			if (found != 1)
			{
				for (sak = antikeimena.begin(); sak != antikeimena.end(); sak++)
				{
					if (strcmp((*sak)->getOnoma().c_str(), onoma.c_str()) == 0)
					{
						cout << "TO ANTIKEIMENO " << onoma << " HDH YPARXEI STO SAKIDIO" << endl;
						found = 1;
						break;
					}
					else if (strcmp((it1)->getOnoma().c_str(), onoma.c_str()) == 0)
					{
						if (antikeimena.size() < 7)
						{
							prosthiki = 1;
							found = 1;
							it1->setTopothesia("SAKIDIO");
							antikeimena.push_back((it1));
							break;
						}
						else
						{
							cout << "!!!! TO SAKIDIO EINAI GEMATO !!!!" << endl;
							cout << "!!!! AN THELETE NA PROSTHESETE ANTIKEIMENO, AFAIRESTE ENA PRWTA !!!!" << endl;
							break;
						}
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
			cout << "EPITYXHS PROSTHIKI ANTIKEIMENOU " << onoma << " STO SAKIDIO" << endl;
			return 1;
		}
		else
		{
			cout << "TO ANTIKEIMENO ME ONOMA " << onoma << " DEN MPIKE STO SAKIDIO" << endl;
			return 0;
		}
	}
	return 0;
}

int Sakidio::afaireshAntikeimenou(string onoma)
{
	vector<Antikeimeno*>::iterator sak;
	int afairesh = 0;

	for (sak = antikeimena.begin(); sak != antikeimena.end(); sak++)
	{
		if (strcmp((*sak)->getOnoma().c_str(), onoma.c_str()) == 0)
		{
			afairesh = 1;
			antikeimena.erase(sak);
			break;
		}
	}
	if (afairesh == 1)
	{
		cout << "EPITYXHS AFAIRESH ANTIKEIMENOU " << onoma << " APO TO SAKIDIO" <<endl;
		return 1;
	}
	else
	{
		cout << "DEN VRETHIKE ANTIKEIMENO ME ONOMA " << onoma << " STO SAKIDIO" << endl;
		return 0;
	}
}

void Sakidio::syndyaseAntikeimena(string ant1, string ant2, string stoxos)
{
	vector<Antikeimeno*>::iterator sak;
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
		for (sak = antikeimena.begin(); sak != antikeimena.end(); sak++)
		{
			if (strcmp((*sak)->getOnoma().c_str(), ant1.c_str()) == 0)
			{
				ncode = (*sak)->getKwdiko().c_str();
				afairesh1 = 1;
				antikeimena.erase(sak);
				break;
			}
		}

		for (sak = antikeimena.begin(); sak != antikeimena.end(); sak++)
		{
			if (strcmp((*sak)->getOnoma().c_str(), ant2.c_str()) == 0)
			{
				afairesh2 = 1;
				antikeimena.erase(sak);
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
			it = new Antikeimeno(ncode, newAnt,"SAKIDIO");
			antikeimena.push_back(it);
			cout << "TO NEO ANTIKEIMENO ME ONOMA " << newAnt << " MPIKE STO SAKIDIO" << endl;
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

void Sakidio::grapseAntikeimena(string onomArxeiou2)
{
	ofstream file(onomArxeiou2.c_str(), std::ios_base::app);
	vector<Antikeimeno*>::iterator sak;
	int i = 0;
	if (file.is_open())
	{
		for (sak = antikeimena.begin(); sak != antikeimena.end(); sak++)
		{
			file << (*sak)->getKwdiko().c_str()
				<< "," << (*sak)->getOnoma().c_str()
				<< "," << (*sak)->getTopothesia().c_str() << endl;
		}
	}
	else
	{
		cout << "!!!! PROVLIMA ANOIGMATOS ARXEIOY !!!!" << endl;
	}
}

void Sakidio::epanekkininshSakidiou()
{
	vector<Antikeimeno*>::iterator sak;

	antikeimena.clear();
}

void Sakidio::ektypwseAntikeimena()
{
	cout << " ------------ ANTIKEIMENA SAKIDIOU ------------" << endl;

	vector <Antikeimeno*>::iterator it;
	int i = 1;
	for (it = antikeimena.begin(); it != antikeimena.end(); it++)
	{

		cout << i << "o) ANTIKEIMENO: " << (*it)->getKwdiko() << " " << (*it)->getOnoma() << endl;
		i++;
	}
}

ostream& operator <<(ostream& channel, Sakidio const& x)
{
	vector <Antikeimeno*>::iterator it;
	int i = 0;

	for ( i=0; i != x.antikeimena.size(); i++)
	{
		channel << i << "o) ANTIKEIMENO: " << (*it)->getKwdiko() << " " << (*it)->getOnoma() << endl;
		it++;
	}

	return channel; //RETURNS ADDRESS NOT OBJECTS
}