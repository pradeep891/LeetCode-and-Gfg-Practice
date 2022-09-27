class Solution {
public:
    
    void solve(int l , int r , string &s){
        int ll = -1 , rr = -1 , fl = 0;
        for(int i=l; i<=r; i++){
            if(s[i] == 'L')
                ll = i;
            
            if(fl == 0 && s[i] == 'R')
            {
                rr = i;
                fl = 1;
            }
        }
        
        if(ll != -1){
            for(int i=l; i<=ll ; i++)
                s[i] = 'L';
        }
        
        if(rr != -1){
            for(int i = rr; i<=r; i++)
                s[i] = 'R';
        }
    }
    
    void solvelr(int l , int r , string &s){
        int len = r-l+1;
        for(int i=l; i<l+len/2 ; i++)
            s[i] = 'R';
        
        for(int i=l+len/2; i<=r; i++)
            s[i] = 'L';
        
        if(len % 2 == 1)
            s[l+len/2] = '.';
        
        
    }
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        
        vector< pair<int , int> >rl;
        
        int i=0;
        int r = -1;
        while(i < n){
            
            if(dominoes[i] == 'R'){
                r = i;
            }
            else if(dominoes[i] == 'L'){
                if(r != -1){
                    rl.push_back({r , i});
                    r = -1;
                }
            }
            i++;
        }
        
        if(rl.size() == 0)
        solve(0 , dominoes.size()-1 , dominoes);
        
        for(int i=0; i<rl.size(); i++){
            
            solvelr(rl[i].first , rl[i].second , dominoes);
            
            if(i == 0){
                solve(0 , rl[i].first-1 , dominoes);
            }
            else{
                solve(rl[i-1].second+1 , rl[i].first-1 , dominoes);
            }
            if(i == rl.size()-1){
                solve(rl[i].second+1 , dominoes.size() - 1 , dominoes);
            }
        }
        
        return dominoes;
    }
};