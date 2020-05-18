#include "Date.h"
#include <string>


Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 0000;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getDay()
{
	return this->day;
}

int Date::getMonth()
{
	return this->month;
}

int Date::getYear()
{
	return this->year;
}

void Date::setDay(int day)
{
	this->day = day;
}

void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setYear(int year)
{
	this->year = year;
}

Date::~Date()
{
}
istream& operator>>(istream& is, Date& d) {
	is >> d.day >> d.month >> d.year;
	return is;
}
ostream& operator<<(ostream& os, Date& d) {
	os << d.day << "/" << d.month << "/" << d.year;
	return os;
}
bool Date::operator == (const Date& d) {
	return this->day == d.day && this->month == d.month && this->year == d.year;
}

string Date::toString()
{
	return std::to_string(this->day) + "/" + std::to_string(this->month) + "/" + std::to_string(this->year);
}