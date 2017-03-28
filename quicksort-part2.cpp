#include <bits/stdc++.h>

using namespace std;

void printArr(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(vector <int> &arr) {
   // Complete this function
    if(arr.size() < 2) {
        return;
    }
    int pivot = arr[0];
    vector<int> left;
    vector<int> right;
    for (int i = 1; i < arr.size(); i++){
        if(arr[i] < pivot){
            left.push_back(arr[i]);
        }else{
            right.push_back(arr[i]);
        }
    }    
    quickSort(left);
    quickSort(right);
    
    int i = 0;
    for (; i < left.size(); i++){
        arr[i] = left[i];
    }
    arr[i] = pivot;
    for (int j = 0; j < right.size(); j++){
        i++;
        arr[i] = right[j];
    }
    printArr(arr);
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}