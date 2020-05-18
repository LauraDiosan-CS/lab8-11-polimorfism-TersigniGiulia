#pragma once
#include "ResursaEconomica.h"
#include "IE.h"
class ResursaFinanciara :public ResursaEconomica, public IE
{
private:
	string moneda;
	void print(ostream& os, ResursaFinanciara&) const;
	void read(istream& is, ResursaFinanciara&) const;
public:
	ResursaFinanciara();
	ResursaFinanciara(ResursaFinanciara& a);
	~ResursaFinanciara();
	ResursaFinanciara& operator=(const ResursaFinanciara&);
	void setMoneda(string moneda);
	string getMoneda();
	friend ostream& operator<<(ostream&, ResursaFinanciara&);
	friend istream& operator>>(istream&, ResursaFinanciara&);
	string toString();
	string writeToFile();
	int getType() {
		return 1;
	}
	IE* clone() {
		ResursaFinanciara* f = new ResursaFinanciara;
		f->nume = this->nume;
		f->data = this->data;
		f->moneda = this->moneda;
		f->valoare = this->valoare;

		return f;
	}
	void copy(IE* e) {
		ResursaFinanciara* f = (ResursaFinanciara*)e;
		this->nume = f->nume;
		this->data = f->data;
		this->moneda = f->moneda;
		this->valoare = f->valoare;
	}
	bool equals(IE* e) {
		return (this->nume == ((ResursaFinanciara*)e)->nume &&
			this->data == ((ResursaFinanciara*)e)->data &&
			this->valoare == ((ResursaFinanciara*)e)->valoare &&
			this->moneda == ((ResursaFinanciara*)e)->moneda
			);
	}
	int compareTo(IE* e) {
		return ((ResursaFinanciara*)e)->valoare > this->valoare;
	}
	bool nameEqual(string name) {
		size_t found = this->nume.find(name);
		if (found != string::npos) {
			return true;
		}
		return false;
	}
	bool dateEqual(Date date) {
		if (this->data == date) {
			return true;
		}
		return false;
	}

};