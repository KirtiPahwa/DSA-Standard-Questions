// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int val[], int w) {
        int dp[w+1][w+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<w+1;i++){
            for(int j=0;j<w+1;j++){
                if(j==0  || i==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<w+1;i++){
            for(int j=1;j<w+1;j++){
               if(i<=j){
                   dp[i][j]=max(val[i-1]+dp[i][j-i],dp[i-1][j]);
               }else{
                   dp[i][j]=dp[i-1][j];
               }
            }
        }
        return dp[w][w];

    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends