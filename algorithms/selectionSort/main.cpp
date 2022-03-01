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
}

void selectionSort(int arr[], int n)
{
    int minInd,j;
    for (int i = 0; i < n-1; i++)
    {
        minInd = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[minInd])
            {
                minInd = j;
            }
        }
        swap(arr[i] , arr[minInd]);
        
    }

    
}

int main(){
    int arr[] = {2, 5, 1, 7, 6, 4};
    // int arr[] = {2, 5, 7, 8, 9, 10};
    int n = 6;
    cout << "Printing the array before sorting: " << endl;
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "Printing the array after sorting: " << endl;
    printArray(arr, n);
    return 0;
}