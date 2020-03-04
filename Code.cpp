#include <bits/stdc++.h>
using namespace std;
#define ll long long int
/*  
    GIVEN AN ARRAY OF LENGTH N-1 WHICH ARE THE XOR BETWEEN TWO ADJECENT ELEMENT OF ORIGINAL ARRAY . 
    
    FIND THE ORINGINAL ARRAY  OF LENGTH N AND IT IS PERMUTATION OF 1 TO N.
    
    */
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n+5],i;
		for(i=1;i<=n-1;i++)
			cin>>arr[i];
      
	 	ll z=0,y=0,last;
    
		for(i=1;i<=n;i++)
			z=z^i;
       
        for(i=1;i<=n-1;i=i+2)
        {
               y=y^arr[i];
        }
        ll brr[n+5];
        last=y^z;
        brr[n]=last;
        for(i=n-1;i>=1;i--)
        {
        	brr[i]=arr[i]^brr[i+1];
        }
        for(i=1;i<=n;i++)
        	cout<<brr[i]<<" ";
        cout<<endl;
	}
	return 0;
}
