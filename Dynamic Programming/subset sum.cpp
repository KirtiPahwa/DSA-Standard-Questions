#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rp(i,s,e) for (ll i = s; i < e; i++)
#define tc    \
    ll t;    \
    cin >> t; \
    while (t--)
#define mod 1e9 + 7
#define v vector
#define p pair<ll,ll>
bool isSubsetSum(vector<int>arr, int s){
        int n=arr.size();
        int dp[n+1][s+1];
        memset(dp,0,sizeof(dp));
        rp(i,0,n+1){
            dp[i][0]=1;
        }

        rp(i,1,n+1){
            rp(j,1,s+1){
                if(arr[i-1]<=j){
                    dp[i][j]=((dp[i-1][j-arr[i-1]]) || (dp[i-1][j]));
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][s];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        int n;
        cin>>n;
        int w;
        cin>>w;
        vector<int>arr(n);
        rp(i,0,n){
            cin>>arr[i];
        }
        
        cout<<isSubsetSum(arr,n)<<endl;
    

    return 0;
}
