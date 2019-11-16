#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<deque>
#include<iterator>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false);

ll root(ll A[],ll i)
{
    while(A[i]!=i)
    {
        A[i]=A[A[i]];
        i=A[i];
    }
    return i;
}
void unionn(ll A[],ll size[],ll a,ll b)
{
    ll root_a;
    ll root_b;
    root_a=root(A,a);
    root_b=root(A,b);
    if(size[root_a]<size[root_b])
    {
        A[root_a]=A[root_b];
        size[root_b]+=size[root_a];
    }
    else
    {
        A[root_b]=A[root_a];
        size[root_a]+=size[root_b];
    }
}
bool find(ll A[],ll a,ll b)
{
    if(root(A,a)==root(A,b))
    return true;
    else
    return false;
}
int main()
{
 
  ll n,m;
  cin>>n>>m;
  ll size[n+1],arr[n+1];
  ll i,x,y;
  for(i=1;i<=n;i++)
  {
      arr[i]=i;
      size[i]=1;
  }
  for(i=1;i<=m;i++)
  {
      cin>>x>>y;
      unionn(arr,size,x,y);
  }
  ll cnt=0;
  for(i=1;i<=n;i++)
  {
      if(arr[i]==i)
      cnt++;
  }
  cout<<cnt;
return 0;
}
