#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int year;
	int day;
	int month;
public:
	Date();
	Date(int day, int month, int year);
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	friend ostream& operator<<(ostream&, Date&);
	friend istream& operator>>(istream&, Date&);
	bool operator == (const Date&);
	string toString();

	~Date();
};
