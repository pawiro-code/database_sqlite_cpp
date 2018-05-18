#ifndef BAZASQLITE_H
#define BAZASQLITE_H
#include <string>
#include "sqlite3.h"
#include "Rekord.h"
#include <iostream>
#include <string>
#include <sstream>
#include  <stdio.h>

using namespace std;

class BazaSQLite {
private:
	//funkcja dla obslugi zapytan sql, uzywana przy wyswietlaniu tablicy
	static int callback(void *NotUsed, int argc, char **argv, char **azColName);
	
public:
	//nazwa pliku bazy danych
	string nazwa_pliku;
	//nazwa tablicy
	string nazwa_tablicy;
	//flaga czy utworzona jest tablica
	bool utworzona;
	sqlite3 *baza;
		
	//id rekordow, inkrementowane przy dodawaniu rekordu do tablicy
	int ilosc_id;

	BazaSQLite();
	~BazaSQLite();
	//tworzy tablice w bazie danych, CREATE TABLE
	void TworzTablice();
	//otwiera baze danych
	void OtworzBaze();
	//dodaje podany rekord do tablicy, INSERT
	void DodajDoTablicy(Rekord rekord);
	//wyswietla tablice, SELECT
	void WyswietlTablice();
	// usuwa z tablicy rekord o podanym id, DELETE
	void KasujZTablicy(int id);
	//kasuje tablice z bazy danych, DROP TABLE
	void SkasujTablice();

	
};
#endif