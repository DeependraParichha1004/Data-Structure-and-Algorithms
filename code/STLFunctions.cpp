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
void printvec(vector<vector<int>> vec){
    for(int i=0;i<vec.size();i++){
        for(auto it=vec[i].begin();it!=vec[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

void TBReverse(vector<vector<int>>& vec){
    for(auto mat:vec) reverse(mat.begin(),mat.end());
}


void BTReverse(vector<vector<int>>& vec){
    reverse(vec.begin(),vec.end());
}

void nex_per(int arr[],int n){
    do{
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
    }while(next_permutation(arr,arr+n));
}

void prev_per(int arr[],int n){
    do{
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
    }while(prev_permutation(arr,arr+n));
}

int main(){
    vector<vector<int>> vec={{1,2,3},
                              {4,5,6},
                              {7,8,9}};

    //bottom to top reverse                          
    // BTReverse(vec);

    //top to bottom reverse
    // TBReverse(vec);
    // printvec(vec);

    //next and prev permutation O(N*N)
    //next permutation -> It is used to rearrange the elements in the range 
    //[first, last) into the next lexicographically greater permutation
    // int arr[]={1,2,3};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // nex_per(arr,n);

    //prev permutation -> It is used to rearrange the elements in the range 
    //[first, last) into the previous lexicographically-ordered permutation
    // int arr[]={3,2,1};//important
    // int n=sizeof(arr)/sizeof(arr[0]);
    // prev_per(arr,n);

    
    return 0; 
}