#include <bits/stdc++.h> 
using namespace std; 
bool compare(int x, int y) 
{ 
    return abs(x) < abs(y); 
}  
int main() 
{ 
    int n;
    cin>>n;
    int arr[n],i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n,compare);
    int y,z;
    int ans=INT_MAX;
    for(i=1;i<n;i++)
    {
           if(abs(arr[i]+arr[i-1])<=ans)
           {
           	y=i-1;
           	z=i;
           	ans=min(ans,abs(arr[i]+arr[i-1]));
           }
     }
     cout<<arr[y]<<" "<<arr[z];
    return 0;  
} 
