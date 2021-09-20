#include "Hrwas.h"

Hrwas::Hrwas()
{
	onoma = "N/A";
	s = NULL;
	p = NULL;
}

Hrwas::Hrwas(string _onoma, Sakidio* _s, Perivallon* _p)
{
	onoma = _onoma;
	s = _s;
	p = _p;
}

Hrwas::Hrwas(const Hrwas& h)
{
	onoma = h.onoma;
	s = h.s;
	p = h.p;
}

string Hrwas::orismosStoxou()
{
	int st;
	string stoxos;

	cout << " ---------- STOXOI PAIXNIDIOU ----------" << endl;
	cout << "1) DHMIOURGIA FWTIAS" << endl;
	cout << "2) DHMIOURGIA PSITOU PSARIOU" << endl;
	cout << "3) DHMIOURGIA PSITOU KREATOS" << endl;
	cout << "4) DHMIOURGIA VRASTOU PSARIOU" << endl;
	cout << "5) DHMIOURGIA VRASTOU KREATOS" << endl;
	cout << "6) DHMIOURGIA GANTZOU ANARIXISHS" << endl;
	cout << "7) KAPSIMO XRIMATWN" << endl;
	cout << "TI THA EPILEKSEIS??? [1-7]" << endl;
	cout << "EPILOGH STOXOU: ";
	cin >> st;
	if (st == 1)
	{
		cout << endl;
		cout << "ORISTHKE H DHMIOURGIA FWTIAS WS STOXOS TOU PAXNIDIOU" << endl;
		stoxos = "FWTIA";
		cout << endl;
		return stoxos;
	}
	else if (st == 2)
	{
		cout << endl;
		cout << "ORISTHKE H DHMIOURGIA PSITOU PSARIOU WS STOXOS TOU PAXNIDIOU" << endl;
		stoxos = "PSARAKI";
		cout << endl;
		return stoxos;
	}
	else if (st == 3)
	{
		cout << endl;
		cout << "ORISTHKE H DHMIOURGIA PSITOU KREATOS WS STOXOS TOU PAXNIDIOU" << endl;
		stoxos = "KREATAKI";
		cout << endl;
		return stoxos;
	}
	else if (st == 4)
	{
		cout << endl;
		cout << "ORISTHKE H DHMIOURGIA VRASTOU PSARIOU WS STOXOS TOU PAXNIDIOU" << endl;
		stoxos = "PSAROSOUPA";
		cout << endl;
		return stoxos;
	}
	else if (st == 5)
	{
		cout << endl;
		cout << "ORISTHKE H DHMIOURGIA VRASTOU KREATOS WS STOXOS TOU PAXNIDIOU" << endl;
		stoxos = "KREATOSOUPA";
		cout << endl;
		return stoxos;
	}
	else if (st == 6)
	{
		cout << endl;
		cout << "ORISTHKE H DHMIOURGIA GANTZOU ANARIXISHS WS STOXOS TOU PAXNIDIOU" << endl;
		stoxos = "ANARIXISH";
		cout << endl;
		return stoxos;
	}
	else if (st == 7)
	{
		cout << endl;
		cout << "ORISTHKE TO KAPSIMO TWN XRIMATWN SAS WS STOXOS TOU PAXNIDIOU" << endl;
		stoxos = "AFRAGKOS";
		cout << endl;
		return stoxos;
	}
	else
	{
		cout << endl;
		cout << "LATHOS EPILOGH STOXOU!!!" << endl;
		cout << endl;
		stoxos = "";
		return stoxos;
	}
	return "";
}

void Hrwas::diavaseCSV(string onomArxeiou)
{
	ifstream file(onomArxeiou.c_str());
	string line, word;
	vector <string> tokens;
	Antikeimeno* it1;
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

			if (strcmp(tokens[2].c_str(), "SAKIDIO") == 0)
			{
				it1->setKwdikos(tokens[0]);
				it1->setOnoma(tokens[1]);
				it1->setTopothesia("SAKIDIO");
				arxikopoihseSakidio(it1);
			}
			else if (strcmp(tokens[2].c_str(), "PERIVALLON") == 0)
			{
				it1->setKwdikos(tokens[0]);
				it1->setOnoma(tokens[1]);
				it1->setTopothesia("PERIVALLON");
				arxikopoihsePerivallon(it1);
			}
		}
		file.close();
	}
	else
	{
		cout << "!!!! PROVLIMA ANOIGMATOS ARXEIOY !!!!" << endl;
	}
}

void Hrwas::arxikopoihseSakidio(Antikeimeno* x)
{
	s->prostheseAntikeimeno(x);
}

void Hrwas::arxikopoihsePerivallon(Antikeimeno* x)
{
	p->prostheseAntikeimeno(x);
}

void Hrwas::ektypwseSakidio()
{
	s->ektypwseAntikeimena();
}

void Hrwas::ektypwsePerivallon()
{
	p->ektypwseAntikeimena();
}

void Hrwas::epanekinnisi(string onomArxeiou)
{
	s->epanekkininshSakidiou();
	p->epanekkinishPerivallontos();
	diavaseCSV(onomArxeiou);
}

void Hrwas::grapseCSV(string onomArxeiou2)
{
	s->grapseAntikeimena(onomArxeiou2);
	p->grapseAntikeimena(onomArxeiou2);

}