#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == element){
            return i;
        }
    }
    return -1;   
}

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    while (low<=high)
    {
        mid = (low+high)/2; 
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] > element){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
    cout<< "mid" <<mid <<endl;
}

int main(){
    int arr[]= {2,3,18,23,34};
    int size = sizeof(arr)/sizeof(int);
    int searchInd = binarySearch(arr, size, 158);
    cout<< "Element found at index " << searchInd <<endl;
    return 0;
}