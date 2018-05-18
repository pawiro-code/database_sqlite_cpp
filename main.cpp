#include "Aplikacja.h"


int main() {
	Aplikacja program;
	
	cout << "Instrukcja uzywania programu:" << endl;
	cout << "Podaj nazwe pliku bazy danych, a nastepnie wybierz jedna z ponizszych opcji" << endl << endl;
	
	cout << "t - tworz tablice" << endl;
	cout << "w - wyswietl baze danych" << endl;
	cout << "k - kasuj rekord" << endl;
	cout << "d - dodaj rekord" << endl;
	cout << "u - usun tablice" << endl;
	cout << "z - zakoncz" << endl << endl;
	
	
	program.PokazMenu();
	
	return 0;

}