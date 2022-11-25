class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>next(n , n) , pre(n , -1);
        stack<int>st;
        for(int i=0; i<arr.size(); i++){
            while(st.empty() ==false && arr[st.top()] > arr[i]) 
                st.pop();
            if(!st.empty()) pre[i] = st.top();
            st.push(i);
        }
        while(st.empty() == false) st.pop();
        for(int i=arr.size()-1; i>=0; i--){
            while(st.empty() ==false && arr[st.top()] >= arr[i]) 
                st.pop();
            if(!st.empty()) next[i] = st.top();
            st.push(i);
        }
        
//         for(auto i : pre) cout << i << " " ;
//         cout << endl;
//         for(auto i : next) cout << i << " " ;
//         cout << endl;
        long long ans = 0;
        // set<int>mp;
        long long mod = 1e9 + 7;
        for(int i=0; i<n; i++){
            int left = i - pre[i] ;
            int right = next[i] - i ;
            long long temp = arr[i] *1LL* ( left * right) % mod;
            // cout << i << " " << left << " " << right << " " << temp << " | ";
            // if(mp.find(arr[i]) == mp.end())
            ans = (ans + temp) % mod;
            
            // mp.insert(arr[i]);
        }
        // cout << endl;
        return ans;
    }
};