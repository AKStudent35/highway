#include <iostream>
#include <math.h>
#include "Table.h"

int main()
{
	int* C;
	float** S;

	float** So;

	// memory allocation
	table::Allocate(C,6);
	table::Allocate(S,6,15);
	table::Allocate(So, 6, 5);

	// set basic variables
	table::SetCosts(C);
	table::SetBasicCosts(S, C);
	

	//first iterations made to debug
	table::FistIteration(So, C);
	//std::cout << "after first iteration" << std::endl << std::endl;
	//table::PrintTable(So);

	table::Iterate(S, So, C, 1);

	table::Iterate(S, So, C, 2);

	table::Iterate(S, So, C, 3);

	table::Iterate(S, So, C, 4);

	table::LastIteration(S, So, C);

	std::cout << "after next iteration" << std::endl << std::endl;
	table::PrintTable(So);




	//TODO
	/*
	zalokowałem koszta
	zrobiłem pierwszą iterację
	liczą się poprawnie(mam nadzieję) tylko w innej kolejności - dorobic algorytm!!!

	Zrobic algorytm z U - system binarny
	dodać możliwość dynamicznego wyboru ilości punktów

	2x tablica 7x4
	jedna na sume kosztów druga na U
	
	*/

	return 0;
}
