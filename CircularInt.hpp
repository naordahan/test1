#ifndef CIRCULAR_INT_CIRCULARINT_H
#define CIRCULAR_INT_CIRCULARINT_H
#include <iostream>

using namespace std;


class CircularInt {
	int start;
	int finish; 
	int current;
	
	CircularInt check_range (int start, int finish);

public:
	CircularInt(CircularInt &c) {//copy constructor
		start = c.start;
		finish = c.finish;
		current = c.current;
	}
	int get_time() {return current;}
	int set_time() {this->current = time;}
	int get_start() {return start;}
	int get_finish() { return finish; }

	
	CircularInt(int start, int finish);
	CircularInt operator+ (const int n);
	CircularInt operator+ (const CircularInt& c);
	CircularInt& operator += (const int num);
	CircularInt& operator -= (const int num);
	CircularInt operator++ (int);
	CircularInt& operator++();
	CircularInt CircularInt::operator-- (int);
	CircularInt& CircularInt::operator-- ();
	CircularInt operator*=(const int num);
	ostream & CircularInt::operator<<(ostream & os, const CircularInt & c);
	CircularInt operator-=(CircularInt c, int num);
	istream & CircularInt::operator>>(istream & is, CircularInt & c);
	CircularInt CircularInt::operator-(int num, CircularInt & c);
	CircularInt CircularInt::operator-(CircularInt & c, int num);
#endif 
