class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin()  , tokens.end());
        int i=0, j= n-1;
        int score = 0;
        int ans = 0;
        while(i<=j){
            if(tokens[i] <= power){
                power -= tokens[i];
                score++;
                ans = max(ans , score);
                i++;
            }
            else if(score > 0){
                power += tokens[j];
                score--;
                j--;
            }
            else
                break;
        }
        
        return ans;    
    }
};