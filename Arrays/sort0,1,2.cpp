#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    // void swap(int &a,int &b){
    //     int temp=a;
    //     a=b;
    //     b=temp;
    // }
    void sort012(int arr[], int n)
    {
        int i=0;
        int l=0;
        int r=n-1;
        while(i<=r){
            if(arr[i]==0){
                swap(arr[i],arr[l]);
                l++;
                i++;
            }else if(arr[i]==2){
                swap(arr[i],arr[r]);
                r--;
            }else{
                i++;
            
            }
            
        }
        
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends