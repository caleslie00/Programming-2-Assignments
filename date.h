#include <iostream>
using namespace std;


struct Date {
    int year;
    int month;
    int day;
};

int monthLength(int month, int year)//returns the number of days in this specific month based on the number of the month and what year it is
{
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
}

Date getTomorrow(Date d)
{
	d.day++;
	if(d.day > monthLength(d.month, d.year)) //checks to see if the day count is begger than it is supposed to be for this month
	{
		d.day = 1;
		d.month++;
		if(d.month > 12) //if the day is a higher number than it can be for that month then it increases the month and then makes sure the month isn't greater than 13, if so it adjusts the month and year
		{
			d.month = 1;
			d.year++;
		}
	}
	return d;
}

Date operator+(Date d, int increment) //adds increment days to the date
{
	for(int i = 0; i < increment; i++)
		d = getTomorrow(d);
	return d;
}

bool operator<(Date l, Date r) //returns true if l is an earlier date than r
{
	if(l.year == r.year)
	{
		if(l.month == r.month)
		{
			return l.day < r.day;
		}
		return l.month < r.month;
	}
	return l.year < r.year;
}

bool operator<=(Date l, Date r) //returns true if l is an earlier date or the same date as r 
{
	if(l.year == r.year)
	{
		if(l.month == r.month)
		{
			return l.day <= r.day;
		}
		return l.month < r.month;
	}
	return l.year < r.year;
}

bool operator>(Date l, Date r) //returns true if l is a later date than r 
{
	if(l.year == r.year)
	{
		if(l.month == r.month)
		{
			return l.day > r.day;
		}
		return l.month > r.month;
	}
	return l.year > r.year;
}

bool operator>=(Date l, Date r) //returns true if l is a later date than or the same date as r
{ 
	if(l.year == r.year)
	{
		if(l.month == r.month)
		{
			return l.day >= r.day;
		}
		return l.month > r.month;
	}
	return l.year > r.year;
}

bool operator==(Date l, Date r) //returns true if l is the same date as r
{
	if(l.year == r.year)
	{
		if(l.month == r.month)
		{
			return l.day == r.day;
		}
		return false;
	}
	return false;
}

ostream& operator<<(ostream& out, Date& d) //corectly outputs a date
{
	out << d.month << '/' << d.day << '/' << d.year;
	return out;
}

istream& operator>>(istream& in, Date& d) //correctly inputs a date
{
	char filler;
	in >> d.month;
	in >> filler;
	in >> d.day;
	in >> filler;
	in >> d.year;
	return in;
}