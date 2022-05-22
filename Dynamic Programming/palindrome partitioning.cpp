// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[501][501];
bool isPalidrome(string s,int i,int j){
    while(s[i]==s[j] && i<=j){
        i++;
        j--;
    }
    if(i>j){
        return 1;
    }else{
        return 0;
    }
}

int solve(string s,int i,int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i>=j || isPalidrome(s,i,j)){
        return dp[i][j]=0;
    }
    
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int temp1,temp2;
        if(dp[i][k]==-1){
         temp1=solve(s,i,k);
    }else{
        temp1=dp[i][k];
    }
    if(dp[k+1][j]!=-1){
        temp2=dp[k+1][j];
    }else{
        temp2=solve(s,k+1,j);
    }
    mn=min(mn,1+temp1+temp2);
    }
    
  return dp[i][j]=mn;
}
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.length()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends