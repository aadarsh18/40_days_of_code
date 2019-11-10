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
    vector<bool>arr(100000000,true);
    long long int i,j;
    arr[1]=false;
    for(i=2;i<=sqrt(100000000);i++)
    {
        if(arr[i]==true)
        {
            for(j=i*i;j<=100000000;j=j+i)
            {
                arr[j]=false;
            }
        }
    }
    for(i=1;i<=100;i++)
    {
        if(arr[i]==true)
        cout<<i<<" ";
      
    }
	return 0;
}
