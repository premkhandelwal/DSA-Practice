#include <iostream>

using namespace std;

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] << " ";
    }
    cout<<endl;
    
}

int insertInd(int arr[], int size, int index, int element){
    for (int i = size - 1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return index;
    
}

int main(){
    int arr[100] = {1,2,6,53};
    int size = 4;
    display(arr, size);
    insertInd(arr, size,3, 45);
    size++;
    display(arr, size);
    return 0;
}