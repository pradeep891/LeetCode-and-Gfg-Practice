class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // cout << endl;
        int w1 = 0 , w2 = 0;
        int i =0 ,j =0;
        while(w1 < word1.size() && w2 < word2.size()){
            
            while(i < word1[w1].size() && j < word2[w2].size()){
                // cout << word1[w1][i] << " " << word2[w2][j] << " | ";
                if(word1[w1][i] != word2[w2][j]) return false;
                i++;
                j++;
            }
            
            if(j == word2[w2].size())
            {
                w2++;
                j = 0;
            }
            if(i == word1[w1].size()){
                w1++;
                i = 0;
            }
        }
        // cout << i << " " << j << endl;
        if(word1.size() == w1 && word2.size() == w2 && i == 0 && j == 0) return true;
        return false;
    }
};