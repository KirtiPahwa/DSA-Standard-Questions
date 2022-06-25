#include<bits/stdc++.h>
using namespace std; 

int fun(vector<int>& inorder, vector<int> levelOrder,int b,int s,int e ){   
       cout<<s<<" "<<e<<endl;

    if(s>=e){
        return 0;
    }
    int root=0;
    bool flag=false;
    int l;
    for(int j=b;j<levelOrder.size();j++){
    int k=levelOrder.at(j);
    for(int i=s;i<=e;i++){
        if(inorder[i]==k){
            root=i;
            l=j;
            flag=true;
            break;
        }
    }
    if(flag){
        break;
    }
    }
    return max(fun(inorder,levelOrder,l+1,s,root-1)
    ,fun(inorder,levelOrder,l+1,root+1,e))+1;
    
    
}

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
  return fun(inorder,levelOrder,0,0,N-1);
}
int main(){

    int n;
    cin>>n;
    vector<int> inorder;
    vector<int> levelOrder;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        inorder.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin>>a;
        levelOrder.push_back(a);
    }
    cout<<heightOfTheTree(inorder,levelOrder,n)<<endl;
    return 0;
}
