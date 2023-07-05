/* Contents
(1) Finding Pivot element from rotated and sorted array
(2) Searching a pivot element(given) from rotated and sorted array
(3) Square root
*/

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

int pivot_element(int arr[], int n)
{
    int l = 0, r = n - 1;
    int mid = l + (r - l) / 2;
    while (l < r)
    {

        if (arr[mid] >= arr[0])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
        mid = l + (r - l) / 2;
    }
    return l;
}

int rotated_search(int arr[], int n, int key)
{
    int l = 0, r = n - 1;
    int mid = l + (r - l) / 2;

    while (l <= r)
    {
        if (arr[mid] == key)
            return mid;

        // left sorted
        if (arr[l] <= arr[mid])
        {
            if (key >= arr[l] && key <= arr[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        // right sorted
        else
        {
            if (key <= arr[r] && key > arr[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        mid = l + (r - l) / 2;
    }

    return -1;
}

//or

int sqrt(int x)
{
    int l = 0;
    int r = x;
    long long int mid = l + (r - l) / 2;
    int ans = -1;
    while (l <= r)
    {
        long long int sq = mid * mid;
        if (sq == x)
            return mid;
        if (sq > x)
        {

            r = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid + 1;
        }
        mid = l + (r - l) / 2;
    }

    return ans;
}

//merge two sorted arrays
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    
}

double moreprecision(int n, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int matrix_search()
{
    vector<vector<int>> matrix;
    matrix = {
        {1, 2, 3},
        {5, 6, 7},
        {10, 11, 12}};
    // int m=3,n=3;
    int target = 8;

    int n = matrix.size();
    int m = matrix[0].size();
    int l = 0, r = m * n - 1;
    int mid = l + (r - l) / 2;
    while (l != r)
    {
        if (matrix[mid / m][mid % m] < target)
            l = mid + 1;
        else
            r = mid;
        mid = l + (r - l) / 2;
    }
    int sol = (matrix[mid / m][mid % m] == target);

    if (sol)
    {
        cout << "Present";
    }
    else
    {
        cout << "absent";
    }
}

bool isPossible(vector<int> &arr, int n, int m, int inx)
{
    int studentCount = 1;
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        if (sum + arr[i] <= inx)
        {
            sum = sum + arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > inx)
            {
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}

void selection_sort(vector<int> &arr, int n)
{

    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(arr[min], arr[i]);
    }

    // in descending order
    // vector<int> arr{3,6,1,8,2};
    // for(int i=arr.size()-1;i>0;i--){
    //     int min=i;
    //     for (int j = i-1; j >=0; j--)
    //     {
    //         if(arr[j]<arr[min]){
    //             min=j;
    //         }
    //     }

    //     swap(arr[min],arr[i]);
    // }

    cout << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSort(vector<int> &arr, int n)
{
    // The most optimized answer
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        { // j<n-i
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }

    // for(int i=0;i<n-1;i++){
    //     int first=i;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[first]>arr[j]){
    //             swap(arr[first],arr[j]);
    //         }
    //     }
    // }

    // for(int i=1;i<n;i++){
    //     for(int j=0;j<n-1;j++){ // j<n-1
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j+1],arr[j]);
    //         }
    //     }
    // }
}

//Sum Of Two Arrays code studio
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
    vector<int> ans;
	int i=n-1;
    int j=m-1;
    int carry=0;

    //Solution 1
    //overlapping part
    // while(i>=0 && j>=0){
    //     int sum=a[i]+b[j]+carry;

    //     carry=sum/10;
    //     sum=sum%10;
    //     ans.push_back(sum);
    //     i--;
    //     j--;

    // }
    // //if size a(i) is > than b(j) size
    // while(i>=0){
    //     int sum=a[i]+carry;
    //     carry=sum/10;
    //     sum=sum%10;
    //     ans.push_back(sum);
    //     i--;
    // }
    // //if size a(i) is < than b(j) size
    // while(j>=0){
    //     int sum=b[j]+carry;
    //     carry=sum/10;
    //     sum=sum%10;
    //     ans.push_back(sum);
    //     j--;
    // }
    // cout<<"carry: "<<carry<<endl;
    // //if size a(i) is == than b(j) size
    // while(carry!=0){
    //     int sum=carry;
    //     carry=sum/10;
    //     // sum=sum%10;
    //     ans.push_back(sum);
    // }


    //Solution 2
    while(i>=0 || j>=0 || carry!=0){
        
        //because i or j can be negative and can give garbage value for 
        //example if j=-1 then b[j] i.e., b[-1]=7867878
        int val1 = 0;
        if(i >= 0)
            val1 = a[i];
        
        int val2 = 0;
        if(j >= 0)
            val2 = b[j];
        
        
        int sum = val1 + val2 + carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        if(i>=0){
            i--;
        }
        if(j>=0){
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int string_compression(vector<char> ch)
{
    // vector<char> ch{'a', 'a', 'b', 'b','c','c','c'};
    int i = 0;
    int charindex = 0;
    int n = ch.size();
    while (i < n)
    {
        int j = i + 1;
        while (j < n && ch[i] == ch[j])
        {
            j++;
        }

        ch[charindex++] = ch[i];
        int count = j - i;

        if (count > 1)
        {
            string cnt = to_string(count);
            for (char c : cnt)
            {
                ch[charindex++] = c;
            }
        }
        i = j;
    }
    for (char c : ch)
    {
        cout << c << " ";
    }
    cout << endl;
    return charindex;
}

string removeDuplicates(string str)
{
    int n = str.size();

    stack<char> st;

    for (int i = 0; i < n; i++)
    {

        bool flag = true;

        if (st.empty() == false && st.top() == str[i])
        {
            flag = false;

            st.pop();
        }

        if (flag)
        {
            st.push(str[i]);
        }
    }

    string res = "";

    while (!st.empty())
    {
        res += st.top();

        st.pop();
    }

    reverse(res.begin(), res.end());

    return res;

    // or
    //  string ans="";

    // ans.push_back(str[0]);

    // for(int i=1;i<str.length();i++)
    // {
    //     if(str[i]==ans.back())
    //     {
    //         ans.pop_back();
    //     }
    //     else
    //     {
    //         ans.push_back(str[i]);
    //     }
    // }
    // return ans;
}

// arr -> matrix index relationship
// arr[m*i+j]=matrix[i][j];
// m = no of column, i = row, j = column
// example -
// arr[4]=arr[3*1+1]=matrix[1][1]
int search_2d(vector<vector<int>> matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int l = 0, r = m * n - 1;
    int mid = l + (r - l) / 2;
    while (l != r)
    {
        if (matrix[mid / m][mid % m] < target)
            l = mid + 1;
        else
            r = mid;
        mid = l + (r - l) / 2;
    }
    int sol = (matrix[mid / m][mid % m] == target);
    if (sol)
    {
        cout << "Target is present" << endl;
    }
    else
    {
        cout << "Target is not present" << endl;
    }
    return sol;
}

void rotate(vector<vector<int>> &matrix)
{
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void kadanes_algo(vector<int>& nums){
    int i=0,end;
    int max_end_here=0,max_so_far=INT_MIN;
    while(i<nums.size()){
        max_end_here=max_end_here+nums[i];
        if(max_end_here>max_so_far ){
            max_so_far=max_end_here;
            end=i;    
        }
        if(max_end_here<0){
            max_end_here=0;  
        }
        i++;
    }

    int maxi=max_so_far;
    int start=end;

    while(start>=0){
        max_so_far-=nums[start];
        if(max_so_far==0){
            break;
        }
        start--;
    }

    std::cout<<endl;
    std::cout<<"And the largest contiguous subarray sum is: -"<<endl;
    std::cout<<maxi<<endl;

    std::cout<<"The Array with largest contiguous subarray sum is: "<<endl;
    for(int i=start;i<=end;i++){
        std::cout<<nums[i]<<" ";

    }

}

//subsets using recursion
void subsets(vector<int>& nums,int i,vector<vector<int>>& ans,vector<int> temp){
    if(i>=nums.size()){
        ans.push_back(temp);
        return ;
    }
    
    //exclude
    subsets(nums,i+1,ans,temp);
    //include
    temp.push_back(nums[i]);
    subsets(nums,i+1,ans,temp);
        
}
int main()
{

    //Bubble sort
    // vector<int> arr{46,27,12,5,33,6};
    // bubbleSort(arr,arr.size());
    // for(auto i:arr){
    //     cout<<i<<" ";
    // }

    // cout << "execution started" << endl;
    // int arr[] = {8, 10, 17, 1, 3};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // cout << pivot_element(arr, n) << endl;
    // cout << "execution comleted";

    // int arr[] = {3,8,10,17,1}; // original array -> {20,30,40,50,60,90,100}
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int key = 3;
    // int ans = rotated_search(arr, n, key);
    // cout << ans << endl;
    // cout << "ans";

    // sqrt
    //  int n=37;
    //  int tempSol=sqrt(n);
    //  cout<<tempSol;
    //  cout<<moreprecision(n,3,tempSol);

    // Allocate Books, Painters Partition, Aggressive Cows
    // vector<int> arr{30,10,20,40};
    // int n=4,m=2;
    // int s=0;
    // int e=100;
    // int ans=-1;
    // int mid=s+(e-s)/2;
    // while(s<=e){
    //     if(isPossible(arr,n,m,mid)){
    //         ans=mid;
    //         e=mid-1;

    //     }
    //     else{
    //         s=mid+1;
    //     }
    //     mid=s+(e-s)/2;
    // }
    // cout<<ans;
    

    // selection sort
    // vector<int> arr{46,27,12,5,33,6};
    // selection_sort(arr,arr.size());
    // cout<<endl;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    // Remove all occurences of a sub string
    // string str1 = "eidbaooo";
    // string str2 = "ab";
    // while (str1.length() != 0 && str1.find(str2) < str1.length())
    // {
    //     str1.erase(str1.find(str2), str2.length());
    // }
    // cout << str1;

    // 151. Reverse Words in a String
    // string str = "Deependra Par";
    // stringstream s(str);
    // string words;
    // vector<string> temp;
    // while (s >> words)
    // {
    //     temp.push_back(words);
    // }
    // string ans = "";
    // for (int i = temp.size() - 1; i >= 0; i--)
    // {
    //     if (i != 0)
    //     {
    //         ans = ans + temp[i] + " ";
    //     }
    //     else
    //     {
    //         ans = ans + temp[i] + "";
    //     }
    // }
    // cout << ans;

    // String Compression
    // vector<char> ch{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    // string_compression(ch);

    // Remove all adjacent duplicates from a given string
    // string s = "abbaca";
    // string ans = removeDuplicates(s);
    // cout << ans;

    // 74. Search a 2D Matrix
    // vector<vector<int>> matrix{{1, 2, 3},
    //                            {4, 5, 6},
    //                            {7, 8, 9}};
    // int target = 8;
    // int idx = search_2d(matrix, target);
    // cout << idx;

    // 48. Rotate Image
    // vector<vector<int>> matrix{{1, 2, 3},
    //                            {4, 5, 6},
    //                            {7, 8, 9}};
    // rotate(matrix);
    

    //88. Merge Sorted Array
    // vector<int> nums1={0,1,2,0,0,0};
    // vector<int> nums2={2,5,6};
    // int m=nums1.size();
    // int n=nums2.size();
    // merge(nums1, m, nums2, n);

    //move zeros
    // int arr[]={0,1,0,0,3,4};
    // int n=sizeof(arr)/sizeof(arr[0]);
    // int i=0,j=0;
    // while(j<n){
    //     if(arr[j]!=0){
    //         swap(arr[i],arr[j]);
    //         i++;
    //     }
    //     j++;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    

    //Kadane's Algorithm
    // vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    // kadanes_algo(nums);

    //Sum Of Two Arrays code studio
    // vector<int> a={4 ,5 ,1};
    // vector<int> b={5};
    // int n=a.size(),m=b.size();
    // vector<int> temp=findArraySum(a, n, b, m);
    // for(auto i:temp){
    //     cout<<i<<" ";
    // }

    //subsets
    vector<int> ques{1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    
    subsets(ques,0,ans,temp);
    cout<<"hi";
    //print
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
