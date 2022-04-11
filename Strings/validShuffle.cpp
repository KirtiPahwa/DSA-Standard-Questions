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
    string s1,s2,result;
    cin>>s1>>s2;
    cin>>result;
    int i=0,j=0,k=0;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    sort(result.begin(),result.end());

    while(k<result.length()){
        if(i<s1.length() && result[k]==s1[i]){
            i++;
        }else if(j<s2.length() && result[k]==s2[j]){
            j++;
        }else{
            cout<<"No"<<endl;
            return 0;
        }
        k++;
    }
    if(i<s1.length() || j<s2.length()){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }

    return 0;
}
