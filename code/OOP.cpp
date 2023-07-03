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
class empty{
    //
};
class priv{
    
    int a;
    int b=5;
};

class get_set{
    private:
    string s;
    int b=5;

    public:
    char ch;
    string getter(){
        return s;
    }

    void setter(string str){
        s=str;

    }
};

class cons{
    public:
    int a=5;
    cons(){
        cout<<"constructor called: "<<endl;
    }
    cons(int a){
        cout<<"address of this keyword: "<<this<<endl;
    }

    //copy constructor
    cons(cons& t){
        cout<<"copy constructor called: "<<endl;
        a=t.a;
    }

    // cons(int a){
    //     a=a;
    //     cout<<"parameterized constructor called: "<<a<<endl;
    // }

    // cons(int a){
    //     this->a=a;
    //     cout<<"parameterized constructor called: "<<a<<endl;
    // }
};

class deep_shallow{
    private:
    int a;
    

    public:
    char* c;
    char level;
    static int st;
    deep_shallow(int a,char level){
        this->a=a;
        this->level=level;
    }

    deep_shallow(deep_shallow& temp){//deep copy is implemented in user defiined copy constructor
        char* cha=new char[strlen(temp.c)+1];
        strcpy(cha,temp.c);
        this->c=cha;
        cout<<"deep: "<<&c<<endl;
        this->level=temp.level;
        this->a=temp.a;
    }

    int geta(){
        return a;
    }
    void seta(int a){
        this->a=a;
    }
    
    void setc(char name[]){
        this->c=name;
        cout<<"set: "<<&c<<endl;
    }
    deep_shallow(){//shallow copy is implemented in default copy constructor 
        c=new char[100];
        cout<<"constructor called"<<endl;
    }


    void print(){
        cout<<"a "<<this->a<<endl;
        cout<<"c "<<this->c<<endl;
        cout<<"level "<<this->level<<endl;
    }

    ~deep_shallow(){
        cout<<"destructor called";
    }//to call destructor for dynamic allocation we need to do manually using 
    
};

class parent{
    protected:
    int priv=18;
    public:
    int age_p;
    int weight=1000;
    string name;

    int setter(int age_p,int weight,string name){
        this->age_p=age_p;
        this->weight=weight;
        this->name=name;
    }
    
    void print_p(){
        cout<<"age "<<this->age_p<<endl;
        cout<<"weight "<<this->weight<<endl;
        cout<<"name "<<this->name<<endl;
    }
};

class child: public parent{
    public:
    int age_c;
    void print_c(){
        // print_p();
        cout<<"c print_p function: "<<endl;
        this->age_c=888;
        cout<<this->priv;
    }
};

int deep_shallow::st=5;

//Inheritance ambiguity
class ambi{
    public:
    void func1(){
        cout<<" ambi1"<<endl;
    }
};

class ambi1{
    public:
    void func1(){
        cout<<" ambi2"<<endl;
    }
};

class ambi2: public ambi1,public ambi{
    //
};

//operator overloading
class oper{
    public:
    int a;
    int b;

    void operator-(oper& obj){
        int value1=this->a;//obj1.a (important)
        int value2=obj.a;
        cout<<"ans is: "<<value1-value2<<endl;
    }
};

//function overriding
class A{
    public:
     virtual void print(){
        cout<<"A's print function"<<endl;
    }
    void show(){
        cout<<"A's show function"<<endl;
    }
};
class B: public A{
    public:
    void print(){
        cout<<"B's print function"<<endl;
    }
    void show(){
        cout<<"B's show function"<<endl;
    }
};

