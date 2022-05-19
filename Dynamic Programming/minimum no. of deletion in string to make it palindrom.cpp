#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends

int findLCS(string str1, string str2,int m,int n){
	    int dp[m+1][n+1];
	    for(int i=0;i<m+1;i++){
	        for(int j=0;j<n+1;j++){
	            if(i==0 || j==0){
	                dp[i][j]=0;
	            }
	        }
	    }
	   for(int i=1;i<m+1;i++){
	        for(int j=1;j<n+1;j++){
	            if(str1[i-1]==str2[j-1]){
	                dp[i][j]=dp[i-1][j-1]+1;
	            }else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    return dp[m][n];
	}
int minDeletions(string str, int n) { 
    string str2=str;
    reverse(str2.begin(),str2.end());
    return n-findLCS(str,str2,n,n);
} 