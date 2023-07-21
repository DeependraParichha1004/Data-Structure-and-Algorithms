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

//int linked list
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

//char linked list
class linkedlist_char{
    public:
    char data;
    linkedlist_char* next;

    linkedlist_char(char data){
        this->data=data;
        this->next=NULL;
    }
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
        cout<<"Please enter the numbers: "<<endl;
        for(int i=cnt;i<=position;i++){
                
            cin>>a;
            insertion_at_start(temp,a);
        
        }
        return reverse(temp);
    }

}

//incomplete
linkedlist* sort_linkedlist(linkedlist* &head){
    if(head==NULL || head->next==NULL){
        cout<<"value"<<head->value<<endl;
        return head;
    }
    linkedlist* fast=head;
    linkedlist* slow=head;
    linkedlist* temp;

    while(fast!=NULL && fast->next!=NULL){
        temp=slow;
        fast=fast->next->next;
        slow=slow->next;
    }

    temp->next=NULL;

    sort_linkedlist(head);
    sort_linkedlist(slow);

}

// sort 0,1,2
// Approach 1 -> count and replace 

// Approach 2 without replacement
// linkedlist* first=new linkedlist(a);

void create(linkedlist* &node,int a){
    linkedlist* temp=new linkedlist(a);
    node=temp->next;
}

linkedlist* sort_0_1_2(linkedlist* &head){
    linkedlist* zeros=new linkedlist(-1);
    linkedlist* zerostail=zeros;
    linkedlist* ones=new linkedlist(-1);
    linkedlist* onestail=ones;
    linkedlist* twos=new linkedlist(-1);
    linkedlist* twostail=twos;
    
    linkedlist* curr=head;

    while(curr!=NULL){
        int value=curr->value;
        if(value==0){
            insertion_at_end(zerostail,0);
        }
        else if(value==1){
            insertion_at_end(onestail,1);
        }
        else if(value==2){
            insertion_at_end(twostail,2);
        }
        curr=curr->next;
    }

    //merge
    if(ones->next!=NULL){
        zerostail->next=ones->next;
    }
    else if(ones->next==NULL && twos->next!=NULL){
        zerostail=twos->next;
    }

    if(twos->next!=NULL){
        onestail->next=twos->next;
    }
    else if(twos->next==NULL){
        onestail->next=NULL;
    }

    head=zeros->next;
    delete zeros;
    delete ones;
    delete twos;
    return head;
}

//merge two sorted linkedlist
linkedlist* merge(linkedlist* first,linkedlist* second){
    
    if(first->next==NULL){
        first->next=second;
    }

    linkedlist* curr1=first;
    linkedlist* next1=curr1->next;
    linkedlist* curr2=second;
    linkedlist* next2=curr2->next;

    

    while(curr2!=NULL && next1!=NULL){
        if ((curr2->value >= curr1->value) && (curr2->value <= next1->value)){
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            curr1=curr2;
            curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1->next==NULL){
                curr1->next=curr2;
                return first;
            }
        }
        
    }
    return first;
}

//merge-sort merge
linkedlist* merge_sort_merge(linkedlist* l1,linkedlist* l2){
    linkedlist* ptr=new linkedlist(-1);
    linkedlist* curr=ptr;

    while(l1!=NULL && l2!=NULL){
        if(l1->value <= l2->value){
            curr->next=l1;
            l1=l1->next;
        }
        else{
            curr->next=l2;
            l2=l2->next;
        }
        curr=curr->next;
    }

    if(l1!=NULL){
        curr->next=l1;
        l1=l1->next;
    }

    if(l2!=NULL){
        curr->next=l2;
        l2=l2->next;
    }

    return ptr->next;
}
//merge sort
linkedlist* merge_sort(linkedlist* head){
    linkedlist* fast=head;
    linkedlist* slow=head;
    linkedlist* prev=NULL;
    if(head==NULL || head->next==NULL){
        return head;
    }
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    prev->next=NULL;

    linkedlist*l1=merge_sort(head);
    linkedlist*l2=merge_sort(slow);

    return merge_sort_merge(l1,l2);

}

void insert_char(linkedlist_char* &head,char c){
    if(head==NULL){
        linkedlist_char* temp=new linkedlist_char(c);
        head=temp;
    }
}

// Approach 1
bool palindrome1(vector<int> vec){
    int l=0,h=vec.size()-1;
    while(l<=h){
        if(vec[l]==vec[h]){
            l++,h--;
        }
        else{
            return false;
        }
    }
    return true;
}
bool palindrome_LL1(linkedlist* head){
    linkedlist* curr=head;
    int l=length(head);
    vector<int> vec{l};
    while(curr!=NULL){
        int val=curr->value;
        vec.push_back(val);
        curr=curr->next;
    }
    return palindrome1(vec);
}

