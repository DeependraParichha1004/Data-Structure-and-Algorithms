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

    /* don't uncomment while running delete_sorted function*/
    /*
    ~linkedlist(){
        
        int value=this->value;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        
        cout<<"destructor called for "<<value<<endl;
    }
    */
    
};

// length of the linked list
int length(linkedlist *head) {
    int cnt=0;
    while(head!=NULL){
        head=head->next;
        cnt++;
    }
    return cnt;
    
} 

// Reverse the linked list in k groups
linkedlist* kReverse(linkedlist* head, int k) {
    int len=length(head);
    if(head==NULL){
        return NULL;
    }
    int cnt=0;
    linkedlist* forward=NULL;
    linkedlist* prev=NULL;
    linkedlist* curr=head;
    
   
    while (cnt < k && curr != NULL) {
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    cnt++;
    }
      
  
    if(len-k>=cnt){
      if (forward != NULL) {
        head->next = kReverse(forward, k);
      }
    }
    else{
        head->next=forward;
    }

    return prev;
}


// Insertion at start, middle and end
void insertion_at_start(linkedlist *&head, int a)
{
    linkedlist *temp = new linkedlist(a);
    temp->next = head;
    head = temp;
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
    linkedlist* linkedlisttoinsert=new linkedlist(a);
    linkedlisttoinsert->next=temp->next;
    temp->next=linkedlisttoinsert;
}


// Deletion
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

// Traversal

void tail_to_head(linkedlist* head){
    while(head!=NULL){
        cout<<head->value<<" ";
        head=head->next;
    }
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

void head_tail(linkedlist* &head,linkedlist* &tail){
    cout<<"head is "<<head->value<<endl;
    cout<<"tail is "<<tail->value<<endl;
}

// Reverse the Linkedlist
// (1) Approach 1
linkedlist* reverse(linkedlist* head){
    linkedlist* prev=NULL;
    linkedlist* l_list=NULL;//remaining list
    linkedlist* curr=head;
    while(curr!=NULL){
        l_list=curr->next;
        curr->next=prev;
        prev=curr;
        curr=l_list;

    }
    return prev;

}

// (2) Approach 2
void reverse_recursive(linkedlist* &head,linkedlist* curr,linkedlist* prev){
    
    if(curr==NULL){
        head=prev;
        return ;
    }
    
    linkedlist* l_list=curr->next;
    reverse_recursive(head,l_list,curr);
    curr->next=prev;
}

// (3) Approach 3
linkedlist* reverse_approach2(linkedlist* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    linkedlist* linkedlist=reverse_approach2(head->next);

    head->next->next=head;
    head->next=NULL;

    return linkedlist;
}

// Loop detection
// Approach 1
bool loop_detection_map(linkedlist* head){
    if(head==NULL){
        return false;
    }

    map<linkedlist*, bool> visited;
    linkedlist* temp=head;

    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
            break;
        }

        visited[temp]=true;
        temp=temp->next;
    }

    return false;
}

// Approach 2
bool floyds(linkedlist* &head){
    linkedlist* fast=head;
    linkedlist* slow=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            // slow=head;//for detecting starting point, don't return any value
            // break;//for detecting starting point, don't return any value
            return true;
        }
    }

    /* //for detecting starting point, don't return any value 
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    
    cout<<slow->value;
    */
    return false;
}


// Delete duplicates from a sorted linked list
void delete_sorted(linkedlist* &head){
    linkedlist* curr=head;
    if(head==NULL){
        return ;
    }
    while(curr!=NULL){
        if( (curr->next!=NULL) && curr->value==curr->next->value ){
            linkedlist* next_node=curr->next;
            linkedlist* next_next_node=curr->next->next;
            delete(next_node);
            
            curr->next=next_next_node;  
            
        }
        
        else{
            curr=curr->next;
        }
    }

}


// Delete duplicates from an unsorted array
void delete_node(linkedlist* &curr,linkedlist* &temp){
    linkedlist* prev=curr;
    while(prev->next!=temp){
        prev=prev->next;
    }

    linkedlist* next_node=prev->next;
    linkedlist* next_next_node=prev->next->next;
    delete(next_node);
    prev->next=next_next_node;
    temp=prev;

}

void delete_dup_unsorted_1(linkedlist* &head){
    if(head==NULL){
        return ;
    }
    if(head->next==NULL){
        return ;
    }
    linkedlist* curr=head;
    while(curr!=NULL){
        linkedlist* temp=curr->next;
        while(temp!=NULL){
            if(curr->value==temp->value){
                delete_node(curr,temp);
                temp=temp->next;
            }
            else{
                temp=temp->next;
            }
        }
        curr=curr->next;
    }
}

linkedlist* create_linked_list(int position){
    linkedlist* temp=NULL;
    // linkedlist* tail=NULL;
    if(position<1){
        cout<<"list cannot be empty!!";
        return NULL;
    }
    else{
        int cnt=1,a;
        cout<<"enter the numbers(in the form of back to front): "<<endl;
        for(int i=cnt;i<=position;i++){
                
            cin>>a;
            insertion_at_start(temp,a);
        
        }
        return temp;
    }

    
    

}

