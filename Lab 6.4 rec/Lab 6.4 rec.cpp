#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>
using namespace std;

void printArray(int* array, int size, int i);
void generateArray(int* arr, int size, int min, int max, int i);
int multPairElements(int* arr, int size, int i);
void printModifiedArray(int* arr, int size, int i);
int sumOfArrayElements(int* arr, int size, int sum, int i);
void QuickSortModified(int* arr, int left, int right);

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int n;
    cout << "n: "; cin >> n;
    int* p = new int[n];
    generateArray(p, n, -10, 10, 0);

    cout << "ArrayElements                     : ";
    printArray(p, n, 0);
    cout << endl;

    int multipleOfPairElements = multPairElements(p, n, 0);
    cout << "Multiply of pair elements in array: " << multipleOfPairElements << endl;


    int Sum = sumOfArrayElements(p, n, 0, 0);
    cout << "Sum of array elements             : " << Sum;
    cout << endl;

    QuickSortModified(p, 0, n - 1);
    cout << "Sorted Array                      : ";


    printModifiedArray(p, n, 0);

    delete[] p;
    return 0;
}


void printArray(int* array, int size, int i) {
    if (i < size) {
        cout << setw(2) << array[i] << " ";
    }
    else return;
    return printArray(array, size, i + 1);
}

void generateArray(int* arr, int size, int min, int max, int i) {
    if (i < size) {
        arr[i] = min + rand() % (max - min + 1);
        generateArray(arr, size, min, max, i + 1);
    }
    else return;
}

void printModifiedArray(int* arr, int size, int i) {
    if (i < size) {
        cout << setw(2) << arr[i] << " ";
        printModifiedArray(arr, size, i + 1);
    }
    else return;
    cout << endl;
}

int multPairElements(int* arr, int size, int i) {
    if (i < size) {
        if (arr[i] == 0) {
            arr[i] = 1;
        }
        if (i % 2 == 0) {
            return arr[i] * multPairElements(arr, size, i + 1);
        }
        return multPairElements(arr, size, i + 1);
    }
    return 1;
}

int sumOfArrayElements(int* arr, int size, int sum, int i) {
    if (i < size) {
        if (i != 0 && i != size - 1) {
            sum += arr[i];
        }
        sumOfArrayElements(arr, size, sum, i + 1);
    }
    else return sum;
}


void QuickSortModified(int* arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp; 

    while (i <= j) {
        while (arr[i] > pivot) 
            i++;
        while (arr[j] < pivot) 
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }


    if (left < j)
        QuickSortModified(arr, left, j);
    if (i < right)
        QuickSortModified(arr, i, right);
}
