#include "Antikeimeno.h"

Antikeimeno::Antikeimeno()
{

}

Antikeimeno::Antikeimeno(string _kwdikos, string _onoma, string _topothesia)
{
	kwdikos = _kwdikos;
	onoma = _onoma;
	topothesia = _topothesia;
}

Antikeimeno::Antikeimeno(const Antikeimeno& x)
{
	kwdikos = x.kwdikos;
	onoma = x.onoma;
	topothesia = x.topothesia;
}