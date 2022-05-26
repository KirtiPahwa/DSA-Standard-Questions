#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string,int> mp;
    bool isScramble(string a, string b) {
        if(a.length()!=b.length()){
            return false;
        }
        if(a==b){
            return true;
        }
        if(a.length()<=1){
            return false;
        }
        string temp=a+" "+b;
        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        int n=a.length();
        for(int i=1;i<n;i++){
            bool swapCase=isScramble(a.substr(0,i),b.substr(n-i,i)) && isScramble(a.substr(i,n-i),b.substr(0,n-i));
            bool noSwapCase=isScramble(a.substr(0,i),b.substr(0,i)) && isScramble(a.substr(i,n-i),b.substr(i,n-i));
            if(swapCase || noSwapCase){
                return mp[temp]=true;
            }

            
            
        }
        return mp[temp]=false;
    }
};