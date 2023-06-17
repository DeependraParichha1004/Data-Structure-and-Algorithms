#include <iostream>
#include <string>
#include <typeinfo>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// bool evenodd(int n){
//     if(n%2==0){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
bool evenodd(int n){
    if(n&1==1){
        return 0;
    }
    else{
        return 1;
    }
}

int arith_progr(int a, int n, int d){
    int an;
    an=a+(n-1)*d;//arithmetic progression formula
    return an;

}

int peak(int arr[],int n){
    int l=0,r=n-1;
    int mid = l + (r-l)/2;
    if(arr[mid]<arr[mid+1]){
        l=mid+1;
    }
    else{
        r=mid;
    }
    return r;
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    while(n!=1){
        return n*factorial(n-1);
    }
}

int isprime(int num){
    for (int i=2;i<num;i++){
        if(num%2==0){
            return 0;
        }
        else{
            return 1;
        }
    }
}

int totalnosetbits(int num){
    int count=0;
    while(num!=0){
        int bit =num&1;
        if(bit==1){
            count++;
        }
        num=num>>1;
    }
    return count;
}


void display(){
    cout<<"display fumction called";
    //return 1;//error
    return ;//no error
}

int fibonnaci(int n){
    int a=0,b=1;
    int sum;
    for (int i=1;i<n-1;i++){
        sum=a+b;
        a=b;
        b=sum;
    }
    return sum;

}

int max_min(int arr[], int n, int min_max)
{
    int max_ = INT_MIN;
    int min_ = INT_MAX;
    // if min_max==0 -> minimum value
    if (min_max == 0)
    {

        for (int i = 0; i < n; i++)
        {

            // or
            // max_=max(max_,arr[i])
            if (arr[i] < min_)
            {
                min_ = arr[i];
            }
        }
        return min_;
    }
    // if min_max==1 -> maximum valuw
    if (min_max == 1)
    {

        for (int i = 0; i < n; i++)
        {

            // or
            // min_=min(min_,arr[i])
            if (arr[i] > max_)
            {
                max_ = arr[i];
            }
        }
        return max_;
    }
}

void updatearr(int arr1[],int num){
    arr1[0]=8;
    cout<<"printing array during updation"<<endl;
    for(int i=0;i<num;i++){
        cout<<arr1[i]<<" ";
    }
}



int binary_search(int arr[], int l, int r, int key)
{
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

//leftmost occurrence of an element of an array
int first(int arr[], int l, int r, int n, int key)
{
    int mid = l + (r - l) / 2;
    int store = -1;
    while (l <= r)
    {

        if (arr[mid] == key)
        {
            store = mid;
            r = mid - 1;
        }
        else if (arr[mid] > key)
        {
            r = mid - 1;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
        mid = l + (r - l) / 2;
    }
    return store;
}

//rightmost occurence of an element of an array 
int last(int arr[], int l, int r, int n, int key)
{
    int mid = l + (r - l) / 2;
    int store = -1;
    while (l <= r)
    {

        if (arr[mid] == key)
        {
            store = mid;
            l = mid + 1;
        }
        else if (arr[mid] > key)
        {
            r = mid - 1;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
        mid = l + (r - l) / 2;
    }
    return store;
}

//no of occurrences of an element of an array
int occurrences(int arr[], int l, int r, int n, int key)
{
    int first_ = first(arr, l, r, n, key);
    int last_ = last(arr, l, r, n, key);

    return (last_ - first_) + 1;
}


void updatevar(int a)
{
    a = a + 1;
    cout << "during" << endl;
    cout << a;
}



void reverse(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
}

int swap(int arr[],int p1,int p2,int n){
    int temp;
    temp=arr[p1];
    arr[p1]=arr[p2];
    arr[p2]=temp;
    return 0;
}

//only one duplicate element
int duplicate(int arr[],int n){
    
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    cout<<"after xor ans is: "<<ans<<endl;
    for(int i=1;i<n;i++){
        ans=ans^i;
    }
    return ans;
}

int btod(int ans){//binary to decimal
    int res=0,inc=0;
    while(ans!=0){
        int i=ans%10;
        res=i*pow(2,inc)+res;
        ans=ans/10;
        inc++;
        
    }
    return res;
}

int reversearray(int arr[], int l, int r)
{
    int point1 = l; //start
    int point2 = r - 1; //end
    while (point1 <= point2)
    {
        // swap(arr[point1],arr[point2]);

        //or
        swap(arr,point1,point2,r-1);
        point1++;
        point2--;
    }


    for(int i=0;i<r;i++){
        cout<<arr[i]<<" ";
    }
}


int adjswap(int arr[],int n){

    for(int i=0;i<n;i+=2){
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}


int frequency(int arr[], int n)
{
    
    
    vector<bool> visited(n, false);
    
    int unique=0;
    bool flag=false;
    for (int i = 0; i < n; i++)
    {
        


        if (visited[i] == true)
        {
            continue;
        }
        

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j] = true;
                count++;
            }
        }

        
        if(unique!=count){
            unique=count;
            flag=true;
        }
        else{
            flag=false;
        }
    
        
    }
    return flag;


}

// incomplete
int find_unique(int arr[], int n)
{
    int count = 0;
    int ele = arr[0];
    int dup;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            count++;
            dup = arr[i];
        }
        else if (arr[i] != ele)
        {
            ele = arr[i];
        }
    }
    if (count > 1)
    {
        cout << "the duplicate eement is: " << dup << ", and count is: " << count;
        ;
    }

    return 0;
}

