#pragma once
#include <iostream>
#include <string>
#include <vector>
/// <summary>
/// struktura warunku 
/// </summary>
struct Condition {
	std::string statement;
	char sign;
	double value;
};
/// <summary>
/// struktura drzewa
/// </summary>
struct Tree {
	int node;
	Condition condition;
	std::string left_child;
	std::string right_child;
};
/// <summary>
/// sprawdzanie czy dziecko nie jest liczba 
/// </summary>
/// <param name="tree_struct">struktura drzewa</param>
/// <param name="i">bufor trzymaj¹cy aktualnego noda drzewa</param>
/// <returns></returns>
bool check_left_child(std::vector<Tree>tree_struct,int i) {
	try {
		std::stoi(tree_struct[i].left_child);
		return true;
	}
	catch(std::exception error){
		return false;
	}

}
/// <summary>
/// sprawdzanie czy dziecko nie jest liczba 
/// </summary>
/// <param name="tree_struct">struktura drzewa</param>
/// <param name="i">bufor trzymaj¹cy aktualnego noda drzewa</param>
/// <returns></returns>
bool check_right_child(std::vector<Tree> tree_struct,int i) {
	try {
		std::stoi(tree_struct[i].right_child);
		return true;
	}
	catch (std::exception error) {
		return false;
	}

}
/// <summary>
/// przechodzenie po drzewie 
/// </summary>
/// <param name="tree_struct">struktura drzewa</param>
/// <param name="reference">struktura pliku wejsciowego</param>
/// <param name="j">osoba która jest aktualnie sprawdzana</param>
/// <returns></returns>
std::string  tree_creator(std::vector<Tree> tree_struct,Reference reference,int j){
	int node=0;

	while(true) {
		double warunek;

		for (int k = 0; k < reference.atributes; k++) {
			
				if (reference.tab[k]==tree_struct[node].condition.statement) {
					warunek = reference.tab_val[j * reference.atributes + k];
					
					break;
				}
			
		}


		 if (tree_struct[node].condition.sign == '>') {
			if (warunek > tree_struct[node].condition.value) {
				if (check_right_child(tree_struct, node) == true) {
					node = std::stoi(tree_struct[node].right_child);
				}
				else {
					return tree_struct[node].right_child;
				}
			}
			else {
				if (check_left_child(tree_struct, node) == true) {
					node = std::stoi(tree_struct[node].left_child);
				}
				else {
					return tree_struct[node].left_child;
				}
			}
		}
		else if (tree_struct[node].condition.sign == '<') {
			if (warunek < tree_struct[node].condition.value) {
				if (check_right_child(tree_struct, node) == true) {
					node = std::stoi(tree_struct[node].right_child);
				}
				else {
					return tree_struct[node].left_child;
				}
			}
			else {
				if (check_left_child(tree_struct, node)==true) {
					node = std::stoi(tree_struct[node].left_child);
				}
				else {
					return tree_struct[node].left_child;
				}
			}
		}
	}

	
}
