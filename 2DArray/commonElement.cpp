#include<iostream>
#include<climits>
#include<unordered_map>
using namespace std;
int commonElement(int arr[][5],int m,int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[0][i]]=1;
    }
    for(int i=1;i<m;i++){  
        for(int j=0;j<n;j++){
            if(mp[arr[i][j]]==i){
                mp[arr[i][j]]++;
                if(i==m-1){
                    cout<<arr[i][j]<<endl;
                }
            }

        }
    }
}
int main(){
    int mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

    commonElement(mat,4,5);
    return 0;
}