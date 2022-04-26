#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rp(i, s, e) for (ll i = s; i < e; i++)
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
#define mod 1e9 + 7
#define v vector
#define p pair<ll, ll>

ll countSumSubset(vector<int>arr, int s)
	{
        int n=arr.size();
        ll dp[n+1][s+1];
        memset(dp,0,sizeof(dp));
        rp(i,0,n+1){
            dp[i][0]=1;
        }
        rp(i,1,n+1){
            rp(j,0,s+1){
                if(arr[i-1]<=j){
                   dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
               

        return dp[n][s];
        
	}
int findTargetSumWays(vector<int>&A ,int target) {
    ll sum=0;
    for(auto x:A){
        sum+=x;
    }
    if((target+sum)%2==0)
        return countSumSubset(A,(target+sum)/2);
        else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, w;
    cin >> n>>w;
    vector<int> arr(n);
    rp(i, 0, n)
    {
        cin >> arr[i];
    }

    cout << findTargetSumWays( arr,w) << endl;

    return 0;
}
