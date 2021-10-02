#include <bits/stdc++.h>
using namespace std;

int binarySearch(int* arr, int len, int target){

    int low=0, high=len, mid;
    while(low <= high){
        mid = low + (high-low)/2; // mid = (low+high)/2 
        if (arr[mid] == target){
            return mid; // return if target found at mid
        } else if (arr[mid] > target){
            high = mid-1; 
            // if target is smaller than mid element
            // then it will be present between low & mid-1 
        } else {
            low = mid+1;
            // if target is smaller than mid element
            // then it will be present between mid+1 & high 
        }
    }

    return -1; // to indicate target was not found in array
}

int main(){

    int arr[] = {1, 2, 3, 5, 7, 10, 12, 30, 40, 45};
    // For binary search to work, the array must be sorted
    int target = 40;
    int n = sizeof(arr)/sizeof(arr[0]); // size of array

    int key = binarySearch(arr, n, target);

    if (key == -1){
        cout << "Target element not found" << endl;
    } else {
        cout << "Target element found at position " << key << endl;
    }

    return 0;
}