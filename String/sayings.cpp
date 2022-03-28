// sayings.cpp -- use advanced String-class
// and using pointers to objects
#include <iostream>
#include <cstdlib>			// rand() and srand()
#include <ctime>			// time()
#include "String.h"
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	String name;
	cout << "Hi, what's your name?\n";
	cin >> name;
	cout << name << ", please enter up to " << ArSize
		<< " short sayings <empty line to quit>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin and cin.get() != '\n')
			continue;
		if (!cin or temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		
		// Pointers for tracking shortest and first string
		String* shortest = &sayings[0];
		String* first = &sayings[0];
		for (i = 1; i < total; i++)
		{
			if (sayings[i].lenght() < shortest->lenght())
				shortest = &sayings[i];
			if (sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "Shortest sayings:\n" << *shortest << endl;
		cout << "First alphabetically:\n" << *first << endl;
		//cout << "This program used " << String::HowMany()
		//	<< " String objects. Bye.\n";
		srand(time(0));
		int choice = rand() % total;			//choose random index
		String* favorite = new String(sayings[choice]);
		cout << "My favorite saying:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "No input. Bye.\n";
	return 0;
}