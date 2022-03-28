/*
::: SourceCode CopyRight @ Yongil Kim
::: Apr.2020 SNU MiLab
::: miles94@snu.ac.kr
*/
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
class arr {
public:
	arr();
	~arr();
	void sort(void (*f)(int*, unsigned int));
	void sort(void(*f)(int*, int, int));
	void init(int n);
	void reset();
	void check();
	void print();
private:
	int* input_array;
	int* ref_array;
	int size;
};
void swap(int& a, int& b);
void bubble_sort(int* array, unsigned int size);
void insertion_sort(int* array, unsigned int size);
void selection_sort(int* array, unsigned int size);
void max_heap_sort(int* array, unsigned int size);
void merge_sort(int* array, int l, int r);

int main(void) {
	srand((unsigned int)time(NULL));

	int size;
	clock_t start, end;
	double passed_time;
	cout << "Give me the size : ";
	cin >> size;
	cout << "" << endl;
	arr mysort;
	mysort.init(size);

	cout << "orginal: ";
	mysort.print();
	cout << "" << endl;


	cout << "Bubble Sort : ";
	start = clock();
	mysort.sort(bubble_sort);
	end = clock();
	mysort.print();

	passed_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.3f(s) & ", passed_time);
	mysort.check();
	mysort.reset();

	cout << "Insertion Sort : ";
	start = clock();
	mysort.sort(insertion_sort);
	end = clock();
	mysort.print();

	passed_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.3f(s) & ", passed_time);
	mysort.check();
	mysort.reset();

	cout << "Selection Sort : ";
	start = clock();
	mysort.sort(selection_sort);
	end = clock();
	mysort.print();
	passed_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.3f(s) & ", passed_time);
	mysort.check();
	mysort.reset();

	cout << "Heap Sort : ";
	start = clock();
	mysort.sort(max_heap_sort);
	end = clock();
	mysort.print();
	passed_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%.3f(s) & ", passed_time);
	mysort.check();
	mysort.reset();

	return 0;
}


arr::arr() {}
arr::~arr() {
	delete[] input_array;
	delete[] ref_array;
}

void arr::init(int size) {
	this->size = size;
	input_array = new int[size];
	ref_array = new int[size];
	for (int i = 0; i < size; i++) {
		int rnd_num = (int)(rand() % 1000);
		input_array[i] = rnd_num;
		ref_array[i] = rnd_num;
	}
}

void arr::reset() {
	if (ref_array == nullptr) ref_array = new int[size];
	for (int i = 0; i < size; i++)
		ref_array[i] = input_array[i];
	cout << "Reset" << endl << endl;

}

void arr::check() {
	bool check = true;
	if (ref_array == nullptr)
		cout << "Error! The array has no element." << endl;
	else {
		for (int i = 0; i < size - 1; i++) {
			if (ref_array[i] > ref_array[i + 1])
				check = false;
		}
	}
	if (check) cout << "Correct!" << endl;
	else cout << "Wrong!" << endl;
}

void arr::sort(void(*f)(int*, unsigned int)) {
	f(ref_array, size);
}

void arr::sort(void(*f)(int*, int, int)) {
	f(ref_array, 0, (int)(size - 1));
}


void arr::print() {
	for (int i = 0; i < size; i++) {
		cout << ref_array[i];
		cout << " ";
	}
	cout << " " << endl;
}


void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}


/*###################################################################################
##########################  Incremental Algorithm ###################################
#####################################################################################
*/

void bubble_sort(int* array, unsigned int size) {
	for (unsigned int i = 0; i < size - 1; i++)
		for (unsigned int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{


				//               	###################implement here################
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				//                 #################################################


			}
		}
}

void insertion_sort(int* array, unsigned int size) {
	for (unsigned int i = 1; i < size; i++)
	{
		int temp = array[i];
		int j = i - 1;
		while (1)
		{


			//                 ###################implement here################
			if (j < 0) break;
			if (temp >= array[j]) break;
			array[j + 1] = array[j];
			j--;
			//                 #################################################


		}
		array[j + 1] = temp;
	}
}

void selection_sort(int* array, unsigned int size) {
	for (unsigned int i = 0; i < size - 1; i++)
	{
		int min = array[i];
		int min_idx = i;
		for (unsigned int j = i + 1; j < size; j++)
		{

			//                 ###################implement here################
			if (min > array[j])
			{
				min_idx = j;
				min = array[min_idx];
			}
			//                 #################################################


		}
		swap(array[i], array[min_idx]);
	}
}


void max_heapify(int* array, int index, int heap_size) {
	int L = 2 * index + 1;
	int R = 2 * index + 2;
	int largest;

	//         ###################implement here################
	//
	if (L<heap_size && array[L]>array[index])
		largest = L;
	else largest = index;
	if (R<heap_size && array[R]>array[largest])
		largest = R;
	if (largest != index)
	{
		swap(array[largest], array[index]);
		max_heapify(array, largest, heap_size);
	}
	//         #################################################
}

void max_heap_sort(int* array, unsigned int size) {
	int heap_size = size;
	for (int i = size / 2 - 1; i >= 0; i--)
		max_heapify(array, i, heap_size);

	for (int i = size - 1; i > 0; i--) {
		swap(array[0], array[i]);
		max_heapify(array, 0, --heap_size);
	}


}
