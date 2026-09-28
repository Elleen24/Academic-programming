#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> merge1(vector<string> &a, vector<string> &b)
{
  vector<string> c;
  int i = 0, j = 0;

  while (i != a.size() && j != b.size())
  {
    if (a[i] < b[j])
    {
      c.push_back(a[i]);in
      i++;
    }
    else
    {
      c.push_back(b[j]);
      j++;
    }
  }

  while (j < b.size())
  {
    c.push_back(b[j]);
    j++;
  }

  while (i < a.size())
  {
    c.push_back(a[i]);
    i++;
  }

  return c;
}

vector<string> mergeSort(vector<string> &a, int l, int h)
{
  if (l == h)
  {
    return {a[l]};
  }

  int mid = (l + h) / 2;
  vector<string> v1 = mergeSort(a, l, mid);
  vector<string> v2 = mergeSort(a, mid + 1, h);

  return merge1(v1, v2);
}

int main()
{
  int n;
  cin>>n;
  vector<string> word(n);
  for(int i = 0 ;  i<n ;i++)
  {
    cin>>word[i];
  }

  word = mergeSort(word, 0, word.size() - 1);
  cout<<endl;
  cout<<endl;
  for (auto &u : word)
  {
    cout << u << "\n";
  }

  return 0;
}