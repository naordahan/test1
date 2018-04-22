#include <iostream>

using namespace std;


class CircularInt {
	int start;
	int finish;
	int current;

public:


	//constructors
	CircularInt(int s, int f) {
		if (s < f) {
			start = s;
			finish = f;
		}
		else {
			start = f;
			finish = s;
		}
		current = start;
	}


	CircularInt(CircularInt &c) {//copy constructor
		start = c.start;
		finish = c.finish;
		current = c.current;
	}



	/*friend ostream& operator<<(ostream& os, const CircularInt& c);
	friend istream& operator>>(istream& is, CircularInt& c);
	friend CircularInt operator- (int num, CircularInt& c);
	friend CircularInt operator- (CircularInt& c, int num);*/
	friend CircularInt operator-= (CircularInt& c, int num);



	//operator +  for two objects
	CircularInt operator+ (const CircularInt& c)
	{
		CircularInt result{ start, finish };
		result.current = current + c.current;
		while (result.current > finish) {
			result.current = result.current - finish;
		}
		return result;
	}

	//operator + for adding a number to a object
	CircularInt operator+ (const int n) {
		CircularInt result{ start, finish };
		result.current = current + n;
		while (result.current > finish) {
			result.current = result.current - finish;
		}
		return result;
	}

	//operator +=
	CircularInt& operator += (const int num) {
		current = current + num;
		while (current > finish) {
			current = current - finish;
		}
		return *this;
	}

	//operator -=
	CircularInt& operator -= (const int num) {
		current = current - num;
		while (current<start) {
			current = current + finish;
		}
		return *this;
	}


	//operator ++ Prefix
	CircularInt operator++ (int)
	{
		CircularInt result(*this);
		operator++();
		return *this;
	}

	//operator++ Postfix
	CircularInt& operator++() {
		current++;
		while (current > finish) {
			current = current - finish;
		}
		return *this;
	}

	//operator-- Prefix
	CircularInt operator-- (int) {
		CircularInt result(*this);
		operator--();
		return *this;
	}

	//operator-- Postfix
	CircularInt& operator-- () {
		current--;
		while (current < start) {
			current += finish;
		}
		return *this;
	}

	//operator - for substracting the number from the maximum possible number
	CircularInt operator- () {
		CircularInt result{ start,finish };
		result.current = result.finish - current;
		while (result.current < result.start) {
			result.current += result.finish;
		}
		return result;
	}



	//operator *=
	CircularInt operator *= (const int num) {
		current *= num;
		while (current > finish) {
			current = current - finish;
		}
		return *this;
	}

	//operator / finds which numbers can be a divider
	string operator/ (const int num) {
		string s;
		for (int i = start; i <= finish; i++) {
			int temp = i * num;
			while (temp > finish) {
				temp = temp - finish;
			}
			if (temp == current) {
				string res = to_string(i);
				s += res + " ";
			}
		}
		if (s.length() == 0) {
			s = "There is no number x in {1,12} such that x*" + to_string(num) + "=10";
		}
		return s;
	}
	//operator -=
	friend ostream& operator<<(ostream& os, const CircularInt& c)
	{
		os << c.current;
		return os;
	}
	// operator <<
	friend CircularInt operator-= (CircularInt c, int num) {
		CircularInt result{ c.start,c.finish };
		result.current = c.current - num;
		while (result.current < c.start) {
			result.current += c.finish;
		}
		return result;
	}
	// operator >>
	friend istream& operator>>(istream& is, CircularInt& c)
	{
		is >> c.current;
		return is;
	}

	//Substracting a structure from a number
	friend CircularInt operator- (int num, CircularInt& c) {
		CircularInt result{ c.start,c.finish };
		result.current = num - c.current;
		while (result.current < c.start) {
			result.current += c.finish;
		}
		return result;
	}

	//Substracting a number from a structure
	friend CircularInt operator- (CircularInt& c, int num) {
		CircularInt result{ c.start,c.finish };
		result.current = c.current - num;
		while (result.current < c.start) {
			result.current += c.finish;
		}
		return result;
	}
	//using code from https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx (for operator <<)
};
