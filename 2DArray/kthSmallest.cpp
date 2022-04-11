// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

int smallerEqual(int mid,int arr[MAX][MAX],int n){
    int count=0;
    for(int i=0;i<n;i++){
        int a=upper_bound(arr[i],arr[i]+n,mid)-arr[i];
        // a=a-(&arr[i]);
        count+=(a);
    }
    return count;
}


int kthSmallest(int arr[MAX][MAX], int n, int k)
{
 int mn=arr[0][0];
 int mx=arr[n-1][n-1];
 int l=mn,r=mx;
 while(l<=r){
     int mid=(l+r)/2;
     if(smallerEqual(mid,arr,n)<=k-1){
         l=mid+1;
     }else{
         r=mid-1;
     }
 }
 return l;
}