vector<vector<int>> pairsum(int arr[],int n,int sum){
    vector<vector<int>> ans;
    
    for (int i=0;i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]+arr[j]==sum){
                vector<int> temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                ans.push_back(temp);
            }
        }
        
    }
    sort(ans.begin(),ans.end());
    return ans;
}

vector<vector<int>> triplets_sum_0(int arr[],int n,int sum){
    vector<vector<int>> ans;
    
    for (int i=0;i < n; i++)
    {

        int j=i+1;
        int k=j+1;
        while(j<n && k<n){
            if(arr[i]+arr[j]+arr[k]==sum){
                vector<int> temp;
                // ans.insert(ans.end(),{arr[i],arr[j],arr[k]});
                // ans.push_back(temp);
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[k]);
                ans.push_back(temp);
                j++;
                k++;
            }
        }
        
    }
    // sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    //(1) Decimal to binary using & operator
    // in this we'll get answer in reverse order
    // for ex - we'll get 0010011 instead of 1100100
    // int n;
    // cout<<"enter a no: "<<endl;
    // cin>>n;
    // while(n!=0){
    //     int bit=(n&1);
    //     n=n>>1;
    //     cout<<bit;4
    // }


    // Decimal to binary using formula
    // ex - n=64 -> ans=1000000
    //  int n;
    //  cout<<"enter a no: "<<endl;
    //  cin>>n;
    //  int i=0,ans=0;
    //  while(n!=0){
    //      int bit =(n & 1);
    //      ans=(bit*pow(10,i))+ans;//imp
    //      n=n>>1;
    //      i=i+1;
    //  }
    //  cout<<ans;


    // binary to decimal conversion - ex n=100010 -> ans=34
    //  int n;
    //  cout<<"enter a no: "<<endl;
    //  cin>>n;
    //  int i=0,ans=0;
    //  while(n!=0){
    //      int digit =(n % 10);
    //      if(digit==1){
    //          ans=ans+pow(2,i);
    //      }
    //      n=n/10;
    //      i=i+1;
    //  }


    //(2) convert -6 to binary(incomplete)
    // cout<<ans;
    // int n=6;
    // int no=0,i=0;
    // //ones compliment
    // // n=-n;
    // while(n!=0){
    //     int bit = n&1;
    //     no=(bit*pow(10,i))+no;
    //     n=n>>1;
    //     i=i+1;
    // }
    // cout<<no;

    // two's compliment



    //(3) prob no 9 - reverse the integer
    // int n=123;
    // int n=1947483649;
    // int ans = 0;
    // while (n != 0)
    // {
    //     int digit = n % 10;
    //     if ((ans > (INT32_MAX / 10)) || ((ans < INT32_MIN / 10)))
    //     {
    //         cout << 0;
    //     };   
    //     ans = (ans * 10) + digit;
    //     n = n / 10;  
    // }
    // cout << ans;


    //1009. Complement of Base 10 Integer
    int mask=0;
    int n=17;
    int m=n;
    int ans;
    if (n==0){
        return 1;
    }
    while(m!=0){
        mask=(mask<<1)|1;
        m=m>>1;
    }
    ans=(~n)&mask;
    cout<<ans;

    //or
    // int x=17;
    // int i=0;
    // int ans=0;
    // int bin=0;
    // while(x!=0){
    //     int digit=x&1;
    //     int comp=digit^1;
    //     ans=comp*pow(10,i)+ans;
    //     bin=digit*pow(10,i)+bin;
    //     i++;
    //     x=x>>1;
    // }
    // cout<<"decimal to binary of x is: "<<bin<<endl;
    // cout<<"1's complement of x is: "<<ans<<endl;
    // cout<<"complement of base 10 integer is: "<<btod(ans);
    // return 0;


    //231. Power of Two
    // int n;
    // cout<<"enter a no: "<<endl;
    // cin>>n;
    // int ans=0;
    // int count=0;
    // while(n!=0){
        
    //     int bit = n&1;
    //     if(bit==1){
    //         count=count+1;
    //     }
    //     n=n>>1;
    // }
    // if(count==1){
    //     cout<<"Power of two";
    // }
    // else{
    //     cout<<"not a power of two";
    // }

    // or
    // int n;
    // cout<<"enter a no";
    // cin>>n;
    // for (int i=0;i<31;i++){
    //     int ans=pow(2,i);
    //     if(ans==n){
    //         cout<<"power of two";
    //     }
        
        
    // }
    // cout<<"not a power of two";

    // or
    // int ans=1;
    //     for (int i=0;i<=30;i++){
            
    //         if(ans==n){
    //             return 1;
    //         }
    //         if(ans<INT32_MAX/2 && ans>INT32_MIN/2){
    //             ans=ans*2;
    //         }
    //     }

    //switch case (homework)



    //(4) calculator
    // int a,b;
    // char s;
    // cout<<"enter two numbers and an operator"<<endl;
    // cin>>a>>b>>s;
    // switch(s){
    //     case '+':cout<<"a + b is "<<(a+b);
    //              break;
    //     case '/':cout<<"a / b is "<<(a/b);
    //              break;

    //     case '*':cout<<"a * b is "<<(a*b);
    //              break;
    //     case '%':cout<<"a % b is "<<(a%b);
    //              break;
    //     case '-':cout<<"a - b is "<<(a-b);
    //              break;
    // }

    //(5) function even odd
    // int x;
    // cout<<"enter a no: "<<endl;
    // cin>>x;
    // bool ans=evenodd(x);
    // cout<<ans;

    //(6) factorial 
    // int a=factorial(18);
    // cout<<a<<endl;
    
    //(7) nCr
    // int n,r;
    // cout<<"enter n: "<<endl;
    // cin>>n;
    // cout<<"enter r: "<<endl;
    // cin>>r;
    // int nCr=factorial(n)/( factorial(r)*factorial(n-r) );
    // cout<<"nCr is: "<<nCr;
    // return 0;


    //(8) isprime
    // int n;
    // cout<<"enter a number"<<endl;
    // cin>>n;
    // int ans=isprime(n);
    // if(ans){
    //     cout<<"prime no";
    // }
    // else{
    //     cout<<"not a prime no";
    // }


    // display();

    //(9) total no of set(1) bits
    // int a,b;
    // cout<<"enter two numbers: "<<endl;
    // cin>>a>>b;
    // int total=totalnosetbits(a)+totalnosetbits(b);
    // cout<<"total no of set bits: "<<total;
    
    

    //(10) initialising all the values of an array with single element
    //  int val=1;
    // int num[n];
    // fill_n(num, n, val);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << num[i] << " ";
    // }
    // cout<< endl;


    //(11) min max  value from an array
    // int n = 9;
    // int arr1[n] = {5, 0, -1, -7, -109, 890, 657, 52624, -9999};
    // int ans = max_min(arr1, n, 0);
    // cout << ans;
 
    
    //(12) passing function(uodation)
    // int arr[5];
    // cout<<"printing array before updation"<<endl;
    // for (int i=0;i<5;i++){
    //     cin>>arr[i];
    // }
    
    // arr[0]=-99;
    // updatearr(arr,5);

    // cout<<"printing array after updation"<<endl;
    // for (int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }

    //(13) Binary Search
    // int arr[9] = {1, 4, 5, 7, 8, 12, 35, 45, 60};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int ans=binarysearch(arr,0,n-1,9);
    // if(ans){
    //     cout<<"yes";
    // }
    // else{
    //     cout<<"no";
    // }
    // cout<<ans;


    //(14) reverse of an array
    // int arr[4]={1,2,3,4};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // reverse(arr,n);

    //or
    // int arr[7] = {1, 3, 4, 5, 6, 7, 9};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // reversearray(arr, 0, n);
    

    //adjacent swapping in an array
    // int arr[6]={1,3,5,8,9,10};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // adjswap(arr,n);


    //find unique
    // int arr[5]={3,1,4,1,3};
    // int ans=0;
    // for (int i = 0; i < 5; i++)
    // {
    //     ans=ans^arr[i];
    // }
    // cout<<ans;


    //unique no of occurrences (better solution leetcode)
    // int arr[] = {-3,0,1,-3,1,1,1,-3,10,0};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int ans=frequency(arr, n);

    // if(ans){
    //     cout<<"unique no of occurences";
    // }
    // else{
    //     cout<<"not a unique no of occurences";
    // }
    


    //duplicate in array
    // int arr[]={2,3,3,4,1,0};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int ans=duplicate(arr,n);
    // cout<<ans;


    // int arr[8]={3,7,7,8,8,8,5,1};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // find_unique(arr,n);



    //intersection of two arrays
    // int arr1[]={1,2,3,4};
    // int arr2[]={3,4};
    // vector<int> ans;
    // int n=sizeof(arr1)/sizeof(arr1[0]);
    // int m=sizeof(arr2)/sizeof(arr2[0]);
    // for (int i = 0; i < n; i++)
    // {
    //     int elem=arr1[i];
    
    //     for (int j = 0; j < m; j++)
    //     {   
    //         if(elem< arr2[j]){
    //             break;
    //         }
    //         if(elem==arr2[j]){
    //             ans.push_back(elem);
    //             arr2[j]=-1;
    //             break;
    //         }
    //     }
    // }
    // cout<<ans;

    //or
    // int arr1[]={1,2,3,4};
    // int arr2[]={3,4};
    // vector<int> ans;
    // int n=sizeof(arr1)/sizeof(arr1[0]);
    // int m=sizeof(arr2)/sizeof(arr2[0]);
    // int i=0,j=0;
    // while(i<n && j<m){
    //     if(arr1[i]==arr2[j]){
    //         ssa
    //     }
    //     else if(arr1[i<arr2[j]]){
    //         i++;
    //     }
    //     else{

    //     }
    // }



    //pair sum
    // int arr[] = {2,-3,3,3,-2};
    // int sum = 0;
    // int n = sizeof(arr) / sizeof(arr[0]);
    // vector<vector<int>> a=pairsum(arr,n,sum);
    // for (int i = 0; i < 3; i++) {
    //     for (
    //         auto it = a[i].begin();
    //         it != a[i].end(); it++)
    //         cout << *it << " ";
    //     cout << endl;
    // }



    // Find All Triplets With Zero Sum
    //incomplete
    // int arr[] = {-10, 5, 5, -5, 2};
    // int sum = 0;
    // int n = sizeof(arr) / sizeof(arr[0]);
    // vector<vector<int>> a=triplets_sum_0(arr,n,sum);
    // vector<vector<int>>::iterator it;
    // // for(auto it=a.begin();it!=a.end();it++){
    // //     cout<<*it;
    // // }
    // for (int i = 0; i < a.size(); i++) {
    //     for (
    //         auto it = a[i].begin();
    //         it != a[i].end(); it++)
    //         cout << *it << " ";
    //     cout << endl;
    // }
    



    //two pointers approach
    // int arr[]={3,2,-3,5,-5};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int sum=0;
    // int i=0,j=n-1;
    // sort(arr,arr+5);
    // while(i<j){    
    //     if(arr[i]+arr[j]>sum){
    //         j--;
    //     }
    //     else if(arr[i]+arr[j]<sum){
    //         i++;
    //     }
    //     else if(arr[i]+arr[j]==sum){
    //         cout<<arr[i]<<" "<<arr[j]<<endl;
    //         i++;
    //         j--;
    //     }  
    // } 


    // first and last 
    // int arr[] = {24,69,100,99,79,78,67,36,26,19};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int key = 5;
    // int first_=first(arr, 0, n - 1, n, key);
    // int last_=last(arr, 0, n - 1, n, key);


    //peak element of an array
    // int arr[]={0,5,10,1,0};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // cout<<"peak element index of an array "<<peak(arr,n)<<endl;
    // cout<<"peak element of an array "<<arr[peak(arr,n)];
    // return 0;
    
    return 0;
}