#pragma once
#include "IE.h"
#include "IIterator.h"
class IContainer
{
public:
	virtual void addElem(IE*) = 0;
	virtual void removeElem(IE*) = 0;
	virtual int getSize() = 0;
	virtual bool contains(IE*) = 0;
	friend class IIterator;
	virtual IIterator* getIterator() = 0;
	virtual ~IContainer() {};
};