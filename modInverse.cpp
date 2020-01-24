#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll modular(ll a,ll b,ll m)
{
    if(a==0)
    return 0;
    if(b==0)
    return 1;
    ll ans;
    if(b%2==0)
    {
        ans=modular(a,b/2,m);
        ans=(ans*ans)%m;
    }
    else
    {
        ans=a%m;
        ans=(ans*modular(a,b-1,m)%m)%m;
    }
    return (ans+m)%m;
}
ll modInverse(ll a,ll b)
{
	return modular(a,b-2,b);
}
int main() 
{ 
	     ll a,m;
	     cin>>a>>m;
     	 cout<<modInverse(a, m); 
	     return 0; 
} 
