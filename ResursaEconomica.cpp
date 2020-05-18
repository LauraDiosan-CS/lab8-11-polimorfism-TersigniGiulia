#include "ResursaEconomica.h"
#include <iostream>
#include "Date.h"
using namespace std;

void ResursaEconomica::print(ostream& os, ResursaEconomica& re) const
{
	os << "Nume: " << re.nume << endl;
	os << "Data intrarii in companie: " << re.data << endl;
	os << "Valoare: " << re.valoare << endl;
}

void ResursaEconomica::read(istream& is, ResursaEconomica& re) const
{
	cout << "Nume/Data intrarii in companie/Valoare" << endl;
	is >> re.nume >> re.data >> re.valoare;
}

ResursaEconomica::ResursaEconomica()
{

	this->nume = "";
	this->data = Date(1, 1, 0000);
	this->valoare = 0;
}

ResursaEconomica::ResursaEconomica(const ResursaEconomica& b)
{

	this->nume = b.nume;
	this->data = b.data;
	this->valoare = b.valoare;
}


ResursaEconomica::~ResursaEconomica()
{

	this->nume.~basic_string();
}

ResursaEconomica& ResursaEconomica::operator=(const ResursaEconomica& b)
{
	if (this != &b) {
		this->nume = b.nume;
		this->data = b.data;
		this->valoare = b.valoare;
	}
	return *this;
}


void ResursaEconomica::setNume(string nume)
{
	this->nume = nume;
}

string ResursaEconomica::getNume()
{
	return this->nume;
}

void ResursaEconomica::setDate(Date date)
{
	this->data = date;
}

Date ResursaEconomica::getDate()
{
	return this->data;
}

void ResursaEconomica::setValoare(double valoare)
{
	this->valoare = valoare;
}

double ResursaEconomica::getValoare()
{
	return this->valoare;
}

ostream& operator<<(ostream& os, ResursaEconomica& b)
{
	b.print(os, b);
	return os;
}

istream& operator>>(istream& is, ResursaEconomica& b)
{
	b.read(is, b);
	return is;
}