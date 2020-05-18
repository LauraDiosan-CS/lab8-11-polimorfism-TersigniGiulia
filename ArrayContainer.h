#pragma once
#include "IContainer.h"
#include <iostream>
class ArrayContainer : public IContainer {
private:
	int size;
	int capacity;
	IE** elements;
	void resize();
public:
	ArrayContainer(int c);
	ArrayContainer(const ArrayContainer& ac);
	~ArrayContainer();
	ArrayContainer& operator=(const ArrayContainer& ac);
	void addElem(IE* e);
	void removeElem(IE* e);
	int getSize();
	bool contains(IE* e);
	friend class ArrayIterator;
	IIterator* getIterator();
};

class ArrayIterator : public IIterator {
private:
	ArrayContainer* container;
	int crtPos;
public:
	ArrayIterator(ArrayContainer* ac) {
		container = ac;
		crtPos = 0;
	}
	~ArrayIterator() {

	}
	void moveNext() {
		crtPos++;
	}
	bool hasNext() {
		return (crtPos < container->getSize() - 1);
	}
	bool isValid() {
		return (crtPos < container->getSize());
	}
	IE* getCrtElem() {
		return container->elements[crtPos];
	}
	void moveFirst() {
		crtPos = 0;
	}
};