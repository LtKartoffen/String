#include <iostream>
#ifndef STRING_H_
#define STRING_H_
class String
{
private:
	char* str;
	int len;
	static int num_strings;						//num of objects
	static const int CINLIM = 80;				//limit for console input
public:
	String(const char* s);						//constructor by default
	String();									//constructor
	~String();									//destructor
	String(const String&);						//constructor of copy
	int lenght() const { return len; }		

	//Methods of refreshed operations
	String& operator=(const String&);
	String& operator=(const char*);
	char& operator[](int i);
	const char& operator[](int i) const;

	//friend-func
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend std::istream& operator>>(std::istream& is, String& st);
	friend std::ostream& operator<<(std::ostream& os, const String& st);

	//Static-func
	static int HowMany();
};

#endif // !STRING_H_
