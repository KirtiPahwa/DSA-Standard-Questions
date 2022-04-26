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
int minDifference(int arr[], int n)  { 
    ll s=0;
    rp(i,0,n){
        s+=arr[i];
    }
	int dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));
    rp(i, 0, n + 1)
    {
        dp[i][0] = 1;
    }
        rp(i, 1, n + 1)
    {
        rp(j, 1, s + 1)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = ((dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]));
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    ll mx=INT_MIN;
    rp(i,0,s/2+1){
        if(dp[n][i]){
            mx=max(mx,i);
        }
    }

    return s-(2*mx);


} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    rp(i, 0, n)
    {
        cin >> arr[i];
    }

    cout << minDifference(arr,n) << endl;

    return 0;
}
