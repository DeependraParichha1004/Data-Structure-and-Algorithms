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
};

void insertion_at_start(linkedlist *&head, int a)
{
    linkedlist *temp = new linkedlist(a);
    temp->next = head;
    head = temp;
}

void insertion_at_position(linkedlist* &head, int position, int a){
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

    linkedlist* nodetoinsert=new linkedlist(a);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}

void insertion_at_end(linkedlist* &tail, int a)
{
    linkedlist *temp = new linkedlist(a);
    tail->next = temp;
    tail=tail->next;
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

int main()
{
    linkedlist* node1 = new linkedlist(10); // statically linkedlist node1(10)
    //cout<<node1->next<<endl;//statically node1.next
    linkedlist* head = node1;
    linkedlist* tail = node1;

    // traversal_at_start Before insertion_at_start
    traversal(head);

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
    insertion_at_end(tail, 120);
    traversal(head);
    insertion_at_end(tail, 134);
    traversal(head);

    insertion_at_position(head,1,34);
    traversal(head);

}
