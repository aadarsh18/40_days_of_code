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

struct  Node
{
    ll u;
    ll v;
};

bool comp(Node const& a,Node const& b)
{
	if(a.u==b.u)
		return a.v<b.v;
	else
		return a.u<b.u;
}
ll tm;
void bridge(ll s,ll p,ll vis[],ll pre[],ll post[],ll A[],vector<ll>vtr[],vector<Node>&edge)
{
	ll i;
	vis[s]=1;
	for(i=0;i<vtr[s].size();i++)
	{
		ll it;
		it=vtr[s][i];
		if(vis[it]==0)
		{
			pre[it]=tm;
			A[it]=tm;
			tm++;
            bridge(it,s,vis,pre,post,A,vtr,edge);
		}
	}
	ll t;
	post[s]=tm;
	tm++;
	for(i=0;i<vtr[s].size();i++)
	{
		ll it;
		it=vtr[s][i];
		if(it!=p)
		{
            t=min(pre[it],A[it]);
            A[s]=min(A[s],t);
		}
	}
	if(A[s]>pre[p])
	{
		Node z;
         z.u=min(s,p);
         z.v=max(s,p);
         if(z.u!=z.v)
         edge.push_back(z);
	}
}
 int main()
 {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t1,t;
   cin>>t;
   for(t1=1;t1<=t;t1++)
   {
   ll n,m;
   cin>>n>>m;
   vector<ll>vtr[100005];
  ll x,y;
  ll i;
  for(i=0;i<m;i++)
  {
  	cin>>x>>y;
  	vtr[x].push_back(y);
  	vtr[y].push_back(x);
  }
  ll vis[100005]={0},pre[n+5],post[n+5],A[n+5];
  vector<Node>edge;
  tm=1;
  tm++;
  pre[1]=1,vis[1]=1,post[1]=1;
  bridge(1,1,vis,pre,post,A,vtr,edge);
  if(edge.size()==0)
  	{
  		cout<<"NO bridge"<<endl;
  	}
  else
    {
    	sort(edge.begin(),edge.end(),comp);
    
    	cout<<edge.size()<<endl;
    	for(i=0;i<edge.size();i++)
    	{
    		cout<<edge[i].u<<" "<<edge[i].v<<endl;
    	}
    }
}
   return 0;
 }