int main()
{
    //singly linkedlist
    // linkedlist* linkedlist1 = new linkedlist(10); // statically linkedlist linkedlist1(10)
    // // cout<<linkedlist1->next<<endl;//statically linkedlist1.next
    // linkedlist* head = linkedlist1;
    // linkedlist* tail = linkedlist1;

    // // traversal_at_start Before insertion_at_start
    // traversal(head);

    // traversal after insertion_at_start
    // insertion_at_start(head,54);
    // traversal(head);
    // insertion_at_start(head,34);
    // traversal(head);

    // traversal after insertion_at_end
    // insertion_at_end(tail, 120);
    // traversal(head);
    // insertion_at_end(tail, 134);
    // traversal(head);

    //traversal after insertion_at_position
    // insertion_at_end(tail, 120);
    // traversal(head);
    // insertion_at_end(tail, 134);
    // traversal(head);

    // insertion_at_position(tail,head,1,4);
    // traversal(head);
    // insertion_at_position(tail,head,2,2);
    // traversal(head);
    // insertion_at_position(tail,head,3,7);
    // traversal(head);
    // head_tail(head,tail);

    // // deletion(head,4);
    // // traversal(head);
    // H/W handle last linkedlist while deletion as well as tail

    


    //reverse a linked list
    // linkedlist* linkedlist1 = new linkedlist(10);
    // linkedlist* head = linkedlist1;
    // linkedlist* tail = linkedlist1;
    // traversal(head);

    // insertion_at_position(tail,head,1,4);
    // traversal(head);
    // insertion_at_position(tail,head,2,2);
    // traversal(head);
    // insertion_at_position(tail,head,3,7);
    // traversal(head);//4 10 2 7
    // head_tail(head,tail);//4 7 


    
    // linkedlist* ptr=reverse(head);
    // traversal(ptr);//7 2 10 4
    // head_tail(head,ptr);//4 7

    // linkedlist* prev=NULL;
    // linkedlist* curr=head;
    // reverse_recursive(head,curr,prev);

    // traversal(head);//7 2 10 4

    // linkedlist* linkedlist=reverse_approach2(head);
    // traversal(linkedlist);



    //Reverse List In K Groups
    // linkedlist* linkedlist1 = new linkedlist(10);
    // linkedlist* head = linkedlist1;
    // linkedlist* tail = linkedlist1;
    // traversal(head);

    // insertion_at_position(tail,head,1,4);
    // traversal(head);
    // insertion_at_position(tail,head,2,2);
    // traversal(head);
    // insertion_at_position(tail,head,3,7);
    // traversal(head);//4 10 2 7
    // head_tail(head,tail);//4 7 

    // linkedlist* ans=kReverse(head,2);
    // traversal(ans); 

    


    //detect loop and floyd's algorithm(loop detection)
    // linkedlist* linkedlist1 = new linkedlist(10);
    // linkedlist* head = linkedlist1;
    // linkedlist* tail = linkedlist1;
    // traversal(head);

    // insertion_at_position(tail,head,1,4);
    // traversal(head);
    // insertion_at_position(tail,head,2,2);
    // traversal(head);
    // insertion_at_position(tail,head,3,7);
    // traversal(head);//4 10 2 7
    // // head_tail(head,tail);//4 7 
    // traversal(head);
    // insertion_at_position(tail,head,4,13);
    // traversal(head);
    // insertion_at_position(tail,head,5,18);
    // traversal(head);
    // insertion_at_position(tail,head,6,38);
    // traversal(head);
    // insertion_at_position(tail,head,7,28);
    // traversal(head);
    

    // tail->next=head->next->next;//loop is present
    // floyds(head);
    // if(loop_detection_map(head)){
    //     cout<<"loop is present";
    // }
    // else{
    //     cout<<"loop is not present";
    // }

    //floyd's algo
    // if(floyds(head)){
    //     cout<<"loop is present";
    // }
    // else{
    //     cout<<"loop is not present";
    // }

    // traversal(head);


    //duplicate in unsorted linked list
    // linkedlist* linkedlist1 = new linkedlist(2);
    // linkedlist* head = linkedlist1;
    // linkedlist* tail = linkedlist1;
    // traversal(head);

    // insertion_at_position(tail,head,1,1);
    // traversal(head);
    // insertion_at_position(tail,head,2,5);
    // traversal(head);
    // insertion_at_position(tail,head,3,3);
    // traversal(head);//4 10 2 7
    // // head_tail(head,tail);//4 7 
    // traversal(head);
    // insertion_at_position(tail,head,4,2);
    // traversal(head);
    // insertion_at_position(tail,head,5,7);
    // traversal(head);
    // insertion_at_position(tail,head,6,5);
    // traversal(head);
    // insertion_at_position(tail,head,7,9);
    // traversal(head);

    
    // duplicate_approach1(head);
    // delete_dup_unsorted_1(head);

    //delete duplications in sorted linked list
    // delete_sorted(head);
    
    // traversal(head);



    //create linked list
    cout<<"how many elements you need to enter: "<<endl;
    int c;
    cin>>c;
    linkedlist* list=create_linked_list(c);
    cout<<"Ans"<<endl;
    traversal(list);
    return 0;


}
