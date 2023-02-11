#include <iostream>
#include <chrono>
#include "class2.h"

using namespace std;
using namespace std::chrono;

int const MAX = 50000;
const int INSERTION_SORT_THRESHOLD = 32;

duration<double, std::micro> avg_time;
unsigned long long int avg_steps;
duration<double, std::micro> avg_time1;
unsigned long long int avg_steps1;
duration<double, std::micro> avg_time2;
unsigned long long int avg_steps2;
duration<double, std::micro> avg_time3;
unsigned long long int avg_steps3;
duration<double, std::micro> avg_time4;
unsigned long long int avg_steps4;
duration<double, std::micro> avg_time5;
unsigned long long int avg_steps5;

void insertionsort(int A[], int size);
void selectionSort(int selectionArray[], int n);
void BubbleSort(int arr[], int n);
void heapSort(int heapArray[], int n);
void heapify(int heapArray[], int n, int i);
void MergeSort(int *arr, int begin, int end);
void Merge(int *arr, int begin, int mid, int end);
void quickSort(int arr[], int begin, int end);
int partition(int arr[], int begin, int end);

void insertionsort(int A[], int size)
{
	avg_steps++;
	for (int i = 1; i <= size - 1; i++)
	{
		avg_steps += 4;
		int temp = A[i];

		for (int j = i - 1; j >= 0 && temp < A[j]; j--)
		{
			avg_steps += 5;
			A[j + 1] = A[j];
			A[j] = temp;
		}
	}
}

void selectionSort(int selectionArray[], int n)
{
	int min;
	avg_steps1 += 2;
	for (int k = 0; k < n - 1; k++)
	{
		avg_steps1 += 4;
		min = k;
		for (int j = k + 1; j < n; j++)
		{
			avg_steps1 += 4;
			if (selectionArray[j] < selectionArray[min])
			{
				avg_steps1++;
				min = j;
			}
		}
		avg_steps1++;
		swap(selectionArray[min], selectionArray[k]);
	}
}

void BubbleSort(int arr[], int n)
{
	avg_steps2++;
	for (int i = 1; i < n; i++) 
	{
		avg_steps2 += 3;
		for (int j = 0; j <= n - i - 1; j++) 
		{
			avg_steps2 += 3;
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				avg_steps2 += 3;
			}
		}
		avg_steps2++;
	}
	avg_steps2++;
}

void quickSort(int A[], int begin, int end)
{
	avg_steps3++;
	if (begin < end)
	{
		avg_steps3++;
		int p = partition(A, begin, end);

		avg_steps3++;
		quickSort(A, begin, p - 1);

		avg_steps3++;
		quickSort(A, p + 1, end);
	}
}

int partition(int A[], int begin, int end)
{
	avg_steps3 += 3;
	int pivot = A[end];
	int index = (begin - 1);

	for (int j = begin; j <= end - 1; j++)
	{
		avg_steps3 += 3;
		if (A[j] < pivot)
		{
			avg_steps3 += 4;
			index++;
			swap(A[index], A[j]);
		}
	}

	avg_steps3 += 4;
	swap(A[index + 1], A[end]);
	return (index + 1);
}

void MergeSort(int *arr, int begin, int end)
{
	avg_steps4++;
	if (begin < end)
	{
		avg_steps4 += 4;
		int mid = (begin + end) / 2;
		MergeSort(arr, begin, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, begin, mid, end);
	}
	return;
}

void Merge(int *arr, int begin, int mid, int end)
{
	int *arrB = new int[end - begin + 1];
	int i = begin;
	int j = mid + 1;
	int k = 0;
	k = 0;

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			arrB[k] = arr[i];
			i++;
		}

		else
		{
			arrB[k] = arr[j];
			j++;
		}

		k++;
	}

	while (i <= mid)
	{
		arrB[k] = arr[i];
		i++;
		k++;
	}

	while (j <= end)
	{
		arrB[k] = arr[j];
		j++;
		k++;
	}

	k = 0;
	for (int i = begin; i <= end; i++)
	{
		arr[i] = arrB[k];
		k++;
	}

	delete[] arrB;

	avg_steps4 += 3;
}

void heapSort(int heapArray[], int n)
{
	avg_steps5++;
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		avg_steps5 += 3;
		heapify(heapArray, n, i);
	}

	avg_steps5++;
	for (int i = n - 1; i > 0; i--)
	{
		avg_steps5 += 6;
		swap(heapArray[0], heapArray[i]);
		heapify(heapArray, i, 0);
	}
}

