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
#define pb push_back
#define pf push_front
#define M 1000000007
#define ll long long int
vector<ll>Gph[1000000];
ll cnt=0,flag=0;

void DFS(ll p ,ll s,ll  vis[],ll start[],ll end[])
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
          DFS(s,it,vis,start,end);
          }
          else if(vis[i]==1&&it!=p)
          {
              flag=1;
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
     ll start[n+5],end[n+5],i,vis[n+5];
     ll x,y;
     for(i=0;i<m;i++)
     {
         cin>>x>>y;
         Gph[x].pb(y);
         Gph[y].pb(x);
     }
     for(i=0;i<=n;i++)
     {
         vis[i]=0;
     }
     cnt=0;
     for(i=1;i<=n;i++)
     {
         if(vis[i]==0)
         {
             start[i]=cnt;
             cnt++;
             DFS(i,i,vis,start,end);
         }
     }
     	for(i=1; i<=n; i++)
		cout<<start[i]<<" ";
	cout<<endl;
	for(i=1; i<=n; i++)
		cout<<end[i]<<" ";
	cout<<"\n\n";
	 
      if(flag==1)
      cout<<"cyclic";
      else
      cout<<"non cyclic";
     return 0;
 }
