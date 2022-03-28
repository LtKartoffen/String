#include "String.h"
#include <cstring>
#include <cctype>
//define _CRT_SECURE_NO_WARNINGS
using std::cout;
using std::cin;

// Initialize static-member of class
int String::num_strings = 0;

// Static method
int String::HowMany()
{
	return num_strings;
}

// String's methods

// Creating a String from C-string
String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	//cout << num_strings << ": \"" << str
	//	<< "\" object created\n";
}

String::String()
{
	len = 1;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
	//cout << num_strings << ": \"" << str
	//	<< "\" default object created\n";
}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	//cout << "\"" << str << "\" object deleted, ";
	num_strings--;
	//cout << num_strings << " left\n";
	delete[] str;
}

// Assign operators
// Assing String to String
String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

// Assign String to char* 
String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

// read and input access for some symbols in non-constant String
char& String::operator[](int i)
{
	return str[i];
}

// read acces for some symbols in constant String
const char& String::operator[](int i) const
{
	return str[i];
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
		str[i]= toupper(str[i]);
}

int String::repeat_symb(char symbol) const
{
	int count = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == symbol)
			count++;
	return count;
}

// Friend funcs for refreshed operations
bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String& st1, const String& st2)
{
	return st2.str < st1.str;
}
bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}
// Simple output String
std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}
String operator+(const String& st1, const String& st2)
{
	//int len = st1.len + st2.len;
	String temp;
	temp.len = st1.len + st2.len;
	temp.str = new char[temp.len + 1];
	std::strcpy(temp.str, st1.str);
	std::strcat(temp.str, st2.str);
	return temp;
}
// Simple input String
std::istream& operator>>(std::istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is and is.get() != '\n')
		continue;
	return is;
}