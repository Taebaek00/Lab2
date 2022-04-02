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
void bubble_sort_descending(int* array, unsigned int size);
void insertion_sort_descending(int* array, unsigned int size);
void selection_sort_descending(int* array, unsigned int size);

int main(void) {
        srand((unsigned int)time(NULL));

        int size;
        cout << "Give me the size : ";
        cin >> size;
        
        int type_sort;
        cout << "Give me the type of algorithm (0: Bubble, 1: Insertion, 2: Selection): ";
	    cin >> type_sort;


        arr mysort;
	    mysort.init(size);


	    if (type_sort ==0){
            mysort.sort(bubble_sort_descending);
            mysort.print();
	        mysort.reset();
        } 
        else if (type_sort ==1){
	        mysort.sort(insertion_sort_descending);
            mysort.print();
	        mysort.reset();
        }
        else if (type_sort ==2){
	        mysort.sort(selection_sort_descending);
	        mysort.print();
	        mysort.reset();
        }
        

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
                int rnd_num;
                cin >> rnd_num;
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
                        if (ref_array[i] < ref_array[i + 1])
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
    for (int i = 0; i < size; i++){
       cout << ref_array[i]  ;
       cout << " "  ;
       }
       cout << " "<<endl;
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


void bubble_sort_descending(int* array, unsigned int size) {
    for (unsigned int i = 0; i < size - 1; i++)
    {
        for(int j = size - 1; j > i; j--){
            if(array[j] > array[j-1]) {
                swap(array[j], array[j-1]);
            }
        }
    }
}

void insertion_sort_descending(int* array, unsigned int size) {
	for (unsigned int i = 1; i < size; i++)
	{
        int j = i - 1;
        int tmp = array[i];
        while(1) {
            if(j >= 0 && tmp > array[j]) {
                array[j + 1] = array[j];
            }
            else {
                break;
            }
            j--;
        }
        array[j + 1] = tmp;
	}
}

void selection_sort_descending(int* array, unsigned int size) {
	for (unsigned int i = 0; i < size - 1; i++)
	{
        int max = array[i];
        int max_ind = i;
        for(int j = i; j < size; j++) {
            if(max < array[j]) {
                max = array[j];
                max_ind  = j;
            }
        }
        swap(array[max_ind], array[i]);
	}
}


