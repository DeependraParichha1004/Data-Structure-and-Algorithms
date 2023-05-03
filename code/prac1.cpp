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
#include <numeric>
#include <cmath>
#include <chrono>
using namespace std::chrono;
using namespace std;

string reverse_string(string &str){
    int l=str.length();
    for(int i=0;i<l/2;i++){
        swap(str[i],str[l-i-1]);
    }
    return str;
}
string rec_rev(string &str,int n,int i){

    if(n<=i){
        return str;
    }
    swap(str[i],str[n]);
    rec_rev(str,n-1,i+1);
}

bool palindrome(string &str,int l){
    for(int i=0;i<l/2;i++){
        if(str[i]==str[l-i]){
            return true;
        }
        return false;
    }
    
}

//Check If The String Is A Palindrome
string Clean(string s){
    string temp="";
    int l=0;
    int e=s.length()-1;
    for(int i=0;i<s.length();i++){
        if( (s[i]>='a'&& s[i]<='z') || (s[i]>='0'&& s[i]<='9') ){
                temp=temp+s[i];
            }
    }
    return temp;
}

bool checkPalindrome(string s)
{
    
    if(s.length()==1){
        return true;
    }
    else{
        int l=0;
        int e=s.length()-1;
        // transform(s.begin(),s.end(),s.begin(), ::tolower);
        // string clean=Clean(s);
        while(l<=e){
            if(s[l]!=s[e]){
                return false;
            }
            else{
                l++;
                e--;
            }
        }
        return true;
    }
}

void maxoccchar(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int number=0;
        if(ch>='a' && ch<='z' ){
            number=ch-'a';
        }
        if(ch>='A' && ch<='Z' ){
            number=ch-'A';
        }
        arr[number]++;
    }
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=0,max=-1;
    for(int i=0;i<26;i++){
        if(arr[i]>max){
            ans=i;
            max=arr[i];
        }
        // cout<<arr[i]<<" "; // 2 4 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

    }
    char c='a'+ans;
    cout<<c;
}

string string_replace(string s, int n){
    for(int i=0;i<n;i++){
        if(s[i]=='\0'){
            s[i]='@';
        }
    }
    return s;
}

bool check( int arr[26], int arr2[26] ){
    for(int i=0;i<26;i++){
        if(arr[i]!=arr2[i]){
            return false;
        }
        
    }
    return true;
}

int main(){ 


    // int arr[]={3,6,11,-8,2,90};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // for(int i=0;i<n-1;i++){
    //     int first=i;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[first]>arr[j]){
    //             swap(arr[first],arr[j]);
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    

    // reverse a string
    // string s="harsh";
    // cout<<strlen(s.c_str())<<endl;
    // cout<<"reverse string: "<<endl;
    // for(int i=s.length()-1;i>=0;i--){
    //     cout<<s[i];
    // }



    //check if a string is palindrome
    // string s="Harsj!* %j*srah";
    // transform(s.begin(),s.end(),s.begin(), ::tolower);
    // string clean=Clean(s);
    // if(checkPalindrome(clean)){
    //     cout<<"yes it's a palindrome";
    // }
    // else{
    //     cout<<"no it is not a palindrome";
    // }
    


    // Maximum Occuring Character
    // maxoccchar("DaabbaBBa");// lexicographically correct
    //or
    // string s="mmmxccccnnaaaa";
    // map<char,int> m;
    // // map<char,int>::iterator it;
    // //0r
    // int size=sizeof(s)/sizeof(s[0]);
    // // char prev;
    // // char lat;
    // // int cnt=0;
    // for(int i=0;i<s.length();i++){
    //     m[s[i]]++;
    //     // if(cnt<=m[s[i]]){
    //     //     if(s[i]>prev){
    //     //         lat=prev;
    //     //     }
    //     //     prev=s[i];
    //     //     cnt=m[s[i]];
    //     // }

    // }
    // for(auto it:m){
    //     cout<<it.first<<" "<<it.second;
    //     cout<<endl;
    // }
    // cout<<"occurences:"<<endl;
    // map<char,int>::iterator it=min_element(m.begin(),m.end(),[] (const pair<char,int> a,const pair<char,int> b)->bool{return a.second<b.second;} );
    // cout<<it->first<<" "<<it->second;


    // use of cin.getline
    // (1) string
    // int n;
    // string s;
    // getline(cin,s);
    // for(int i=0;i<s.length();i++){
    //     cout<<s[i];
    // }
    // (2) Character
    // char y_name[30];
    // cin.getline (y_name,30);
    // cout<<"my name is: "<<y_name;
    


    // int n;
    // string s;
    // getline(cin,s);
    // for(int i=0;i<s.length();i++){
    //     if(s[i]==' '){
    //         s.push_back('@');
    //         s.push_back('4');
    //         s.push_back('0');
    //     }
    //     else{
    //         s.push_back(s[i]);
    //     }
    // }
    // cout<<s;

    
    // #include <chrono>
    // using namespace std::chrono
    auto start = high_resolution_clock::now();
    //Your Programmme...


    // permutation in string
    string s2="baasasABHj";
    string s1="ab";
    
    int arr[26]={0};
        int number=0;
        for (int i = 0; i < s1.length(); i++)
        {
            if(s1[i]>='a' && s1[i]<='z' ){
                number=s1[i]-'a';
            }
            if(s1[i]>='A' && s1[i]<='Z' ){
                number=s1[i]-'A';
            }
            arr[number]++;
        }




        int i=0;
        int k=s1.length();
        int win[26]={0};
        while(i<k && i<s2.length()){
            int idx=s2[i]-'a';
            win[idx]++;
            i++;
        }

        
        
        if(check(arr,win)){
            return 1;
        }

        while(i<s2.length()){
            int id=s2[i]-'a';
            win[id]++;
            id=s2[i-k]-'a';
            
            win[id]--;
            i++;
            if(check(arr,win))
            return 1;
        }
        return 0;


        
    
    
    
    

    

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<endl;
    cout << "Time taken by function: "<< duration.count()<< " microseconds " << endl;
    

}


