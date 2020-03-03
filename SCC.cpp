/* Dynamic Programming C++ implementation of LCS problem */
#include<bits/stdc++.h> 
using namespace std;
#define ll long long int
 #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
ll t=0;
bool vis[100005]={false};
bool inst[100005]={false};
ll low[1000005]={0};
vector<ll>vtr[100005];
stack<ll>stk;
ll tym[100005];
ll e=0,o=0;
  void scc(ll u)
  {
  	ll i;
  	vis[u]=true;
  	inst[u]=true;
  	low[u]=t;
  	tym[u]=t;
  	t++;
  	stk.push(u);
  	for(i=0;i<vtr[u].size();i++)
  	{
  		ll v;
  		v=vtr[u][i];
        if(vis[v]==0)
        {
        	scc(v);
        	low[u]=min(low[u],low[v]);
        }
        else if(inst[v]==true)
        {
              low[u]=min(low[u],tym[v]);
        }
  	}
  	ll temp=0;
  	if(tym[u]==low[u])
  	{
  		while(stk.top()!=u)
  		{
  			inst[stk.top()]=false;
            temp++;
            cout<<stk.top()<<" ";
            stk.pop();
  		}
  		inst[stk.top()]=false;
            temp++;
            cout<<stk.top()<<" ";
            cout<<endl;
            stk.pop();
  	}
  }
int main() 
{ 
	fastio;
	ll n,m;
	cin>>n>>m;
	ll i,x,y;
	for(i=0;i<m;i++)
	{
          cin>>x>>y;
          vtr[x].push_back(y);
	}
    for(i=1;i<=n;i++)
    {
    	if(vis[i]==0)
    	{
    	    scc(i);	
    	}
    }
	return 0; 
} 

