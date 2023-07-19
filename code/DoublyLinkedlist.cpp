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
            this->next=NULL;
        }
        cout<<"memory deleted for doublylinkedlist's value "<<value<<endl;
    }

};

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

    doublylinkedlist* linkedlisttoinsert=new doublylinkedlist(a);
    linkedlisttoinsert->next=temp->next;
    temp->next->prev=linkedlisttoinsert;
    temp->next=linkedlisttoinsert;
    linkedlisttoinsert->prev=temp;

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

    if(curr->next==NULL){// H/W handle last linkedlist while deletion as well as tail
        tail=curr->prev;
    }

    // curr->prev=NULL;
    // prev->next=curr->next;
    // curr->next=NULL;
    // delete curr;

    prev=curr->prev;
    prev->next=curr->next;
    curr->next->prev=prev;
    curr=NULL;
    delete curr;
    }

}

void doubly_head_tail(doublylinkedlist* &head,doublylinkedlist* &tail){
    cout<<"head is "<<head->value<<endl;
    cout<<"tail is "<<tail->value<<endl;
}

int main(){
    // Doublylinkedlist

    // Create doubly linkedlist
    doublylinkedlist* linkedlist1=new doublylinkedlist(10);
    doublylinkedlist* head=linkedlist1;
    doublylinkedlist* tail=linkedlist1;
    doublytraversal(head);


    // Insertion
    doubly_insertion_at_start(tail,head,16);
    doublytraversal(head);

    doubly_insertion_at_end(tail,head,16);
    doublytraversal(head);
    doubly_insertion_at_end(tail,head,161);
    doublytraversal(head);

    doubly_insertion_at_position(tail,head,2,78);
    doublytraversal(head);

    doubly_insertion_at_position(tail,head,2,1161);
    doublytraversal(head);

    doublydelete(tail,head,1);
    doublytraversal(head);

    // Deletion
    // doublydelete(tail,head,2);
    // doublytraversal(head);
    // doubly_head_tail(head,tail);

    return 0;
}