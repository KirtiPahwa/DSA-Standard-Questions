
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
int  lessthanequal(int mid,vector<vector<int>> &matrix, int r, int c){
    int count=0;
    for(int i=0;i<r;i++){
        int l=0,h=c-1;
        // cout<<l<<" "<<h<<" "<<mid<<endl;
        while(l<=h){
            int m=(l+h)/2;
            // cout<<l<<" "<<h<<" "<<m<<endl;
            if(matrix[i][m]<=mid){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        count+=l;
        // cout<<count<<endl;
    }
    return count;
}
    int median(vector<vector<int>> &matrix, int r, int c){
        if(r==1 && c==1){
            return matrix[r-1][c-1];
        }
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<r;i++){
            mx=max(mx,matrix[i][c-1]);
            mn=min(mn,matrix[i][0]);
        }
        int med=(r*c)/2;
        int l=mn,h=mx;
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            int cal=lessthanequal(mid,matrix,r,c);
            // break;
            // cout<<cal<<" "<<mid<<endl;
            if(cal<=med){
                l=mid+1;
                ans=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans; 
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends