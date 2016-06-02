#include "Skoczek.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{	
	
	int dlugosc_skoczni[10];
	Skoczek tabskoczkow[20];
	for(int i=0;i<10;i++)
		dlugosc_skoczni[i]=100+rand()%100;
	int ilosc_sezonow=3;
	srand(time(NULL));

	for(int k=0;k<ilosc_sezonow;k++)
	{
	int pom=0;
	cout<<"TURNIEJ NR:"<<k+1<<endl;
		for(int i=0;i<10;i++)
		{
			
			int pogoda= 50+rand()%50; // 50 tragiczna 100 najlepsza
			for(int x=0;x<20;x++)
			{	
				
				int zmiana_pogody= (-3)+rand()%6;
				pogoda=pogoda+zmiana_pogody;
				if(pogoda<=50)
					pogoda=50;
				else if(pogoda>=100)
					pogoda=50;
				

				tabskoczkow[x].jump(i,pogoda,dlugosc_skoczni[i]);
				
			}
			
			
			for(int x=0;x<20;x++)
				{	int z=0;
					for(int a=0;a<20;a++)
					{
						if(tabskoczkow[x].tab(pom)<tabskoczkow[a].tab(pom))
							z++;
						
					}
					tabskoczkow[x].numeracja(pom,z);
				}

			for(int x=0;x<20;x++)
				tabskoczkow[x].riseconfidence(pom);
			pom+=2;	
		}		
	for(int i=0;i<20;i++)
		{
			cout.width(30);
			cout<<left<<"["+to_string(i+1)+"] "+tabskoczkow[i].description1()<<">>";
			for(int k=0;k<20;k++)
				{
				if(k%2==0)
					{
					cout.width(3);
					cout<<to_string(tabskoczkow[i].tab(k));
					cout<<" ";}
				else
					{
					cout<<"(";
					cout.width(2);				
					cout<<to_string(tabskoczkow[i].tab(k));
					cout<<") ";}
				}
			cout<<"Wynik: "<<tabskoczkow[i].wynik();
			cout<<endl;
		}	

	cout<<endl;
	}
	

for(int i=0;i<10;i++)
cout<<dlugosc_skoczni[i]<<" ";

}
