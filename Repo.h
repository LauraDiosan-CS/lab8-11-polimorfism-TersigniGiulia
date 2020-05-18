#pragma once
#include "ResursaEconomica.h"
#include "ArrayContainer.h"
class Repo
{
private:
	IContainer* resurse = new ArrayContainer(5);

	string fileName;
	void readFromFile();
public:
	Repo();
	Repo(string fileName);
	Repo(Repo& r);
	~Repo();
	void adaugaResursa(IE* res);
	void modificaResursa(IE* oldRes, IE* newRes);
	IContainer* GetAll();
	void setFileName(string fileName);
	string getFileName();
	void printAll();
	IE* findResursaByIndex(int index);
};