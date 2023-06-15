#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
    //Bitwise operators
    // int a=3,b=4;
    // cout<<(a&b)<<endl;
    // cout<<(a|b)<<endl;
    // cout<<(~a)<<endl;
    // cout<<(a^b)<<endl;

    //left shift and right shift
    // int a=5;
    // cout<<(5<<1)<<endl;
    // cout<<(-5<<2)<<endl;
    // cout<<(5>>1)<<endl;
    // cout<<(5>>2)<<endl;

    //post increment
    // int a = 5;
    // int b=a++;
    // cout<<a<<" "<<b;

    //pre increment
    // int a = 5;
    // int b=++a;
    // cout<<a<<" "<<b;

    //post decrement
    // int a = 5;
    // int b=a--;
    // cout<<a<<" "<<b;

    //pre decrement
    // int a = 5;
    // int b=--a;
    // cout<<a<<" "<<b;
    // return 0;

    //programs

    //(1)
    // int a;
    // a=3;
    // if(0 || 1){
    //     cout<<"hi";
    // }
    // else{
    //     cout<<"hello";
    // }

    // cout<<(25*(a++));//75
    // cout<<(25*(++a));//100

    //(2)
    // fibonacci series {n=(n-1)+(n-2)}
    // int n;
    // cout<<"enter a number";
    // cin>>n;
    // int a=0;
    // int b=1;
    // for (int i=0;i<n;i++){
    //     int nxt=a+b;
    //     cout<<nxt<<endl;
    //     a=b;
    //     b=nxt;
        
    // }

    //(3)
    // int n;
    // cout<<"enter a no";
    // cin>>n;
    // for (int i=2;i<n;i++){
    //     if(n%i==0){
    //         //rem is zero
    //         cout<<"not a prime no for: "<<i;
    //         break;
    //     }
    //     else{
    //         //rem is not zero
    //         cout<<"prime no for: "<<i;
    //     }
    // }

    //(4)
    // for(int i=0;i<5;i++){
    //     for(int j=i;j<=5;j++){
    //         cout<<i<<" "<<j<<endl;
    //     }
    // }


    //variables and scope
    // int a=3;
    // if(true){
    //     cout<<a;
    // }

    // int n;
    // cin>>n;
    // cout<<i%10<<endl;
    // cout<<i/10;
    // int l=trunc(log10(n)) + 1;
    // int product=1;
    // int sum=0;
    // for (int i=0;i<l;i++){
    //     int rem=n%10;
    //     int quo=n/10;
    //     product=product*rem;
    //     sum=sum+rem;

    //     n=quo;
    // }
    //or
    // while(n!=0){
    //     int rem=n%10;
    //     product=product*rem;
    //     sum=sum+rem;
    //     n=n/10;
    // }
    // cout<<product-sum;
    // return 0;
    
    
    //191. Number of 1 Bits
    // uint32_t n;
    // cin>>n;
    // cout<<n;
    // int count=0;
    //     while(n!=0){
    //         if(n&1){
    //             count=count+1;
    //         }
    //         n=n>>1;
    //     }
    // cout<<count;

    // (5) getting ascii value
    // char c='f';
    // cout<<(int)c;//ascii value - 102
    
    // (6) typeid
    // char c;
    // cin>>c;
    // cout<<typeid(c).name();// c -> character
    
    // (7) string to integer using(stoi)
    // string c1;
    // cin>>c1;
    // cout<<typeid(c1).name()<<endl;// string
    // int c2=stoi(c1);
    // cout<<typeid(c2).name()<<endl;// n -> intger
    
    // (8) program 
    // char c1;
    // cout<<"select input: "<<endl;
    // cin>>c1;
    // // int c2=stoi(c1);
    // c1=int(c1);
    // if((c1>=97) && (c1<=122)){
    //     cout<<"lowercase"<<endl;
    // }
    // else if((c1>=65) && (c1<=90)){
    //     cout<<"uppercase"<<endl;
    // }
    // else if((c1>=48) && (c1<=57)){
    //     cout<<"numeric"<<endl;
    // }

    //(9) prime or not
    // int n,i=2;
    // cout<<"select a number"<<endl;
    // cin>>n;
    // if(n==1){
    //     cout<<"not a prime no";
    // }
    // else{
    //     while(i<n){
    //         if(n%i==0){
    //             cout<<"not prime for "<<i<<endl;
    //         }
    //         else{
    //             cout<<"prime for "<<i<<endl;
    //         }
    //         i=i+1;
    //     }
    // }
    
    //(10) int to string using to_string()
    // int i;
    // cout<<"enter an interger type data"<<endl;
    // cin>>i;
    // cout<<"int to string: "<<to_string(i);
    // string s=to_string(i);
    // cout<<endl;
    // cout<<"typeid: "<<typeid(s).name();

    //(11) Program
    // char a='A';
    // char b=a+1;
    // int x = int(a);
    // cout<<b;

    //(12) Program
    // int n;
    // cout<<"enter a no: "<<endl;
    // cin>>n;
    // int i=0;
    // int ans=0;
    // while(n!=0){
    //     int bit =n & 1;
    //     ans=(bit*pow(10,i))+ans;//imp
    //     n=n>>1;
    //     i++;

    // }
    // cout<<ans;


    //(13) Russian Peasant Multiplication
    // #include <iostream>
    // using namespace std;
    // int main() {
    //     // Write C++ code here
    //     int a=16,b=226,res=0;
    //     while(a>0){
    //         if(a%2!=0){
    //             res+=b;
    //         }
    //         a>>=1;
    //         b<<=1;
    //     }
    //     cout<<res;

    // }



    //(14) Array Initialization (Initialization of all elements of an array to one default value in C++)
    // int arr[6]={};
    // std::fill_n(arr, 6, -1);
    // for(int i=0;i<6;i++){
    //     cout<<arr[i];
    // }

    //or
    // array<int,6> a;
    // a.fill(-1);
    // for (int i = 0; i < 6; i++)
    // {
    //     cout<<a[i];
    // }
    return 0;
}