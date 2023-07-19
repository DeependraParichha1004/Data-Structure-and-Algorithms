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
class circularlinkedlist
{
public:
    int value;
    circularlinkedlist* next;

    circularlinkedlist(int value)
    {
        this->value = value;
        this->next = NULL;
    }

    ~circularlinkedlist(){
        int value=this->value;
        if(this->next!=NULL){
            delete next;
            this->next-NULL;
        }
        cout<<"memory deleted for doublylinkedlist's value "<<value<<endl;
    }

};
void circularinsert(circularlinkedlist* &tail,int element,int a){
    if(tail==NULL){
        circularlinkedlist* newlinkedlist=new circularlinkedlist(a);
        tail=newlinkedlist;
        newlinkedlist->next=newlinkedlist;
    }
    else{
        circularlinkedlist* curr=tail;
        while(curr->value!=element){
            curr=curr->next;
        }

        circularlinkedlist* temp=new circularlinkedlist(a);
        temp->next=curr->next;
        curr->next=temp;
        

    }
}

void circular_head_tail(circularlinkedlist* &head,circularlinkedlist* &tail){
    cout<<"head is "<<head->value<<endl;
    cout<<"tail is "<<tail->value<<endl;
}

void circulardeletion(circularlinkedlist* &tail,int value){
    if(tail==NULL){
        cout<<"list is empty "<<endl;
        return ;
    }

    circularlinkedlist* prev=tail;
    circularlinkedlist* curr=prev->next;
    
    while(curr->value!=value){
        prev=curr;
        curr=curr->next;
    }

    prev->next=curr->next;

    // if(curr==prev){
    //     tail=NULL;
    // }
    if(tail==curr){
        tail=prev;
    }

    curr->next=NULL; 
    delete curr;
}

void circulartraversal(circularlinkedlist* &tail)
{
    circularlinkedlist* temp = tail;

    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return ;
    }
    do
    {
        cout << tail->value << " ";
        tail = tail->next;
    }while (tail != temp);
    cout<<endl;
}

bool length_circular(circularlinkedlist* head){
    circularlinkedlist* curr=head;
    do{
        curr=curr->next;
        if(curr->value!=head->value){
            
            continue;
        }
        else{
            return true;
            break;
        }

        return false;
    }while(curr->next!=NULL || curr->next==head);

    
}

int main(){
   
    // Circular linked list
    // create circulrt linkedlist

    circularlinkedlist* tail=NULL;
    circularinsert(tail,2,1);
    circulartraversal(tail);

    // circularinsert(tail,1,2);
    // circulartraversal(tail);

    // circularinsert(tail,2,7);
    // circulartraversal(tail);

    // circularinsert(tail,7,8);
    // circulartraversal(tail);

    // circularinsert(tail,2,18);
    // circulartraversal(tail);

    // circularinsert(tail,8,10);
    // circulartraversal(tail);

    // circulardeletion(tail,1);
    // circulartraversal(tail);
    // cout<<tail->value;


    
    return 0; 
}