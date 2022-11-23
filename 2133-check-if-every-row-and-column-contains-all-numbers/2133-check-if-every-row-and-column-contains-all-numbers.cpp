class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            set<int>row , col;
            for(int j=0; j<n; j++){
                char a = matrix[i][j] , b = matrix[j][i];
                // cout << a << " " << b << " | ";
                if(row.find(a) != row.end()) return false;
                if(col.find(b) != col.end()) return false;
                row.insert(a);
                col.insert(b);
            }
        }
        return true;
    }
};