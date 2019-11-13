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
ll modInverse(ll a, ll m) 
{ 
	ll m0 = m; 
	ll y = 0, x = 1; 
	if (m == 1) 
	return 0; 
	while (a > 1) 
	{ 
		ll q = a / m; 
		ll t = m; 
		m = a % m, a = t; 
		t = y; 
		y = x - q * y; 
		x = t; 
	} 
	if (x < 0) 
	x += m0; 
	return x; 
} 
int main() 
{ 
	     ll a,m;
	     cin>>a>>m;
     	 cout<<modInverse(a, m); 
	     return 0; 
} 
