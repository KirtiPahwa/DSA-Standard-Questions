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
int knapSack(int W, int wt[], int val[], int n) 
    { 

        // <-------Top Down approach-------->
    int mat[n+1][W+1];
    memset(mat,0,sizeof(mat));
    rp(i,0,n+1){
        rp(j,0,W+1){
            if(i==0 || j==0)
            mat[i][j]=0;
        }
    }
    rp(i,1,n+1){
        rp(j,1,W+1){
            if(wt[i-1]<=j){
                mat[i][j]=max((val[i-1]+mat[i-1][j-wt[i-1]]),(mat[i-1][j]));
            }else{
                mat[i][j]=mat[i-1][j];
            }
        
        }
    }
    return mat[n][W];





        // <------Memoisation------>
        // if(W==0 || n==0){
        //     return 0;
        // }
        // if(mat[W][n]>-1){
        //     return mat[W][n];
        // }
        // if(W>=wt[n-1]){
        //     int a=knapSack(W-wt[n-1],wt,val,n-1);
        //     int b=knapSack(W,wt,val,n-1);
        //     int ans=max(a+val[n-1],b);
        //      mat[W][n]=ans;
        //      return ans;
        // }else{
        //     return  (mat[W][n]=knapSack(W,wt,val,n-1));
        // }
       

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
        int wt[n],val[n];
        rp(i,0,n){
            cin>>val[i];
        }
        rp(i,0,n){
            cin>>wt[i];
        }
        cout<<knapSack(w,wt,val,n)<<endl;
    

    return 0;
}
