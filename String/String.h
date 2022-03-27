#ifndef STRING_H_
#define STRING_H_
class String
{
private:
	char* str;
	int len;
	static int num_strings;
public:
	String(const char* s);
	String();
	~String();
	
	//friend-func
	
};

#endif // !STRING_H_
