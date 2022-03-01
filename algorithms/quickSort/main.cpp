#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    (*a) = (*a) + (*b);
    (*b) = (*a) - (*b);
    (*a) = (*a) - (*b);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] <= pivot)
        {
            cout << "i1111111111 " << arr[i] << endl;
            printArray(arr, 6);
            i++;
            /* code */
        }
        while (arr[j] > pivot)
        {
            cout << "j " << arr[j] << endl;

            j--;
        }
        if (i < j)
        {
            cout<< "Printing before swapping" <<endl;
            printArray(arr, 6);
            cout<< "Swapping" <<endl;
            swap(arr[i], arr[j]);
            cout<< "Printing after swapping" <<endl;
            printArray(arr, 6);
        }
    } while (i < j);
    cout<< "Out of while loop" <<endl;
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int arr[] = {2, 5, 1, 7, 6, 4};
    // int arr[] = {2, 5, 7, 8, 9, 10};
    int n = 6;
    cout << "Printing the array before sorting: " << endl;
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Printing the array after sorting: " << endl;
    printArray(arr, n);
    return 0;
}