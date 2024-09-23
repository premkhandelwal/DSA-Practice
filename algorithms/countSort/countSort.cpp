#include <bits/stdc++.h>

using namespace std;

void countSort(vector<int> &arr){
    int n = arr.size();
    if(n <= 1){
        return;
    }
    int k = arr[0];
    for(int i: arr){
        k = max(k, i);
    }
    vector<int> countArr(k);
    for(int i = 0; i < n; i++){
        countArr[arr[i]]++;
    }
    for(int i = 1; i <= k; i++){
        countArr[i] = countArr[i] + countArr[i - 1]; 
    }
    vector<int> outputArr(n);
    for(int i = n - 1; i >= 0; i--){
        outputArr[--countArr[arr[i]]] = arr[i];
    }
    for(int i = 0; i < n; i++){
        arr[i] = outputArr[i];
    }
    return;
    //0 1 2 3 4 5 6 7 8 9
    //0 1 2 1 1 1 1 2 1 1

    //0 1 3 4 5 6 7 9 10 11
    //

}

int main(){
    vector<int> arr = {3, 5, 2, 4, 7, 7, 7, 6, 2, 1};
    int n = arr.size();
    countSort(arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}