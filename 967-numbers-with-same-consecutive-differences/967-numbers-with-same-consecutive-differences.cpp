class Solution {
public:
    void solve(int n , int k , vector<int>&res , int cur , int pre){ 
        if(n == 0)
        {
            res.push_back(cur);
            return;
        }
        for(int i=0; i<10; i++){
            if(abs(pre - i) == k){
                solve(n-1  , k , res , cur*10 + i , i);
            }            
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        // vector<int>vis(10 , 0);
        vector<int>res; 
        for(int i=1; i<10; i++)
            solve(n-1 , k , res , i , i);   
        
        return res;
    }
};