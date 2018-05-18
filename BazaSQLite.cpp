#include "BazaSQLite.h"

//konstrukor
BazaSQLite::BazaSQLite() {
	
	//inicjatory
	ilosc_id = 0;
	utworzona = false;
}
//destruktor
BazaSQLite::~BazaSQLite() {
	//zamykamy baze
	sqlite3_close(baza);
	cout << "Baza zamknieta" << endl;
	//wychodzimy z programu
	exit(0);
}

//otworz baze o danej nazwie
void BazaSQLite::OtworzBaze() {
	int status_bazy = 0;
	
	//string to char
	char *pomoc = new char[nazwa_pliku.length() + 1];
	strcpy(pomoc, nazwa_pliku.c_str());
	
	//otwieramy baze danych o danej nazwie
	status_bazy = sqlite3_open(pomoc, &baza);
	delete [] pomoc;
	
	if(status_bazy) {
		cout << "Nie mozna utworzyc bazy danych" << sqlite3_errmsg(baza) << endl;
	} 
	else {
		cout << "Baza otworzona pomyslnie" <<endl;
	}
}

//callback sqlite
int BazaSQLite::callback(void *NotUsed, int argc, char **argv, char **azColName) {
   
	for(int i = 0; i<argc;i++) {
		cout << argv[i] << "	";
		//poprawka tabulatora dla kolumny wieku
		if(i == argc-2)
		cout << "	";
	}
	cout << endl;
	return 0;
}

void BazaSQLite::DodajDoTablicy(Rekord rekord) {

	char *blad = 0;
	int status_bazy = 0;


	ostringstream tmp;
	string rozkaz;
	
	//zapytanie SQLite
	tmp.str("");
	tmp << "INSERT INTO " << nazwa_tablicy <<"(id, imie, nazwisko, wiek) VALUES (" << ++ilosc_id<< ",'" << rekord.imie<<"', '"<< rekord.nazwisko<<"', "<<  rekord.wiek <<");";
	rozkaz = tmp.str();
	status_bazy = sqlite3_exec(baza, rozkaz.c_str(), callback, 0, &blad);

	//status bazy - czy operacja sie udala
	if(status_bazy != SQLITE_OK) {
		cout << "Blad SQL: "<< blad << endl;
		sqlite3_free(blad);
		sqlite3_close(baza);
	}
	else {
		cout << "Rekord dodany poprawnie" << endl;
	}
  
}

void BazaSQLite::WyswietlTablice() {
	int status_bazy = 0;
	char *blad = 0;
   
	//zapytanie SQLite
	ostringstream tmp;
	string rozkaz;
	tmp.str("");
	tmp << "SELECT * from "<< nazwa_tablicy <<";";
	rozkaz = tmp.str();

	//wypisanie grida
	cout << endl;
	cout << "id" << "	" << "imie	"<< "nazwisko	" << "wiek" << endl;
	status_bazy = sqlite3_exec(baza, rozkaz.c_str(), callback, 0, &blad);
	cout << endl;
	
	//status bazy - czy operacja sie udala
	if(status_bazy != SQLITE_OK) {
		cout << "Blad SQL: " << blad << endl;
		sqlite3_free(blad);
	} 
	else {
		cout << "Baza wyswietlona pomyslnie" << endl;
	}
	sqlite3_close(baza);
  
}


void BazaSQLite::TworzTablice() {
	
	int status_bazy = 0;
	char *blad = 0;
	    
	ostringstream tmp;
	string rozkaz;
	
	//zapytanie SQLite
	tmp.str("");
	tmp << "CREATE TABLE "<< nazwa_tablicy << "(id INT, imie TEXT, nazwisko TEXT, wiek INT);";
	rozkaz = tmp.str();

	status_bazy = sqlite3_exec(baza, rozkaz.c_str(), callback, 0, &blad);
	
	//status bazy - czy operacja sie udala
	if(status_bazy != SQLITE_OK) {
		cout << "Blad SQL: " << blad << endl;
		sqlite3_free(blad);
		sqlite3_close(baza);
	}
	else {
		cout << "Tablica " <<  nazwa_tablicy << " utworzona poprawnie"<< endl;
	}

}

void BazaSQLite::KasujZTablicy(int id) {
	char *blad = 0;
	int status_bazy = 0;

	ostringstream tmp;
	string rozkaz;

	//zapytanie SQLite
	tmp.str("");
	tmp << "DELETE FROM "<< nazwa_tablicy << " WHERE ID=" << id <<";";
	rozkaz = tmp.str();
	status_bazy = sqlite3_exec(baza, rozkaz.c_str(), callback, 0, &blad);

	//status bazy - czy operacja sie udala
	if(status_bazy != SQLITE_OK) {
		cout << "Blad SQL: " << blad << endl;
		sqlite3_free(blad);
		sqlite3_close(baza);
	}
	else {
		cout << "Rekord usuniety poprawnie" << endl;
	}
	 
 
}

void BazaSQLite::SkasujTablice() {
	int status_bazy = 0;	
	char *blad = 0;
	  
	ostringstream tmp;
	string rozkaz;

	//zapytanie SQLite
	tmp.str("");
	tmp << "DROP TABLE "<< nazwa_tablicy << ";";
	rozkaz = tmp.str();
	
	status_bazy = sqlite3_exec(baza, rozkaz.c_str(), callback, 0, &blad);
	
	//status bazy - czy operacja sie udala
	if(status_bazy != SQLITE_OK) {
		cout << "Blad SQL: " << blad << endl;
		sqlite3_free(blad);
		sqlite3_close(baza);
	} 
	else {
		cout << "Tablica " <<  nazwa_tablicy << " usunieta pomyslnie"<< endl;
		nazwa_tablicy = "";
	}
}