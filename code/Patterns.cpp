#include <iostream>
#include <string>
using namespace std;
int main()
{
    //                                           Patterns

    //(1)
    /*              ******
     ******
     ******
     ******
     ******
     */
    // int n;
    // cout<<"Enter the no of rows: "<<endl;
    // cin>>n;
    // int i=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=n){
    //         cout<<'*';
    //         j=j+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    //(2)
    /*             1111
                   2222
                   3333
                   4444
    */
    // int n;
    // cout<<"Enter the no of rows: "<<endl;
    // cin>>n;
    // int i=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=n){
    //         cout<<i;
    //         j=j+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    //(3)
    /*              1234
                    1234
                    1234
                    1234
    */
    // int n;
    // cout<<"Enter the no of rows: "<<endl;
    // cin>>n;
    // int i=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=n){
    //         cout<<j;
    //         j=j+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    //(4)
    /*              321
                    321
                    321
                    321
    */
    // int n;
    // cout<<"Enter the no of rows: "<<endl;
    // cin>>n;
    // int i=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=n){
    //         cout<<n-j+1;
    //         j=j+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    //(5)
    /*              1 2 3 4
                    5 6 7 8
                    9 10 11 12
                    13 14 15 16
    */
    // int n;
    // cout<<"Enter the no of rows: "<<endl;
    // cin>>n;
    // int i=1;
    // int count=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=n){
    //         cout<<count<<" ";
    //         count=count+1;
    //         j=j+1;
    //     }
    //     cout<<"c"<<count;
    //     cout<<endl;
    //     i=i+1;
    // }

    //(6)
    /*              *
     **
     ***
     */
    // int i=1,n;
    // cout<<"enter a no";
    // cin>>n;
    // while(i<=n){
    //     int j=1;
    //     while(j<=i){
    //         cout<<'*';
    //         j=j+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    //(7)
    /*              1
                    22
                    333
                    4444
    */
    // int i=1,n;
    // cout<<"enter a no"<<endl;
    // cin>>n;
    // while(i<=n){
    //     int j=1;
    //     while(j<=i){
    //         cout<<i;
    //         j=j+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    // or
    // int i = 1, n;
    // cout << "enter a no" << endl;
    // cin >> n;
    // char a = 1;
    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout << a + i - 1;
    //         j = j + 1;
    //     }
    //     cout << endl;
    //     i = i + 1;
    // }

    //(8)
    /*              1111
                    222
                    33
                    4
    */
    // int i=1,n;
    // cout<<"enter a no"<<endl;
    // cin>>n;
    // while(i<=n){
    //     int j=n;
    //     // int count=
    //     while(j>=i){
    //         cout<<i;
    //         j=j-1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    //(9)
    /*              1
                    22
                    333
                    4444
    */
    // int i=1,n;
    // cout<<"enter a no"<<endl;
    // cin>>n;
    // int count=1;
    // while(i<=n){
    //     int j=1;

    //     // int count=
    //     while(j<=i){
    //         cout<<count<<" ";
    //         count=count+1;
    //         j=j+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    //(10) imp
    /*              1
                    23
                    345
                    4567
    */
    // int i=1,n;
    // cout<<"enter a no"<<endl;
    // cin>>n;
    // while(i<=n){
    //     int j=1;
    //     int value=i;
    //     while(j<=i){
    //         cout<<value<<" ";
    //         j=j+1;
    //         value=value+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    // or (without value variable)

    // int i=1,n;
    // cout<<"enter a no"<<endl;
    // cin>>n;
    // while(i<=n){
    //     int j=1;
    //     while(j<=i){
    //         cout<<i+j-1;  // Important step
    //         j=j+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    //(11) imp
    /*              1
                    21
                    321
                    4321
    */
    // int i=1,n;
    // cout<<"enter a no"<<endl;
    // cin>>n;
    // while(i<=n){
    //     int j=1;
    //     int count=i;
    //     while(j<=i){
    //         cout<<count<<" ";
    //         count=count-1;
    //         j=j+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    // or (without variable value)
    //  int i=1,n;
    //  cout<<"enter a no"<<endl;
    //  cin>>n;
    //  while(i<=n){
    //      int j=1;
    //      while(j<=i){
    //          cout<<i-j+1<<" ";  // Important step
    //          j=j+1;
    //      }
    //      cout<<endl;
    //      i=i+1;
    //  }

    //(12)
    /*              A A A
                    B B B
                    C C C
    */
    // int i = 1, n;
    // cout << "enter a no" << endl;
    // cin >> n;
    // while (i <= n)
    // {
    //     int j = 1;

    //     while (j <= n)
    //     {
    //         char x = 'A';
    //         char a = x + i - 1;
    //         cout << a << " ";
    //         j = j + 1;
    //     }
    //     cout << endl;
    //     i = i + 1;
    // }

    //(13)
    /*              A B C
                    A B C
                    A B C
    */
    // int i = 1, n;
    // cout << "enter a no" << endl;
    // cin >> n;
    // while (i <= n)
    // {
    //     int j = 1;
    //     char x = 'A';
    //     while (j <= n)
    //     {
    //         cout << x << " ";
    //         x=x+1;
    //         j = j + 1;
    //     }
    //     cout << endl;
    //     i = i + 1;
    // }

    // or
    //  int i = 1, n;
    //  cout << "enter a no" << endl;
    //  cin >> n;
    //  while (i <= n)
    //  {
    //      int j = 1;
    //      char x = 'A';
    //      while (j <= n)
    //      {
    //          char y=x +j-1;
    //          cout <<y<< " ";
    //          j = j + 1;
    //      }
    //      cout << endl;
    //      i = i + 1;
    //  }

    //(14)
    /*
                    A B C D
                    E F G H
                    I J K L
                    M N O P
    */
    // int i = 1, n;
    // cout << "enter a no" << endl;
    // cin >> n;
    // char x = 'A';
    // while (i <= n)
    // {
    //     int j = 1;

    //     while (j <= n)
    //     {
    //         cout <<x<< " ";
    //         x=x+1;
    //         j = j + 1;
    //     }
    //     cout << endl;
    //     i = i + 1;
    // }

    //(15) v. v. imp
    /*
                    A B C D
                    B C D E
                    C D E F
                    D E F G
    */
    // int i = 1, n;
    // cout << "enter a no" << endl;
    // cin >> n;
    // char x = 'A';
    // while (i <= n)
    // {
    //     int j = 1;

    //     while (j <= n)
    //     {
    //         char a=x+i+j-2;  // Important step
    //         cout <<a<< " ";
    //         j = j + 1;
    //     }
    //     cout << endl;
    //     i = i + 1;
    // }

    //(16)
    /*
                    A
                    B B
                    C C C
    */
    // int i = 1, n;
    // cout << "enter a no" << endl;
    // cin >> n;
    // char x = 'A';
    // while (i <= n)
    // {
    //     int j = 1;

    //     while (j <= i)
    //     {

    //         cout <<x<< " ";

    //         j = j + 1;
    //     }
    //     x=x+1;
    //     cout << endl;
    //     i = i + 1;
    // }

    // or
    // int i = 1, n;
    // cout << "enter a no" << endl;
    // cin >> n;
    // char a = 'A';
    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         char b = a + i - 1;
    //         cout << b;
    //         j = j + 1;
    //     }
    //     cout << endl;
    //     i = i + 1;
    // }

    //(17)
    /*
                    A
                    B C
                    D E F
    */
    // int i = 1, n;
    // cout << "enter a no" << endl;
    // cin >> n;
    // char a = 'A';
    // while (i <= n)
    // {
    //     int j = 1;
    //     while (j <= i)
    //     {
    //         cout<<a;
    //         a=a+1;
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i = i + 1;
    // }

    //(18) imp
    /*
                    A
                    B C
                    C D E
    */
    // int i = 1, n;
    // cout << "enter a no" << endl;
    // cin >> n;
    // char a = 'A';
    // while (i <= n)
    // {
    //     int j = 1;

    //     while (j <= i)
    //     {
    //         char ch=a+i+j-2;
    //         cout<<ch;
    //         j=j+1;
    //     }
    //     // a=a+1;
    //     cout << endl;
    //     i = i + 1;
    // }

    //(19) imp
    /*
                    D
                    C D
                    B C D
                    A B C D
    */
    // int i = 1, n;
    // cout << "enter a no" << endl;
    // cin >> n;
    // char a = 'D';
    // while (i <= n)
    // {
    //     int j = 1;

    //     while (j <= i)
    //     {
    //         char ch=a-i+j;
    //         cout<<ch;
    //         j=j+1;
    //     }
    //     cout << endl;
    //     i = i + 1;
    // }

    // or
    //  int i = 1, n;
    //  cout << "enter a no" << endl;
    //  cin >> n;
    //  char a = 'A';
    //  while (i <= n)
    //  {
    //      int j = 1;
    //      char ch=a+n-i;
    //      while (j <= i)
    //      {
    //          cout<<ch;
    //          ch=ch+1;
    //          j=j+1;
    //      }
    //      cout << endl;
    //      i = i + 1;
    //  }

    // or(using 'A'+i+j-2 formula video-timeline:47:20)

    // int i = 1, n;
    // cout<<"enter a no"<<endl;
    // cin >> n;
    // while (i<=n)
    // {

    //     int j = 4;
    //     while (j <n)
    //     {
    //         cout<<"*";

    //         j = j - 1;
    //     }
    //     cout << endl;
    //     i=i+1;
    // }

    // (19) imp
    /*          ___*
                --**
                -***
                ****
  */
    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){
    //     int space=n-i;
    //     while(space){
    //         cout<<"_"<<" ";
    //         space=space-1;
    //     }
    //     int col=1;
    //     while(col<=i){
    //         cout<<"*";
    //         col=col+1;

    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    //(20)
    /*              ****
                    _***
                    __**
                    ___*
    */
    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){
    //     int space=1;
    //     while(i-space){
    //         cout<<"_";
    //         space=space+1;
    //     }
    //     int star=n-i+1;
    //     while(star){
    //         cout<<"*";
    //         star=star-1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    // solve the above question using i-1

    // (21)
    /*
                    1111
                    _222
                    __33
                    ___4
    */

    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){
    //     int space=1;
    //     while(i-space){
    //         cout<<"_";
    //         space=space+1;
    //     }
    //     int init=n-i+1;
    //     while(init){
    //         cout<<i;
    //         init=init-1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    //(22)
    /*              ___1
                    __22
                    _333
                    4444
    */
    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){
    //     int space=n-i;
    //     while(space){
    //         cout<<"_";
    //         space=space-1;
    //     }
    //     int init=1;
    //     while(init<=i){
    //         cout<<i;
    //         init=init+1;
    //     }
    //     cout<<endl;
    //     i=i+1;
    // }

    // (23) imp
    /*
                    1234
                    _234
                    __34
                    ___4
    */
    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){

    //     int space=1;
    //     while(i-space){
    //         cout<<"_";
    //         space=space+1;
    //     }

    //     int j=1 ;
    //     int init=i;
    //     while(j<=n-i+1){
    //         cout<<init;
    //         init=init+1;
    //         j=j+1;
    //     }

    //     cout<<endl;
    //     i=i+1;
    // }

    // (24) imp
    /*                  ___1
                        __23
                        _345
                        4567
        */
    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){

    //     int space=n-i;
    //     while(space){
    //         cout<<"_";
    //         space=space-1;
    //     }

    //     int j=1;
    //     int value=i;
    //     while(j<=i){
    //         cout<<value;
    //         value=value+1;
    //         j=j+1;
    //     }

    //     cout<<endl;
    //     i=i+1;
    // }

    // (25) v. v. imp
    /*
                    ___1
                    __121
                    _12321
                    1234321
    */
    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){

    //     int space=n-i;
    //     while(space){
    //         cout<<"_";
    //         space=space-1;
    //     }

    //     int j=1;
    //     // int value=1;
    //     while(j<=i){
    //         cout<<j;
    //         // value=value+1;
    //         j=j+1;
    //     }

    //     int init=i-1;
    //     while(init){
    //         cout<<init;
    //         init=init-1;
    //     }

    //     cout<<endl;
    //     i=i+1;
    // }

    // (26)
    /*
                    12345**12345
                    1234****1234
                    123******123
                    12********12
                    1**********1
     */
    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){

    //     int j=1;
    //     // int value=1;
    //     while(j<=n-i+1){
    //         cout<<j;
    //         // value=value+1;
    //         j=j+1;
    //     }

    //     int space=1;
    //     while(space<=i){
    //         cout<<"*";
    //         space=space+1;
    //     }

    //     int k=1;
    //     while(k<=i){
    //         cout<<"*";
    //         k=k+1;
    //     }

    //     int j1=1;
    //     // int value=1;
    //     while(j1<=n-i+1){
    //         cout<<j1;
    //         // value=value+1;
    //         j1=j1+1;
    //     }

    //     cout<<endl;
    //     i=i+1;
    // }

    // (27)
    /*
                    12345**54321
                    1234****4321
                    123******321
                    12********21
                    1**********1
     */
    int n;
    cin>>n;
    int i=1;
    while(i<=n){

        int j=1;
        // int value=1;
        while(j<=n-i+1){
            cout<<j;
            // value=value+1;
            j=j+1;
        }

        int space=1;
        while(space<=i){
            cout<<"*";
            space=space+1;
        }

        int k=1;
        while(k<=i){
            cout<<"*";
            k=k+1;
        }

        int j1=5;
        // int value=1;
        while(j1>=i){
            cout<<j1-i+1;
            // value=value+1;
            j1=j1-1;
        }

        cout<<endl;
        i=i+1;
    }

    // (28) most & v. v. imp
    /*

                    1234554321
                    1234**4321
                    123****321
                    12******21
                    1********1

    */
    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){

    //     int j=1;
    //     // int value=1;
    //     while(j<=n-i+1){
    //         cout<<j;
    //         // value=value+1;
    //         j=j+1;
    //     }

    //     int space=1;
    //     while(space<=i-1){
    //         cout<<"*";
    //         space=space+1;
    //     }

    //     int space2=1;
    //     while(space2<=i-1){
    //         cout<<"*";
    //         space2=space2+1;
    //     }

    //     int j1=n-i+1;
    //     while(j1>=1){
    //         cout<<j1;
    //         j1=j1-1;
    //     }

    //     cout<<endl;
    //     i=i+1;
    // }

    return 0;
}