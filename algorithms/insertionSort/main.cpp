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
    /* 
        arr = [5, 3, 2. 6, 8, 4]

        for i = 1:
            key = arr[i] = arr[1] = 3
            j = i - 1 = 1- 1 = 0
            while (j >= 0 && arr[j] > key) ==> 
                Loop 1:
                    while(0>=0 && 5 >3)
                    {
                        arr[j+1] = arr[j] ==> arr[1] = arr[0] ==> arr = [3, 3, 2, 6, 8, 4]
                        j-- ==> j = -1;
                    }
                Loop 2:
                    while(-1>=0) ==> Condition becomes false ;   ==> arr = [3, 3, 2, 6, 8, 4]    
            END OF WHILE LOOP

            arr = [3, 3, 2, 6, 8, 4]
            j = -1; key = 3;;
            arr[j+1] = key 
            arr[0] =  3
            arr = [3, | 5, 2, 6, 8, 4]


        for i = 2:
            arr = [3, 5, 2. 6, 8, 4]
            key = arr[i] = arr[2] = 5
            j = i - 1 = 2- 1 = 1
            while (j >= 0 && arr[j] > key) ==> 
                Loop 1:
                    while(1>=0 && 5 >5) ==> Condition becomes false as 5 == 5; arr = [3, 5, 2, 6, 8, 4]        
            END OF WHILE LOOP

            arr = [3, 5, 2, 6, 8, 4]    
            j = 1; key = 5;
            arr[j+1] = key 
            arr[1] =  5
            arr = [3, 5 | 2, 6, 8, 4]

        for i = 3:
            arr = [3, 5, 2. 6, 8, 4]
            key = arr[i] = arr[3] = 2
            j = i - 1 = 3- 1 = 2
            while (j >= 0 && arr[j] > key) ==> 
                Loop 1:
                    while(0>=0 && 5 >3)
                    {
                        arr[j+1] = arr[j] ==> arr[1] = arr[0] ==> arr = [3, 3, 2, 6, 8, 4]
                        j-- ==> j = -1;
                    }
                Loop 2:
                    while(-1>=0) ==> Condition becomes false ;   ==> arr = [3, 3, 2, 6, 8, 4]        
            END OF WHILE LOOP
     */
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