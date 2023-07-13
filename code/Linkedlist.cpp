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

};

void insertion_at_start(linkedlist *&head, int a)
{
    linkedlist *temp = new linkedlist(a);
    temp->next = head;
    head = temp;
}

void doubly_insertion_at_start(doublylinkedlist *&head, int a)
{
    doublylinkedlist *temp = new doublylinkedlist(a);
    temp->next = head;
    head->prev=temp;
    head=temp;
}

void doubly_insertion_at_end(doublylinkedlist *&head, int a)
{
    doublylinkedlist *temp = new doublylinkedlist(a);
    head->next = temp;
    temp->prev=head;
    temp->next=NULL;
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

    // // H/W handle last node while deletion as well as tail

    
    //doublylinkedlist
    doublylinkedlist* node1=new doublylinkedlist(10);
    doublylinkedlist* head=node1;
    doublytraversal(head);

    // doubly_insertion_at_start(head,16);
    // doublytraversal(head);

    doubly_insertion_at_end(head,16);
    doublytraversal(head);



}
