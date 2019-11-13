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

int main() 
{
    ll n,m;
    cin>>n>>m;
    ll graph[n][3];
    ll i,x,y,z;
    ll dis[n+10];
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        graph[i][0]=x;
        graph[i][1]=y;
        graph[i][2]=z;
    }
    for(i=0;i<=n;i++)
    {
        dis[i]=1e10;
    }
    ll j;
    dis[1]=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<m;j++)
        {
            if(dis[graph[j][0]]+graph[j][2]<dis[graph[j][1]])
            {
                dis[graph[j][1]]=graph[j][2]+dis[graph[j][0]];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
	return 0;
}
