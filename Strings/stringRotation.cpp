#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rp(s, e, i) for (ll i = s; i < e; i++)
#define tc    \
    ll t;    \
    cin >> t; \
    while (t--)
#define mod 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        string s1,s2;
        cin>>s1;
        cin>>s2;
        string temp=s1+s1;
        cout<<temp<<endl;
        if(s1.length()==s2.length()){
        if(temp.find(s2)!=string::npos){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
        }

    

    return 0;
}
