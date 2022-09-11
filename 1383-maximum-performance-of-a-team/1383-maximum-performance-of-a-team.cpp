class Solution {
public:

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector< pair<int ,int> > v;
        for(int i=0; i<n; i++){
            v.push_back({efficiency[i] , speed[i] });
        }
        
        sort(v.rbegin() , v.rend());
            
            
            long long ans = 0;
            long long total = 0;
            priority_queue<int , vector<int> , greater<int> >pq;
        
        
            for(auto i : v){
                if(pq.size() == k ){
                    if(pq.top() <= i.second){
                        // cout << " top = " << pq.top() << " ";
                        total = total - pq.top() + i.second;
                        ans = max(ans , total * i.first);
                        pq.pop();
                        pq.push(i.second);
                    }
                }
                else{
                    
                total += i.second;
                ans = max(ans ,  total * i.first);
                pq.push(i.second);
                }
                
                // cout << ans << " ";
                
            }
        int mod = 1e9+7;
        return ans % mod;
            
        
    }
};