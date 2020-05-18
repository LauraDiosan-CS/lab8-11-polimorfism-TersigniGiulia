#pragma once
#include "IE.h"
class IIterator
{
public:
	virtual void moveNext() = 0;
	virtual bool hasNext() = 0;
	virtual bool isValid() = 0;
	virtual IE* getCrtElem() = 0;
	virtual void moveFirst() = 0;
	virtual ~IIterator() {};
};