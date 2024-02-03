#pragma once
#include<iostream>
#include<fstream>

/// <summary>
/// funkcja zapisujaca o pliku wyjsciowego
/// </summary>
/// <param name="odp">wektor z odpowiedzia</param>
/// <param name="reference">struktura z zawartoscia pliku wejsciowego</param>
/// <param name="name"></param>
void odp_write(std::vector<std::string>odp,Reference reference,std::string name) {
	std::fstream plik;
	plik.open(name,std::ios::out);
	if (plik.is_open()) {
		std::cout << "plik wyjsciowy otwarty" << std::endl;
	}
	else {
		std::cout << "nie rozpoznano nazwy pliku wyjsciowego" << std::endl;
	}
	
	
	int j = 0;
	for (int i = 0; i < reference.people_count*reference.atributes; i=i+2) {

		plik << reference.tab_val[i] << '\t' << reference.tab_val[i + 1] << '\t' << odp[j] << std::endl;
		
		j++;
	}

	plik.close();



}