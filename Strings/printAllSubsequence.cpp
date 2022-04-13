#include<bits/stdc++.h>
using namespace std;
void print(string s,vector<string> &output,int n){
    if(n==0){
        output.push_back("");
        return ;
    }
    print(s,output,n-1);
    int ind=s.length()-n;
    int len=output.size();
    for(int i=0;i<len;i++){
        output.push_back(s[ind]+output[i]);
    }
}
int main(){
    string s="abc";
    vector<string>output;
    print(s,output,s.length());
    for(auto x:output){
        cout<<x<<endl;
    }

    return 0;
}