#include "class.h"
#include <algorithm>

void Sort::SetMax(int num)
{
	n = num;
}

int Sort::GetMax()
{
	return n;
}

void Sort::print(int* A)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

void Sort::fillArray(int* A)
{
	for (int i = 0; i < n; i++)
	{
		A[i] = i + 1;
	}

}
void Sort::fillReverse(int* A)
{
	int j = n - 1;
	for (int i = 0; i < n; i++)
	{
		A[j] = i + 1;
		j--;
	}
}

void Sort::fillRandomperm(int* A)
{
	for (int i = 0; i < n; i++) 
	{
		int pos = 0 + (rand() % n);
		SwapB(i, pos, A);  
	}
	//std::random_shuffle(A, A + n);
}


void Sort::SwapB(int i, int j, int* A)
{
	int tmp = 0;
	if (i >= 0 && i < n)
	{
		tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}

}

void Sort::ResetArrayB(int* A, int* B)
{
	for (int i = 0; i < n; i++) 
	{
		B[i] = A[i];
	}

}

int Sort::NextInput(int num)
{
	switch (num)
	{
	case 0: return 100;
	case 1: return 300;
	case 2: return 500;
	case 3: return 1000;
	case 4: return 3000;
	case 5: return 5000;
	case 6: return 10000;
	case 7: return 50000;
	default: return 0;
	}
}