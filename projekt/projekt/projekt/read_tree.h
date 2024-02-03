#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"wczytywanie.h"
#include"Tree_create.h"



/// <summary>
/// parsowanie warunków drzewa 
/// </summary>
/// <param name="cond">warunek</param>
/// <param name="reference">struktura z zawartoœci¹ pliku wejœciowego</param>
/// <returns></returns>
Condition parcer_condition(std::string cond,Reference reference) {

	Condition condition;
	std::string atrybuty;
	bool wykonane=false;
	std::string wartosc;
	
	for (int i = 0; i < cond.size(); i++) {
		if ((cond[i] == '>') || (cond[i] == '<')) {
			condition.sign = cond[i];
			wykonane = true;
		}
		else if (wykonane == true) {
			wartosc = wartosc + cond[i];
		}
		else {
			atrybuty = atrybuty + cond[i];
		}

		
	}
	
	for (int i = 0; i < reference.size; i++) {
		if (atrybuty == reference.tab[i]) {
			condition.statement = atrybuty;
		}
	}
	condition.value = std::stod(wartosc);


	return condition;
}


/// <summary>
/// wczytywanie i tworzenie drzewa 
/// </summary>
/// <param name="name">nazwa pliku drzewa</param>
/// <param name="reference">struktura z zawartoœci¹ pliku wejœciowego</param>
/// <returns></returns>
std::vector<std::string> read_tree(std::string name, Reference reference) {
	std::fstream plik;
	plik.open(name, std::ios::in);
	if (plik.is_open()) {
		std::cout << "plik drzewa otwarty" << std::endl;
		}
	else {
		std::cout << "nie rozpoznano nazwy pliku drzewa" << std::endl;
	}
	int wezly;
	plik >> wezly;

	std::vector<Tree> tree_struct;
	
	Tree tree;
	
	std::string cond,left_child,right_child;

	for (int i = 0; i < wezly; i++) {

		plik >> tree.node >> cond >> left_child >> right_child;

		Condition condition = parcer_condition(cond, reference);

		tree.left_child = left_child;
		tree.right_child = right_child;
		tree.condition.statement = condition.statement;
		tree.condition.sign = condition.sign;
		tree.condition.value = condition.value;
		tree_struct.push_back(tree);
		/*
		std::cout << tree.left_child << std::endl;
		std::cout << tree.right_child << std::endl;
		std::cout << tree.condition.statement << std::endl;
		std::cout << tree.condition.sign << std::endl;
		std::cout << tree.condition.value << std::endl;
		*/
	}

	std::vector<std::string>odp;
	

	for (int j = 0; j < reference.people_count; j++) {	


		odp.push_back(tree_creator(tree_struct, reference, j));
		
		
		
	}
	

	return odp;
}
