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

int main()
{
 ll n,m;
 cin>>n>>m;
 ll graph[n+1][n+1][n+1];
 ll i,j,k;
 for(i=1;i<=n;i++)
 {
     for(j=1;j<=n;j++)
     {
         graph[i][j][0]=1000;
         if(i==j)
         {
             graph[i][j][0]=0;
         }
     }
 }
 ll x,y,w;
 for(i=0;i<m;i++)
 {
     cin>>x>>y>>w;
     graph[x][y][0]=w;
 }
  for(k=1;k<=n;k++)
  {
      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
          {
              graph[i][j][k]=min(graph[i][j][k-1],graph[i][k][k-1]+graph[k][j][k-1]);
          }
      }
  }
  for(i=1;i<=n;i++)
  {
      for(j=1;j<=n;j++)
      {
          cout<<graph[i][j][n]<<" ";
      }
      cout<<endl;
  }
return 0;
}
