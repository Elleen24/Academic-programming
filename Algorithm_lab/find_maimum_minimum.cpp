#include<bits/stdc++.h>
using namespace std;
pair<int,int> findaMaxAndMin(vector<int>v,int l, int h)
{
  if(l==h)
  {
      pair<int,int>p;
      p.first = v[l];
      p.second = v[l];
      return p;
  }
  int mid = (l+h)/2;
  pair<int,int>p;
  p.first = min(findaMaxAndMin(v,l,mid).first,findaMaxAndMin(v,mid+1,h).first);
  p.second = max(findaMaxAndMin(v,l,mid).second,findaMaxAndMin(v,mid+1,h).second);
  return p;
}
int main()
{
  vector<int>v = {7,2,9,4,1,8,3};
  pair<int,int>p = findaMaxAndMin(v,0,v.size()-1);
  cout<<p.first<<" "<<p.second;
}