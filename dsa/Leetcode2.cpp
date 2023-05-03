/* Contents
(1) Finding Pivot element from rotated and sorted array
(2) Searching a pivot element(given) from rotated and sorted array
(3) Square root
*/

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

int pivot_element(int arr[], int n)
{
    int l = 0, r = n - 1;
    int mid = l + (r - l) / 2;
    while (l < r)
    {

        if (arr[mid] >= arr[0])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
        mid = l + (r - l) / 2;
    }
    return l;
}

int rotated_search(int arr[], int n, int key)
{
    int l = 0, r = n - 1;
    int mid = l + (r - l) / 2;

    while (l <= r)
    {
        if (arr[mid] == key)
            return mid;

        // left sorted
        if (arr[l] <= arr[mid])
        {
            if (key >= arr[l] && key <= arr[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        // right sorted
        else
        {
            if (key <= arr[r] && key > arr[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        mid = l + (r - l) / 2;
    }

    return -1;
}

int sqrt(int x)
{
    int l = 0;
    int r = x;
    long long int mid = l + (r - l) / 2;
    int ans = -1;
    while (l <= r)
    {
        long long int sq = mid * mid;
        if (sq == x)
            return mid;
        if (sq > x)
        {

            r = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid + 1;
        }
        mid = l + (r - l) / 2;
    }

    return ans;
}

double moreprecision(int n,int precision,int tempSol){
    double factor=1;
    double ans=tempSol;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}

int matrix_search(){
    vector<vector<int>> matrix;
    matrix={
        {1,2,3},
        {5,6,7},
        {10,11,12}
    };
    // int m=3,n=3;
    int target=8;

    int n = matrix.size();
    int m = matrix[0].size();
    int l = 0, r = m * n - 1;
    int mid = l+(r-l)/2;
    while (l != r){
        if (matrix[mid / m][mid % m] < target)
            l = mid + 1;
        else 
            r = mid;
        mid = l+(r-l)/2;
        
    }
    int sol =(matrix[mid/m][mid%m]==target);

    if(sol){
        cout<<"Present";
    }
    else{
        cout<<"absent";
    }
}

bool isPossible(vector<int> &arr,int n,int m,int inx){
    int studentCount=1;
    int sum=0;
    for(int i=0;i<4;i++){
        if(sum+arr[i]<=inx){
            sum=sum+arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>inx){
                return false;
            }
            sum=arr[i];
        }
    }
    return true;
}

void selection_sort(vector<int> &arr,int n){
    
    for(int i=0;i<arr.size()-1;i++){
        int min=i;
        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        
        swap(arr[min],arr[i]);
    }
    
    // in descending order
    // vector<int> arr{3,6,1,8,2};
    // for(int i=arr.size()-1;i>0;i--){
    //     int min=i;
    //     for (int j = i-1; j >=0; j--)
    //     {
    //         if(arr[j]<arr[min]){
    //             min=j;
    //         }
    //     }
        
    //     swap(arr[min],arr[i]);
    // }

    cout<<endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(vector<int>& arr, int n)
{   
    //The most optimized answer
    bool swapped=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){ // j<n-i
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
    }



    // for(int i=0;i<n-1;i++){
    //     int first=i;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[first]>arr[j]){
    //             swap(arr[first],arr[j]);
    //         }
    //     }
    // }

    // for(int i=1;i<n;i++){
    //     for(int j=0;j<n-1;j++){ // j<n-1
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j+1],arr[j]);
    //         }
    //     }
    // }

    // for(int i=1;i<n;i++){
    //     for(int j=0;j<n-i;j++){ // j<n-i
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j+1],arr[j]);
    //         }
    //     }
    // }

    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-i-1;j++){ // j<n-i
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j+1],arr[j]);
    //         }
    //     }
    // }


}

int main()
{
    // cout << "execution started" << endl;
    // int arr[] = {8, 10, 17, 1, 3};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // cout << pivot_element(arr, n) << endl;
    // cout << "execution comleted";

    // int arr[] = {3,8,10,17,1}; // original array -> {20,30,40,50,60,90,100}
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int key = 3;
    // int ans = rotated_search(arr, n, key);
    // cout << ans << endl;
    // cout << "ans";
    
    
    //sqrt
    // int n=37;
    // int tempSol=sqrt(n);
    // cout<<tempSol;
    // cout<<moreprecision(n,3,tempSol);


    // Allocate Books, Painters Partition, Aggressive Cows
    // vector<int> arr{30,10,20,40};
    // int n=4,m=2;
    // int s=0;
    // int e=100;
    // int ans=-1;
    // int mid=s+(e-s)/2;
    // while(s<=e){
    //     if(isPossible(arr,n,m,mid)){
    //         ans=mid;
    //         e=mid-1;
            
    //     }
    //     else{
    //         s=mid+1;
    //     }
    //     mid=s+(e-s)/2;
    // }
    // cout<<ans;
    


    // selection sort
    // vector<int> arr{46,27,12,5,33,6};
    // selection_sort(arr,arr.size());
    // cout<<endl;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout<<arr[i]<<" ";
    // }


    //Remove all occurences of a sub string
    string str1="eidbaooo";
    string str2="ab";
    while(str1.length()!=0 && str1.find(str2)<str1.length() ){
        str1.erase( str1.find(str2),str2.length() );
    }
    cout<<str1;
    
    return 0;
}
