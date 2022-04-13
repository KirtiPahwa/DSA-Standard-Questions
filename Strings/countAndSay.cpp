#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
class Solution {  
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string out=countAndSay(n-1);
        
        int count=0;
        string ans="";
        int i=0;
        for(i=0;i<(out.length())-1;i++){
            if(out[i]!=out[i+1]){
                char a=(char)((++count)+'0');
                char b=(out[i]);
                ans+=a;
                ans+=b;
                count=0;
            }else{
                count++;
            }
        }
        if(i==(out.length()-1)){
                char a=(char)((++count)+'0');
                char b=(out[i]);
                ans+=a;
                ans+=b;
               

        }
        return ans;
        
    }
};
int main(){
    Solution a;
    cout<<a.countAndSay(4)<<endl;
    return 0;
}