#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int S[], int m, int n) 
	{ 
        long long  dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n+1;i++){
            dp[0][i]=INT_MAX-1;
        }
       
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(S[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-S[i-1]],dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return( dp[m][n]>=INT_MAX-1?-1:dp[m][n] );
    
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends