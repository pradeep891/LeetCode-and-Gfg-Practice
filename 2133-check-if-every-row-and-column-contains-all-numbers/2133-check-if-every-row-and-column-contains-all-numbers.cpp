class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            
            for(int j=0; j<n; j++){
                int n = matrix[i][j];
                int id = abs(n) - 1;
                if(matrix[i][id] < 0) return false;
                matrix[i][id] *= -1;
            }
            
            
            for(int j=0; j<n; j++){
                matrix[i][j] = abs(matrix[i][j]);
            }
        }
                
        for(int i=0; i<n; i++){            
            for(int j=0; j<n; j++){
                int n = matrix[j][i];
                int id = abs(n) - 1;
                if(matrix[id][i] < 0) return false;
                matrix[id][i] *= -1;
            }
        }
        return true;
    }
};