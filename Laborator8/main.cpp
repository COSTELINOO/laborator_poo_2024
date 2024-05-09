#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
std::ifstream fin("input.txt");
bool separator(char sep)
{
	if (sep == ' ' || sep == ',' || sep == '.' || sep == '?' || sep == '!')
		return true;
	return false;
}

void litera_mare(std::string& aux)
{
	std::string::iterator it;
	for(it=aux.begin();it!=aux.end();it++)
		if ((*it) >= 'A' && (*it) <= 'Z')
			(*it) = (*it) - 'A' + 'a';
}

struct Compare {
	bool operator() (std::map<std::string, int>::iterator s1, std::map<std::string, int>::iterator s2)
	{
		if (s1->second < s2->second) return true;
		if (s1->second > s2->second) return false;
		if (s1->first < s2->first) return false;
		return true;
	}
};

int main()
{
	
	std::string s;
	std::map<std::string, int> m;

	std::getline(fin, s);

	int i = 0;
	int j = 0;
	std::string aux;
	while (s[i + j] != 0)
	{
		if (separator(s[j + i]))
		{
			aux = s.substr(i, j);
			while (separator(s[j + i]))
				j++;
			i += j;
			j = 0;
			litera_mare(aux);
			if (m.find(aux) == m.end())
				m[aux] = 1;
			else
				m[aux]++;
		}
		else
			j++;
	}
	std::priority_queue<std::map<std::string, int>::iterator, std::vector<std::map<std::string, int>::iterator>, Compare> p;
	std::map<std::string, int>::iterator it = m.begin();
	while (it != m.end())
	{
		p.push(it);
		it++;
	}
	while (!p.empty())
	{
		std::cout  << p.top()->first << " => " << p.top()->second << std::endl;
		p.pop();
	}

	fin.close();
	return 0;
}