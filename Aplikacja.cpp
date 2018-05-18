#include "Aplikacja.h"

Aplikacja::Aplikacja() {
	SQL = new BazaSQLite;
	
}


Aplikacja::~Aplikacja() {

}

void Aplikacja::PokazMenu() {
	cout << "Podaj nazwe pliku bazy" << endl;
	
	string nazwa_pliku;
	cin >> nazwa_pliku;
	nazwa_pliku = nazwa_pliku + ".db";

	this->SQL->nazwa_pliku = nazwa_pliku; 
	
	
	while(true) {
		cin >> opcja;
		ObsluzMenu();
	}
}

void Aplikacja::ObsluzMenu() {
	
	
		switch (opcja) {
		//dodawanie rekordow
		case 'd':
			DodajRekord();
			break;
		//wyswietlanie rekordow
		case 'w':
			WyswietlTablice();
			break;
		//kasowanie rekordow
		case 'k':
			KasujRekord();
			break;
		//tworzenie tablicy
		case 't':
			StworzBaze();
			break;
		//usun tablice
		case 'u':
			UsunTablice();
			break;
		//zakoncz
		case 'z':
			//sprawdzenie czy w ogole utworzono obiekt
			if(this->SQL->nazwa_tablicy.length() != NULL)
				delete SQL;
			else 
				exit(0);
		}
	
}

void Aplikacja::DodajRekord() {
	if(this->SQL->nazwa_tablicy.length() != NULL) {
		Rekord rekord;

		cout << "Podaj imie" << endl;
		cin >> rekord.imie;

		cout << "Podaj nazwisko" << endl;
		cin >> rekord.nazwisko;

		cout << "Podaj wiek" << endl;
		cin >> rekord.wiek;
	
		this->SQL->OtworzBaze();
		this->SQL->DodajDoTablicy(rekord);;

	}
	else
		cout << "Utworz tablice!" << endl;
}

void Aplikacja::WyswietlTablice() {
	if(this->SQL->nazwa_tablicy.length() != NULL) {
		this->SQL->OtworzBaze();
		this->SQL->WyswietlTablice();
	}
	else
		cout << "Utworz tablice!" << endl;
}

void Aplikacja::KasujRekord() {
	if(this->SQL->nazwa_tablicy.length() != NULL) {
		int id = 0;
		cout << "Podaj id rekordu do skasowania" << endl;
		cin >> id;

		this->SQL->OtworzBaze();
		this->SQL->KasujZTablicy(id);
	}
	else
		cout << "Utworz tablice!" << endl;
}

void Aplikacja::UsunTablice() {
	if(this->SQL->nazwa_tablicy.length() != NULL) {
		this->SQL->OtworzBaze();
		this->SQL->SkasujTablice();
		this->SQL->utworzona = false;
		

	}
	else
		cout << "Utworz tablice!" << endl;

}


void Aplikacja::StworzBaze() {
	if(!this->SQL->utworzona) {
		cout << "Podaj nazwe tablicy" << endl;
	
		string nazwa_tablicy;
		cin >> nazwa_tablicy;

		this->SQL->nazwa_tablicy = nazwa_tablicy;
		this->SQL->utworzona = true;

		this->SQL->OtworzBaze();
		this->SQL->TworzTablice();
	}
	else 
		cout << "Utworzyles juz jedna tablice!" << endl;
}

