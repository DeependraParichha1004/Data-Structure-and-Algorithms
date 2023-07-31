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
            cout<<"stack uderflow";
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
    string s="a+((b*c))";
    if(redundant(s)){
        cout<<"redundant";
    }
    else{
        cout<<"non redundant";
    }
    

}