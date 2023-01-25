#include <iostream>
#include <chrono>
#include "class.h"

using namespace std;
using namespace std::chrono;

const int INSERTION_SORT_THRESHOLD = 32;
int const MAX = 50000;
unsigned long long int steps;

void insertionsort(int A[], int size);
void selectionSort(int selectionArray[], int n);
void BubbleSort(int arr[], int n);
void heapSort(int heapArray[], int n);
void heapify(int heapArray[], int n, int i);
void MergeSort(int *arr, int begin, int end);
void Merge(int *arr, int begin, int mid, int end);
void quickSort(int arr[], int begin, int end);
int partition(int arr[], int begin, int end);
void merge(int* array, int size, int* temp);
void merge_sort(int* array, int size, int* temp);
void combine_merge_sort_and_insertion_sort(int* array, int size);

void insertionsort(int A[], int size)
{
	steps++;
	high_resolution_clock::time_point start = high_resolution_clock::now();
	for (int i = 1; i <= size - 1; i++)
	{
		steps += 4;
		int temp = A[i];

		for (int j = i - 1; j >= 0 && temp < A[j]; j--)
		{
			steps += 5;
			A[j + 1] = A[j];
			A[j] = temp;
		}
	}
	high_resolution_clock::time_point end = high_resolution_clock::now();
	duration<double, std::micro> timeRequired = (end - start);
	cout << "The insertion sort algorthim took: " << timeRequired.count() << " micro seconds" << endl;
	cout << "Insertion sort number of steps: " << steps << endl << endl;
	steps = 0;
}

void selectionSort(int selectionArray[], int n) 
{
	high_resolution_clock::time_point start = high_resolution_clock::now();
	int min;
	steps += 2;
	for (int k = 0; k < n - 1; k++)
	{
		steps += 4;
		min = k;
		for (int j = k + 1; j < n; j++) 
		{
			steps += 4;
			if (selectionArray[j] < selectionArray[min])
			{
				steps++;
				min = j;
			}
		}
		steps++;
		swap(selectionArray[min], selectionArray[k]);
	}
	high_resolution_clock::time_point end = high_resolution_clock::now();
	duration<double, std::micro> timeRequired = (end - start);
	cout << "The selection sort algorthim took: " << timeRequired.count() << " micro seconds" << endl;
	cout << "Selection sort number of steps: " << steps << endl << endl;
	steps = 0;
}

void BubbleSort(int arr[], int n)
{
	high_resolution_clock::time_point start = high_resolution_clock::now();
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	steps += 3;
	high_resolution_clock::time_point end = high_resolution_clock::now();
	duration<double, std::micro> timeRequired = (end - start);
	cout << "The bubble sort algorthim took: " << timeRequired.count() << " micro seconds" << endl;
	cout << "Bubble sort number of steps: " << steps << endl << endl;
	steps = 0;
}


void heapSort(int heapArray[], int n) 
{
	steps++;
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		steps += 3;
		heapify(heapArray, n, i);
	}

	steps++;
	for (int i = n - 1; i > 0; i--)
	{
		steps += 6;
		swap(heapArray[0], heapArray[i]);
		heapify(heapArray, i, 0);
	}
}

void heapify(int heapArray[], int n, int i) 
{
	int largest = i;

	int l = 2 * i + 1;
	int r = 2 * i + 2;

	steps += 4;
	if (l < n && heapArray[l] > heapArray[largest])
	{
		steps++;
		largest = l;
	}

	steps++;
	if (r < n && heapArray[r] > heapArray[largest])
	{
		steps++;
		largest = r;
	}

	steps++;
	if (largest != i)
	{
		steps += 4;
		swap(heapArray[i], heapArray[largest]);

		heapify(heapArray, n, largest);
	}
}

