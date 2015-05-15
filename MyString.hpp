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

Operatoren und Methoden geändert für Lab3 A2    |Tommel     |15.5.15
Operatoren und Methoden für 'Const' Argumente überladen.

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
	MyString(const char*);		// Konstruktor für const MyString

	// Kopierkonstruktor
	MyString(MyString const & str);

	// Prototypen Methoden und Funktionen
	void reserve(unsigned int);
	MyString & append(MyString & str);
	MyString & append(const MyString & str);
	MyString & append(const MyString & str)const;
	MyString & assign(MyString & str);
	MyString & assign(const MyString & str);
	MyString & assign(string & str);
	const char * c_str();
	const char * c_str()const;
	int size();
	int size()const;
	int capacity();
	int capacity() const;
	void clear();
	bool empty();
	bool empty()const;
	char & at(unsigned int i);
	MyString operator+ (MyString & str);
	MyString operator+ (const MyString & str)const;
	MyString operator= (MyString & str);
	MyString operator= (string str);
	MyString operator= (const MyString &);

	//char& operator= (char);

	bool operator== (MyString & str);
	bool operator== (const MyString &)const; // Hallo!
	friend ostream & operator<< (ostream & o, MyString & str);
	friend ostream & operator<< (ostream &, const MyString &);
	char & operator[] (unsigned int index); // Hallo!
	static string remove(const string&, const char);										// Entfernt als default Leerzeichen, kann aber jedes belibige einzelne Zeichen aus einer Kette entfernen.
	
private:
	unsigned int strSize;
	unsigned int strCapacity;
	char *strPtr;
};

