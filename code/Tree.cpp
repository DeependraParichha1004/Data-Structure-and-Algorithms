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
        cout<<temp->data<<" ";
        return ;
    }
    if(temp->right==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    inorder_traversal(temp->left);
    cout<<temp->data<<" ";
    inorder_traversal(temp->right);
}

//left right root
void post_order_traversal(BinaryTree* root){
    BinaryTree* temp=root;
    if(temp->left==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    if(temp->right==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    post_order_traversal(temp->left);
    
    post_order_traversal(temp->right);
    cout<<temp->data<<" ";
}

//root left right 
void pre_order_traversal(BinaryTree* root){
    BinaryTree* temp=root;
    if(temp->left==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    if(temp->right==NULL){
        cout<<temp->data<<" ";
        return ;
    }
    cout<<temp->data<<" ";
    pre_order_traversal(temp->left);
    
    pre_order_traversal(temp->right);
}

int height(BinaryTree* root){
    if(root==NULL){
        return 0;
    }

    int l=height(root->left);
    int r=height(root->right);
    int ans =max(l,r)+1;
    return ans;
}

vector<int> spiral_traversal(BinaryTree* root){
    bool ori=true;//left to right
    vector<int> ans;
    if (root==NULL){
        return ans;      
    }
    queue<BinaryTree*> q;
    q.push(root);
    
    while(!q.empty()){
        int size=q.size();
        vector<int> temp(size);
        for(int i=0;i<size;i++){
            BinaryTree* Front=q.front();
            q.pop();

            int index=ori?i:size-i-1;
            temp[index]=Front->data;

            if(Front->left){
                q.push(Front->left);
            }
            if(Front->right){
                q.push(Front->right);
            }
        }
        ori=!ori;
        for(auto i:temp){
            ans.push_back(i);
        }
    }
    return ans;
}
vector<int> verticalTraversal(BinaryTree* node){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<BinaryTree*,pair<int,int>>> q;
    vector<int> ans;
    if(node==NULL){
        return ans;
    }

    q.push(make_pair(node,make_pair(0,0)));
    while(!q.empty()){
        pair<BinaryTree*,pair<int,int>> temp=q.front();
        q.pop();
        BinaryTree* front_node=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        nodes[hd][lvl].push_back(front_node->data);
        if(front_node->left){
            q.push(make_pair(front_node->left,make_pair(hd-1,lvl+1)));
        }
        if(front_node->right){
            q.push(make_pair(front_node->right,make_pair(hd+1,lvl+1)));
        }
    }
    cout<<"map";
    for(auto i:nodes){
        cout<<i.first<<" ";
        for(auto j:i.second){
            cout<<j.first<<" ";
            for(auto z:j.second){
                cout<<z<<" ";
            }
            // for(auto k:j.second){
                
            //     ans.push_back(k);
            // }
        }
        cout<<endl;
    }
    
    
    return ans;
    

}

bool identical(BinaryTree* root1,BinaryTree* root2 ){
    
    if(root1==nullptr && root2==nullptr){
        return true;
    }
    if(root1==nullptr || root2==nullptr){
        return false;
    }

   return (root1->data == root2->data) && identical(root1->left,root2->left) && identical(root1->right,root2->right);
}

int height_depth(BinaryTree* root){
        if (root == nullptr){
            return 0;
        }
        
        int left=height_depth(root->left);
        int right = height_depth(root->right);
        int maxy = max(left,right)+1;
        return maxy;
    }

int diameter(BinaryTree* root,int maxi){ //time complexity O(n**2)
    if(root==nullptr){
        return 0;
    }
    int lh = height_depth(root->left);
    int rh = height_depth(root->right);
    maxi = max(maxi,lh+rh+1);
    diameter(root->left,maxi);
    diameter(root->right,maxi);
    return maxi;

}

int diameter_2(BinaryTree* root,int maxi){ // optimized version O(n)
    if(root==nullptr){
        return 0;
    }
    int left = diameter_2(root->left,maxi);
    int right = diameter_2(root->right,maxi);
    maxi = max(maxi, left+right);
    return 1+max(left,right);
}

int maximum_sum_path(BinaryTree* root, int &maxi){ // O(n)
    if(root==nullptr){
        return 0;
    }
    int left_sum = max(0,maximum_sum_path(root->left,maxi)); //return 0 if the sum is negative
    int right_sum = max(0,maximum_sum_path(root->right,maxi)); //same as above
    maxi = max(maxi, left_sum+right_sum+root->data);
    return (root->data) + max(left_sum, right_sum);
}
vector<vector<int>> zig_zag_traversal(BinaryTree* root){
    vector<vector<int>> res;
    if(root==nullptr){
        return res;
    }

    queue<BinaryTree*> q;
    q.push(root);
    bool flag = true; 

    while(!q.empty()){
        int size = q.size();
        vector<int> r(size);

        

        for (int i=0;i<size;i++){
            BinaryTree* node = q.front();
            q.pop();
            int index = flag ? i : size-1-i;

            r[index]=node->data;
            if(node->left){
                q.push(node->left);
            }
             if(node->right){
                q.push(node->right);
            }
        }
        flag = !flag;
        res.push_back(r);
    }
    return res;
}

int main(){

    BinaryTree* root=new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    vector<vector<int>> result = zig_zag_traversal(root);
    for (const auto& level : result) {
    for (int val : level) {
        cout << val << " ";
    }
}

    // level_order_traversal(root);
    // inorder_traversal(root);
    // post_order_traversal(root);
    // pre_order_traversal(root);

    // cout<<"height of the given binary tree is: "<<height(root)-1;

    // vector<int> res=spiral_traversal(root);
    // for(auto i:res){
    //     cout<<i<<" ";
    // }

//     vector<int> ans=verticalTraversal(root);
//     for(auto i:ans){
//         cout<<i<<" ";
//     }
//    return 0;

    root->left = new BinaryTree(2);
    root->right = new BinaryTree(10);
    root->left->left = new BinaryTree(20);
    root->left->right = new BinaryTree(1);
    root->right->right = new BinaryTree(-25);
    root->right->right->left = new BinaryTree(3);
    root->right->right->right = new BinaryTree(4);

    // int maxi =0;
    // cout<<diameter_2(root,maxi);

    // BinaryTree* root1 = new BinaryTree(1);    
    // root1->left = new BinaryTree(2);   
    // root1->right = new BinaryTree(3); 
    // root1->left->left = new BinaryTree(4); 

    // BinaryTree* root2 = new BinaryTree(1);    
    // root2->left = new BinaryTree(2);   
    // root2->right = new BinaryTree(3); 
    // root2->left->left = new BinaryTree(41); 

    //  if (identical(root1, root2))
    //     cout << "Yes\n";
    // else
    //     cout << "No\n";


}
