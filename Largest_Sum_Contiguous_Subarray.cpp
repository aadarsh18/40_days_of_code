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

int main() 
{ 
	      int n;
	      scanf("%d",&n);
	      ll a[n],i;
	   for(i=0;i<n;i++)
	   {
	       scanf("%lld",&a[i]);
	   }
	    ll max=INT_MIN,sum=0;
	    for(i=0;i<n;i++)
	    {
	        sum+=a[i];
	        if(max<sum)
	        max=sum;
	        
	        if(sum<0)
	        sum=0;
	    }
	    printf("%lld",max);
	     return 0; 
} 
