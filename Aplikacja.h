#ifndef APLIKACJA_H
#define APLIKACJA_H

#include "BazaSQLite.h"
#include <iostream>
#include <string>
using namespace std;

class Aplikacja {
private:
	char opcja;
		  
	void DodajRekord();
	void WyswietlTablice();
	void KasujRekord();
	void StworzBaze();
	void UsunTablice();

	void ObsluzMenu();

public:
	Aplikacja();
	~Aplikacja();
	void PokazMenu();

	BazaSQLite *SQL;
};

#endif