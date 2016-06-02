#include "Skoczek.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int agerandomValue()
{
	return 20+rand()%15;
}

int predispositionrandomValue()
{
	return 100+rand()%100;
}

int ktoryskoczek=0;

Skoczek::Skoczek()
{
	string names[20]={"Robert Swistak","Adam Malysz","Super Man","Iron Man","Bat Man","Robert Mateja","Don Vito Corleone","Forest Gump","Capitan Ameryka","Spider Man","Simon Amann","Andreas Felder","Sven Hannawald","Robert Kranjec","Peter Prevc","Walter Steiner","Stefan Kraft","Kamil Stoch","Piotr Zyla","Noriaki Kasai"};
	
	_name=names[ktoryskoczek];
	_age=agerandomValue();
	_confidence=50;
	_predisposition=predispositionrandomValue();
	_if_sick=0;
	for(int i=0;i<21;i++)
		_tab[i]=0;
	ktoryskoczek++;
}

int Skoczek::ifsick()
{
	srand(time(NULL));
	_if_sick= 0+rand()%10;	
}

string Skoczek::description1()
{
	return _name+" "+to_string(_age)+" "+to_string(_predisposition);
}

int Skoczek::numeracja(int i,int k)
{
	_tab[i+1]=k;
	
}

void Skoczek::riseconfidence(int pom)
{
	if(_tab[pom+1]<5)
		_confidence+=5;
	else if(_tab[pom+1]>=15)
		_confidence-=5;
}

void Skoczek::jump(int i,int pogoda,int dl_skoczni)
{
	
	
	_if_sick=0+rand()%10;
	int premia_zachorobe=0;
	if(_if_sick==1)
		premia_zachorobe=-30;
	int predyspozycja;
	if(_predisposition>dl_skoczni)
		predyspozycja=dl_skoczni/_predisposition;
	else if(_predisposition<dl_skoczni)
		predyspozycja=_predisposition/dl_skoczni;
	else 
		predyspozycja=1;
	_tab[2*i]=pogoda*dl_skoczni/100+premia_zachorobe+predyspozycja*40+dl_skoczni/_age+_confidence/3;

}

string Skoczek::wynik()
{
	int wynik=0;
	for(int i=0;i<20;i=i+2)
		wynik+=_tab[i];
	return to_string(wynik);

}
