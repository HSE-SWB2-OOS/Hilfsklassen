/* Uebungen zu OOP HA 3, Aufgabe 3
Erstersteller: Matthias Geckeler
E-Mail: matthias.geckeler@stud.hs-esslinge.de

Datum: 23.04.2015
Version: 2.2
Zeitaufwand: 2h

Aenderungshistorie:
-------------------
Durchgefuehrte Aenderung						|Autor		|Datum
Operatoren "+", "=", "[]" und "==" hinzugefügt  |Geckeler	|22.04.2015
Überprufung ob angegbener Index OK ist bei Operator [] |Geckeler |23.04.2015 
Operator "=" hinzugefügt um einen String dem MyString zuweisen zu Können und Kommentare hinzugefügt | Geckeler | 29.04.2015
-------------------------------------------------------
Programmbeschreibung:
Klasse My String mit erweiterung von Operatoren
---------------------
*/

#pragma once
#include "MyString.hpp"
#include <sstream>
#include <string>
#include <ostream>

// Standartkonstruktor
MyString::MyString()
{
	this->strSize = 0;
	this->strCapacity = 0;
	strPtr = new char[1];
	strPtr[0] = '\0';
}

// Konvertierkonstruktor c-String -> MyString
MyString::MyString(char* str)
{
	strSize = (unsigned int)strlen(str);
	strPtr = new char[strSize + 1];
	//memcpy(strPtr, str, strSize);
	strcpy_s(strPtr, strSize + 1, str);
	strCapacity = strSize;
}

// Konvertierkonstruktor String -> MyString
MyString::MyString(string str)
{
	strSize = (unsigned int)str.length();
	strPtr = new char[strSize + 1];
	strcpy_s(strPtr, strSize + 1, str.c_str ());
	strCapacity = strSize;
}

// Kopierkonstruktor
MyString::MyString(MyString const & str)
{
	strSize = str.strSize;
	strPtr = new char[strSize + 1];
	//memcpy(strPtr, str.strPtr, strSize);
	strcpy_s(this->strPtr, str.strSize + 1, str.strPtr);
	strCapacity = strSize;
}

// Destruktor
MyString::~MyString()
{
	delete[] strPtr;
}

// Methode um den Speicherplatz zu reservieren.
void MyString::reserve(unsigned int c)
{
	if (strCapacity < c)
	{
		char *temp = new char[strSize+1];
		strcpy_s(temp, strSize+1, strPtr);

		strCapacity = c;
		delete[] strPtr;
		strPtr = new char[strCapacity+1];
		strcpy_s(strPtr, strSize + 1, temp);
	}
}

// Methode um einen MyString an das MyString Opjekt anhängen zu können.
MyString & MyString::append(MyString & str)
{
	// String größe überprüfen
	reserve(this->strSize + str.strSize);
	this->strSize = this->strSize + str.strSize;

	strcat_s(this->strPtr, this->strSize+1, str.strPtr);
	return *this;
}

// Methode um einen andern MyString dem Opjekt MySting zuweisen zukönnen.
MyString & MyString::assign(MyString & str)
{
	// String größe überprüfen
	//if ((this->strSize + str.strSize) < this->strCapacity)
	reserve(str.strSize);
	this->strSize = str.strSize;
	strcpy_s(this->strPtr, str.strSize+1, str.strPtr);
	return *this;
}

// Methode um einem String dem Opjekt MySting zuweisen zukönnen.
MyString & MyString::assign(string & str)
{
	reserve(str.length());
	this->strSize = str.length();
	strcpy_s(this->strPtr, str.length() + 1, str.c_str());

	return *this;
}

// MyString um den c-String aus dem MyString Objekt abzufragen´.
const char* MyString::c_str()
{
	return this->strPtr;
}

// Methode um die größe des Strings abzufragen.
int MyString::size()
{
	return strSize;
}

// Methode um die Kapazität abzufragen.
int MyString::capacity()
{
	return strCapacity;
}

// Methode um den Sting zu löschen der sich in MyString befindet.
void MyString::clear()
{
	//strcpy_s(this->strPtr, 1, '\0');
	this->strPtr[0] = '\0';
	this->strSize = 0;

}

// Abfrage ob das MyString Objekt leer ist. 
bool MyString::empty()
{
	if (strSize == 0)
		return true;
	else
		return false;
}

// Methode um das Zeichen an der abgegebene Position abzufragen.
char & MyString::at(unsigned int i)
{
	if (i > strSize)
		return strPtr[0];
	else
		return strPtr[i-1];
}

// Operator "+" um Strings miteinander zu verbinden zu können.
MyString MyString::operator+ (MyString & str)
{
	MyString temp(*this);
	temp.append(str);
	return temp;
}

// Operator "=" um einen MyString zuweisen zu können. 
MyString MyString::operator= (MyString & str)
{
	return assign(str);
}

// Operator "=" um einen String zuweisen zu können.
MyString MyString::operator= (string str)
{
	this->assign(str);
	return *this;
}

// Operator "==" um 2 Strings auf Gleichheit überprüfen zu können.
bool MyString::operator== (MyString & str)
{
	bool result = false;

	if (strcmp(this->strPtr, str.strPtr)== 0)
		result = true;

	return result;
}

// Operator "<<" für eine cout des Strings
ostream & operator<< (ostream & o, MyString & str)
{
	return o<<str.c_str();
}

char & MyString::operator[] (unsigned int index)
{
	char result = '\0';

	if (index <= this->strSize)
		result = this->strPtr[index];

	return result;
}

// Die Methode entfernt alle Leehrzeichen aus einem String und gibt den bearbeiteten String zurück.
// Es kann aber auch eine anderes Zeichen entvert werden. 
string MyString::remove(const string &str,const char c =' '){
	
	istringstream inputstring(str);
	string returnStr;
	char checkChar;
	do
	{
		inputstring >> checkChar;
		if (checkChar != c)
			returnStr += checkChar;
	} while (inputstring);

	return returnStr;
}