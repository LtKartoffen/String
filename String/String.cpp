#include "String.h"
#include <cstring>
using std::cout;

// Initialize static-member of class
int String::num_strings = 0;

// String's methods

// Creating a String from C-string
String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ": \"" << str
		<< "\" object created\n";
}

String::String()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str
		<< "\" default object created\n";
}

String::~String()
{
	cout << "\"" << str << "\" object deleted, ";
	num_strings--;
	cout << num_strings << " left\n";
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}