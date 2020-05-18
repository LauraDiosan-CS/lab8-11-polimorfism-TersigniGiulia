#include "ResursaFinanciara.h"
#include <string>

ResursaFinanciara::ResursaFinanciara() :ResursaEconomica()
{
	this->moneda = "";
}

ResursaFinanciara::ResursaFinanciara(ResursaFinanciara& rf) : ResursaEconomica(rf)
{
	this->moneda = rf.moneda;
}


ResursaFinanciara::~ResursaFinanciara()
{
	this->moneda.~basic_string();
}

ResursaFinanciara& ResursaFinanciara::operator=(const ResursaFinanciara& rf)
{
	if (this != &rf) {
		ResursaEconomica::operator=(rf);

		this->moneda = rf.moneda;
	}
	return *this;
}

void ResursaFinanciara::setMoneda(string moneda)
{

	this->moneda = moneda;
}

string ResursaFinanciara::getMoneda()
{
	return this->moneda;
}

void ResursaFinanciara::print(ostream& os, ResursaFinanciara& rf) const
{
	ResursaEconomica::print(os, rf);
	os << "Moneda: " << rf.moneda << endl;
}
void ResursaFinanciara::read(istream& is, ResursaFinanciara& rf) const
{
	cout << "Nume/Data intrarii in companie/Valoare/Moneda" << endl;
	is >> rf.nume >> rf.data >> rf.valoare >> rf.moneda;
}
ostream& operator<<(ostream& os, ResursaFinanciara& rf)
{
	rf.print(os, rf);
	return os;
}

istream& operator>>(istream& is, ResursaFinanciara& rf)
{
	rf.read(is, rf);
	return is;
}
string ResursaFinanciara::toString() {
	string special = "";
	if (this->valoare == 0) {
		special = "<!>";
	}
	string s = special + this->nume + " " + this->data.toString() + " " + std::to_string(this->valoare) + " " + this->moneda + special;
	return s;
}
string ResursaFinanciara::writeToFile() {
	string s = this->nume + "," + std::to_string(this->data.getDay()) + " " + std::to_string(this->data.getMonth()) + " " + std::to_string(this->data.getYear()) + "," + std::to_string(this->valoare) + "," + this->moneda + "\n";
	return s;
}