void MergeSort(int *arr, int begin, int end) 
{
	steps++;
	if (begin < end) 
	{
		steps += 4;
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

	steps += 3;
}

void quickSort(int A[], int begin, int end)
{
	steps++;
	if (begin < end)
	{
		steps++;
		int p = partition(A, begin, end);

		steps++;
		quickSort(A, begin, p - 1);

		steps++;
		quickSort(A, p + 1, end);
	}
}

int partition(int A[], int begin, int end)
{
	steps += 3;
	int pivot = A[end];
	int index = (begin - 1);

	for (int j = begin; j <= end - 1; j++)
	{
		steps += 3;
		if (A[j] < pivot) 
		{
			steps += 4;
			index++;
			swap(A[index], A[j]);
		}
	}

	steps += 4;
	swap(A[index + 1], A[end]);
	return (index + 1);
}

void merge(int* array, int size, int* temp) 
{
	int middle = size / 2;
	int i = 0, j = middle, k = 0;

	while (i < middle && j < size) 
	{
		if (array[i] < array[j])
		{
			temp[k++] = array[i++];
		}

		else 
		{
			temp[k++] = array[j++];
		}
	}

	while (i < middle)
	{
		temp[k++] = array[i++];
	}

	while (j < size)
	{
		temp[k++] = array[j++];
	}

	for (int i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}

}

void merge_sort(int* array, int size, int* temp)
{
	if (size <= INSERTION_SORT_THRESHOLD)
	{
		return;
	}

	int middle = size / 2;
	merge_sort(array, middle, temp);
	merge_sort(array + middle, size - middle, temp);
	merge(array, size, temp);
}

void combine_merge_sort_and_insertion_sort(int* array, int size)
{
	if (size <= INSERTION_SORT_THRESHOLD)
	{
		insertionsort(array, size);
	}

	else
	{
		int* temp = new int[size];
		merge_sort(array, size, temp);
		delete[] temp;
	}
}

int main()
{	
	Sort s;
	int counter = 0;
	int input;
	int length;
	int *A;
	int *B;

	cout << "Sorted input: " << endl;
	do {
		input = s.NextInput(counter);
		cout << "Size of array currently is: " << input << endl;

		s.SetMax(input);
		length = s.GetMax();

		A = new int[length];
		B = new int[length];

		s.fillArray(A);
		s.fillArray(B);
		
		insertionsort(B, length);
		//s.print(B);
		s.ResetArrayB(A, B);

		selectionSort(B, length);
		//s.print(B);
		s.ResetArrayB(A, B);

		BubbleSort(B, length);
		//s.print(B);
		s.ResetArrayB(A, B);


		high_resolution_clock::time_point start = high_resolution_clock::now();
		heapSort(B, length);
		high_resolution_clock::time_point end = high_resolution_clock::now();
		duration<double, std::micro> timeRequired = (end - start);
		cout << "The Heapsort algorthim took: " << timeRequired.count() << " micro seconds" << endl;
		cout << "Heapsort number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);
		

		high_resolution_clock::time_point start2 = high_resolution_clock::now();
		MergeSort(B, 0, length - 1);
		high_resolution_clock::time_point end2 = high_resolution_clock::now();
		duration<double, std::micro> timeRequired2 = (end2 - start2);
		cout << "The merge sort algorthim took: " << timeRequired2.count() << " micro seconds" << endl;
		cout << "Merge sort number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);


		high_resolution_clock::time_point start3 = high_resolution_clock::now();
		quickSort(B, 0, length - 1);
		high_resolution_clock::time_point end3 = high_resolution_clock::now();
		duration<double, std::micro> timeRequired3 = (end3 - start3);
		cout << "The Quicksort algorthim took: " << timeRequired3.count() << " micro seconds" << endl;
		cout << "Quick sort number of steps: " << steps << endl << endl;
	    steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);

		high_resolution_clock::time_point start4 = high_resolution_clock::now();
		combine_merge_sort_and_insertion_sort(B, length);
		high_resolution_clock::time_point end4 = high_resolution_clock::now();
		duration<double, std::micro> timeRequired4 = (end4 - start4);
		cout << "The Merge && insertion sort algorthim took: " << timeRequired4.count() << " micro seconds" << endl;
		cout << "Merge && insertion number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);

		delete A;
	    delete B;

		counter++;
		cout << endl;
	} 
	while (input < MAX);

	
	counter = 0;
	cout << "Reverse input:" << endl;
	do {
		input = s.NextInput(counter);
		cout << "Size of array currently is: " << input << endl;

		s.SetMax(input);
		length = s.GetMax();

		A = new int[length];
		B = new int[length];

		s.fillReverse(A);
		s.fillReverse(B);
		
		insertionsort(B, length);
		//s.print(B);
		s.ResetArrayB(A, B);

		selectionSort(B, length);
		//s.print(B);
		s.ResetArrayB(A, B);

		BubbleSort(B, length);
		//s.print(B);
		s.ResetArrayB(A, B);


		high_resolution_clock::time_point start = high_resolution_clock::now();
		heapSort(B, length);
		high_resolution_clock::time_point end = high_resolution_clock::now();
		duration<double, std::micro> timeRequired = (end - start);
		cout << "The Heapsort algorthim took: " << timeRequired.count() << " micro seconds" << endl;
		cout << "Heapsort number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);
		

		high_resolution_clock::time_point start2 = high_resolution_clock::now();
		MergeSort(B, 0, length - 1);
		high_resolution_clock::time_point end2 = high_resolution_clock::now();
		duration<double, std::micro> timeRequired2 = (end2 - start2);
		cout << "The merge sort algorthim took: " << timeRequired2.count() << " micro seconds" << endl;
		cout << "Merge sort number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);


		high_resolution_clock::time_point start3 = high_resolution_clock::now();
		quickSort(B, 0, length - 1);
		high_resolution_clock::time_point end3 = high_resolution_clock::now();
		duration<double, std::micro> timeRequired3 = (end3 - start3);
		cout << "The Quicksort algorthim took: " << timeRequired3.count() << " micro seconds" << endl;
		cout << "Quick sort number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);

		high_resolution_clock::time_point start4 = high_resolution_clock::now();
		combine_merge_sort_and_insertion_sort(B, length);
		high_resolution_clock::time_point end4 = high_resolution_clock::now();
		duration<double, std::micro> timeRequired4 = (end4 - start4);
		cout << "The Merge && insertion sort algorthim took: " << timeRequired4.count() << " micro seconds" << endl;
		cout << "Merge && insertion number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);


		delete A;
		delete B;

		counter++;
		cout << endl;
	} 
	while (input < MAX);
	
	
	counter = 0;
	cout << "Random permutation input: " << endl;
	srand(unsigned(time(0)));
	do {
		input = s.NextInput(counter);
		cout << "Size of array currently is: " << input << endl;

		s.SetMax(input);
		length = s.GetMax();

		A = new int[length];
		B = new int[length];

		s.fillArray(A);
		s.fillArray(B);

		s.fillRandomperm(A);
		s.fillRandomperm(B);

		insertionsort(B, length);
		//s.print(B);
		s.ResetArrayB(A, B);

		selectionSort(B, length);
		//s.print(B);
		s.ResetArrayB(A, B);

		BubbleSort(B, length);
		//s.print(B);
		s.ResetArrayB(A, B);


		high_resolution_clock::time_point start = high_resolution_clock::now();
		heapSort(B, length);
		high_resolution_clock::time_point end = high_resolution_clock::now();
		duration<double, std::micro> timeRequired = (end - start);
		cout << "The Heapsort algorthim took: " << timeRequired.count() << " micro seconds" << endl;
		cout << "Heapsort number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);
		

		high_resolution_clock::time_point start2 = high_resolution_clock::now();
		MergeSort(B, 0, length - 1);
		high_resolution_clock::time_point end2 = high_resolution_clock::now();
		duration<double, std::micro> timeRequired2 = (end2 - start2);
		cout << "The merge sort algorthim took: " << timeRequired2.count() << " micro seconds" << endl;
		cout << "Merge sort number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);


		high_resolution_clock::time_point start3 = high_resolution_clock::now();
		quickSort(B, 0, length - 1);
		high_resolution_clock::time_point end3 = high_resolution_clock::now();
		duration<double, std::micro> timeRequired3 = (end3 - start3);
		cout << "The Quicksort algorthim took: " << timeRequired3.count() << " micro seconds" << endl;
		cout << "Quick sort number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);

		high_resolution_clock::time_point start4 = high_resolution_clock::now();
		combine_merge_sort_and_insertion_sort(B, length);
		high_resolution_clock::time_point end4 = high_resolution_clock::now();
		duration<double, std::micro> timeRequired4 = (end4 - start4);
		cout << "The Merge && insertion sort algorthim took: " << timeRequired4.count() << " micro seconds" << endl;
		cout << "Merge && insertion number of steps: " << steps << endl << endl;
		steps = 0;
		//s.print(B);
		s.ResetArrayB(A, B);

		delete A;
		delete B;

		counter++;
		cout << endl;
	}
	while (input < MAX);
	
	return 0;
}