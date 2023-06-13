#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <typeinfo>
#include <utility>
#include <vector>
#include <unordered_set>
using namespace std;


void selection_sort(vector<int> arr){
    int elem = 0;
    int min = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(arr[min], arr[i]);
        }
    }
    cout << "The sorted array:" << endl;
    for (auto p : arr)
    {
        cout << p << " ";
    }
    cout << endl;
}

int binary_search(int arr[], int l, int r, int key)
{
    sort(arr,arr+r+1);
    int mid = l + (r - l) / 2;
    while (l <= r)
    {

        if (key == arr[mid])
        {
            return mid;
        }
        if (key < arr[mid])
        { // left
            return binary_search(arr, 0, mid - 1, key);
        }
        if (key > arr[mid])
        {
            return binary_search(arr, mid + 1, r, key);
        }
        mid = l + (r - l)/2;
    }
    return -1;
}


int main()
{
    // (1) Selection Sort
    // vector<int> arr{45212, -8, 34, 23, 11, 0, 8, 45, 3, 2, 8, -100};
    // selection_sort(arr);

    //(2) Binary Search
    // int arr[]={5,-8,3,4,1,0,6,2};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int idx=binary_search(arr,0,n-1,1);
    // cout<<"The no is at: "<<idx;

    return 0;
}