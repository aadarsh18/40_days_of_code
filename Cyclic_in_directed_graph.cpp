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

vector<ll>Gph[1000000];
ll cnt=0;
struct Node
{
    ll u;
    ll v;
};
void DFS(ll s,ll vis[],ll start[],ll end[])
{
    vis[s]=1;
    ll i;
    for(i=0;i<Gph[s].size();i++)
    {
        ll it=Gph[s][i];
        if(vis[it]==0)
        {
            start[it]=cnt;
            cnt++;
            DFS(it,vis,start,end);
        }
    }
    end[s]=cnt;
    cnt++;
}
 int main()
 {
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);
     ll n,m;
     cin>>n>>m;
     ll start[n+5],end[n+5];
     ll vis[n+5],i;
     for(i=1;i<=n;i++)
     {
         vis[i]=0;
     }
     ll x,y;
     Node z;
     vector<Node>edge;
     for(i=0;i<m;i++)
     {
         cin>>x>>y;
         z.u=x;
         z.v=y;
         edge.pb(z);
         Gph[x].pb(y);
     }
     cnt=0;
     for(i=1;i<=n;i++)
     {
         if(vis[i]==0)
         {
           start[i]=cnt;
           cnt++;
           DFS(i,vis,start,end);
         }
     }
     for(i=1; i<=n; i++)
		cout<<start[i]<<" ";
	cout<<endl;
	for(i=1; i<=n; i++)
		cout<<end[i]<<" ";
	cout<<"\n\n";
	ll tx1,tx2,ty1,ty2,flag=0;
     for(i=0;i<m;i++)
     {
         x=edge[i].u;
         y=edge[i].v;
         tx1=start[x];ty1=start[y];
         tx2=end[x];ty2=end[y];
         if(tx1>ty1&&tx2<ty2)
         {
             flag=1;
             break;
         }
     }
     if(flag==0)
     {
         cout<<"non cyclic";
     }
     else
     {
         cout<<"cyclic";
     }
     return 0;
 }
