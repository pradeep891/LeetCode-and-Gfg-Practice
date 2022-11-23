class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            set<int>row , col;
            for(int j=0; j<9; j++){
                char a = board[i][j] , b = board[j][i];
                // cout << a << " " << b << " | ";
                if(row.find(a) != row.end()) return false;
                if(col.find(b) != col.end()) return false;
                if(a != '.')
                row.insert(a);
                if(b != '.')
                col.insert(b);
            }
        }
        // cout << "I am here!";
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                set<int>st;
                for(int row = 3*i ; row< 3*i+3 ; row++){
                    for(int col = 3*j ; col < 3*j + 3; col++){
                        char a = board[row][col];
                        if(st.find(a) != st.end()) return false;
                        if(a != '.')
                        st.insert(a);
                    }
                }
            }
        }
        return true;
    }
};