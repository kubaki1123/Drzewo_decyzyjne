#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "help.h"
#include "wczytywanie.h"
#include "parse_args.h"

/// <summary>
/// sprawdzanie parametrów wejsciowych
/// </summary>
/// <param name="argc">ilosc parametrów wejsciowych</param>
/// <param name="argv">tablica parametrów wejsciowych</param>
/// <returns></returns>
int main(int argc,char* argv[])
{
	if (argc == 1) {
		help();
		return 0;
	}
	else if (argc != 7) {
		std::cout << "podana zla ilosc argumentow" << std::endl;
		return -1;
	}

	parse(argc, argv);

	



}

