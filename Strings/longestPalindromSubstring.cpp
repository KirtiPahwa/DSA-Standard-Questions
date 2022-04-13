#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  
    string longestPalin (string s) {
        int mx=INT_MIN;
        string ans="";
        int n=s.length();
        for(int i=0;i<s.length();i++){
            int a=i,b=i+1;
            while(a>=0 && b<n && s[a]==s[b]){
                if(mx<(b-a+1)){
                    mx=b-a+1;
                    ans=s.substr(a,b-a+1);
                }
                a--;
                b++;
            }
             a=i,b=i;
            while(a>=0 && b<n && s[a]==s[b]){
                if(mx<(b-a+1)){
                    mx=b-a+1;
                    ans=s.substr(a,b-a+1);
                }
                a--;
                b++;
            }
            
        }
        return ans;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends