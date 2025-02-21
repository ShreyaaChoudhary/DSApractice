class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> matm(m,0);
        vector<int> matn(n,0);
        for(int i = 0; i< m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(matrix[i][j]==0){
                    matm[i]=1;
                    matn[j]=1;
                }
            }
        }
        for(int i = 0; i< m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(matm[i]||matn[j]){
                    matrix[i][j]=0;
                }
            }
        }
        }
};