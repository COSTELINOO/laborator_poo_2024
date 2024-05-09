#include "Map.h"
#include <fstream>
#include <string>

#include <queue>
#include <iostream>
int main()
{

	Map<int, const char*> m, n;
	n[15] = "";
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";


	int index = 0;
	for (auto it = m.begin(); it != m.end(); ++it) {
		std::cout << "Index:" << index++ << ", Key=" << it->key << ", Value=" << it->value << std::endl;
	}
	m[20] = "result";
	for (auto it = m.begin(); it != m.end(); ++it) {
		std::cout << "Index:" << index++ << ", Key=" << it->key << ", Value=" << it->value << std::endl;
	}
	return 0;
}
