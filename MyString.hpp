/* Uebungen zu OOP HA 3, Aufgabe 3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 22.04.2015
Version: 2.0
Zeitaufwand: 1h

Aenderungshistorie:
-------------------
Durchgefuehrte Aenderung						|Autor		|Datum
Operatoren "+", "=", "[]" und "==" hinzugefügt  |Geckeler	|22.04.2015
-------------------------------------------------------
Programmbeschreibung:
Header der Klasse MyString mit der Erweiterung von Operatoren
---------------------
*/

#include <cstring>
#include <ostream>
#pragma once;
using namespace std;

class MyString
{
public:
	MyString();
	~MyString();

	// Konvertierkonstruktor Definition
	MyString(char*);
	MyString(string);

	// Kopierkonstruktor
	MyString(MyString const & str);

	// Prototypen Methoden und Funktionen
	void reserve(unsigned int);
	MyString & append(MyString & str);
	MyString & assign(MyString & str);
	MyString & assign(string & str);
	const char * c_str();
	int size();
	int capacity();
	void clear();
	bool empty();
	char & at(unsigned int i);
	MyString operator+ (MyString & str);
	MyString operator= (MyString & str);
	MyString operator= (string str);
	bool operator== (MyString & str);
	friend ostream & operator<< (ostream & o, MyString & str);
	char & operator[] (unsigned int index);
	static string remove(const string&, const char);										// Entfernt als default Leerzeichen, kann aber jedes belibige einzelne Zeichen aus einer Kette entfernen.
	
private:
	unsigned int strSize;
	unsigned int strCapacity;
	char *strPtr;
};

