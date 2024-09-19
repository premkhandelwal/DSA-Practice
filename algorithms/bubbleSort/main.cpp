#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void swap(int* a, int* b)
{
    (*a) = (*a) + (*b);
    (*b) = (*a) - (*b);
    (*a) = (*a) - (*b);
}

void bubbleSort(int arr[], int n)
{
    int isSorted = 0;
    for (int i = n - 1; i >= 1; i--) // For number of pass - -1 because last element will by default be at correct position
    {
        cout<< "Working on pass number: " << i <<endl;
        isSorted = 1; // A) Set isSorted at beginning of each PASS
        for (int j = 0; j < i; j++) // For comparison in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j+1]);
                isSorted = 0; // B) If it comes in this loop, that means array is not sorted
            }
        }
        if(isSorted)
        {
            return;
        }
    }
}

int main()
{
    // int arr[] = {2, 5, 1, 7, 6, 4};
    int arr[] = {2, 5, 7,8,9,10};
    int n = 6;
    cout << "Printing the array before sorting: " << endl;
    printArray(arr, n);
    bubbleSort(arr, n);
    cout << "Printing the array after sorting: " << endl;
    printArray(arr, n);
    return 0;
}
