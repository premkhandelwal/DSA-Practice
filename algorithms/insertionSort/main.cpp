#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void swap(int *a, int *b)
{
    (*a) = (*a) + (*b);
    (*b) = (*a) - (*b);
    (*a) = (*a) - (*b);
}

void insertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++) // Loop for passes
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {2, 5, 1, 7, 6, 4};
    // int arr[] = {2, 5, 7, 8, 9, 10};
    int n = 6;
    cout << "Printing the array before sorting: " << endl;
    printArray(arr, n);
    insertionSort(arr, n);
    cout << "Printing the array after sorting: " << endl;
    printArray(arr, n);
    return 0;
}