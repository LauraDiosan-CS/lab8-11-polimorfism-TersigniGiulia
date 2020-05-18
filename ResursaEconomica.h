#pragma once
#include "Date.h"
class ResursaEconomica
{
protected:
	string nume;
	Date data;
	double valoare;
	virtual void print(ostream& os, ResursaEconomica&) const;
	virtual void read(istream& is, ResursaEconomica&) const;
public:
	ResursaEconomica();
	ResursaEconomica(const ResursaEconomica&);
	virtual ~ResursaEconomica();
	virtual ResursaEconomica& operator = (const ResursaEconomica&);
	friend ostream& operator<<(ostream&, ResursaEconomica&);
	friend istream& operator>>(istream&, ResursaEconomica&);

	void setNume(string nume);
	string getNume();

	void setDate(Date date);
	Date getDate();

	void setValoare(double valoare);
	double getValoare();
};