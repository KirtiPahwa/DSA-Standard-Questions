#include<iostream>
using namespace std;
int minJump(int n,int arr[]){
     if(n==1){
            return 0;
        }else if(arr[0]==0){
            return -1;
        }
        int step=0,maxStep=arr[0],csum=0;
    for(int i=1;i<n;i++){
        csum=max(arr[i]+i,csum);
        if(maxStep>=n-1){
            step++;
            return step;
        }
        if(i==maxStep){
            maxStep=csum;
            step++;
            csum=0;
        }
    cout<<csum<<" ";
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minJump(n,arr);
    return 0;

}