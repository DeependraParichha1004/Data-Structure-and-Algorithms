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

void level_order_traversal(BinaryTree* root){
    queue<BinaryTree*> q;
    q.push(root);
    q.push(NULL);//separator

    while(!q.empty()){
        BinaryTree* temp=q.front();
        
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }  
    }
}

//left root right
void inorder_traversal(BinaryTree* root){
    BinaryTree* temp=root;
    if(temp->left==NULL){
        cout<<temp->data;
        return ;
    }
    if(temp->right==NULL){
        cout<<temp->data;
        return ;
    }
    inorder_traversal(temp->left);
    cout<<temp->data;
    inorder_traversal(temp->right);
}

//left right root
void post_order_traversal(BinaryTree* root){
    BinaryTree* temp=root;
    if(temp->left==NULL){
        cout<<temp->data;
        return ;
    }
    if(temp->right==NULL){
        cout<<temp->data;
        return ;
    }
    post_order_traversal(temp->left);
    
    post_order_traversal(temp->right);
    cout<<temp->data;
}

int main(){
   BinaryTree* root=NULL;
   root=Tree(root);
//    level_order_traversal(root);
//    inorder_traversal(root);
   post_order_traversal(root);
   return 0; 
}