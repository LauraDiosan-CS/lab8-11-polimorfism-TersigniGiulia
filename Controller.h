#pragma once
#include <string>
#include "Repo.h"
using namespace std;
class Controller
{
private:
	Repo* r;
	bool isLoggedIn;

public:
	Controller();
	Controller(const Controller& c);
	bool logIn(string username, string password);
	void printAll();
	void logOut();
	~Controller();
	bool logged();
	IContainer* findResursaByName(string name);
	IContainer* findResursaByData(Date dataAdaugarii);
	IE* findResursaByIndex(int index);
	void modificaResursa(IE* oldRes, IE* newRes);
};