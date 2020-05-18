#include "ResursaMateriala.h"

void ResursaMateriala::print(ostream& os, ResursaMateriala& f) const
{
	ResursaEconomica::print(os, f);
	os << "Durata de viata: " << f.durataDeViata << endl;
	os << "Numar de exemplare: " << f.numarDeExemplare << endl;
}

void ResursaMateriala::read(istream& is, ResursaMateriala& f) const
{

	cout << "Nume/Data intrarii in companie/Valoare/Durata de viata/Numar de exemplare" << endl;;
	is >> f.nume >> f.data >> f.valoare >> f.durataDeViata >> f.numarDeExemplare;
}

ResursaMateriala::ResursaMateriala() :ResursaEconomica()
{
	this->durataDeViata = 0;
	this->numarDeExemplare = 0;
}

ResursaMateriala::ResursaMateriala(ResursaMateriala& f) :ResursaEconomica(f)
{
	this->durataDeViata = f.durataDeViata;
	this->numarDeExemplare = f.numarDeExemplare;
}


ResursaMateriala::~ResursaMateriala()
{
}

ResursaMateriala& ResursaMateriala::operator=(const ResursaMateriala& f)
{
	if (this != &f) {
		ResursaEconomica::operator=(f);
		this->numarDeExemplare = f.numarDeExemplare;
		this->durataDeViata = f.durataDeViata;
	}
	return *this;
}


ostream& operator<<(ostream& os, ResursaMateriala& f)
{
	f.print(os, f);
	return os;
}

istream& operator>>(istream& in, ResursaMateriala& f)
{
	f.read(in, f);
	return in;
}

void ResursaMateriala::setDurataDeViata(int durataDeViata)
{
	this->durataDeViata = durataDeViata;
}

int ResursaMateriala::getDurataDeViata()
{
	return this->durataDeViata;
}

void ResursaMateriala::setNumarDeExemplare(int numarDeExemplare)
{
	this->numarDeExemplare = numarDeExemplare;
}

int ResursaMateriala::getNumarDeExemplare()
{
	return this->numarDeExemplare;
}