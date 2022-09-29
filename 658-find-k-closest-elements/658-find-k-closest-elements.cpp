class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue< pair<int , int> , vector< pair<int , int> >  , greater< pair<int,int> > >pq;
        for(auto i : arr){
            int a = abs(i - x);
            pq.push({a , i});
        }
        
        vector<int>ans;
        for(int i=0; i<k; i++){
            int top = pq.top().second;
            pq.pop();
            ans.push_back(top);
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};