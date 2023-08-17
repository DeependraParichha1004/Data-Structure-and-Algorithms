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
class BinaryTree{
    public:
    int data;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

BinaryTree* Tree(BinaryTree* root){
    int data;
    
    cout<<"enter data: "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new BinaryTree(data);

    cout<<"enter data for inserting in left of: "<<data<<endl;
    root->left=Tree(root->left);
    cout<<"enter data for inserting in right of: "<<data<<endl;
    root->right=Tree(root->right);
    return root;

}
int main(){
   BinaryTree* root=NULL;
   Tree(root);
     
    return 0; 
}