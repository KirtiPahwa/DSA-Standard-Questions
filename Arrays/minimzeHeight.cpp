int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int mn=arr[0]+k;
        int mx=arr[n-1]-k;
        int mn1=mn-k,mx2=mx+k;
        int mindiff=arr[n-1]-arr[0];

        for(int i=1;i<n;i++){
            if(arr[i]-k>=0){
                mn1=min(arr[i]-k,mn);
            
           mx2=max(arr[i-1]+k,mx);
            mindiff=min(mindiff,mx2-mn1);}
        }
        return mindiff;
    }