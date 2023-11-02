#include <iostream>
#include <cmath>
#include <random>
using namespace std;

void printArray(int* array, int size, int i);
void generateArray(int* arr, int size, int min, int max, int i);
int MaxElement(int a[], const int size, int i, int max);
int Sum(int a[], const int size, int i, int sum);
void ModArray(int a[], int size, int aval, int bval, int i, int j);

template <typename T>
T SumSecond(T a[], const int size, int i, int sum) {
    if (i == size) {
        return sum;
    }
    if (a[i] > 0) {
        return SumSecond(a, size, i + 1, 0);
    }
    sum += a[i];
    return SumSecond(a, size, i + 1, sum);
}

int main() {
    int n;
    cout << "n: "; cin >> n;
    int *p = new int [n];
    generateArray(p, n, -10, 10, 0);

    cout << "Array Elements: ";
    printArray(p, n, 0);
    cout << endl;

    cout << "MaxNumber: ";
    int max = MaxElement(p, n, 0, INT_MIN);
    cout << max << endl;

    int Summ = Sum(p, n, 0, 0);
    cout << "Start Sum: " << Summ << endl;
   
    int fnum, snum;
    int t[10];
    cout << "type num: ";  cin >> fnum;
    cout << "type second num: ";  cin >> snum;
    
    cout << "\nModified: " << endl;
    generateArray(t, 10, fnum, snum, 0);
    int Summ2 = SumSecond(t, 10, 0, 0);
    cout << "Last Sum: " << Summ2 << endl;
    printArray(t, 10, 0);

    return 0;
}


void printArray(int *array, int size, int i) {
    if (i < size) {
        printf("%d ", array[i]);
    }
    else return;
    return printArray(array, size, i + 1);
}

void generateArray(int* arr, int size, int min, int max, int i) {
    if (i < size) {
        arr[i] = min + rand() % (max - min + 1);
        generateArray(arr, size, min, max, i + 1);
    }
}

int MaxElement(int a[], const int size, int i, int max = INT_MIN) {
    if (i == size) {
        return max;
    }
    if (a[i] > max) {
        max = a[i];
    }
    return MaxElement(a, size, i + 1, max);
}

int Sum(int a[], const int size, int i, int sum) {
    if (i == size) {
        return sum;
    }
    if (a[i] > 0) {
        return Sum(a, size, i + 1, 0);
    }
    sum += a[i];
    return Sum(a, size, i + 1, sum);
}



void ModArray(int a[], int size, int fnum, int snum, int i, int j) {
    if (i == size) {
        size = j;
        while (j < 25) {
            a[j] = 0;
            j++;
        }
    }
    else {
        if (abs(a[i]) < fnum || abs(a[i]) > snum) {
            a[j] = a[i];
            ModArray(a, size, fnum, snum, i + 1, j + 1);
        }
        else {
            ModArray(a, size, fnum, snum, i + 1, j);
        }
    }
}