int main(){
   
    //(1) empty class
    // empty e1;
    // cout<<"size of empty class object: "<<sizeof(e1);

    //(2) access specifiers(or modifiers) of the member variables are
    // private by default
    // priv obj1;
    // cout<<obj1.a;//error

    // (3) getter & setter
    // get_set obj1;
    // // cout<<obj1.s;//error

    // cout<<obj1.getter();
    // obj1.setter("bk");
    // cout<<obj1.getter();

    // (4) Dynamic allocation
    // get_set* obj1=new get_set;
    // cout<<(*obj1).getter();
    // cout<<obj1->getter();//same as above


    // (5) 
    // get_set obj1;
    // obj1.setter("bc");
    // cout<<obj1.getter()<<endl;

    // get_set obj2;
    // cout<<obj2.ch;//garbage value
    
    // (6) this keyword -> The 'this' keyword or the 'this' pointer is used as
    // an implicit object parameter when an object's member function is called and 
    // refers(which stores the address of the created object) to the invoking object.

    //without this keyword
    // cons obj1(17);//17
    // cout<<"cons object's a value: "<<obj1.a;//5

    //with this keyword
    // cons obj1(17);//17
    // cout<<"cons object's a value: "<<obj1.a;//17

    //address
    // cons obj1,  obj2(10);
    // cout<<"address of the cons object: "<<&obj1;

    // (7) copy constructor
    // cons obj1;
    // cout<<"obj1 a: "<<obj1.a<<endl;

    // cons obj2(obj1);
    // cout<<"obj2 a: "<<obj2.a<<endl;

    // cons obj1(10);
    // cout<<"obj1 a: "<<obj1.a<<endl;

    // cons obj2(obj1);
    // cout<<"obj2 a :"<<obj2.a<<endl;

    // (8) Deep and Shallow copy
    // deep_shallow obj1(5,'A');
    // char ch[9]="parichha";
    // obj1.setc(ch);
    // cout<<"original obj1: "<<endl;
    // obj1.print();

    //shallow copy -> same memory access by both the objects
    // cout<<"Shallow copy: "<<endl;
    // deep_shallow obj2(obj1);
    // ch[0]='P';
    // cout<<"obj1: "<<endl;
    // obj1.print();//c-Parichha
    // cout<<"obj2: "<<endl;
    // obj2.print();//c- Parichha

    //deep copy -> different memory access by both the objects
    // cout<<"deep copy: "<<endl;
    // deep_shallow obj2(obj1);
    // obj1.c[0]='P';
    // cout<<"obj1: "<<endl;
    // obj1.print();//c- Parichha
    // cout<<"obj2: "<<endl;
    // obj2.print();//c- parichha

    // (9) copy assignment
    // deep_shallow obj1(9,'X');
    // obj1.seta(10);
    // deep_shallow obj2;
    // obj2=obj1;
    // cout<<obj2.geta();

    // deep_shallow* a=new deep_shallow();
    // (*a).print();
    
    // (10) Static Keyword
    // cout<<deep_shallow::st;//5 without creating object

    // (11)Inheritance
    // parent p;
    // child c;
    // p.setter(30,60,"harsh");
    // p.print_p();//p's print() function
    
    // c.setter(90,160,"Harsh");
    // c.print_c();//c's print() function
    // cout<<c.age_c;//888 only when reassigned, otherwise garbage value

    // cout<<c.priv;//inaccessible due to the access specifier

    // parent p;
    // cout<<p.weight;
    // child c;
    // // cout<<c.priv;//protected here
    // c.print_c();
    // cout<<c.age_c;

    // (12) Inheritance ambiguity
    // ambi2 a;
    // a.func1();//func1' is ambiguous

    // solution using scope resolution operator
    // ambi2 a;
    // a.ambi::func1();//ambi's func1 is called

    // (13) operator overloading
    // oper obj1,obj2;
    // obj1.a=23;
    // obj2.a=15;
    // obj1 - obj2;

    // (14) function overriding
    // B obj1;
    // obj1.print();//B's print function
    // obj1.A::print();//A's print function

    // (15) virtual function
    // A* base;
    // B derived;
    // base=&derived;
    // base->print();//B's print function

    // base->show();//A's show function

    //(16) const and function
    




    return 0;
}