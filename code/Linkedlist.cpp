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
class linkedlist
{
public:
    int value;
    linkedlist* next;

    linkedlist(int value)
    {
        this->value = value;
        this->next = NULL;
    }

    ~linkedlist(){
        
        int value=this->value;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"destructor called for "<<value<<endl;
    }
};

class doublylinkedlist
{
public:
    int value;
    doublylinkedlist* next;
    doublylinkedlist* prev;

    doublylinkedlist(int value)
    {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }

    ~doublylinkedlist(){
        int value=this->value;
        if(this->next!=NULL){
            delete next;
            this->next-NULL;
        }
        cout<<"memory deleted for doublylinkedlist's value "<<value<<endl;
    }

};

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
        circularlinkedlist* newnode=new circularlinkedlist(a);
        tail=newnode;
        newnode->next=newnode;
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
void insertion_at_start(linkedlist *&head, int a)
{
    linkedlist *temp = new linkedlist(a);
    temp->next = head;
    head = temp;
}

void doubly_insertion_at_start(doublylinkedlist *&tail,doublylinkedlist *&head, int a)
{
    if(tail==NULL){
        doublylinkedlist *temp = new doublylinkedlist(a);
        tail=temp;
        head=temp;
    }
    else{
    doublylinkedlist *temp = new doublylinkedlist(a);
    temp->next = head;
    head->prev=temp;
    head=temp;
    }
}

void doubly_insertion_at_end(doublylinkedlist *&tail,doublylinkedlist *&head, int a)
{
    if(tail==NULL){
        doublylinkedlist *temp = new doublylinkedlist(a);
        tail=temp;
        head=temp;
    }
    else{
        doublylinkedlist *temp = new doublylinkedlist(a);
        tail->next = temp;
        temp->prev=tail;
        tail=temp;
    }
}

void doubly_insertion_at_position(doublylinkedlist* &tail,doublylinkedlist* &head, int position, int a){
    doublylinkedlist* temp=head;
    int cnt=1;
    if(position==1){
        // temp->next=head;
        // temp->prev=NULL;
        // head=temp;

        doubly_insertion_at_start(tail,head,a);
        return ;
    }

    

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        doubly_insertion_at_end(tail,head,a);
        return ;
    }

    doublylinkedlist* nodetoinsert=new doublylinkedlist(a);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;

}

void insertion_at_end(linkedlist* &tail, int a)
{
    linkedlist *temp = new linkedlist(a);
    tail->next = temp;
    tail=temp;
}

void insertion_at_position(linkedlist* &tail,linkedlist* &head, int position, int a){
    linkedlist* temp=head;
    int cnt=1;

    if(position==1){
        insertion_at_start(head,a);
        return ;
    }

    while(cnt<position){
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        insertion_at_end(tail,a);
        return;
    }
    linkedlist* nodetoinsert=new linkedlist(a);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}


void deletion(linkedlist* &head,int position){
    //at start
    if(position==1){
        linkedlist* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    //at end or any other position
    linkedlist* prev=NULL;
    linkedlist* curr=head;

    int cnt=1;
    while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }

    
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;

    
}
void traversal(linkedlist* &head)
{
    linkedlist* temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout<<endl;
}

void doublytraversal(doublylinkedlist* &head)
{
    doublylinkedlist* temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout<<endl;
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
void doublydelete(doublylinkedlist* &tail,doublylinkedlist* &head,int position){
    if(position==1){
        doublylinkedlist* temp=head;
        temp->next->prev=NULL;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    else{
    //at end or any other position
    doublylinkedlist* prev=NULL;
    doublylinkedlist* curr=head;

    int cnt=1;
    while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }

    if(curr->next==NULL){// H/W handle last node while deletion as well as tail
        tail=curr->prev;
    }

    curr->prev=NULL;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    }

}

void circular_head_tail(circularlinkedlist* &head,circularlinkedlist* &tail){
    cout<<"head is "<<head->value<<endl;
    cout<<"tail is "<<tail->value<<endl;
}

void doubly_head_tail(doublylinkedlist* &head,doublylinkedlist* &tail){
    cout<<"head is "<<head->value<<endl;
    cout<<"tail is "<<tail->value<<endl;
}
void head_tail(linkedlist* &head,linkedlist* &tail){
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

    if(curr==prev){
        tail=NULL;
    }
    if(tail==curr){
        tail=prev;
    }

    curr->next=NULL; 
    delete curr;
}
int main()
{
    //singly linkedlist
    // linkedlist* node1 = new linkedlist(10); // statically linkedlist node1(10)
    // //cout<<node1->next<<endl;//statically node1.next
    // linkedlist* head = node1;
    // linkedlist* tail = node1;

    // // traversal_at_start Before insertion_at_start
    // traversal(head);

    // // traversal after insertion_at_start
    // // insertion_at_start(head,54);
    // // traversal(head);
    // // insertion_at_start(head,34);
    // // traversal(head);

    // // traversal after insertion_at_end
    // // insertion_at_end(tail, 120);
    // // traversal(head);
    // // insertion_at_end(tail, 134);
    // // traversal(head);

    // //traversal after insertion_at_position
    // insertion_at_end(tail, 120);
    // traversal(head);
    // insertion_at_end(tail, 134);
    // traversal(head);

    // insertion_at_position(tail,head,1,34);
    // traversal(head);

    // // deletion(head,4);
    // // traversal(head);
    // H/W handle last node while deletion as well as tail

    
    //doublylinkedlist
    // doublylinkedlist* node1=new doublylinkedlist(10);
    // doublylinkedlist* head=node1;
    // doublylinkedlist* tail=node1;
    // doublytraversal(head);

    // // doubly_insertion_at_start(head,16);
    // // doublytraversal(head);

    // doubly_insertion_at_end(tail,head,16);
    // doublytraversal(head);
    // doubly_insertion_at_end(tail,head,161);
    // doublytraversal(head);

    // doubly_insertion_at_position(tail,head,2,78);
    // doublytraversal(head);

    // doubly_insertion_at_position(tail,head,2,1161);
    // doublytraversal(head);

    // // doublydelete(head,1);
    // // doublytraversal(head);

    // doublydelete(tail,head,2);
    // doublytraversal(head);
    // doubly_head_tail(head,tail);

    
    //circular linked list
    circularlinkedlist* tail=NULL;
    circularinsert(tail,2,1);
    circulartraversal(tail);

    circularinsert(tail,1,2);
    circulartraversal(tail);

    circularinsert(tail,2,7);
    circulartraversal(tail);

    circularinsert(tail,7,8);
    circulartraversal(tail);

    circularinsert(tail,2,18);
    circulartraversal(tail);

    circularinsert(tail,8,10);
    circulartraversal(tail);

    circulardeletion(tail,18);
    circulartraversal(tail);


}
