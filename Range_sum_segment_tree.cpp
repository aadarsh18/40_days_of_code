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
#define pb push_back
#define pf push_front
#define M 1000000007
#define ll long long int
void build(ll *tree,ll *a,ll srt,ll end,ll index)
{
    if(srt>end)
    return ;
    if(srt==end)
    {
        tree[index]=a[srt];
        return ;
    }
    ll mid;
    mid=(srt+end)/2;
    build(tree,a,srt,mid,2*index);
    build(tree,a,mid+1,end,2*index+1);
    tree[index]=tree[2*index]+tree[2*index+1];
}
ll query(ll *tree,ll srt,ll end,ll qs,ll qe,ll index)
{
    if(qs>end||qe<srt)
    {
        return 0;
    }
    if(srt>=qs&&end<=qe)
    {
        return tree[index];
    }
    ll mid,left,right;
    mid=(srt+end)/2;
    left=query(tree,srt,mid,qs,qe,2*index);
    right=query(tree,mid+1,end,qs,qe,2*index+1);
    return left+right;
}
int main() 
{
	int n;
	cin>>n;
	ll arr[n],i;
	for(i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	ll q;
	cin>>q;
	ll x,y,z;
	ll *tree=new ll[4*n+1];
	build(tree,arr,0,n-1,1);
	for(i=1;i<=q;i++)
	{
	    cin>>x>>y;
	    z=query(tree,0,n-1,x,y,1);
	    cout<<z<<endl;
	}
	return 0;
}
