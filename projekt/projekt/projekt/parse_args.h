#pragma once
#include <iostream>
#include <cstring>
#include "wczytywanie.h"
#include "read_tree.h"
#include "odp.h"

/// <summary>
/// sprawdzanie flagi i
/// </summary>
/// <param name="argc">ilosc argumentów wejsciowych</param>
/// <param name="argv">tablica argumentów wejsciowych</param>
/// <param name="i">bufor flagi </param>
/// <returns></returns>
Reference compare_i(int argc, char* argv[], int i) {
	std::string flag_i(argv[i + 1]);
	Reference reference;
	reference = wczytaj(flag_i);
	
	return reference;
}

/// <summary>
/// sprawdzanie flagi o
/// </summary>
/// <param name="argc">ilosc argumentów wejœciowych</param>
/// <param name="argv">tablica argumentów wejœciowych</param>
/// <param name="i">bufor flagi </param>
/// <param name="odp">wektor z odpowiedzi¹</param>
/// <param name="reference">struktura z zawartoscia pliku wejœciowego</param>
void compare_o(int argc, char* argv[], int i,std::vector<std::string> odp,Reference reference) {
	std::string flag_o(argv[i + 1]);

	odp_write(odp,reference,flag_o);

}

/// <summary>
/// sprawdzanie flagi t
/// </summary>
/// <param name="argc">ilosc argumentów wejœciowych</param>
/// <param name="argv">tablica argumentów wejœciowych</param>
/// <param name="i">bufor flagi</param>
/// <param name="reference">struktura z zawartoscia pliku wejœciowego</param>
/// <returns></returns>
std::vector<std::string> compare_t(int argc, char* argv[], int i, Reference reference) {
	std::string flag_t(argv[i + 1]);
	std::vector<std::string>odp;
	return odp=read_tree(flag_t,reference);

}

/// <summary>
/// parsowanie flag 
/// </summary>
/// <param name="argc">ilosc argumentów wejœciowych</param>
/// <param name="argv">tablica argumentów wejœciowych</param>
void parse(int argc, char* argv[]) {
	int flag_buf_i = 0;
	int flag_buf_t = 0;
	int flag_buf_o = 0;
	for (int i = 1; i < argc; i=i+2) {
		if ((std::strcmp(argv[i], "-i") == 0)) {
			flag_buf_i = i;
			
			
		}
		else if (std::strcmp(argv[i], "-t") == 0) {
			flag_buf_t = i;
			
			
		}
		else if ((std::strcmp(argv[i], "-o") == 0)) {
			flag_buf_o = i;
			
			
		}
		else {
			std::cout << "nie rozpoznano flag" << std::endl;
		}
			
		
	}
	Reference reference = compare_i(argc, argv, flag_buf_i);
	std::vector<std::string>odp;
	odp=compare_t(argc, argv, flag_buf_t,reference);
	compare_o(argc, argv, flag_buf_o,odp,reference);

}