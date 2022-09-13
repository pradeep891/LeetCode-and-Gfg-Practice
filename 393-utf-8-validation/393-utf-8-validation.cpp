class Solution {
public:
    int find(int n){
        // int k = n >> 7;
        // cout <<  n << " >> 7 =  " << k << endl; 
        if(n >> 7 == 0 ){
            // cout << "hel ";
            return 1;
        }
        
        if(n >> 5 == 6)
            return 2;
        
        if(n >> 4 == 14)
            return 3;
        
        if(n >> 3 == 30)
            return 4;
        
        return 0;
    }
    
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int i = 0;
        while(i < n){
            int k = find(data[i]);
            // cout << " k = " << k << endl;
            if(k == 0)
                return false;
            
            i++;
            while(k > 1 && i < n){
                if( data[i] >> 6 != 2) return false;
                i++;
                k--;
            }
            
            if(k > 1)
                return false;
        }
        return true;
    }
};