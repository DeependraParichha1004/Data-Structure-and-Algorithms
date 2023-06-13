#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <typeinfo>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

int frequency(int arr[], int n)
{

    // vector
    vector<int> visited(n, 0);

    int unique = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {

        if (visited[i] == 1)
        {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j] = 1;
                count++;
            }
        }

        cout << arr[i] << " " << count << endl;

        if (unique != count)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}

//multiple duplicate elements
int findDuplicate(vector<int> &arr) 
{
    
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]=mp[arr[i]]+1;
    }

    for(auto pr:mp){
        if(pr.second>=2){
            return pr.first;
        }
    }
    return 0;
	
}

int duplicate(int arr[],int n){
    
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]=mp[arr[i]]+1;
    }

    for(auto pr:mp){
        if(pr.second>=2){
            return pr.first;
        }
    }

    // for (int i = 0; i < mp.size(); i++)
    // {
    //     if(mp[i]>=2){
    //         return mp[i].first;
    //     }
    // }

    return 0;
}

// An interval has start time and end time
struct Interval {
    int start, end;
};
  

// Compares two intervals according to starting times.
bool compareInterval(Interval i1, Interval i2)
{   
    //character - { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } }
    return (i1.start < i2.start);
}


//driver code
int main()
{

    // unordered_set
    //  unordered_set<string> s{"harsh","max","mmanshi","divya"};
    //  for (auto i = s.begin(); i != s.end(); i++)
    //  {
    //      cout<<&i<<" ";
    //  }
    //  cout<<endl;

    // for (unsigned i = 0; i < s.bucket_count(); i++)
    // {
    //     cout<<"bucket no "<<i<<": ";
    //     for (auto j = s.begin(i); j !=s.end(i); j++)
    //     {
    //         cout<<" "<<*j;
    //     }
    //     cout<<endl;
    // }


    // list
    //  list<int> list1{1,2,3};
    //  for (auto i = list1.begin(); i != list1.end(); i++)//iterating
    //  {
    //      cout<<*i<<" ";
    //  }

    // list1.assign(3, 2);//output 2,2,2

    // // initializing list iterator to beginning
    // list<int>::iterator it = list1.begin();

    // // iterator to point to 3rd position
    // advance(it, 2);
    
    // list1.insert(it, 5);
    // for (auto it = list1.begin(); it != list1.end(); it++)//iterating
    // {
    //     cout<<*it<<" ";
    // }



    // set
    //  set<string> s{"harsh","max","manshi","divya","manshi","Harsh","max"};
    //  for (auto i = s.begin(); i != s.end(); i++)
    //  {
    //      cout<<*i<<" ";
    //  }
    //  cout<<endl;



    //unordered map
    // int arr[]={3,3,4,4,4,7,8,8,8,8};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // unordered_map<int,int> mp;
    // set<int> st;

    // map<int,int>::iterator it;
    // for(int it1=0;it1<n;it1++){
        
    //     mp[arr[it1]]+=1;
    // }
    // cout<<endl;
    // // for(auto pr:mp){
    // //     cout<<pr.first<<" "<<pr.second<<endl;;
    // // }
    // for(auto pr:mp){
    //     st.insert(pr.second);
    // }
    // if(mp.size()==st.size()){
    //     return true;
    // }
    // else{
    //     return false;
    // }



    //vector
    // vector<int> arr{6, 3, 1, 5, 4, 3, 2};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int ans=duplicate(arr,n);
    // int ans=findDuplicate(arr);
    // cout<<ans;


    //unordered map
    // unordered_map<int,int> mp;
    // for(int i=0;i<n;i++){
    //     mp[arr[i]]=mp[arr[i]]+1;
    // }

    // for(auto pr:mp){
    //     cout<<pr.first<<" "<<pr.second<<endl;
    // }

    // for (int i = 0; i < mp.size(); i++)
    // {
    //     if(mp[i]>=2){
    //         return mp[i];
    //     }
    // }
    

    //unordered set
    // unordered_set<string> s{"harsh","max","mmanshi","divya"};
    // for (auto i = s.begin(); i != s.end(); i++)
    // {
    //     cout<<&i<<" ";
    // }
    // cout<<endl;

    // for (unsigned i = 0; i < s.bucket_count(); i++)
    // {
    //     cout<<"bucket no "<<i<<": ";
    //     for (auto j = s.begin(i); j !=s.end(i); j++)
    //     {
    //         cout<<" "<<*j;
    //     }
    //     cout<<endl;
        

    //vectors
    // vector<int> vect{1,-2,4,5,2,-6,0,9,3};
    // sort(vect.begin(),vect.end(),greater<int>());//in descending order default(ascending order)

    // for(auto p:vect){
    //     cout<<p<<" ";
    // }    



    //sort vector of pairs
    // vector<Interval> v { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
  
    // // sort the intervals in increasing order of
    // // start time
    // sort(v.begin(), v.end(),compareInterval);
  
    // cout << "Intervals sorted by start time : \n";
    // for (auto x : v)
    //     cout << "[" << x.start << ", " << x.end << "] ";
    

    return 0;
}
