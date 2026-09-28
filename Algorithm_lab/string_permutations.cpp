#include<bits/stdc++.h>
using namespace std;

void generate_permutations(string &s,map<int,int>&index, string &permut, set<string>&res)
{
  int n = s.size();
  if(n == permut.size())
  {
    res.insert(permut);
    return;
  }
  for(int i = 0 ; i<n ; i++)
  {
      if(index[i]==0)
      {
        permut.push_back(s[i]);
        index[i]++;
        generate_permutations(s,index, permut, res);
        permut.pop_back();
        index[i] = 0;
      }
  }
}

int main()
{
  string s;
  cout<<"Enter the string: ";
  cin>>s;
  map<int,int>index;
  string permut;
  set<string>result;
  generate_permutations(s,index,permut, result);
  for(auto u : result)
  {
    cout<<u<<endl;
  }
}