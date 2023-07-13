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
class linkedlist{
    public:
    int value;
    linkedlist* next;

    linkedlist(int value){
        this->value=value;
        this->next=NULL;
    }
};
int main(){
   linkedlist* node1=new linkedlist(10);//statically linkedlist node1(10)
   cout<<node1->next;//statically node1.next
   return 0; 
}
