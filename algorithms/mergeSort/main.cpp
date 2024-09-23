#include <bits/stdc++.h>

using namespace std;

void mergeAndCount(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int i = low;
    int j = mid + 1;
    while(i <= mid && j <= high){
        if(arr[i] > arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= high){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
    return;
}

void mergeSort(vector<int> &arr, int low, int high) {
    if(low == high){
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeAndCount(arr, low, mid, high);
    return;
}

int main(){
    vector<int> arr = {3, 4, 2, 5, 7, 1, 3, 9, 3, 2, 4};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    for(auto i: arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}