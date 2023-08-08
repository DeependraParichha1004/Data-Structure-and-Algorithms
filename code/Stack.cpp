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

class Node{
    public:
    int value;
    Node* next;
    
    Node(int x){
        this->value=x;
        this->next=NULL;
    }
};
class StackLL{
    private:
    Node* top;
    public:
    StackLL(){
        top=NULL;
    }
    void push(int x){
        Node* temp=new Node(x);
        if(!temp){
            cout<<"stack overflow"<<endl;
            exit(1);
        }
        temp->value=x;
        temp->next=top;
        top=temp;
    }
    void pop(){
        
        Node* nxt;
        if(top==NULL){
            cout<<"stack underflow"<<endl;
            exit(1);
        }
        else{
            nxt=top;
            cout<<"popped element is: "<<top->value<<endl;
            top=top->next;
            delete(nxt);
        }
       

    }
    bool isEmpty(){
        if(top==NULL){
            cout<<"stack is empty"<<endl;
            return true;
        } 
        else{
            cout<<"not empty"<<endl;
            return false;
        }
    }
    void peak(){
        if(!isEmpty()){
            cout<<"top element is: "<<top->value<<endl;
        }
        else{
            exit(1);
        }
        
    }
    
    void display()
    {
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        }
    
        cout<<"linkedlist traversal: "<<endl;

        Node* curr;
        curr=top;
        while (curr != NULL)
        {
            cout << curr->value << " ";
            curr = curr->next;
            if (curr != NULL)
                cout <<"-> ";
        }
        cout<<endl;
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

void insert_at_bottom(stack<int>& s,int x){
    if(s.empty()){
        s.push(x);
        return ;
    }

    int num=s.top();
    s.pop();
    insert_at_bottom(s,x);
    s.push(num);
}

void sorting(stack<int>& s,int num){
    if( s.empty() || ( !s.empty() && num>s.top()) ){
        s.push(num);
        return ;
    }

    int n=s.top();
    s.pop();
    sorting(s,num);
    s.push(n);
}
void divide(stack<int> &s){
    if(s.empty()){
        return;
    }

    int num=s.top();
    s.pop();
    divide(s);
    sorting(s,num);
}

void circular_tour_1(int* fuel1,int* cost1,int n){
    int ans;
    for(int i=0;i<n;i++){
        int currpetrol=0,travelled=0;
        while(currpetrol>=0 && travelled<n){
            currpetrol+=( fuel1[(i+travelled)%n]-cost1[(i+travelled)%n] );
            travelled++;
        }
        if(travelled==n && currpetrol>=0){
            ans=i;
        }
    }
    cout<<"the index is: "<<ans+1;  
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

    //linkedlist
    // StackLL s;
    // s.push(14);
    // s.push(67);
    // s.display();
    // s.pop();
    // s.push(999);
    // s.push(-1);
    // s.peak();
    // s.display();

    //insert element at bottom
    // stack<int> s;
    // s.push(5);
    // s.push(4);
    // s.push(3);
    // s.push(2);
    // s.push(1);

    // int x=56;
    // insert_at_bottom(s,x);
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.top();//56


    //sort stack
    // stack<int> s;
    // s.push(-5);
    // s.push(14);
    // s.push(31);
    // s.push(10);
    // s.push(-1);

    // divide(s);
    // for(int i=0;i<5;i++){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    //first negative element in every window of size k
    // int A[]={-8,2,3,-6,10};
    // int K=2,N=5;
    // deque<int> dq;
    // vector<int> ans;  
    
    // for(int i=0;i<K;i++){
    //     if(A[i]<0){
    //         dq.push_back(i);
    //     }
    // }
    
    // if(dq.size()>0){
    //     ans.push_back(A[dq.front()]);
    // }
    // else{
    //     ans.push_back(0);
    // }
    
    // for(int k=K;k<N;k++){
    //     if(!dq.empty() && k-dq.front()>=K){
    //       dq.pop_front();  
    //     }
        
    //     if(A[k]<0){
    //         dq.push_back(k);
            
    //     }
    //     if(dq.size()>0){
    //         ans.push_back(A[dq.front()]);
    //     }
    //     else{
    //         ans.push_back(0);
    //     }
        
    // }
    
    // for(auto i:ans){
    //     cout<<i<<" ";
    // }


    // First circular tour
    //Approach 1
    int fuels[] = {5, 2, 11, 8};
    int costs[] = {3, 7, 2, 9};
    int n=sizeof(fuels)/sizeof(fuels[0]);
    circular_tour_1(fuels,costs,n);//O(N*N)
    return 0;
    

}
