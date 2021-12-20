#include <iostream>;

namespace table{

	void SetBasicCosts(float**& S, int* C);

	void SetCosts(int* &C);
	
	void FistIteration(float**& So,int **&U, int* C);

	void Iterate(float** S,float **&So, int**& U, int i);

	void LastIteration(float** S, float**& So,int**&U, int* C);

	void PrintResult(float** S, int** U);

	void PrintTable(int* C);
	
	void PrintTable(float** S);

	void PrintTable(int** S);

	void Allocate(int*& S, int N);

	void Allocate(float*& S, int N);

	void Allocate(float**& S, int N, int M);

	void Allocate(int**& S, int N, int M);
}