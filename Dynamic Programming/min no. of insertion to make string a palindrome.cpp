//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
#define ll long long int
#define rp(i, s, e) for (ll i = s; i < e; i++)

class Solution{
  public:
  int findLCS(string s1,string s2,int m,int n){
     int dp[m+1][n+1];
     rp(i,0,m+1){
         rp(j,0,n+1){
             if(i==0 || j==0){
                 dp[i][j]=0;
             }
         }
     }
     rp(i,1,m+1){
         rp(j,1,n+1){
             if(s1[i-1]==s2[j-1]){
                 dp[i][j]=1+dp[i-1][j-1]; 
             }else{
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
             }
         }
     }
     return dp[m][n];
}

    int countMin(string str){
        string a=str;
        reverse(str.begin(),str.end());
        ll k=findLCS(a,str,str.length(),str.length());
    return (str.length()-k);
        
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends