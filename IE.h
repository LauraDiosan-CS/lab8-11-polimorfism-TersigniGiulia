#pragma once
#include <string>
#include "Date.h"
using namespace std;
class IE
{
public:
	virtual IE* clone() = 0;
	virtual void copy(IE*) = 0;
	virtual bool equals(IE*) = 0;
	virtual int compareTo(IE*) = 0;
	virtual string toString() = 0;
	virtual bool nameEqual(string name) = 0;
	virtual bool dateEqual(Date date) = 0;
	virtual string writeToFile() = 0;
	virtual int getType() = 0;
	virtual ~IE() {};
};