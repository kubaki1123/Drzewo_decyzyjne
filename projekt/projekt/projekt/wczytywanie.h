#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
/// <summary>
/// struktura reference
/// </summary>
struct Reference {
	std::string* tab;
	int size;
	double* tab_val;
	int people_count;
	int atributes;
};
/// <summary>
/// wczytywanie z pliku wejsciowego
/// </summary>
/// <param name="name">nazwa pliku wejsciowego</param>
/// <returns></returns>
Reference wczytaj(std::string name) {
	std::fstream plik;
	plik.open(name, std::ios::in);
	if (plik.is_open()) {
		std::cout << "plik wejsciowy otwarty" << std::endl;
	}
	else {
		std::cout << "nie rozpoznano nazwy pliku wejsciowego" << std::endl;
	}
	int liczba_danych = 0, atrybuty = 0;
	plik >> liczba_danych >> atrybuty;


	

	std::string* tab_str = new std::string[atrybuty];

	double* tab = new double[liczba_danych * atrybuty];

	for (int i = 0; i < atrybuty; i++) {
		plik >> tab_str[i];

	}
	std::cout << std::endl;
	for (int i = 0; i < liczba_danych * atrybuty; i++) {

		plik >> tab[i];

	}
	Reference reference;
	reference.size = atrybuty;
	reference.tab = tab_str;
	reference.tab_val = tab;
	reference.people_count = liczba_danych;
	reference.atributes = atrybuty;
	return reference;
}