void heapify(int heapArray[], int n, int i)
{
	int largest = i;

	int l = 2 * i + 1;
	int r = 2 * i + 2;

	avg_steps5 += 4;
	if (l < n && heapArray[l] > heapArray[largest])
	{
		avg_steps5++;
		largest = l;
	}

	avg_steps5++;
	if (r < n && heapArray[r] > heapArray[largest])
	{
		avg_steps5++;
		largest = r;
	}

	avg_steps5++;
	if (largest != i)
	{
		avg_steps5 += 4;
		swap(heapArray[i], heapArray[largest]);

		heapify(heapArray, n, largest);
	}
}

int main()
{
	Sort s;
	int counter = 0;
	int input;
	int length;

	int *A;
	int *temp1;
	int *temp2;
	int *temp3;
	int *temp4;
	int *temp5;

	cout << "Random input: " << endl;
	do {
		input = s.NextInput(counter);
		cout << "Size of array currently is: " << input << endl;

		s.SetMax(input);
		length = s.GetMax();

		A = new int[length];
		temp1 = new int[length];
		temp2 = new int[length];
		temp3 = new int[length];
		temp4 = new int[length];
		temp5 = new int[length];

		for (int i = 0; i <= 50; i++)
		{
			s.fillrandom(A);
			for (int i = 0; i < length; i++)
			{
				temp1[i] = A[i];
				temp2[i] = A[i];
				temp3[i] = A[i];
				temp4[i] = A[i];
				temp5[i] = A[i];
			}

			high_resolution_clock::time_point start = high_resolution_clock::now();
			insertionsort(A, length);
			high_resolution_clock::time_point end = high_resolution_clock::now();
			duration<double, std::micro> timeRequired = (end - start);
			avg_time += timeRequired;

			high_resolution_clock::time_point start1 = high_resolution_clock::now();
			quickSort(temp1, 0, length - 1);
			high_resolution_clock::time_point end1 = high_resolution_clock::now();
			duration<double, std::micro> timeRequired1 = (end1 - start1);
			avg_time1 += timeRequired1; 

			high_resolution_clock::time_point start2 = high_resolution_clock::now();
			BubbleSort(temp2, length);
			high_resolution_clock::time_point end2 = high_resolution_clock::now();
			duration<double, std::micro> timeRequired2 = (end2 - start2);
			avg_time2 += timeRequired2;

			high_resolution_clock::time_point start3 = high_resolution_clock::now();
			selectionSort(temp3, length);
			high_resolution_clock::time_point end3 = high_resolution_clock::now();
			duration<double, std::micro> timeRequired3 = (end3 - start3);
			avg_time3 += timeRequired3;

			high_resolution_clock::time_point start4 = high_resolution_clock::now();
			MergeSort(temp4, 0, length - 1);
			high_resolution_clock::time_point end4 = high_resolution_clock::now();
			duration<double, std::micro> timeRequired4 = (end4 - start4);
			avg_time4 += timeRequired4;

			high_resolution_clock::time_point start5 = high_resolution_clock::now();
			heapSort(temp5, length);
			high_resolution_clock::time_point end5 = high_resolution_clock::now();
			duration<double, std::micro> timeRequired5 = (end5 - start5);
			avg_time5 += timeRequired5;
		}

		cout << "The average CPU time for insertion sort is: " << avg_time.count() / 50 << endl;
		cout << "The average steps for insertion sort is: " << avg_steps / 50 << endl;

		cout << "The average CPU time for selection sort is: " << avg_time1.count() / 50 << endl;
		cout << "The average steps for Quicksort sort is: " << avg_steps1 / 50 << endl;

		cout << "The average CPU time for bubble sort is: " << avg_time2.count() / 50 << endl;
		cout << "The average steps for Quicksort sort is: " << avg_steps2 / 50 << endl;

		cout << "The average CPU time for Quicksort sort is: " << avg_time3.count() / 50 << endl;
		cout << "The average steps for Quicksort sort is: " << avg_steps3 / 50 << endl;

		cout << "The average CPU time for merge sort is: " << avg_time4.count() / 50 << endl;
		cout << "The average steps for Quicksort sort is: " << avg_steps4 / 50 << endl;

		cout << "The average CPU time for heap sort is: " << avg_time5.count() / 50 << endl;
		cout << "The average steps for Quicksort sort is: " << avg_steps5 / 50 << endl;
		
		delete A;
		delete temp1;
		delete temp2;
		delete temp3;
		delete temp4;
		delete temp5;

		avg_time = std::chrono::microseconds::zero();
		avg_time1 = std::chrono::microseconds::zero();
		avg_time2 = std::chrono::microseconds::zero();
		avg_time3 = std::chrono::microseconds::zero();
		avg_time4 = std::chrono::microseconds::zero();
		avg_time5 = std::chrono::microseconds::zero();

		avg_steps = 0;
		avg_steps1 = 0;
		avg_steps2 = 0;
		avg_steps3 = 0;
		avg_steps4 = 0;
		avg_steps5 = 0;

		counter++;
		cout << endl;
	} 
	while (input < MAX);

	return 0;
}