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

struct comp
{
    bool operator()(const pair<int , int> &a , const pair<int , int> &b)
    {
        return a.first > b.first;
    }
};

 int main()
 {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
    vector<ll>G[n+2];
    vector<ll>cost[n+2];
    ll i,x,y,w,mx=0;
    for(i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        
        G[x].pb(y);
        cost[x].pb(w);
        G[y].pb(x);
        cost[y].pb(w);
    }
 /*   for(i=1; i<=n; i++)
    {
    	cout<<i<<" ";
    	for(int j=0; j<G[i].size(); j++)
    	{
    		cout<<"("<<G[i][j]<<", "<<cost[i][j]<<")   ";
    	}
    	cout<<endl;
    } cout<<endl; */
	 
    ll dist[n+2];
    for(i=1; i<=n; i++)
    {
        dist[i]=1000000000;
    }
    priority_queue<pii, vector<pii>, comp>pq;

    ll source;
    cin>>source;

    dist[1]=0;
    pq.push(mp(0, 1));
    
    while(!pq.empty())
    {
        ll node=pq.top().second;
        pq.pop();
        
        for(i=0; i<G[node].size(); i++)
        {
            ll it=G[node][i];
            if(dist[it]>dist[node]+cost[node][i])
            {
               dist[it]=dist[node]+cost[node][i];
               pq.push(mp(dist[it], it));
            }
        }
    }
    
    // distance from source to other
    for(i=1; i<=n; i++)
    {
        cout<<dist[i]<<" ";
    }
     return 0;
 }

