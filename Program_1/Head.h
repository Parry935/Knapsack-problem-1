#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

// funkcja odczytuj�ca dane wejsciowe z pliku tekstowego
int odczyt_z_pliku(int &M_max, vector<string>&przedmiot, vector<int>&masa, vector<int>&cena, int &ilosc, string nazwa_pliku);

//funkcja realizuj�ca algorytm zach�anny dla problemu plecakowego
int algorytm_zachlanny(int &M_max, vector<string>&przedmiot, vector<int>&masa, vector<int>&cena, int &ilosc);

#endif
