#include<iostream>
#include<climits>
using namespace std;
int specificPair(int arr[][5],int n){
    int ans[n]={0};
        int mx=INT_MIN;
    for(int i=n-1;i>=0;i--){
    for(int j=i;j<n;j++){
        mx=max(mx,arr[i][j]);
        mx=max(mx,arr[j][i]);
    }
    ans[i]=mx;
    }
    // for(int i=0;i<n;i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    int fina=INT_MIN;
    for(int i=0;i<n-1;i++){
        int mn=INT_MAX;
        for(int j=i;j<n-1;j++){
            mn=min(mn,arr[i][j]);
            mn=min(mn,arr[j][i]);
        }
        fina=max(fina,(ans[i+1])-mn);
    }
    return fina;
}
int main(){
    // int arr[n][n];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    int mat[5][5] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }
            };
    cout<<specificPair(mat,5)<<endl;
    return 0;
}