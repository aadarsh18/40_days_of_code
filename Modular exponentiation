#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define mod 1000000007

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
int main() 
{
	ll a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	ll z;
	z=modular(a,b,c);
	cout<<z;
	return 0;
}
