#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define rp(i, s, e) for (ll i = s; i < e; i++)

class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int m, int n)
    {
        ll dp[m+1][n+1];
     rp(i,0,m+1){
         rp(j,0,n+1){
             if(i==0 || j==0){
                 dp[i][j]=0;
             }
         }
     }
     ll mx=INT_MIN;
     rp(i,1,m+1){
         rp(j,1,n+1){
             if(s1[i-1]==s2[j-1]){
                 mx=max(1+dp[i-1][j-1],mx); 
                 dp[i][j]=1+dp[i-1][j-1]; 
             }else{
                 dp[i][j]=0;
             }
         }
     }
     
     return (mx<0?0:mx);
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
