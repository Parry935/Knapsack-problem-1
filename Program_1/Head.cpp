#include "pch.h"
#include "Head.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

int odczyt_z_pliku(int & M_max, vector<string>&przedmiot, vector<int>& masa, vector<int>& cena, int & ilosc, string nazwa_pliku)
{
	fstream file;
	file.open(nazwa_pliku.c_str(), ios::in);
	if (file.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku" << endl;
		exit(0);
	}


	file >> M_max;
	string  linia;
	int dana;

	while (!file.eof()) //wykonuj dopuki plik nie jest pusty
	{
		//dodanie danych do okreœlonych vektorów

		file >> linia;
		przedmiot.push_back(linia);

		file >> dana;
		masa.push_back(dana);
	
		file >> dana;
		cena.push_back(dana);
		
		
		ilosc++;
	}

	file.close();

	return 0;
}


int algorytm_zachlanny(int & M_max, vector<string>&przedmiot, vector<int>& masa, vector<int>& cena, int & ilosc)
{
	int waga = 0;
	vector<int> ile_przedmiotow(ilosc,0);
	int wartosc = 0;
	int i = 0;
	
	
	while (M_max > waga) //wykonuj dopóki maksymalna waga plecaka nie jest przekroczona
	{
		int help = 0;

		if (i>ilosc-1) //jeœli przedmioty skoñcz¹ siê przerwij pêtlê
			break;

		if (M_max >= (waga + masa[i])) //jeœli kolejny przedmiot mieœci siê w plecaku to dodaj go
		{
			waga += masa[i];
			wartosc += cena[i];
			ile_przedmiotow[i]++;
		}

		else
			i++;  //jeœli nie sprawdŸ kolejny przedmiot
	}


	//wypisanie wyników

	cout << endl;
	cout << "Max pojemnosc plecaka " << M_max << endl;
	cout << "Waga plecaka wynosi: " << waga << endl;
	cout << "Wartosc plecaka wynisi " << wartosc << endl;
	cout << endl;
	cout << "Poszczegolne przedmioty w plecaku: " << endl;
	
	for (int i = 0; i < ilosc; i++)
	{
		cout << przedmiot[i] << " :  " << ile_przedmiotow[i] << endl;
	}
	
	return 0;
}
