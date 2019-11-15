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
struct Node
{
    ll s;
    ll d;
    ll w;
};
struct comp
{
    bool operator()(Node const& a,Node const& b)
    {
        return a.w>b.w;
    }
};
ll root(ll A[],ll i)
{
    while(A[i]!=i)
    {
        A[i]=A[A[i]];
        i=A[i];
    }
    return i;
}
void unionn(ll arr[],ll size[],ll a,ll b)
{
    ll root_a=root(arr,a);
    ll root_b=root(arr,b);
    if(size[root_a]<size[root_b])
    {
        arr[root_a]=arr[root_b];
        size[root_b]+=size[root_a];
    }
    else
    {
        arr[root_b]=arr[root_a];
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
     ll n,m;
     cin>>n>>m;
     ll A[n+5],size[n+5],vis[n+5];
     ll i;
     for(i=1;i<=n;i++)
     {
         A[i]=i;
         size[i]=1;
         vis[i]=0;
     }
     vector<Node>MST;
     priority_queue<Node, vector<Node>, comp>pq;
     ll x,y,val;
     Node z;
     for(i=1;i<=m;i++)
     {
         cin>>x>>y>>val;
         z.s=x;
         z.d=y;
         z.w=val;
         pq.push(z);
     }
     //cout<<pq.size()<<endl;
     while(MST.size()<n-1)
     {
         z=pq.top();
         x=z.s;
         y=z.d;
         pq.pop();
         
         if(!find(A,x,y))
         {
            unionn(A,size,x,y);
            MST.pb(z);
         }
     } 
     ll sum=0;
     for(i=0;i<MST.size();i++)
     {
         sum+=MST[i].w;
     }
     cout<<sum;
     return 0;
 }
