#include <iostream>
#include <string>
#include "CircularInt.hpp"


CircularInt::CircularInt (int start, int finish) {
if (start < finish) {
	this->start = start;
	this->finish = finish;
}
else {
	this->start = finish;
	this->finish = start;
}
current = start;
	}
//operator + for adding a number to a object
CircularInt CircularInt::operator+ (const int n) {
	CircularInt result{ start, finish };
	result.current = current + n;
	while (result.current > finish) {
		result.current = result.current - finish;
	}
	return result;
}
//operator +  for two objects
CircularInt CircularInt::operator+ (const CircularInt& c)
{
	CircularInt result{ start, finish };
	result.current = current + c.current;
	while (result.current > finish) {
		result.current = result.current - finish;
	}
	return result;
}

CircularInt& CircularInt::operator += (const int num)
{
	current = current + num;
	while (current > finish) {
		current = current - finish;
	}
	return *this;
}
CircularInt& CircularInt::operator -= (const int num) {
	current = current - num;
	while (current<start) {
		current = current + finish;
	}
	return *this;
}

//operator ++ Prefix
CircularInt CircularInt::operator++ (int)
{
	CircularInt result(*this);
	operator++();
	return *this;
}

//operator++ Postfix
CircularInt& CircularInt::operator++() {
	current++;
	while (current > finish) {
		current = current - finish;
	}
	return *this;
}

//operator-- Prefix
CircularInt CircularInt::operator-- (int) {
	CircularInt result(*this);
	operator--();
	return *this;
}

//operator-- Postfix
CircularInt& CircularInt::operator-- () {
	current--;
	while (current < start) {
		current += finish;
	}
	return *this;
}


//operator *=
CircularInt CircularInt::operator *= (const int num) {
	current *= num;
	while (current > finish) {
		current = current - finish;
	}
	return *this;
}

//operator / finds which numbers can be a divider
string CircularInt::operator/ (const int num) {
	string s;
	for (int i = start; i <= finish; i++) {
		int temp = i * num;
		while (temp > finish) {
			temp = temp - finish;
		}
		if (temp == current) {
			string res = std::to_string(i);
			s += res + " ";
		}
	}
	if (s.length() == 0) {
		s = "There is no number x in {1,12} such that x*" + to_string(num) + "=10";
	}
	return s;
}
// operator <<
ostream& operator<<(ostream& os, const CircularInt& c)
{
	os << c.get_time;
	return os;
}
//operator -=
 CircularInt operator-= (CircularInt c, int num) {
	CircularInt result{ c.get_start,c.get_finish };
	result.set_time = c.get_time - num;
	while (result.get_time < c.get_start) {
		result.set_time += c.get_finish;
	}
	return result;
}
// operator >>
 istream& operator>>(istream& is, CircularInt& c)
{
	is >> c.set_time;
	return is;
}

//Substracting a structure from a number
 CircularInt operator- (int num, CircularInt& c) {
	CircularInt result{ c.get_start,c.get_finish };
	result.set_time = num - c.get_time;
	while (result.get_time < c.get_start) {
		result.set_time += c.get_finish;
	}
	return result;
}

//Substracting a number from a structure
 CircularInt operator- (CircularInt& c, int num) {
	CircularInt result{ c.get_start,c.get_finish };
	result.set_time = c.get_time - num;
	while (result.get_time < c.get_start) {
		result.get_time += c.get_finish;
	}
	return result;
}
//using code from https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx (for operator <<)

