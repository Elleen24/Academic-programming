#include <bits/stdc++.h>
using namespace std;
vector<int> merge1(vector<int>a, vector<int>b )
{
    vector<int>c;
    int i =0,j=0;
    while(i!=a.size()&&j!=b.size())
    {
      if(a[i]<b[j])
      {
        c.push_back(a[i]);
        i++;
      }
      else
      {
        c.push_back(b[j]);
        j++;
      }
    }
    if(c.size()==a.size()+b.size())
    {
      return c;
    }
    if(i==a.size())
    {
      for(j;j<b.size();j++)
      {
        c.push_back(b[j]);
      }
    }
    else
    {
      for(i;i<a.size();i++)
      {
        c.push_back(a[i]);
      }
    }
    return c;
}
vector<int>mergeSort(vector<vector<int>>&a,int l, int h)
{
  if(l==h)
  {
    vector<vector<int>>v1;
    v1.push_back(a[l]);
    return v1[0];
  }
  int mid = (l+h)/2;
  vector<int>v1 = mergeSort(a,l,mid);
  vector<int>v2 = mergeSort(a,mid+1,h);
  return merge1(v1,v2);
}
int main()
{
  vector<vector<int>>v = {{1,4,7},{2,5,8},{3,6,9}};
  vector<int>a = mergeSort(v,0,v.size()-1);
  for(auto u : a)
  {
    cout<<u<<" ";
  }
}