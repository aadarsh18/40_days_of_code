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
#define pii pair<ll,ll>
#define mp make_pair 
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
void unionfun(ll A[],ll size[],ll a,ll b)
{
    ll root_a,root_b;
    root_a=root(A,a);
    root_b=root(A,b);
    if(size[a]<size[b])
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
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);
     ll n,m,i;
     cin>>n>>m;
     ll arr[n+5],size[n+5];
     for(i=1;i<=n;i++)
     {
         arr[i]=i;
         size[i]=1;
     }
     int z,x,y;
     
     for(i=1;i<=m;i++)
     {
         cin>>z;
         if(z==0)
         {
             cin>>x>>y;
             unionfun(arr,size,x,y);
         }
         else if(z==1)
         {
             cin>>x>>y;   
             if(find(arr,x,y))
             cout<<x<<" and "<<y<<" are in same set"<<endl;
             else
             cout<<x<<" and "<<y<<" are in different set"<<endl;
         }
     }
     return 0;
 }
