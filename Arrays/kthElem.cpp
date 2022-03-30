#include <queue>
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
void swap(int *arr,int a,int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
int partition(int* arr,int s,int e){
    int pivot=arr[s];
    int smallCount=0;
    for(int i=s;i<=e;i++){
        if(pivot>arr[i]){
            smallCount++;
        }
    }
    int pivotLoc=s+smallCount;
    swap(arr,s,pivotLoc);
    int i=s,j=e;
    while(i<pivotLoc && j>pivotLoc){
        if(arr[i]<pivot){
            i++;
        }else if(arr[j]>=pivot){
            j--;
        }else{
            swap(arr,i,j);
            i++;
            j--;
        }
    }
    return pivotLoc;
}
int call(int arr[],int l,int r,int k){
    if(l==r){
        if(l==k-1){
            return arr[l];
        }else{
            return -1;
        }
    }else{
    int pivot= partition(arr,l,r);
    if(pivot==k-1){
        return arr[pivot];
    }else if(pivot>k-1){
        return call(arr,l,pivot-1,k);
    }else{
        return call(arr,pivot+1,r,k);
    }
    }
}
