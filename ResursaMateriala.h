#pragma once
#include "ResursaEconomica.h"
#include "IE.h"
#include <vector>
#include <string>
using namespace std;
class ResursaMateriala :public ResursaEconomica, public IE
{
private:
	int durataDeViata; // numar de zile
	int numarDeExemplare;
	void print(ostream& os, ResursaMateriala&) const;
	void read(istream& is, ResursaMateriala&) const;
public:
	ResursaMateriala();
	ResursaMateriala(ResursaMateriala& a);
	~ResursaMateriala();
	ResursaMateriala& operator=(const ResursaMateriala&);

	friend ostream& operator<<(ostream&, ResursaMateriala&);
	friend istream& operator>>(istream&, ResursaMateriala&);

	void setDurataDeViata(int durataDeViata);
	int getDurataDeViata();

	void setNumarDeExemplare(int numarDeExemplare);
	int getNumarDeExemplare();
	IE* clone() {
		ResursaMateriala* f = new ResursaMateriala;
		f->nume = this->nume;
		f->data = this->data;
		f->durataDeViata = this->durataDeViata;
		f->numarDeExemplare = this->numarDeExemplare;
		f->valoare = this->valoare;

		return f;
	}
	void copy(IE* e) {
		ResursaMateriala* f = (ResursaMateriala*)e;
		this->nume = f->nume;
		this->data = f->data;
		this->durataDeViata = f->durataDeViata;
		this->numarDeExemplare = f->numarDeExemplare;
		this->valoare = f->valoare;
	}
	bool equals(IE* e) {
		return (this->nume == ((ResursaMateriala*)e)->nume &&
			this->data == ((ResursaMateriala*)e)->data &&
			this->valoare == ((ResursaMateriala*)e)->valoare &&
			this->durataDeViata == ((ResursaMateriala*)e)->durataDeViata &&
			this->numarDeExemplare == ((ResursaMateriala*)e)->numarDeExemplare);
	}
	int compareTo(IE* e) {
		return ((ResursaMateriala*)e)->valoare > this->valoare;
	}
	string toString() {
		string special = "";
		if (this->valoare == 0 || this->numarDeExemplare == 0) {
			special = "<!>";
		}
		string s = special + this->nume + " " + this->data.toString() + " " + std::to_string(this->valoare) + " " + std::to_string(this->durataDeViata) + " " + std::to_string(this->numarDeExemplare) + special;
		return s;
	}
	string writeToFile() {
		string s = this->nume + "," + std::to_string(this->data.getDay()) + " " + std::to_string(this->data.getMonth()) + " " + std::to_string(this->data.getYear()) + "," + std::to_string(this->valoare) + "," + std::to_string(this->durataDeViata) + "," + std::to_string(this->numarDeExemplare) + "\n";
		return s;
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
	int getType() {
		return 2;
	}
};