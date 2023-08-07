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
class Stack{
    private:
    int top,size;
    int* arr;

    public:
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    //push
    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow";
        }
    }

    //pop
    void pop(){
        if(top==-1){
            cout<<"stack underflow";
        }
        else{
            top--;
        }
    }

    //top
    void peak(){
        if(top==-1){
            cout<<"no element s present in stack";
        }
        else{
            cout<<arr[top];
        }
        
    }

    //isempty
    void isempty(){
        if(top==-1){
            cout<<"empty";
        }
        else{
            cout<<"not empty";
        }
    }
};

//redundant bracket
bool redundant(string &s){
    stack<char> c;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+' || s[i]=='*' || s[i]=='-' || s[i]=='/' || s[i]=='(' ){
            c.push(s[i]);
        }
        else{
            if(s[i]==')'){
                bool isredundant=true;
                while(c.top()!='('){
                    if(c.top()=='+' || c.top()=='*' || c.top()=='-' || c.top()=='/'){
                        isredundant=false;
                    }
                    c.pop();
                }
                if(isredundant){
                    return true;
                }
                c.pop();

            }
            
        }
    }
    return false;
    
}
void increasingStack(int arr[],int N){
    stack<int> st;

    for(int i=0;i<N;i++){
        while(!st.empty() &&  arr[i]<st.top()){
            st.pop();
        }
        st.push(arr[i]);
    }

    int n=st.size();
    int ans[n];
    int j=n-1;
    while(!st.empty()){
        ans[j]=st.top();
        st.pop();
        j--;
    }

    cout<<"Array after call ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

}
void decreasingStack(int arr[],int N){
    stack<int> st;

    for(int i=0;i<N;i++){
        while(!st.empty() &&  arr[i]>st.top()){
            st.pop();
        }
        st.push(arr[i]);
    }

    int n=st.size();
    int ans[n];
    int j=n-1;
    while(!st.empty()){
        ans[j]=st.top();
        st.pop();
        j--;
    }

    cout<<"Array after call ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

}
//monotonic increasing stack 
vector<int> nextGreaterElement(const vector<int>& nums) {
	stack<int> stack;
	vector<int> result(nums.size(), -1);

	for (int i = 0; i < nums.size(); i++) {
		while (!stack.empty() && nums[i] > nums[stack.top()]) {
			int index = stack.top();
			stack.pop();
			result[index] = nums[i];
		}
		stack.push(i);
	}

	return result;
}

vector<int> prevSmallerElement(const vector<int>& nums) {
	stack<int> stack;
	vector<int> result(nums.size(), -1);
    int n=nums.size();
	for (int i = n-1; i >=0; i--) {
		while (!stack.empty() && nums[i] <nums[stack.top()]) {
			int index = stack.top();
			stack.pop();
			result[index] = nums[i];
		}
		stack.push(i);
	}

	return result;
}

//max rectange gfg question 
void create_vector(vector<vector<int>> mat){
    int n=mat.size();
    for(int i=0;i<1;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=0){
                mat[i][j]=mat[i][j]+mat[i-1][j];
                cout<<mat[i][j]<<" ";
            }
            
        }
        cout<<endl;
        
    }
}
int main(){
    // Stack obj1(5);
    // obj1.push(2);
    // obj1.push(21);
    // obj1.push(22);
    // obj1.pop();
    // obj1.peak();

    //reverse a string
    // string s="Deependra";
    // stack<char> st;
    // for(int i =0;i<s.size();i++){
    //     st.push(s[i]);
    // }
    // for(int i =0;i<s.size();i++){
    //     cout<<st.top();
    //     st.pop();
    // }

    //delete middle element in a stack
    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);

    
    // for (int i=0;i<s.size();i++){
    //     cout<<s.top();
    //     s.pop();
    // }


    // redundant bracket
    // string s="a+((b*c))";
    // if(redundant(s)){
    //     cout<<"redundant";
    // }
    // else{
    //     cout<<"non redundant";
    // }

    //monotonic increasing stack -> notes copy
    // int arr[] = { 1, 4, 5, 3, 12, 10 };
    // int N = sizeof(arr) / sizeof(arr[0]);
    
    // cout<<"Array before call ";
    // for(int i=0;i<N;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // // Function Call
    // increasingStack(arr, N);


    //monotonic decreasing stack -> notes copy
    // int arr[] = { 15 ,17 ,12 ,13 ,14 ,10 };
    // int N = sizeof(arr) / sizeof(arr[0]);
    
    // cout<<"Array before call ";
    // for(int i=0;i<N;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // // Function Call
    // decreasingStack(arr, N);


    //next greatest element
    // vector<int> nums = {4, 5, 2, 25, 7, 18};
    // vector<int> result = nextGreaterElement(nums);

    // for (int num : result) {
	// 	cout << num << " ";
	// }

    //prev smallest
    // vector<int> nums = {2,5,3,7,8,1,9};
    // vector<int> result = prevSmallerElement(nums);

    // for (int num : result) {
	// 	cout << num << " ";
	// }

    
    // vector<vector<int>> mat={{0, 1 ,1, 0},
    //                         {1, 1 ,1 ,1},
    //                         {1, 1 ,1 ,1},
    //                         {1, 1, 0 ,0}};
    // create_vector(mat);

    return 0;
    

}
