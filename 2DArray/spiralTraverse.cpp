class Solution{
 public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> arr;
    int rs=0,re=r-1,cs=0,ce=c-1;
    int j=0;
    while(cs<=ce && rs<=re){
        for(int i=cs;i<=ce;i++){
         arr.push_back(matrix[rs][i]);
        }
        rs++;
        for(int i=rs;i<=re;i++){
            arr.push_back(matrix[i][ce]);
        }
        ce--;
        if(rs<=re){
        for(int i=ce;i>=cs;i--){
            arr.push_back(matrix[re][i]);
        }
        re--;
        }
        if(cs<=ce){
        for(int i=re;i>=rs;i--){
            arr.push_back(matrix[i][cs]);
        }
        cs++;
        }
    }
    return arr;
    }
};