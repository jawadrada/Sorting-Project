#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class Sort {
public:
	void SetMax(int num);
	int GetMax();
	int NextInput(int num);
	void print(int* A);
	void fillArray(int* A);
	void fillReverse(int* A);
	void fillRandomperm(int* A);
	void ResetArrayB(int* A, int* B);
	void SwapB(int i, int j, int* A);

private:
	int n;
};