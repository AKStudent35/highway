#include <iostream>;

namespace table{

	void SetBasicCosts(float**& S, int* C);

	void SetCosts(int* &C);
	
	void FistIteration(float**& So, int* C);

	void Iterate(float** S,float **&So, int* C, int i);

	void LastIteration(float** S, float**& So, int* C);

	void PrintTable(int* C);
	
	void PrintTable(float** S);

	void Allocate(int*& S, int N);

	void Allocate(float*& S, int N);

	void Allocate(float**& S, int N, int M);
}