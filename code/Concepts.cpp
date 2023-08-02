#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
bool ispossible(vector<int>& arr,int n,int mid,int m){
    int count=1;
    int sum=0;
    for(int i=0;i<n;i++){
        
        if(sum+arr[i]<=mid){
            
            sum+=arr[i];
        }
        else{
            count++;
            if(count>m || arr[i]>mid ){
                return false;
            }
            sum=arr[i];
        }
    }
    
    return true;
    
    
}

int findPages(vector<int>& arr, int n, int m) {
    
    
    int sum=0;
    sum=accumulate(arr.begin(),arr.end(),sum);

    int l=0,h=sum,ans=-1;
    int mid=l+(h-l)/2;
    if(m<=n){
    while(l<=h){
        
        if(ispossible(arr,n,mid,m)){
            ans=mid;
            h=mid-1;
            
        }
        else{
            l=mid+1;
        }
        mid=l+(h-l)/2;
    }
    return ans;
    }
    else{
        return -1;
    }
}

int getMinDiff(int arr[], int n, int k) {
    sort(arr,arr+n);
    int ans=arr[n-1]-arr[0];
    
    int largest=arr[n-1]-k;
    int smallest=arr[0]+k;
    int mini,maxi;
    
    for(int i=0;i<n-1;i++){
        mini=min(smallest,arr[i+1]-k);
        maxi=max(largest,arr[i]+k);
        if(mini<0){
            continue;
        }
        ans=min(ans,maxi-mini);
    }
    return ans;
}

int factorial(int n,int r){
    if(r>n){
        return 0;
    }
    if((n-r)<r){
        r=n-r;
    }
    int dp[r+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=min(r,i);j>0;j--){
            dp[j]=dp[j]+dp[j-1];
        }

        
    }
    cout<<"answer is: "<<endl;
    cout<<dp[r];

}

void heights(vector<int> arr,int k){
    sort(arr.begin(),arr.end());//(n*logn)
    int mini,maxi;
    int ans=arr[arr.size()-1]-arr[0];
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]-k<0){
            continue;
        }

        mini=min(arr[i]-k,arr[0]+k);
        maxi=max(arr[i-1]+k,arr[arr.size()-1]-k);
        ans=min(ans,maxi-mini);
    }

    cout<<ans;
}

//subarrays
void subarrays(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout<<arr[k];
            }
            cout<<endl;
        }
    }
}

template<typename T>
T maxi(T a,T b){
    return (a>b)?a:b;
}

int queue_maxSum(int arr[],int n,int k){
    queue<int> q;
    if(n<k){
        cout<<"invalid";
        return -1;
    }

    int res=0,maxi=INT_MIN;
    for(int i=0;i<k;i++){
        q.push(arr[i]);
        res+=arr[i];
    }

    for(int i=k;i<n;i++){
        res-=q.front();
        q.pop();
        q.push(arr[i]);
        res+=arr[i];

        maxi=max(res,maxi);


    }
    return maxi;

}

int window_maxSum(int arr[],int n,int k){
    if(n<k){
        cout<<"invalid";
        return -1;
    }

    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }

    int curr_sum=sum;
    for(int i=k;i<n;i++){
        curr_sum+=arr[i]-arr[i-k];
        sum=max(curr_sum,sum);
    }
    return sum;
}
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


    //(13) Russian Peasant Multiplication -> O(log2b) -> with base 2
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

    //(15) search space in sorted array
    // vector<int> arr = {12,34,67,90 };
    // int n=4,m=2;
    // cout<<findPages(arr, n, m);

    //(16) Minimize the maximum difference between the heights
    // int arr[] = {1, 5, 15, 10}, k = 3;
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout<<getMinDiff(arr,n,k);

    //(15) nCr using pascals concept
    // int n,r;
    // cout<<"enter n and r respectively: "<<endl;
    // cin>>n>>r;
    
    // factorial(n,r);

    //Minimize the maximum difference between the heights -> O(N * log(N))
    // vector<int> arr{1, 5, 15, 10};
    // // vector<int> arr{7, 4, 8, 8, 8, 9};
    // int k=3;
    // heights(arr,k);

    //subarrays
    // int arr[]={1,2,3,4};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // subarrays(arr,n);
    // return 0;

    //template in c++
    // cout<<maxi<int>(2,3)<<endl;
    // cout<<maxi<char>('s','f');

    //Find maximum (or minimum) sum of a subarray of size k
    //(1) brute force -> generate subarrays, add then and compare -> O(N*N)
    //(2) using queue -> O(N) s.c ->O(k)
    
    // int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    // int k = 4;
    // int n = sizeof(arr) / sizeof(arr[0]);
    // cout << queue_maxSum(arr, n, k);

    //(3) window concept O(N) s.c -> O(1)
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << window_maxSum(arr, n, k);
    return 0;

}