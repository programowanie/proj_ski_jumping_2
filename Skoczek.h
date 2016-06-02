#pragma once

#include <string>
#include <vector>

using namespace std;


class Skoczek
{
	string _name;
	int _age;
	int _confidence;
	int _predisposition;
	int _if_sick;
	int _tab[21];
public:
	Skoczek();

	string name() { return _name; }
	int age() { return _age; }
	int confidence() { return _confidence; }
	int predisposition() {return _predisposition; }
	int ifsick();
	void jump(int i,int pogoda,int dl_skoczni);
	int tab(int i){return _tab[i];}
	int numeracja(int i,int k);
	string description1();
	void riseconfidence(int pom);
	string wynik();
};

