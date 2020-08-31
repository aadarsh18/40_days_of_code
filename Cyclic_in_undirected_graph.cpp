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



USING BFS 

#include <bits/stdc++.h>
using namespace std;
#define ll  long long  int
#define mod 1000000007
#define pb push_back
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
bool comp(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 
ll f=0;
void bfs(vector<ll>vtr[],ll s,ll vis[],ll n)
{
      queue<ll>q;
      q.push(s);
      vis[s]=1;
      ll par[n+5];
      ll i;
      for(i=0;i<=n;i++)
         par[i]=-1;
    while(!q.empty())
    {
        ll z=q.front();
        q.pop();
        for(i=0;i<vtr[z].size();i++)
        {
            ll num=vtr[z][i];
            if(vis[num]==0)
            {
                 vis[num]=1;
                 par[num]=z;
                 q.push(num);
            }
            else if(par[z]!=num)
              f=1;
        }
    }
}
  void solve()
  {
      ll n,m;
      cin>>n>>m;
      ll x,y;
     vector<ll>vtr[n+5];
      ll i;
      for(i=0;i<m;i++)
      {
          cin>>x>>y;
          vtr[x].push_back(y);
          vtr[y].push_back(x);
      }
      
    ll vis[n+2]={0};
   
    for(i=0;i<=n;i++)
      vis[i]=0;
   for(i=1;i<=n;i++)
   {
    if(vis[i]==0)
      {
        bfs(vtr,i,vis,n);
      }
   }
    if(f)
      cout<<"NO";
    else
      cout<<"YES";
  }
int main()
{
    fast();
    solve();
    return 0;
}
