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

void findLCS(string s1,string s2,int m,int n){
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
    //  print the subsequence
    int i=m,j=n;
    string s;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s.push_back(s1[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1,s2;
    cin>>s1;
    cin>>s2;
    findLCS(s1,s2,s1.length(),s2.length());

    return 0;
}
