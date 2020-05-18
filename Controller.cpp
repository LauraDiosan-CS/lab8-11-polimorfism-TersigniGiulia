#include "Controller.h"
#include "BadTypeException.h"
bool Controller::logIn(string username, string password)
{
	if (username == "emilia" && password == "1234") {
		this->isLoggedIn = true;
		return true;
	}
	return false;
}

void Controller::printAll()
{
	this->r->printAll();
}

void Controller::logOut()
{
	this->isLoggedIn = false;
}

Controller::Controller()
{
	this->isLoggedIn = false;
	this->r = new Repo("Input.txt");
}

Controller::Controller(const Controller& c)
{
	this->r = c.r;
	this->isLoggedIn = c.isLoggedIn;

}


Controller::~Controller()
{
	if (this->r) {
		delete this->r;
		this->r = NULL;
	}
}

bool Controller::logged()
{
	return this->isLoggedIn;
}

IContainer* Controller::findResursaByName(string name)
{
	IContainer* c = this->r->GetAll();
	IIterator* it = c->getIterator();
	IContainer* result = new ArrayContainer(5);
	while (it->isValid()) {
		if (it->getCrtElem()->nameEqual(name)) {
			result->addElem(it->getCrtElem()->clone());
		}
		it->moveNext();
	}
	return result;
}

IContainer* Controller::findResursaByData(Date dataAdaugarii)
{
	IContainer* c = this->r->GetAll();
	IIterator* it = c->getIterator();
	IContainer* result = new ArrayContainer(5);
	while (it->isValid()) {
		if (it->getCrtElem()->dateEqual(dataAdaugarii)) {
			result->addElem(it->getCrtElem()->clone());
		}
		it->moveNext();
	}
	return result;
}

IE* Controller::findResursaByIndex(int index)
{
	try {
		return this->r->findResursaByIndex(index);

	}
	catch (BadTypeException& ex) {
		throw BadTypeException(ex.getMessage());
	}
}

void Controller::modificaResursa(IE* oldRes, IE* newRes)
{
	this->r->modificaResursa(oldRes, newRes);
}