// Approach 2
bool palindrome_2(linkedlist* head,linkedlist* fast,linkedlist* slow){
    linkedlist* temp=slow->next;
    slow->next=reverse(temp);

    linkedlist* curr=head;

    linkedlist* head1=head;
    linkedlist* head2=slow->next;
    
    while(head2!=NULL){
        if(head1->value != head2->value){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    temp=slow->next;
    slow->next=reverse(temp);
    return true;
}


bool palindrome_LL2(linkedlist* head){
    if(head->next==NULL){//single element
        return true;
    }
    linkedlist* fast=head;
    linkedlist* slow=head;

    while(fast!=NULL && fast->next!=NULL){
        
        slow=slow->next;
        fast=fast->next->next;
    }

    return palindrome_2(head,fast,slow);
}
int main()
{
    // Singly linkedlist operations

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


    // reverse a linked list
    // Approach 1
    // cout<<"how many elements you need to enter: "<<endl;
    // int c;
    // cin>>c;
    // linkedlist* list=create_linked_list(c);
    // linkedlist* ptr=reverse(list);
    // traversal(ptr);
    // head_tail(list,ptr);

    // Approach 2
    // linkedlist* prev=NULL;
    // linkedlist* curr=head;
    // reverse_recursive(list,curr,prev);
    // traversal(list);

    // Approach 3
    // linkedlist* linkedlist=reverse_approach2(list);
    // traversal(linkedlist);



    //Reverse List In K Groups
    // cout<<"how many elements you need to enter: "<<endl;
    // int c;
    // cin>>c;
    // linkedlist* list=create_linked_list(c);
    // linkedlist* ans=kReverse(list,2);
    // traversal(ans); 


    // Detect loop and floyd's algorithm(loop detection)
    // cout<<"how many elements you need to enter: "<<endl;
    // int c;
    // cin>>c;
    // linkedlist* list=create_linked_list(c);
    
    // linkedlist* tail=list;
    // while(tail->next!=NULL){
    //     tail=tail->next;
    // }

    // tail->next=list->next->next;//create loop

    // if(loop_detection_map(list)){
    //     cout<<"loop is present";
    // }
    // else{
    //     cout<<"loop is not present";
    // }


    //floyd's algorithm
    // if(floyds(list)){
    //     cout<<"loop is present";
    // }
    // else{
    //     cout<<"loop is not present";
    // }



    //duplicate in unsorted linked list
    // cout<<"how many elements you need to enter: "<<endl;
    // int c;
    // cin>>c;
    // linkedlist* list=create_linked_list(c);
    
    // duplicate_approach1(head);
    //traversal(list);
    // delete_dup_unsorted_1(list);
    // traversal(list);

    //delete duplications in sorted linked list
    // delete_sorted(head);
    // traversal(list);


    //create linked list
    // cout<<"how many elements you need to enter: "<<endl;
    // int c;
    // cin>>c;
    // linkedlist* list=create_linked_list(c);
    // cout<<"Ans"<<endl;
    // traversal(list);//reverse

    // sort the linked list
    // cout<<"how many elements you need to enter: "<<endl;
    // int c;
    // cin>>c;
    // linkedlist* list=create_linked_list(c);
    // // sort_linkedlist(list);
    // traversal(list);


    // Sort 0,1,2
    // cout<<"how many elements do you need to enter: "<<endl;
    // int c;
    // cin>>c;
    // linkedlist* list=create_linked_list(c);
    // linkedlist* s=sort_0_1_2(list);
    // traversal(s);

    // Merge two sorted array
    // cout<<"how many elements do you need to enter for first list: "<<endl;
    // int c;
    // cin>>c;
    // linkedlist* first=create_linked_list(c);
    // cout<<"how many elements do you need to enter for second list: "<<endl;
    // int d;
    // cin>>d;
    // linkedlist* second=create_linked_list(d);

    // // linkedlist* s=merge(first,second);
    // if(first->value<=second->value){
    //     merge(first,second);
    // }
    // else{
    //     merge(second,first);
    // }
    // traversal(first);

    //merge_sort
    // cout<<"how many elements do you need to enter for first list: "<<endl;
    // int c;
    // cin>>c;
    // linkedlist* first=create_linked_list(c);
    // linkedlist* temp=merge_sort(first);
    // traversal(temp);

    // Check-if-linked-list-is-pallindrome
    // Approach 1

    // cout<<"how many elements do you need to enter for first list: "<<endl;
    // int c;
    // cin>>c;
    // linkedlist* first=create_linked_list(c);
    
    // if(palindrome_LL1(first)){
    //     cout<<"yes palindrome";
    // }
    // else{
    //     cout<<"no palindrome";
    // }
    
    // Approach 2
    cout<<"how many elements do you need to enter for first list: "<<endl;
    int c;
    cin>>c;
    linkedlist* first=create_linked_list(c);
    if(palindrome_LL2(first)){
        cout<<"yes paliondrome";
    }
    else{
        cout<<"no palindrme";
    }


    return 0;
}
