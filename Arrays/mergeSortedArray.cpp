class Solution{
public:
void swap(int &a,int &b){
    int temp=a;
	a=b;
	b=temp;
    
}
	void merge(int arr1[], int arr2[], int n, int m) {
	    	        int gap=n+m;

	    while(gap>=1){
	        if(gap<=1){
	            gap=0;
	        }
	        gap=ceil((double)gap/2);
	       // cout<<gap<<endl;
	       // break;
	        int j;
	        int i;
	        for(i=0;i+gap<n;i++){
	            if(arr1[i]>=arr1[i+gap]){
	                swap(arr1[i],arr1[i+gap]);
	            }
	        }
	       for (j =  0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
                
	        if(j<m){
	            for(j=0;j+gap<m;j++){
	                if(arr2[j]>arr2[j+gap]){
	                    swap(arr2[j],arr2[j+gap]);
	                }
	            }
	        }
	    }
	}
};