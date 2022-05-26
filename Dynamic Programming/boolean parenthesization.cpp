// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[200][200];
    int mod = 1003;

    unordered_map<string,int>mp;
    int solve(string s,int i,int j,bool isTrue){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(s[i]=='T'){
            if(isTrue==true){
                return 1;
            }else{
                return 0;
            }
            }
            else{
            if(isTrue==false){
                return 1;
            }else{
                return 0;
            }
            }
        }
        string temp=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        int ans=0;
    
        for(int k=i+1;k<=j-1;k+=2){
        int leftTrue=solve(s,i,k-1,true);
        int rightTrue=solve(s,k+1,j,true);
        int leftFalse=solve(s,i,k-1,false);
        int rightFalse=solve(s,k+1,j,false);
        int tempTrue=0,tempFalse=0;
        
        if(s[k]=='&'){
            tempTrue+=leftTrue*rightTrue;
            tempFalse+=rightTrue*leftFalse+leftFalse*rightFalse+rightFalse*leftTrue;
        }else if(s[k]=='|'){
            tempTrue+=leftTrue*rightTrue+leftFalse*rightTrue+leftTrue*rightFalse;
            tempFalse+=leftFalse*rightFalse;
        }else if(s[k]=='^'){
            tempTrue+=leftTrue*rightFalse+rightTrue*leftFalse;
            tempFalse+=leftTrue*rightTrue+leftFalse*rightFalse;
        }
        if(isTrue==true){
                ans+=tempTrue;
            }else{
                ans+=tempFalse;
            }
        }
        return mp[temp]=ans%mod;
    }
    int countWays(int N, string S){
                memset(dp,-1,sizeof(-1));
                mp.clear();
                return solve(S,0,N-1,true);
                 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends