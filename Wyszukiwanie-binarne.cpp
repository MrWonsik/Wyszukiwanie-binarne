 //============================================================================
 // Name        : Wyszukiwanie-liniowe.cpp
 // Author      : Tomasz Wasacz
 // Version     :
 // Copyright   : Your copyright notice
 // Description : Hello World in C++, Ansi-style
 //============================================================================

 #include <iostream>
 #include <cstdlib> //biblioteka potrzebna do wywo³ywania funkcji odpowiedzialnych za pseudolosowosc
 #include <ctime>
 using namespace std;

  bool wyszukiwanie_binarne(int search_num, int *table, int table_size)
 {
 	int poczatkowy_element=0, koncowy_element=table_size, srodek=0;

 	while(poczatkowy_element <= koncowy_element)
 	{
 		srodek=(poczatkowy_element+koncowy_element)/2;
 		if(table[srodek]==search_num)
 			return true;
 		else if( table[srodek] > search_num )
 			koncowy_element=srodek-1;
 		else
 			poczatkowy_element=srodek+1;
 	}
 	return false;
 }

  void wyswietl(int *table, int table_size) //funkcja pomocnicza do wyswietlania tablicy;
 {
 	for(int i=0;i<table_size;i++) cout << table[i] << endl;
 }

  int main() {

  	srand(time(NULL)); //niezbêdna do generowania przy ka¿dym wywo³aniu aplikacji ró¿nych liczb losowych
 	int table_size = 40; //Podajemy liczbê tablicy do wygenerowania
 	int *table = new int[table_size];
 	int search_num=0;

 	table[0]=rand() % table_size;
  	for (int i=1; i<table_size; i++)
 		table[i]=table[i-1]+(rand() % table_size); //dziêki temu otrzymamy liczby posegregowane rosn¹co (niezbêdne jest to do wyszukiwania binarnego)

  	wyswietl(table, table_size);

  	cout << "Searching number:";cin >> search_num;cout << endl;

  	if(wyszukiwanie_binarne(search_num, table, table_size))
 		cout << "Znaleziono!" << endl;
 	else
 		cout << "Nieznaleziono!" << endl;


  	return 0;
 }
