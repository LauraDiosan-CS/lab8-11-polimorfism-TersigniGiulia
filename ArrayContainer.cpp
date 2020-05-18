#include "ArrayContainer.h"


void ArrayContainer::resize() {
	IE** aux = new IE * [2 * capacity];
	for (int i = 0; i < capacity; i++)
		aux[i] = elements[i]->clone();
	delete[] elements;
	elements = aux;
	capacity *= 2;
}
ArrayContainer::ArrayContainer(int c) {
	size = 0;
	capacity = c;
	elements = new IE * [c];
}
ArrayContainer::ArrayContainer(const ArrayContainer& ac) {
	size = ac.size;
	capacity = ac.capacity;
	elements = new IE * [ac.capacity];
	for (int i = 0; i < ac.size; i++)
		elements[i] = ac.elements[i]->clone();
}
ArrayContainer::~ArrayContainer() {
	if (elements) {
		for (int i = 0; i < size; i++)
			if (elements[i]) {
				delete elements[i];
				elements[i] = NULL;
			}
		delete[] elements;
		elements = NULL;
	}
}
ArrayContainer& ArrayContainer::operator=(const ArrayContainer& ac) {
	if (this != &ac) {
		size = ac.size;
		capacity = ac.capacity;
		if (elements) {
			for (int i = 0; i < size; i++)
				if (elements[i]) {
					delete elements[i];
					elements[i] = NULL;
				}
			delete[] elements;
		}
		elements = new IE * [ac.capacity];
		for (int i = 0; i < ac.size; i++)
			elements[i] = ac.elements[i]->clone();
	}
	return *this;
}
void ArrayContainer::addElem(IE* e) {
	if (size >= capacity)
		resize();
	elements[size++] = e->clone();
}
void ArrayContainer::removeElem(IE* e) {
	int i = 0;
	while (i < size) {
		if (e->equals(elements[i])) {
			delete elements[i];
			for (int j = i; j < size - 1; j++)
				elements[j] = elements[j + 1];
			size--;
		}
		else
			i++;
	}
}
int ArrayContainer::getSize() {
	return size;
}
bool ArrayContainer::contains(IE* e) {
	for (int i = 0; i < size; i++)
		if (e->equals(elements[i]))
			return true;
	return false;
}
IIterator* ArrayContainer::getIterator() {
	return new ArrayIterator(this);
}