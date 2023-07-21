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

void sort012(int arr[], int n)
{
    // int arr[]={2,0,1,0,0,0,1,1,0,2,2};
    // int n=sizeof(arr)/sizeof(arr[0]);
    int i=0,j=0,k=n-1,l=n-1;
    for(j=0;j<n;j++){
        if(arr[j]==0){
            swap(arr[i],arr[j]);
            i++;
        }

    }

    for(k=n-1;k>=0;k--){
        if(arr[k]==2){
            swap(arr[k],arr[l]);
            l--;
        }

    }
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

string string_replace(string str, int n){


    // space complexity -> O(n)
    // string ans="";
    // for(int i=0;i<str.length();i++){
    //     if(str[i]==' '){
	// 		ans.push_back('@');
	// 		ans.push_back('4');
	// 		ans.push_back('0');
    //     } else {
    //       ans.push_back(str[i]);
    //     }
    // }
    // return ans;

    // or
    //// space complexity -> O(1)
    for(int i=0;i<str.length();i++){
        if(str[i]==' '){
            str.replace(i,1,"@40");
        }
    }
    return str;
}

bool check( int arr[26], int arr2[26] ){
    for(int i=0;i<26;i++){
        if(arr[i]!=arr2[i]){
            return false;
        }
        
    }
    return true;
}

bool permutation(string s1,string s2){
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
}

//aggressive cows
bool ispossible_ac(vector<int> &arr,int mid, int k){
    int cows=1;
    int lastpos=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]-lastpos>=mid){
            cows++;
            if(k==cows){
                return true;
            }
            lastpos=arr[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    
    int maxi=-1;
    for(int i=0;i<stalls.size();i++){
        maxi=max(maxi,stalls[i]);
    }

    int l=0,h=maxi,ans=-1;
    int mid=l+(h-l)/2;
    
    while(l<=h){
        
        if(ispossible_ac(stalls,mid,k)){
            ans=mid;
            l=mid+1;
            
        }
        else{
            h=mid-1;
        }
        mid=l+(h-l)/2;
    }
    return ans;
    
    
}

//book allocation
bool ispossible_b(int arr[],int n,int mid,int m){
    int count=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>mid){
            count++;
            sum=arr[i];
        }
    }
    
    if(count>m){
        return 0;
    }
    else{
        return 1;
    }
    
    
    
}


