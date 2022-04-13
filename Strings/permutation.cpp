#include<bits/stdc++.h>
using namespace std;
	void permutation(string s,vector<string> &ans,int n,int ind){
    if(n==1){
        ans.push_back(s);
        return;
    }        
    for(int i=ind;i<s.length();i++){
        swap(s[ind],s[i]);
        permutation(s,ans,n-1,ind+1);
    }
    }
int main(){
    string s="ABC";
    vector<string>ans;
    permutation(s,ans,3,0);
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x<<" ";
    }
    
    return 0;
}
