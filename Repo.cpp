#include "Repo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include "ResursaFinanciara.h"
#include "ResursaMateriala.h"
#include "BadTypeException.h"
const int MAX = 100;

using namespace std;

Repo::Repo()
{
	this->fileName = "";
}

Repo::Repo(string fileName)
{

	this->fileName = fileName;
	this->readFromFile();
}

Repo::Repo(Repo& r)
{
	this->resurse = r.resurse;

	this->fileName = r.fileName;
	this->readFromFile();
}


Repo::~Repo()
{
	this->fileName.~basic_string();
}

void Repo::adaugaResursa(IE* res)
{
	this->resurse->addElem(res);
}

void Repo::modificaResursa(IE* oldRes, IE* newRes)
{
	IIterator* it = this->resurse->getIterator();
	while (it->isValid()) {
		if (it->getCrtElem()->equals(oldRes)) {
			this->resurse->removeElem(oldRes);
			this->resurse->addElem(newRes);
		}
		it->moveNext();
	}
	ofstream f;
	f.open("Input.txt");
	if (!f.is_open()) {
		cout << "File not opened!";
		return;
	}
	it->moveFirst();
	while (it->isValid()) {
		f << it->getCrtElem()->writeToFile();
		it->moveNext();
	}
}


IContainer* Repo::GetAll()
{
	return this->resurse;
}

void Repo::setFileName(string fileName)
{

	this->fileName = fileName;
	this->readFromFile();
}

string Repo::getFileName()
{
	return this->fileName;
}
void Repo::printAll()
{
	IIterator* it = this->resurse->getIterator();
	int index = 1;
	while (it->isValid()) {
		cout << to_string(index) + ". " + it->getCrtElem()->toString() << endl;
		index++;
		it->moveNext();
	}
}
IE* Repo::findResursaByIndex(int index)
{
	int localIndex = 1;
	IIterator* it = this->resurse->getIterator();
	while (it->isValid()) {
		if (localIndex == index) {
			return it->getCrtElem()->clone();
		}
		else {
			localIndex++;
			it->moveNext();
		}
	}
	throw BadTypeException("Index out of bounds");
}
void Repo::readFromFile()
{
	fstream f;
	string line;
	f.open("Input.txt");
	if (!f.is_open()) {
		cout << "File not opened!";
		return;
	}
	while (getline(f, line))
	{
		string delimiter = ",";
		vector<string> words;
		size_t pos = 0;
		string token;
		while ((pos = line.find(delimiter)) != string::npos) {
			token = line.substr(0, pos);
			words.push_back(token);
			line.erase(0, pos + delimiter.length());
		}
		words.push_back(line);
		std::string::size_type sz;

		if (words.size() == 4) // resursa financiara
		{
			ResursaFinanciara* rf = new ResursaFinanciara();
			string nume;
			Date data;
			double valoare;
			string moneda;
			for (unsigned int i = 0; i < words.size(); i++)
			{
				stringstream ss(words[i]);
				switch (i)
				{
				case 0: {
					getline(ss, nume);
					break;
				}
				case 1: {
					try {
						ss >> data;
						if (data.getDay() > 31 || data.getDay() < 1 || data.getMonth() > 12 || data.getMonth() < 1 || data.getYear() < 2018)
						{
							throw BadTypeException("Invalid date!");
						}
					}
					catch (BadTypeException& ex) {
						cout << "Exception: " << ex.getMessage() << endl;
					}
					break;
				}
				case 2: {
					try {
						string val;
						ss >> val;

						if (val.find_first_not_of("0123456789-+.") != string::npos) {
							throw BadTypeException("Not an int");
						}
						valoare = stod(val, &sz);
						if (valoare < 0) {
							throw BadTypeException("Value cannot be <0");
						}
					}
					catch (BadTypeException& ex) {
						cout << "Exception: " << ex.getMessage() << endl;
					}

					break;
				}
				case 3: {
					try {
						ss >> moneda;
						if (moneda.find_first_of("0123456789-+.") != string::npos) {
							throw BadTypeException("Invalid currency");
						}
					}
					catch (BadTypeException& ex) {
						cout << "Exception: " << ex.getMessage() << endl;
					}
					break;
				}
				}
				ss.clear();
			}
			rf->setNume(nume);
			rf->setDate(data);
			rf->setValoare(valoare);
			rf->setMoneda(moneda);
			nume.~basic_string();
			moneda.~basic_string();
			this->resurse->addElem(rf);
		}
		else if (words.size() == 5) {
			ResursaMateriala* rm = new ResursaMateriala();
			string nume = "";
			Date data;
			double valoare = 0;
			int durataDeViata = 0;
			int numarDeExemplare = 0;
			for (unsigned int i = 0; i < words.size(); i++)
			{
				stringstream ss(words[i]);
				switch (i) {
				case 0: {
					getline(ss, nume);
					break;
				}
				case 1: {
					try {
						ss >> data;
						if (data.getDay() > 31 || data.getDay() < 1 || data.getMonth() > 12 || data.getMonth() < 1 || data.getYear() < 2018)
						{
							throw BadTypeException("Invalid date!");
						}
					}
					catch (BadTypeException& ex) {
						cout << "Exception: " << ex.getMessage() << endl;
					}
					break;
				}
				case 2: {
					try {
						string val;
						ss >> val;
						if (val.find_first_not_of("0123456789-+.") != string::npos) {
							throw BadTypeException("Not an int");
						}
						valoare = stod(val, &sz);
						if (valoare < 0) {
							throw BadTypeException("Value cannot be < 0");
						}
					}
					catch (BadTypeException& ex) {
						cout << "Exception: " << ex.getMessage() << endl;
					}

					break;
				}
				case 3: {
					try {
						string val;
						ss >> val;
						if (val.find_first_not_of("0123456789-+.") != string::npos) {
							throw BadTypeException("Not an int");
						}
						durataDeViata = stoi(val, &sz, 10);
						if (durataDeViata < 0) {
							throw BadTypeException("Durata de viata nu poate fi < 0");
						}
					}
					catch (BadTypeException& ex) {
						cout << "Exception: " << ex.getMessage() << endl;
					}

					break;
				}
				case 4: {
					try {
						string val;
						ss >> val;
						if (val.find_first_not_of("0123456789-+.") != string::npos) {
							throw BadTypeException("Not an int");
						}
						numarDeExemplare = stoi(val, &sz, 10);
						if (numarDeExemplare < 0) {
							throw BadTypeException("NumarDeExemplare nu poate fi < 0");
						}
					}
					catch (BadTypeException& ex) {
						cout << "Exception: " << ex.getMessage() << endl;
					}

					break;
				}
				}
				ss.clear();
			}
			rm->setNume(nume);
			rm->setDate(data);
			rm->setValoare(valoare);
			rm->setDurataDeViata(durataDeViata);
			rm->setNumarDeExemplare(numarDeExemplare);
			this->resurse->addElem(rm);
			nume.~basic_string();
		}

		words.~vector();
	}

}