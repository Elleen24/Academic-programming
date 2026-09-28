#include<bits/stdc++.h>
using namespace std;

int find_maximum(vector<int>&arr, int i, int max)
{
    if(i == arr.size())
    {
      return max;
    }
    if(arr[i]>max)
    {
        max = arr[i];
    }
    return find_maximum(arr, i+1, max);
}
int main()
{
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the array: ";
    for(int i = 0 ; i<n ;i++)
    {
        cin>>v[i];
    }
    cout<<find_maximum(v,0, INT_MIN);
    
}