int allocation(int arr[],int n,int m){
    int sum=0;
    sum=accumulate(arr,arr+n,sum);

    int l=0,h=sum,ans=0;
    int mid=l+(h-l)/2;
    while(l<=h){
        cout<<"mid"<<mid<<endl;
        if(ispossible_b(arr,n,mid,m)){
            h=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
        mid=l+(h-l)/2;
    }
    return ans;
}


int pair_2d(vector<vector<int>> mat,int N){
    // vector<vector<int>> mat {{ 1, 2, -1, -4, -20 },
    //                 { -8, -3, 4, 2, 1 }, 
    //                 { 3, 8, 6, 1, 3 },
    //                 { -4, -1, 1, 7, -6 },
    //                 { 0, -4, 10, -5, 1 }};
    // int N=5;
    int maxV=-1;
    int maxArr[N][N];
    maxArr[N-1][N-1] = mat[N-1][N-1];
    
    //preprocess last row
    int maxValue=mat[N-1][N-1];
    for(int i=N-1;i>=0;i--){
        if(mat[N-1][i]>maxValue){
            maxValue=mat[N-1][i];
        }
        maxArr[N-1][i]=maxValue;
    }

    //prprocess last column
    maxValue=mat[N-1][N-1];
    for(int i=N-1;i>=0;i--){
        if(mat[i][N-1]>maxValue){
            maxValue=mat[i][N-1];
        }
        maxArr[i][N-1]=maxValue;
    }

    for(int i=N-2;i>=0;i--){
        for(int j=N-2;j>=0;j--){
        
            maxArr[i][j]=max({maxArr[i][j+1],maxArr[i+1][j],maxArr[i+1][j+1]});
        }
    }

    for(int i=N-2;i>=0;i--){
        for(int j=N-2;j>=0;j--){
            if(maxArr[i+1][j+1]-mat[i][j]>maxV){
                maxV=maxArr[i+1][j+1]-mat[i][j];
            }
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout<<maxArr[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    
    return maxV;
}
void reference(int& x){
    x++;
}

void fun(int arr[]){
    cout<<arr[0];
}
void swap(char *x,char *y){
    char *t=x;
    x=y;
    y=t;
}

void jagged_static(){
    // create 3 row arrays having different sizes
    // ( no ofcolumns)
    int row1[] = { 1, 2, 3, 4 };
    int row2[] = { 5, 6 };
    int row3[] = { 7, 8, 9 };
  
    // storing base address of each row array
    int* jagged[] = { row1, row2, row3 };
  
    int sizes[] = { 4, 2, 3 };

    for(int i=0;i<3;i++){
        int* ptr=jagged[i];
        for(int j=0;j<sizes[i];j++){
            cout<<*(ptr+j)<<" ";
        }
        cout<<endl;
    }
}

void jagged_dynamic(){
    int row=3,col;
    int** arr=new int*[row];

    int sizes[]={4,2,3};

    for(int i=0;i<row;i++){
        arr[i]=new int[sizes[i]];
    }


    // input from user
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    cout << "elements in matrix form as follow" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}
int main(){ 
    auto start = high_resolution_clock::now();

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

    //Note
    //(1)
    // char ch[20]="Deependra Parichha";
    // cout<<ch;//Deependra Parichha

    //(2)
    // char ch[20];
    // cin>>ch;//Deependra Parichha
    // cout<<ch;//Deependra 
    //         //because cin terminates the execution after seeing tab, space or enter
    

    //aggressive cows
    // int k=4;
    // vector<int> arr={0, 3, 4, 7, 10, 9};
    // cout<<aggressiveCows(arr, k);
    

    //find a specific pair with maximum difference
    // vector<vector<int>> mat {{ 1, 2, -1, -4, -20 },
    //                 { -8, -3, 4, 2, 1 }, 
    //                 { 3, 8, 6, 1, 3 },
    //                 { -4, -1, 1, 7, -6 },
    //                 { 0, -4, 10, -5, 1 }};
    // cout<<pair_2d(mat,5);

    //pointers

    //arrays
    // int arr[]={2,3,6};
    // int n = sizeof(arr)/sizeof(arr[0]);\
    // int x=5;
    // int *ptr=&arr[0];
    // cout<<"address of the first element: "<<arr<<", second element: "<<arr+1<<endl;//or cout<<&arr; cout<<&arr[0];
    // cout<<"value of element at index 1 : "<<*(arr+1)<<endl;
    // cout<<"same value: "<<arr[2]<<" "<<2[arr]<<" "<<" "<<*(arr+2)<<endl;
    // cout<<"size of array: "<<sizeof(arr)<<" size of pointer: "<<sizeof(ptr)<<endl;;
    // cout<<sizeof(&arr)<<endl;//ans 4 
    // cout<<sizeof(*arr)<<endl;//ans 4 
    // cout<<&arr;


    //chars
    //different cout implementation
    // char ch[4]="abc";
    // char h='s';
    // char *c=&ch[0];//output c -> abc
    // char *p=&h;
    // cout<<ch<<endl;//ans is abcd and not address
    // cout<<&ch[0]<<endl;//abcd
    // cout<<c<<endl;//abcd
    // cout<<p<<endl;

    // char ch[6]="abcde";//okay
    // char *c="abcde";//bad practice and risky too
    // cout<<c[0];

    //functions
    // (1) pointer remains same after updation
    // (2) value gets changed after updation

    
    // Dangling pointer
    //Deallocated pointer
    // int *ptr=(int *)malloc(sizeof(int));
    // free(ptr);
    // cout<<ptr;

    //Null Pointer
    // int *ptr=NULL;
    // cout<<ptr;

    //Wild Pointer
    // int *ptr;
    // cout<<ptr;

    //segmentation fault - >
    //A segmentation fault usually occurs when you try to 
    //access data via pointers for which no memory has been allocated. 
    // int a=7;
    // int* ptr=0;
    // *ptr=9;//rather ptr=&a;
    // cout<<ptr;

    
    // Double Pointers
    // int a=8;
    // int* ptr=&a;
    // cout<<"a address: "<<&a<<endl;
    // cout<<"ptr: "<<ptr<<endl;
    // cout<<"ptr: "<<&ptr<<endl;
    // cout<<"ptr: "<<*ptr<<endl;
    // int **ptr2=&ptr;
    // int **ptr3=ptr2;//8
    // cout<<"ptr2: "<<ptr2;
    // cout<<"ptr2: "<<&ptr2;
    // cout<<"ptr2: "<<*ptr2;

    // cout<<"ptr2: "<<**ptr2;


    //questions
    // (1)
    // int arr[]={8,4,6};
    // int* ptr=arr;
    // cout<<ptr[1];

    // {2}
    // int arr[]={8,4,6};
    // int* ptr=arr++;//error because we're manipulating the symbol table 

    // (3)
    // char ch[]="anbc";
    // char* ptr=ch;
    // cout<<ptr[0];

    //(4)
    // int f=100;
    // int *p=&f;
    // int **q=&p;
    // int second=(**q)++;
    // int *r=*q;
    // (*r)++;
    // cout<<f<<" "<<second;

    //(5)
    // char *ptr;
    // char str[]="abcdefg";
    // ptr=str;
    // cout<<ptr;//abcdefg
    // ptr+=5;
    // cout<<ptr;//fg 

    //(6)
    // float arr[]={12.5,14.2,13.5};
    // float *ptr1=&arr[0];
    // float *ptr2=ptr1+3;
    // cout<<*ptr1<<" ";
    // cout<<*ptr2<<" ";
    // cout<<ptr2-ptr1;//3 -> ptr2=ptr+3,ptr1=ptr1,ptr2-ptr1=3

    //(7)
    // int arr[]={1,2,3,4};
    // fun(arr+1);//2
    // cout<<*(arr);//1
    

    //(8)
    // char *x="ninja";
    // char *y="cod";
    // swap(x,y);
    // cout<<x<<" "<<y;

    //Reference variable ->  Reference variable is an alternate name of already existing variable.
    //why? -> Use pass-by-reference if you want to modify the argument value in 
    //the calling function
    // int i=5;
    // int& j=i;
    // cout<<&j;//0x61fee4
    // cout<<&i;//0x61fee4
    // i++;
    // cout<<i;//i=6,j=6

    //in function pass by reference
    // int n=5;
    // cout<<"before: "<<n<<endl;
    // reference(n);
    // cout<<"after: "<<n<<endl;

    //variable size array creation(dynamic memory allocation)
    // int n;
    // cin>>n;
    // int* ptr=new int[n]; 
    // cout<<ptr;

    //Kadanes's Algorithm
    // int max_here=0,max_so_far=INT_MIN;
    // int arr[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int i=0;
    // while(i<n){
    //     max_here=max_here+arr[i];
    //     if(max_here>max_so_far){
    //         max_so_far=max_here;
    //     }
    //     if(max_here<0){
    //         max_here=0;
    //     }
    //     i++;
        
    // }
    // cout<<max_so_far;


    //1d array pointers
    // int* arr=new int[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     arr[i]=i;//or *(arr+i)=i;
    // }
    // cout<<endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    

    //2d array pointers
    //Jaggered array
    // int c=0;
    // //m=5,n=4
    // int** arr=new int*[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     for(int j=0;j<i+1;j++){
    //         arr[i]=new int[j];
    //     }
        
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j=0;j<i+1;j++)
    //     {
    //         arr[i][j]=++c;
    //     }
    // }
    // // Traverse the 2D array
    // for (int i = 0; i < 5; i++) {
    //     for (int j=0;j<i+1;j++) {
 
    //         // Print the values of
    //         // memory blocks created
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    
    // }
    // //freeing up memory
    // for(int i=0;i<5;i++){
    //     delete [] arr[i];
    // }
    // delete []arr;


    //A common method to rotate the image
    /*
    * clockwise rotate
    * first reverse up to down, then swap the symmetry 
    * 1 2 3     7 8 9     7 4 1
    * 4 5 6  => 4 5 6  => 8 5 2
    * 7 8 9     1 2 3     9 6 3
    */
    // void rotate(vector<vector<int> > &matrix) {
    //     reverse(matrix.begin(), matrix.end());
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = i + 1; j < matrix[i].size(); ++j)
    //             swap(matrix[i][j], matrix[j][i]);
    //     }
    // }

    /*
    * anticlockwise rotate
    * first reverse left to right, then swap the symmetry
    * 1 2 3     3 2 1     3 6 9
    * 4 5 6  => 6 5 4  => 2 5 8
    * 7 8 9     9 8 7     1 4 7
    */
    // void anti_rotate(vector<vector<int> > &matrix) {
    //     for (auto vi : matrix) reverse(vi.begin(), vi.end());
    //     for (int i = 0; i < matrix.size(); ++i) {
    //         for (int j = i + 1; j < matrix[i].size(); ++j)
    //             swap(matrix[i][j], matrix[j][i]);
    //     }
    // }


    //jagged array
    //(1) Using static array of pointers
    // jagged_static();
    //(2) Using Dynamic 2D arrays
    jagged_dynamic();
    

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<endl;
    cout << "Time taken by function: "<< duration.count()<< " microseconds " << endl;
    

}


