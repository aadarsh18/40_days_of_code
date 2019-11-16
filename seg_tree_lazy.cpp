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
    return;
    if(srt==end)
    {
        tree[index]=a[srt];
        return;
    }
    ll mid;
    mid=(srt+end)/2;
    build(tree,a,srt,mid,2*index);
    build(tree,a,mid+1,end,2*index+1);
    tree[index]=max(tree[2*index],tree[2*index+1]);
}
ll query(ll *tree,ll *lazy,ll srt,ll end,ll qs,ll qe,ll index)
{
    if(srt>qe||end<qs||srt>end)
    return -100000000;
    if(srt>=qs&&end<=qe)
    {
        return tree[index];
    }
    if(lazy[index]!=0)
    {
        tree[index]+=lazy[index];
        if(srt!=end)
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    ll left,right;
    ll mid;
    mid=(srt+end)/2;
    left=query(tree,lazy,srt,mid,qs,qe,2*index);
    right=query(tree,lazy,mid+1,end,qs,qe,2*index+1);
    return max(left,right);
}
void update(ll *tree,ll *lazy,ll srt,ll end,ll qs,ll qe,ll val,ll index)
{
    if(lazy[index]!=0)
    {
        tree[index]+=lazy[index];
        if(srt!=end)
        {
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(srt>end||srt>qe||end<qs)
    {
        return;
    }
    if(srt>=qs&&end<=qe)
    {
        tree[index]+=val;
        if(srt!=end)
        {
            lazy[2*index]+=val;
            lazy[2*index+1]+=val;
        }
        return;
    }
    ll mid;
    mid=(srt+end)/2;
    update(tree,lazy,srt,mid,qs,qe,val,2*index);
    update(tree,lazy,mid+1,end,qs,qe,val,2*index+1);
    tree[index]=max(tree[2*index],tree[2*index+1]);
}
int main()
 {
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);
     int n;
     cin>>n;
     ll arr[n],i;
     for(i=0;i<n;i++)
     {
         cin>>arr[i];
     }
    ll *tree=new ll[4*n+1];
     ll lazy[4*n+1]={0};
     build(tree,arr,0,n-1,1);
     ll q;
     cin>>q;
     ll w,x,y,z,num;
     for(i=1;i<=q;i++)
     {
         cin>>w;
         if(w==0)
         {
             cin>>x>>y>>z;
            update(tree,lazy,0,n-1,x,y,z,1);
         }
         else
         {
             cin>>x>>y;
            num=query(tree,lazy,0,n-1,x,y,1);
             cout<<num<<endl;
         }
     }
     return 0;
 }
