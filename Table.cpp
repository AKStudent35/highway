#include <iostream>
#include <math.h>
#include "Table.h"
/*
float singleCost(int k,int C) {
	return sqrtf(1 + k * k) * C;
}
*/

float singleCost(int* C,int k,int i) {	return sqrtf(1 +k*k)*C[i];}

// setting default costs
void table::SetCosts(int * &C) {
	C[0] = 4;
	C[1] = 2;
	C[2] = 1;
	C[3] = 6;
	C[4] = 5;
	C[5] = 1;
}

// generating first row of results
void table::FistIteration(float**& So, int* C)
{	
	int counter = 0;
	for (int i = 4; i >=0; i--) {
		So[0][counter] = singleCost(C,i,0);
		counter++;
	}
}

// printg table to the console
void table::PrintTable(float** S) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << S[i][j] << std::endl;
		}
		std::cout << std::endl << std::endl;
	}
}

// generating basic costs of reaching particular places in table
void table::SetBasicCosts(float**& S, int* C) {
	int counter=0;

	//first row
	for (int i = 4; i>=0 ; i--) {
		for (int j = i; j >=0; j--) {
			S[0][counter] = singleCost(C, j, 0);
			counter++;
		}
	}

	for (int i = 1; i < 6; i++) {
		counter = 0;
		for (int j = 4; j >= 0; j--) {
			for (int k = 0; k <= j; k++) {
				S[i][counter] = singleCost(C,k,i);
				counter++;
			}
		}
	}

	//std::cout << "debug1" << std::endl;
	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 15; j++) {
	//		std::cout << S[i][j] << std::endl;
	//	}
	//	std::cout << std::endl;
	//}
}

// summing costs at some point (obtaining 4 paths)
void table::Iterate(float **S,float**&So,int* C,int k) {
	int counter=0;
	float* Sbuff;
	float buff;
	Allocate(Sbuff,15);


	for (int i = 0; i < 5; i++) {
		for (int j = i; j <= 4; j++) {

			Sbuff[counter] = S[k][counter] + So[k - 1][j];
			//std::cout << S[k][counter] << std::endl << So[k - 1][j] << std::endl;
			//std::cout << Sbuff[counter];
			
			counter++;
		}

		buff = Sbuff[counter - 1];
		for (int j = counter - 1; j >= counter -4 + i - 1; j--) {
			if (buff > Sbuff[j]) {
				buff = Sbuff[j];
			}
		}

		So[k][i] = buff;
		//std::cout << buff << std:: endl;
	}

	//std::cout << "debug2" << std::endl;
	//for (int i = 0; i < counter; i++)
	//{
	//	std::cout << Sbuff[i] << std::endl;
	//}
}

void table::LastIteration(float** S, float**& So, int* C) {
		for (int j = 0; j <=4; j++) {
			std::cout << S[5][j] << std::endl << So[4][j] << std::endl;
			So[5][j] = S[5][j] + So[4][j];
			//std::cout << S[k][counter] << std::endl << So[k - 1][j] << std::endl;
			//std::cout << Sbuff[counter];
		}
		//std::cout << buff << std:: endl;
}

// allocating space for new 1d array
void table::Allocate(int*&S, int N) {
	S = new int [N];
}

// allocating space for new 1d array 
void table::Allocate(float*& S, int N) {
	S = new float[N];
}

// allocating space for new 2d array
void table::Allocate(float**&S,int N,int M) {
	S = new float* [N];
	for (int i = 0; i < N; i++) {
		S[i] = new float[M];
	}
}
