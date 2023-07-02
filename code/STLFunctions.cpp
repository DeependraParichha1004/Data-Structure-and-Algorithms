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
void printvec(vector<vector<int>> vec){
    for(int i=0;i<vec.size();i++){
        for(auto it=vec[i].begin();it!=vec[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

void TBReverse(vector<vector<int>>& vec){
    for(auto mat:vec) reverse(mat.begin(),mat.end());
}


void BTReverse(vector<vector<int>>& vec){
    reverse(vec.begin(),vec.end());
}
int main(){
    vector<vector<int>> vec={{1,2,3},
                              {4,5,6},
                              {7,8,9}};

    //bottom to top reverse                          
    // BTReverse(vec);

    //top to bottom reverse
    TBReverse(vec);
    printvec(vec);
    
    return 0; 
}