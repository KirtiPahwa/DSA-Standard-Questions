#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    map <char,int> mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    for(auto x:mp){
        if(x.second>1){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }

    return 0;
}