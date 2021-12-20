#include <iostream>
#include <math.h>
#include "Table.h"

int main()
{
	int* C;
	float** S;

	float** So;
	int** U;

	// memory allocation
	table::Allocate(C,6);
	table::Allocate(S,6,15);
	table::Allocate(So, 6, 5);
	table::Allocate(U, 6, 5);


	// set basic variables
	table::SetCosts(C);
	table::SetBasicCosts(S, C);
	

	//first iterations made to debug
	table::FistIteration(So,U, C);

	table::Iterate(S, So, U, 1);

	table::Iterate(S, So, U, 2);

	table::Iterate(S, So, U, 3);

	table::Iterate(S, So, U, 4);

	table::LastIteration(S, So,U, C);



	//std::cout << "U table" << std::endl;

	//table::PrintTable(U);

	//std::cout << "after next iteration" << std::endl << std::endl;
	//table::PrintTable(So);


	table::PrintResult(So,U);



	//TODO
	/*
	zalokowałem koszta
	zrobiłem pierwszą iterację
	liczą się poprawnie(mam nadzieję) tylko w innej kolejności - dorobic algorytm!!!
	zrobiłem poprawnie liczące się koszty
	Praktycznie KONIEC - wysłać kamelowi przez gita - niech dołączy - dynamic punkty dorobić jeśli będzie chwila wolnego

	dodać możliwość dynamicznego wyboru ilości punktów

	2x tablica 7x4
	jedna na sume kosztów druga na U
	
	*/

	return 0;
}
