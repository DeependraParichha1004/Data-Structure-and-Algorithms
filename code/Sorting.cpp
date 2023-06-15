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
        // if (min != i)
        // {
        //     swap(arr[min], arr[i]);
        // }
        swap(arr[min], arr[i]);
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

int partition(int arr[],int l,int h){
    //pivot low
    int pivot=arr[l];
    //pivot high
    // int pivot=arr[h];
    int i = l-1 , j = h + 1;
    while(i<j){
        
        do{
            i++;
        }while(arr[i]<pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i<j){
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[l],arr[j]);
    return j;
}

void quicksort(int arr[],int l,int h){
    if(l<h){
        int part_idx=partition(arr,l,h);
        quicksort(arr,l,part_idx);
        quicksort(arr,part_idx+1,h);
    }
}

int main()
{
    // (1) Selection Sort
    vector<int> arr{45212, -8, 34, 23, 11, 0, 8, 45, 3, 2, 8, -100};
    selection_sort(arr);

    //(2) Binary Search
    // int arr[]={5,-8,3,4,1,0,6,2};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int idx=binary_search(arr,0,n-1,1);
    // cout<<"The no is at: "<<idx;

    // (3) quick sort
    // consist of two parts ->
    //(a) quick sort ans (2) partition algorithm 
    // int arr[]={10,80,30,90,40};
    // int arr[]={ 10, 7, 8, 9, 1, 5 };
    // int arr[]={10,16,8,12,15,6,3,9,5};
    // int arr[]={70,40,10,90,30};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int l=0,h=n-1;
    // quicksort(arr,l,h);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    
    return 0;
}