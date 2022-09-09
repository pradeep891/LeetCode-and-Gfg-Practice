class Solution {
public:
    bool static cmp(vector<int>&a , vector<int>&b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin() , properties.end() , cmp);
        // priority_queue<int>pq;
        
        int ct = 0;
        // pq.push();
        int mxd = properties[0][1];
        for(int i=1; i<properties.size(); i++){
            int d = properties[i][1];
            if(mxd > d) ct++;
            mxd = max(mxd , d);
        }
        return ct;
    }
};